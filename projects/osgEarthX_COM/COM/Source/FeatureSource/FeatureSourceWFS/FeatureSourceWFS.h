// FeatureSourceWFS.h : CFeatureSourceWFS ������

#pragma once
#include "resource.h"       // ������



#include "osgEarthX_COM_i.h"



#if defined(_WIN32_WCE) && !defined(_CE_DCOM) && !defined(_CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA)
#error "Windows CE ƽ̨(�粻�ṩ��ȫ DCOM ֧�ֵ� Windows Mobile ƽ̨)���޷���ȷ֧�ֵ��߳� COM ���󡣶��� _CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA ��ǿ�� ATL ֧�ִ������߳� COM ����ʵ�ֲ�����ʹ���䵥�߳� COM ����ʵ�֡�rgs �ļ��е��߳�ģ���ѱ�����Ϊ��Free����ԭ���Ǹ�ģ���Ƿ� DCOM Windows CE ƽ̨֧�ֵ�Ψһ�߳�ģ�͡�"
#endif

using namespace ATL;

#include <COM/Source/SourceDispatchImpl.h>
#include <osgEarthDrivers/feature_wfs/WFSFeatureOptions>

// CFeatureSourceWFS
class CFeatureSourceWFS;
typedef 
	SourceDispatchImpl
	< 
	osgEarth::Drivers::WFSFeatureOptions, 
	CFeatureSourceWFS, 
	IFeatureSourceWFS, 

	CLSID_FeatureSourceWFS,
	IID_IFeatureSourceWFS, 
	NULL, 
	CLSCTX_INPROC_SERVER,

	&LIBID_osgEarthX_COMLib, 
	/*wMajor =*/ 1, 
	/*wMinor =*/ 0 
	> 
	IFeatureSourceWFSDipsatchImpl;

class ATL_NO_VTABLE CFeatureSourceWFS :
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CFeatureSourceWFS, &CLSID_FeatureSourceWFS>,
	public ISupportErrorInfo,
	public IFeatureSourceWFSDipsatchImpl
{
public:
	CFeatureSourceWFS() : IFeatureSourceWFSDipsatchImpl( FEATURE_SOURCE_WFS )
	{
	}

DECLARE_REGISTRY_RESOURCEID(IDR_FEATURESOURCEWFS)


BEGIN_COM_MAP(CFeatureSourceWFS)
	COM_INTERFACE_ENTRY(IFeatureSourceWFS)
	COM_INTERFACE_ENTRY(IFeatureSourceDispatch)
	COM_INTERFACE_ENTRY(ISourceDispatch)
	COM_INTERFACE_ENTRY(IEarthDispatch)
	COM_INTERFACE_ENTRY2(IDispatch, IFeatureSourceWFS)
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

OBJECT_ENTRY_AUTO(__uuidof(FeatureSourceWFS), CFeatureSourceWFS)
