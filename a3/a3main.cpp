/****************************************************/
/*                                                  */
/*  BTP600                                          */
/*  a3 tester                                       */
/*                                                  */
/*  To compile:                                     */
/*      c++ a3main.cpp linkedlist.cpp -std=c++0x    */
/*                                                  */
/****************************************************/


#include "adapter.h"
#include <iostream>
using namespace std;

int main(void){

    Queue* q=new ObjectAdapter();
    if(q->isEmpty() && q->numItems()==0){
        cout << "test 1 passed" << endl;
    }
    else{
        cout << "test 1 failed " << endl;
    }

    q->enqueue(5);
    q->enqueue(10);
    q->enqueue(11);
    if(!q->isEmpty() && q->numItems()==3 && q->front() == 5){
        cout << "test 2 passed" << endl;
    }
    else{
        cout << "test 2 failed " << endl;
    }


    q->dequeue();
    if(!q->isEmpty() && q->numItems()==2 && q->front() == 10){
        cout << "test 3 passed" << endl;
    }
    else{
        cout << "test 3 failed " << endl;
    }

    q->enqueue(15);
    if(!q->isEmpty() && q->numItems()==3 && q->front() == 10){
        cout << "test 4 passed" << endl;
    }
    else{
        cout << "test 4 failed " << endl;
    }

    q->dequeue();
    if(!q->isEmpty() && q->numItems()==2 && q->front() == 11){
        cout << "test 5 passed" << endl;
    }
    else{
        cout << "test 5 failed " << endl;
    }


    q->dequeue();
    if(!q->isEmpty() && q->numItems()==1 && q->front() == 15){
        cout << "test 6 passed" << endl;
    }
    else{
        cout << "test 6 failed " << endl;
    }

    q->dequeue();
    if(q->isEmpty() && q->numItems()==0){
        cout << "test 7 passed" << endl;
    }
    else{
        cout << "test 7 failed " << endl;
    }
    delete q;
    q=new ClassAdapter();
    if(q->isEmpty() && q->numItems()==0){
        cout << "test 8 passed" << endl;
    }
    else{
        cout << "test 8 failed " << endl;
    }

    q->enqueue(5);
    q->enqueue(10);
    q->enqueue(11);
    if(!q->isEmpty() && q->numItems()==3 && q->front() == 5){
        cout << "test 9 passed" << endl;
    }
    else{
        cout << "test 9 failed " << endl;
    }


    q->dequeue();
    if(!q->isEmpty() && q->numItems()==2 && q->front() == 10){
        cout << "test 10 passed" << endl;
    }
    else{
        cout << "test 10 failed " << endl;
    }

    q->enqueue(15);
    if(!q->isEmpty() && q->numItems()==3 && q->front() == 10){
        cout << "test 11 passed" << endl;
    }
    else{
        cout << "test 11 failed " << endl;
    }

    q->dequeue();
    if(!q->isEmpty() && q->numItems()==2 && q->front() == 11){
        cout << "test 12 passed" << endl;
    }
    else{
        cout << "test 12 failed " << endl;
    }


    q->dequeue();
    if(!q->isEmpty() && q->numItems()==1 && q->front() == 15){
        cout << "test 13 passed" << endl;
    }
    else{
        cout << "test 13 failed " << endl;
    }

    q->dequeue();
    if(q->isEmpty() && q->numItems()==0){
        cout << "test 14 passed" << endl;
    }
    else{
        cout << "test 14 failed " << endl;
    }
    delete q;	

}