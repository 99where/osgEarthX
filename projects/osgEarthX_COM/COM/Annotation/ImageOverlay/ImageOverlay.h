// ImageOverlay.h : CImageOverlay ������

#pragma once
#include "resource.h"       // ������



#include "osgEarthX_COM_i.h"



#if defined(_WIN32_WCE) && !defined(_CE_DCOM) && !defined(_CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA)
#error "Windows CE ƽ̨(�粻�ṩ��ȫ DCOM ֧�ֵ� Windows Mobile ƽ̨)���޷���ȷ֧�ֵ��߳� COM ���󡣶��� _CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA ��ǿ�� ATL ֧�ִ������߳� COM ����ʵ�ֲ�����ʹ���䵥�߳� COM ����ʵ�֡�rgs �ļ��е��߳�ģ���ѱ�����Ϊ��Free����ԭ���Ǹ�ģ���Ƿ� DCOM Windows CE ƽ̨֧�ֵ�Ψһ�߳�ģ�͡�"
#endif

using namespace ATL;

#include <COM/EarthObject/EarthObjectDispatchImpl.h>

//osgEarthX
#include <Annotation/ImageOverlay.h>

// CImageOverlay
class CImageOverlay;
typedef 
	EarthObjectDispatchImpl
	< 
	osgEarthX::ImageOverlay, 
	CImageOverlay, 
	IImageOverlay, 

	CLSID_ImageOverlay,
	IID_IImageOverlay, 
	NULL, 
	CLSCTX_INPROC_SERVER,

	&LIBID_osgEarthX_COMLib, 
	/*wMajor =*/ 1, 
	/*wMinor =*/ 0
	> 
	IImageOverlayDispatchImpl;

class ATL_NO_VTABLE CImageOverlay :
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CImageOverlay, &CLSID_ImageOverlay>,
	public ISupportErrorInfo,
	public IImageOverlayDispatchImpl
{
public:
	STDMETHOD( setImageSrc )( BSTR bstrImgSrc );
	STDMETHOD( setBounds )( DOUBLE lowerLeftX, DOUBLE lowerLeftY, DOUBLE upperRightX, DOUBLE upperRightY );

public:
	CImageOverlay() : IImageOverlayDispatchImpl( ANNOTATION_IMAGE_OVERLAY )
	{
	}

DECLARE_REGISTRY_RESOURCEID(IDR_IMAGEOVERLAY)


BEGIN_COM_MAP(CImageOverlay)
	COM_INTERFACE_ENTRY(IImageOverlay)
	COM_INTERFACE_ENTRY(IEarthObject)
	COM_INTERFACE_ENTRY(IEarthDispatch)
	COM_INTERFACE_ENTRY2(IDispatch, IImageOverlay)
	COM_INTERFACE_ENTRY(ISupportErrorInfo)
END_COM_MAP()

// ISupportsErrorInfo
	STDMETHOD(InterfaceSupportsErrorInfo)(REFIID riid);


	DECLARE_PROTECT_FINAL_CONSTRUCT()

	HRESULT FinalConstruct()
	{
		return S_OK;
	}

	void FinalRelease()
	{
	}

public:



};

OBJECT_ENTRY_AUTO(__uuidof(ImageOverlay), CImageOverlay)
