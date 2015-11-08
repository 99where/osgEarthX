// Place.h : CPlace ������

#pragma once
#include "resource.h"       // ������



#include "osgEarthX_COM_i.h"



#if defined(_WIN32_WCE) && !defined(_CE_DCOM) && !defined(_CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA)
#error "Windows CE ƽ̨(�粻�ṩ��ȫ DCOM ֧�ֵ� Windows Mobile ƽ̨)���޷���ȷ֧�ֵ��߳� COM ���󡣶��� _CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA ��ǿ�� ATL ֧�ִ������߳� COM ����ʵ�ֲ�����ʹ���䵥�߳� COM ����ʵ�֡�rgs �ļ��е��߳�ģ���ѱ�����Ϊ��Free����ԭ���Ǹ�ģ���Ƿ� DCOM Windows CE ƽ̨֧�ֵ�Ψһ�߳�ģ�͡�"
#endif

using namespace ATL;

#include <COM/EarthObject/EarthObjectDispatchImpl.h>

//osgEarthX
#include <Annotation/Place.h>

// CPlace
class CPlace;
typedef 
	EarthObjectDispatchImpl
	< 
	osgEarthX::Place, 
	CPlace, 
	IPlace, 

	CLSID_Place,
	IID_IPlace, 
	NULL, 
	CLSCTX_INPROC_SERVER,

	&LIBID_osgEarthX_COMLib, 
	/*wMajor =*/ 1, 
	/*wMinor =*/ 0 
	> 
	IPlaceDispatchImpl;

class ATL_NO_VTABLE CPlace :
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CPlace, &CLSID_Place>,
	public ISupportErrorInfo,
	public IPlaceDispatchImpl
{
public:
	//IPlace
	STDMETHOD( setPosition )( IGeoPoint * pIGeoPoint );
	STDMETHOD( getPosition )( IGeoPoint ** pIGeoPoint );
	STDMETHOD( setText )( BSTR strText );
	STDMETHOD( getText )( BSTR * pStrText );
	STDMETHOD( setImageSrc )( BSTR strImageSrc );

public:
	CPlace() : IPlaceDispatchImpl( ANNOTATION_PLACE )
	{
	}

DECLARE_REGISTRY_RESOURCEID(IDR_PLACE)


BEGIN_COM_MAP(CPlace)
	COM_INTERFACE_ENTRY(IPlace)
	COM_INTERFACE_ENTRY(IEarthObject)
	COM_INTERFACE_ENTRY(IEarthDispatch)
	COM_INTERFACE_ENTRY2(IDispatch, IPlace)
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

OBJECT_ENTRY_AUTO(__uuidof(Place), CPlace)
