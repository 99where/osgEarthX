// TileSourceTileCache.h : CTileSourceTileCache ������

#pragma once
#include "resource.h"       // ������



#include "osgEarthX_COM_i.h"



#if defined(_WIN32_WCE) && !defined(_CE_DCOM) && !defined(_CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA)
#error "Windows CE ƽ̨(�粻�ṩ��ȫ DCOM ֧�ֵ� Windows Mobile ƽ̨)���޷���ȷ֧�ֵ��߳� COM ���󡣶��� _CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA ��ǿ�� ATL ֧�ִ������߳� COM ����ʵ�ֲ�����ʹ���䵥�߳� COM ����ʵ�֡�rgs �ļ��е��߳�ģ���ѱ�����Ϊ��Free����ԭ���Ǹ�ģ���Ƿ� DCOM Windows CE ƽ̨֧�ֵ�Ψһ�߳�ģ�͡�"
#endif

using namespace ATL;

#include <COM/Source/SourceDispatchImpl.h>
#include <osgEarth/URI>
#include <osgEarthDrivers/tilecache/TileCacheOptions>

// CTileSourceTileCache
class CTileSourceTileCache;
typedef 
	SourceDispatchImpl
	< 
	osgEarth::Drivers::TileCacheOptions, 
	CTileSourceTileCache, 
	ITileSourceTileCache,

	CLSID_TileSourceTileCache,
	IID_ITileSourceTileCache, 
	NULL, 
	CLSCTX_INPROC_SERVER,

	&LIBID_osgEarthX_COMLib, 
	/*wMajor =*/ 1, 
	/*wMinor =*/ 0 
	> 
	ITileSourceTileCacheDispatchImpl;

class ATL_NO_VTABLE CTileSourceTileCache :
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CTileSourceTileCache, &CLSID_TileSourceTileCache>,
	public ISupportErrorInfo,
	public ITileSourceTileCacheDispatchImpl
{
public:
	CTileSourceTileCache() : ITileSourceTileCacheDispatchImpl( TILE_SOURCE_TILE_CACHE )
	{
	}

DECLARE_REGISTRY_RESOURCEID(IDR_TILESOURCETILECACHE)


BEGIN_COM_MAP(CTileSourceTileCache)
	COM_INTERFACE_ENTRY(ITileSourceTileCache)
	COM_INTERFACE_ENTRY(ITileSourceDispatch)
	COM_INTERFACE_ENTRY(ISourceDispatch)
	COM_INTERFACE_ENTRY(IEarthDispatch)
	COM_INTERFACE_ENTRY2(IDispatch, ITileSourceTileCache)
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

OBJECT_ENTRY_AUTO(__uuidof(TileSourceTileCache), CTileSourceTileCache)
