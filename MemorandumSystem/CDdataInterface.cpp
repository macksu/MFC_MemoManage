#include "pch.h"
#include "CDdataInterface.h"

bool CDdataInterface::Open(CString FilePath)
{
	ifstream in(FilePath,ios::in);
	if (in.is_open()) {
		int num;
		in >> num;
		for (int i = 0; i < num; i++) {
			CInfo MyInfo;
			MyInfo.Load(in);
			Info.push_back(MyInfo);
		}
		return true;

	}
	return false;
}

void CDdataInterface::Add(CInfo MyInfo)
{
	Info.push_back(MyInfo);
}

void CDdataInterface::Del(int index)
{
	Info.erase(Info.begin() + index);
}

void CDdataInterface::Amend(int index, CInfo MyInfo)
{
	Info[index] = MyInfo;
}

CInfo CDdataInterface::Find(int id)
{
	return CInfo();
}
