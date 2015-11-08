
// Demo_AtE_MFC_SDIView.h : CDemo_AtE_MFC_SDIView ��Ľӿ�
//

#pragma once

//AT_Earth
#include <Earth/Earth.h>

class CDemo_AtE_MFC_SDIView : public CView
{
private:
	osg::ref_ptr<AtEarth::Earth> m_refEarth;

protected: // �������л�����
	CDemo_AtE_MFC_SDIView();
	DECLARE_DYNCREATE(CDemo_AtE_MFC_SDIView)

// ����
public:
	CDemo_AtE_MFC_SDIDoc* GetDocument() const;

// ����
public:

// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// ʵ��
public:
	virtual ~CDemo_AtE_MFC_SDIView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
public:
	virtual void OnInitialUpdate();
};

#ifndef _DEBUG  // Demo_AtE_MFC_SDIView.cpp �еĵ��԰汾
inline CDemo_AtE_MFC_SDIDoc* CDemo_AtE_MFC_SDIView::GetDocument() const
   { return reinterpret_cast<CDemo_AtE_MFC_SDIDoc*>(m_pDocument); }
#endif

