/**
 * structstudent.h
 * Header-Datei fuer das Student-Struct.
 * Enthaelt Funktionsprototypen zum Verarbeiten von Student-Structs.
 *
 * @author Michelle Blau, Johannes Gerwert
 * @version 24.11.2018
 */

#include <iostream>
#include <fstream>
#include <string>


#ifndef STUDENT_H_
#define STUDENT_H_
#define MAX_GROESSE 256
using namespace std;

struct structStudent {
	unsigned int matrikelNr {0};
	string name {""};
	string vorname {""};
	string geburtsdatum {""};
	float durchschnittsnote {0.0F};
};


void ausgeben(const structStudent&);
bool ausDateiEinlesen(istream&, structStudent&);
bool vergleicheName(const structStudent&,const structStudent&);
bool vergleicheVorname(const structStudent&,const structStudent& );
bool vergleicheDurchschnittsnote(const structStudent&,const structStudent&);


#endif /* STUDENT_H_ */
