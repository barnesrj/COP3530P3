#pragma once

#include <vector>
#include "Airman.h"
using namespace std;

vector<string> inTakeCSV(string filename);
vector<Airman> parseLines(vector<string>& lines, char choice);
void printTopAirmen(vector<Airman>& airmen, int count);
void PrintMenu();
void initializeSortParam(vector<Airman>& airmen, char sortParameter);


