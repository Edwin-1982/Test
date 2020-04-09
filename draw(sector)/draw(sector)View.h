
// draw(sector)View.h: CdrawsectorView 类的接口
//

#pragma once


class CdrawsectorView : public CView
{
protected: // 仅从序列化创建
	CdrawsectorView() noexcept;
	DECLARE_DYNCREATE(CdrawsectorView)

// 特性
public:
	CdrawsectorDoc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 实现
public:
	virtual ~CdrawsectorView();
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
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
protected:
	CPoint m_pOrigin;
	bool m_bDraw;
public:
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // draw(sector)View.cpp 中的调试版本
inline CdrawsectorDoc* CdrawsectorView::GetDocument() const
   { return reinterpret_cast<CdrawsectorDoc*>(m_pDocument); }
#endif

