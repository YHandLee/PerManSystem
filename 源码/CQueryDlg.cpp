// CQueryDlg.cpp: 实现文件
//

#include "pch.h"
#include "PerManSystem.h"
#include "CQueryDlg.h"
#include "CConnectDlg.h"


// CQueryDlg

IMPLEMENT_DYNCREATE(CQueryDlg, CFormView)

CQueryDlg::CQueryDlg()
	: CFormView(IDD_QUERYINFO)
{

}

CQueryDlg::~CQueryDlg()
{
}

void CQueryDlg::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, p_list);
}

BEGIN_MESSAGE_MAP(CQueryDlg, CFormView)
	ON_BN_CLICKED(IDC_BUTTON1, &CQueryDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CQueryDlg::OnBnClickedButton2)
END_MESSAGE_MAP()


// CQueryDlg 诊断

#ifdef _DEBUG
void CQueryDlg::AssertValid() const
{
	CFormView::AssertValid();
}

#ifndef _WIN32_WCE
void CQueryDlg::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif
#endif //_DEBUG


// CQueryDlg 消息处理程序


void CQueryDlg::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	exit(0);
}


void CQueryDlg::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();

	// TODO: 在此添加专用代码和/或调用基类
	p_list.DeleteAllItems();
	CString str[] = { TEXT("编号"),TEXT("姓名"),TEXT("性别"),TEXT("年龄"),TEXT("职位") };
	for (int i = 0; i < 5; i++)
	{
		p_list.InsertColumn(i, str[i], LVCFMT_LEFT, 100);
	}
}


void CQueryDlg::OnBnClickedButton2()
{
	// TODO: 在此添加控件通知处理程序代码
	
	p_list.DeleteAllItems();//清空列表
	CString str;
	char select[1000];
	int i;
	sprintf_s(select, "select * from empolyee order by e_id desc;");
	mysql_query(&m_sqlCon, select);
	res = mysql_store_result(&m_sqlCon);
	
	//如果为空则返回
    if (NULL == res)
	{
		return;
	}
	while (row = mysql_fetch_row(res))
	{
		i = 0;
		p_list.InsertItem(i,row[0]);
		for (int j = 1; j < 5; j++)
		{
			p_list.SetItemText(i, j, row[j]);
		}
		i++;

	}
	p_list.SetExtendedStyle(p_list.GetExtendedStyle() | LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);

}
