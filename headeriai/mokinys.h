#pragma once

#include "tikrinimas.h"

#include<fstream>
#include<vector>
#include <iostream>
#include<algorithm>
#include <string>

using std::cin;
using std::cout;
using std::string;
using std::endl;
using std::vector;

class Mokinys : public tikrinimas
{
private:
    string vardas, pavarde;
    vector<int> pazymiai;
    int egzaminas;
    double vidurkis = 0;
    double mediana = 0;

    bool PazTikrinimas(int t);

public:
    void setFirstName(string name);
    void setFirstName(std::istream& name);
    void setLastName(string name);
    void setLastName(std::istream & name);
    void setEgzaminas(int paz);

    double getMediana();
    double getVidurkis();
    double getEgzaminas();
    std::string getFirstName();
    std::string getLastName();

    void rankinisPazIvedimas();
    void addPaz(int paz);
    int getPopMark();

    void galutinisVid();
    void galutinisMed();
    void RezSk();
};

bool lyginimas(Mokinys& a, Mokinys& b);
bool vargsiukas(Mokinys &a);