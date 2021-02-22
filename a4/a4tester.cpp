/****************************************************/
/*                                                  */
/*  BTP600                                          */
/*  a4 tester                                       */
/*                                                  */
/*  To compile:                                     */
/*      c++ a4tester.cpp a4.cpp -std=c++0x          */
/*                                                  */
/****************************************************/
#include "a4.h"
#include <iostream>
void printObservers(Observer* obs[],int numObservers);
void test1(); 
void test2(); 
void test3(); 
typedef void (*TestPtr)();

int main(void){
	const int numTests=3;
    TestPtr runTest[numTests]={test1, test2, test3};
    std::string testSummary[numTests]={
                            "Singleton Test",
                            "Observer Test",
                            "Memento Test"
                        };
    for(int i=0;i<numTests;i++){
       std::cout << "Test " << i+1 <<" - "<< testSummary[i] << std::endl;
       runTest[i]();
    }

}

void printObservers(Observer* obs[],int numObservers){

	char desc[3][15]={"Stars: ","Seconds: ", "Status: "};
	for(int i=0;i<numObservers;i++){
		std::cout << desc[i%3];
		obs[i]->print();
		std::cout << std::endl;
	}
	std::cout << std::endl;
	std::cout << "--------------------------------------------" << std::endl;
	std::cout << std::endl;
}

void test1(){
	Timer* t1=Timer::getInstance();
	t1->start();
	int first,second;
	while(t1->currtime()<1.5);
	first=t1->currtime();
	Timer* t2=Timer::getInstance();
	second=t2->currtime();
	if(first!=second){
		std::cout << "Test 1a: failed" << std::endl;
	}
	else{
		t1->stop();
		if(!t2->isPaused()){
			std::cout << "Test 1b: failed" << std::endl;		
		}
		else{
			std::cout << "Test 1: passed" << std::endl;
		}
	}
}
void test2(){

	Timer* theTimer=Timer::getInstance();
	Observer* obs[6]={
		new Stars(), new Seconds(), new Status(),
		new Stars(), new Seconds(), new Status()
	};
	for(int i=0;i<3;i++){
		theTimer->attach(obs[i]);
	}
	theTimer->reset();
	theTimer->start();
	while(theTimer->currtime() < 1.1);
	theTimer->notify();
	printObservers(obs,6);

	theTimer->attach(obs[3]);
	theTimer->attach(obs[4]);
	theTimer->attach(obs[5]);
	while(theTimer->currtime() < 2.1);
	theTimer->notify();
	printObservers(obs,6);

	theTimer->detach(obs[0]);
	theTimer->detach(obs[1]);
	theTimer->detach(obs[2]);
	while(theTimer->currtime() < 3.1);
	theTimer->notify();
	printObservers(obs,6);
	theTimer->stop();
	theTimer->notify();
	printObservers(obs,6);

}
void test3(){
	Timer* theTimer=Timer::getInstance();
	theTimer->reset();
	Observer* obs[3]={
		new Stars(), new Seconds(), new Status()
	};
	UndoStack undos;
	for(int i=0;i<3;i++){
		theTimer->attach(obs[i]);
	}
	undos.save(theTimer->createMemento());
	theTimer->start();
	printObservers(obs,3);
	//loop 2 seconds
	while(theTimer->currtime() < 1.1);
	theTimer->notify();
	undos.save(theTimer->createMemento());
	printObservers(obs,3);
	theTimer->stop();
	theTimer->notify();
	undos.save(theTimer->createMemento());
	printObservers(obs,3);

	theTimer->start();

	//loop 2 more seconds
	while(theTimer->currtime() < 2.1);
	theTimer->notify();
	undos.save(theTimer->createMemento());
	printObservers(obs,3);

	theTimer->stop();
	theTimer->notify();
	printObservers(obs,3);

	theTimer->restoreFromMemento(undos.getMemento());
	theTimer->notify();
	printObservers(obs,3);

	//loop 1 more seconds
	while(theTimer->currtime() < 3.1);
	theTimer->notify();
	undos.save(theTimer->createMemento());
	printObservers(obs,3);


	//loop 1 more seconds
	while(theTimer->currtime() < 4.1);
	theTimer->notify();
	undos.save(theTimer->createMemento());
	printObservers(obs,3);

	//loop 1 more seconds
	while(theTimer->currtime() < 5.1);
	theTimer->notify();
	undos.save(theTimer->createMemento());
	printObservers(obs,3);

	//loop 1 more seconds
	while(theTimer->currtime() < 6.5);
	theTimer->notify();
	printObservers(obs,3);

	for(int i=0;i<5;i++){
		theTimer->restoreFromMemento(undos.getMemento());
		theTimer->notify();
		printObservers(obs,3);
	}
}