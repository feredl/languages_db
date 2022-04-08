#pragma once
#include "language.h"

class Germanic : public IELang {
private:
    string spread;
    string stress;
public:
    Germanic();
    //~Germanic();

    string get_spread();
    string get_stress();

    int set_spread(int b);
    int set_stress(int c);

    void literature(long long int amount);
    void save(ofstream &F) override;
    void add() override;
    void print() override;
    void edit() override;
};