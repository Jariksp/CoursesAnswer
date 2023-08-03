// Task:
// Add IsCommon template function overload, which return false, and take difference types.
// Uncomment Assert lines in TTestQ2 after finish.

#include <typeinfo>
#ifndef TQ2_H_
#define TQ2_H_

//template <typename T>
//bool IsCommon(T a, T b, T c) {
//	return true;
//}


template <typename T1,typename T2,typename T3>
bool IsCommon(T1 a,T2 b,T3 c) {
	return typeid(a).name()==typeid(b).name() && typeid(b).name()==typeid(c).name(); 
}

#endif // TQ2_H_