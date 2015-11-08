// GeoPoint.h : CGeoPoint ������

#pragma once
#include "resource.h"       // ������



#include "osgEarthX_COM_i.h"



#if defined(_WIN32_WCE) && !defined(_CE_DCOM) && !defined(_CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA)
#error "Windows CE ƽ̨(�粻�ṩ��ȫ DCOM ֧�ֵ� Windows Mobile ƽ̨)���޷���ȷ֧�ֵ��߳� COM ���󡣶��� _CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA ��ǿ�� ATL ֧�ִ������߳� COM ����ʵ�ֲ�����ʹ���䵥�߳� COM ����ʵ�֡�rgs �ļ��е��߳�ģ���ѱ�����Ϊ��Free����ԭ���Ǹ�ģ���Ƿ� DCOM Windows CE ƽ̨֧�ֵ�Ψһ�߳�ģ�͡�"
#endif

using namespace ATL;

#include <COM/Earth/PtrEarthDispatchImpl.h>
#include <osgEarth/GeoData>

class CGeoPoint;
// CGeoPoint
typedef 
	PtrEarthDispatchImpl
	< 
	GeoClassType, 
	osgEarth::GeoPoint, 
	CGeoPoint, 
	IGeoPoint, 

	CLSID_GeoPoint,
	IID_IGeoPoint, 
	NULL, 
	CLSCTX_INPROC_SERVER,

	&LIBID_osgEarthX_COMLib, 
	/*wMajor =*/ 1, 
	/*wMinor =*/ 0
	> 
	IGeoPointDispatchImpl;

class ATL_NO_VTABLE CGeoPoint :
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CGeoPoint, &CLSID_GeoPoint>,
	public ISupportErrorInfo,
	public IGeoPointDispatchImpl
{
public:
	STDMETHOD( put_x )( DOUBLE dX );
	STDMETHOD( get_x )( DOUBLE *pX );
	STDMETHOD( put_y )( DOUBLE dY );
	STDMETHOD( get_y )( DOUBLE *pY );
	STDMETHOD( put_z )( DOUBLE dZ );
	STDMETHOD( get_z )( DOUBLE *pZ );
	STDMETHOD( put_srs )( ISpatialReference* pISpatialReference );
	STDMETHOD( get_srs )( ISpatialReference** ppISpatialReference );

public:
	CGeoPoint() : IGeoPointDispatchImpl( GEO_CLASS_GEO_POINT )
	{
	}

DECLARE_REGISTRY_RESOURCEID(IDR_GEOPOINT)


BEGIN_COM_MAP(CGeoPoint)
	COM_INTERFACE_ENTRY(IGeoPoint)
	COM_INTERFACE_ENTRY(IEarthDispatch)
	COM_INTERFACE_ENTRY2(IDispatch, IGeoPoint)
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

OBJECT_ENTRY_AUTO(__uuidof(GeoPoint), CGeoPoint)
