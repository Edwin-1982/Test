
<<<<<<< HEAD
// draw3Doc.cpp: Cdraw3Doc 类的实现
=======
// demo3Doc.cpp: Cdemo3Doc 类的实现
>>>>>>> 9e554366a77ae3dcece734b3397a645223ff5948
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
<<<<<<< HEAD
#include "draw3.h"
#endif

#include "draw3Doc.h"
=======
#include "demo3.h"
#endif

#include "demo3Doc.h"
>>>>>>> 9e554366a77ae3dcece734b3397a645223ff5948

#include <propkey.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

<<<<<<< HEAD
// Cdraw3Doc

IMPLEMENT_DYNCREATE(Cdraw3Doc, CDocument)

BEGIN_MESSAGE_MAP(Cdraw3Doc, CDocument)
END_MESSAGE_MAP()


// Cdraw3Doc 构造/析构

Cdraw3Doc::Cdraw3Doc() noexcept
=======
// Cdemo3Doc

IMPLEMENT_DYNCREATE(Cdemo3Doc, CDocument)

BEGIN_MESSAGE_MAP(Cdemo3Doc, CDocument)
END_MESSAGE_MAP()


// Cdemo3Doc 构造/析构

Cdemo3Doc::Cdemo3Doc() noexcept
>>>>>>> 9e554366a77ae3dcece734b3397a645223ff5948
{
	// TODO: 在此添加一次性构造代码

}

<<<<<<< HEAD
Cdraw3Doc::~Cdraw3Doc()
{
}

BOOL Cdraw3Doc::OnNewDocument()
=======
Cdemo3Doc::~Cdemo3Doc()
{
}

BOOL Cdemo3Doc::OnNewDocument()
>>>>>>> 9e554366a77ae3dcece734b3397a645223ff5948
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: 在此添加重新初始化代码
	// (SDI 文档将重用该文档)

	return TRUE;
}




<<<<<<< HEAD
// Cdraw3Doc 序列化

void Cdraw3Doc::Serialize(CArchive& ar)
=======
// Cdemo3Doc 序列化

void Cdemo3Doc::Serialize(CArchive& ar)
>>>>>>> 9e554366a77ae3dcece734b3397a645223ff5948
{
	if (ar.IsStoring())
	{
		// TODO:  在此添加存储代码
	}
	else
	{
		// TODO:  在此添加加载代码
	}
}

#ifdef SHARED_HANDLERS

// 缩略图的支持
<<<<<<< HEAD
void Cdraw3Doc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
=======
void Cdemo3Doc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
>>>>>>> 9e554366a77ae3dcece734b3397a645223ff5948
{
	// 修改此代码以绘制文档数据
	dc.FillSolidRect(lprcBounds, RGB(255, 255, 255));

	CString strText = _T("TODO: implement thumbnail drawing here");
	LOGFONT lf;

	CFont* pDefaultGUIFont = CFont::FromHandle((HFONT) GetStockObject(DEFAULT_GUI_FONT));
	pDefaultGUIFont->GetLogFont(&lf);
	lf.lfHeight = 36;

	CFont fontDraw;
	fontDraw.CreateFontIndirect(&lf);

	CFont* pOldFont = dc.SelectObject(&fontDraw);
	dc.DrawText(strText, lprcBounds, DT_CENTER | DT_WORDBREAK);
	dc.SelectObject(pOldFont);
}

// 搜索处理程序的支持
<<<<<<< HEAD
void Cdraw3Doc::InitializeSearchContent()
=======
void Cdemo3Doc::InitializeSearchContent()
>>>>>>> 9e554366a77ae3dcece734b3397a645223ff5948
{
	CString strSearchContent;
	// 从文档数据设置搜索内容。
	// 内容部分应由“;”分隔

	// 例如:     strSearchContent = _T("point;rectangle;circle;ole object;")；
	SetSearchContent(strSearchContent);
}

<<<<<<< HEAD
void Cdraw3Doc::SetSearchContent(const CString& value)
=======
void Cdemo3Doc::SetSearchContent(const CString& value)
>>>>>>> 9e554366a77ae3dcece734b3397a645223ff5948
{
	if (value.IsEmpty())
	{
		RemoveChunk(PKEY_Search_Contents.fmtid, PKEY_Search_Contents.pid);
	}
	else
	{
		CMFCFilterChunkValueImpl *pChunk = nullptr;
		ATLTRY(pChunk = new CMFCFilterChunkValueImpl);
		if (pChunk != nullptr)
		{
			pChunk->SetTextValue(PKEY_Search_Contents, value, CHUNK_TEXT);
			SetChunkValue(pChunk);
		}
	}
}

#endif // SHARED_HANDLERS

<<<<<<< HEAD
// Cdraw3Doc 诊断

#ifdef _DEBUG
void Cdraw3Doc::AssertValid() const
=======
// Cdemo3Doc 诊断

#ifdef _DEBUG
void Cdemo3Doc::AssertValid() const
>>>>>>> 9e554366a77ae3dcece734b3397a645223ff5948
{
	CDocument::AssertValid();
}

<<<<<<< HEAD
void Cdraw3Doc::Dump(CDumpContext& dc) const
=======
void Cdemo3Doc::Dump(CDumpContext& dc) const
>>>>>>> 9e554366a77ae3dcece734b3397a645223ff5948
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


<<<<<<< HEAD
// Cdraw3Doc 命令
=======
// Cdemo3Doc 命令
>>>>>>> 9e554366a77ae3dcece734b3397a645223ff5948
