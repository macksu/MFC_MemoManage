// ChidDlg.cpp: 实现文件
//

#include "pch.h"
#include "MemorandumSystem.h"
#include "afxdialogex.h"
#include "ChidDlg.h"


// ChidDlg 对话框

IMPLEMENT_DYNAMIC(ChidDlg, CDialogEx)

ChidDlg::ChidDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_ChildDialog, pParent)
	, m_id(_T(""))
	, m_lastname(_T(""))
	, m_date(_T(""))
	, m_content(_T(""))
	, m_firstname(_T(""))
{

}

ChidDlg::~ChidDlg()
{
}

void ChidDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_id);
	DDX_Text(pDX, IDC_EDIT2, m_lastname);
	DDX_Text(pDX, IDC_EDIT3, m_lastname);
	DDX_Text(pDX, IDC_EDIT4, m_date);
	DDX_Text(pDX, IDC_EDIT5, m_content);
	DDX_Text(pDX, IDC_EDIT2, m_firstname);
}


BEGIN_MESSAGE_MAP(ChidDlg, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &ChidDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &ChidDlg::OnBnClickedButton2)
END_MESSAGE_MAP()


// ChidDlg 消息处理程序


void ChidDlg::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	if (m_id == TEXT("") || m_firstname == TEXT("") || m_lastname == TEXT("") || m_date ==
		TEXT("") || m_content == TEXT("")) {
		MessageBox(TEXT("您输入有空，请补充完整"),TEXT("提示"));
	}
	else {
		OnOK();
		return;
	}
}


void ChidDlg::OnBnClickedButton2()
{
	// TODO: 在此添加控件通知处理程序代码
	EndDialog(0);
}
