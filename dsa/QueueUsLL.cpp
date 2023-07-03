#include<iostream>
using namespace std;
class node{
    public:
    int data;
    node* next;
    node(int val){
        data=val;
        next=NULL;
    }
};
class Queue{
    node* front;
    node* back;
    public:
    Queue(){
        front=NULL;
        back=NULL;
    }
    void Enqueue(int x){
        node* n=new node(x);
        if(front==NULL){
            back=n;
            front=n;
            return;
        }
        back->next=n;
        back=n;
    }
    void Dequeue(){
        if(front==NULL){
            cout<<"Queue underflow\n";
            return;
        }
        node* todelete=front;
        front=front->next;
        delete todelete;
    }
    int peek(){
        if(front==NULL){
            cout<<"NO element in Queue\n";
            return -1;
        }
        return front->data;
    }
    bool empty(){
        if(front ==NULL){
            return true;
        }
        return false;
    }
};
int main(){
    Queue q;
	q.Enqueue(5);
	q.Enqueue(8);
	q.Enqueue(9);
	cout<<q.peek()<<endl;
	q.Dequeue();
	cout<<q.peek()<<endl;
    q.Dequeue();
    cout<<q.empty()<<endl;
	return 0;
}