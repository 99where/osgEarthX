
// Demo_AtEC_MFC_SDI.h : Demo_AtEC_MFC_SDI Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������


// CDemo_AtEC_MFC_SDIApp:
// �йش����ʵ�֣������ Demo_AtEC_MFC_SDI.cpp
//

class CDemo_AtEC_MFC_SDIApp : public CWinApp
{
public:
	CDemo_AtEC_MFC_SDIApp();


// ��д
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// ʵ��
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CDemo_AtEC_MFC_SDIApp theApp;
