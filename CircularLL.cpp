#include <iostream>
using namespace std;
class node{
    public:
    int data;
    node* next;
// constructor
    node(int data){
        this -> data = data;
        this -> next = NULL;
    }
// destructur
    ~node() {
       int value = this -> data;
       //memory free
       if(this -> next == NULL){
        delete next;
       this -> next = NULL;
       }
       cout << "memory is free for node with data " << value << endl;
    }
};

void insertnode(node* &tail, int element, int d){

    // empty list
    if(tail == NULL){
        node* newnode = new node(d);
        tail = newnode;
        newnode -> next = newnode;
    }
    else{
        // non empty list
       // assuming that the element is present in the list
       node* curr = tail;
       while(curr -> data != element){
        curr  = curr -> next;
       }

       //element found : curr is representing element wala node
       node* temp = new node(d);
       temp -> next = curr -> next;
       curr -> next = temp;
    }
}

void print(node* &tail){
    node* temp = tail;
   if(tail == NULL){
    cout << "LIST IS EMPTY " << endl;
    return;
   }
    do{
        cout << tail -> data << " ";
        tail = tail -> next;
    } while(tail != temp);
    cout << endl;
}

void deletenode(node* &tail, int value){
    // empty list 
    if(tail == NULL){
        cout << "List is empty , check again " << endl;
        return;
    }

    //non-empty
    //assuming that value present in LL
    node* prev = tail;
    node* curr = prev -> next;

    while(curr -> data != value){
        prev = curr;
        curr = curr -> next;
    }
    prev -> next = curr -> next;
    // one node LL
    if(curr == prev){
        tail = NULL;
    }
    // >= 2 node
    else if(tail == curr){
        tail = prev;
    }

    curr -> next = NULL;
    delete curr;
}

int main(){
    node* tail = NULL;
   // empty list me insert krna
    insertnode(tail,5,3);
    print(tail);

    insertnode(tail, 3, 5);
    print(tail);

    insertnode(tail, 5, 7);
    print(tail);

    insertnode(tail, 7, 9);
    print(tail);

    insertnode(tail, 5, 6);
    print(tail);

    deletenode(tail, 3);
    print(tail);
}