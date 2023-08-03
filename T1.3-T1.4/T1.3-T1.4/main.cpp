#include "TXTest.h"
#include <iostream>
#include <typeinfo>

int main() {

	RUN_ALLAUTOTESTS(); 
	crx::TDebug::TXTest::ShowStats();

	return 0;
}
