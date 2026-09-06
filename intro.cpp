#include<iostream>
using namespace std;
class Node{
    public:
        int data;
        Node* next;
    Node(int value){
        this->data=value;
        this->next=NULL;
    }

};
void InsertATHead(int value,Node* &head,Node* &tail){
    if(head==NULL && tail==NULL){
        Node* newNode=new Node(value);
        head=newNode;
        tail=newNode;
    }
    else{
        Node* newNode=new Node(value);
        newNode->next=head;
        head=newNode;
    }
    // return head;
};
void InsertATTail(int value,Node* &head,Node* &tail){
    if(head==NULL && tail==NULL){
        Node* newNode=new Node(value);
        head=newNode;
        tail=newNode;
    }
    else{
        Node* newNode=new Node(value);
        tail->next=newNode;
        tail=newNode;
    }
    // return tail;
};
void print(Node* head){
    Node* temp=head;
    while(temp !=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}
bool search(int target,Node* &head){
    Node* temp=head;
    while(temp!=NULL){
        if(temp->data==target){
            return true;
        }
        else{
            temp=temp->next;
        }
    }
    return false;
    
}
int getlengthoflinkedlist(Node* head){
    int len=0;
    Node* temp=head;
    while(temp!=NULL){
        len++;
        temp=temp->next;
    }
    return len;
}

void insertAtposition(int position,int value,Node* &head,Node*&tail){
    if(position ==1){
        InsertATHead(value,head,tail);
        return;
    }
    int length=getlengthoflinkedlist(head);
    if(position == length+1){
        InsertATTail(value,head,tail);
        return;
    }
    else{
        Node*newNode=new Node(value);
        Node* temp=head;
        for(int i=1;i<=position-2;i++){
            temp=temp->next;
        }
        newNode->next=temp->next;
        temp->next=newNode;


    }
}
void deletell(int position,Node*&head,Node*&tail){
    int length=getlengthoflinkedlist(head);
    if(position >length){
        return;
    }
    if(head==NULL && tail==NULL){
        return;
    }
    if(head==tail && position==1){
        Node* temp=head;
        head=NULL;
        tail=NULL;
        delete temp;
        return;
    }
    if(position==1){
        Node*temp=head;
        head=head->next;
        temp->next=NULL;
        delete temp;
        return;
    }
    else{
        Node* previous=head;
        for(int i=1;i<=position-2;i++){
            previous=previous->next;
        }
        Node* current=previous->next;
        Node* forward=current->next;
        current->next=NULL;
        previous->next=forward;
        delete current;

    }
}


int main(){
    Node* head=NULL;
    Node* tail=NULL;
    InsertATHead(10,head,tail);
    InsertATHead(30,head,tail);
    InsertATTail(20,head,tail);
  
    print(head);
    // cout<<search(100,head);
    insertAtposition(2,500,head,tail);
    deletell(3,head,tail);
    print(head);
    return 0;
}