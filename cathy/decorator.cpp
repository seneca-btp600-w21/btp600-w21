#include <iostream>
using namespace std;
//This is the abstract component
class ScreenObject{
public:
//screen objects need to be able to draw itself
	virtual void show()=0;
	virtual int width()=0;
};


//a concrete component
class Label:public ScreenObject{
	string text_;

public:
	Label(string s){
		text_=s;
	}
	virtual void show(){
		cout << text_ << endl;
	}
	virtual int width(){
		return text_.length();
	}
};

//an abstract Decorarator 
class Decorator:public ScreenObject{
	ScreenObject* so_;
public:
	Decorator(ScreenObject* so){
		so_=so;
	}
	virtual void show(){
		so_->show();
	}
	virtual int width(){
		return so_->width();
	}
};

class DashBorder:public Decorator{
public:

	DashBorder(ScreenObject* so):Decorator(so){};
	virtual void show(){
		//this part draws a border above the Screen Object
		for(int i=0;i<width();i++){
			std::cout << '-';
		}
		std::cout << std::endl;

		// Base class show() call... ie draws the thing 
		// that is inside border
		Decorator::show();

		//this part draws a border above the Screen Object
		for(int i=0;i<width();i++){
			std::cout << '-';
		}
		std::cout << std::endl;
	}
	virtual int width(){
		return Decorator::width();
	}
};

class StarBorder:public Decorator{
public:
	StarBorder(ScreenObject* so):Decorator(so){};
	virtual void show(){
		//this part draws a border above the Screen Object
		for(int i=0;i<width();i++){
			std::cout << '*';
		}
		std::cout << std::endl;

		// Base class show() call... ie draws the thing 
		// that is inside border
		Decorator::show();

		//this part draws a border above the Screen Object
		for(int i=0;i<width();i++){
			std::cout << '*';
		}
		std::cout << std::endl;
	}
	virtual int width(){
		return Decorator::width();
	}
};

class EqualsBorder:public Decorator{
public:
	EqualsBorder(ScreenObject* so):Decorator(so){};

	virtual void show(){
		//this part draws a border above the Screen Object
		for(int i=0;i<width();i++){
			std::cout << '=';
		}
		std::cout << std::endl;

		// Base class show() call... ie draws the thing 
		// that is inside border
		Decorator::show();

		//this part draws a border above the Screen Object
		for(int i=0;i<width();i++){
			std::cout << '=';
		}
		std::cout << std::endl;
	}
	virtual int width(){
		return Decorator::width();
	}
};

//Yes there is a mem leak here

int main(void){

	ScreenObject*  myLabel=new Label("This is cool!");

	myLabel->show();

	int choice=1;
	while(choice != 0){
		std::cout << "what deco do you want to add? (1-dash, 2-star, 3-equal, 0 quit): ";
		std::cin >> choice;
		switch(choice){
			case 1: 
				myLabel=new DashBorder(myLabel);
				break;
			case 2: 
				myLabel=new StarBorder(myLabel);
				break;
			case 3: 
				myLabel=new EqualsBorder(myLabel);
				break;

		}
		std::cout<< std::endl;
		myLabel->show();		
	}

	return 0;

}

