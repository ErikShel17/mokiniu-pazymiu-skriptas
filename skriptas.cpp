#include <iostream>
#include <string>
using namespace std;

// Maksimalūs dydžiai pagal sąlygą
const int MAX_MOKINIU = 100;
const int MAX_PAZYMIU = 10;

int main() {
    // Vienmatis masyvas mokinių vardams
    string vardai[MAX_MOKINIU];

    // Dvimatis masyvas pažymiams
    int pazymiai[MAX_MOKINIU][MAX_PAZYMIU] = { 0 };

    int mokiniuKiekis = 0; // kiek turime mokinių
    int pasirinkimas;

    do {
        // Meniu pasirinkimui
        cout << "\n--- MENIU ---\n";
        cout << "1. Prideti mokini\n";
        cout << "2. Rodyti visus mokinius\n";
        cout << "3. Rodyti vieno mokinio pazymius\n";
        cout << "4. Atnaujinti pazymi\n";
        cout << "5. Pasalinti mokini\n";
        cout << "0. Baigti\n";
        cout << "Pasirinkimas: ";
        cin >> pasirinkimas;

        // 1. Pridėti mokinį
        if (pasirinkimas == 1) {
            if (mokiniuKiekis >= MAX_MOKINIU) {
                cout << "Nebegalima prideti daugiau mokiniu\n";
                continue;
            }

            cout << "Iveskite varda: ";
            cin >> vardai[mokiniuKiekis]; // įrašomas vardas

            // Įvedami pažymiai
            cout << "Iveskite pazymius (0 - baigti):\n";
            for (int j = 0; j < MAX_PAZYMIU; j++) {
                int p;
                cin >> p;

                if (p == 0) break; // stabdom įvedimą

                pazymiai[mokiniuKiekis][j] = p; // išsaugom pažymį
            }

            mokiniuKiekis++; // padidinam mokinių skaičių
        }

        // 2. Rodyti visus mokinius
        else if (pasirinkimas == 2) {
            for (int i = 0; i < mokiniuKiekis; i++) {
                cout << vardai[i] << ": ";

                // rodom pažymius
                for (int j = 0; j < MAX_PAZYMIU; j++) {
                    if (pazymiai[i][j] == 0) break;
                    cout << pazymiai[i][j] << " ";
                }
                cout << endl;
            }
        }

        // 3. Rodyti vieną mokinį
        else if (pasirinkimas == 3) {
            string vardas;
            cout << "Iveskite varda: ";
            cin >> vardas;

            // ieškom mokinio
            for (int i = 0; i < mokiniuKiekis; i++) {
                if (vardai[i] == vardas) {
                    cout << "Pazymiai: ";

                    // rodom pažymius
                    for (int j = 0; j < MAX_PAZYMIU; j++) {
                        if (pazymiai[i][j] == 0) break;
                        cout << pazymiai[i][j] << " ";
                    }
                    cout << endl;
                }
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

                    pazymiai[i][nr - 1] = naujas; // pakeičiam pažymį
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

                    // perstumiam masyvą į kairę
                    for (int k = i; k < mokiniuKiekis - 1; k++) {
                        vardai[k] = vardai[k + 1];

                        for (int j = 0; j < MAX_PAZYMIU; j++) {
                            pazymiai[k][j] = pazymiai[k + 1][j];
                        }
                    }

                    mokiniuKiekis--; // sumažinam kiekį
                    break;
                }
            }
        }

    } while (pasirinkimas != 0); // kartojam kol 0

    return 0;
}