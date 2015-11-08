// VectorSourceStencil.h : CVectorSourceStencil ������

#pragma once
#include "resource.h"       // ������



#include "osgEarthX_COM_i.h"



#if defined(_WIN32_WCE) && !defined(_CE_DCOM) && !defined(_CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA)
#error "Windows CE ƽ̨(�粻�ṩ��ȫ DCOM ֧�ֵ� Windows Mobile ƽ̨)���޷���ȷ֧�ֵ��߳� COM ���󡣶��� _CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA ��ǿ�� ATL ֧�ִ������߳� COM ����ʵ�ֲ�����ʹ���䵥�߳� COM ����ʵ�֡�rgs �ļ��е��߳�ģ���ѱ�����Ϊ��Free����ԭ���Ǹ�ģ���Ƿ� DCOM Windows CE ƽ̨֧�ֵ�Ψһ�߳�ģ�͡�"
#endif

using namespace ATL;

#include <COM/Source/SourceDispatchImpl.h>
#include <osgEarthDrivers/model_feature_stencil/FeatureStencilModelOptions>

// CVectorSourceStencil
class CVectorSourceStencil;
typedef 
	SourceDispatchImpl
	< 
	osgEarth::Drivers::FeatureStencilModelOptions, 
	CVectorSourceStencil, 
	IVectorSourceStencil, 

	CLSID_VectorSourceStencil,
	IID_IVectorSourceStencil, 
	NULL, 
	CLSCTX_INPROC_SERVER,

	&LIBID_osgEarthX_COMLib, 
	/*wMajor =*/ 1, 
	/*wMinor =*/ 0
	> 
	IVectorSourceStencilDispatchImpl;

class ATL_NO_VTABLE CVectorSourceStencil :
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CVectorSourceStencil, &CLSID_VectorSourceStencil>,
	public ISupportErrorInfo,
	public IVectorSourceStencilDispatchImpl
{
public:
	CVectorSourceStencil() : IVectorSourceStencilDispatchImpl( VECTOR_SOURCE_STENCIL )
	{
	}

DECLARE_REGISTRY_RESOURCEID(IDR_VECTORSOURCESTENCIL)


BEGIN_COM_MAP(CVectorSourceStencil)
	COM_INTERFACE_ENTRY(IVectorSourceStencil)
	COM_INTERFACE_ENTRY(IVectorSourceDispatch)
	COM_INTERFACE_ENTRY(ISourceDispatch)
	COM_INTERFACE_ENTRY(IEarthDispatch)
	COM_INTERFACE_ENTRY2(IDispatch,IVectorSourceStencil)
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

OBJECT_ENTRY_AUTO(__uuidof(VectorSourceStencil), CVectorSourceStencil)
