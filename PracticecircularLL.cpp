#include <iostream>
using namespace std;

class node{
  public:
  int data;
  node* next;
  
  node(int d){
      this->data = d;
      this->next = NULL;
  }
  ~node(){
      int value = this -> data;
      while(this->next != NULL){
          delete next;
          this->next = NULL;
      }
      cout << "Destructor delete " << value << endl;
  }
};
void insertnode(node* &tail, int element, int d){
    if(tail == NULL){
        node* newnode = new node(d);
        tail = newnode;
        newnode->next = newnode;
    }else{
        node* curr = tail;
        while(curr -> data != element){
            curr = curr -> next;
        }
        
        node* temp = new node(d);
        temp -> next = curr -> next;
        curr -> next = temp;
    }
}
void deletenode(node* &tail , int value){
    if(tail == NULL){
        cout << "NOTHING TO DELETE HERE" << endl;
    }else{
        node* prev = tail;
        node* curr = prev -> next;
        
        while(curr->data != value){
            prev = curr;
            curr = curr -> next;
        }
        
        prev -> next = curr -> next;
        if(curr == prev){
            tail = NULL;
        }
        if(tail == curr){
            tail = prev;
        }
        curr -> next = NULL;
        delete curr;
    }
}
bool checkcircularll(node* &tail){
    if(tail == NULL){
        return true;
    }
     node* temp = tail -> next;
       
        while(temp != NULL && temp != tail){
            temp = temp -> next;
        }
    
     if(temp == tail){
            return true;
        }
        else{
            return false;
        }
    }
void print(node* &tail){
    node* temp = tail;
    if(tail == NULL){
        cout << "List is empty " << endl;
        return;
    }
    do{
        cout << temp -> data << endl;
        temp = temp -> next;
    } while(tail != temp);
    cout << endl;
}
int main(){
    node* tail = NULL;
    insertnode(tail, 5, 2);
    print(tail);
    insertnode(tail, 2, 4);
    print(tail);
    insertnode(tail, 4, 6);
    print(tail);
    insertnode(tail, 6, 8);
    print(tail);
    
    insertnode(tail, 4, 1);
    print(tail);
    
    // deletenode(tail,2);
    // print(tail);

    if(checkcircularll(tail)){
        cout << "it is circular linked list" << endl;
    }else{
        cout << "it is not circular ll";
    }
}