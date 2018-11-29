/**
 * readCSV.cpp
 * Liest csv-Datei mit Studentendaten aus dem aktuellen Verzeichnis ein
 * und wertet diese aus.
 *
 * @author Michelle Blau, Johannes Gerwert
 * @version 24.11.2018
 */

#include <algorithm>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "structstudent.h"
using namespace std;

/**Konstanten**/
constexpr auto DATEINAME = "studentendaten.csv";

/**Funktions-Prototypen**/
void vectorAusgeben(const vector<structStudent>&);



/**
 * Liest Inhalte aus der Datei DATEINAME und speichert diese
 * in einer Datenstruktur bestehend aus Studenten-Structs
 *
 * @param argc Anzahl Parameter
 * @param argv Wird nicht verwendet
 *
 * @return 1, falls Datei sich nicht oeffnen laesst, sonst 0
 */
int main (int argc, char** argv){
	vector<structStudent> studentVector;
	ifstream eingabestrom;

	eingabestrom.open(DATEINAME, ios::in);
	if(eingabestrom.good() == false){
		cout << DATEINAME << " kann nicht geoeffnet werden\n\n";
		return 1;
	}

	for(int zeile = 1; eingabestrom.eof() == false; zeile++){
		structStudent tmpStudent;
		bool einlesenOK = ausDateiEinlesen(eingabestrom, tmpStudent);

		if(einlesenOK){
			studentVector.push_back(tmpStudent);
		}else if(eingabestrom.eof()) {
			cout << "Eof in Zeile: " << zeile << endl;;
		}else{
			cout << "Einlesen war nicht ok in Zeile: " << zeile << endl;
			eingabestrom.clear();
			eingabestrom.ignore(MAX_GROESSE, '\n');
		}
	}

	cout << "--Sortierung nach Name, Vorname:--" << endl;
	sort(studentVector.begin(), studentVector.end(), vergleicheName);
	vectorAusgeben(studentVector);

	cout << "--Sortierung nach Durchschnittsnote, aufsteigend:--" << endl;
	sort(studentVector.begin(), studentVector.end(), vergleicheDurchschnittsnote);
	vectorAusgeben(studentVector);

	eingabestrom.close();
	cout << "Erfolgreich beendet!" << endl;
	return 0;
}


/**
 * Hilfsfunktion zum Ausgeben der Datenstruktur-Inhalte
 *
 * @param studentVector auszugebende Datenstruktur
 */
void vectorAusgeben (const vector<structStudent>& studentVector ){
	for(structStudent s : studentVector){
		ausgeben(s);
	}
	cout << "\n" << endl;
}


