#include "CMax3SatProblem.h"
#include <fstream>
#include <iostream>

CMax3SatProblem::CMax3SatProblem() {
	cout << "CMax3SatProblem()" << endl;
	vec_clausesProblem.reserve(1000);
	i_numberOfClauses = 0;
	i_numberOfVar = 0;
}

CMax3SatProblem::~CMax3SatProblem(){
	for (int i = 0; i < (int) vec_clausesProblem.size(); i++) {
		if (vec_clausesProblem.at(i) != NULL) {
			delete vec_clausesProblem.at(i);
		}
	}
	vec_clausesProblem.clear();
}

bool CMax3SatProblem::bLoad(string sPath) {
	ifstream file;
	file.open(sPath, ios::in);
	
	if (!file) {
		cout << "blad przy otwiernaiu pliku" << endl;
		return false;
	}
	int min = 1000;
	int max = 0;
	int s1 = 0;
	bool f1 = false;
	int s2 = 0;
	bool f2 = false;
	int s3 = 0;
	bool f3 = false;
	int s4 = 0;
	bool f4 = false;
	char sign;
	if (file.is_open()) {

		while (!file.eof()) {
			f1 = false;
			f2 = false;
			f3 = false;
			file.ignore(100, ' ');
			sign = file.peek();
			if (sign == '-') {
				f1 = true;
				file.ignore();
			}
			file >> s1;
			if (max < abs(s1)) max = s1;
			file.ignore(2);
			sign = file.peek();
			if (sign == '-') {
				f2 = true;
				file.ignore();
			}
			file >> s2;
			if (max < abs(s2)) max = s2;
			file.ignore(2);
			sign = file.peek();
			if (sign == '-') {
				f3 = true;
				file.ignore();
			}
			file >> s3;
			if (max < abs(s3)) max = s3;
			file.ignore(2);
			sign = file.peek();
			if (sign == '-') {
				f4 = true;
				file.ignore();
			}
			file >> s4;
			if (max < abs(s4)) max = s4;

			file.ignore(100, '\n');
			vec_clausesProblem.push_back(new CClause(f1,s1,f2,s2,f3,s3,f4,s4));
			i_numberOfClauses++;
			
		}
		i_numberOfVar = max;
		file.close();
	}
	return true;

}

double CMax3SatProblem::dCompute(vector<bool>* vecSolution) {
	double counterGoodClauses = 0.0;
	for (int i = 0; i < (int) vec_clausesProblem.size(); i++) {
		if (vec_clausesProblem.at(i)->bCompute(vecSolution) ){
			counterGoodClauses += 1.0;
		}
	}
	//cout << "nr GOODclauses : " << counterGoodClauses << " nr clauses: " << i_numberOfClauses << "fitness: "<< (double)(counterGoodClauses / i_numberOfClauses) <<endl;
	return (double)(counterGoodClauses / i_numberOfClauses);
}

int CMax3SatProblem::iGetNumberOfVar()
{
	return i_numberOfVar;
}

