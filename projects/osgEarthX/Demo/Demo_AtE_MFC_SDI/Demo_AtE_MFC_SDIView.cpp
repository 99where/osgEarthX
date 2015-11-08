
// Demo_AtE_MFC_SDIView.cpp : CDemo_AtE_MFC_SDIView ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "Demo_AtE_MFC_SDI.h"
#endif

#include "Demo_AtE_MFC_SDIDoc.h"
#include "Demo_AtE_MFC_SDIView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

#include <Viewer/Win32ViewerT.h>

// CDemo_AtE_MFC_SDIView

IMPLEMENT_DYNCREATE(CDemo_AtE_MFC_SDIView, CView)

BEGIN_MESSAGE_MAP(CDemo_AtE_MFC_SDIView, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
END_MESSAGE_MAP()

// CDemo_AtE_MFC_SDIView ����/����

CDemo_AtE_MFC_SDIView::CDemo_AtE_MFC_SDIView()
{
	// TODO: �ڴ˴���ӹ������
	m_refEarth = new AtEarth::Earth();
}

CDemo_AtE_MFC_SDIView::~CDemo_AtE_MFC_SDIView()
{
}

BOOL CDemo_AtE_MFC_SDIView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CDemo_AtE_MFC_SDIView ����

void CDemo_AtE_MFC_SDIView::OnDraw(CDC* /*pDC*/)
{
	CDemo_AtE_MFC_SDIDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}


// CDemo_AtE_MFC_SDIView ��ӡ

BOOL CDemo_AtE_MFC_SDIView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CDemo_AtE_MFC_SDIView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CDemo_AtE_MFC_SDIView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
}


// CDemo_AtE_MFC_SDIView ���

#ifdef _DEBUG
void CDemo_AtE_MFC_SDIView::AssertValid() const
{
	CView::AssertValid();
}

void CDemo_AtE_MFC_SDIView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CDemo_AtE_MFC_SDIDoc* CDemo_AtE_MFC_SDIView::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CDemo_AtE_MFC_SDIDoc)));
	return (CDemo_AtE_MFC_SDIDoc*)m_pDocument;
}
#endif //_DEBUG


// CDemo_AtE_MFC_SDIView ��Ϣ�������


void CDemo_AtE_MFC_SDIView::OnInitialUpdate()
{
	CView::OnInitialUpdate();

	// TODO: �ڴ����ר�ô����/����û���
	AtEarthCore::Win32ViewerT< osgViewer::Viewer >* pViewerContext = new AtEarthCore::Win32ViewerT< osgViewer::Viewer >( true );
	pViewerContext->setCameraGraphicsWindow( pViewerContext->getCamera(), m_hWnd );
	m_refEarth->getEarthViewer()->setViewer( pViewerContext );
	m_refEarth->run();
}
