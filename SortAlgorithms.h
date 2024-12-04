#pragma once

#include <vector>
#include "Airman.h"
using namespace std;

void bubbleSort(vector<Airman>& airmen);
void heapSort(vector<Airman>& airmen);
void heapify(vector<Airman>& airmen, int n, int i);