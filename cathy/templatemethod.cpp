#include <iostream>
class MathStuff{
public:
	MathStuff(){
	}
	virtual void op1()=0;
	virtual void op2()=0;
	virtual void print()=0;
	void doThings(){
		op1();  //variant functions
		op2();

		std::cout << "Hello world" << std::endl; //invariant 

	}


};

class Incrementor:public MathStuff{
	int data_;
public:
	Incrementor(int d):MathStuff(){
		data_=d;
	}
	virtual void op1(){data_=data_+1;}
	virtual void op2(){data_=data_+data_;}
	virtual void print(){std::cout << data_ << std::endl;}

};
class Decrementor:public MathStuff{
	int data_;
public:
	Decrementor(int d):MathStuff(){
		data_=d;
	}
	virtual void op1(){data_=data_-1;}
	virtual void op2(){data_=data_-data_;}
	virtual void print(){std::cout << data_ << std::endl;}
};
int main(void){

	Incrementor i(1);
	Decrementor d(1);

	i.print();
	d.print();

	i.doThings();
	d.doThings();
	std::cout << "********************"	<< std::endl;
	i.print();
	d.print();
}



class Game{
public:
	void gameLoop(){
		while(notend()){
			currplayergo();
			nextplayer();
		}
	}
	bool notend()=0;
	void currplayergo()=0;
	void nextplayer()=0;

}

class PokerGame::public Game{

public:
	bool notend(){
		//until we show the cards or all but one drops
	}
	void currplayergo(){

	}
	void nextplayer(){
		//go to next player that has not dropped out
	}
}


class MahjongGame::public Game{

public:
	bool notend(){
		//until some wins or runs out of blocks
	}
	void currplayergo(){

	}
	void nextplayer(){
		//round unless someone takes something
	}
}






