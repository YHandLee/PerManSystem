#pragma once
#include "afxdialogex.h"


// CDloginDlg 对话框

class CDloginDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CDloginDlg)

public:
	CDloginDlg(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~CDloginDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_LoginDlg };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CString p_user;
	CString p_password;
	afx_msg void OnBnClickedButton1();
	afx_msg void OnClose();
	virtual void OnOK();
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedButton2();
};
