#include "TQ1.h"


void TQ1::NegativeCalculations(){
	
	m_neg0=0; 
	m_neg1=0;  
	for(auto number:m_vHumanNumbers) if(number <= 0) m_neg0=m_neg0 + number;
	for(auto number:m_vAINumbers) if(number <= 0) m_neg1=m_neg1 + number;

}


bool TQ1::CheckNull() { 

	if(m_pos0==0 && m_pos1==0) return false;							//Comparing to 0;
	else if(m_neg0==0 && m_neg1==0) return false;

}

bool TQ1::CheckResult() {

	if(m_pos0==m_pos1) return true;				//Comparing to similarity 			
	if(m_neg0==m_neg1) return true;
	if(abs(m_neg0 + m_neg1 + m_pos0 + m_pos1) % 3==0) return true;	// Comparing to division

	return false;
}


bool TQ1::Check() {
	return ( CheckNull() && CheckResult() );
}

void TQ1::PositiveCalculations() {

	m_pos0=0;
	m_pos1=0;

	for(auto number:m_vHumanNumbers) if(number > 0) m_pos0=m_pos0 + number;
	for(auto number:m_vAINumbers)	if(number > 0) m_pos1=m_pos1 + number;

}


bool TQ1::CompareOwners(std::vector<std::pair<NOwnerType,int>> input) {
	m_vInput=input;

	m_vHumanNumbers.clear();
	m_vAINumbers.clear();

	for(auto& [owner,value]:m_vInput) {
		if(owner==NOwnerType::Human) { m_vHumanNumbers.push_back(value); }
		if(owner==NOwnerType::AI) { m_vAINumbers.push_back(value); }
	}

	NegativeCalculations();
	PositiveCalculations();
	return Check();
}