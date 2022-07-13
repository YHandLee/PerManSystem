// CRightDlg.cpp: 实现文件
//

#include "pch.h"
#include "PerManSystem.h"
#include "CRightDlg.h"


// CRightDlg

IMPLEMENT_DYNCREATE(CRightDlg, CFormView)

CRightDlg::CRightDlg()
	: CFormView(IDD_RIGHT)
{

}

CRightDlg::~CRightDlg()
{
}

void CRightDlg::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CRightDlg, CFormView)
END_MESSAGE_MAP()


// CRightDlg 诊断

#ifdef _DEBUG
void CRightDlg::AssertValid() const
{
	CFormView::AssertValid();
}

#ifndef _WIN32_WCE
void CRightDlg::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif
#endif //_DEBUG


// CRightDlg 消息处理程序
