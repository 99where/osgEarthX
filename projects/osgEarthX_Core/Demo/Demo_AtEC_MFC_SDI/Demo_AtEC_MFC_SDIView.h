
// Demo_AtEC_MFC_SDIView.h : CDemo_AtEC_MFC_SDIView ��Ľӿ�
//

#pragma once

//AT_Earth_Core
#include <Map/Map.h>
#include <Viewer/MapViewer.h>

class CDemo_AtEC_MFC_SDIView : public CView
{
private:
	osg::ref_ptr<AtEarthCore::Map> m_refMap;
	osg::ref_ptr<AtEarthCore::MapViewer> m_refMapViewer;

protected: // �������л�����
	CDemo_AtEC_MFC_SDIView();
	DECLARE_DYNCREATE(CDemo_AtEC_MFC_SDIView)

// ����
public:
	CDemo_AtEC_MFC_SDIDoc* GetDocument() const;

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
	virtual ~CDemo_AtEC_MFC_SDIView();
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
	afx_msg void OnExternalsGraticule();
	afx_msg void OnExternalsSky();
};

#ifndef _DEBUG  // Demo_AtEC_MFC_SDIView.cpp �еĵ��԰汾
inline CDemo_AtEC_MFC_SDIDoc* CDemo_AtEC_MFC_SDIView::GetDocument() const
   { return reinterpret_cast<CDemo_AtEC_MFC_SDIDoc*>(m_pDocument); }
#endif

