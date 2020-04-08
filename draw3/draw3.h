
<<<<<<< HEAD
// draw3.h: draw3 应用程序的主头文件
=======
// demo3.h: demo3 应用程序的主头文件
>>>>>>> 9e554366a77ae3dcece734b3397a645223ff5948
//
#pragma once

#ifndef __AFXWIN_H__
	#error "在包含此文件之前包含 'pch.h' 以生成 PCH"
#endif

#include "resource.h"       // 主符号


<<<<<<< HEAD
// Cdraw3App:
// 有关此类的实现，请参阅 draw3.cpp
//

class Cdraw3App : public CWinApp
{
public:
	Cdraw3App() noexcept;
=======
// Cdemo3App:
// 有关此类的实现，请参阅 demo3.cpp
//

class Cdemo3App : public CWinApp
{
public:
	Cdemo3App() noexcept;
>>>>>>> 9e554366a77ae3dcece734b3397a645223ff5948


// 重写
public:
	virtual BOOL InitInstance();

// 实现
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

<<<<<<< HEAD
extern Cdraw3App theApp;
=======
extern Cdemo3App theApp;
>>>>>>> 9e554366a77ae3dcece734b3397a645223ff5948
