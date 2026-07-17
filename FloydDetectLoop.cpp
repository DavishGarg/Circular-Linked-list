#include <iostream>
#include <map>
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

// for loop detection
node* floyddetectloop(node* &head){
    if(head==NULL){
        return NULL;
    }

    node* slow = head;
    node* fast = head;
    while(fast != NULL ){
        fast = fast -> next;
        if(fast != NULL){
            fast = fast -> next;
        }
        slow = slow -> next;

        if(slow == fast){
            cout << " loop present at " << slow -> data << endl;
            return slow;
        }
    }
    return NULL;

}

// for starting point of loop
node* startingpoint(node* &head){
    if(head == NULL){
        return NULL;
    }

    node* intersection =  floyddetectloop(head);
    node* slow = head;

    while(slow != intersection){
        slow = slow -> next;
        intersection = intersection -> next;
    }
    return slow;
}


// remove loop from ll

void removeloop(node* &head){
    if(head == NULL){
        return;
    }

    node* startpoint = startingpoint(head);
    node* temp = startpoint;
    while(temp -> next != startpoint){
        temp = temp -> next;
    }

    temp -> next = NULL;
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
    
    insertattail(tail, 12);
    // print(head);
    
    insertattail(tail, 15);
    // print(head);
    
    insertattail(tail, 22);
    // print(head);
    
    // insertatmiddle(tail,head, 1,99);
    // print(head);
    
    // cout << "Tail " << tail-> data << endl;
    // cout << "head " << head-> data << endl;
    
    // deletenode(2,head,tail);
    // print(head);
    
    // cout << "Tail " << tail-> data << endl;
    // cout << "head " << head-> data << endl;
 

    // make loop ***********
    tail -> next = head -> next;
    //  print(head);
    if(floyddetectloop(head) != NULL){
        cout << "Loop is present" << endl;
    }else{
        cout << "Loop is not present ";
    }

    // fetch start point of loop **************
    node* ans = startingpoint(head);
    cout << "Start point is " << ans -> data<< endl;


    // remove loop*********************
    removeloop(head);
    print(head);
    
}