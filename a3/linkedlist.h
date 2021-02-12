#ifndef LINKEDLIST_H
#define LINKEDLIST_H

class LinkedList{
public:
	virtual void push_front(const int& data)=0;
	virtual void push_back(const int& data)=0;
	virtual void pop_front()=0;
	virtual void pop_back()=0;
	virtual int frontData() const=0;
	virtual int backData() const=0;
	virtual bool empty() const=0;
	virtual int size() const=0;
	virtual ~LinkedList(){}
};

/* A doubly linked list (with sentinel nodes) implementation*/

class DList:public LinkedList{
	struct Node{
		int data_;
		Node* next_;
		Node* prev_;
		Node(const int& data=int{},Node* nx=nullptr,Node* pr=nullptr){
			data_=data;
			next_=nx;
			prev_=pr;
		}

	};
	Node* front_;
	Node* back_;
	int size_;

public:
	DList();
	virtual void push_front(const int& data);
	virtual void push_back(const int& data);
	virtual void pop_front();
	virtual void pop_back();
	virtual int frontData() const;
	virtual int backData() const;
	virtual bool empty() const;
	virtual int size() const;
	virtual ~DList();
};


//Singly linked list without sentinels
class SList:public LinkedList{
	struct Node{
		int data_;
		Node* next_;
		Node(const int& data=int{},Node* nx=nullptr){
			data_=data;
			next_=nx;
		}

	};
	Node* front_;
	Node* back_;
	int size_;

public:
	SList();
	virtual void push_front(const int& data);
	virtual void push_back(const int& data);
	virtual void pop_front();
	virtual void pop_back();
	virtual int frontData() const;
	virtual int backData() const;
	virtual bool empty() const;
	virtual int size() const;
	virtual ~SList();
};


#endif