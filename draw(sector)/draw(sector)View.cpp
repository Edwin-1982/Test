
// draw(sector)View.cpp: CdrawsectorView 类的实现
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "draw(sector).h"
#endif

#include "draw(sector)Doc.h"
#include "draw(sector)View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CdrawsectorView

IMPLEMENT_DYNCREATE(CdrawsectorView, CView)

BEGIN_MESSAGE_MAP(CdrawsectorView, CView)
	ON_WM_LBUTTONDOWN()
	ON_WM_MOUSEMOVE()
	ON_WM_LBUTTONUP()
END_MESSAGE_MAP()

// CdrawsectorView 构造/析构

CdrawsectorView::CdrawsectorView() noexcept
{
	// TODO: 在此处添加构造代码
	m_pOrigin = 0;
	m_bDraw = false;
}

CdrawsectorView::~CdrawsectorView()
{
}

BOOL CdrawsectorView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CdrawsectorView 绘图

void CdrawsectorView::OnDraw(CDC* /*pDC*/)
{
	CdrawsectorDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}


// CdrawsectorView 诊断

#ifdef _DEBUG
void CdrawsectorView::AssertValid() const
{
	CView::AssertValid();
}

void CdrawsectorView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CdrawsectorDoc* CdrawsectorView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CdrawsectorDoc)));
	return (CdrawsectorDoc*)m_pDocument;
}
#endif //_DEBUG


// CdrawsectorView 消息处理程序

void CdrawsectorView::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值

	CView::OnLButtonUp(nFlags, point);
}
void CdrawsectorView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	m_pOrigin = point;
	m_bDraw = !m_bDraw;
	CView::OnLButtonDown(nFlags, point);
}
void CdrawsectorView::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CClientDC dc(this);
	CPen pen(PS_SOLID, 1, RGB(255, 100, 0));
	CPen *pOldPen=dc.SelectObject(&pen);
	if (m_bDraw) {
		dc.MoveTo(m_pOrigin);
		dc.LineTo(point);
	}
	dc.SelectObject(pOldPen);
	CView::OnMouseMove(nFlags, point);
}