#pragma once
#include"CInfo.h"
class CDdataInterface
{
public:
	bool Open(CString FilePath);
	void Add(CInfo Info);
	void Del(int index);
	void Amend(int index,CInfo Info);
	CInfo Find(int id);
	void Save();

	vector<CInfo> Info;
};

