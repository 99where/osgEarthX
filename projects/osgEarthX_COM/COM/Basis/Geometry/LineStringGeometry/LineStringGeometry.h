// LineStringGeometry.h : CLineStringGeometry ������

#pragma once
#include "resource.h"       // ������



#include "osgEarthX_COM_i.h"



#if defined(_WIN32_WCE) && !defined(_CE_DCOM) && !defined(_CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA)
#error "Windows CE ƽ̨(�粻�ṩ��ȫ DCOM ֧�ֵ� Windows Mobile ƽ̨)���޷���ȷ֧�ֵ��߳� COM ���󡣶��� _CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA ��ǿ�� ATL ֧�ִ������߳� COM ����ʵ�ֲ�����ʹ���䵥�߳� COM ����ʵ�֡�rgs �ļ��е��߳�ģ���ѱ�����Ϊ��Free����ԭ���Ǹ�ģ���Ƿ� DCOM Windows CE ƽ̨֧�ֵ�Ψһ�߳�ģ�͡�"
#endif

using namespace ATL;

#include <COM/Basis/Geometry/Geometry/GeometryDispatchImpl.h>
#include <osgEarthSymbology/Geometry>

// CLineStringGeometry
class CLineStringGeometry;
typedef 
	GeometryDispatchImpl
	< 
	osgEarth::Symbology::LineString, 
	CLineStringGeometry, 
	ILineStringGeometry, 

	CLSID_LineStringGeometry,
	IID_ILineStringGeometry, 
	NULL, 
	CLSCTX_INPROC_SERVER,

	&LIBID_osgEarthX_COMLib, 
	/*wMajor =*/ 1, 
	/*wMinor =*/ 0
	> 
	ILineStringDispatchImpl;

class ATL_NO_VTABLE CLineStringGeometry :
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CLineStringGeometry, &CLSID_LineStringGeometry>,
	public ISupportErrorInfo,
	public ILineStringDispatchImpl
{
public:
	CLineStringGeometry():ILineStringDispatchImpl( GEOMETRY_CLASS_LINESTRING )
	{
	}

DECLARE_REGISTRY_RESOURCEID(IDR_LINESTRINGGEOMETRY)


BEGIN_COM_MAP(CLineStringGeometry)
	COM_INTERFACE_ENTRY(ILineStringGeometry)
	COM_INTERFACE_ENTRY(IGeometry)
	COM_INTERFACE_ENTRY(IEarthDispatch)
	COM_INTERFACE_ENTRY2(IDispatch,ILineStringGeometry)
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

OBJECT_ENTRY_AUTO(__uuidof(LineStringGeometry), CLineStringGeometry)
