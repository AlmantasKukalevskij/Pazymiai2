#include "application.h"

std::string application::writeFileName()
{
    string file_name = "";
    cin.ignore();
    getline(cin, file_name);
    if (!file_name.empty())
        file_name += ".txt";
    return file_name;
}
void application::run()
{
    cout << "Ar norite sugeneruoti failus (1/0)?" << endl;
    bool gen = validMode(0, 1);
    if (gen)
    {
        Generatorius fileGen;

        cout << "Kaip norite pavadinti faila?(kitaip bus mokiniai.txt) ";
        fileGen.set_file_name(writeFileName());
        cout << "Kiek sugeneruoti mokiniu?" << endl;
        fileGen.set_mok_count(IntTikrinimas());
        cout << "Kiek sugeneruoti namu darbu?" << endl; 
        fileGen.set_nd_count(IntTikrinimas());
        fileGen.failoGen();
        return;
    }

    cout << "Ar norite vesti pazymius ranka (1), kitaip (0) pazymiai bus nuskaityti is failo" << endl;
    manual = validMode(0, 1);

    if (!manual)
        runAutoMode();
    else
        runManualMode();
}
void application::ivestis(Mokinys& temp)
{
    cout << "Iveskite varda: ";
    temp.setFirstName(cin);
    cout << "Iveskite pavarde: ";
    temp.setLastName(cin);

    if (egzaminas)
    {
        cout << "Iveskite egzamino iverti: ";
        while (true)
        {
            int egz = tikrinimas::IntTikrinimas();
            if (tikrinimas::PazTikrinimas(egz))
            {
                temp.setEgzaminas(egz);
                break;
            }
        }
    }
    else temp.setEgzaminas(generator.randomInt(1, 10));

    if (pazymys)
        temp.rankinisPazIvedimas();
    else
    {
        cout << "Jeigu norite sugeneruoti pazymi spauskite 1, jeigu ne - 0" << endl;
        while (true)
        {
            int run = validMode(0, 1);
            if (run)
            {
                temp.addPaz(generator.randomInt(1, 10));
            }
            else break;
        }
    }
    cout << "pazymiai ivesti" << endl;
}

void application::buferioSkaitymas(vector<Mokinys>& mokiniai)
{
    std::string line;
    std::stringstream buffer;
    std::ifstream open_f;

    systemTimer.Stop();
    openFile(open_f);
    systemTimer.Resume();
    otherTimer.Start();
    buffer << open_f.rdbuf();
    open_f.close();
    std::getline(buffer, line);

    int counter = 0;
    while (buffer)
    {
        std::getline(buffer, line);
        if (line.length() == 0)
            break;
        Mokinys t;
        std::istringstream lineStream(line);
        t.setFirstName(lineStream);
        t.setLastName(lineStream);
        int mark;
        while (lineStream >> mark)
        {
            t.addPaz(mark);
        }
        t.setEgzaminas(t.getPopMark());

        mokiniai.push_back(t);
    }
    cout << "Failo nuskaitymas uztruko: " << otherTimer.StopReturn() << " sek." << endl;
}

void application::buferioSkaitymas(list<Mokinys>& mokiniai)
{
    std::string line;
    std::stringstream buffer;
    std::ifstream open_f;

    systemTimer.Stop();
    openFile(open_f);
    systemTimer.Resume();
    otherTimer.Start();
    buffer << open_f.rdbuf();
    open_f.close();
    std::getline(buffer, line);

    int counter = 0;
    while (buffer)
    {
        std::getline(buffer, line);
        if (line.length() == 0)
            break;
        Mokinys t;
        std::istringstream lineStream(line);
        t.setFirstName(lineStream);
        t.setLastName(lineStream);
        int mark;
        while (lineStream >> mark)
        {
            t.addPaz(mark);
        }
        t.setEgzaminas(t.getPopMark());

        mokiniai.push_back(t);
    }
    cout << "Failo nuskaitymas uztruko: " << otherTimer.StopReturn() << " sek." << endl;
}

void application::buferioSkaitymas(deque<Mokinys>& mokiniai)
{
    std::string line;
    std::stringstream buffer;
    std::ifstream open_f;

    systemTimer.Stop();
    openFile(open_f);
    systemTimer.Resume();
    otherTimer.Start();
    buffer << open_f.rdbuf();
    open_f.close();
    std::getline(buffer, line);

    int counter = 0;
    while (buffer)
    {
        std::getline(buffer, line);
        if (line.length() == 0)
            break;
        Mokinys t;
        std::istringstream lineStream(line);
        t.setFirstName(lineStream);
        t.setLastName(lineStream);
        int mark;
        while (lineStream >> mark)
        {
            t.addPaz(mark);
        }
        t.setEgzaminas(t.getPopMark());

        mokiniai.push_back(t);
    }
    cout << "Failo nuskaitymas uztruko: " << otherTimer.StopReturn() << " sek." << endl;
}

void application::buferioRasymas(std::string write_vardas, vector<Mokinys>& mokiniai)
{
    std::stringstream isvestis;

    isvestis << left << setw(20) << "Vardas";
    isvestis << left << setw(20) << "Pavarde";
    isvestis << std::left << std::setw(20) << "Vidurkis";
    isvestis << std::left << std::setw(20) << "Mediana";
    isvestis << endl;
    for (auto& mok : mokiniai)
    {
        isvestis << left << setw(20) << mok.getFirstName();
        isvestis << left << setw(20) << mok.getLastName();
        isvestis << left << setw(20) << mok.getVidurkis();
        isvestis << left << setw(20) << mok.getMediana();
        isvestis << endl;
    }
    mokiniai.clear();

    std::ofstream fout(write_vardas);
    fout << isvestis.rdbuf();
    fout.close();
}

void application::buferioRasymas(std::string write_vardas, list<Mokinys>& mokiniai)
{
    std::stringstream isvestis;

    isvestis << left << setw(20) << "Vardas";
    isvestis << left << setw(20) << "Pavarde";
    isvestis << std::left << std::setw(20) << "Vidurkis";
    isvestis << std::left << std::setw(20) << "Mediana";
    isvestis << endl;
    for (auto& mok : mokiniai)
    {
        isvestis << left << setw(20) << mok.getFirstName();
        isvestis << left << setw(20) << mok.getLastName();
        isvestis << left << setw(20) << mok.getVidurkis();
        isvestis << left << setw(20) << mok.getMediana();
        isvestis << endl;
    }
    mokiniai.clear();

    std::ofstream fout(write_vardas);
    fout << isvestis.rdbuf();
    fout.close();
}

void application::buferioRasymas(std::string write_vardas, deque<Mokinys>& mokiniai)
{
    std::stringstream isvestis;

    isvestis << left << setw(20) << "Vardas";
    isvestis << left << setw(20) << "Pavarde";
    isvestis << std::left << std::setw(20) << "Vidurkis";
    isvestis << std::left << std::setw(20) << "Mediana";
    isvestis << endl;
    for (auto& mok : mokiniai)
    {
        isvestis << left << setw(20) << mok.getFirstName();
        isvestis << left << setw(20) << mok.getLastName();
        isvestis << left << setw(20) << mok.getVidurkis();
        isvestis << left << setw(20) << mok.getMediana();
        isvestis << endl;
    }
    mokiniai.clear();

    std::ofstream fout(write_vardas);
    fout << isvestis.rdbuf();
    fout.close();
}

void application::contToFile(string file_name, vector<Mokinys>& data)
{
    std::stringstream isvestis;
    isvestis << std::left << std::setw(20) << "Vardas" << std::left << std::setw(20) << "Pavarde" << std::left << std::setw(20) << "Vid." << std::left << std::setw(20) << "Med." << endl;
    for (auto& mok : data)
    {
        isvestis << std::left << std::setw(20) << mok.getFirstName();
        isvestis << std::left << std::setw(20) << mok.getLastName();
        isvestis << std::left << std::setw(20) << mok.getVidurkis();
        isvestis << std::left << std::setw(20) << mok.getMediana();
        isvestis << endl;
    }
    
    std::ofstream file_out(file_name);
    file_out << isvestis.rdbuf();
    file_out.close();
}

void application::contToFile(string file_name, list<Mokinys>& data)
{
    std::stringstream isvestis;
    isvestis << std::left << std::setw(20) << "Vardas" << std::left << std::setw(20) << "Pavarde" << std::left << std::setw(20) << "Vid." << std::left << std::setw(20) << "Med." << endl;
    for (auto& mok : data)
    {
        isvestis << std::left << std::setw(20) << mok.getFirstName();
        isvestis << std::left << std::setw(20) << mok.getLastName();
        isvestis << std::left << std::setw(20) << mok.getVidurkis();
        isvestis << std::left << std::setw(20) << mok.getMediana();
        isvestis << endl;
    }
    std::ofstream file_out(file_name);
    file_out << isvestis.rdbuf();
    file_out.close();
}

void application::contToFile(string file_name, deque<Mokinys>& data)
{
    std::stringstream isvestis;
    isvestis << std::left << std::setw(20) << "Vardas" << std::left << std::setw(20) << "Pavarde" << std::left << std::setw(20) << "Vid." << std::left << std::setw(20) << "Med." << endl;
    for (auto& mok : data)
    {
        isvestis << std::left << std::setw(20) << mok.getFirstName();
        isvestis << std::left << std::setw(20) << mok.getLastName();
        isvestis << std::left << std::setw(20) << mok.getVidurkis();
        isvestis << std::left << std::setw(20) << mok.getMediana();
        isvestis << endl;
    }
    std::ofstream file_out(file_name);
    file_out << isvestis.rdbuf();
    file_out.close();
}

void application::openFile(std::ifstream& open_f)
{
    bool err = true;
    cin.ignore();
    while (err)
    {
        cout << "Iveskite failo pavadinima, kitaip bus mokiniai.txt: ";
        string file_name;
        getline(cin, file_name);

        if (file_name.empty())
            file_name = "mokiniai.txt";
        try
        {
            open_f.open(file_name);
            if (open_f.fail())
                throw std::invalid_argument("Ivestas neteisingas failo pavadinimas");
            err = false;
        }
        catch (const std::invalid_argument& e)
        {
            cout << e.what() << std::endl;
        }
    }
}
application::application()
{

}
application::~application()
{

}
void application::MokiniuSortiravimasV2(vector<Mokinys>& kietekai, vector<Mokinys>& vargsai)
{
    auto sortStart = hrClock::now();
    copy_if(kietekai.begin(), kietekai.end(), back_inserter(vargsai), vargsiukas);
    kietekai.erase(remove_if(kietekai.begin(), kietekai.end(), vargsiukas), kietekai.end());
    cout << "Mokiniai padalinti i dvi grupes per: " << durationDouble(hrClock::now() - sortStart).count() << " sek." << endl;
}
void MokiniuSortiravimasV2(list<Mokinys>& kietekai, list<Mokinys>& vargsai)
{
    auto sortStart = hrClock::now();
    copy_if(kietekai.begin(), kietekai.end(), back_inserter(vargsai), vargsiukas);
    kietekai.erase(remove_if(kietekai.begin(), kietekai.end(), vargsiukas), kietekai.end());
    cout << "Mokiniai padalinti i dvi grupes per: " << durationDouble(hrClock::now() - sortStart).count() << " sek." << endl;
}
void MokiniuSortiravimasV2(deque<Mokinys>& kietekai, deque<Mokinys>& vargsai)
{
    auto sortStart = hrClock::now();
    copy_if(kietekai.begin(), kietekai.end(), back_inserter(vargsai), vargsiukas);
    kietekai.erase(remove_if(kietekai.begin(), kietekai.end(), vargsiukas), kietekai.end());
    cout << "Mokiniai padalinti i dvi grupes per: " << durationDouble(hrClock::now() - sortStart).count() << " sek." << endl;
}
void application::MokiniuSortiravimas(vector<Mokinys>& kietekai, vector<Mokinys>& vargsai, vector<Mokinys>& mokiniai)
{
    auto sortStart = hrClock::now();
    for (auto& mok : mokiniai)
    {
        if (mok.getVidurkis() < 5 || mok.getMediana() < 5)
        {
            vargsai.push_back(mok);
        }
        else
        {
            kietekai.push_back(mok);
        }
    }
    mokiniai.clear();
    cout << "Mokiniai padalinti i dvi gupes per: " << durationDouble(hrClock::now() - sortStart).count() << " sek." << endl;
}

void application::MokiniuSortiravimas(list<Mokinys>& kietekai, list<Mokinys>& vargsai, list<Mokinys>& mokiniai)
{
    auto sortStart = hrClock::now();
    for (auto& mok : mokiniai)
    {
        if (mok.getVidurkis() < 5 || mok.getMediana() < 5)
        {
            vargsai.push_back(mok);
        }
        else
        {
            kietekai.push_back(mok);
        }
    }
    mokiniai.clear();
    cout << "Mokiniai padalinti i dvi gupes per: " << durationDouble(hrClock::now() - sortStart).count() << " sek." << endl;
}

void application::MokiniuSortiravimas(deque<Mokinys>& kietekai, deque<Mokinys>& vargsai, deque<Mokinys>& mokiniai)
{
    auto sortStart = hrClock::now();
    for (auto& mok : mokiniai)
    {
        if (mok.getVidurkis() < 5 || mok.getMediana() < 5)
        {
            vargsai.push_back(mok);
        }
        else
        {
            kietekai.push_back(mok);
        }
    }
    mokiniai.clear();
    cout << "Mokiniai padalinti i dvi gupes per: " << durationDouble(hrClock::now() - sortStart).count() << " sek." << endl;
}

void application::runAutoMode()
{
    cout << "Pasirinkite tipa: 1 - vectorius, 2 - listas, 3 - deque" << endl;
    contTipas = validMode(1, 3);
    cout << "Kokia strategija norite naudotis, greitesne kuri naudoja daugiau atmintis - 1, ar 2 - letesne kuri uzima maziau atminties" << endl;
    strategyType = validMode(1, 2);

    if (contTipas == 1)
    {
        vector<Mokinys> mokiniai;
        vector<Mokinys> vargsai;
        vector<Mokinys> kietekai;
        systemTimer.Start();
        processStarts(mokiniai, kietekai, vargsai);

        std::sort(kietekai.begin(), kietekai.end(), [](Mokinys& a, Mokinys& b)
            {return a.getFirstName() < b.getFirstName(); });
        std::sort(vargsai.begin(), vargsai.end(), [](Mokinys& a, Mokinys& b)
            {return a.getFirstName() < b.getFirstName(); });

        otherTimer.Start();
        contToFile("kietekai.txt", kietekai);
        contToFile("vargsai.txt", vargsai);
        cout << "Isrusiuoti mokinius i atskirus failus uztruko: " << otherTimer.StopReturn() << endl;
    }
    else if(contTipas == 2)
    {
        list<Mokinys> mokiniai;
        list<Mokinys> vargsai;
        list<Mokinys> kietekai;
        systemTimer.Start();
        processStarts(mokiniai, kietekai, vargsai);

        kietekai.sort(lyginimas);
        vargsai.sort(lyginimas);

        otherTimer.Start();
        contToFile("kietekai.txt", kietekai);
        contToFile("vargsai.txt", vargsai);
        cout << "Isrusiuoti mokinius i atskirus failus uztruko: " << otherTimer.StopReturn() << endl;
    }
    else if (contTipas == 3)
    {
        deque<Mokinys> mokiniai;
        deque<Mokinys> vargsai;
        deque<Mokinys> kietekai;
        systemTimer.Start();
        processStarts(mokiniai, kietekai, vargsai);

        std::sort(kietekai.begin(), kietekai.end(), [](Mokinys& a, Mokinys& b)
            {return a.getFirstName() < b.getFirstName(); });
        std::sort(vargsai.begin(), vargsai.end(), [](Mokinys& a, Mokinys& b)
            {return a.getFirstName() < b.getFirstName(); });

        otherTimer.Start();
        contToFile("kietekai.txt", kietekai);
        contToFile("vargsai.txt", vargsai);
        cout << "Isrusiuoti mokinius i atskirus failus uztruko: " << otherTimer.StopReturn() << endl;
    }
    cout << "Programa veike: " << systemTimer.StopReturn() << " sek." << endl;
    cout << "=======================" << endl;
}

void application::runManualMode()
{
    vector<Mokinys> mokiniai;
    cout << "Jeigu norite ivesti egzamino ivertinima spauskite 1, jeigu norite sugeneruoti automatiskai - 0" << endl;
    egzaminas = validMode(0, 1);
    cout << "Jeigu norite suvesti pazymius ranka spauskite 1, jeigu norite sugeneruoti automatiskai - 0" << endl;
    pazymys = validMode(0, 1);

    while (true)
    {
        cout << "Jeigu norite ivesti mokini spauskite 1, jeigu norite baigti - 0" << endl;
        bool run = validMode(0, 1);
        if (!run)
            break;
        else
        {
            Mokinys temp;
            ivestis(temp);
            mokiniai.push_back(temp);
        }
    }
    for (auto& mok : mokiniai)
        mok.RezSk();

    std::sort(mokiniai.begin(), mokiniai.end(), [](Mokinys& a, Mokinys& b)
        {return a.getFirstName() < b.getLastName(); });

    buferioRasymas("ats.txt", mokiniai);
    cout << "Programos veikimo laikas: " << durationDouble(hrClock::now() - programStart).count() << " sek." << endl;
    cout << "=============================" << endl;
}

void application::processStarts(vector<Mokinys>& mokiniai, vector<Mokinys>& kietekai, vector<Mokinys>& vargsai)
{
    if (strategyType == 1)
    {
        buferioSkaitymas(mokiniai);
        for (auto el : mokiniai)
            el.RezSk();
        MokiniuSortiravimas(kietekai, vargsai, mokiniai);
    }
    else if (strategyType == 2)
    {
        buferioSkaitymas(kietekai);
        for (auto el : kietekai)
            el.RezSk();
        MokiniuSortiravimasV2(kietekai, vargsai);
    }
}

void application::processStarts(list<Mokinys>& mokiniai, list<Mokinys>& kietekai, list<Mokinys>& vargsai)
{
    if (strategyType == 1)
    {
        buferioSkaitymas(mokiniai);
        for (auto el : mokiniai)
            el.RezSk();
        MokiniuSortiravimas(kietekai, vargsai, mokiniai);
    }
    else if (strategyType == 2)
    {
        buferioSkaitymas(kietekai);
        for (auto el : kietekai)
            el.RezSk();
        MokiniuSortiravimasV2(kietekai, vargsai);
    }
}

void application::processStarts(deque<Mokinys>& mokiniai, deque<Mokinys>& kietekai, deque<Mokinys>& vargsai)
{
    if (strategyType == 1)
    {
        buferioSkaitymas(mokiniai);
        for (auto el : mokiniai)
            el.RezSk();
        MokiniuSortiravimas(kietekai, vargsai, mokiniai);
    }
    else if (strategyType == 2)
    {
        buferioSkaitymas(kietekai);
        for (auto el : kietekai)
            el.RezSk();
        MokiniuSortiravimasV2(kietekai, vargsai);
    }
}
