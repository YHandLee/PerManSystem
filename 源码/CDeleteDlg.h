﻿#pragma once



// CDeleteDlg 窗体视图

class CDeleteDlg : public CFormView
{
	DECLARE_DYNCREATE(CDeleteDlg)

protected:
	CDeleteDlg();           // 动态创建所使用的受保护的构造函数
	virtual ~CDeleteDlg();

public:
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DELETE };
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
public:
	afx_msg void OnBnClickedButton2();
	int d_id;
	afx_msg void OnBnClickedButton1();
};


