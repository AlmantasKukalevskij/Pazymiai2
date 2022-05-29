#pragma once

#include "tikrinimas.h"
#include "mokinys.h"
#include "generavimas.h"
#include "timer.h"

#include <deque>
#include <list>

using std::deque;
using std::list;

class application : public tikrinimas
{
private:
	bool genMode;
	int programMode;
	int contTipas;
	int strategyType;
	std::chrono::time_point<std::chrono::high_resolution_clock> programStart;
	string file_name;

	Mokinys mokiniai;
	Generatorius generator;
	Timer systemTimer;
	Timer otherTimer;


	bool egzaminas;
	bool pazymys;
	bool manual;

public:
	application();
	~application();
	void run();

private:
	void ivestis(Mokinys& temp);

	void buferioSkaitymas(vector<Mokinys>& mokiniai);
	void buferioRasymas(std::string write_vardas, vector<Mokinys>& mokiniai);

	void buferioSkaitymas(list<Mokinys>& mokiniai);
	void buferioRasymas(std::string write_vardas, list<Mokinys>& mokiniai);

	void buferioSkaitymas(deque<Mokinys>& mokiniai);
	void buferioRasymas(std::string write_vardas, deque<Mokinys>& mokiniai);

	void buferisToContainer();

	void failoGen(int size, string file_name, int ndSkaicius);
	void contToFile(string file_name, vector<Mokinys>& data);
	void contToFile(string file_name, list<Mokinys>& data);
	void contToFile(string file_name, deque<Mokinys>& data);
	void openFile(std::ifstream& open_f);
	std::string writeFileName();

	void printToFile(string text);

	void MokiniuSortiravimas(vector<Mokinys>& kietekai, vector<Mokinys>& vargsai, vector<Mokinys>& VisiMokiniai);
	void MokiniuSortiravimas(list<Mokinys>& kietekai, list<Mokinys>& vargsai, list<Mokinys>& VisiMokiniai);
	void MokiniuSortiravimas(deque<Mokinys>& kietekai, deque<Mokinys>& vargsai, deque<Mokinys>& VisiMokiniai);

	void MokiniuSortiravimasV2(vector<Mokinys>& kietekai, vector<Mokinys>& vargsai);
	void MokiniuSortiravimasV2(list<Mokinys>& kietekai, list<Mokinys>& vargsai);
	void MokiniuSortiravimasV2(deque<Mokinys>& kietekai, deque<Mokinys>& vargsai);

	void processStarts(vector<Mokinys>& mokiniai, vector<Mokinys>& kietekai, vector<Mokinys>& vargsai);
	void processStarts(list<Mokinys>& mokiniai, list<Mokinys>& kietekai, list<Mokinys>& vargsai);
	void processStarts(deque<Mokinys>& mokiniai, deque<Mokinys>& kietekai, deque<Mokinys>& vargsai);

	void runManualMode();
	void runAutoMode();
};

