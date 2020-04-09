
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


// CdarwTextView

IMPLEMENT_DYNCREATE(CdarwTextView, CView)

BEGIN_MESSAGE_MAP(CdarwTextView, CView)
END_MESSAGE_MAP()

// CdarwTextView 构造/析构

CdarwTextView::CdarwTextView() noexcept
{
	// TODO: 在此处添加构造代码

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
