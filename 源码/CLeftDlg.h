#pragma once


#include "afxcview.h"
// CLeftDlg 窗体视图

class CLeftDlg : public CTreeView
{
	DECLARE_DYNCREATE(CLeftDlg)

protected:
	CLeftDlg();           // 动态创建所使用的受保护的构造函数
	virtual ~CLeftDlg();

public:
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_LEFT };
#endif
#ifdef _DEBUG
	virtual void AssertValid() const;
#ifndef _WIN32_WCE
	virtual void Dump(CDumpContext& dc) const;
#endif
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
	CTreeCtrl* m_treeCtrl;
public:
	virtual void OnInitialUpdate();
	afx_msg void OnTvnSelchanged(NMHDR* pNMHDR, LRESULT* pResult);
};


