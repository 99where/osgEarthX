
// Demo_AtE_MFC_SDIDoc.h : CDemo_AtE_MFC_SDIDoc ��Ľӿ�
//


#pragma once


class CDemo_AtE_MFC_SDIDoc : public CDocument
{
protected: // �������л�����
	CDemo_AtE_MFC_SDIDoc();
	DECLARE_DYNCREATE(CDemo_AtE_MFC_SDIDoc)

// ����
public:

// ����
public:

// ��д
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
#ifdef SHARED_HANDLERS
	virtual void InitializeSearchContent();
	virtual void OnDrawThumbnail(CDC& dc, LPRECT lprcBounds);
#endif // SHARED_HANDLERS

// ʵ��
public:
	virtual ~CDemo_AtE_MFC_SDIDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()

#ifdef SHARED_HANDLERS
	// ����Ϊ����������������������ݵ� Helper ����
	void SetSearchContent(const CString& value);
#endif // SHARED_HANDLERS
};
