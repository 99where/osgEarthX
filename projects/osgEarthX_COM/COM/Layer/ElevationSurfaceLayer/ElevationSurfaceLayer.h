// ElevationSurfaceLayer.h : CElevationSurfaceLayer ������

#pragma once
#include "resource.h"       // ������



#include "osgEarthX_COM_i.h"



#if defined(_WIN32_WCE) && !defined(_CE_DCOM) && !defined(_CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA)
#error "Windows CE ƽ̨(�粻�ṩ��ȫ DCOM ֧�ֵ� Windows Mobile ƽ̨)���޷���ȷ֧�ֵ��߳� COM ���󡣶��� _CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA ��ǿ�� ATL ֧�ִ������߳� COM ����ʵ�ֲ�����ʹ���䵥�߳� COM ����ʵ�֡�rgs �ļ��е��߳�ģ���ѱ�����Ϊ��Free����ԭ���Ǹ�ģ���Ƿ� DCOM Windows CE ƽ̨֧�ֵ�Ψһ�߳�ģ�͡�"
#endif

using namespace ATL;

#include <COM/EarthObject/EarthObjectDispatchImpl.h>

#include <Layer/ElevationSurfaceLayer.h>

// CElevationSurfaceLayer
class CElevationSurfaceLayer;
typedef 
	EarthObjectDispatchImpl
	< 
	osgEarthX::ElevationSurfaceLayer, 
	CElevationSurfaceLayer, 
	IElevationSurfaceLayer, 

	CLSID_ElevationSurfaceLayer,
	IID_IElevationSurfaceLayer, 
	NULL, 
	CLSCTX_INPROC_SERVER,
 
	&LIBID_osgEarthX_COMLib, 
	/*wMajor =*/ 1, 
	/*wMinor =*/ 0 
	> 
	IElevationSurfaceLayerDispatchImpl;

class ATL_NO_VTABLE CElevationSurfaceLayer :
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CElevationSurfaceLayer, &CLSID_ElevationSurfaceLayer>,
	public ISupportErrorInfo,
	public IElevationSurfaceLayerDispatchImpl
{
public:
	//IElevationSurfaceLayer
	STDMETHOD( put_tileSource )( ITileSourceDispatch* pITileSourceDispatch );

public:
	CElevationSurfaceLayer();
	CElevationSurfaceLayer( const CElevationSurfaceLayer& layer );
	CElevationSurfaceLayer::~CElevationSurfaceLayer();

DECLARE_REGISTRY_RESOURCEID(IDR_ELEVATIONSURFACELAYER)


BEGIN_COM_MAP(CElevationSurfaceLayer)
	COM_INTERFACE_ENTRY(IElevationSurfaceLayer)
	COM_INTERFACE_ENTRY(ILayer)
	COM_INTERFACE_ENTRY(IEarthObject)
	COM_INTERFACE_ENTRY(IEarthDispatch)
	COM_INTERFACE_ENTRY2(IDispatch, IElevationSurfaceLayer)
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

OBJECT_ENTRY_AUTO(__uuidof(ElevationSurfaceLayer), CElevationSurfaceLayer)
