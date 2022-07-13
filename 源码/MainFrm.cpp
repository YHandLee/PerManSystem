
// MainFrm.cpp: CMainFrame 类的实现
//

#include "pch.h"
#include "framework.h"
#include "PerManSystem.h"

#include "MainFrm.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CMainFrame

IMPLEMENT_DYNCREATE(CMainFrame, CFrameWnd)

BEGIN_MESSAGE_MAP(CMainFrame, CFrameWnd)
	ON_WM_CREATE()

	ON_MESSAGE(NM_A, OnMyChange)
	ON_MESSAGE(NM_B, OnMyChange)
	ON_MESSAGE(NM_C, OnMyChange)
	ON_MESSAGE(NM_D, OnMyChange)

END_MESSAGE_MAP()

static UINT indicators[] =
{
	ID_SEPARATOR,           // 状态行指示器
	ID_INDICATOR_CAPS,
	ID_INDICATOR_NUM,
	ID_INDICATOR_SCRL,
};

// CMainFrame 构造/析构

CMainFrame::CMainFrame() noexcept
{
	// TODO: 在此添加成员初始化代码
}

CMainFrame::~CMainFrame()
{
}

LRESULT CMainFrame::OnMyChange(WPARAM wParam, LPARAM lParam)
{
	CCreateContext Context;

	if (wParam == NM_A)
	{
		Context.m_pNewViewClass = RUNTIME_CLASS(CQueryDlg);
		Context.m_pCurrentFrame = this;
		Context.m_pLastView = (CFormView*)m_wnd.GetPane(0, 1);
		m_wnd.DeleteView(0, 1);
		m_wnd.CreateView(0, 1, RUNTIME_CLASS(CQueryDlg), CSize(600, 500), & Context);
		CQueryDlg* pNewView = (CQueryDlg*)m_wnd.GetPane(0, 1);
		m_wnd.RecalcLayout();
		pNewView->OnInitialUpdate();
		m_wnd.SetActivePane(0, 1);

	}
	else if (wParam == NM_B)
	{
		Context.m_pNewViewClass = RUNTIME_CLASS(CAddInfo);
		Context.m_pCurrentFrame = this;
		Context.m_pLastView = (CFormView*)m_wnd.GetPane(0, 1);
		m_wnd.DeleteView(0, 1);
		m_wnd.CreateView(0, 1, RUNTIME_CLASS(CAddInfo), CSize(600, 500), &Context);
		CAddInfo* pNewView = (CAddInfo*)m_wnd.GetPane(0, 1);
		m_wnd.RecalcLayout();
		pNewView->OnInitialUpdate();
		m_wnd.SetActivePane(0, 1);
	}
	else if (wParam == NM_C)
	{
		Context.m_pNewViewClass = RUNTIME_CLASS(CAlterDlg);
		Context.m_pCurrentFrame = this;
		Context.m_pLastView = (CFormView*)m_wnd.GetPane(0, 1);
		m_wnd.DeleteView(0, 1);
		m_wnd.CreateView(0, 1, RUNTIME_CLASS(CAlterDlg), CSize(600, 500), &Context);
		CAlterDlg* pNewView = (CAlterDlg*)m_wnd.GetPane(0, 1);
		m_wnd.RecalcLayout();
		pNewView->OnInitialUpdate();
		m_wnd.SetActivePane(0, 1);
	}
	else if (wParam == NM_D)
	{
		
		Context.m_pNewViewClass = RUNTIME_CLASS(CDeleteDlg);
		Context.m_pCurrentFrame = this;
		Context.m_pLastView = (CFormView*)m_wnd.GetPane(0, 1);
		m_wnd.DeleteView(0, 1);
		m_wnd.CreateView(0, 1, RUNTIME_CLASS(CDeleteDlg), CSize(600, 500), &Context);
		CDeleteDlg* pNewView = (CDeleteDlg*)m_wnd.GetPane(0, 1);
		m_wnd.RecalcLayout();
		pNewView->OnInitialUpdate();
		m_wnd.SetActivePane(0, 1);
	}

	return 0;
}

int CMainFrame::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CFrameWnd::OnCreate(lpCreateStruct) == -1)
		return -1;

	if (!m_wndStatusBar.Create(this))
	{
		TRACE0("未能创建状态栏\n");
		return -1;      // 未能创建
	}
	m_wndStatusBar.SetIndicators(indicators, sizeof(indicators)/sizeof(UINT));

	SetTitle(TEXT("version_1.0"));

	MoveWindow(0, 0, 800, 500);
	CenterWindow();


	return 0;
}

BOOL CMainFrame::PreCreateWindow(CREATESTRUCT& cs)
{
	if( !CFrameWnd::PreCreateWindow(cs) )
		return FALSE;
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return TRUE;
}

// CMainFrame 诊断

#ifdef _DEBUG
void CMainFrame::AssertValid() const
{
	CFrameWnd::AssertValid();
}

void CMainFrame::Dump(CDumpContext& dc) const
{
	CFrameWnd::Dump(dc);
}
#endif //_DEBUG


// CMainFrame 消息处理程序



BOOL CMainFrame::OnCreateClient(LPCREATESTRUCT lpcs, CCreateContext* pContext)
{
	// TODO: 在此添加专用代码和/或调用基类

	m_wnd.CreateStatic(this, 1, 2);
	m_wnd.CreateView(0, 0, RUNTIME_CLASS(CLeftDlg), CSize(200, 500), pContext);
	m_wnd.CreateView(0, 1, RUNTIME_CLASS(CRightDlg), CSize(600, 500), pContext);
	ShowWindow(SW_SHOWMAXIMIZED);
	return TRUE;
}
