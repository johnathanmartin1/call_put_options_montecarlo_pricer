#ifndef ASIAN
#define ASIAN


#include"Contract.h"

class Asian : public Contract
{
public:
	void type() override {
		std::cout << "Contract type is Asian\n";
	}
	~Asian() 
	{
		std::cout << "asian option deleted\n";
	}

};





#endif
