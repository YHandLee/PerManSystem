#pragma once
#include "afxdialogex.h"


// CRegsitDlg 对话框

class CRegsitDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CRegsitDlg)

public:
	CRegsitDlg(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~CRegsitDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_REGIST };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CString r_user;
	CString r_pwd;
	CString rr_pwd;
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
};
