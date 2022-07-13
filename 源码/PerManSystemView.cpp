
// PerManSystemView.cpp: CPerManSystemView 类的实现
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "PerManSystem.h"
#endif

#include "PerManSystemDoc.h"
#include "PerManSystemView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CPerManSystemView

IMPLEMENT_DYNCREATE(CPerManSystemView, CView)

BEGIN_MESSAGE_MAP(CPerManSystemView, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
END_MESSAGE_MAP()

// CPerManSystemView 构造/析构

CPerManSystemView::CPerManSystemView() noexcept
{
	// TODO: 在此处添加构造代码

}

CPerManSystemView::~CPerManSystemView()
{
}

BOOL CPerManSystemView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CPerManSystemView 绘图

void CPerManSystemView::OnDraw(CDC* /*pDC*/)
{
	CPerManSystemDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}


// CPerManSystemView 打印

BOOL CPerManSystemView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CPerManSystemView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CPerManSystemView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// CPerManSystemView 诊断

#ifdef _DEBUG
void CPerManSystemView::AssertValid() const
{
	CView::AssertValid();
}

void CPerManSystemView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CPerManSystemDoc* CPerManSystemView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CPerManSystemDoc)));
	return (CPerManSystemDoc*)m_pDocument;
}
#endif //_DEBUG


// CPerManSystemView 消息处理程序
