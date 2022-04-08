#include "iran.h"

Iran::Iran() {
    alphabet = "not chosen";
    religious_usage = "not defined";
}
Iran::~Iran() {
    cout << "Called for a destructor";
}
string Iran::get_alphabet()
{
    return alphabet;
}
string Iran::get_religious_usage()
{
    return religious_usage;
}

int Iran::set_alphabet(int d) {
    switch (d) {
        case 1:
            alphabet = "Arabic script";
            break;
        case 2:
            alphabet = "roman";
            break;
        case 3:
            alphabet = "cyrillic";
            break;
        default:
            cout << "try again" << endl;
            break;
    }
    return 0;
}

int Iran::set_religious_usage(int f) {
    if (f == 1) {
        religious_usage = "used as confessional";
    }
    if (f == 2) {
        religious_usage = "not used as confessional";
    }
    return 0;
}

void Iran::save(ofstream &F) {
    IELang::save(F);
    F << "alphabet: " << alphabet << endl <<
      "religious usage: " << religious_usage << endl << endl;
}

void Iran::add() {
    IELang::add();
    int int_boof;
    cout << "set alphabet for the Iranian language: " << endl;
    cout << "1 - 'Arabic script'" << endl <<
         "2 - 'roman' " << endl <<
         "3 - 'cyrillic' " << endl;
    cin >> int_boof;
    set_alphabet(int_boof);

    cout << "choose if the language is used for religious purposes:" << endl;
    cout << "1 - used as confessional" << endl <<
         "2 - not used as confessional " << endl;
    cin >> int_boof;
    set_religious_usage(int_boof);
}
void Iran::print() {
    IELang::print();
    cout << "alphabet: " << alphabet << endl <<
         "religious usage: " << religious_usage << endl;
}
void Iran::edit() {
    IELang::edit();
    string str_boof;
    int int_boof;
    int a;
    cout << "4 for setting new alphabet type\n"
            "5 for choosing religious usage\n"
            ""<< endl;
    cin >> a;
    switch (a)
    {
        case 4:
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            cout << "1 - 'Arabic script'" << endl <<
                 "2 - 'roman' " << endl <<
                 "3 - 'cyrillic' " << endl;
            cin >> int_boof;
            set_alphabet(int_boof);
            return;
        case 5:
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            cout << "1 - used as confessional" << endl <<
                 "2 - not used as confessional " << endl;
            cin >> int_boof;
            set_religious_usage(int_boof);
        default:
            cout << "try again" << endl;
}}

void Iran::usage_sphere(long long int z) {
    if (z >= 35000000){
        cout << "The language is national" << endl;
    }
    if (25000000 <= z && z < 35000000){
        cout << "The language is literary" << endl;
    }
    if (6000000 <= z && z < 25000000){
        cout << "The language is used in media" << endl;
    }
    if (3000000 <= z && z < 6000000){
        cout << "The language is used while trading" << endl;
    }
    if (125000 <= z && z < 3000000){
        cout << "The language is used in a very small local media" << endl;
    }
    if (1 <= z && z < 125000){
        cout << "The language is used for speaking at home" << endl;
    }
    else
        cout << "404";
}



