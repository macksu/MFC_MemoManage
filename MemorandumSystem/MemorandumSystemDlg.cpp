
// MemorandumSystemDlg.cpp: 实现文件
//

#include "pch.h"
#include "framework.h"
#include "MemorandumSystem.h"
#include "MemorandumSystemDlg.h"
#include "afxdialogex.h"

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
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMemorandumSystemDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, m_list);
}

BEGIN_MESSAGE_MAP(CMemorandumSystemDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CMemorandumSystemDlg::OnBnClickedButton1)
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
		UpdateList();
		MessageBox(TEXT("123"));
      
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
