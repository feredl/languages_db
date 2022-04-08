#include "language.h"
#include <utility>

IELang::IELang() {
    name = "no name";
    speakers_amount = 0;
    writing_type = "writing type not chosen";
}

IELang::~IELang() = default;;

string IELang::get_name() {
    return name;
};

long long int IELang::get_speakers_amount() {
    return speakers_amount;
};

string IELang::get_writing_type() {
    return writing_type;
};
void IELang::set_name(string lang_name) {
    name = std::move(lang_name);
};

void IELang::set_speakers_amount(long long int new_speakers_amount){
    speakers_amount = new_speakers_amount;
};

void IELang::set_writing_type(int a) {
    switch (a) {
        case 1:
            writing_type = "ideographic";
            break;
        case 2:
            writing_type = "syllabic";
            break;
        case 3:
            writing_type = "phonetic";
            break;
        default:
            cout << "try again" << endl;
            break;
    }
};

void IELang::add(){
    string str_boof;
    int int_boof;

    cout << "set language name: ";
    cin.ignore();
    getline(cin, str_boof);
    set_name(str_boof);

    cout << "set speakers amount: ";
    cin >> int_boof;
    set_speakers_amount(int_boof);

    cout << "set writing type: "
    <<"1 - 'ideographic'" << endl <<
    "2 - 'syllabic' " << endl <<
    "3 - 'phonetic' " << endl;
    cin >> int_boof;
    set_writing_type(int_boof);
}
void IELang::save(ofstream &F) {
    F << "\t<" << "Language" << ">" << endl;
    F << "name: " << name << endl <<
      "speakers amount: " << speakers_amount << endl <<
      "writing type: " << writing_type << endl;
};

void IELang::print()
{
    cout << "language name: " << name << endl <<
         "amount of speakers: " << speakers_amount << endl <<
         "type of writing: " << writing_type << endl;
};

void IELang::edit(){
    string str_boof;
    long long int longint_boof;
    int int_boof;
    int a;
    cout << "Editing language\n1 for setting new language name\n"
            "2 for setting new amount of speakers\n"
            "3 for setting new writing type\n"
            "if you don't want to edit these fields press 0"<< endl;
    cin >> a;
    switch (a)
    {
        case 1:
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            getline(cin, str_boof);
            set_name(str_boof);
            return;
        case 2:
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            cin >> longint_boof;
            set_speakers_amount(longint_boof);
            return;
        case 3:
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            cout <<"1 - 'ideographic'" << endl <<
            "2 - 'syllabic' " << endl <<
            "3 - 'phonetic' " << endl;
            cin >> int_boof;
            set_writing_type(int_boof);
            return;
        default:
            break;
    }
}
