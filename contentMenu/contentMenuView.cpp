
// contentMenuView.cpp: CcontentMenuView 类的实现
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "contentMenu.h"
#endif

#include "contentMenuDoc.h"
#include "contentMenuView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CcontentMenuView

IMPLEMENT_DYNCREATE(CcontentMenuView, CView)

BEGIN_MESSAGE_MAP(CcontentMenuView, CView)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
END_MESSAGE_MAP()

// CcontentMenuView 构造/析构

CcontentMenuView::CcontentMenuView() noexcept
{
	// TODO: 在此处添加构造代码

}

CcontentMenuView::~CcontentMenuView()
{
}

BOOL CcontentMenuView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CcontentMenuView 绘图

void CcontentMenuView::OnDraw(CDC* /*pDC*/)
{
	CcontentMenuDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}

void CcontentMenuView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CcontentMenuView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	//theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_MENU1, point.x, point.y, this, TRUE);
#endif
}


// CcontentMenuView 诊断

#ifdef _DEBUG
void CcontentMenuView::AssertValid() const
{
	CView::AssertValid();
}

void CcontentMenuView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CcontentMenuDoc* CcontentMenuView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CcontentMenuDoc)));
	return (CcontentMenuDoc*)m_pDocument;
}
#endif //_DEBUG


// CcontentMenuView 消息处理程序
