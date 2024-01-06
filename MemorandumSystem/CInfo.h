#pragma once

#include <string>
class CInfo
{
public:
	CInfo();
	CInfo(int m_id, string m_lastname, string m_firstname, string m_date, string m_content);


	int m_id;
	string m_lastname;
	string m_firstname;
	string m_date;
	string m_content;
};

