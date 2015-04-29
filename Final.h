#ifndef FINAL_H_INCLUDED
#define FINAL_H_INCLUDED
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

class Network{
    public:
        Network(int qs);
        void swapNodes(city *first,city *second);
        void bubbleSortAlphabetically();
        void bubbleSortAlphabeticallyLow();
        void bubbleSortNumerically();
        void bubbleSortNumericallyLow();
        void printPath();
        void printQueue();
        void transmit(std::string word);
        void addNode(std::string name, int population);
        void deleteNode(std::string name);
        void buildNetwork();
        void enqueue (std::string addition);
        std::string deQueue();
        void fullDQ();
        void sendMessage(int readLength,string fileRead[]);
        void clr();
    protected:
    private:
        int queueSize;
        string *arrayQueue;
        int queueHead;
        int queueTail;
        int netLength;
        city *networkHead;
};

#endif // FINAL_H_INCLUDED
