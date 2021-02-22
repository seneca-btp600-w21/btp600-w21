/****************************************************/
/*                                                  */
/*  BTP600                                          */
/*  a4 interactive tester                           */
/*                                                  */
/*  To compile:                                     */
/*      c++ a4main.cpp a4.cpp -std=c++0x            */
/*                                                  */
/****************************************************/
#include "a4.h"
#include <iostream>

int main(void){
	Timer* theTimer=Timer::getInstance();
	int choice=1;
	Observer* obs[3]={
		new Stars(), new Seconds(), new Status()
	};

	UndoStack undos;
	undos.save(theTimer->createMemento());

	theTimer->attach(obs[0]);
	theTimer->attach(obs[2]);
	bool attached[3]={true, false, true};
	for(int i=0;i<3;i++){
		obs[i]->print();
		std::cout << std::endl;
	}
	std::cout << "what do you want to do?" << std::endl;
	std::cout << "(1-pause/unpause, 2-save, 3-restore, 4-Stars, 5-Seconds, 6-Status, 0 quit): ";
	std::cin >> choice;
	while(choice != 0){
		if(choice>=1 && choice <=6){
			switch(choice){
				case 1: 
					if(theTimer->isPaused()){
						theTimer->start();
					}
					else{
						theTimer->stop();
					}
					break;
				case 2:
					undos.save(theTimer->createMemento());
					break;
				case 3: 
					theTimer->restoreFromMemento(undos.getMemento());
					break;
				case 4:
					if(attached[0]){
						theTimer->detach(obs[0]);
					}
					else{
						theTimer->attach(obs[0]);
					}
					attached[0]=!attached[0];
					break;
				case 5:
					if(attached[1]){
						theTimer->detach(obs[1]);
					}
					else{
						theTimer->attach(obs[1]);
					}
					attached[1]=!attached[1];
					break;
				case 6:
					if(attached[2]){
						theTimer->detach(obs[2]);
					}
					else{
						theTimer->attach(obs[2]);
					}
					attached[2]=!attached[2];
					break;
			}

			theTimer->notify();

			for(int i=0;i<3;i++){
				obs[i]->print();
				std::cout << std::endl;
			}
		}
		std::cout << "what do you want to do?" << std::endl;
		std::cout << "(1-pause/unpause, 2-save, 3-restore, 4-Stars, 5-Seconds, 6-Status, 0 quit): ";
		std::cin >> choice;
    }
}