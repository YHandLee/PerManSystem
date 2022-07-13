#pragma once



// CAddInfo 窗体视图

class CAddInfo : public CFormView
{
	DECLARE_DYNCREATE(CAddInfo)

protected:
	CAddInfo();           // 动态创建所使用的受保护的构造函数
	virtual ~CAddInfo();

public:
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ADDINFO };
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
	int e_id;
	CString e_name;
	CString e_gander;
	int e_age;
	CString e_job;
	afx_msg void OnBnClickedButton1();
	virtual void OnInitialUpdate();
	CComboBox e_cbx;
	CComboBox e_cbx2;
};


