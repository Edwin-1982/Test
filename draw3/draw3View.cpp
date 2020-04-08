
// draw3View.cpp: Cdraw3View 类的实现
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "draw3.h"
#endif

#include "draw3Doc.h"
#include "draw3View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Cdraw3View

IMPLEMENT_DYNCREATE(Cdraw3View, CView)

BEGIN_MESSAGE_MAP(Cdraw3View, CView)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
END_MESSAGE_MAP()

// Cdraw3View 构造/析构

Cdraw3View::Cdraw3View() noexcept
{
	// TODO: 在此处添加构造代码

	m_pOrigin = 0;
}

Cdraw3View::~Cdraw3View()
{
}

BOOL Cdraw3View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// Cdraw3View 绘图

void Cdraw3View::OnDraw(CDC* /*pDC*/)
{
	Cdraw3Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}


// Cdraw3View 诊断

#ifdef _DEBUG
void Cdraw3View::AssertValid() const
{
	CView::AssertValid();
}

void Cdraw3View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

Cdraw3Doc* Cdraw3View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Cdraw3Doc)));
	return (Cdraw3Doc*)m_pDocument;
}
#endif //_DEBUG


// Cdraw3View 消息处理程序


void Cdraw3View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	//保存起点到成员变量
	m_pOrigin = point;
	int a = 1;
	CView::OnLButtonDown(nFlags, point);
}


void Cdraw3View::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	//画线
	//获取上下文设备
	CDC* pDC = GetDC();
	
	//画笔移动到起始点
	pDC->MoveTo(m_pOrigin);
	//从起点到终点画一条线
	pDC->LineTo(point);

	ReleaseDC(pDC);

	CView::OnLButtonUp(nFlags, point);
}
