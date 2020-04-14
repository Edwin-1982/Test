
// draw(Menu)View.h: CdrawMenuView 类的接口
//

#pragma once

enum DRAW_TYPE
{
	DT_LINE,
	DT_RECT,
	DT_ELLIPSE,
	DT_PEN
};
class CdrawMenuView : public CView
{
protected: // 仅从序列化创建
	CdrawMenuView() noexcept;
	DECLARE_DYNCREATE(CdrawMenuView)

// 特性
public:
	CdrawMenuDoc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 实现
public:
	virtual ~CdrawMenuView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
public:
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
protected:
	CPoint m_pOrigin;
	bool m_bDraw;
	enum DRAW_TYPE m_DrawType;
public:
	afx_msg void OnDrawLine();
	afx_msg void OnDrawRect();
	afx_msg void OnDrawPen();
	afx_msg void OnDrawEllipse();
	afx_msg void OnUpdateDrawLine(CCmdUI* pCmdUI);
	afx_msg void OnUpdateDrawRect(CCmdUI* pCmdUI);
	afx_msg void OnUpdateDrawEllipse(CCmdUI* pCmdUI);
	afx_msg void OnUpdateDrawPen(CCmdUI* pCmdUI);
};

#ifndef _DEBUG  // draw(Menu)View.cpp 中的调试版本
inline CdrawMenuDoc* CdrawMenuView::GetDocument() const
   { return reinterpret_cast<CdrawMenuDoc*>(m_pDocument); }
#endif

