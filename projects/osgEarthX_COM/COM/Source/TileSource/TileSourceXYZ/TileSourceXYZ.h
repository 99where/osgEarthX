// TileSourceXYZ.h : CTileSourceXYZ ������

#pragma once
#include "resource.h"       // ������



#include "osgEarthX_COM_i.h"



#if defined(_WIN32_WCE) && !defined(_CE_DCOM) && !defined(_CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA)
#error "Windows CE ƽ̨(�粻�ṩ��ȫ DCOM ֧�ֵ� Windows Mobile ƽ̨)���޷���ȷ֧�ֵ��߳� COM ���󡣶��� _CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA ��ǿ�� ATL ֧�ִ������߳� COM ����ʵ�ֲ�����ʹ���䵥�߳� COM ����ʵ�֡�rgs �ļ��е��߳�ģ���ѱ�����Ϊ��Free����ԭ���Ǹ�ģ���Ƿ� DCOM Windows CE ƽ̨֧�ֵ�Ψһ�߳�ģ�͡�"
#endif

using namespace ATL;

#include <COM/Source/SourceDispatchImpl.h>
#include <osgEarthDrivers/xyz/XYZOptions>

// CTileSourceXYZ
class CTileSourceXYZ;
typedef 
	SourceDispatchImpl
	< 
	osgEarth::Drivers::XYZOptions, 
	CTileSourceXYZ, 
	ITileSourceXYZ, 

	CLSID_TileSourceXYZ,
	IID_ITileSourceXYZ, 
	NULL, 
	CLSCTX_INPROC_SERVER,

	&LIBID_osgEarthX_COMLib, 
	/*wMajor =*/ 1, 
	/*wMinor =*/ 0 
	> 
	ITileSourceXYZDispatchImpl;

class ATL_NO_VTABLE CTileSourceXYZ :
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CTileSourceXYZ, &CLSID_TileSourceXYZ>,
	public ISupportErrorInfo,
	public ITileSourceXYZDispatchImpl
{
public:
	CTileSourceXYZ() : ITileSourceXYZDispatchImpl( TILE_SOURCE_XYZ )
	{
	}

DECLARE_REGISTRY_RESOURCEID(IDR_TILESOURCEXYZ)


BEGIN_COM_MAP(CTileSourceXYZ)
	COM_INTERFACE_ENTRY(ITileSourceXYZ)
	COM_INTERFACE_ENTRY(ITileSourceDispatch)
	COM_INTERFACE_ENTRY(ISourceDispatch)
	COM_INTERFACE_ENTRY(IEarthDispatch)
	COM_INTERFACE_ENTRY2(IDispatch, ITileSourceXYZ)
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

OBJECT_ENTRY_AUTO(__uuidof(TileSourceXYZ), CTileSourceXYZ)
