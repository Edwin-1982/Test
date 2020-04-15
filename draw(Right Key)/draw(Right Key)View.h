
// draw(Right Key)View.h: CdrawRightKeyView 类的接口
//

#pragma once
enum DRAW_TYPE {
	DT_LINE,
	DT_RECT,
	DT_ELLIPSE,
	DT_PEN
};

class CdrawRightKeyView : public CView
{
protected: // 仅从序列化创建
	CdrawRightKeyView() noexcept;
	DECLARE_DYNCREATE(CdrawRightKeyView)

// 特性
public:
	CdrawRightKeyDoc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 实现
public:
	virtual ~CdrawRightKeyView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
protected:
	CPoint m_pOrigin;
	bool m_bDraw;
	CMenu m_Menu;
	enum DRAW_TYPE m_DrawType;
public:
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnDrawLine();
	afx_msg void OnDrawRect();
	afx_msg void OnDrawEllipse();
	afx_msg void OnDrawPen();
	afx_msg void OnUpdateDrawLine(CCmdUI* pCmdUI);
	afx_msg void OnUpdateDrawRect(CCmdUI* pCmdUI);
	afx_msg void OnUpdateDrawEllipse(CCmdUI* pCmdUI);
	afx_msg void OnUpdateDrawPen(CCmdUI* pCmdUI);
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // draw(Right Key)View.cpp 中的调试版本
inline CdrawRightKeyDoc* CdrawRightKeyView::GetDocument() const
   { return reinterpret_cast<CdrawRightKeyDoc*>(m_pDocument); }
#endif

