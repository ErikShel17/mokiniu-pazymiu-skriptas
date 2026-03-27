#include <iostream>
#include <string>
#include <limits>

using namespace std;

const int MAX_MOKINIU = 100;
const int MAX_PAZYMIU = 10;

int rastiMokini(const string vardai[], int kiekis, const string& vardas) {
    for (int i = 0; i < kiekis; i++) {
        if (vardai[i] == vardas) {
            return i;
        }
    }
    return -1;
}

int pazymiuKiekis(const int pazymiai[][MAX_PAZYMIU], int mokinys) {
    int kiekis = 0;
    while (kiekis < MAX_PAZYMIU && pazymiai[mokinys][kiekis] != 0) {
        kiekis++;
    }
    return kiekis;
}

void pridetiMokini(string vardai[], int pazymiai[][MAX_PAZYMIU], int& kiekis) {
    if (kiekis >= MAX_MOKINIU) {
        cout << "Mokiniu sarasas pilnas.\n";
        return;
    }

    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    cout << "Iveskite mokinio varda: ";
    getline(cin, vardai[kiekis]);

    cout << "Iveskite pazymius po viena (1-10). Baigti - 0.\n";

    for (int j = 0; j < MAX_PAZYMIU; j++) {
        int pazymys;
        cout << "Pazymys " << j + 1 << ": ";
        cin >> pazymys;

        while (cin.fail() || pazymys < 0 || pazymys > 10) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Neteisinga ivestis. Iveskite skaiciu nuo 0 iki 10: ";
            cin >> pazymys;
        }

        if (pazymys == 0) {
            break;
        }

        pazymiai[kiekis][j] = pazymys;
    }

    kiekis++;
    cout << "Mokinys pridetas.\n";
}

void rodytiVisus(const string vardai[], const int pazymiai[][MAX_PAZYMIU], int kiekis) {
    if (kiekis == 0) {
        cout << "Sarasas tuscias.\n";
        return;
    }

    for (int i = 0; i < kiekis; i++) {
        cout << i + 1 << ". " << vardai[i] << " -> ";

        int kiek = pazymiuKiekis(pazymiai, i);
        if (kiek == 0) {
            cout << "Nera pazymiu";
        }
        else {
            for (int j = 0; j < kiek; j++) {
                cout << pazymiai[i][j];
                if (j < kiek - 1) cout << ", ";
            }
        }
        cout << '\n';
    }
}

void rodytiViena(const string vardai[], const int pazymiai[][MAX_PAZYMIU], int kiekis) {
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string vardas;
    cout << "Iveskite mokinio varda: ";
    getline(cin, vardas);

    int indeksas = rastiMokini(vardai, kiekis, vardas);

    if (indeksas == -1) {
        cout << "Mokinys nerastas.\n";
        return;
    }

    cout << vardai[indeksas] << " pazymiai: ";

    int kiek = pazymiuKiekis(pazymiai, indeksas);
    if (kiek == 0) {
        cout << "Nera pazymiu";
    }
    else {
        for (int j = 0; j < kiek; j++) {
            cout << pazymiai[indeksas][j];
            if (j < kiek - 1) cout << ", ";
        }
    }
    cout << '\n';
}

void atnaujintiPazymi(string vardai[], int pazymiai[][MAX_PAZYMIU], int kiekis) {
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string vardas;
    cout << "Iveskite mokinio varda: ";
    getline(cin, vardas);

    int indeksas = rastiMokini(vardai, kiekis, vardas);

    if (indeksas == -1) {
        cout << "Mokinys nerastas.\n";
        return;
    }

    int kiek = pazymiuKiekis(pazymiai, indeksas);
    if (kiek == 0) {
        cout << "Sis mokinys neturi pazymiu.\n";
        return;
    }

    int nr;
    cout << "Kuri pazymi norite pakeisti? (1-" << kiek << "): ";
    cin >> nr;

    while (cin.fail() || nr < 1 || nr > kiek) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Neteisingas numeris. Iveskite nuo 1 iki " << kiek << ": ";
        cin >> nr;
    }

    int naujas;
    cout << "Iveskite nauja pazymi (1-10): ";
    cin >> naujas;

    while (cin.fail() || naujas < 1 || naujas > 10) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Neteisinga ivestis. Iveskite nuo 1 iki 10: ";
        cin >> naujas;
    }

    pazymiai[indeksas][nr - 1] = naujas;
    cout << "Pazymys atnaujintas.\n";
}

void pasalintiMokini(string vardai[], int pazymiai[][MAX_PAZYMIU], int& kiekis) {
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string vardas;
    cout << "Iveskite mokinio varda, kuri norite pasalinti: ";
    getline(cin, vardas);

    int indeksas = rastiMokini(vardai, kiekis, vardas);

    if (indeksas == -1) {
        cout << "Mokinys nerastas.\n";
        return;
    }

    for (int i = indeksas; i < kiekis - 1; i++) {
        vardai[i] = vardai[i + 1];
        for (int j = 0; j < MAX_PAZYMIU; j++) {
            pazymiai[i][j] = pazymiai[i + 1][j];
        }
    }

    vardai[kiekis - 1] = "";
    for (int j = 0; j < MAX_PAZYMIU; j++) {
        pazymiai[kiekis - 1][j] = 0;
    }

    kiekis--;
    cout << "Mokinys pasalintas.\n";
}

int main() {
    string vardai[MAX_MOKINIU];
    int pazymiai[MAX_MOKINIU][MAX_PAZYMIU] = { 0 };
    int kiekis = 0;

    int pasirinkimas;

    do {
        cout << "\n--- Meniu ---\n";
        cout << "1. Ivesti mokini ir jo pazymius\n";
        cout << "2. Perziureti visu mokiniu sarasa\n";
        cout << "3. Perziureti konkretaus mokinio pazymius\n";
        cout << "4. Atnaujinti konkretu pazymi\n";
        cout << "5. Pasalinti mokini\n";
        cout << "0. Baigti darba\n";
        cout << "Pasirinkite veiksma: ";
        cin >> pasirinkimas;

        while (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Neteisinga ivestis. Bandykite dar karta: ";
            cin >> pasirinkimas;
        }

        switch (pasirinkimas) {
        case 1:
            pridetiMokini(vardai, pazymiai, kiekis);
            break;
        case 2:
            rodytiVisus(vardai, pazymiai, kiekis);
            break;
        case 3:
            rodytiViena(vardai, pazymiai, kiekis);
            break;
        case 4:
            atnaujintiPazymi(vardai, pazymiai, kiekis);
            break;
        case 5:
            pasalintiMokini(vardai, pazymiai, kiekis);
            break;
        case 0:
            cout << "Programa baigta.\n";
            break;
        default:
            cout << "Neteisingas pasirinkimas.\n";
        }

    } while (pasirinkimas != 0);

    return 0;
}