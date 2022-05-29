#include "mokinys.h"

void Mokinys::galutinisVid()
{
    double sum = 0;
    for (auto& el : pazymiai)
        sum += el;

    if (pazymiai.size() != 0)
        vidurkis = sum / (pazymiai.size() * 1.0) * 0.4 + egzaminas * 0.6;
    else
        vidurkis = egzaminas * 0.6;
}
void Mokinys::galutinisMed()
{
    sort(pazymiai.begin(), pazymiai.end());
    if (pazymiai.size() % 2 == 0 && pazymiai.size() != 0)
    {
        mediana = (pazymiai[pazymiai.size() / 2] + pazymiai[pazymiai.size() / 2 - 1]) * 1.0 / 2;
    }
    else if (pazymiai.size() % 2 != 0 && pazymiai.size() != 0)
    {
        mediana = pazymiai[pazymiai.size() / 2] * 0.4 + egzaminas * 0.6;
    }
    else if (pazymiai.size() == 0)
    {
        cout << "no marks" << endl;
        mediana = egzaminas * 0.6;
    }
}
void Mokinys::RezSk()
{
    galutinisMed();
    galutinisVid();
}
void Mokinys::rankinisPazIvedimas()
{
    cout << "Iveskite pazymius, kai noresite baigti spauskite 0" << endl;
    int t;
    while (true)
    {
        t = IntTikrinimas();
        if (t == 0)
            break;
        else if (PazTikrinimas(t))
            pazymiai.push_back(t);
    }
}
bool Mokinys::PazTikrinimas(int n)
{
    if (n > 0 && n <= 10)
        return true;
    else
    {
        cout << "Neteisingas pazymys" << endl;
        return false;
    }
}
void Mokinys::addPaz(int paz)
{
    pazymiai.push_back(paz);
}
int Mokinys::getPopMark()
{
    int t = pazymiai.back();
    pazymiai.pop_back();
    return t;
}
void Mokinys::setFirstName(string name)
{
    vardas = name;
}
void Mokinys::setFirstName(std::istream& name)
{
    name >> vardas;
}
void Mokinys::setLastName(string name)
{
    pavarde = name;
}
void Mokinys::setLastName(std::istream& name)
{
    name >> pavarde;
}
void Mokinys::setEgzaminas(int paz)
{
    egzaminas = paz;
}
double Mokinys::getMediana()
{
    return mediana;
}
double Mokinys::getVidurkis()
{
    return vidurkis;
}
double Mokinys::getEgzaminas()
{
    return egzaminas;
}
std::string Mokinys::getFirstName()
{
    return vardas;
}
std::string Mokinys::getLastName()
{
    return pavarde;
}

bool lyginimas(Mokinys& a, Mokinys& b)
{
    return a.getFirstName() < b.getLastName();
}
bool vargsiukas(Mokinys& a)
{
    if (a.getMediana() < 5 || a.getVidurkis() < 5)
        return true;
    return false;
}
Mokinys::Mokinys() : vidurkis(0), mediana(0)
{

}
Mokinys::Mokinys(const Mokinys& m)
{
    this->vardas = m.vardas;
    this->pavarde = m.pavarde;
    this->pazymiai.reserve(m.pazymiai.size());
    this->pazymiai.resize(m.pazymiai.size());
    for (int i = 0; i < m.pazymiai.size(); i++)
    {
        this->pazymiai.at(i) = m.pazymiai[i];
    }
    this->egzaminas = m.egzaminas;
    this->vidurkis = m.vidurkis;
    this->mediana = m.mediana;
}
Mokinys& Mokinys::operator=(const Mokinys& m)
{
    if (&m == this)
        return *this;
    vardas = m.vardas;
    pavarde = m.pavarde;
    this->pazymiai.reserve(m.pazymiai.size());
    this->pazymiai.resize(m.pazymiai.size());
    for (int i = 0; i < m.pazymiai.size(); i++)
    {
        pazymiai[i] = m.pazymiai[i];
    }
    vidurkis = m.vidurkis;
    mediana = m.mediana;
    egzaminas = m.egzaminas;
    return *this;
}
Mokinys::~Mokinys()
{
    pazymiai.clear();
}