#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <numeric>
#include <array>
#include <memory>
#include <map>
#include "Header.h"

std::string TCommon::ToString() {

	std::cout << "Name class\t- TCommon \n Methods\t- ToString()\n size\t\t- " << sizeof(TCommon) << "\n\n";

	return "TCommon\n\n";
}

std::string TBase::ToString() {

	std::cout << "Name class\t- TBase \n Methods\t- ToString()\n size\t\t- " << sizeof(TBase) << "\n\n";

	return "TBase\n\n";
}

std::string TDerived::ToString() { 

	std::cout << "Name class\t- TDerrived \n Methods\t- ToString()\n size\t\t- " << sizeof(TDerived) << "\n\n";

	return "TBase\n\n";

}

std::string TDistributionGenerator::ToString() {
	std::cout << "Name class\t- TDistributionGenerator \n Methods\t- ToString(), GetRandomNumberWithSetRange(), GetRandomNumberFromZeroToOne()\n size\t\t- " << sizeof(TDistributionGenerator) << "\n\n";

	return "TBase\n\n";
}


float TDistributionGenerator::GetRandomNumberFromZeroToOne() {

	srand( unsigned(time(nullptr)) );
	auto number = static_cast<float>(std::rand()) / static_cast<float>(RAND_MAX);
	vec.push_back(number);

	return number;
}

std::vector<float> TDistributionGenerator::GetRandomNumberWithSetRange(float InputValue) {

	while(true) {

		srand( unsigned(time(nullptr)) );
		auto value = static_cast<float>(std::rand()) / static_cast<float>(RAND_MAX);
		auto sum = std::accumulate(vec.begin(),vec.end(),value);

		if(sum >= 1) return vec;

		vec.push_back(value);
	}
	return vec;
}

std::string TParent::ToString() {
	std::cout << "Name class\t- TParent \n Methods\t- ToString(), Name()\n size\t\t- " << sizeof(TParent) << "\n\n";

	return "TBase\n\n";
}


std::string TDerived1::ToString() {
	std::cout << "Name class\t-" << Name() << "\n Methods\t - ToString(),Name()\n size\t\t - " << sizeof(TDerived1) << "\n\n";

	return "TBase\n\n";
}


std::string TDerived2::ToString() {
	std::cout << "Name class\t- TDerived2 \n Methods\t- ToString(), Name()\n size\t\t- " << sizeof(TDerived2) << "\n\n";

	return "TBase\n\n";
}

std::string TDerived3::ToString() {
	std::cout << "Name class\t- TDerived3 \n Methods\t- ToString(), Name()\n size\t\t- " << sizeof(TDerived3) << "\n\n";

	return "TBase\n\n";
}



int main() {

	//first task

	auto ptrB = std::make_shared<TDerived>(); 
	auto ptrA = std::make_shared<TBase>();

	ptrA = ptrB;
	auto ptrC = ptrB;
	ptrB = nullptr;

	//second task

	TDistributionGenerator obj;
	obj.GetRandomNumberWithSetRange(obj.GetRandomNumberFromZeroToOne());

	//third task

	std::map<std::string,std::unique_ptr<TParent>> objects; 

	objects["Object1"] = std::make_unique<TDerived1>(); 
	objects["Object2"] = std::make_unique<TDerived2>(); 
	objects["Object3"] = std::make_unique<TDerived3>();
	objects["Object4"] = std::make_unique<TDerived3>();
	objects["Object5"] = std::make_unique<TDerived2>();
	objects["Object6"] = std::make_unique<TDerived1>();
	objects["Object7"] = std::make_unique<TDerived1>();

	//For 4-th tasks
 
	auto ptr1 = std::make_shared<TBase>();
	auto ptr2 = std::make_shared<TDerived>();
	auto ptr3 = std::make_shared<TDistributionGenerator>();
	auto ptr4 = std::make_shared<TDerived3>();
	auto ptr5 = std::make_shared<TDerived2>();
	auto ptr6 = std::make_shared<TDerived1>();
	auto ptr7 = std::make_shared<TDerived3>();
	auto ptr8 = std::make_shared<TDerived2>();
	auto ptr9 = std::make_shared<TDerived1>();
	auto ptr10 = std::make_shared<TDerived1>();
	
	std::array<std::shared_ptr<TCommon>,10> arr = {ptr1,ptr2,ptr3,ptr4,ptr5,ptr6,ptr7,ptr8,ptr9,ptr10}; 
	
	for(auto iter = arr.begin(); iter != arr.end(); ++iter)
		(*iter)->ToString();

	

	return 0;
}

