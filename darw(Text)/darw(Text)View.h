
// darw(Text)View.h: CdarwTextView 类的接口
//

#pragma once


class CdarwTextView : public CView
{
protected: // 仅从序列化创建
	CdarwTextView() noexcept;
	DECLARE_DYNCREATE(CdarwTextView)

// 特性
public:
	CdarwTextDoc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 实现
public:
	virtual ~CdarwTextView();
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
public:
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnTimer(UINT_PTR nIDEvent);
protected:
	int m_nWidth;
};

#ifndef _DEBUG  // darw(Text)View.cpp 中的调试版本
inline CdarwTextDoc* CdarwTextView::GetDocument() const
   { return reinterpret_cast<CdarwTextDoc*>(m_pDocument); }
#endif

