#pragma once
#include<cstdio>
#include<iostream>
#include<string>
#include<vector>
#include<iterator>
#include<fstream>
#include<algorithm>

using namespace std;

class IELang {
protected:
    string name;
    long long int speakers_amount;
    string writing_type;

public:
    IELang();
    ~IELang();

    string get_name();
    long long int get_speakers_amount();
    string get_writing_type();

    void set_name(string lang_name);
    void set_speakers_amount(long long int n_speakers_amount);
    void set_writing_type(int a);

    virtual void save(ofstream &F);
    virtual void add();
    virtual void print();
    virtual void edit();
    //void viability(string lang);
};