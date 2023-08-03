#include "TXTest.h"
#include "TQ1.h"

struct TTestQ1 : crx::TDebug::TXTest {	
	TQ1 p;

	AUTOTEST_BODY(TTestQ1) {
		auto bb=false;
		
		using namespace NNOwnerType;
		{
			bb=p.CompareOwners({{Human,11},{AI,1},{Human,31},{AI,-21},{Human,-11},{AI,-13},{Human,-23}}) == true;
			Assert(bb,"Negative are equal");

			bb=p.CompareOwners({{Human,0},{AI,0},{Human,0},{AI,-0},{Human,-0},{AI,-0},{Human,-0}}) == false;
			Assert(bb,"Zero");

			bb=p.CompareOwners({{Human,1},{AI,1},{Human,1},{AI,-1},{Human,-1},{AI,-1},{Human,-1}}) == true;
			Assert(bb,"All are equal");

			bb=p.CompareOwners({{Human,3},{AI,333},{Human,333},{AI,-3},{Human,-3},{AI,-33},{Human,-3}}) == true;
			Assert(bb,"Divides to 3");

			bb=p.CompareOwners({{Human,45},{AI,54},{Human,40},{AI,-45},{Human,-555},{AI,-5},{Human,-222}}) == false;
			Assert(bb,"Random");
		}
	}
};