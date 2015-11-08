// TileSourceWMS.h : CTileSourceWMS ������

#pragma once
#include "resource.h"       // ������



#include "osgEarthX_COM_i.h"



#if defined(_WIN32_WCE) && !defined(_CE_DCOM) && !defined(_CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA)
#error "Windows CE ƽ̨(�粻�ṩ��ȫ DCOM ֧�ֵ� Windows Mobile ƽ̨)���޷���ȷ֧�ֵ��߳� COM ���󡣶��� _CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA ��ǿ�� ATL ֧�ִ������߳� COM ����ʵ�ֲ�����ʹ���䵥�߳� COM ����ʵ�֡�rgs �ļ��е��߳�ģ���ѱ�����Ϊ��Free����ԭ���Ǹ�ģ���Ƿ� DCOM Windows CE ƽ̨֧�ֵ�Ψһ�߳�ģ�͡�"
#endif

using namespace ATL;

#include <COM/Source/SourceDispatchImpl.h>
#include <osgEarth/URI>
#include <osgEarthDrivers/wms/WMSOptions>

// CTileSourceWMS
class CTileSourceWMS;
typedef 
	SourceDispatchImpl
	< 
	osgEarth::Drivers::WMSOptions,
	CTileSourceWMS, 
	ITileSourceWMS, 

	CLSID_TileSourceWMS,
	IID_ITileSourceWMS, 
	NULL, 
	CLSCTX_INPROC_SERVER,

	&LIBID_osgEarthX_COMLib, 
	/*wMajor =*/ 1, 
	/*wMinor =*/ 0 
	> 
	ITileSourceWMSDispatchImpl;

class ATL_NO_VTABLE CTileSourceWMS :
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CTileSourceWMS, &CLSID_TileSourceWMS>,
	public ISupportErrorInfo,
	public ITileSourceWMSDispatchImpl
{
public:
	CTileSourceWMS() : ITileSourceWMSDispatchImpl( TILE_SOURCE_WMS )
	{
	}

DECLARE_REGISTRY_RESOURCEID(IDR_TILESOURCEWMS)


BEGIN_COM_MAP(CTileSourceWMS)
	COM_INTERFACE_ENTRY(ITileSourceWMS)
	COM_INTERFACE_ENTRY(ITileSourceDispatch)
	COM_INTERFACE_ENTRY(ISourceDispatch)
	COM_INTERFACE_ENTRY(IEarthDispatch)
	COM_INTERFACE_ENTRY2(IDispatch, ITileSourceWMS)
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

OBJECT_ENTRY_AUTO(__uuidof(TileSourceWMS), CTileSourceWMS)
