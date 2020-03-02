#include <iostream>
#include <time.h>
using namespace std;

struct Node{
    int Data;
    struct Node* Next;
};


void append(Node * &head, Node * &tail, int data){
    Node *temp = new Node;

    temp->Data = data;
    temp->Next = NULL;

    if(head == NULL){
        head = temp;
        tail = temp;
        temp = NULL;
    }
    else{
        tail->Next = temp;
        tail = temp;
    }

}


void prepend(Node * &head, Node * &tail, int data){
    
    Node *temp = new Node;

    temp->Data = data;

    if(head == NULL){
        head = temp;
        tail = temp;
        head->Next = NULL;
        tail = head;
    }
    else{
        temp->Next = head;
        head = temp;
    }

    
}


void removeNode(Node * &head, Node * &tail, int del){

    bool flag = false;

    Node *last = new Node;
    Node *curr = new Node;
    last = head;
    curr = head->Next;

    if(head == NULL){  // checks if the list is empty

        cout << "Your list is empty. Atleast one node is required to delete\n";
        return;
    }
    else if(head->Next == NULL){  // checks if the list is only one node long
        if(head->Data == del){
            head = NULL;
            tail = head;
            flag = true;
        }
    }
    else if(head->Data == del){ // checks if the head is equal to the del
        last = head;
        head = head->Next;
        delete last;
    }
    else{
        while(curr != NULL && !flag){ // goes through the rest of the list and checks each node
            if(curr->Data != del){
                last = curr;
                curr = curr->Next;
            }
            else{
                last->Next = curr->Next;
                delete curr;
                flag = true;
            }
        }
    }

    if(flag){
        cout << "That node was removed from the list...\n";
    }
    else{
        cout << "That node was not found in the list...\n";
    }
}


void removeFirst(Node * &head, Node * &tail){
    
    Node *temp = new Node;

    if(head == NULL){  // checks if the list is empty

        cout << "Your list is empty. Atleast one node is required to delete\n";
        return;
    }
    else if(head->Next == NULL){  // checks if the list is only one node long
            head = NULL;
            tail = head;      
    }
    else{
        temp = head;
        head = head->Next;
        delete temp;
    }
}



void display(Node *node){

    if(node == NULL){
        cout << "Your list is empty. Atleast one node is required to print\n";
        return;
    }

    while(node != NULL){
        cout << node->Data << "-->";
        node = node->Next;
    }

    if(node == NULL){
        cout << "NULL\n";
    }
}


void findData(Node * node){
    int numNodes = 0;
    int total = 0;
    double avg;
    int largest = node->Data;
    
    if(node == NULL){
        cout << "Your list is empty. Atleast one node is required to look for data\n";
        return;
    }

    while(node != NULL){
        numNodes++;
        total += node->Data;
        if(node->Data > largest){
            largest = node->Data;
        }

        node = node->Next;
    }
    avg = total/numNodes;
    cout << "Average: " << avg << endl
         << "Largest: " << largest << endl
         << "Number of Nodes: " << numNodes << endl;
}

int main(){
    srand(time(NULL));

    int choice;

    Node *head = new Node;
    Node *tail = new Node;;
    head = NULL;
    tail = head;

    do{

    cout << "1.Print List | 2.Add Ten Random Numbers| 3.Prepend | 4.append | 5.Remove | 6.Find data | 7.QUIT\n";
    cin >> choice;

    if(choice == 1){
        display(head);
    }
    else if(choice == 2){
        for(int i=0; i<10 ;i++){
            choice = rand()% 100+1;
            append(head, tail, choice);
        }
        display(head);
    }
    else if(choice == 3){
        cout << "What number woudl you like to prepend\n";
        cin >> choice;
        prepend(head, tail, choice);
    }
    else if(choice == 4){   
        cout << "What number woudl you like to append\n";
        cin >> choice;
        append(head, tail, choice);
    }
    else if(choice == 5){
        cout << "1.Remove first node | 2.Search for node | 3.Go back\n";
        cin >> choice;
        if(choice == 1){
            removeFirst(head, tail);
        }
        else if(choice == 2){
            cout << "What number would you like to remove?\n";
            cin >> choice;
            removeNode(head, tail, choice);
        }
        else if(choice == 3){
          
        }
        else{
            cout << "Your did not enter a vaild option\n";
        }
    }
    else if(choice == 6){
        findData(head);
    }
    else if(choice == 7){
        break;
    }
    cout << endl;
    }while(true);



    return 0;
}