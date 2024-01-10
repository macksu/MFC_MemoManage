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
	for (int i = 0; i < Info.size(); i++) {
		if (Info[i].m_id == id); return Info[i];
	}
	return CInfo(-1, TEXT(""), TEXT(""), TEXT(""), TEXT(""));
}

bool CDdataInterface::Save(CString FilePath)
{
	ofstream out(FilePath, ios::out);
	if (out.is_open()) {
		out << Info.size() << endl;
		for (int i = 0; i < Info.size(); i++) {
			Info[i].Save(out);
		}
		out.close();
		return true;
	}
	
	return false;
}
