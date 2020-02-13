#include <iostream>
#include <vector>
#include <stdlib.h>
#include <fstream> 
using namespace std;


struct name
{
    string first;
    string last;
};


void readNames(vector<name> &list){ // read names from txt file / allocate more space for array if needed
    string tempf, templ;
    ifstream file;
    file.open("clients.txt");
    while(!file.eof()){
        file >> tempf >> templ;
        list.push_back({tempf, templ});
    }
}


void sortFirst(vector<name> &list){ // sort names by first name using bubble sort
    name temp;
    int flag = 1;
    for(int i=0; (i <= list.size()) && flag; i++){
        flag = 0;
        for(int j=0; j<list.size()-1 ;j++){
            if(list[j+1].first < list[j].first){
                temp = list[j];
                list[j] = list[j+1];
                list[j+1] = temp;
                flag = 1;
            }
        }
    }
}


void sortLast(vector<name> &list){ // sort by last name using selection sort
name temp;
int firstNum;
for(int i=list.size(); i>0 ;i--){
    firstNum = 0;
    for(int j=0; j<=i ;j++){
        if(list[j].last > list[firstNum].last){
            firstNum = j;
        }
        temp = list[firstNum];
        list[firstNum] = list[i];
        list[i] = temp;
    }
}

}


void sortAlpha(vector<name> &list){ // sort by alphabetical order last name , first name.


}


void addName(vector<name> &list){ // add names to the array / allocate more space if needed.  
    string tempf, templ;
    do{
        cout << "Enter your first name. Then enter you last name\n" << "If you are finished type \"none\" \n";
        cin >> tempf; cin >> templ;
        if(tempf != "none"){
            tempf[0] = toupper(tempf[0]);
            templ[0] = toupper(templ[0]);
            list.push_back({tempf, templ});
            cout << "The new name has been added to the list...\n";
        }
        else{
            break;
        }

    }while(true);

}
void removeName(vector<name> &list){
    bool flag = false;
    name temp;
    string tempf, templ;
    do{
        cout << "What name would you like to remove from the list?\n" << "Type \"none\" if you are finished";
        cin >> tempf; cin >> templ;
        if(tempf != "none"){
            tempf[0] = toupper(tempf[0]);
            templ[0] = toupper(templ[0]);
            for(int i=0; i<list.size() ;i++){
                if((list[i].first == tempf && list[i].last == templ ) && !flag){
                    list.erase(list.begin()+i);
                    flag = true;
                } 
            }
        }
        else{
            break;
        }
        if(!flag){
            cout << "That name was not found in the list...\n";
        }
        else{
            cout << "That name has been removed...\n";
            flag = false;
        }
    } while(true);

}



void printList(vector<name> &list){
for(int i=0; i < list.size() ;i++){
    cout << list[i].first << ' ' << list[i].last << endl;
}

}


int main(){

    int choice;
    vector<name> list(0);

    readNames(list);

    do{
        cout << "1.Sort by first name | 2.Sort by last name | 3.Sort by alphabetical | 4.Edit list | 5.QUIT\n";
        cin >> choice;
        while(cin.fail()){
            cout << "Please enter a number 1-5\n";
            cin.clear();
            cin.ignore(256, '\n');
            cin >> choice;
        }

    if(choice == 1){
    sortFirst(list);
    cout << "Here is your new list sorted by first name: \n";
    printList(list);
    }

    else if(choice == 2){
    sortLast(list);
    cout << "Here is your new list sorted by last name: \n";
    printList(list);
    }

    else if(choice == 3){
    sortAlpha(list);
    cout << "Here is your new list sorted in alphabetical order: \n";
    printList(list);
    }

    else if(choice == 4){
    cout << "1.Add name | 2.Remove name\n";
    cin >> choice;
    while(cin.fail()){
        cout << "Please enter a number 1 or 2\n";
        cin.clear();
        cin.ignore(256, '\n');
        cin >> choice;
        }
    if(choice == 1){
        addName(list);
    }
    else if(choice == 2){
        removeName(list);
    }
    }


    }while(choice != 5);

        return 0;
}