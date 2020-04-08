
<<<<<<< HEAD
// draw3Doc.h: Cdraw3Doc 类的接口
=======
// demo3Doc.h: Cdemo3Doc 类的接口
>>>>>>> 9e554366a77ae3dcece734b3397a645223ff5948
//


#pragma once


<<<<<<< HEAD
class Cdraw3Doc : public CDocument
{
protected: // 仅从序列化创建
	Cdraw3Doc() noexcept;
	DECLARE_DYNCREATE(Cdraw3Doc)
=======
class Cdemo3Doc : public CDocument
{
protected: // 仅从序列化创建
	Cdemo3Doc() noexcept;
	DECLARE_DYNCREATE(Cdemo3Doc)
>>>>>>> 9e554366a77ae3dcece734b3397a645223ff5948

// 特性
public:

// 操作
public:

// 重写
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
#ifdef SHARED_HANDLERS
	virtual void InitializeSearchContent();
	virtual void OnDrawThumbnail(CDC& dc, LPRECT lprcBounds);
#endif // SHARED_HANDLERS

// 实现
public:
<<<<<<< HEAD
	virtual ~Cdraw3Doc();
=======
	virtual ~Cdemo3Doc();
>>>>>>> 9e554366a77ae3dcece734b3397a645223ff5948
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()

#ifdef SHARED_HANDLERS
	// 用于为搜索处理程序设置搜索内容的 Helper 函数
	void SetSearchContent(const CString& value);
#endif // SHARED_HANDLERS
};
