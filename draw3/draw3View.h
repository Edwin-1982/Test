
<<<<<<< HEAD
// draw3View.h: Cdraw3View 类的接口
=======
// demo3View.h: Cdemo3View 类的接口
>>>>>>> 9e554366a77ae3dcece734b3397a645223ff5948
//

#pragma once


<<<<<<< HEAD
class Cdraw3View : public CView
{
protected: // 仅从序列化创建
	Cdraw3View() noexcept;
	DECLARE_DYNCREATE(Cdraw3View)

// 特性
public:
	Cdraw3Doc* GetDocument() const;
=======
class Cdemo3View : public CView
{
protected: // 仅从序列化创建
	Cdemo3View() noexcept;
	DECLARE_DYNCREATE(Cdemo3View)

// 特性
public:
	Cdemo3Doc* GetDocument() const;
>>>>>>> 9e554366a77ae3dcece734b3397a645223ff5948

// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 实现
public:
<<<<<<< HEAD
	virtual ~Cdraw3View();
=======
	virtual ~Cdemo3View();
>>>>>>> 9e554366a77ae3dcece734b3397a645223ff5948
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
<<<<<<< HEAD
	CPoint m_pOrigin;
};

#ifndef _DEBUG  // draw3View.cpp 中的调试版本
inline Cdraw3Doc* Cdraw3View::GetDocument() const
   { return reinterpret_cast<Cdraw3Doc*>(m_pDocument); }
=======
	CPoint m_porigin;
};

#ifndef _DEBUG  // demo3View.cpp 中的调试版本
inline Cdemo3Doc* Cdemo3View::GetDocument() const
   { return reinterpret_cast<Cdemo3Doc*>(m_pDocument); }
>>>>>>> 9e554366a77ae3dcece734b3397a645223ff5948
#endif

