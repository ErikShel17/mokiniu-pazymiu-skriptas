#include <iostream>
#include <string>
using namespace std;

// Maksimalūs dydžiai
const int MAX_MOKINIU = 100;
const int MAX_PAZYMIU = 10;

int main() {
    string vardai[MAX_MOKINIU]; // saugo mokinių vardus
    int pazymiai[MAX_MOKINIU][MAX_PAZYMIU] = { 0 }; // saugo pažymius

    int mokiniuKiekis = 0;
    int pasirinkimas;

    do {
        // Meniu
        cout << "\n--- MENIU ---\n";
        cout << "1. Prideti mokini\n";
        cout << "2. Rodyti visus mokinius\n";
        cout << "3. Rodyti vieno mokinio pazymius\n";
        cout << "4. Atnaujinti pazymi\n";
        cout << "5. Pasalinti mokini\n";
        cout << "0. Baigti\n";
        cout << "Pasirinkimas: ";
        cin >> pasirinkimas;

        // Tikrinam įvestį
        if (cin.fail()) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Bloga ivestis!\n";
            continue;
        }

        // 1. Pridėti mokinį
        if (pasirinkimas == 1) {
            if (mokiniuKiekis >= MAX_MOKINIU) {
                cout << "Sarasas pilnas\n";
                continue;
            }

            cout << "Iveskite varda: ";
            cin >> vardai[mokiniuKiekis];

            // Naujas įvedimo būdas
            cout << "Iveskite pazymius per tarpa (0 - baigti):\n";

            for (int j = 0; j < MAX_PAZYMIU; j++) {
                int p;
                cin >> p; // įvedam be papildomo teksto

                // Tikrinam ar skaičius
                if (cin.fail()) {
                    cin.clear();
                    cin.ignore(1000, '\n');
                    cout << "Iveskite skaiciu!\n";
                    j--;
                    continue;
                }

                if (p == 0) break; // baigiam įvedimą

                pazymiai[mokiniuKiekis][j] = p;
            }

            mokiniuKiekis++;
        }

        // 2. Rodyti visus mokinius
        else if (pasirinkimas == 2) {
            if (mokiniuKiekis == 0) {
                cout << "Nera mokiniu\n";
            }

            for (int i = 0; i < mokiniuKiekis; i++) {
                cout << vardai[i] << ": ";

                for (int j = 0; j < MAX_PAZYMIU; j++) {
                    if (pazymiai[i][j] == 0) break;
                    cout << pazymiai[i][j] << " ";
                }
                cout << endl;
            }
        }

        // 3. Rodyti vieno mokinio pažymius
        else if (pasirinkimas == 3) {
            string vardas;
            cout << "Iveskite varda: ";
            cin >> vardas;

            bool rastas = false;

            for (int i = 0; i < mokiniuKiekis; i++) {
                if (vardai[i] == vardas) {
                    cout << "Pazymiai: ";

                    for (int j = 0; j < MAX_PAZYMIU; j++) {
                        if (pazymiai[i][j] == 0) break;
                        cout << pazymiai[i][j] << " ";
                    }
                    cout << endl;
                    rastas = true;
                }
            }

            if (!rastas) {
                cout << "Mokinys nerastas\n";
            }
        }

        // 4. Atnaujinti pažymį
        else if (pasirinkimas == 4) {
            string vardas;
            cout << "Iveskite varda: ";
            cin >> vardas;

            for (int i = 0; i < mokiniuKiekis; i++) {
                if (vardai[i] == vardas) {
                    int nr, naujas;

                    cout << "Kuri pazymi keisti (1-10): ";
                    cin >> nr;

                    cout << "Naujas pazymys: ";
                    cin >> naujas;

                    if (nr >= 1 && nr <= MAX_PAZYMIU) {
                        pazymiai[i][nr - 1] = naujas;
                        cout << "Atnaujinta\n";
                    }
                    else {
                        cout << "Blogas numeris\n";
                    }
                }
            }
        }

        // 5. Pašalinti mokinį
        else if (pasirinkimas == 5) {
            string vardas;
            cout << "Iveskite varda: ";
            cin >> vardas;

            for (int i = 0; i < mokiniuKiekis; i++) {
                if (vardai[i] == vardas) {

                    // Perstumiam masyvą
                    for (int k = i; k < mokiniuKiekis - 1; k++) {
                        vardai[k] = vardai[k + 1];

                        for (int j = 0; j < MAX_PAZYMIU; j++) {
                            pazymiai[k][j] = pazymiai[k + 1][j];
                        }
                    }

                    mokiniuKiekis--;
                    cout << "Mokinys pasalintas\n";
                    break;
                }
            }
        }

    } while (pasirinkimas != 0);

    return 0;
}
