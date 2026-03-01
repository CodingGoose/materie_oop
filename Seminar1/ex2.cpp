#include <iostream>
#include <string>
// Definiere eine Struktur für die Eingabe von Kundendaten mit folgenden Informationen:
// Eine Nummer, ein Name, eine Postleitzahl, und eine Ortsname.
// Erzeugen Sie ein Array vom Typ der Struktur.

struct Kunde {
    int nummer;
    std::string name;
    int postleitzahl;
    std::string ortsname;
};

int main() {
    Kunde array[2];
    array[0] = {78457, "Petru", 400698, "Kolozs" };
    return 0;
}