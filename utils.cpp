#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <vector>
#include "utils.h"
using namespace std;


//utility to read in the csv data
vector<string> inTakeCSV(string filename) {
    vector<string> lines;
    ifstream file(filename);
    string line;
    int index = 0;
    while (getline(file, line)) 
        lines.emplace_back(line);
    return lines;
}

//utility to parse the csv data into individual struct attributes
vector<Airman> parseLines(vector<string>& lines, char choice) 
{
    vector<Airman> airmen;

    int serviceNumber, pfe, skt, totTest, mech, admin, gen;
    int elec, total, pt, deco, epr1, epr2, epr3, EPRTot, waps;
    bool ccaf, bachelor, master;
    float weightedTotal;
    int sortVal;
    for (int i = 0; i < lines.size(); i++)
    {
        stringstream ss;
        string token;
        if (i != 0)
        {
            
            ss.str(lines.at(i));

            getline(ss, token, ',');
            serviceNumber = stoi(token);

            getline(ss, token, ',');
            epr1 = stoi(token);
            getline(ss, token, ',');
            epr2 = stoi(token);
            getline(ss, token, ',');
            epr3 = stoi(token);
            EPRTot = epr1 + epr2 + epr3;

            getline(ss, token, ',');
            pfe = stoi(token);
            getline(ss, token, ',');
            skt = stoi(token);
            totTest = pfe + skt;
            getline(ss, token, ',');
            deco = stoi(token);
            getline(ss, token, ',');
            pt = stoi(token);
            getline(ss, token, ',');
            mech = stoi(token);
            getline(ss, token, ',');
            admin = stoi(token);
            getline(ss, token, ',');
            gen = stoi(token);
            getline(ss, token, ',');
            elec = stoi(token);
            getline(ss, token, ',');
            total = stoi(token);

            waps = EPRTot + totTest + deco;

            getline(ss, token, ',');
            ccaf = (token == "true");
            getline(ss, token, ',');
            bachelor = (token == "true");
            getline(ss, token, ',');
            master = (token == "true");
            weightedTotal = waps / 460 * 100 + pt + total;
            if (ccaf == false)
                weightedTotal *= 0.5;
            if (bachelor == true)
                weightedTotal *= 1.25;
            if (master == true)
                weightedTotal *= 1.5;

        
            sortVal = choice;
            //used this procedure so I didn't have to mame a temporary vector
            airmen.emplace_back(serviceNumber, pfe, skt, totTest, mech, admin, gen, elec, total, pt, deco, epr1, epr2, epr3, EPRTot, waps, ccaf, bachelor, master, weightedTotal, sortVal);

        }


    }
    

    return airmen;
}
//this prints out the number of Airmen specified
void printTopAirmen(vector<Airman>& airmen, int count) {
    cout << left << setw(13) << "|Service No";
    cout << left << setw(18) << "|EPRs";
    cout << left << setw(4) << "|PFE";
    cout << left << setw(4) << "|SKT";
    cout << left << setw(6) << "|Tests";
    cout << left << setw(6) << "|Decs";
    cout << left << setw(5) << "|WAPS";
    cout << left << setw(4) << "|PT";
    
    
    cout << left << setw(4) << "|M";
    cout << left << setw(4) << "|A";
    cout << left << setw(4) << "|G";
    cout << left << setw(4) << "|E";
    cout << left << setw(15) << "|ASVAB Total";
    cout << left << setw(5) << "|CCAF";
    cout << left << setw(5) << "|B";
    cout << left << setw(5) << "|M+";
    cout << left << setw(5) << "|Weighted";
    cout << endl;

    cout << string(115, '-') << endl;
    for (int i = 0; i < count && i < airmen.size(); ++i) {
        airmen[i].PrintAirman();

    }
}
//this prints the original menu
void PrintMenu() {
    cout << string(80, '-') << endl;
    cout << "|  " << "Sort By:                       " << string(46, ' ') << "|" << endl;
    cout << "|  " << "1. Service Number (in sequence)" << string(46, ' ') << "|" << endl;
    cout << "|  " << "2. PFE Score                   " << string(46, ' ') << "|" << endl;
    cout << "|  " << "3. SKT Score                   " << string(46, ' ') << "|" << endl;
    cout << "|  " << "4. Total Tests                 " << string(46, ' ') << "|" << endl;
    cout << "|  " << "5. Decorations                 " << string(46, ' ') << "|" << endl;
    cout << "|  " << "6. Total WAPS                  " << string(46, ' ') << "|" << endl;
    cout << "|  " << "7. ASVAB Mechanical            " << string(46, ' ') << "|" << endl;
    cout << "|  " << "8. ASVAB Administrative        " << string(46, ' ') << "|" << endl;
    cout << "|  " << "8. ASVAB General               " << string(46, ' ') << "|" << endl;
    cout << "|  " << "9. ASVAB Electrical            " << string(46, ' ') << "|" << endl;
    cout << "|  " << "A. ASVAB Total                 " << string(46, ' ') << "|" << endl;
    cout << "|  " << "B. PT Test                     " << string(46, ' ') << "|" << endl;
    cout << "|  " << "C. Weighted Overall            " << string(46, ' ') << "|" << endl;
    cout << "|  " << "X. Quit                        " << string(46, ' ') << "|" << endl;
    cout << string(80, '-') << endl;
}
//this allows the program to sort by the parameter the user specifies with a integer variable that
//copies the value of the attribute specified
void initializeSortParam(vector<Airman>& airmen, char sortParameter) {
    
    if (sortParameter == '2')
        for (int i = 0; i < airmen.size(); i++)
            airmen[i].sortVal = airmen[i].pfeScore;
    else if (sortParameter == '3')
        for (int i = 0; i < airmen.size(); i++)
            airmen[i].sortVal = airmen[i].sktScore;
    else if (sortParameter == '4')
        for (int i = 0; i < airmen.size(); i++)
            airmen[i].sortVal = airmen[i].totTest;
    else if (sortParameter == '5')
        for (int i = 0; i < airmen.size(); i++)
            airmen[i].sortVal = airmen[i].decorationsScore;
    else if (sortParameter == '6')
        for (int i = 0; i < airmen.size(); i++)
            airmen[i].sortVal = airmen[i].wapsScore;
    else if (sortParameter == '7')
        for (int i = 0; i < airmen.size(); i++)
            airmen[i].sortVal = airmen[i].asvabMechanical;
    else if (sortParameter == '8')
        for (int i = 0; i < airmen.size(); i++)
            airmen[i].sortVal = airmen[i].asvabAdministrative;
    else if (sortParameter == '9')
        for (int i = 0; i < airmen.size(); i++)
            airmen[i].sortVal = airmen[i].asvabGeneral;
    else if (sortParameter == 'A')
        for (int i = 0; i < airmen.size(); i++)
            airmen[i].sortVal = airmen[i].asvabElectrical;
    else if (sortParameter == 'B')
        for (int i = 0; i < airmen.size(); i++)
            airmen[i].sortVal = airmen[i].asvabTotal;
    else if (sortParameter == 'C')
        for (int i = 0; i < airmen.size(); i++)
            airmen[i].sortVal = airmen[i].ptScore;
    else if (sortParameter == 'D')
        for (int i = 0; i < airmen.size(); i++)
            airmen[i].sortVal = airmen[i].weightedTotal;
    
    else {
        for (int i = 0; i < airmen.size(); i++)
            airmen[i].sortVal = airmen[i].serviceNumber;
    }
}