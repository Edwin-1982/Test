
// draw(Circle)View.cpp: CdrawCircleView 类的实现
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "draw(Circle).h"
#endif

#include "draw(Circle)Doc.h"
#include "draw(Circle)View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CdrawCircleView

IMPLEMENT_DYNCREATE(CdrawCircleView, CView)

BEGIN_MESSAGE_MAP(CdrawCircleView, CView)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
END_MESSAGE_MAP()

// CdrawCircleView 构造/析构

CdrawCircleView::CdrawCircleView() noexcept
{
	// TODO: 在此处添加构造代码
	m_pOrigin = 0;
	m_bDraw = false;
}

CdrawCircleView::~CdrawCircleView()
{
}

BOOL CdrawCircleView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CdrawCircleView 绘图

void CdrawCircleView::OnDraw(CDC* /*pDC*/)
{
	CdrawCircleDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}


// CdrawCircleView 诊断

#ifdef _DEBUG
void CdrawCircleView::AssertValid() const
{
	CView::AssertValid();
}

void CdrawCircleView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CdrawCircleDoc* CdrawCircleView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CdrawCircleDoc)));
	return (CdrawCircleDoc*)m_pDocument;
}
#endif //_DEBUG


// CdrawCircleView 消息处理程序


void CdrawCircleView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	m_pOrigin = point;
	m_bDraw = !m_bDraw;
	CView::OnLButtonDown(nFlags, point);
}


void CdrawCircleView::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CClientDC dc(this);
	CPen pen(PS_DASH, 1, RGB(255, 0, 255));
	CPen* pOldpen = dc.SelectObject(&pen);

	//画椭圆
	//dc.Ellipse(CRect(m_pOrigin,point));

	//画圆
	long len = point.x - m_pOrigin.x;
	dc.Ellipse(m_pOrigin.x, m_pOrigin.y, m_pOrigin.x + len, m_pOrigin.y + len);
	dc.SelectObject(pOldpen);
	CView::OnLButtonUp(nFlags, point);
}


void CdrawCircleView::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值

	CView::OnMouseMove(nFlags, point);
}
