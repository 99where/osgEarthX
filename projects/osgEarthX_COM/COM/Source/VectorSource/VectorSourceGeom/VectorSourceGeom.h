// VectorSourceGeom.h : CVectorSourceGeom ������

#pragma once
#include "resource.h"       // ������



#include "osgEarthX_COM_i.h"



#if defined(_WIN32_WCE) && !defined(_CE_DCOM) && !defined(_CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA)
#error "Windows CE ƽ̨(�粻�ṩ��ȫ DCOM ֧�ֵ� Windows Mobile ƽ̨)���޷���ȷ֧�ֵ��߳� COM ���󡣶��� _CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA ��ǿ�� ATL ֧�ִ������߳� COM ����ʵ�ֲ�����ʹ���䵥�߳� COM ����ʵ�֡�rgs �ļ��е��߳�ģ���ѱ�����Ϊ��Free����ԭ���Ǹ�ģ���Ƿ� DCOM Windows CE ƽ̨֧�ֵ�Ψһ�߳�ģ�͡�"
#endif

using namespace ATL;

#include <COM/Source/SourceDispatchImpl.h>
#include <osgEarthDrivers/model_feature_geom/FeatureGeomModelOptions>

// CVectorSourceGeom
class CVectorSourceGeom;
typedef 
	SourceDispatchImpl
	< 
	osgEarth::Drivers::FeatureGeomModelOptions, 
	CVectorSourceGeom, 
	IVectorSourceGeom, 

	CLSID_VectorSourceGeom,
	IID_IVectorSourceGeom, 
	NULL, 
	CLSCTX_INPROC_SERVER,

	&LIBID_osgEarthX_COMLib, 
	/*wMajor =*/ 1, 
	/*wMinor =*/ 0 
	> 
	IVectorSourceGeomDispatchImpl;

class ATL_NO_VTABLE CVectorSourceGeom :
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CVectorSourceGeom, &CLSID_VectorSourceGeom>,
	public ISupportErrorInfo,
	public IVectorSourceGeomDispatchImpl
{
public:
	//IVectorSourceGeom
	STDMETHOD( put_featureSource )( IFeatureSourceDispatch* pIFeatureSourceDispatch );

public:
	CVectorSourceGeom();

DECLARE_REGISTRY_RESOURCEID(IDR_VECTORSOURCEGEOM)


BEGIN_COM_MAP(CVectorSourceGeom)
	COM_INTERFACE_ENTRY(IVectorSourceGeom)
	COM_INTERFACE_ENTRY(IVectorSourceDispatch)
	COM_INTERFACE_ENTRY(ISourceDispatch)
	COM_INTERFACE_ENTRY(IEarthDispatch)
	COM_INTERFACE_ENTRY2(IDispatch,IVectorSourceGeom)
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

OBJECT_ENTRY_AUTO(__uuidof(VectorSourceGeom), CVectorSourceGeom)
