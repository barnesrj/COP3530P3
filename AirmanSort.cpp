#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include "Airman.h"
#include "SortAlgorithms.h"
#include "utils.h"
using namespace std;

int main() {
    
    //opens menu and loop with an escape option
    string input = "Y";
    while (input == "Y" || input == "y") {
        cout << "Reading file airmen.csv" << endl;
        //read the csv lines
        vector<string> lines = inTakeCSV("airmen.csv");
        //prints the menu and takes in user's option
        PrintMenu();
        char choice;
        cin >> choice;
        if (choice == 'X' || choice == 'x')
            exit('0');
        //parse the csv lines into the struct
        cout << "Sorting Airmen" << endl;
        vector<Airman> airmen = parseLines(lines,choice);
        //this initializes a paramter so that I can sort regardless of attribute chosen
        initializeSortParam(airmen, choice);
        
        //this invokes the bubble sort algorithm
        bubbleSort(airmen);
        //this lets me choose how many units of output
        cout << "Enter number of top results to display: ";
        int count;
        cin >> count;
        //this prints the result of the bubble sort       
        printTopAirmen(airmen, count);
        //this does the heapsort algorithm and prints out, then asks if you want to repeat        
        heapSort(airmen);
        printTopAirmen(airmen, count);
        cout << endl << "Continue? (Y for yes, else no)" << endl;
        cin >> input;
    }
    return 0;
}
