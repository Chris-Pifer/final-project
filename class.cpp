#include "Final.h"

int x = 0;
int fakeHead = 0; // These track the number of enqueues and dequeues for COG
int fakeTail = 0; // Nothing to do with any implementation.

        Network::Network(int qs){
            queueSize = qs;
            arrayQueue = new string[queueSize];
            queueHead = 0;
            queueTail = 0;
        }
        //~Network();
        // METHODS
        void Network::swapNodes(city *first, city *second){ // switches two nodes in the linked list.
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
        // Orders HIGH -> LOW
        void Network::bubbleSortAlphabetically (){
            cout << "Bubble sorting list by name: HIGH -> LOW" << endl;
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
        //Bubble sorts the list alphabetically by city name.   //Note, alphabetical sorting is CAPS SENSITIVE, ie, a comes after Z.
        //Orders LOW -> HIGH
        void Network::bubbleSortAlphabeticallyLow (){
            cout << "Bubble sorting list by name: LOW -> HIGH" << endl;
            bool op = true;
            while (op){
                op = false;
                city *temp = networkHead;
                while (temp->next){
                    if (temp->name.compare(temp->next->name) < 0){
                        swapNodes(temp,temp->next);
                        op = true;
                    }
                    temp = temp->next;
                }
            }
        }
        //Bubble sorts the list numerically by population.
        //Orders HIGH -> LOW
        void Network::bubbleSortNumerically(){
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
                    temp = temp->next;
                }
            }
        }
        //Bubble sorts the list numerically by population
        //Orders LOW -> HIGH
        void Network::bubbleSortNumericallyLow(){
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
                    temp = temp->next;
                }
            }
        }
        void Network::printPath(){ // Printing for network path
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
        void Network::printQueue(){ // printing for queue
            for (int i=0;i<queueTail;i++){
                cout << i << ": " << arrayQueue[i] << endl;
            }
        }
        void Network::transmit(string word){
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
        void Network::addNode(string name, int population){
            city *temp = networkHead;
            city *addition = new city;
            addition->name = name;
            addition->pop = population;
            networkHead->prev = addition;
            networkHead = addition;
            addition->next = temp;

            netLength++;
        }
        void Network::deleteNode(string name){
            bool found = false;
            city *temp;
            temp = networkHead;
            while (temp){
                if (temp->name == name){found = true;break;}
                temp = temp->next;
            }
            if (found){
                if (temp->next && temp->prev){
                    temp->prev->next = temp->next;
                    temp->next->prev = temp->prev;
                    delete temp;
                }
                else if (temp->next && !temp->prev){
                    temp->next->prev = NULL;
                    networkHead = temp->next;
                    delete temp;
                }
                else if (!temp->next && temp->prev){
                    temp->prev->next = NULL;
                    delete temp;
                }
                else {cout << "City found but delete failed to execute."<<endl;}
                netLength--;
            }
            else {cout << "City not found" << endl;}
        }
        void Network::buildNetwork(){
             string defaultNet[10] = {"Los Angeles","Phoenix","Denver","Dallas","St. Louis","Chicago","Atlanta","Washington, D.C.","New York","Boston"};
             int populations[10] = {16370000,1513000,649465,1258000,318416,2719000,447841,658893,8406000,645966};
             city *temp;
             networkHead = new city;
             temp = networkHead;  // build the global head.
             networkHead->name = defaultNet[0];
             networkHead->pop = populations[0];
             for (int i=1;i<10;i++){ // build the Llist following the head.
                    temp->next = new city;
                    temp->next->prev = temp;
                    temp->next->next = NULL;
                    temp = temp->next;
                    temp->name = defaultNet[i];
                    temp->pop = populations[i];
             }
             netLength = 10;
             printPath();
        }
        void Network::enqueue (string addition){ // Queue addition function. With printing.
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
        string Network::deQueue(){ // Queue accessing function
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
        void Network::fullDQ(){
            while(queueTail>0){
                deQueue();
            }
        }
        void Network::sendMessage(int readLength, string fileRead[]){
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
        void Network::clr(){
            city *temp;
            city *temp2;
            temp = networkHead;

            for (int i=0;i<netLength;i++){
                temp2 = temp->next;
                delete temp;
                temp = temp2;
            }
        }

