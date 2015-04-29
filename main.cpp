#include "Final.h"

using namespace std;

string fileRead[100];
int readLength = 0;


// Global Variables
bool exitCon = false;
Network *Net = new Network(10);
void display (){
    cout << "======Main Menu====="<<endl;
    cout << "1. Build Network"<<endl;
    cout << "2. Print Network Path"<<endl;
    cout << "3. Enqueue"<<endl;
    cout << "4. Dequeue"<<endl;
    cout << "5. Print Queue"<<endl;
    cout << "6. Send Entire Message"<<endl;
    cout << "7. Bubble Sort Alphabetically"<<endl;
    cout << "8. Bubble Sort by Population"<<endl;
    cout << "9. Add City"<<endl;
    cout << "10.Delete City"<<endl;
    cout << "11. Quit"<<endl;
}

bool loadFile(){ // Hardcoded to load messageIn.txt because im lazy.
    string word;
    ifstream file;

    file.open("messageIn.txt");

    if (file.is_open()){
        while (!file.eof()){
            file >> word;
            fileRead[readLength] = word;;
            readLength++;
            if (word == "weird."){
                break;
            }
        }
        file.close();
        return 1;
    }
    else {cout<<"Failed to open file."<<endl;return 0;}
}


bool input(int choice){
    bool valid = false;
    string target;
    int Itarget;
    if      (choice == 1) {Net->buildNetwork();       valid=true;}
    else if (choice == 2) {Net->printPath();          valid=true;}
    //else if (choice == 3) {Net->enqueue(fileRead[x]); valid=true;}
    //else if (choice == 4) {Net->deQueue();            valid=true;}
    //else if (choice == 5) {Net->printQueue();         valid=true;}
    //else if (choice == 6) {Net->sendMessage(readLength,fileRead);        valid=true;}
    else if (choice == 7) {cout<< "Enter 1 for HIGH->LOW, or 0 for LOW->HIGH:"<<endl;cin>>Itarget;cin.get();if (Itarget==1)Net->bubbleSortAlphabetically();else Net->bubbleSortAlphabeticallyLow();valid = true;}
    else if (choice == 8) {cout<< "Enter 1 for HIGH->LOW, or 0 for LOW->HIGH:"<<endl;cin>>Itarget;cin.get();if (Itarget==1)Net->bubbleSortNumerically();else Net->bubbleSortNumericallyLow();valid = true;}
    else if (choice == 9) {cout<<"Enter name:"<<endl;getline(cin,target);cout<<"Enter population"<<endl;cin>>Itarget;cin.get();Net->addNode(target,Itarget);valid=true;}
    else if (choice == 10){cout<<"Enter name:"<<endl;getline(cin,target);Net->deleteNode(target); valid = true;}
    else if (choice == 11) {exitCon = true;            valid=true;}
    return valid;
}

int main()
{
    cout << "CSCI 2270 Final Project" << endl << "By Christopher Pifer" << endl;
    cout << "Start by building the network, then explore the added functionality (7-10)!" << endl;
    cout << endl;
    cout << "Note: The functions from assignment 4 (3-6) have been disabled since they require external text files and aren't relevant to the new additions."<<endl;
    cout << endl;
    cout << "The default list of 10 cities is loaded with their actual populations! (for sorting)" << endl << endl;
    //loadFile();
    int inputParameter;
    while (!exitCon){
        display();
        cin >> inputParameter;
        cin.get();
        if (!input(inputParameter)){
            cout << "Invalid input."<<endl;
        }
    }
    cout<< "Goodbye!"<<endl;
    Net->clr();
    //
    //~Net;
    return 0;
}

