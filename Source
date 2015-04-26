// Final project
// Extended from CSCI Assignment 4
// By Chris Pifer

#include <iostream>
#include <string>
#include <sstream>
#include <stdlib.h>
#include <fstream>


using namespace std;

struct city {
    string name;
    string message;
    int pop; // population.
    city *next;
    city *prev;
};
string fileRead[100];
int readLength = 0;
int x = 0;
int fakeHead = 0; // These track the number of enqueues and dequeues for COG
int fakeTail = 0; // Nothing to do with any implementation.

// Communication network class
class Network {
    public:
        Network(int qs){
            queueSize = qs;
            arrayQueue = new string[queueSize];
            queueHead = 0;
            queueTail = 0;
        }
        ~Network();
        // METHODS
        void swapNodes(city *first, city *second){ // switches two nodes in the linked list.
            city temp;
            temp = *first;
            city *Tnext = NULL; Tnext = first->next;
            city *Tprev = NULL; Tprev = first->prev;
            *first = *second;
            first->next = Tnext;
            first->prev = Tprev;

            Tnext = second->next;
            Tprev = second->prev;

            *second = temp;
            second->next = Tnext;
            second->prev = Tprev;
        }
        // Bubble sorts the list alphabetically by city name.
        void bubbleSortAlphabetically (){
            bool op = true;
            while (op){
                op = false;
                city *temp = networkHead;
                while (temp->next){
                    if (temp->name.compare(temp->next->name) > 0){
                        swapNodes(temp,temp->next);
                        op = true;
                    }
                    temp = temp->next;
                }
            }
        }
        //Bubble sorts the list numerically by population.
        //Orders HIGH -> LOW
        void bubbleSortNumerically(){
            cout << "Bubble sorting list by population: HIGH -> LOW" << endl;
            bool op = true;
            while (op){
                op = false;
                city *temp = networkHead;
                while (temp->next){
                    if (temp->next->pop > temp->pop){
                        swapNodes(temp,temp->next);
                        op = true;
                    }
                }
            }
        }
        //Bubble sorts the list numerically by population
        //Orders LOW -> HIGH
        void bubbleSortNumericallyLow(){
            cout << "Bubble sorting list by population: LOW -> HIGH" << endl;
            bool op = true;
            while (op){
                op = false;
                city *temp = networkHead;
                while (temp->next){
                    if (temp->next->pop < temp->pop){
                        swapNodes(temp,temp->next);
                        op = true;
                    }
                }
            }
        }
        void printPath(){ // Printing for network path
             city *temp;
             temp = networkHead;
             cout<<"===CURRENT PATH==="<<endl;
             for (int i=0;i<netLength;i++){
                    cout<<temp->name<<" -> ";
                    temp = temp->next;
             }
             cout << "NULL"<<endl;
             cout << "=================="<<endl;
        }
        void printQueue(){ // printing for queue
            for (int i=0;i<queueTail;i++){
                cout << i << ": " << arrayQueue[i] << endl;
            }
        }
        void transmit(string word){
            city *temp;
            city *temp2;
            city *reverseHead;
            temp = networkHead;

            networkHead->message = word;
            cout << networkHead->name <<" received "<<word<<endl;
            for (int i=1;i<netLength;i++){ // Passes forwards.
                temp->next->message = temp->message;
                temp->message = "";
                cout<<temp->next->name<<" received "<<word<<endl;
                if (i == netLength - 1){ // activates on last run.
                    reverseHead = temp->next;
                    temp2 = reverseHead;
                }
                temp = temp->next;
            }
            //cout<<reverseHead->name;
            reverseHead->message=word;
            for (int i=1;i<netLength;i++){ // Passes backwards.
                temp2->prev->message = temp2->message;
                temp2->message = "";
                cout<<temp2->prev->name<<" received "<<word<<endl;
                temp2 = temp2->prev;
            }

        }
        void buildNetwork(){
             string defaultNet[10] = {"Los Angeles","Phoenix","Denver","Dallas","St. Louis","Chicago","Atlanta","Washington, D.C.","New York","Boston"};
             city *temp;
             networkHead = new city;
             temp = networkHead;  // build the global head.
             networkHead->name = defaultNet[0];

             for (int i=1;i<10;i++){ // build the Llist following the head.
                    temp->next = new city;
                    temp->next->prev = temp;
                    temp = temp->next;
                    temp->name = defaultNet[i];
             }
             netLength = 10;
             printPath();
        }
        void enqueue (string addition){ // Queue addition function. With printing.
            arrayQueue[queueTail] = addition;
            queueTail++;
            fakeTail++;
            int fakeHeadTemp;
            int fakeTailTemp;
            fakeTailTemp = fakeTail%10;
            fakeHeadTemp = fakeHead%10;
            if (fakeTailTemp == 10){fakeTailTemp = 0;}
            if (fakeHeadTemp == 10){fakeHeadTemp = 0;}
            cout<<"E: "<<addition<<endl;
            cout<<"H: "<<fakeHeadTemp<<endl;
            cout<<"T: "<<fakeHeadTemp<<endl;
            x++;
        }
        string deQueue(){ // Queue accessing function
            if (queueHead == queueTail){
                cout<<"Queue is empty."<<endl;
                return "!";
            }
            string target;
            target = arrayQueue[queueHead];
            for (int i=0;i<queueSize-1;i++){
                arrayQueue[i] = arrayQueue[i+1];
            }
            queueTail--;
            fakeHead++;
            int fakeHeadTemp;
            int fakeTailTemp;
            fakeTailTemp = fakeTail%10;
            fakeHeadTemp = fakeHead%10;
            if (fakeTailTemp == 10){fakeTailTemp = 0;}
            if (fakeHeadTemp == 10){fakeHeadTemp = 0;}
            cout<<"H: "<<fakeHeadTemp<<endl<<"T: "<<fakeTailTemp<<endl;
            transmit(target);
            return target;
        }
        void fullDQ(){
            while(queueTail>0){
                deQueue();
            }
        }
        void sendMessage(){
            bool flag = false;
            for (int i=0;i<readLength;i++){
                if (queueTail == queueSize){
                    fullDQ();
                    flag = true;
                }
                enqueue(fileRead[i]);
            }
            fullDQ();
        }
        void clr(){
            city *temp;
            city *temp2;
            temp = networkHead;

            for (int i=0;i<netLength;i++){
                temp2 = temp->next;
                delete temp;
                temp = temp2;
            }
        }
    protected:
    private:
        int queueSize;
        string *arrayQueue; // queue variables.
        int queueHead;
        int queueTail;

        int netLength;     // actual network variables
        city *networkHead;
};

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
    cout << "8. Quit"<<endl;
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

    if      (choice == 1) {Net->buildNetwork();       valid=true;}
    else if (choice == 2) {Net->printPath();          valid=true;}
    else if (choice == 3) {Net->enqueue(fileRead[x]); valid=true;}
    else if (choice == 4) {Net->deQueue();            valid=true;}
    else if (choice == 5) {Net->printQueue();         valid=true;}
    else if (choice == 6) {Net->sendMessage();        valid=true;}
    else if (choice == 7) {Net->bubbleSortAlphabetically();valid = true;}
    else if (choice == 8) {exitCon = true;            valid=true;}
    return valid;
}

int main()
{
    loadFile();
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

