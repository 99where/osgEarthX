
// Demo_AtE_MFC_SDI.h : Demo_AtE_MFC_SDI Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������


// CDemo_AtE_MFC_SDIApp:
// �йش����ʵ�֣������ Demo_AtE_MFC_SDI.cpp
//

class CDemo_AtE_MFC_SDIApp : public CWinApp
{
public:
	CDemo_AtE_MFC_SDIApp();


// ��д
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// ʵ��
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CDemo_AtE_MFC_SDIApp theApp;
