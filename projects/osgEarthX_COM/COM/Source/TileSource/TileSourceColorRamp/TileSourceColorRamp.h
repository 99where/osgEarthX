// TileSourceColorRamp.h : CTileSourceColorRamp ������

#pragma once
#include "resource.h"       // ������



#include "osgEarthX_COM_i.h"



#if defined(_WIN32_WCE) && !defined(_CE_DCOM) && !defined(_CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA)
#error "Windows CE ƽ̨(�粻�ṩ��ȫ DCOM ֧�ֵ� Windows Mobile ƽ̨)���޷���ȷ֧�ֵ��߳� COM ���󡣶��� _CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA ��ǿ�� ATL ֧�ִ������߳� COM ����ʵ�ֲ�����ʹ���䵥�߳� COM ����ʵ�֡�rgs �ļ��е��߳�ģ���ѱ�����Ϊ��Free����ԭ���Ǹ�ģ���Ƿ� DCOM Windows CE ƽ̨֧�ֵ�Ψһ�߳�ģ�͡�"
#endif

using namespace ATL;

#include <COM/Source/SourceDispatchImpl.h>
#include <osgEarthDrivers/colorramp/ColorRampOptions>

// CTileSourceColorRamp
class CTileSourceColorRamp;
typedef 
	SourceDispatchImpl
	< 
	osgEarth::Drivers::ColorRampOptions, 
	CTileSourceColorRamp, 
	ITileSourceColorRamp, 

	CLSID_TileSourceColorRamp,
	IID_ITileSourceColorRamp, 
	NULL, 
	CLSCTX_INPROC_SERVER,

	&LIBID_osgEarthX_COMLib, 
	/*wMajor =*/ 1, 
	/*wMinor =*/ 0 
	> 
	ITileSourceColorRampDispatchImpl;

class ATL_NO_VTABLE CTileSourceColorRamp :
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CTileSourceColorRamp, &CLSID_TileSourceColorRamp>,
	public ISupportErrorInfo,
	public ITileSourceColorRampDispatchImpl
{
public:
	CTileSourceColorRamp() : ITileSourceColorRampDispatchImpl( TILE_SOURCE_COLOR_RAMP )
	{
	}

DECLARE_REGISTRY_RESOURCEID(IDR_TILESOURCECOLORRAMP)


BEGIN_COM_MAP(CTileSourceColorRamp)
	COM_INTERFACE_ENTRY(ITileSourceColorRamp)
	COM_INTERFACE_ENTRY(ITileSourceDispatch)
	COM_INTERFACE_ENTRY(ISourceDispatch)
	COM_INTERFACE_ENTRY(IEarthDispatch)
	COM_INTERFACE_ENTRY2(IDispatch, ITileSourceColorRamp)
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

OBJECT_ENTRY_AUTO(__uuidof(TileSourceColorRamp), CTileSourceColorRamp)
