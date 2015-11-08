
// Demo_AtEC_MFC_SDIView.cpp : CDemo_AtEC_MFC_SDIView ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "Demo_AtEC_MFC_SDI.h"
#endif

#include "Demo_AtEC_MFC_SDIDoc.h"
#include "Demo_AtEC_MFC_SDIView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

#include <osgEarthDrivers/gdal/GDALOptions>

#include <osgViewer/Viewer>
#include <Viewer/Win32ViewerT.h>

// CDemo_AtEC_MFC_SDIView

IMPLEMENT_DYNCREATE(CDemo_AtEC_MFC_SDIView, CView)

BEGIN_MESSAGE_MAP(CDemo_AtEC_MFC_SDIView, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_COMMAND(ID_EXTERNALS_GRATICULE, &CDemo_AtEC_MFC_SDIView::OnExternalsGraticule)
	ON_COMMAND(ID_EXTERNALS_SKY, &CDemo_AtEC_MFC_SDIView::OnExternalsSky)
END_MESSAGE_MAP()

// CDemo_AtEC_MFC_SDIView ����/����

CDemo_AtEC_MFC_SDIView::CDemo_AtEC_MFC_SDIView()
{
	// TODO: �ڴ˴���ӹ������
	m_refMap = new AtEarthCore::Map();
	m_refMapViewer = new AtEarthCore::MapViewer();

	m_refMap->setMaxThreadsNum( 10 );
	m_refMapViewer->setMap( m_refMap );

	AtEarthCore::ImageLayerProvider* pImageLayerProvider = new AtEarthCore::ImageLayerProvider();
	osgEarth::Drivers::GDALOptions gdal;
	gdal.url() = "E:\\OpenSceneGraph\\AtEarth\\environment\\data\\world.tif";
	pImageLayerProvider->setTileSource( gdal );
	m_refMap->addImageLayerProvider( pImageLayerProvider );
}

CDemo_AtEC_MFC_SDIView::~CDemo_AtEC_MFC_SDIView()
{
	m_refMapViewer = NULL;
	m_refMap = NULL;
}

BOOL CDemo_AtEC_MFC_SDIView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CDemo_AtEC_MFC_SDIView ����

void CDemo_AtEC_MFC_SDIView::OnDraw(CDC* /*pDC*/)
{
	CDemo_AtEC_MFC_SDIDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}


// CDemo_AtEC_MFC_SDIView ��ӡ

BOOL CDemo_AtEC_MFC_SDIView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CDemo_AtEC_MFC_SDIView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CDemo_AtEC_MFC_SDIView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
}


// CDemo_AtEC_MFC_SDIView ���

#ifdef _DEBUG
void CDemo_AtEC_MFC_SDIView::AssertValid() const
{
	CView::AssertValid();
}

void CDemo_AtEC_MFC_SDIView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CDemo_AtEC_MFC_SDIDoc* CDemo_AtEC_MFC_SDIView::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CDemo_AtEC_MFC_SDIDoc)));
	return (CDemo_AtEC_MFC_SDIDoc*)m_pDocument;
}
#endif //_DEBUG


// CDemo_AtEC_MFC_SDIView ��Ϣ�������


void CDemo_AtEC_MFC_SDIView::OnInitialUpdate()
{
	CView::OnInitialUpdate();

	// TODO: �ڴ����ר�ô����/����û���
	AtEarthCore::Win32ViewerT< osgViewer::Viewer >* pViewer = new AtEarthCore::Win32ViewerT< osgViewer::Viewer >();
	pViewer->setCameraGraphicsWindow( pViewer->getCamera(), m_hWnd );
	m_refMapViewer->setViewer( pViewer );
	m_refMapViewer->run();
}


void CDemo_AtEC_MFC_SDIView::OnExternalsGraticule()
{
	// TODO: �ڴ���������������
	m_refMap->setGraticuleProvider( new AtEarthCore::GraticuleProvider() );
}


void CDemo_AtEC_MFC_SDIView::OnExternalsSky()
{
	// TODO: �ڴ���������������
	m_refMap->setSkyProvider( new AtEarthCore::SkyProvider() );
}
