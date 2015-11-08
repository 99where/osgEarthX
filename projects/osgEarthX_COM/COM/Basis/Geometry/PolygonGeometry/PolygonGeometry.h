// PolygonGeometry.h : CPolygonGeometry ������

#pragma once
#include "resource.h"       // ������



#include "osgEarthX_COM_i.h"



#if defined(_WIN32_WCE) && !defined(_CE_DCOM) && !defined(_CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA)
#error "Windows CE ƽ̨(�粻�ṩ��ȫ DCOM ֧�ֵ� Windows Mobile ƽ̨)���޷���ȷ֧�ֵ��߳� COM ���󡣶��� _CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA ��ǿ�� ATL ֧�ִ������߳� COM ����ʵ�ֲ�����ʹ���䵥�߳� COM ����ʵ�֡�rgs �ļ��е��߳�ģ���ѱ�����Ϊ��Free����ԭ���Ǹ�ģ���Ƿ� DCOM Windows CE ƽ̨֧�ֵ�Ψһ�߳�ģ�͡�"
#endif

using namespace ATL;

#include <COM/Basis/Geometry/RingGeometry/RingGeometryDispatchImpl.h>
#include <osgEarthSymbology/Geometry>

// CPolygonGeometry
class CPolygonGeometry;
typedef 
	RingGeometryDispatchImpl
	< 
	osgEarth::Symbology::Polygon, 
	CPolygonGeometry, 
	IPolygonGeometry, 

	CLSID_PolygonGeometry,
	IID_IPolygonGeometry, 
	NULL, 
	CLSCTX_INPROC_SERVER,

	&LIBID_osgEarthX_COMLib, 
	/*wMajor =*/ 1, 
	/*wMinor =*/ 0
	> 
	IPolygonGeometryDispatchImpl;

class ATL_NO_VTABLE CPolygonGeometry :
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CPolygonGeometry, &CLSID_PolygonGeometry>,
	public ISupportErrorInfo,
	public IPolygonGeometryDispatchImpl
{
public:
	CPolygonGeometry(): IPolygonGeometryDispatchImpl( GEOMETRY_CLASS_POLYGON )
	{
	}

DECLARE_REGISTRY_RESOURCEID(IDR_POLYGONGEOMETRY)


BEGIN_COM_MAP(CPolygonGeometry)
	COM_INTERFACE_ENTRY(IPolygonGeometry)
	COM_INTERFACE_ENTRY(IRingGeometry)
	COM_INTERFACE_ENTRY(IGeometry)
	COM_INTERFACE_ENTRY(IEarthDispatch)
	COM_INTERFACE_ENTRY2(IDispatch,IPolygonGeometry)
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

OBJECT_ENTRY_AUTO(__uuidof(PolygonGeometry), CPolygonGeometry)
