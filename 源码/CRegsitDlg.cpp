// CRegsitDlg.cpp: 实现文件
//

#include "pch.h"
#include "PerManSystem.h"
#include "afxdialogex.h"
#include "CRegsitDlg.h"
#include "CConnectDlg.h"


// CRegsitDlg 对话框

IMPLEMENT_DYNAMIC(CRegsitDlg, CDialogEx)

CRegsitDlg::CRegsitDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_REGIST, pParent)
	, r_user(_T(""))
	, r_pwd(_T(""))
	, rr_pwd(_T(""))
{

}

CRegsitDlg::~CRegsitDlg()
{
}

void CRegsitDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, r_user);
	DDX_Text(pDX, IDC_EDIT2, r_pwd);
	DDX_Text(pDX, IDC_EDIT3, rr_pwd);
}


BEGIN_MESSAGE_MAP(CRegsitDlg, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &CRegsitDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CRegsitDlg::OnBnClickedButton2)
END_MESSAGE_MAP()


// CRegsitDlg 消息处理程序


void CRegsitDlg::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	char* x = (char*)r_user.GetBuffer();
	char* y = (char*)r_pwd.GetBuffer();

	
	if (r_user.IsEmpty() || r_pwd.IsEmpty())
	{
		MessageBox(TEXT("输入内容不能为空！"));
	}
	else if (r_pwd != rr_pwd)
	{
		MessageBox(TEXT("输入密码不同！"));
		return;
	}

	else
	{
		char insert[1000];
		char select[1000];
		sprintf_s(insert, "insert into manager values (\'%s\', \'%s\')", x, y);
		sprintf_s(select,"select m_user from manager where m_user = \"%s\"",x);
		mysql_query(&m_sqlCon, select);
		res = mysql_store_result(&m_sqlCon);
		//row = mysql_fetch_row(res);
		if (mysql_query(&m_sqlCon, insert) == 0)
		{
			MessageBox(_T("注册成功!"));
			CDialog::OnCancel();

		}
		else if ( mysql_fetch_row(res) != 0) 
		{
			
			MessageBox(_T("用户名已在，注册失败!"));

		}

	}
}


void CRegsitDlg::OnBnClickedButton2()
{
	// TODO: 在此添加控件通知处理程序代码
	CDialog::OnCancel();
}
