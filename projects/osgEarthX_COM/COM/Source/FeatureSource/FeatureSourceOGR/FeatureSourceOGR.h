// FeatureSourceOGR.h : CFeatureSourceOGR ������

#pragma once
#include "resource.h"       // ������



#include "osgEarthX_COM_i.h"



#if defined(_WIN32_WCE) && !defined(_CE_DCOM) && !defined(_CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA)
#error "Windows CE ƽ̨(�粻�ṩ��ȫ DCOM ֧�ֵ� Windows Mobile ƽ̨)���޷���ȷ֧�ֵ��߳� COM ���󡣶��� _CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA ��ǿ�� ATL ֧�ִ������߳� COM ����ʵ�ֲ�����ʹ���䵥�߳� COM ����ʵ�֡�rgs �ļ��е��߳�ģ���ѱ�����Ϊ��Free����ԭ���Ǹ�ģ���Ƿ� DCOM Windows CE ƽ̨֧�ֵ�Ψһ�߳�ģ�͡�"
#endif

using namespace ATL;

#include <COM/Source/SourceDispatchImpl.h>
#include <osgEarthDrivers/feature_ogr/OGRFeatureOptions>

// CFeatureSourceOGR
class CFeatureSourceOGR;
typedef 
	SourceDispatchImpl
	< 
	osgEarth::Drivers::OGRFeatureOptions, 
	CFeatureSourceOGR, 
	IFeatureSourceOGR, 

	CLSID_FeatureSourceOGR,
	IID_IFeatureSourceOGR, 
	NULL, 
	CLSCTX_INPROC_SERVER,

	&LIBID_osgEarthX_COMLib, 
	/*wMajor =*/ 1, 
	/*wMinor =*/ 0 
	> 
	IFeatureSourceOGRDispatchImpl;

class ATL_NO_VTABLE CFeatureSourceOGR :
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CFeatureSourceOGR, &CLSID_FeatureSourceOGR>,
	public ISupportErrorInfo,
	public IFeatureSourceOGRDispatchImpl
{
public:
	//IFeatureSourceOGR
	STDMETHOD( get_url )( BSTR* pBstrUrl );
	STDMETHOD( put_url )( BSTR bstrUrl );

public:
	CFeatureSourceOGR() : IFeatureSourceOGRDispatchImpl( FEATURE_SOURCE_OGR )
	{
	}

DECLARE_REGISTRY_RESOURCEID(IDR_FEATURESOURCEOGR)


BEGIN_COM_MAP(CFeatureSourceOGR)
	COM_INTERFACE_ENTRY(IFeatureSourceOGR)
	COM_INTERFACE_ENTRY(IFeatureSourceDispatch)
	COM_INTERFACE_ENTRY(ISourceDispatch)
	COM_INTERFACE_ENTRY(IEarthDispatch)
	COM_INTERFACE_ENTRY2(IDispatch, IFeatureSourceOGR)
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

OBJECT_ENTRY_AUTO(__uuidof(FeatureSourceOGR), CFeatureSourceOGR)
