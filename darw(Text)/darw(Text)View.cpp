
// darw(Text)View.cpp: CdarwTextView 类的实现
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "darw(Text).h"
#endif

#include "darw(Text)Doc.h"
#include "darw(Text)View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

#define TIMER_TEXT 9526
// CdarwTextView

IMPLEMENT_DYNCREATE(CdarwTextView, CView)

BEGIN_MESSAGE_MAP(CdarwTextView, CView)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
	ON_WM_CREATE()
	ON_WM_TIMER()
END_MESSAGE_MAP()

// CdarwTextView 构造/析构

CdarwTextView::CdarwTextView() noexcept
{
	// TODO: 在此处添加构造代码
	m_pOrigin = 0;
	m_bDraw = !m_bDraw;
	m_nWidth = 0;
}

CdarwTextView::~CdarwTextView()
{
}

BOOL CdarwTextView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CdarwTextView 绘图

void CdarwTextView::OnDraw(CDC* /*pDC*/)
{
	CdarwTextDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}


// CdarwTextView 诊断

#ifdef _DEBUG
void CdarwTextView::AssertValid() const
{
	CView::AssertValid();
}

void CdarwTextView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CdarwTextDoc* CdarwTextView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CdarwTextDoc)));
	return (CdarwTextDoc*)m_pDocument;
}
#endif //_DEBUG


// CdarwTextView 消息处理程序


void CdarwTextView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值

	m_pOrigin = point;
	m_bDraw = !m_bDraw;
	CView::OnLButtonDown(nFlags, point);
}


void CdarwTextView::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CClientDC dc(this);
	CFont font;
	//字体
	font.CreatePointFont(200,_T("华文行楷"));
	CFont* pOldFont = dc.SelectObject(&font);

	CString str(_T("你好,我好,大家好!"));
	//设置文字颜色
	dc.SetTextColor(RGB(125, 0, 127));

	//输出字符串
	//dc.TextOut(point.x, point.y, str, str.GetLength());
	
	//获取文字在屏幕上的空间大小,长度和宽度
	CSize cz=dc.GetTextExtent(str);

	//在指定矩形区域内画文字
	dc.DrawText(str,CRect(point.x,point.y,point.x + cz.cx/0.8,point.y + cz.cy/0.8),DT_LEFT);
	
	dc.SelectObject(pOldFont);
	CView::OnLButtonUp(nFlags, point);
}


void CdarwTextView::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值

	CView::OnMouseMove(nFlags, point);
}


int CdarwTextView::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CView::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  在此添加您专用的创建代码
	//添加定时器
	SetTimer(TIMER_TEXT, 200, NULL);
	return 0;
}


void CdarwTextView::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CClientDC dc(this);
	CFont font;
	font.CreatePointFont(200, _T("华文行楷"));
	CFont* pOldFont = dc.SelectObject(&font);

	CString str(_T("曾经沧海难为水,除却巫山不是云!"));
	dc.SetTextColor(RGB(125, 0, 127));
	CSize cz = dc.GetTextExtent(str);
	CRect rect;

	switch (nIDEvent)
	{
	case TIMER_TEXT:
		m_nWidth += 10;
		//获取文字在屏幕上的空间大小,长度和宽度
		
		rect.left = 200;
		rect.top = 100;
		rect.bottom = rect.top + cz.cy;
		rect.right = rect.left+m_nWidth;
		//在指定矩形区域内画文字
		dc.DrawText(str, rect, DT_LEFT); 
		if (m_nWidth > cz.cx) {
			m_nWidth = 0;
			//使屏幕无效(擦除屏幕内容)
			Invalidate();
		}
		dc.SelectObject(pOldFont);
		break;
	defualt:
		break;
	}
	CView::OnTimer(nIDEvent);
}
