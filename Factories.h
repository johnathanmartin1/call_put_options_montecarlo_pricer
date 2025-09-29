#ifndef FACTORY
#define FACTORY

#include "Contract.h"
#include "Asian.h"
#include "European.h"

std::unique_ptr<Contract> createcontract(const std::string& contracttype)
{
	if (contracttype == "Asian")
	{
		return std::make_unique<Asian>();
	}
	else if (contracttype == "European")
	{
		return std::make_unique<European>();
	}
	return nullptr;
}






#endif
