#pragma once

#include <string>

struct Airman {
    int serviceNumber;
    int pfeScore, sktScore, totTest;
    int asvabMechanical, asvabAdministrative, asvabGeneral, asvabElectrical, asvabTotal;
    int ptScore, decorationsScore;
    int mostRecentEPR, secondMostRecentEPR, thirdMostRecentEPR, EPRTot;
    int wapsScore;
    bool hasCCAF, hasBachelor, hasMaster;
    float weightedTotal;
    int sortVal;

    Airman();

    Airman(int serviceNumber, int pfe, int skt, int totTest, int mech, int admin, int gen, int elec, int total, int pt, int deco, int epr1, int epr2, int epr3, int totEPR, int waps, bool ccaf, bool bachelor, bool master, float weightedTotal, int sortVal);

    void PrintAirman();
};




