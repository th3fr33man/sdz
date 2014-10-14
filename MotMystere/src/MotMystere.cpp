//============================================================================
// Name        : MotMystere.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;


string melangerMot(string mot, string& motMelange)
{
	srand(time(0)); // lance la g�n�ration de chiffre al�atoire
	while(mot.size() != 0)
	{
		int pos = rand() % mot.size();
		cout << "lettre : " << pos << endl;
		motMelange += mot[pos];
		mot.erase(pos,1);
	}

}

string demanderMot()
{
	string mot("");
	cout << "choisissez un mot a faire deviner : " << endl;
	cin >> mot;
	return mot;
}


int main() {

	char c('q');

	do
	{
		// demander le mot � deviner
		string mot(demanderMot());
		string motMelange("");
		string motTest("");

		// melanger le mot
		melangerMot(mot, motMelange);


		// demander le mot et verifier
		cout << "quel est ce mot? " <<  motMelange  << " " << endl;
		cin >> motTest;
		while(motTest.compare(mot) != 0)
		{
			cout << "le mot est incorrect, essayes encore! " << endl;
			cin >> motTest;
		}
		cout << "bien jou�!" << endl;
		cout << "appuyez sur q pour quitter, sur r pour rejouer !" << endl;
		cin >> c;
	} while (c == 'r');
	return 0;
}
