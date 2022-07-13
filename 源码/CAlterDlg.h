#pragma once



// CAlterDlg 窗体视图

class CAlterDlg : public CFormView
{
	DECLARE_DYNCREATE(CAlterDlg)

protected:
	CAlterDlg();           // 动态创建所使用的受保护的构造函数
	virtual ~CAlterDlg();

public:
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ALTER };
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
	int a_id;
	int qa_id;
	CString qa_name;
	CString qa_gander;
	int qa_age;
	CString qa_job;
	CComboBox a_cbxg;
	CComboBox a_cbxj;
	virtual void OnInitialUpdate();
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnDoubleclickedButton1();
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	afx_msg void OnBnClickedButton2();
};


