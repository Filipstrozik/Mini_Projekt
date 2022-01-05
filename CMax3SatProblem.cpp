#include "CMax3SatProblem.h"
#include <fstream>
#include <iostream>
using namespace std;

CMax3SatProblem::CMax3SatProblem() {
	vec_clausesProblem.reserve(1000);
}

bool CMax3SatProblem::bLoad(std::string sPath) {
	ifstream file;
	file.open(sPath, std::ios::in);
	
	if (!file) {
		cout << "blad przy otwiernaiu pliku" << endl;
		return false;
	}
	int s1 = 0;
	int s2 = 0;
	int s3 = 0;

	if (file.is_open()) {

		while (!file.eof()) {
			file.ignore(100, ' ');
			file >> s1;
			//cout << s1 << endl;
			file.ignore(100, ' ');
			file >> s2;
			//cout << s2 << endl;;
			file.ignore(100, ' ');
			file >> s3;
			//cout << s3 << endl;
			file.ignore(100, '\n');
			// mamy inty pokolei
			vec_clausesProblem.push_back(new CClause(s1, s2, s3));
		}
		
		file.close();
	}
	return true;

}


/*
 first = std::cin.get();     // get one character
  std::cin.ignore(256,' ');   // ignore until space

  last = std::cin.get();      // get one character

*/
