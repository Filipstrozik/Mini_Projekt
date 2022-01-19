#pragma once

#include <vector>
#include <string>
#include "CClause.h"

class CMax3SatProblem
{
public:
	CMax3SatProblem();
	~CMax3SatProblem();

	//crucial functions
	bool bLoad(string path);
	double dCompute(vector<bool>* vecSolution);

	//getters
	int iGetNumberOfVar();

private:
	int i_numberOfVar;
	vector<CClause*> vec_clausesProblem;
	int i_numberOfClauses;
};

