#include <iostream>
#include <fstream>
using namespace std;


struct Node{
    int idNum;
    string fname, lname;
    Node *Next;
};


void readTxt(Node * &head, Node * &tail){
    string tempf, templ;
    int tempID;

    fstream input;
    input.open("class_list.txt");

    while(!input.eof()){
        input >> tempf >> templ >> tempID;
        Node *temp = new Node;

        temp->fname = tempf;
        temp->lname = templ;
        temp->idNum = tempID;
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
}


void prepend(Node*&head, Node*&tail, string tempf, string templ, int tempID){
    Node *temp = new Node;

    temp->fname = tempf;
    temp->lname = templ;
    temp->idNum = tempID;

    if(head == NULL){
        head = temp;
        tail = temp;
        tail = head;
    }
    else{
        temp->Next = head;
        head = temp;
    }

}


void append(Node*&head, Node*&tail, string tempf, string templ, int tempID){
    Node *temp = new Node;

    temp->fname = tempf;
    temp->lname = templ;
    temp->idNum = tempID;
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


void remove(Node*&head, Node*&tail, int del){
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
        if(head->idNum == del){
            head = NULL;
            tail = head;
            flag = true;
        }
    }
    else if(head->idNum == del){ // checks if the head is equal to the del
        last = head;
        head = head->Next;
        delete last;
    }
    else{
        while(curr != NULL && !flag){ // goes through the rest of the list and checks each node
            if(curr->idNum != del){
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

}


void sort(){


}


void displayList(Node *node){

    if(node == NULL){
        cout << "Your list is empty. Atleast one node is required to print...\n";
    }

    while(node != NULL){
        cout << node->fname << ' ' 
             << node->lname << endl 
             << "ID number: " << node->idNum << endl;
        node = node->Next;
    }
}


int main(){

Node *head = new Node;
Node *tail = new Node;
head = NULL;
tail = head;

readTxt(head, tail);

/*
displayList(head);
prepend(head, tail, "Billy", "Bob", 7878);
append(head, tail, "Billy", "Bob", 7878);
*/

displayList(head);

    return 0;
}