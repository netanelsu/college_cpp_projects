#include "manager.h"

float manager::Salary()
{
	return 4500 * 3.0 + Seniority * 500;
}

bool manager::OutStanding()
{
	if (Seniority > 4) {
		return true;
	}
	else {
		return false;
	}
}

