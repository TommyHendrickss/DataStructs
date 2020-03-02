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


void remove(){


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
             << node->idNum << endl;
        node = node->Next;
    }

    if(node == NULL){
        cout << "NULL\n";
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