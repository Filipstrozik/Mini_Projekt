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

private:
	std::vector<CClause*> vec_clausesProblem;
};

