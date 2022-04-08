#pragma once
#include<cstdio>
#include<iostream>
#include<string>
#include<vector>
#include<iterator>
#include<fstream>
using namespace std;

#include "slavic.cpp"
#include "Germanic.cpp"
#include "iran.cpp"

class Menu {
private:
    vector<IELang*> language_list;
    void add_base_lang();

    vector<Slavic*> slavic_list;
    void add_slavic_lang();

    vector<Iran*> iranian_list;
    void add_iranian_lang();

    vector<Germanic*> germanic_list;
    void add_germanic_lang();

public:
    Menu();
    ~Menu();
    void printAll();
    void printSlv();
    void printIrn();
    void printGrm();
    void edit();
    void delAll();
    void addLang();
    void MainMenu();
    void save();
    void viability(int id);
    void literatureGrm();
    void understandSlv();
    void usageIrn();
    //void load();
};