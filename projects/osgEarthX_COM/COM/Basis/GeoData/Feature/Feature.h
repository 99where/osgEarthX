// Feature.h : CFeature ������

#pragma once
#include "resource.h"       // ������



#include "osgEarthX_COM_i.h"



#if defined(_WIN32_WCE) && !defined(_CE_DCOM) && !defined(_CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA)
#error "Windows CE ƽ̨(�粻�ṩ��ȫ DCOM ֧�ֵ� Windows Mobile ƽ̨)���޷���ȷ֧�ֵ��߳� COM ���󡣶��� _CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA ��ǿ�� ATL ֧�ִ������߳� COM ����ʵ�ֲ�����ʹ���䵥�߳� COM ����ʵ�֡�rgs �ļ��е��߳�ģ���ѱ�����Ϊ��Free����ԭ���Ǹ�ģ���Ƿ� DCOM Windows CE ƽ̨֧�ֵ�Ψһ�߳�ģ�͡�"
#endif

using namespace ATL;

#include <COM/Earth/RefEarthDispatchImpl.h>
#include <Basis/Geo/Feature.h>

// CFeature
class CFeature;
typedef 
	RefEarthDispatchImpl
	< 
	GeoClassType, 
	osgEarthXCore::Feature, 
	CFeature, 
	IFeature, 

	CLSID_Feature,
	IID_IFeature, 
	NULL, 
	CLSCTX_INPROC_SERVER,

	&LIBID_osgEarthX_COMLib, 
	/*wMajor =*/ 1, 
	/*wMinor =*/ 0
	> 
	IFeatureDispatchImpl;

class ATL_NO_VTABLE CFeature :
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CFeature, &CLSID_Feature>,
	public ISupportErrorInfo,
	public IFeatureDispatchImpl
{
public:
	STDMETHOD( setGeometry )( IGeometry* pIGeometry );

public:
	CFeature():IFeatureDispatchImpl( GEO_CLASS_FEATURE )
	{
	}

DECLARE_REGISTRY_RESOURCEID(IDR_FEATURE)


BEGIN_COM_MAP(CFeature)
	COM_INTERFACE_ENTRY(IFeature)
	COM_INTERFACE_ENTRY(IEarthDispatch)
	COM_INTERFACE_ENTRY2(IDispatch, IFeature)
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

OBJECT_ENTRY_AUTO(__uuidof(Feature), CFeature)
