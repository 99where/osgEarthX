// SpatialReference.h : CSpatialReference ������

#pragma once
#include "resource.h"       // ������



#include "osgEarthX_COM_i.h"



#if defined(_WIN32_WCE) && !defined(_CE_DCOM) && !defined(_CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA)
#error "Windows CE ƽ̨(�粻�ṩ��ȫ DCOM ֧�ֵ� Windows Mobile ƽ̨)���޷���ȷ֧�ֵ��߳� COM ���󡣶��� _CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA ��ǿ�� ATL ֧�ִ������߳� COM ����ʵ�ֲ�����ʹ���䵥�߳� COM ����ʵ�֡�rgs �ļ��е��߳�ģ���ѱ�����Ϊ��Free����ԭ���Ǹ�ģ���Ƿ� DCOM Windows CE ƽ̨֧�ֵ�Ψһ�߳�ģ�͡�"
#endif

using namespace ATL;

#include <COM/Earth/RefEarthDispatchImpl.h>
#include <osgEarth/SpatialReference>

class CSpatialReference;
// CSpatialReference
typedef 
	RefEarthDispatchImpl
	< 
	GeoClassType, 
	const osgEarth::SpatialReference, 
	CSpatialReference, 
	ISpatialReference, 

	CLSID_SpatialReference,
	IID_ISpatialReference, 
	NULL, 
	CLSCTX_INPROC_SERVER,

	&LIBID_osgEarthX_COMLib, 
	/*wMajor =*/ 1, 
	/*wMinor =*/ 0
	> ISpatialReferenceDispatchImpl;

class ATL_NO_VTABLE CSpatialReference :
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CSpatialReference, &CLSID_SpatialReference>,
	public ISupportErrorInfo,
	public ISpatialReferenceDispatchImpl
{
public:
	CSpatialReference(): ISpatialReferenceDispatchImpl( GEO_CLASS_SPATIAL_REFERENCE )
	{
	}

DECLARE_REGISTRY_RESOURCEID(IDR_SPATIALREFERENCE)


BEGIN_COM_MAP(CSpatialReference)
	COM_INTERFACE_ENTRY(ISpatialReference)
	COM_INTERFACE_ENTRY(IEarthDispatch)
	COM_INTERFACE_ENTRY2(IDispatch,ISpatialReference)
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

OBJECT_ENTRY_AUTO(__uuidof(SpatialReference), CSpatialReference)
