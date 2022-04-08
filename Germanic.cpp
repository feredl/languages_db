#include "Germanic.h"

Germanic::Germanic() {
    spread = "spread is not known"; // запад, восток, скандинавия
    stress = "stress is not chosen";// ударение на 1 или 2 часть слова
};

void Germanic::literature(long long int amount)
{
    if (amount > 100000000) {
        cout << "The language is literary " << name << endl;
    } else {
        cout << "The language is not literary  " << name << endl;
    }
}

string Germanic::get_spread(){
    return spread;
}

string Germanic::get_stress(){
    return stress;
}

//устанавливаем распространение
int Germanic::set_spread(int b){
    switch (b) {
        case 1:
            spread = "western";
            break;
        case 2:
            spread = "eastern";
            break;
        case 3:
            spread = "Scandinavian";
            break;
        default:
            cout << "try again" << endl;
            break;
    }
    return 0;
}
// устанавливаем тип ударения
int Germanic::set_stress(int c){
    switch (c) {
        case 1:
            stress = "first part of the word is stressed";
            break;
        case 2:
            stress = "second part of the word is stressed";
            break;
        default:
            cout << "try again" << endl;
            break;
    }
    return 0;
}

void Germanic::save(ofstream &F) {
    IELang::save(F);
    F << "spread: " << spread << endl <<
    "stress: " << stress << endl;
}

void Germanic::add(){
    IELang::add();
    int int_boof;
    cout << "set spread for the germanic language: " << endl;
    cout << "1 - 'western'" << endl <<
         "2 - 'eastern' " << endl <<
         "3 - 'Scandinavian' " << endl;
    cin >> int_boof;
    set_spread(int_boof);

    cout << "set stress rule for the germanic language: " << endl;
    cout << "1 - 'first part of the word is stressed'" << endl <<
         "2 - 'second part of the word is stressed'" << endl;
    cin >> int_boof;
    set_stress(int_boof);
}

void Germanic::print(){
    IELang::print();
    cout << "spread: " << spread << endl <<
    "stress: " << stress << endl;
}

void Germanic::edit() {
    IELang::edit();
    string str_boof;
    int int_boof;
    int a;
    cout << "4 for setting new spread\n"
            "5 for choosing stress rule\n"
            ""<< endl;
    cin >> a;
    switch (a)
    {
        case 4:
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            cout << "set new spread for the language: " << endl;
            cout << "1 - 'western'" << endl <<
                 "2 - 'eastern' " << endl <<
                 "3 - 'Scandinavian' " << endl;
            cin >> int_boof;
            set_spread(int_boof);
            return;
        case 5:
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            cout << "set new stress rule for the language: " << endl;
            cout << "1 - 'first part of the word is stressed'" << endl <<
                 "2 - 'second part of the word is stressed'" << endl;
            cin >> int_boof;
            set_stress(int_boof);
        default:
            break;
}}