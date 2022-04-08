#include "menu.h"

Menu::Menu()
{
    auto *new_lang = new IELang();
    language_list.push_back(new_lang);

    auto *new_lang1 = new Slavic();
    language_list.push_back(new_lang1);
    slavic_list.push_back(new_lang1);

    auto *new_lang2 = new Iran();
    language_list.push_back(new_lang2);
    iranian_list.push_back(new_lang2);

    auto *new_lang3 = new Germanic();
    language_list.push_back(new_lang3);
    germanic_list.push_back(new_lang3);
}

Menu::~Menu()
{
    cout << "Called for destructor" << endl;
}

void Menu::MainMenu() {
    int a;
    while (true)
    {
        cout << "Main menu\nEnter the type of operation\n1 - print\n2 - add new language\n"
                "3 - edit\n4 - delete\n5 - save\n"
                "6 - get some interesting information depending on the language family\n"
                "0 - exit\n" << endl;
        cin >> a;
        switch (a)
            {
                case 1:
                    int b;
                    cout << "Choose print options: \n";
                    cout << "1 - print All\n2 - print Slavic languages\n3 - print Iranian languages\n4 - print Germanic languages\n";
                    cin >> b;
                    switch(b) {
                        case 1:
                        printAll();
                        break;
                        case 2:
                        printSlv();
                        break;
                        case 3:
                        printIrn();
                        break;
                        case 4:
                        printGrm();
                        break;
                        default:
                            cout << "something's wrong";
                    }
                    break;
                case 2:
                    addLang();
                    break;
                case 3:
                    edit();
                    cout << "called edit()" << endl;
                    break;
                case 4:
                    delAll();
                    cout << "called del()" << endl;
                    break;
                case 5:
                    save();
                    break;
                case 6:
                    int o;
                    cout << "1 - check the viability of a language\n"
                            "2 - to see if a Germanic language is used as literary\n"
                            "3 - to see if two speakers of different Slavic languages can understand each other\n"
                            "4 - to see the sphere of usage of an Iranian language\n";
                    cin >> o;
                    switch(o) {
                        case 1:
                            cout << "Enter the number of language which viability you'd like to know: ";
                            int id;
                            cin >> id;
                            viability(id);
                            break;
                        case 2:
                            literatureGrm();
                            break;
                        case 3:
                            understandSlv();
                        case 4:
                            usageIrn();
                        default:
                            break;
                    }

                case 0:
                    return;
                default:
                    cout << "404" << endl;
                    break;
            }
        }
}
void Menu::edit() {
    //TODO
    int i;
    cout << "Enter the number of language: " << endl;
    cin >> i;
    if (i-1 < language_list.size())
        language_list[i-1]->edit();
    else cout << "Out of bounds" << endl;
}

void Menu::printAll() {
    for (unsigned int i = 0; language_list.size() > i; i++)
    {
        cout << i + 1 << ". ";
        language_list[i]->print();
        cout << endl;
    }
}

void Menu::printSlv() {
    for (unsigned int i = 0; slavic_list.size() > i; i++)
    {
        cout << i + 1 << ". ";
        slavic_list[i]->print();
        cout << endl;
    }
}

void Menu::printGrm() {
    for (unsigned int i = 0; germanic_list.size() > i; i++)
    {
        cout << i + 1 << ". ";
        germanic_list[i]->print();
        cout << endl;
    }
}

void Menu::printIrn() {
    for (unsigned int i = 0; iranian_list.size() > i; i++)
    {
        cout << i + 1 << ". ";
        iranian_list[i]->print();
        cout << endl;
    }
}

void Menu::save()
{
    ofstream F;
    F.open("database.txt");
    for (auto & i : language_list)
        if (i->get_name() != "no name") {
            i->save(F);
        }
}

void Menu::addLang() {
    int a;
    cout << "Creating new language\n1 - Indo-European language\n2 - Slavic language\n3 - Iranian language\n4 - Germanic" << endl;
    cin >> a;
    switch (a)
    {
        case 1:
            add_base_lang();
            return;
        case 2:
            add_slavic_lang();
            return;
        case 3:
            add_iranian_lang();
            return;
        case 4:
            add_germanic_lang();
            return;
        default:
            cout << "try again" << endl;
    }
}

void Menu::add_base_lang()
{
    auto *new_lang = new IELang();
    new_lang->add();
    language_list.push_back(new_lang);
};

void Menu::add_slavic_lang()
{
    auto *new_lang = new Slavic();
    new_lang->add();
    language_list.push_back(new_lang);
    slavic_list.push_back(new_lang);
}

void Menu::add_iranian_lang() {
    auto *new_lang = new Iran();
    new_lang->add();
    language_list.push_back(new_lang);
    iranian_list.push_back(new_lang);
}

void Menu::add_germanic_lang() {
    auto *new_lang = new Germanic();
    new_lang->add();
    language_list.push_back(new_lang);
    germanic_list.push_back(new_lang);
};

void Menu::delAll() {
    vector<IELang*> v;
    int s;
    cout << "1 - delete all\n2 - delete Slavic languages from database\n3 - delete Iranian languages from database\n"
            "4 - delete Germanic languages from database" << endl;
    cin >> s;
    switch (s) {
        case 1:
            language_list.clear();
            slavic_list.clear();
            germanic_list.clear();
            iranian_list.clear();
        case 2:
            set_difference(language_list.begin(), language_list.end(), slavic_list.begin(), slavic_list.end(), back_inserter(v));
            language_list.swap(v);
            slavic_list.clear();
        case 3:
            set_difference(language_list.begin(), language_list.end(), iranian_list.begin(), iranian_list.end(), back_inserter(v));
            language_list.swap(v);
            iranian_list.clear();
        case 4:
            set_difference(language_list.begin(), language_list.end(), germanic_list.begin(), germanic_list.end(), back_inserter(v));
            language_list.swap(v);
            germanic_list.clear();
        default:
            break;
    }
}

void Menu::viability(int id) {
    long long int ns = language_list[id - 1]->get_speakers_amount();
    if (ns > 1000000) {
        cout << "The language is 'safe'" << endl;
    }
    if (10000 <= ns && ns < 1000000){
        cout << "The language is 'vulnerable'" << endl;
    }
    if (5000 <= ns && ns < 10000){
        cout << "The language is 'definitely endangered'" << endl;
    }
    if (3000 <= ns && ns < 5000){
        cout << "The language is 'severely endangered'" << endl;
    }
    if (0 < ns && ns < 3000){
        cout << "The language is 'nearly extinct'" << endl;
    }
    if (ns == 0){
        cout << "The language is 'extinct'" << endl;
    }
}

void Menu::literatureGrm() {
    int i;
    printGrm();
    cout << "To see if a language is used as literary enter the number of language (the list is above): " << endl;
    cin >> i;
    if (i-1 < germanic_list.size()) {
        long long int z = germanic_list[i-1]->get_speakers_amount();
        germanic_list[i-1]->literature(z);
    }
    else cout << "Out of bounds" << endl;
}

void Menu::understandSlv() {
    int f, s;
    printSlv();
    cout << "To see if 2 speakers of different SLAVIC languages can understand each other\n"
            "write these language's numbers from the list above: " << endl;
    cout << "first: ";
    cin >> f;
    cout << "second: ";
    cin >> s;
    if (s-1 && f-1 < slavic_list.size()) {
        string z = slavic_list[f-1]->get_spread();
        string z1 = slavic_list[f-2]->get_spread();
        Slavic::understand(z, z1);
    }
    else cout << "Out of bounds" << endl;
}

void Menu::usageIrn() {
    int i;
    printIrn();
    cout << "To see the sphere of usage of an IRANIAN language the the number (the list is above): " << endl;
    cin >> i;
    if (i-1 < iranian_list.size()) {
        long long int z = iranian_list[i-1]->get_speakers_amount();
        iranian_list[i-1]->usage_sphere(z);
    }
    else cout << "Out of bounds" << endl;
}
