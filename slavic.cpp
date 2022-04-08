#include "slavic.h"
Slavic::Slavic() {
    spread = "spread is not known";
    alphabet = "alphabet not chosen";
};

void Slavic::understand(string spread1, string spread2) {
    if (spread1 == spread2){
        cout << "The speakers of the languages will understand each other";
    }
    else
        cout << "The speakers of the languages won't understand each other";
};

string Slavic::get_spread(){
    return spread;
};

string Slavic::get_alphabet(){
    return alphabet;
};

int Slavic::set_spread(int b){
    switch (b) {
        case 1:
            spread = "western";
            break;
        case 2:
            spread = "southern";
            break;
        case 3:
            spread = "eastern";
            break;
        default:
            cout << "try again" << endl;
            set_spread(b);
            break;
    }
    return 0;
};

int Slavic::set_alphabet(int c){
    switch (c) {
        case 1:
            alphabet = "cyrillic";
            break;
        case 2:
            alphabet = "roman";
            break;
        default:
            cout << "try again" << endl;
            break;
    }
    return 0;
};

void Slavic::save(ofstream &F) {
    IELang::save(F);
    F << "spread: " << spread << endl <<
      "alphabet: " << alphabet << endl;
    F << "\t</" << "Language" << ">\n" << endl;
}

void Slavic::add(){
    IELang::add();
    int int_boof;
    cout << "set spread for the slavic language: " << endl;
    cout << "1 - 'western'" << endl <<
         "2 - 'southern' " << endl <<
         "3 - 'eastern' " << endl;
    cin.ignore();
    cin >> int_boof;
    set_spread(int_boof);

    cout << "set alphabet for the slavic language:" << endl;
    cout << "1 - 'cyrillic'" << endl <<
         "2 - 'roman' " << endl;
    cin.ignore();
    cin >> int_boof;
    set_alphabet(int_boof);
};

void Slavic::print(){
    IELang::print();
    cout << "spread: " << spread << endl <<
         "alphabet: " << alphabet << endl;
};

void Slavic::edit() {
    IELang::edit();
    string str_boof;
    int int_boof;
    int a;
    cout << "4 for setting new writing type\n"
            "5 for choosing spread of a language\n"
            ""<< endl;
    cin >> a;
    switch (a)
    {
        case 4:
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            cout << "set new spread for the slavic language: " << endl;
            cout << "1 - 'western'" << endl <<
                 "2 - 'southern' " << endl <<
                 "3 - 'eastern' " << endl;
            cin >> int_boof;
            set_spread(int_boof);
            return;
        case 5:
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            cout << "set alphabet for the slavic language:" << endl;
            cout << "1 - 'cyrillic'" << endl <<
                 "2 - 'roman' " << endl;
            cin >> int_boof;
            set_alphabet(int_boof);
        default:
            cout << "try again" << endl;

}}
