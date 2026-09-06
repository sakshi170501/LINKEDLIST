#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* prev;
    Node* next;

    Node(int value) {
        data = value;
        prev = NULL;
        next = NULL;
    }
};

void insertathead(Node* &head, Node* &tail, int value) {
    if (head == NULL && tail == NULL) {
        Node* newNode = new Node(value);
        head = newNode;
        tail = newNode;
    }
    else {
        Node* newNode = new Node(value);
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
}

void print(Node* head) {
    Node* temp = head;

    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }

    cout << endl;
}

void printreverse(Node* tail) {
    Node* temp = tail;

    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->prev;
    }

    cout << endl;
}

void InsertATTail(int value, Node* &head, Node* &tail) {
    if (head == NULL && tail == NULL) {
        Node* newNode = new Node(value);
        head = newNode;
        tail = newNode;
    }
    else {
        Node* newNode = new Node(value);
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
}

int getlen(Node* &head) {
    Node* temp = head;
    int count = 0;

    while (temp != NULL) {
        count++;
        temp = temp->next;
    }

    return count;
}

void insertAtposition(int position, int value, Node* &head, Node* &tail) {

    int len = getlen(head);

    if (position == 1) {
        insertathead(head, tail, value);
    }
    else if (position == len + 1) {
        InsertATTail(value, head, tail);
    }
    else {
        Node* temp = head;

        // Move to position-1 node
        for (int i = 1; i < position - 1; i++) {
            temp = temp->next;
        }

        Node* newnode = new Node(value);
        Node* forward = temp->next;

        temp->next = newnode;
        newnode->prev = temp;

        newnode->next = forward;
        forward->prev = newnode;
    }
}
bool search(int target,Node* head,Node* tail){
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
void deletef(int position, Node* &head, Node* &tail) {

    int length = getlen(head);

    if(head == NULL && tail == NULL){
        return;
    }

    if(length < position){
        return;
    }

    if(head == tail && position == 1){
        Node* temp = head;
        head = NULL;
        tail = NULL;
        delete temp;
        return;
    }

    if(position == 1){
        Node* temp = head;

        head = head->next;
        head->prev = NULL;

        temp->next = NULL;
        delete temp;
        return;
    }
     if(position==length){
        Node* temp=tail;
        tail=temp->prev;
        tail->next=NULL;
        temp->prev=NULL;
        delete temp;
    }

    else{
        Node* backward = head;

        for(int i = 1; i < position - 1; i++){
            backward = backward->next;
        }

        Node* curr = backward->next;
        Node* forward = curr->next;

        backward->next = forward;
        forward->prev = backward;

        curr->next = NULL;
        curr->prev = NULL;

        delete curr;
    }
   
}
void reverselinkedlist(Node* &head){
    if(head==NULL){
        return;
    }
    Node* prev=NULL;
    Node* curr=head;
    while(curr!=NULL){
        Node* forward=curr->next;
        curr->next=prev;
        prev=curr;
        curr=forward;
    }
    head=prev;
}
Node* reverse(Node* &head, Node* prev) {
    if (head == NULL) {
        return prev;
    }

    Node* curr = head;
    Node* forward = curr->next;

    curr->next = prev;

    return reverse(forward, curr);
}
//returns the mid node of linked list
Node* getMidNode(Node* head){
    Node* slow=head;
    Node* fast=head;
    while(fast!=NULL && fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
    }
    return slow;

}
bool checkPalindrome(Node* head) {

    int len = getlengthoflinkedlist(head);

    Node* mid = getMidNode(head);

    Node* finalmid = NULL;

    if(len & 1) {
        finalmid = mid->next;
    }
    else {
        finalmid = mid;
    }

    reverselinkedlist(finalmid);

    Node* temp = head;

    while(temp != NULL && finalmid != NULL) {

        if(temp->data != finalmid->data) {
            return false;
        }

        temp = temp->next;
        finalmid = finalmid->next;
    }

    return false;
}
int main() {

    Node* head = NULL;
    Node* tail = NULL;

    insertathead(head, tail, 10);
    insertathead(head, tail, 20);
    insertathead(head, tail, 30);

    InsertATTail(40, head, tail);

    print(head);
    printreverse(tail);

    insertAtposition(3, 420, head, tail);
    if (search(10, head, tail)) {
    cout << "Found" << endl;
}
else {
    cout << "Not Found" << endl;
}
   print(head);
   deletef(5,head,tail);
   print(head);
//    reverselinkedlist(head);
   Node*prev=NULL;
   head=reverse(head,prev);
   print(head);
   Node*mid=getMidNode(head);
   cout<<mid->data<<endl;
   checkPalindrome(head);
   

    return 0;
}