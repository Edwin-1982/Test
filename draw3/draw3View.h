
// draw3View.h: Cdraw3View 类的接口
//

#pragma once


class Cdraw3View : public CView
{
protected: // 仅从序列化创建
	Cdraw3View() noexcept;
	DECLARE_DYNCREATE(Cdraw3View)

// 特性
public:
	Cdraw3Doc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 实现
public:
	virtual ~Cdraw3View();
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
protected:
	CPoint m_pOrigin;
public:
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
protected:
	bool m_bDraw;
};

#ifndef _DEBUG  // draw3View.cpp 中的调试版本
inline Cdraw3Doc* Cdraw3View::GetDocument() const
   { return reinterpret_cast<Cdraw3Doc*>(m_pDocument); }
#endif

