#pragma once

#include <vector>
#include <string>
#include "CClause.h"

class CMax3SatProblem
{
public:
	CMax3SatProblem();
	bool bLoad(std::string path);
	double dCompute(std::vector<bool> vecSolution);
	int iGetNumberOfVar();

private:
	int i_numberOfVar;
	std::vector<CClause*> vec_clausesProblem;
	int i_numberOfClauses;
};

