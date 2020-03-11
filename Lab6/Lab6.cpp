#include <iostream>
#include <time.h>
using namespace std;


struct Node{
    int Data;
    Node *Next;
    Node *Prev;
};


void append(Node *&head, Node *&tail, int x){
    Node *temp = new Node;

    temp->Data = x;
    temp->Next = NULL;

    if(head == NULL){
        head = temp;
        tail = temp;
        head->Prev = NULL;
        temp = NULL;
    }
    else{
        tail->Next = temp;
        temp->Prev = tail;
        tail = temp;
    }

}

// dont really need this but its her anyways. 
void prepend(Node *&head, Node *&tail, int x){
    Node *temp = new Node;

    temp->Data = x;

    if(head == NULL){
        head = temp;
        tail = temp;
        head->Prev = NULL;
        head->Next = NULL;
        temp = NULL;
    }

    else{
        head->Prev = temp;
        temp->Next = head;
        temp->Prev = NULL;
        head = temp;
    }
    
}


void appendInOrder(Node *&head, Node *&tail, int x){
    Node *node = new Node;
    Node *temp = new Node;
    node = head;

    temp->Data = x;
    temp->Next = NULL;

    if(head == NULL){
        head = temp;
        tail = temp;
        head->Prev = NULL;
        temp = NULL;
    }

    if(node == NULL){
        cout << "Your list is empty. Please add a node to it first...\n";
        return;
    }
    while(node != NULL && node->Data < x){
        node = node->Next;
    }
    
    // if node == head

    // if node == tail

    // putting it where it belongs in the list
}


void fillList(Node*&head, Node*&tail){
    int temp = 0;

    for(int i=0; i<10 ;i++){
        temp += 2;

        append(head, tail, temp);
    }
}


void display(Node *node){

    if(node == NULL){
        cout << "Your list is empty. Please add a node to it first...\n";
        return;
    }

    while(node != NULL){
        cout << node->Data << "<-->";
        node = node->Next;
    }
   
    if(node == NULL){
        cout << "NULL\n";
    }
}


int main(){
    srand(time(NULL));

    int c;

    Node *head = new Node;
    Node *tail = new Node;
    head->Prev = NULL;
    head->Next = NULL;
    head = NULL;
    tail = head;


    do{
        cout << "1.Display | 2.Append | 3.Prepend | 4.Append Ten Node\n";
        cin >> c;

        if(c==1){
            display(head);
        }
        if(c==2){
        cout << "What number would you like to append?\n";
        cin >> c;
        appendInOrder(head, tail, c);
        }
        else if(c==3){

        }
        else if(c==4){
            fillList(head, tail);
        }
    }while(true);


    return 0;
}