#include <iostream>
using namespace std;
struct NODE{
    int key;
    NODE* p_next;
};
struct List{
    NODE* p_head;
    NODE* p_tail;
};
NODE* createNode(int data){
    NODE *p=new NODE;
    p->key=data;
    p->p_next=NULL;
    return p;   
}
List* createList(){
    List *L=new List;
    L->p_head=NULL;
    L->p_tail=NULL;
    return L;
}
void addHead(List *&L, int data){
    NODE *p= createNode(data);
    p->p_next=L->p_head;
    L->p_head=p;
}
void addTail(List *&L, int data){
    NODE *p= createNode(data);
   if(L->p_head==NULL){
       addHead(L,data);
       return;
   }
    NODE *temp=L->p_head;
    for(temp;temp->p_next!=NULL;temp=temp->p_next);
    temp->p_next=p;
    p->p_next=nullptr;
}

void print(List *L){
    NODE *temp=L->p_head;
    for(temp;temp!=NULL;temp=temp->p_next){
        cout<<temp->key<<" ";
    }
    delete temp;
}
void removeHead(List * &L){
    NODE *x;
    x=L->p_head;
    L->p_head=x->p_next;
    x->p_next=NULL;
    delete x;
}
void removeTail(List* &L){
    NODE *temp= L->p_head;
    if(L->p_head->p_next==NULL){
        NODE *n= L->p_head->p_next;
        L->p_head=NULL;
        delete n;
        return;
    }
    for(temp;temp->p_next->p_next!=NULL;temp=temp->p_next);
    NODE *x=temp->p_next;
    temp->p_next=NULL;
    L->p_tail=temp;
    delete x;
}
void removeAll(List* &L){
    while(L->p_head!=NULL){
        removeHead(L);
    }
}
void removeBefore(List* &L, int val){
    NODE *temp=L->p_head;
    for(temp;temp->p_next!=NULL;temp=temp->p_next){
        if(temp->p_next->p_next==NULL){
            break;
        }
        else if(temp->p_next->p_next->key==val){
            NODE *x=temp->p_next;
            temp->p_next=temp->p_next->p_next;
            x->p_next=NULL;
            delete x;
        }
        if(  temp->p_next->key==val&& temp ==L->p_head){
            removeHead(L);
        }
    }
        
}
void removeAfter(List* &L, int val){
    NODE *temp=L->p_head;
    for(temp;temp->p_next!=NULL;temp=temp->p_next){
        if(temp->p_next->key==val){
            NODE *x=temp->p_next->p_next;
            temp->p_next->p_next=temp->p_next->p_next->p_next;
            x->p_next=NULL;
            delete x;
        }
        if(  temp->key==val&& temp ==L->p_head){
            NODE *x=temp->p_next;
            temp->p_next=temp->p_next->p_next;
            x->p_next=NULL;
            delete x;
        }
    }
}
bool addPos(List* &L, int data, int pos){
    if(pos==0){
        addHead(L,data);
    }
    int i=1;
    NODE *temp=L->p_head;
    for(temp;temp->p_next!=NULL;temp=temp->p_next){
        if(i==pos)break;
        i++;
    }
    if(temp->p_next==NULL){
        return false ;
    }
    NODE *n=createNode(data);
    n->p_next=temp->p_next;
    temp->p_next=n;
    return true;
}
void RemovePos(List* &L, int data, int pos){
    if(pos==0){
        removeHead(L);
        return ;
    }
    int i=1;
    NODE *temp=L->p_head;
    for(temp;temp->p_next!=NULL;temp=temp->p_next){
        if(i==pos)break;
        i++;
    }
    if(temp->p_next==NULL){
        return  ;
    }
    NODE *n=temp->p_next;
    temp->p_next=temp->p_next->p_next;
    n->p_next=NULL;
    delete n;
    return ;
}
bool addBefore(List* &L, int data, int val){
    if(L->p_head->key==val){
        addHead(L,data);
        return true;
    }
    NODE *temp=L->p_head;
    for(temp;temp->p_next!=NULL;temp=temp->p_next){
        if(temp->p_next->key==val){
            NODE *p=createNode(data);
            p->p_next=temp->p_next;
            temp->p_next=p;
            return true; 
        }
    }
    return false;
}
bool addAfter(List* &L, int data, int val){
    if(L->p_head->key==val){
        addPos(L,data,1);
        return true;
    }
    NODE *temp=L->p_head;
    for(temp;temp!=NULL;temp=temp->p_next){
        NODE *p=createNode(data);
        if(temp->p_next==NULL&&temp->key==val){
            p->p_next=NULL;
            temp->p_next=p;
            return true;
        }
        if(temp->key==val){
            p->p_next=temp->p_next;
            temp->p_next=p; 
            return true; 
        }
        
    }
    return false;
}
int countElements(List* L){
    int count=0;
    NODE *temp=L->p_head;
    for(temp;temp!=NULL;temp=temp->p_next){
        count++;
    }
    return count;
}
List* reverseList(List* L){
    List *rever ;
    rever= createList();
    while(L->p_head!=NULL){
    NODE *temp=L->p_head;
    for(temp;temp->p_next!=nullptr;temp=temp->p_next);
    addTail(rever,temp->key);
    removeTail(L);
    }
    return rever;
}
void removeDuplicate(List* &L){
    NODE *temp=L->p_head;
    for(temp;temp!=NULL;temp=temp->p_next){
        NODE *temp2=temp->p_next;
        for(temp2;temp2!=NULL;temp2=temp2->p_next){
            if(temp2->key==temp->key){
                removeBefore(L,temp2->p_next->key);
            }
        }
    }
}
bool removeElement(List* &L, int key){
    NODE *temp=L->p_head;
    if(L->p_head->key==key){
        removeHead(L);
        temp=L->p_head;

    }
    for(temp;temp->p_next!=NULL;temp=temp->p_next){
        if(temp->p_next->key==key){
            if(temp->p_next->p_next==NULL){
                removeTail(L);
                break;
            }
            NODE *x=temp->p_next;
            temp->p_next=temp->p_next->p_next;
            delete x;
        }
    }
    temp =L->p_head;
    for(temp;temp->p_next!=NULL;temp=temp->p_next){
        if(temp->key==key){
            return false;
        }
    }
    return true;
}
int main(){
    List *L;
    L=createList();
    int arr[5]={1,2,5,4,5};
    for(int i=0;i<5;i++){
        addHead(L,arr[i]);
    }
    print(L);
   if( removeElement(L,4)){
       cout<<"1 ";
   }
   else {
       cout<<"0 ";
   }
    // List *rever=reverseList(L);
    
    print(L);
    return 0;
}