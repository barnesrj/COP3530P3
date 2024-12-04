#include <iostream>
#include <iomanip>
#include "Airman.h"
using namespace std;
//standard constructors
Airman::Airman() {
    int serviceNumber = 0;
    int pfeScore = 0;
    int sktScore = 0;
    int totTest = 0;
    int asvabMechanical = 0;
    int asvabAdministrative = 0;
    int asvabGeneral = 0;
    int asvabElectrical = 0;
    int asvabTotal = 0;
    int ptScore = 0;
    int decorationsScore = 0;
    int mostRecentEPR = 0;
    int secondMostRecentEPR = 0;
    int thirdMostRecentEPR = 0;
    int wapsScore = 0;
    bool hasCCAF = false;
    bool hasBachelor = false;
    bool hasMaster = false;
    float weightedTotal = 0;
    int sortVal;
}

Airman::Airman(int svsNumber, int pfe, int skt, int TotTest, int mech, int admin, int gen, int elec, int total, int pt, int deco, int epr1, int epr2, int epr3, int totEPR, int waps, bool ccaf, bool bachelor, bool master, float wtdTotal, int sortVal){
        serviceNumber = svsNumber;
        pfeScore = pfe;
        sktScore = skt;
        totTest = TotTest;
        asvabMechanical = mech;
        asvabAdministrative = admin;
        asvabGeneral = gen;
        asvabElectrical = elec;
        asvabTotal = total;
        ptScore = pt;
        decorationsScore = deco;
        mostRecentEPR = epr1;
        secondMostRecentEPR = epr2;
        thirdMostRecentEPR = epr3;
        EPRTot = totEPR;
        wapsScore = waps;
        hasCCAF = ccaf;
        hasBachelor = bachelor;
        hasMaster = master;
        weightedTotal = wtdTotal;
        sortVal = sortVal;
}
//utility to print out the data in a format for a single Airman
void Airman::PrintAirman() {
    
    cout << "|";
    cout << left << setw(12) << serviceNumber;
    cout << "|";
    cout << left << setw(3) << mostRecentEPR;
    cout << left << setw(1) << "/";
    cout << left << setw(2) << secondMostRecentEPR;
    cout << left << setw(1) << "/";
    cout << left << setw(2) << thirdMostRecentEPR;
    cout << left << setw(3) << " = ";
    cout << left << setw(5) << EPRTot;
    cout << "|";
    cout << left << setw(3) <<  pfeScore;
    cout << "|";
    cout << left << setw(3) <<  sktScore;
    cout << "|";
    cout << left << setw(5) <<  totTest;
    cout << "|";
    cout << left << setw(5) <<  decorationsScore;
    cout << "|";
    cout << left << setw(4) <<  wapsScore;
    cout << "|";
    cout << left << setw(3) <<  ptScore;
    cout << "|";
    cout << left << setw(3) <<  asvabMechanical;
    cout << "|";
    cout << left << setw(3) <<  asvabAdministrative;
    cout << "|";
    cout << left << setw(3) <<  asvabGeneral;
    cout << "|";
    cout << left << setw(3) <<  asvabElectrical;
    cout << "|";
    cout << left << setw(14) << asvabTotal;
    cout << "|";
    if (hasCCAF == true)
        cout << left << setw(4) << "Y";    
    else
        cout << left << setw(4)  << " ";

    cout << "|";
    if (hasBachelor == true)
        cout << left << setw(4)  << "Y";
    else
        cout << left << setw(4)  << " ";

    cout << "|";
    if (hasMaster == true)
        cout << left << setw(4)  << "Y";
    else
        cout << left << setw(4)  << " ";

    cout << "|";
    cout << fixed << setprecision(2) << left << setw(5) << weightedTotal;
    cout << endl;
}

