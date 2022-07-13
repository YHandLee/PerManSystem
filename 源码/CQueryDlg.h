#pragma once



// CQueryDlg 窗体视图

class CQueryDlg : public CFormView
{
	DECLARE_DYNCREATE(CQueryDlg)

protected:
	CQueryDlg();           // 动态创建所使用的受保护的构造函数
	virtual ~CQueryDlg();

public:
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_QUERYINFO };
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
	afx_msg void OnBnClickedButton1();
	CListCtrl p_list;
	virtual void OnInitialUpdate();
	afx_msg void OnBnClickedButton2();
};


