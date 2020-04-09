
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
	ON_WM_MOUSEMOVE()
END_MESSAGE_MAP()

// Cdraw3View 构造/析构

Cdraw3View::Cdraw3View() noexcept
{
	// TODO: 在此处添加构造代码
	m_pOrigin = 0;
	m_bDraw = false;
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
	m_bDraw = !m_bDraw;//鼠标按下开始画
	m_bDraw = true;    //鼠标按住开始画
	/*if (m_bDraw) {
		m_bDraw = false;
	}
	else {
		m_bDraw = true;
	}*/
	CView::OnLButtonDown(nFlags, point);
}


void Cdraw3View::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	//画线
	//获取设备上下文
	/*
	CDC* pDC = GetDC();

	//画笔
	//CPen pen(PS_SOLID, 5, RGB(0,255,0));//绿实线
	CPen pen(PS_DASHDOT, 1, RGB(255,0,0));//红色点划线

	//设备上下文选中画笔
	CPen *pOldPen=pDC->SelectObject(&pen);

	//画笔移动到起点
	pDC->MoveTo(m_pOrigin);
	//画线
	pDC->LineTo(point);
	//设备上下文恢复画笔
	pDC->SelectObject(pOldPen);
	//释放设备上下文
	ReleaseDC(pDC);
	*/

	/*
	CClientDC dc(this);
	//获得系统透明画刷
	CBrush* brush = CBrush::FromHandle((HBRUSH)GetStockObject(NULL_BRUSH));
	//在设备上下文中选择画刷
	CBrush* oldbrush = dc.SelectObject(brush); 
	//画矩形
	dc.Rectangle(CRect(m_pOrigin, point));
	//恢复画刷
	dc.SelectObject(oldbrush);
	*/

	/*
	CClientDC dc(this);
	//默认画刷,白色,不透明
	dc.Rectangle(CRect(m_pOrigin,point));
	*/

	/*
	CClientDC dc(this);
	//CBrush brush(RGB(255, 0, 0));//红色矩形
	//CBrush brush(RGB(0, 255, 0));//绿色矩形
	CBrush brush(RGB(0, 125, 255));//天蓝矩形

	dc.FillRect(CRect(m_pOrigin, point),&brush);
	*/

	/*
	CClientDC dc(this);
	//Bitmap对象
	CBitmap bitmap;
	//从项目资源加载bitmap图像到对象中
	bitmap.LoadBitmap(IDB_BITMAP1);
	//以Bitmap做参数,生成画刷对象
	CBrush brush(&bitmap);
	
	dc.FillRect(CRect(m_pOrigin, point), &brush);
	*/
	m_bDraw = false;
	CView::OnLButtonUp(nFlags, point);
}


void Cdraw3View::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CClientDC dc(this);
	if (m_bDraw) {
		dc.MoveTo(m_pOrigin);
		dc.LineTo(point);

		m_pOrigin = point;
	}
	CView::OnMouseMove(nFlags, point);
}
