
// contentMenuView.h: CcontentMenuView 类的接口
//

#pragma once


class CcontentMenuView : public CView
{
protected: // 仅从序列化创建
	CcontentMenuView() noexcept;
	DECLARE_DYNCREATE(CcontentMenuView)

// 特性
public:
	CcontentMenuDoc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 实现
public:
	virtual ~CcontentMenuView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // contentMenuView.cpp 中的调试版本
inline CcontentMenuDoc* CcontentMenuView::GetDocument() const
   { return reinterpret_cast<CcontentMenuDoc*>(m_pDocument); }
#endif

