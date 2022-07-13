// CDeleteDlg.cpp: 实现文件
//

#include "pch.h"
#include "PerManSystem.h"
#include "CDeleteDlg.h"
#include "CConnectDlg.h"


// CDeleteDlg

IMPLEMENT_DYNCREATE(CDeleteDlg, CFormView)

CDeleteDlg::CDeleteDlg()
	: CFormView(IDD_DELETE)
	, d_id()
{

}

CDeleteDlg::~CDeleteDlg()
{
}

void CDeleteDlg::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, d_id);
}

BEGIN_MESSAGE_MAP(CDeleteDlg, CFormView)
	ON_BN_CLICKED(IDC_BUTTON2, &CDeleteDlg::OnBnClickedButton2)
    ON_BN_CLICKED(IDC_BUTTON1, &CDeleteDlg::OnBnClickedButton1)
END_MESSAGE_MAP()


// CDeleteDlg 诊断

#ifdef _DEBUG
void CDeleteDlg::AssertValid() const
{
	CFormView::AssertValid();
}

#ifndef _WIN32_WCE
void CDeleteDlg::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif
#endif //_DEBUG


// CDeleteDlg 消息处理程序


void CDeleteDlg::OnBnClickedButton2()
{
	// TODO: 在此添加控件通知处理程序代码
	exit(0);
}


void CDeleteDlg::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	char select[1000];
	char delete1[1000];
	sprintf_s(select, "select e_id from empolyee where e_id = \"%d\"", d_id);
	sprintf_s(delete1, "delete from empolyee where e_id = \'%d\'", d_id);
	mysql_query(&m_sqlCon, select);
	res = mysql_store_result(&m_sqlCon);
	if (mysql_fetch_row(res) != 0)
	{
		if (mysql_query(&m_sqlCon, delete1))
		{
			MessageBox(_T("删除失败，请重试!"));
		}
		else MessageBox(_T("删除成功!"));

	}
	else MessageBox(_T("该用户不存在，删除失败!"));
	
}
