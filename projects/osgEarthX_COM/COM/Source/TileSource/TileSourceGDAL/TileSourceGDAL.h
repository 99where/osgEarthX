// TileSourceGDAL.h : CTileSourceGDAL ������

#pragma once
#include "resource.h"       // ������



#include "osgEarthX_COM_i.h"



#if defined(_WIN32_WCE) && !defined(_CE_DCOM) && !defined(_CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA)
#error "Windows CE ƽ̨(�粻�ṩ��ȫ DCOM ֧�ֵ� Windows Mobile ƽ̨)���޷���ȷ֧�ֵ��߳� COM ���󡣶��� _CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA ��ǿ�� ATL ֧�ִ������߳� COM ����ʵ�ֲ�����ʹ���䵥�߳� COM ����ʵ�֡�rgs �ļ��е��߳�ģ���ѱ�����Ϊ��Free����ԭ���Ǹ�ģ���Ƿ� DCOM Windows CE ƽ̨֧�ֵ�Ψһ�߳�ģ�͡�"
#endif

using namespace ATL;

#include <COM/Source/SourceDispatchImpl.h>
#include <osgEarthDrivers/gdal/GDALOptions>

// CTileSourceGDAL
class CTileSourceGDAL;
typedef 
	SourceDispatchImpl
	< 
	osgEarth::Drivers::GDALOptions, 
	CTileSourceGDAL, 
	ITileSourceGDAL, 

	CLSID_TileSourceGDAL,
	IID_ITileSourceGDAL, 
	NULL, 
	CLSCTX_INPROC_SERVER,

	&LIBID_osgEarthX_COMLib, 
	/*wMajor =*/ 1, 
	/*wMinor =*/ 0 
	> 
	ITileSourceGDALDispatchImpl;

class ATL_NO_VTABLE CTileSourceGDAL :
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CTileSourceGDAL, &CLSID_TileSourceGDAL>,
	public ISupportErrorInfo,
	public ITileSourceGDALDispatchImpl
{
public:
	//ITileSourceGDAL
	STDMETHOD( get_url )( BSTR* pBstrUrl );
	STDMETHOD( put_url )( BSTR bstrUrl );

public:
	CTileSourceGDAL() : ITileSourceGDALDispatchImpl( TILE_SOURCE_GDAL )
	{
	}

DECLARE_REGISTRY_RESOURCEID(IDR_TILESOURCEGDAL)


BEGIN_COM_MAP(CTileSourceGDAL)
	COM_INTERFACE_ENTRY(ITileSourceGDAL)
	COM_INTERFACE_ENTRY(ITileSourceDispatch)
	COM_INTERFACE_ENTRY(ISourceDispatch)
	COM_INTERFACE_ENTRY(IEarthDispatch)
	COM_INTERFACE_ENTRY2(IDispatch, ITileSourceGDAL)
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

OBJECT_ENTRY_AUTO(__uuidof(TileSourceGDAL), CTileSourceGDAL)
