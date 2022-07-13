// CAddInfo.cpp: 实现文件
//

#include "pch.h"
#include "PerManSystem.h"
#include "CAddInfo.h"
#include "CConnectDlg.h"


// CAddInfo

IMPLEMENT_DYNCREATE(CAddInfo, CFormView)

CAddInfo::CAddInfo()
	: CFormView(IDD_ADDINFO)
	, e_id()
	, e_name(_T(""))
	, e_gander(_T(""))
	, e_age()
	, e_job(_T(""))
{

}

CAddInfo::~CAddInfo()
{
}

void CAddInfo::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, e_id);
	DDX_Text(pDX, IDC_EDIT2, e_name);
	DDX_CBString(pDX, IDC_COMBO2, e_gander);
	DDX_Text(pDX, IDC_EDIT3, e_age);
	DDX_CBString(pDX, IDC_COMBO3, e_job);
	DDX_Control(pDX, IDC_COMBO2, e_cbx);
	DDX_Control(pDX, IDC_COMBO3, e_cbx2);
}

BEGIN_MESSAGE_MAP(CAddInfo, CFormView)
	ON_BN_CLICKED(IDC_BUTTON2, &CAddInfo::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON1, &CAddInfo::OnBnClickedButton1)
END_MESSAGE_MAP()


// CAddInfo 诊断

#ifdef _DEBUG
void CAddInfo::AssertValid() const
{
	CFormView::AssertValid();
}

#ifndef _WIN32_WCE
void CAddInfo::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif
#endif //_DEBUG


// CAddInfo 消息处理程序


void CAddInfo::OnBnClickedButton2()
{
	// TODO: 在此添加控件通知处理程序代码
	exit(0);
}


void CAddInfo::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码

	UpdateData(TRUE);
	mysql_set_character_set(&m_sqlCon, "gb2312"); //设置字节符，防止中文乱码.
	CString str1,str2;
	e_cbx.GetWindowText(str1);
	e_cbx2.GetWindowText(str2);
	char* name = (char*)e_name.GetBuffer();
	char* gander = (char*)str1.GetBuffer();
	char* job = (char*)str2.GetBuffer();

	char insert[1000];
	char select[1000];
	//mysql_set_character_set(&m_sqlCon, "gb2312"); //设置字节符，防止中文乱码.
	sprintf_s(insert, "insert into empolyee values (\'%d\', \"%s\", \"%s\", \'%d\', \"%s\")",e_id, name, gander, e_age, job);
	sprintf_s(select, "select e_id from empolyee where e_id = \"%d\"", e_id);
	mysql_query(&m_sqlCon, select);
	res = mysql_store_result(&m_sqlCon);
	if (mysql_query(&m_sqlCon, insert) == 0)
	{
		MessageBox(_T("添加成功!"));
	}
	else if (mysql_fetch_row(res) != 0)
	{
		MessageBox(_T("员工编号已存在，添加失败!"));
	}
}


void CAddInfo::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();

	// TODO: 在此添加专用代码和/或调用基类
	e_cbx.AddString(TEXT("男"));
	e_cbx.AddString(TEXT("女"));
	e_cbx2.AddString(TEXT("程序员"));
	e_cbx2.AddString(TEXT("销售"));
	e_cbx2.AddString(TEXT("产品经理"));
	e_cbx2.AddString(TEXT("大数据高级工程师"));
	e_cbx2.AddString(TEXT("项目经理"));

	e_cbx.SetCurSel(0);
	e_cbx2.SetCurSel(0);
}
