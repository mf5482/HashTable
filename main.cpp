//This program creates a hash table for a list of unsorted names.

#include<iostream>
#include<fstream>
#include<string>
using namespace std;

struct hEntry {
    bool occupied = false;
    string fullName;
    struct hEntry *nextPtr = NULL;
};

const unsigned int LIMIT = 256; //global variable setting the amount of entries in structureArray
hEntry structureArray[LIMIT];

int main() {

    ifstream inputFile;
    string firstName;
    string lastName;
    string fullName;
    string file;
    struct hEntry *entry;

    cout << "Enter a file with names: ";
    getline(cin, file);

    inputFile.open(file);

    cout << endl;

    if (!inputFile.is_open()) {
        cout << "File not found\n";
        system("pause");
        return 0;

    }

    while (!inputFile.eof()) {

        inputFile >> firstName;
        inputFile >> lastName;

        if (inputFile.eof()) {
            break;
        }

        fullName = firstName + " " + lastName;

        unsigned char key = 0;

        for (int i = 0; i < fullName.length(); i++) {
            key ^= fullName[i];
        }

        if (structureArray[key].occupied != true) {
            structureArray[key].occupied = false;
        }

        if (structureArray[key].occupied == false) {

            structureArray[key].occupied = true;
            structureArray[key].fullName = fullName;
        }

        else if (structureArray[key].occupied == true) {
            struct hEntry *newEntry = new struct hEntry;
            newEntry->occupied = true;
            newEntry->fullName = fullName;


            entry = &structureArray[key];

            while (entry->nextPtr != NULL) {
            entry = entry->nextPtr;
            }

            entry->nextPtr = newEntry;

        }

    }

    for (int i = 0; i < LIMIT; i++) {
        if (structureArray[i].occupied == true) {
            cout << "Slot " << i << " is occupied with" << endl;

            entry = &structureArray[i];

            while (entry->nextPtr != NULL) {
                cout << entry->fullName;
                if(entry->nextPtr != NULL){
                    cout << ",";
                }
                cout << '\t';

                entry = entry->nextPtr;
            }
            cout << entry->fullName;
            cout << endl << endl;
        }
    }

    system("pause");
    return 0;



}
