#include "SortAlgorithms.h"
#include "Airman.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;
//straight forward vanilla bubble sort
void bubbleSort(std::vector<Airman>& airmen) {
    int n = airmen.size();
    for (int i = 0; i < n - 1; i++) {

        bool swapped = false;
        for (int j = 0; j < n - i - 1; ++j) {
            if (airmen[j].sortVal < airmen[j + 1].sortVal) {

                Airman tempAirman;
                tempAirman = airmen[j];
                airmen[j] = airmen[j + 1];
                airmen[j + 1] = tempAirman;
                swapped = true;
            }
        }
        if (!swapped) break;

        if (i % 10000 == 0)
            cout << i << "...";

    }
}
//standard heapify and heap sort (max heap)
void heapify(vector<Airman>& airmen, int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    
    if (left < n && airmen[left].sortVal < airmen[largest].sortVal)
        largest = left;

    
    if (right < n && airmen[right].sortVal < airmen[largest].sortVal)
        largest = right;

    
    if (largest != i) {
        //found this in algorigthm library to simplify the swapping
        swap(airmen[i], airmen[largest]);

        
        heapify(airmen, n, largest);
    }
}

void heapSort(vector<Airman>& airmen) {
    int n = airmen.size();

    
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(airmen, n, i);

    
    for (int i = n - 1; i > 0; i--) {
    
        swap(airmen[0], airmen[i]);

        
        heapify(airmen, i, 0);
    }
}
