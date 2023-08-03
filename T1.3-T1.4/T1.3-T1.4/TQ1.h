// Program takes pair vector of owner and some value,
// break by two different arrays, 
// calculating sum of all positive and sum of all negative values,
// and then compare results with following rules:
// - return true if sum of positive or sum of negative different owners is equal;
// - return false if sum of positive and sum of negative is equal or zero; 
// - return true if sum of positive and negative numbers dividing by 3 without fix point part.

// Task:
// You should simplify code bellow by DRY, KISS and SOLID.

#ifndef TQ1_H_
#define TQ1_H_

#include <vector>
#include "NOwnerType.h"


using NOwnerType = NNOwnerType::NOwnerType;

class TQ1 {
	public:
	void NegativeCalculations();
	void PositiveCalculations();

	public:
	bool CheckNull();
	bool CheckResult();

	public:
	bool Check();
	bool CompareOwners(std::vector<std::pair<NOwnerType,int>> input);

	protected:
	std::vector<std::pair<NOwnerType, int>> m_vInput;

	protected:
	std::vector<int> m_vHumanNumbers;
	std::vector<int> m_vAINumbers;

	protected:
	int m_pos0 = 0;
	int m_neg0 = 0;

	protected:
	int m_pos1 = 0;
	int m_neg1 = 0;
};

#endif // TQ1_H_
