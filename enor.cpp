#include "enor.h"
#include <iostream>
#include <cstdlib>
using namespace std;

Enor::Enor(const string &str)
{
    f.open(str.c_str());
    if(f.fail())
    {
        cout <<"Nem lehet megnyitni az inputfajlt!\n";
        exit(1);
    }
    akt.sorszam=0;
}
void Enor::next()
{
    while(st==norm&&sor.size()==0)
        read();

    vege=st==abnorm;

    if(!vege)
    {
        akt.sorszam++;
        akt.jo=false;
        while(st==norm&&sor.size()!=0)
        {
            akt.jo=akt.jo || sor.find("alma")==string::npos;
            read();
        }
    }
}
void Enor::read()
{
    sor.clear();
    getline(f,sor);
    if(!f.fail()) st = norm;
    else st=abnorm;
}
