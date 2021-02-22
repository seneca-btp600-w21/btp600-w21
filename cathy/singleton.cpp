#include <iostream>

class Singleton{
	static Singleton* theOne_;
	int counter_;
	Singleton(){
		counter_=0;
		//do initialization
	}
public:
	static Singleton* getInstance(){
		if(theOne_==0){
			theOne_=new Singleton();
		}
		return theOne_;
	}
	void increment(){
		counter_++;
	}
	void print() const{
		std::cout << counter_ << std::endl;
	}
};
Singleton* Singleton::theOne_=nullptr;


int main(void){
	
	Singleton* A=Singleton::getInstance();
	A->print();
	A->increment();
	A->print();

	Singleton* B=Singleton::getInstance();
	B->increment();
	B->print();


	return 0;
}