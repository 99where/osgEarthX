// VectorSurfaceLayer.h : CVectorSurfaceLayer ������

#pragma once
#include "resource.h"       // ������



#include "osgEarthX_COM_i.h"



#if defined(_WIN32_WCE) && !defined(_CE_DCOM) && !defined(_CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA)
#error "Windows CE ƽ̨(�粻�ṩ��ȫ DCOM ֧�ֵ� Windows Mobile ƽ̨)���޷���ȷ֧�ֵ��߳� COM ���󡣶��� _CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA ��ǿ�� ATL ֧�ִ������߳� COM ����ʵ�ֲ�����ʹ���䵥�߳� COM ����ʵ�֡�rgs �ļ��е��߳�ģ���ѱ�����Ϊ��Free����ԭ���Ǹ�ģ���Ƿ� DCOM Windows CE ƽ̨֧�ֵ�Ψһ�߳�ģ�͡�"
#endif

using namespace ATL;

//osgEarthX
#include <Layer/VectorSurfaceLayer.h>

//osgEarthX_COM
#include <COM/EarthObject/EarthObjectDispatchImpl.h>
#include <COM/Layer/VectorSurfaceLayer/IDispVectorSurfaceLayerEvents_CP.h>

// CVectorSurfaceLayer
class CVectorSurfaceLayer;
typedef 
	EarthObjectDispatchImpl
	< 
	osgEarthX::VectorSurfaceLayer, 
	CVectorSurfaceLayer, 
	IVectorSurfaceLayer, 

	CLSID_VectorSurfaceLayer,
	IID_IVectorSurfaceLayer, 
	NULL, 
	CLSCTX_INPROC_SERVER,

	&LIBID_osgEarthX_COMLib, 
	/*wMajor =*/ 1, 
	/*wMinor =*/ 0 
	> 
	IVectorSurfaceLayerDispatchImpl;

class ATL_NO_VTABLE CVectorSurfaceLayer :
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CVectorSurfaceLayer, &CLSID_VectorSurfaceLayer>,
	public ISupportErrorInfo,
	public IVectorSurfaceLayerDispatchImpl,
	public IConnectionPointContainerImpl<CVectorSurfaceLayer>,
	public CProxyIDispVectorSurfaceLayerEvents<CVectorSurfaceLayer>
{
public:
	//IVectorSurfaceLayer
	STDMETHOD( put_vectorSource )( IVectorSourceDispatch* pIVectorSourceDispatch );

public:
	CVectorSurfaceLayer();
	CVectorSurfaceLayer(const CVectorSurfaceLayer&vecSufLayer);
	virtual ~CVectorSurfaceLayer();

DECLARE_REGISTRY_RESOURCEID(IDR_VECTORSURFACELAYER)


BEGIN_COM_MAP(CVectorSurfaceLayer)
	COM_INTERFACE_ENTRY(IVectorSurfaceLayer)
	COM_INTERFACE_ENTRY(ILayer)
	COM_INTERFACE_ENTRY(IEarthObject)
	COM_INTERFACE_ENTRY(IEarthDispatch)
	COM_INTERFACE_ENTRY2(IDispatch,IVectorSurfaceLayer)
	COM_INTERFACE_ENTRY(ISupportErrorInfo)
	COM_INTERFACE_ENTRY(IConnectionPointContainer)
END_COM_MAP()

BEGIN_CONNECTION_POINT_MAP(CVectorSurfaceLayer)
	CONNECTION_POINT_ENTRY(__uuidof(IDispVectorSurfaceLayerEvents))
END_CONNECTION_POINT_MAP()


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

OBJECT_ENTRY_AUTO(__uuidof(VectorSurfaceLayer), CVectorSurfaceLayer)
