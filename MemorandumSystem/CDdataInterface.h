#pragma once
#include"CInfo.h"
class CDdataInterface
{
public:
	bool Open(CString FilePath);
	void Add(CInfo MyInfo);
	void Del(int index);
	void Amend(int index,CInfo MyInfo);
	CInfo Find(int id);
	bool Save();

	vector<CInfo> Info;
};

