#pragma once
#include "afxdialogex.h"


// ChidDlg 对话框

class ChidDlg : public CDialogEx
{
	DECLARE_DYNAMIC(ChidDlg)

public:
	ChidDlg(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~ChidDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ChildDialog };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CString m_id;
	CString m_firstname;
	CString m_lastname;
	CString m_date;
	CString m_content;
	afx_msg void OnBnClickedButton1();

};
