#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>
#include <cstdlib>
#include <ctime>
using namespace std;

const int MAX = 100;

void toLowercase(string &str) {
    transform(str.begin(), str.end(), str.begin(), ::tolower);
}

void toUppercase(string &str) {
    transform(str.begin(), str.end(), str.begin(), ::toupper);
}

void displayHeroes(string names[], string powers[], string weaknesses[], int details[][2], string universes[], int size, string caseType) {
    for (int i = 0; i < size; i++) {
        string n = names[i], p = powers[i], w = weaknesses[i], u = universes[i];
        if (caseType == "lower") {
            toLowercase(n); toLowercase(p); toLowercase(w); toLowercase(u);
        } else if (caseType == "upper") {
            toUppercase(n); toUppercase(p); toUppercase(w); toUppercase(u);
        }
        cout << n << " | " << p << " | " << w << " | " << details[i][0] << " | " << u << endl;
    }
}

int searchByName(string names[], int size, string target) {
    toLowercase(target);
    for (int i = 0; i < size; i++) {
        string temp = names[i];
        toLowercase(temp);
        if (temp.find(target) != string::npos) return i;
    }
    return -1;
}

void searchByPower(string powers[], string names[], int size, string target) {
    toLowercase(target);
    bool found = false;
    for (int i = 0; i < size; i++) {
        string temp = powers[i];
        toLowercase(temp);
        if (temp.find(target) != string::npos) {
            cout << names[i] << " has the power: " << powers[i] << endl;
            found = true;
        }
    }
    if (!found) {
        cout << "No superheroes found with that power.\n";
    }
}

void sortAlphabetically(string names[], string powers[], string weaknesses[], int details[][2], string universes[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = i + 1; j < size; j++) {
            if (names[i] > names[j]) {
                swap(names[i], names[j]);
                swap(powers[i], powers[j]);
                swap(weaknesses[i], weaknesses[j]);
                swap(details[i][0], details[j][0]);
                swap(details[i][1], details[j][1]);
                swap(universes[i], universes[j]);
            }
        }
    }
}

void showPowerRankings(string names[], int details[][2], int size) {
    cout << "\n--- Superhero Rankings (Power Level) ---\n";
    for (int i = 0; i < size; i++) {
        cout << names[i] << " | Power Level: " << details[i][1] << endl;
    }
}

void addNewHero(string names[], string powers[], string weaknesses[], int details[][2], string universes[], int &size) {
    if (size >= MAX) {
        cout << "Database full. Cannot add more superheroes.\n";
        return;
    }
    cout << "Enter hero name: ";
    cin.ignore();
    getline(cin, names[size]);
    cout << "Enter superpower: ";
    getline(cin, powers[size]);
    cout << "Enter weakness: ";
    getline(cin, weaknesses[size]);
    cout << "Enter year introduced: ";
    cin >> details[size][0];
    cout << "Enter universe (Marvel, DC, Other): ";
    cin.ignore();
    getline(cin, universes[size]);
    cout << "Enter power level (1-100): ";
    cin >> details[size][1];
    size++;
    cout << "Hero added successfully.\n";
}

void generateRandomHero(string names[], string powers[], string weaknesses[], int details[][2], string universes[], int size) {
    srand(time(0));
    int index = rand() % size;
    cout << "\n--- Random Superhero ---\n";
    cout << names[index] << " | " << powers[index] << " | " << weaknesses[index]
         << " | " << details[index][0] << " | " << universes[index]
         << " | Power Level: " << details[index][1] << endl;
}

int main() {
    string names[MAX] = {
        "Squirrel Girl", "Arm-Fall-Off-Boy", "The Tick", "Matter-Eater Lad",
        "Doorman", "Zeitgeist", "Ragman", "Elongated Man", "Dogwelder", "Bouncing Boy"
    };

    string powers[MAX] = {
        "Control Squirrels", "Detachable Limbs", "Super Strength", "Eats Anything",
        "Teleportation Access", "Acid Vomit", "Absorbs Souls", "Elasticity",
        "Welds Dogs to People", "Inflates Body"
    };

    string weaknesses[MAX] = {
        "Time Limits", "Heavy Objects", "Poor Judgment", "Indigestion",
        "Wall Only", "Inexperience", "Spiritual Drain", "Confusion",
        "Unknown", "Deflation"
    };

    string universes[MAX] = {
        "Marvel", "DC", "Other", "DC", "Marvel", "Marvel", "DC", "DC", "DC", "DC"
    };

    int details[MAX][2] = {
        {1992, 80}, {1989, 40}, {1986, 70}, {1962, 65},
        {1989, 50}, {2001, 55}, {1976, 75}, {1960, 68},
        {1996, 30}, {1961, 60}
    };

    int size = 10;
    int choice;

    do {
        cout << "\n--- Obscure Superhero Database ---\n";
        cout << "1. Search superhero by name\n";
        cout << "2. Find superheroes by power\n";
        cout << "3. Sort superheroes alphabetically\n";
        cout << "4. Display all superheroes (uppercase)\n";
        cout << "5. Display all superheroes (lowercase)\n";
        cout << "6. Show hero rankings (by power level)\n";
        cout << "7. Add a new superhero\n";
        cout << "8. Generate random superhero\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            string search;
            cin.ignore();
            cout << "Enter name to search: ";
            getline(cin, search);
            int idx = searchByName(names, size, search);
            if (idx != -1) {
                cout << names[idx] << " | " << powers[idx] << " | " << weaknesses[idx]
                     << " | " << details[idx][0] << " | " << universes[idx] << endl;
            } else {
                cout << "Superhero not found.\n";
            }
        } else if (choice == 2) {
            string powerSearch;
            cin.ignore();
            cout << "Enter power keyword to search: ";
            getline(cin, powerSearch);
            searchByPower(powers, names, size, powerSearch);
        } else if (choice == 3) {
            sortAlphabetically(names, powers, weaknesses, details, universes, size);
            cout << "Superheroes sorted alphabetically.\n";
        } else if (choice == 4) {
            displayHeroes(names, powers, weaknesses, details, universes, size, "upper");
        } else if (choice == 5) {
            displayHeroes(names, powers, weaknesses, details, universes, size, "lower");
        } else if (choice == 6) {
            showPowerRankings(names, details, size);
        } else if (choice == 7) {
            addNewHero(names, powers, weaknesses, details, universes, size);
        } else if (choice == 8) {
            generateRandomHero(names, powers, weaknesses, details, universes, size);
        }

    } while (choice != 0);

    return 0;
}
