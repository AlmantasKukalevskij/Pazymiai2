#pragma once

#include "tikrinimas.h"
#include "zmogus.h"

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

class Mokinys : public zmogus
{
public:
    vector<int> pazymiai;
    int egzaminas;
    double vidurkis = 0;
    double mediana = 0;
    tikrinimas tinkamas;
    
    void f()
    {

    };

public:
    Mokinys();
    ~Mokinys();
    Mokinys(const Mokinys& m);
    Mokinys& operator = (const Mokinys& m);

    void setEgzaminas(int paz);

    double getMediana() const;
    double getVidurkis() const;
    double getEgzaminas() const;

    void rankinisPazIvedimas();
    void addPaz(int paz);
    int getPopMark();

    void galutinisVid();
    void galutinisMed();
    void RezSk();
};

bool lyginimas(Mokinys& a, Mokinys& b);
bool vargsiukas(Mokinys& a);

