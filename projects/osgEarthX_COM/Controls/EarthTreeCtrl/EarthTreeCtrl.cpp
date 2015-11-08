// EarthTreeCtrl.cpp : CEarthTreeCtrl ��ʵ��
#include "stdafx.h"
#include "EarthTreeCtrl.h"

#include <Controls/EarthCtrl/EarthCtrl.h>

// CEarthTreeCtrl


LRESULT CEarthTreeCtrl::OnCreate(UINT /*uMsg*/, WPARAM /*wParam*/, LPARAM /*lParam*/, BOOL& /*bHandled*/)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	RECT rc;
	this->GetWindowRect(&rc);
	m_EarthTreeView.Create(this->m_hWnd, rc, _T(""),WS_CHILD | WS_VISIBLE | WS_CLIPCHILDREN );
	m_EarthTreeView.ShowWindow(SW_SHOW);
	return 0;
}

LRESULT CEarthTreeCtrl::OnSize(UINT /*uMsg*/, WPARAM /*wParam*/, LPARAM lParam, BOOL& /*bHandled*/)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	m_EarthTreeView.MoveWindow(0, 0, LOWORD(lParam), HIWORD(lParam));
	return 0;
}


STDMETHODIMP CEarthTreeCtrl::bindEarthCtrl(IEarthCtrl* pIEarthCtrl)
{
	CEarthCtrl* pEarthCtrl = dynamic_cast<CEarthCtrl*>(pIEarthCtrl);
	if (pIEarthCtrl)
	{

	}

	return S_OK;
}