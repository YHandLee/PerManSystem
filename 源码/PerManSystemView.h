
// PerManSystemView.h: CPerManSystemView 类的接口
//

#pragma once


class CPerManSystemView : public CView
{
protected: // 仅从序列化创建
	CPerManSystemView() noexcept;
	DECLARE_DYNCREATE(CPerManSystemView)

// 特性
public:
	CPerManSystemDoc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// 实现
public:
	virtual ~CPerManSystemView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // PerManSystemView.cpp 中的调试版本
inline CPerManSystemDoc* CPerManSystemView::GetDocument() const
   { return reinterpret_cast<CPerManSystemDoc*>(m_pDocument); }
#endif

