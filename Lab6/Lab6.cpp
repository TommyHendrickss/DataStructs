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

    // if the list is empty
    if(head == NULL){
        head = temp;
        tail = temp;
        head->Prev = NULL;
        head->Next = NULL;
        temp = NULL;
        return;
    }
    
    // if the list is only one node long it checks if it should insert at the beginning or the end.
        if(node->Data >= x){
            temp->Next = head;
            temp->Prev = NULL;
            head->Prev = temp;
            head = temp;
            return;
        }
        

    // This goes through the list till it finds the point of insertion

    while(node->Next != NULL && node->Next->Data < x){
        node = node->Next;
    }
    
    cout << node->Data << endl;

    // if node == tail
    if(node == tail){
        append(head, tail, x);
    }

    // putting it where it belongs in the list
    else{
        node->Next->Prev = temp;
        temp->Prev = node;
        temp->Next = node->Next;
        node->Next = temp;
    }
}


void deleteNode(Node *&head, Node *&tail, int x){
    
    Node *node = head;

    if(head == NULL){
        cout << "Your list is empty. Try adding a node or two\n";
        return;
    }
    else if(head->Next == NULL){
        cout << "You only have one node in the list so you cant delete it\n";
        return;
    }

    while(node != NULL){
        if(node->Data == x){
            break;
        }
    }

    // if your deleting the head
    if(node == head){
        node->Next->Prev = NULL;
        head = node->Next;
        delete node;
    }
    // if your deleting the tail
    else if(node == tail){

    }
    // if your deleting anyhting else

}


void fillList(Node*&head, Node*&tail){
    int temp;

    for(int i=0; i<10 ;i++){
        temp = ( rand()%100 ) +1;

        appendInOrder(head, tail, temp);
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

    append(head, tail, 10);

    do{
        cout << "1.Display | 2.Append Ten Nodes | 3.Delete | 4.Append in Order\n";
        cin >> c;

        if(c==1){
            display(head);
        }
        else if(c==2){
            fillList(head, tail);
            
        }
        else if(c==3){
            cout << "What number would you like to delete?\n";
            cin >> c;   
            deleteNode(head,tail,c);
        }
        else if(c==4){
            cout << "What number would you like to insert?\n";
            cin >> c;
            appendInOrder(head, tail, c);
        }
    }while(true);


    return 0;
}
