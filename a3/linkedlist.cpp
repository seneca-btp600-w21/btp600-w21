#include "linkedlist.h"
DList::DList(){
	front_=new Node();
	back_= new Node();
	front_->next_=back_;
	back_->prev_=front_;
	size_=0;
}
DList::~DList(){
	Node* curr=front_;
	while(curr){
		Node* rm=curr;
		curr=curr->next_;
		delete rm;
	}
}


void DList::push_front(const int& data){
	Node* nn=new Node(data,front_->next_,front_);
	front_->next_->prev_=nn;
	front_->next_=nn;
	size_++;
}
void DList::push_back(const int& data){
	Node* nn=new Node(data,back_,back_->prev_);
	back_->prev_->next_=nn;
	back_->prev_=nn;
	size_++;
}
void DList::pop_front(){
	if(size_!=0){
		Node* rm = front_->next_;
		Node* second = rm->next_;
		second->prev_=front_;
		front_->next_=second;
		size_--;
		delete rm;
	}
}
void DList::pop_back(){
	if(size_!=0){
		Node* rm=back_->prev_;
		Node* secondLast=rm->prev_;
		secondLast->next_=back_;
		back_->prev_=secondLast;
		size_--;
		delete rm;
	}
}
bool DList::empty() const{
	return size_==0;
}
int DList::size() const{
	return size_;
}
int DList::frontData() const{
	return front_->next_->data_;
}
int DList::backData() const{
	return back_->prev_->data_;
}

SList::SList(){
	front_=nullptr;
	back_=nullptr;
	size_=0;
}
SList::~SList(){
	Node* curr=front_;
	while(curr){
		Node* rm=curr;
		curr=curr->next_;
		delete rm;
	}
}


void SList::push_front(const int& data){
	Node* nn=new Node(data,front_);
	front_=nn;
	if(back_==nullptr){
		back_=nn;
	}
	size_++;
}
void SList::push_back(const int& data){
	Node* nn=new Node(data);
	if(back_){
		back_->next_=nn;
	}
	else{
		front_=nn;

	}
	back_=nn;
	size_++;
}
void SList::pop_front(){
	if(size_!=0){
		Node* rm = front_;
		front_=front_->next_;
		if(front_==nullptr){
			back_=nullptr;
		}
		size_--;
		delete rm;
	}
}
void SList::pop_back(){
	if(size_!=0){
		Node* rm=back_;
		if(front_==back_){
			front_=nullptr;
			back_=nullptr;
		}
		else{
			Node* curr=front_;
			while(curr->next_!=back_){
				curr=curr->next_;
			}
			back_=curr;
		}
		size_--;
		delete rm;
	}
}
bool SList::empty() const{
	return size_==0;
}
int SList::size() const{
	return size_;
}
int SList::frontData() const{
	return front_->data_;
}
int SList::backData() const{
	return back_->data_;
}
