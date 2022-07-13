// CDloginDlg.cpp: 实现文件
//

#include "pch.h"
#include "PerManSystem.h"
#include "afxdialogex.h"
#include "CDloginDlg.h"
#include "CConnectDlg.h"
#include "CRegsitDlg.h"


// CDloginDlg 对话框

IMPLEMENT_DYNAMIC(CDloginDlg, CDialogEx)


CDloginDlg::CDloginDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_LoginDlg, pParent)
	, p_user(_T(""))
	, p_password(_T(""))
{

}

CDloginDlg::~CDloginDlg()
{
}

void CDloginDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, p_user);
	DDX_Text(pDX, IDC_EDIT2, p_password);
}


BEGIN_MESSAGE_MAP(CDloginDlg, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &CDloginDlg::OnBnClickedButton1)
	ON_WM_CLOSE()
	ON_BN_CLICKED(IDC_BUTTON3, &CDloginDlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON2, &CDloginDlg::OnBnClickedButton2)
END_MESSAGE_MAP()


// CDloginDlg 消息处理程序


void CDloginDlg::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);

	char* x = (char*)p_user.GetBuffer();
	char select[1000];
	sprintf_s(select, "select m_user from manager where m_user = \"%s\"", x);
	mysql_query(&m_sqlCon, select);
	res = mysql_store_result(&m_sqlCon);
	if (p_user.IsEmpty() || p_password.IsEmpty())
	{
		MessageBox(TEXT("输入内容不能为空！"));
		return;
	}
	else if (mysql_fetch_row(res) == 0)
	{
		MessageBox(TEXT("该用户不存在！"));
	}
	else
	{
		CDialog::OnCancel();
	}

}


void CDloginDlg::OnClose()
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值

	//CDialogEx::OnClose();
	exit(0);
}


void CDloginDlg::OnOK()
{
	// TODO: 在此添加专用代码和/或调用基类

	//CDialogEx::OnOK();
}


void CDloginDlg::OnBnClickedButton3()
{
	// TODO: 在此添加控件通知处理程序代码
	exit(0);
}


void CDloginDlg::OnBnClickedButton2()
{
	// TODO: 在此添加控件通知处理程序代码
	CRegsitDlg dlg;
	dlg.DoModal();
}
