
// draw(Menu)View.cpp: CdrawMenuView 类的实现
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "draw(Menu).h"
#endif

#include "draw(Menu)Doc.h"
#include "draw(Menu)View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CdrawMenuView

IMPLEMENT_DYNCREATE(CdrawMenuView, CView)

BEGIN_MESSAGE_MAP(CdrawMenuView, CView)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
	ON_COMMAND(ID_DRAW_LINE, &CdrawMenuView::OnDrawLine)
	ON_COMMAND(ID_DRAW_RECT, &CdrawMenuView::OnDrawRect)
	ON_COMMAND(ID_DRAW_PEN, &CdrawMenuView::OnDrawPen)
	ON_COMMAND(ID_DRAW_ELLIPSE, &CdrawMenuView::OnDrawEllipse)
	ON_UPDATE_COMMAND_UI(ID_DRAW_LINE, &CdrawMenuView::OnUpdateDrawLine)
	ON_UPDATE_COMMAND_UI(ID_DRAW_RECT, &CdrawMenuView::OnUpdateDrawRect)
	ON_UPDATE_COMMAND_UI(ID_DRAW_ELLIPSE, &CdrawMenuView::OnUpdateDrawEllipse)
	ON_UPDATE_COMMAND_UI(ID_DRAW_PEN, &CdrawMenuView::OnUpdateDrawPen)
END_MESSAGE_MAP()

// CdrawMenuView 构造/析构

CdrawMenuView::CdrawMenuView() noexcept
{
	// TODO: 在此处添加构造代码
	m_pOrigin = 0;
	m_bDraw = false;
	m_DrawType = DT_LINE;
}

CdrawMenuView::~CdrawMenuView()
{
}

BOOL CdrawMenuView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CdrawMenuView 绘图

void CdrawMenuView::OnDraw(CDC* /*pDC*/)
{
	CdrawMenuDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}


// CdrawMenuView 诊断

#ifdef _DEBUG
void CdrawMenuView::AssertValid() const
{
	CView::AssertValid();
}

void CdrawMenuView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CdrawMenuDoc* CdrawMenuView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CdrawMenuDoc)));
	return (CdrawMenuDoc*)m_pDocument;
}
#endif //_DEBUG


// CdrawMenuView 消息处理程序


void CdrawMenuView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	//保存起点到成员变量
	m_pOrigin = point;
	
	if (m_DrawType == DT_PEN) {
		m_bDraw = true;
	}
	CView::OnLButtonDown(nFlags, point);
}


void CdrawMenuView::OnLButtonUp(UINT nFlags, CPoint point)
{
	
	CClientDC dc(this);
	CPen pen(PS_SOLID, 2, RGB(0, 10, 255));
	CPen* pOldPen = dc.SelectObject(&pen);

	switch (m_DrawType) {
	case DT_LINE:
		dc.MoveTo(m_pOrigin);
		dc.LineTo(point);
		break;
	case DT_RECT:
		dc.Rectangle(CRect(m_pOrigin, point));
		break;
	case DT_ELLIPSE:
		dc.Ellipse(CRect(m_pOrigin, point));
		break;
	case DT_PEN:
		m_bDraw = false;
		break;
	default:
		break;
	}
	dc.SelectObject(pOldPen);
	//CView::OnLButtonUp(nFlags, point);
}


void CdrawMenuView::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	
	if (m_DrawType==DT_PEN && m_bDraw==true) {
		CClientDC dc(this);
		CPen pen(PS_SOLID,2,RGB(0, 10, 255));
		CPen* pOldPen = dc.SelectObject(&pen);

		//从起点画一条线到终点
		dc.MoveTo(m_pOrigin);
		dc.LineTo(point);

		//终点变成新的起点
		m_pOrigin = point;
		dc.SelectObject(pOldPen);
	}
	CView::OnMouseMove(nFlags, point);
}


void CdrawMenuView::OnDrawLine()
{
	// TODO: 在此添加命令处理程序代码
	m_DrawType = DT_LINE;
}


void CdrawMenuView::OnDrawRect()
{
	// TODO: 在此添加命令处理程序代码
	m_DrawType = DT_RECT;

}

void CdrawMenuView::OnDrawEllipse()
{
	// TODO: 在此添加命令处理程序代码
	m_DrawType = DT_ELLIPSE;

}

void CdrawMenuView::OnDrawPen()
{
	// TODO: 在此添加命令处理程序代码
	m_DrawType = DT_PEN;
}


void CdrawMenuView::OnUpdateDrawLine(CCmdUI* pCmdUI)
{
	// TODO: 在此添加命令更新用户界面处理程序代码
	//决定"画线"菜单项check状态,如果m_drawType是DT_LINE,打勾
	pCmdUI->SetCheck(m_DrawType == DT_LINE);

}


void CdrawMenuView::OnUpdateDrawRect(CCmdUI* pCmdUI)
{
	// TODO: 在此添加命令更新用户界面处理程序代码
	//决定"画椭圆"菜单项check状态,如果m_drawType是DT_RECT,打勾
	pCmdUI->SetCheck(m_DrawType == DT_RECT);

}


void CdrawMenuView::OnUpdateDrawEllipse(CCmdUI* pCmdUI)
{
	// TODO: 在此添加命令更新用户界面处理程序代码
	//决定"画椭圆"菜单项check状态,如果m_drawType是DT_ELLIPSE,打勾
	pCmdUI->SetCheck(m_DrawType==DT_ELLIPSE);
}


void CdrawMenuView::OnUpdateDrawPen(CCmdUI* pCmdUI)
{
	// TODO: 在此添加命令更新用户界面处理程序代码
	//决定"画椭圆"菜单项check状态,如果m_drawType是DT_PEN,打勾
	pCmdUI->SetCheck(m_DrawType == DT_PEN);
	//pCmdUI->Enable(false);//禁用画笔功能

}
