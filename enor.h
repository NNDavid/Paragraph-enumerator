#ifndef ENOR_H_INCLUDED
#define ENOR_H_INCLUDED

#include<fstream>
#include<string>
enum Status {norm,abnorm};
struct Bekezdes{
    bool jo;
    int sorszam;
};

class Enor{
    private:
        std::ifstream f;
        std::string sor;
        Status st;
        Bekezdes akt;
        bool vege;
        void read();
    public:
        Enor(const std::string &str);
        void first(){read();next();}
        void next();
        Bekezdes current() const {return akt;}
        bool end(){return vege;}
};
#endif // ENOR_H_INCLUDED
