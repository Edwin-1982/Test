
// draw(Right Key)View.cpp: CdrawRightKeyView 类的实现
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "draw(Right Key).h"
#endif

#include "draw(Right Key)Doc.h"
#include "draw(Right Key)View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CdrawRightKeyView

IMPLEMENT_DYNCREATE(CdrawRightKeyView, CView)

BEGIN_MESSAGE_MAP(CdrawRightKeyView, CView)
	ON_WM_LBUTTONUP()
	ON_WM_LBUTTONDOWN()
	ON_WM_MOUSEMOVE()
	ON_COMMAND(ID_DRAW_LINE, &CdrawRightKeyView::OnDrawLine)
	ON_COMMAND(ID_DRAW_RECT, &CdrawRightKeyView::OnDrawRect)
	ON_COMMAND(ID_DRAW_ELLIPSE, &CdrawRightKeyView::OnDrawEllipse)
	ON_COMMAND(ID_DRAW_PEN, &CdrawRightKeyView::OnDrawPen)
	ON_UPDATE_COMMAND_UI(ID_DRAW_LINE, &CdrawRightKeyView::OnUpdateDrawLine)
	ON_UPDATE_COMMAND_UI(ID_DRAW_RECT, &CdrawRightKeyView::OnUpdateDrawRect)
	ON_UPDATE_COMMAND_UI(ID_DRAW_ELLIPSE, &CdrawRightKeyView::OnUpdateDrawEllipse)
	ON_UPDATE_COMMAND_UI(ID_DRAW_PEN, &CdrawRightKeyView::OnUpdateDrawPen)
	ON_WM_RBUTTONUP()
END_MESSAGE_MAP()

// CdrawRightKeyView 构造/析构

CdrawRightKeyView::CdrawRightKeyView() noexcept
{
	// TODO: 在此处添加构造代码

	m_pOrigin = 0;
	m_bDraw = false;
	m_DrawType = DT_LINE;
}

CdrawRightKeyView::~CdrawRightKeyView()
{
}

BOOL CdrawRightKeyView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式
	m_Menu.LoadMenu(IDR_MENU1);

	return CView::PreCreateWindow(cs);
}

// CdrawRightKeyView 绘图

void CdrawRightKeyView::OnDraw(CDC* /*pDC*/)
{
	CdrawRightKeyDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}


// CdrawRightKeyView 诊断

#ifdef _DEBUG
void CdrawRightKeyView::AssertValid() const
{
	CView::AssertValid();
}

void CdrawRightKeyView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CdrawRightKeyDoc* CdrawRightKeyView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CdrawRightKeyDoc)));
	return (CdrawRightKeyDoc*)m_pDocument;
}
#endif //_DEBUG


// CdrawRightKeyView 消息处理程序

void CdrawRightKeyView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	//保存起点到成员变量
	m_pOrigin = point;

	if (m_DrawType == DT_PEN) {
		m_bDraw = true;
	}
	CView::OnLButtonUp(nFlags, point);
}
void CdrawRightKeyView::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
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
}

void CdrawRightKeyView::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	if (m_DrawType == DT_PEN && m_bDraw == true) {
		CClientDC dc(this);
		CPen pen(PS_SOLID, 2, RGB(0, 10, 255));
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


void CdrawRightKeyView::OnDrawLine()
{
	// TODO: 在此添加命令处理程序代码
	m_DrawType = DT_LINE;
}


void CdrawRightKeyView::OnDrawRect()
{
	// TODO: 在此添加命令处理程序代码
	m_DrawType = DT_RECT;
}


void CdrawRightKeyView::OnDrawEllipse()
{
	// TODO: 在此添加命令处理程序代码
	m_DrawType = DT_ELLIPSE;
}

void CdrawRightKeyView::OnDrawPen()
{
	// TODO: 在此添加命令处理程序代码
	m_DrawType = DT_PEN;
}


void CdrawRightKeyView::OnUpdateDrawLine(CCmdUI* pCmdUI)
{
	// TODO: 在此添加命令更新用户界面处理程序代码
	//决定"画线"菜单项check状态,如果m_drawType是DT_LINE,打勾
	pCmdUI->SetCheck(m_DrawType == DT_LINE);
}


void CdrawRightKeyView::OnUpdateDrawRect(CCmdUI* pCmdUI)
{
	// TODO: 在此添加命令更新用户界面处理程序代码
	//决定"画线"菜单项check状态,如果m_drawType是DT_LINE,打勾
	pCmdUI->SetCheck(m_DrawType == DT_RECT);
}


void CdrawRightKeyView::OnUpdateDrawEllipse(CCmdUI* pCmdUI)
{
	// TODO: 在此添加命令更新用户界面处理程序代码
	//决定"画线"菜单项check状态,如果m_drawType是DT_LINE,打勾
	pCmdUI->SetCheck(m_DrawType == DT_ELLIPSE);
}


void CdrawRightKeyView::OnUpdateDrawPen(CCmdUI* pCmdUI)
{
	// TODO: 在此添加命令更新用户界面处理程序代码
	//决定"画线"菜单项check状态,如果m_drawType是DT_LINE,打勾
	pCmdUI->SetCheck(m_DrawType == DT_PEN);
	//pCmdUI->Enable(false);//禁用画笔功能
}


void CdrawRightKeyView::OnRButtonUp(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CMenu* mu = m_Menu.GetSubMenu(0);
	//把应用坐标转换成屏幕坐标
	ClientToScreen(&point);
	//ScreenToClient(&point);//屏幕坐标转应用坐标
	mu->TrackPopupMenu(TPM_LEFTALIGN,point.x,point.y,this);
	CView::OnRButtonUp(nFlags, point);
}
