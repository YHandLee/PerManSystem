// CAlterDlg.cpp: 实现文件
//

#include "pch.h"
#include "PerManSystem.h"
#include "CAlterDlg.h"
#include "CConnectDlg.h"

// CAlterDlg

IMPLEMENT_DYNCREATE(CAlterDlg, CFormView)

CAlterDlg::CAlterDlg()
	: CFormView(IDD_ALTER)
	, a_id(0)
	, qa_id(0)
	, qa_name(_T(""))
	, qa_gander(_T(""))
	, qa_age(0)
	, qa_job(_T(""))
{

}

CAlterDlg::~CAlterDlg()
{
}

void CAlterDlg::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT6, a_id);
	DDX_Text(pDX, IDC_EDIT1, qa_id);
	DDX_Text(pDX, IDC_EDIT2, qa_name);
	DDX_CBString(pDX, IDC_COMBO1, qa_gander);
	DDX_Text(pDX, IDC_EDIT4, qa_age);
	DDX_CBString(pDX, IDC_COMBO2, qa_job);
	DDX_Control(pDX, IDC_COMBO1, a_cbxg);
	DDX_Control(pDX, IDC_COMBO2, a_cbxj);
}

BEGIN_MESSAGE_MAP(CAlterDlg, CFormView)
//	ON_BN_CLICKED(IDC_BUTTON2, &CAlterDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON1, &CAlterDlg::OnBnClickedButton1)
	ON_BN_DOUBLECLICKED(IDC_BUTTON1, &CAlterDlg::OnBnDoubleclickedButton1)
//	ON_WM_LBUTTONDOWN()
ON_BN_CLICKED(IDC_BUTTON2, &CAlterDlg::OnBnClickedButton2)
END_MESSAGE_MAP()


// CAlterDlg 诊断

#ifdef _DEBUG
void CAlterDlg::AssertValid() const
{
	CFormView::AssertValid();
}

#ifndef _WIN32_WCE
void CAlterDlg::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif
#endif //_DEBUG


// CAlterDlg 消息处理程序


void CAlterDlg::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();

	// TODO: 在此添加专用代码和/或调用基类
	a_cbxg.AddString(TEXT("男"));
	a_cbxg.AddString(TEXT("女"));
	a_cbxj.AddString(TEXT("前端程序员"));
	a_cbxj.AddString(TEXT("后端程序员"));
	a_cbxj.AddString(TEXT("销售"));
	a_cbxj.AddString(TEXT("产品经理"));
	a_cbxj.AddString(TEXT("大数据高级工程师"));
	a_cbxj.AddString(TEXT("项目经理"));
	a_cbxj.AddString(TEXT("测试"));
	a_cbxj.AddString(TEXT("总经理"));
	a_cbxj.AddString(TEXT("后端工程师"));
	a_cbxj.AddString(TEXT("程序员"));

	a_cbxg.SetCurSel(0);
	a_cbxj.SetCurSel(0);
}



void CAlterDlg::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	MessageBox(TEXT("双击修改！"));

}


void CAlterDlg::OnBnDoubleclickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);

	CString str1, str2;
	a_cbxg.GetWindowText(str1);
	a_cbxj.GetWindowText(str2);
	char* name = (char*)qa_name.GetBuffer();
	char* gander = (char*)str1.GetBuffer();
	char* job = (char*)str2.GetBuffer();
	char delete1[1000];
	char insert[1000];
	char select[1000];
	sprintf_s(select, "select e_id from empolyee where e_id = \'%d\'", a_id);
	sprintf_s(delete1, "delete from empolyee where e_id = \'%d\'", a_id);
	sprintf_s(insert, "insert into empolyee values (\'%d\', \"%s\", \"%s\", \'%d\', \"%s\")", qa_id, name, gander, qa_age, job);
	mysql_query(&m_sqlCon, select);
	res = mysql_store_result(&m_sqlCon);
	if (qa_id = a_id)
	{
		mysql_query(&m_sqlCon, delete1);
		mysql_query(&m_sqlCon, insert);
		MessageBox(_T("修改成功!"));
	}
	else if (mysql_fetch_row(res) != 0)
	{
		MessageBox(_T("员工编号已存在，修改失败!"));
	}
	else 
	{
		mysql_query(&m_sqlCon, delete1);
		mysql_query(&m_sqlCon, insert);
		MessageBox(_T("修改成功!"));
	}
}


BOOL CAlterDlg::PreTranslateMessage(MSG* pMsg)
{
	// TODO:  在此添加专用代码和/或调用基类
	if (pMsg->message == WM_LBUTTONUP)//mfc的按钮不知道为什么不能响应双击响应。如果需要响应双击，要根据WM_LBUTTONUP来判断
	{
		MSG message;
		DWORD st = GetTickCount();//记录下鼠标弹起时的时间
		while (1)
		{
			if (::PeekMessage(&message, NULL, 0, 0, PM_REMOVE))
			{
				if (message.message == WM_LBUTTONUP) 
				{//如果在100ms内，找到新的鼠标弹起的消息，则将消息为双击
					pMsg->message = WM_LBUTTONDBLCLK;//将会响应 OnLButtonDblClk 函数，该函数可在类向导中自动生成
					break;
				}
				else if (message.message == WM_LBUTTONDOWN) 
				{//如果收到鼠标按下消息，不做处理

				}
				else 
				{
					//如果不是鼠标按下或弹起的消息，则将消息插进消息上队列重新分发
					::TranslateMessage(&message);
					::DispatchMessage(&message);
				}
				DWORD et = GetTickCount();//如果时间差超过100ms，则将此次点击当作单击处理
				if (et - st > 100) 
				{
					pMsg->message == WM_LBUTTONUP;
					break;;
				}
			}
		}

	}

	return CFormView::PreTranslateMessage(pMsg);
}


void CAlterDlg::OnBnClickedButton2()
{
	// TODO: 在此添加控件通知处理程序代码
	{
		// TODO: 在此添加控件通知处理程序代码
		UpdateData(TRUE);
		char select[1000];
		sprintf_s(select, "select * from empolyee where e_id = \'%d\'", a_id);
		mysql_set_character_set(&m_sqlCon, "gb2312");
		mysql_query(&m_sqlCon, select);
		res = mysql_store_result(&m_sqlCon);
		row = mysql_fetch_row(res);
		if (row != 0)
		{
			qa_id = atoi(row[0]);
			qa_name = row[1];
			qa_gander = row[2];
			qa_age = atoi(row[3]);
			qa_job = row[4];
			UpdateData(FALSE);
		}
		else
		{
			MessageBox(TEXT("该用户不存在！"));
		}
	}
}
