
// Demo_AtE_MFC_SDIDoc.cpp : CDemo_AtE_MFC_SDIDoc ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "Demo_AtE_MFC_SDI.h"
#endif

#include "Demo_AtE_MFC_SDIDoc.h"

#include <propkey.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CDemo_AtE_MFC_SDIDoc

IMPLEMENT_DYNCREATE(CDemo_AtE_MFC_SDIDoc, CDocument)

BEGIN_MESSAGE_MAP(CDemo_AtE_MFC_SDIDoc, CDocument)
END_MESSAGE_MAP()


// CDemo_AtE_MFC_SDIDoc ����/����

CDemo_AtE_MFC_SDIDoc::CDemo_AtE_MFC_SDIDoc()
{
	// TODO: �ڴ����һ���Թ������

}

CDemo_AtE_MFC_SDIDoc::~CDemo_AtE_MFC_SDIDoc()
{
}

BOOL CDemo_AtE_MFC_SDIDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: �ڴ�������³�ʼ������
	// (SDI �ĵ������ø��ĵ�)

	return TRUE;
}




// CDemo_AtE_MFC_SDIDoc ���л�

void CDemo_AtE_MFC_SDIDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: �ڴ���Ӵ洢����
	}
	else
	{
		// TODO: �ڴ���Ӽ��ش���
	}
}

#ifdef SHARED_HANDLERS

// ����ͼ��֧��
void CDemo_AtE_MFC_SDIDoc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
{
	// �޸Ĵ˴����Ի����ĵ�����
	dc.FillSolidRect(lprcBounds, RGB(255, 255, 255));

	CString strText = _T("TODO: implement thumbnail drawing here");
	LOGFONT lf;

	CFont* pDefaultGUIFont = CFont::FromHandle((HFONT) GetStockObject(DEFAULT_GUI_FONT));
	pDefaultGUIFont->GetLogFont(&lf);
	lf.lfHeight = 36;

	CFont fontDraw;
	fontDraw.CreateFontIndirect(&lf);

	CFont* pOldFont = dc.SelectObject(&fontDraw);
	dc.DrawText(strText, lprcBounds, DT_CENTER | DT_WORDBREAK);
	dc.SelectObject(pOldFont);
}

// ������������֧��
void CDemo_AtE_MFC_SDIDoc::InitializeSearchContent()
{
	CString strSearchContent;
	// ���ĵ����������������ݡ�
	// ���ݲ���Ӧ�ɡ�;���ָ�

	// ����:  strSearchContent = _T("point;rectangle;circle;ole object;")��
	SetSearchContent(strSearchContent);
}

void CDemo_AtE_MFC_SDIDoc::SetSearchContent(const CString& value)
{
	if (value.IsEmpty())
	{
		RemoveChunk(PKEY_Search_Contents.fmtid, PKEY_Search_Contents.pid);
	}
	else
	{
		CMFCFilterChunkValueImpl *pChunk = NULL;
		ATLTRY(pChunk = new CMFCFilterChunkValueImpl);
		if (pChunk != NULL)
		{
			pChunk->SetTextValue(PKEY_Search_Contents, value, CHUNK_TEXT);
			SetChunkValue(pChunk);
		}
	}
}

#endif // SHARED_HANDLERS

// CDemo_AtE_MFC_SDIDoc ���

#ifdef _DEBUG
void CDemo_AtE_MFC_SDIDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CDemo_AtE_MFC_SDIDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CDemo_AtE_MFC_SDIDoc ����
