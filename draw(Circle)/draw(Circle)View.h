
// draw(Circle)View.h: CdrawCircleView 类的接口
//

#pragma once


class CdrawCircleView : public CView
{
protected: // 仅从序列化创建
	CdrawCircleView() noexcept;
	DECLARE_DYNCREATE(CdrawCircleView)

// 特性
public:
	CdrawCircleDoc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 实现
public:
	virtual ~CdrawCircleView();
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
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
protected:
	bool m_bDraw;
	CPoint m_pOrigin;
};

#ifndef _DEBUG  // draw(Circle)View.cpp 中的调试版本
inline CdrawCircleDoc* CdrawCircleView::GetDocument() const
   { return reinterpret_cast<CdrawCircleDoc*>(m_pDocument); }
#endif

