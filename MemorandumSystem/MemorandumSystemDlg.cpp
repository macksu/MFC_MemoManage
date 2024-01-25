
// MemorandumSystemDlg.cpp: 实现文件
//

#include "pch.h"
#include "framework.h"
#include "MemorandumSystem.h"
#include "MemorandumSystemDlg.h"
#include "afxdialogex.h"

#include "ChidDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CMemorandumSystemDlg 对话框



CMemorandumSystemDlg::CMemorandumSystemDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MEMORANDUMSYSTEM_DIALOG, pParent)
	, m_find(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMemorandumSystemDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, m_list);
	DDX_Text(pDX, IDC_EDIT1, m_find);
}

BEGIN_MESSAGE_MAP(CMemorandumSystemDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CMemorandumSystemDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON4, &CMemorandumSystemDlg::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON3, &CMemorandumSystemDlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON6, &CMemorandumSystemDlg::OnBnClickedButton6)
	ON_BN_CLICKED(IDC_BUTTON5, &CMemorandumSystemDlg::OnBnClickedButton5)
	ON_BN_CLICKED(IDC_BUTTON2, &CMemorandumSystemDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON7, &CMemorandumSystemDlg::OnBnClickedButton7)
END_MESSAGE_MAP()


// CMemorandumSystemDlg 消息处理程序

BOOL CMemorandumSystemDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码
	//设置listCtrl风格
	DWORD dwStyle = m_list.GetExtendedStyle();
	dwStyle |= LVS_EX_FULLROWSELECT;	//选中某行使整行高亮（只适用与report风格的ListCtrl） 
	dwStyle |= LVS_EX_GRIDLINES;	   //网格线（只适用与report风格的ListCtrl） 
	m_list.SetExtendedStyle(dwStyle); //设置扩展风格 

	m_list.InsertColumn(0, TEXT("编号"), 0, 150);
	m_list.InsertColumn(1, TEXT("姓氏"), 0, 150);
	m_list.InsertColumn(2, TEXT("名字"), 0, 150);
	m_list.InsertColumn(3, TEXT("日期"), 0, 150);
	m_list.InsertColumn(4, TEXT("内容"), 0, 300);

	isopen = false;
	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CMemorandumSystemDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CMemorandumSystemDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CMemorandumSystemDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CMemorandumSystemDlg::OnBnClickedButton1()
{ 
	 // 设置过滤器   
	TCHAR szFilter[] = _T("文本文件(*.txt)|*.txt|所有文件(*.*)|*.*||");
	// 构造打开文件对话框   
	CFileDialog fileDlg(TRUE, _T("txt"), NULL, 0, szFilter, this);
	CString strFilePath;
	// 显示打开文件对话框   
	if (IDOK == fileDlg.DoModal())
	{
		// 如果点击了文件对话框上的“打开”按钮，则将选择的文件路径显示到编辑框里   
		strFilePath = fileDlg.GetPathName();
		dataInterface.Open(strFilePath);
		isopen = true;
		UpdateList();
      
	}

}

void CMemorandumSystemDlg::UpdateList()
{
	m_list.DeleteAllItems();  //清除所有行
	CString str;
	for (int i = 0; i < dataInterface.Info.size(); i++) {
		str.Format(TEXT("%d"), dataInterface.Info[i].m_id);
		m_list.InsertItem(i, str);
		str.Format(TEXT("%s"), dataInterface.Info[i].m_lastname);
		m_list.SetItemText(i, 1, dataInterface.Info[i].m_lastname.c_str());
		str.Format(TEXT("%s"), dataInterface.Info[i].m_firstname);
		m_list.SetItemText(i, 2, dataInterface.Info[i].m_firstname.c_str());
		str.Format(TEXT("%s"), dataInterface.Info[i].m_date);
		m_list.SetItemText(i, 3, dataInterface.Info[i].m_date.c_str());
		str.Format(TEXT("%s"), dataInterface.Info[i].m_content);
		m_list.SetItemText(i, 4, dataInterface.Info[i].m_content.c_str());
	}

}


void CMemorandumSystemDlg::OnBnClickedButton4()
{
	// TODO: 在此添加控件通知处理程序代码
	if (isopen) {
		ChidDlg childDlg;
		if (IDOK == childDlg.DoModal()) {
			CInfo Info(atoi(childDlg.m_id), childDlg.m_lastname.GetBuffer(), childDlg.m_firstname.GetBuffer(), childDlg.m_date.GetBuffer(), childDlg.m_content.GetBuffer());
			dataInterface.Add(Info);
			UpdateList();
		}
	}
	else {
		MessageBox(TEXT("请先打开文件"), TEXT("提示"));
	}
	
}


void CMemorandumSystemDlg::OnBnClickedButton3()
{
	// TODO: 在此添加控件通知处理程序代码
    int index = m_list.GetSelectionMark();

	if (index > -1) {
		UINT i;
		i = MessageBox(_T("确定删除这条记录吗？"), _T("提示"), MB_YESNO | MB_ICONQUESTION);
		if (i == IDYES) {
			dataInterface.Del(index);
			MessageBox(TEXT("删除成功"), TEXT("提示"));
			UpdateList();
		}
		else {
			return;
		}
	
	}
	else {
		MessageBox(TEXT("请先点击列表选择需要删除的记录"), TEXT("提示"));
	}
}


void CMemorandumSystemDlg::OnBnClickedButton6()
{
	// TODO: 在此添加控件通知处理程序代码
	int index = m_list.GetSelectionMark();
	if (index > -1) {
		ChidDlg childDlg;
		CString str;
		str.Format(TEXT("%d"), dataInterface.Info[index].m_id);
		childDlg.m_id = str;
		str.Format(TEXT("%s"), dataInterface.Info[index].m_lastname.c_str());
		childDlg.m_lastname = str;
		str.Format(TEXT("%s"), dataInterface.Info[index].m_firstname.c_str());
		childDlg.m_firstname = str;
		str.Format(TEXT("%s"), dataInterface.Info[index].m_date.c_str());
		childDlg.m_date = str;
		str.Format(TEXT("%s"), dataInterface.Info[index].m_content.c_str());
		childDlg.m_content = str;
		if (IDOK == childDlg.DoModal()) {
			CInfo Info(atoi(childDlg.m_id), childDlg.m_lastname.GetBuffer(), childDlg.m_firstname.GetBuffer(), childDlg.m_date.GetBuffer(), childDlg.m_content.GetBuffer());
			dataInterface.Amend(index,Info);
			UpdateList();
		}


	}
	else {
		MessageBox(TEXT("请先点击列表选择需要修改的记录"), TEXT("提示"));
	}
}


void CMemorandumSystemDlg::OnBnClickedButton5()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	CInfo FindInfo=dataInterface.Find(atoi(m_find));
	if (FindInfo.m_id == -1) {
		MessageBox(TEXT("查无记录"), TEXT("提示"));

	}
	else {
		CString str;
		str.Format(TEXT("查找成功！\n\n编号:%d\n姓氏:%s\n名字:%s\n时间:%s\n事务内容:%s"),
			FindInfo.m_id, FindInfo.m_lastname.c_str(), FindInfo.m_firstname.c_str(), FindInfo.m_date.c_str(), FindInfo.m_content.c_str());
		MessageBox(str, TEXT("提示"));

	}

}


void CMemorandumSystemDlg::OnBnClickedButton2()
{
	// TODO: 在此添加控件通知处理程序代码
	if (isopen) {
		if (dataInterface.Save(strFilePath)) MessageBox(TEXT("保存成功"), TEXT("提示"));
		else MessageBox(TEXT("保存失败"), TEXT("提示"));
	}
	else {
		MessageBox(TEXT("请先打开文件"), TEXT("提示"));
	}
	
}


void CMemorandumSystemDlg::OnBnClickedButton7()
{
	// TODO: 在此添加控件通知处理程序代码
	UINT i;
	i = MessageBox(_T("确定要退出吗？"), _T("提示"), MB_YESNO | MB_ICONQUESTION);
	if (i == IDYES) {
		exit(0);
	}
	else {
		return;
	}
}
