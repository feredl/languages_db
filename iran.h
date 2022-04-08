#pragma once
#include "language.cpp"

class Iran : public IELang {
private:
    string alphabet;
    string religious_usage;
public:
    Iran();
    ~Iran();
    string get_alphabet();
    string get_religious_usage();

    int set_alphabet(int d);
    int set_religious_usage(int f);

    void save(ofstream &F) override;
    void add() override;
    void print() override;
    void edit() override;
    void usage_sphere(long long int z);
};

