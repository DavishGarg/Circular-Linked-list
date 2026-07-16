#include <iostream>
using namespace std;
class node{
    public:
    int data;
    node* next;
    
    node(int d){
        this-> data = d;
        this-> next = NULL;
    }
    
    ~node(){
        int value = this -> data;
        if(this->next != NULL){
            delete next;
            this->next = NULL;
        }
        cout << "Memory freed for node with data " << value << endl;
    }
    
};
void insertathead(node* &head, int d){
    node* temp = new node(d);
    temp -> next = head;
    head = temp;
}
void insertattail(node* &tail, int d){
    node* temp = new node(d);
    tail -> next = temp;
    tail = tail -> next;
}
void insertatmiddle(node* &tail,node* &head, int position, int d){
    if(position == 1){
        insertathead(head,d);
        return;
    }
    node* temp = head;
    int cnt = 1;
    while(cnt < position - 1){
        temp = temp -> next;
        cnt++;
    }
    if(temp -> next == NULL){
        insertattail(tail,d);
        return;
    }
    node* newnode = new node(d);
    newnode -> next = temp -> next;
    temp -> next = newnode;
}
void deletenode(int position, node* &head,node* &tail){
    if(position == 1){
        node* temp = head;
        head= head -> next;
        temp-> next = NULL;
        delete temp;
    }
    else{
        int cnt = 1;
        node * prev = NULL;
        node * curr= head;
        while(cnt < position){
            prev = curr;
            curr = curr->next;
            cnt++;
        }
        if(curr->next == NULL){
            tail = prev;
        }
        prev->next = curr->next;
        curr->next = NULL;
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

void print(node* &head){
    node* temp = head;
    while(temp != NULL){
        cout << temp -> data << endl;
        temp = temp -> next;
    }
    cout << endl;
}



int main(){
    
    node* node1 = new node(10);
    // cout << node1->data << endl;
    // cout << node1 -> next << endl;
    
    node* head = node1;
    node* tail = node1;
    // print(head);
    
    insertattail(tail, 15);
    // print(head);
    
    insertattail(tail, 20);
    // print(head);
    
    insertattail(tail, 22);
    // print(head);
    
    insertatmiddle(tail,head, 1,99);
    // print(head);
    
    // cout << "Tail " << tail-> data << endl;
    // cout << "head " << head-> data << endl;
    
    // deletenode(2,head,tail);
    // print(head);
    
    // cout << "Tail " << tail-> data << endl;
    // cout << "head " << head-> data << endl;
    tail ->next = head;
if(checkcircularll(tail)){
        cout << "it is circular linked list" << endl;
    }else{
        cout << "it is not circular ll";
    }


    
    
}