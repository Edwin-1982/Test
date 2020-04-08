
// demo3View.cpp: Cdemo3View 类的实现
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "demo3.h"
#endif

#include "demo3Doc.h"
#include "demo3View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Cdemo3View

IMPLEMENT_DYNCREATE(Cdemo3View, CView)

BEGIN_MESSAGE_MAP(Cdemo3View, CView)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
END_MESSAGE_MAP()

// Cdemo3View 构造/析构

Cdemo3View::Cdemo3View() noexcept
{
	// TODO: 在此处添加构造代码

}

Cdemo3View::~Cdemo3View()
{
}

BOOL Cdemo3View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// Cdemo3View 绘图

void Cdemo3View::OnDraw(CDC* /*pDC*/)
{
	Cdemo3Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}


// Cdemo3View 诊断

#ifdef _DEBUG
void Cdemo3View::AssertValid() const
{
	CView::AssertValid();
}

void Cdemo3View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

Cdemo3Doc* Cdemo3View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Cdemo3Doc)));
	return (Cdemo3Doc*)m_pDocument;
}
#endif //_DEBUG


// Cdemo3View 消息处理程序


void Cdemo3View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	//保存起点到成员变量
	m_porigin = point;

	CView::OnLButtonDown(nFlags, point);
}


void Cdemo3View::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	//画线
	//获得设备上下文
	CDC* pDC = GetDC();

	//画笔移动到起始点
	pDC->MoveTo(m_porigin);
	//从起点到终点画一条线
	pDC->LineTo(point);
	//释放设备上下文
	ReleaseDC(pDC);

	CView::OnLButtonUp(nFlags, point);
}
