/**
 * structstudent.cpp
 * Source-Datei von structstudent.h, enthaelt Implementierungen der Funktionen.
 *
 * @author Michelle Blau, Johannes Gerwert
 * @version 26.11.2018
 */

#include "structstudent.h"

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

/**
 * Gibt die Komponenten eines Student-Structs im CSV-Format
 * auf der Standardausgabe aus.
 *
 * @param student Auszugebendes Student-Struct
 */
void ausgeben(const structStudent& student){
	cout << student.matrikelNr << ";"<< student.name << ";";
	cout << student.vorname << ";"<< student.geburtsdatum << ";";
	cout << student.durchschnittsnote << ";" << endl;
}

/**
 * Liest Datei-Inhalte ein und speichert diese in einem Struct.
 * Gibt true zurueck, wenn beim Einlesen keine Fehler auftreten, sonst false.
 *
 * Die Dateiinhalte muessen folgendes Format haben:
 * Matrikelnummer;Name;Vorname;Geburtsdatum;Durchschnittsnote;
 *
 * @param eingabestrom Liest Daten aus einer zuvor festgelegten Datei ein
 * @param student Struct, in dem die Daten gespeichert werden
 *
 * @return Das good-Bit von "eingabestrom"
 */
bool ausDateiEinlesen(istream& eingabestrom, structStudent& student){
	
	char nameCharArray[MAX_GROESSE];
	char vornameCharArray[MAX_GROESSE];
	char geburtsdatumCharArray[MAX_GROESSE];

	eingabestrom >> student.matrikelNr;
	eingabestrom.get();

	eingabestrom.getline(nameCharArray, MAX_GROESSE, ';');
	eingabestrom.getline(vornameCharArray, MAX_GROESSE, ';');
	eingabestrom.getline(geburtsdatumCharArray, MAX_GROESSE, ';');

	eingabestrom >> student.durchschnittsnote;
	eingabestrom.get();

	student.name = nameCharArray;
	student.vorname = vornameCharArray;
	student.geburtsdatum = geburtsdatumCharArray;

	return eingabestrom.good();
}

/**
 * Vergleicht die "name-Komponente" zweier Student-Structs.
 * Wird spaeter zum Sortieren verwendet.
 *
 * @param stud1
 * @param stud2
 */
bool vergleicheName(const structStudent& stud1,const structStudent& stud2){
	return stud1.name < stud2.name;
}

/**
 * Vergleicht die "vorname-Komponente" zweier Student-Structs.
 * Wird spaeter zum Sortieren verwendet.
 *
 * @param stud1
 * @param stud2
 */
bool vergleicheVorname(const structStudent& stud1,const structStudent& stud2){
	return stud1.vorname < stud2.vorname;
}

/**
 * Vergleicht die "durchschnittsnote-Komponente" zweier Student-Structs.
 * Wird spaeter zum Sortieren verwendet.
 *
 * @param stud1
 * @param stud2
 */
bool vergleicheDurchschnittsnote(const structStudent& stud1,const structStudent& stud2){
	return stud1.durchschnittsnote < stud2.durchschnittsnote;
}

