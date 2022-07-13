// CConnectDlg.cpp: 实现文件
//

#include "pch.h"
#include "PerManSystem.h"
#include "afxdialogex.h"
#include "CConnectDlg.h"

MYSQL m_sqlCon;  //声明数据库对象
MYSQL_RES* res;	//保存读取到的结果，存入MYSQL_RES结构体中
MYSQL_ROW row;	//读取上述结果时，将每行的数据存入该字符串中

// CConnectDlg 对话框

IMPLEMENT_DYNAMIC(CConnectDlg, CDialogEx)

CConnectDlg::CConnectDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_CONNECT, pParent)
	, d_address(_T("localhost"))
	, d_user(_T("root"))
	, d_password(_T("111111"))
	, d_port(3306)
	, d_name(_T("perman"))
{

}

CConnectDlg::~CConnectDlg()
{
}

void CConnectDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, d_address);
	DDX_Text(pDX, IDC_EDIT2, d_user);
	DDX_Text(pDX, IDC_EDIT3, d_password);
	DDX_Text(pDX, IDC_EDIT4, d_port);
	DDX_Text(pDX, IDC_EDIT5, d_name);
}


BEGIN_MESSAGE_MAP(CConnectDlg, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON2, &CConnectDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON1, &CConnectDlg::OnBnClickedButton1)
	ON_WM_CLOSE()
END_MESSAGE_MAP()


// CConnectDlg 消息处理程序



void CConnectDlg::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	char * addr = (char*)d_address.GetBuffer();
	char * user = (char*)d_user.GetBuffer();
	char * pwd = (char*)d_password.GetBuffer();
	char * dname = (char*)d_name.GetBuffer();
	mysql_init(&m_sqlCon);//初始化数据库对象
	mysql_set_character_set(&m_sqlCon, "gb2312"); //设置字节符，防止中文乱码. 
	if (mysql_real_connect(&m_sqlCon, addr, user, pwd, dname, d_port, NULL, 0)) {

		MessageBox(TEXT("连接成功"));
		CDloginDlg dlg;
	    dlg.DoModal();
		CDialog::OnCancel();

	}
	else
	{
		MessageBox(TEXT("连接失败"));
	}

}


void CConnectDlg::OnBnClickedButton2()
{
	// TODO: 在此添加控件通知处理程序代码
	exit(0);
}


void CConnectDlg::OnOK()
{
	// TODO: 在此添加专用代码和/或调用基类

	//CDialogEx::OnOK();
}




void CConnectDlg::OnClose()
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值

	//CDialogEx::OnClose();
	exit(0);
}
