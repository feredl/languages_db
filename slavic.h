#pragma once
#include "language.h"

class Slavic : public IELang {
private:
    string spread;
    string alphabet;
public:
    Slavic();
    //~Slavic();

    string get_spread();
    string get_alphabet();

    int set_spread(int b);
    int set_alphabet(int c);

    void edit() override;
    static void understand(string spread1, string spread2);
    void save(ofstream &F) override;
    void add() override;
    void print() override;
};