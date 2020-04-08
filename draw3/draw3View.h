
// demo3View.h: Cdemo3View 类的接口
//

#pragma once


class Cdemo3View : public CView
{
protected: // 仅从序列化创建
	Cdemo3View() noexcept;
	DECLARE_DYNCREATE(Cdemo3View)

// 特性
public:
	Cdemo3Doc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 实现
public:
	virtual ~Cdemo3View();
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
	CPoint m_porigin;
};

#ifndef _DEBUG  // demo3View.cpp 中的调试版本
inline Cdemo3Doc* Cdemo3View::GetDocument() const
   { return reinterpret_cast<Cdemo3Doc*>(m_pDocument); }
#endif

