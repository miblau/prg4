/**
 * a.cpp
 *
 * @author Michelle Blau, Johannes Gerwert
 * @version 24.11.2018
 */

#include <algorithm>
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

/**Konstanten**/


/**Funktions-Prototypen**/
int zaehleWoerter(char*);
bool istLeerzeichen(char);
int ueberspringeRestLeerzeichen(char*, int);



/**
 * @param argc Anzahl Parameter
 * @param argv
 *
 * @return 0
 */
int main (int argc, char** argv){
	char* wort ="hallo Guten   Tag";
	int anzahl = zaehleWoerter(wort);

	cout << anzahl << endl;

	return 0;
}

int zaehleWoerter(char* charString){
	int anzahlWoerter{1};

	for(int i = 0; *charString != '\0'; i++ ){
		if(istLeerzeichen(*(charString))){
			anzahlWoerter++;
			ueberspringeRestLeerzeichen(charString);
		}
		cout << "Anzahl Zeichen: " << i << endl;
	}
	return anzahlWoerter;
}


bool istLeerzeichen(char zeichen){
	char linefeed{10};
	char blank{32};
	char tab{9};

	return ((zeichen == linefeed) || (zeichen == blank) || (zeichen == tab));
}


void ueberspringeRestLeerzeichen(char* charString){

}

