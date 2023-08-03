#include "TXTest.h"
#include "TQ2.h"

struct TTestQ2 : crx::TDebug::TXTest {
	AUTOTEST_BODY(TTestQ2) {
		Assert(IsCommon(2.3, 3.3, 1.1)==true, "SAME TYPES"/*test msg*/);
		Assert(IsCommon("2.3", 3.3, 1.1)==false, "Dfferent types"/*test msg*/);
		Assert(IsCommon(2, 3.3, "1.1")==false, "Dfferent types"/*test msg*/);
		Assert(IsCommon(2.3f, 3.3, 1.1)==false, "Dfferent types"/*test msg*/);
	}
};