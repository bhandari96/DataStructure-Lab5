//Santosh Bhandari
//Lab 5
//Data Structure

//main.cpp
#include<iostream>
#include<memory>
#include<cstdlib>    
#include<ctime>
#include <random>      
#include "LinkedSortedList.h"
using namespace std;
int fillList(shared_ptr<SortedListInterface<int>> listPtr);
void displayList(shared_ptr<SortedListInterface<int>> listPtr);

int main() {

    std::random_device rd;
    shared_ptr<SortedListInterface<int>> listPtr;
    listPtr = make_shared<LinkedSortedList<int>>();

    int firstEntry = fillList(listPtr);           

    displayList(listPtr);                         

    std::cout << "First number added: "
         << listPtr->getEntry(firstEntry)
         << " at position " << firstEntry << endl;

    std::cout << "Deleting first entry added to list... ";
    listPtr->remove(firstEntry);                   
    cout << "done." << endl << endl;

    displayList(listPtr);                         

    return 0;
}

// Function definitions
void displayList(shared_ptr<SortedListInterface<int>> listPtr)
{
    std::cout << "Contents of sorted list: " << endl;
    for (int i = 1; i <= listPtr->getLength(); i++)
    {
        std::cout << listPtr->getEntry(i) << "-";
    }
    std::cout << endl << endl;
}

int fillList(shared_ptr<SortedListInterface<int>> listPtr)

{
	int random = 0;
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(1, 100);
 
    for (int n=0; n<21; ++n){
    random = dis(gen);
	listPtr->insertSorted(random);	
	}
     return listPtr->getPosition(random);   
}

