#ifndef TSAVE_INFO_H
#define TSAVE_INFO_H

#include <string>

class TSaveInfo {
	public:
	TSaveInfo(int dd, int mm, int yyyy);
	~TSaveInfo()=default;
	
	public:
	std::string Date();

	public:
	int Day();
	int Month();
	int Year();

	protected:  
	int m_iDay;
	int m_iMonth; 
	int m_iYear; 

	protected:
	char* m_pData = nullptr;
	std::string m_sDate; 
};

#endif // TSAVE_INFO_H


