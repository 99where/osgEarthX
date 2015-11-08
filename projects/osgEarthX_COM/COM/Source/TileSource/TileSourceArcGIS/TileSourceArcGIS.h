// TileSourceArcGIS.h : CTileSourceArcGIS ������

#pragma once
#include "resource.h"       // ������



#include "osgEarthX_COM_i.h"



#if defined(_WIN32_WCE) && !defined(_CE_DCOM) && !defined(_CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA)
#error "Windows CE ƽ̨(�粻�ṩ��ȫ DCOM ֧�ֵ� Windows Mobile ƽ̨)���޷���ȷ֧�ֵ��߳� COM ���󡣶��� _CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA ��ǿ�� ATL ֧�ִ������߳� COM ����ʵ�ֲ�����ʹ���䵥�߳� COM ����ʵ�֡�rgs �ļ��е��߳�ģ���ѱ�����Ϊ��Free����ԭ���Ǹ�ģ���Ƿ� DCOM Windows CE ƽ̨֧�ֵ�Ψһ�߳�ģ�͡�"
#endif

using namespace ATL;

#include <COM/Source/SourceDispatchImpl.h>
#include <osgEarthDrivers/arcgis/ArcGISOptions>

// CTileSourceArcGIS
class CTileSourceArcGIS;
typedef 
	SourceDispatchImpl
	< 
	osgEarth::Drivers::ArcGISOptions, 
	CTileSourceArcGIS, 
	ITileSourceArcGIS,

	CLSID_TileSourceArcGIS,
	IID_ITileSourceArcGIS, 
	NULL, 
	CLSCTX_INPROC_SERVER,

	&LIBID_osgEarthX_COMLib, 
	/*wMajor =*/ 1, 
	/*wMinor =*/ 0 
	> 
	ITileSourceArcGISDispatchImpl;

class ATL_NO_VTABLE CTileSourceArcGIS :
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CTileSourceArcGIS, &CLSID_TileSourceArcGIS>,
	public ISupportErrorInfo,
	public ITileSourceArcGISDispatchImpl
{
public:
	//ITileSourceArcGIS
	STDMETHOD( get_url )( BSTR* pBstrUrl );
	STDMETHOD( put_url )( BSTR bstrUrl );

public:
	CTileSourceArcGIS() : ITileSourceArcGISDispatchImpl( TILE_SOURCE_ARCGIS )
	{
	}

DECLARE_REGISTRY_RESOURCEID(IDR_TILESOURCEARCGIS)


BEGIN_COM_MAP(CTileSourceArcGIS)
	COM_INTERFACE_ENTRY(ITileSourceArcGIS)
	COM_INTERFACE_ENTRY(ITileSourceDispatch)
	COM_INTERFACE_ENTRY(ISourceDispatch)
	COM_INTERFACE_ENTRY(IEarthDispatch)
	COM_INTERFACE_ENTRY2(IDispatch, ITileSourceArcGIS)
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

OBJECT_ENTRY_AUTO(__uuidof(TileSourceArcGIS), CTileSourceArcGIS)
