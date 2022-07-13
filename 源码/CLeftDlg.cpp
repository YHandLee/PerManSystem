// CLeftDlg.cpp: 实现文件
//

#include "pch.h"
#include "PerManSystem.h"
#include "CLeftDlg.h"
#include "MainFrm.h"


// CLeftDlg

IMPLEMENT_DYNCREATE(CLeftDlg, CTreeView)

CLeftDlg::CLeftDlg()
	: CTreeView()
{

}

CLeftDlg::~CLeftDlg()
{
}

void CLeftDlg::DoDataExchange(CDataExchange* pDX)
{
	CTreeView::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CLeftDlg, CTreeView)
	ON_NOTIFY_REFLECT(TVN_SELCHANGED, &CLeftDlg::OnTvnSelchanged)
END_MESSAGE_MAP()


// CLeftDlg 诊断

#ifdef _DEBUG
void CLeftDlg::AssertValid() const
{
	CTreeView::AssertValid();
}

#ifndef _WIN32_WCE
void CLeftDlg::Dump(CDumpContext& dc) const
{
	CTreeView::Dump(dc);
}
#endif
#endif //_DEBUG


// CLeftDlg 消息处理程序


void CLeftDlg::OnInitialUpdate()
{
	CTreeView::OnInitialUpdate();

	// TODO: 在此添加专用代码和/或调用基类
	m_treeCtrl = &GetTreeCtrl();
	m_treeCtrl->InsertItem(TEXT("查询信息"), 0, 0, 0);
	m_treeCtrl->InsertItem(TEXT("增加信息"), 0, 0, 0);
	m_treeCtrl->InsertItem(TEXT("修改信息"), 0, 0, 0);
	m_treeCtrl->InsertItem(TEXT("删除信息"), 0, 0, 0);

}


void CLeftDlg::OnTvnSelchanged(NMHDR* pNMHDR, LRESULT* pResult)
{
	LPNMTREEVIEW pNMTreeView = reinterpret_cast<LPNMTREEVIEW>(pNMHDR);
	// TODO: 在此添加控件通知处理程序代码
	*pResult = 0;
	HTREEITEM item = m_treeCtrl->GetSelectedItem();
	CString str = m_treeCtrl->GetItemText(item);
	if (str == TEXT("查询信息"))
	{
		::PostMessage(AfxGetMainWnd()->GetSafeHwnd(), NM_A, (WPARAM)NM_A, (LPARAM)0);
	}
	else if (str == TEXT("增加信息"))
	{
		::PostMessage(AfxGetMainWnd()->GetSafeHwnd(), NM_B, (WPARAM)NM_B, (LPARAM)0);
	}
	else if (str == TEXT("修改信息"))
	{
		::PostMessage(AfxGetMainWnd()->GetSafeHwnd(), NM_C, (WPARAM)NM_C, (LPARAM)0);
	}
	else if (str == TEXT("删除信息"))
	{
		::PostMessage(AfxGetMainWnd()->GetSafeHwnd(), NM_D, (WPARAM)NM_D, (LPARAM)0);
	}


}
