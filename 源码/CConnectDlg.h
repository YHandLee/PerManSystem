#pragma once
#include "afxdialogex.h"
#include "CDloginDlg.h"
#include "CLeftDlg.h"
#include <winsock.h>
#include <mysql.h>
#pragma comment(lib,"libmySQL.lib")//附加依赖项，也可以在工程属性中设置
#pragma comment(lib,"mysqlclient.lib")


extern MYSQL m_sqlCon;  //声明数据库对象
extern MYSQL_RES* res;	//保存读取到的结果，存入MYSQL_RES结构体中
extern MYSQL_ROW row;	//读取上述结果时，将每行的数据存入该字符串中

// CConnectDlg 对话框

class CConnectDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CConnectDlg)

public:
	CConnectDlg(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~CConnectDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_CONNECT };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton2();
	CString d_address;
	CString d_user;
	CString d_password;
	int d_port;
	afx_msg void OnBnClickedButton1();
	CString d_name;
	virtual void OnOK();
	afx_msg void OnClose();
};
