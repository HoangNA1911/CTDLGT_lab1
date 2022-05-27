#include <iostream>
using namespace std;
 NODE *front=new NODE, *rear=new NODE;
 NODE *top= new NODE;
struct NODE{
int key;
NODE* pNext;
};
typedef NODE node;
//stack...
void Initialize(){
    top=NULL;
}
void push(int data){
    NODE *p=new NODE ;
    p->pNext=top;
    p->key=data;
    top=p;
}
void pop(){
    if(top==NULL){
        cout<<"loi";
        return;
    }
    else{
        NODE *temp;
        temp=top;
        top=top->pNext;
        temp->pNext=NULL;
        delete temp;
    }
}
int count(){
    NODE *temp;
    int countele=0;
    for(temp;temp->pNext!=NULL;temp=temp->pNext){
        countele++;
    }
    return countele;
}
bool isempty(){
    return top==NULL;
}
//queue
void InitializeQueue(){
    front=NULL;
    rear=nullptr;
}
void enQueue(int data){
    NODE *temp;
    temp=new NODE;
    temp->key=data;
    temp->pNext=NULL;
    if(rear==NULL){
        front=temp;
        rear =temp;
        return;
    }
    rear->pNext=temp;
    rear=temp;
}
void deQueue(){
    if(front==NULL){
        return ;
    }
    NODE *temp=front;
    front=front->pNext;
    temp->pNext=NULL;
    if(front==NULL) rear==NULL;
    delete temp;
}
int countQueue(){
    NODE *temp;
    int countele=0;
    for(temp;temp->pNext!=NULL;temp=temp->pNext){
        countele++;
    }
    return countele;
}
bool QueueInempty(){
    return front==NULL;
}
int main(){
    
    Initialize();
   
    return 0;
}