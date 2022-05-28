#include "tikrinimas.h"

tikrinimas::tikrinimas()
{

}
tikrinimas::~tikrinimas()
{

}

int tikrinimas::IntTikrinimas()
{
    int t;
    while (true)
    {
        cin >> t;
        if (cin.good())
            return t;
        else
        {
            cout << " Ivedete neteisinga reiksme" << endl;
            cin.clear();
            cin.ignore(INT_MAX, '\n');
        }
    }
}

bool tikrinimas::PazTikrinimas(int t)
{
    if (t > 0 && t <= 10)
        return true;
    else
    {
        cout << " Ivestas neteisingas pazimys (desimtbale sistema)" << endl;
        return false;
    }
}

int tikrinimas::validMode(int from, int to)
{
    while (true)
    {
        int mode = IntTikrinimas();
        for (int i = from; i <= to; i++)
            if (mode == i)
                return mode;
        cout << "Neteisingas skaicius" << endl;
    }
}
