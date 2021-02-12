#ifndef ADAPTER_H
#define ADAPTER_H
#include "linkedlist.h"

//the Expected interface for a Queue
class Queue{
public:
	Queue(){}
	virtual void enqueue(const int& o)=0;
	virtual void dequeue()=0;
	virtual int front() const =0;
	virtual bool isEmpty() const =0;
	virtual int numItems() const =0;
	virtual ~Queue(){}
};


//class below is not completed... you must structure this as a object adapter
//with appropriate requests and calls inheritance structure etc.
class ObjectAdapter{

};



//class below is not completed... you must structure this as a class adapter
//with appropriate requests and calls inheritance structure etc.
class ClassAdapter{

};
#endif