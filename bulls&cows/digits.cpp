#include "digits.h"

digit::digit()
{
	value = 0;
}

void digit::SetValue(int dig)
{
	value = dig;
}

int digit::GetValue()
{
	return value;
}

bool digit::Compare(const int& dig)const
{
	if (value == dig) {
		return true;
	}
	else {
		return false;
	}
}
