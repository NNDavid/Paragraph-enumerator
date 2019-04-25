#include <iostream>
#include "enor.h"
#define NORMAL_MODE
#ifdef NORMAL_MODE
using namespace std;
int main()
{
   Enor t("input.txt");
   for(t.first();!t.end();t.next())
   {
       Bekezdes e = t.current();
       if(e.jo) cout<<e.sorszam<<endl;
   }

}
#else
#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include<vector>
TEST_CASE("ures fajl", "[t0.txt]")
{
    Enor t("input0.txt");
    for(t.first();!t.end();t.next())
       CHECK(2==3);
}
TEST_CASE("minden sorban alma","[t1.txt]")
{
    Enor t("input1.txt");
    for(t.first();!t.end();t.next())
    {
        Bekezdes e= t.current();
        CHECK_FALSE(e.jo);    }
}

TEST_CASE("almas es nem almas bekezdesek","[t2.txt]")
{
    Enor t("input2.txt");
    int bekezdeseknr=0;
    std::vector<Bekezdes> v;
    for(t.first();!t.end();t.next())
    {
        Bekezdes e=t.current();
        if(e.jo) v.push_back(e);

        bekezdeseknr++;
    }
    CHECK(bekezdeseknr==6);
    CHECK(v[0].sorszam==1);
    CHECK(v[1].sorszam==3);
    CHECK(v[2].sorszam==5);
    CHECK(v.size()==3);
}
TEST_CASE("minden bekezdes jo, de mindegyikben van egy almas sor","[t3.txt]")
{
    Enor t("input3.txt");
    for(t.first();!t.end();t.next());
        CHECK(t.current().jo);
}
#endif
