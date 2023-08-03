#include <iostream>

#include "TSaveInfo.h"
 
TSaveInfo::TSaveInfo(int dd,int mm,int yyyy) : m_iDay(dd), m_iMonth(mm), m_iYear(yyyy) {

	if(m_iDay<10) m_sDate += "0";
	m_sDate += std::to_string(m_iDay);
	m_sDate += ":";

	if(m_iMonth<10) m_sDate += "0";
	m_sDate += std::to_string(m_iMonth);
	m_sDate += ":";

	m_sDate += std::to_string(m_iYear);
}

std::string TSaveInfo::Date() { return m_sDate; }
int TSaveInfo::Day() { return m_iDay; }
int TSaveInfo::Month() { return m_iMonth; }
int TSaveInfo::Year() {	return m_iYear; }