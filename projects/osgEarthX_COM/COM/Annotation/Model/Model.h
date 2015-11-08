// Model.h : CModel ������

#pragma once
#include "resource.h"       // ������



#include "osgEarthX_COM_i.h"



#if defined(_WIN32_WCE) && !defined(_CE_DCOM) && !defined(_CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA)
#error "Windows CE ƽ̨(�粻�ṩ��ȫ DCOM ֧�ֵ� Windows Mobile ƽ̨)���޷���ȷ֧�ֵ��߳� COM ���󡣶��� _CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA ��ǿ�� ATL ֧�ִ������߳� COM ����ʵ�ֲ�����ʹ���䵥�߳� COM ����ʵ�֡�rgs �ļ��е��߳�ģ���ѱ�����Ϊ��Free����ԭ���Ǹ�ģ���Ƿ� DCOM Windows CE ƽ̨֧�ֵ�Ψһ�߳�ģ�͡�"
#endif

using namespace ATL;

#include <COM/EarthObject/EarthObjectDispatchImpl.h>

//osgEarthX
#include <Annotation/Model.h>

// CModel
class CModel;
typedef 
	EarthObjectDispatchImpl
	< 
	osgEarthX::Model, 
	CModel, 
	IModel, 

	CLSID_Model,
	IID_IModel, 
	NULL, 
	CLSCTX_INPROC_SERVER,

	&LIBID_osgEarthX_COMLib, 
	/*wMajor =*/ 1, 
	/*wMinor =*/ 0 
	> 
	IModelDispatchImpl;

class ATL_NO_VTABLE CModel :
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CModel, &CLSID_Model>,
	public ISupportErrorInfo,
	public IModelDispatchImpl
{
public:
	CModel() : IModelDispatchImpl( ANNOTATION_MODEL )
	{
	}

public:
	STDMETHOD( setModelPath )( BSTR bstrModelPath );
	STDMETHOD( setPosition )( IGeoPoint* pIGeoPoint );

DECLARE_REGISTRY_RESOURCEID(IDR_MODEL)


BEGIN_COM_MAP(CModel)
	COM_INTERFACE_ENTRY(IModel)
	COM_INTERFACE_ENTRY(IEarthObject)
	COM_INTERFACE_ENTRY(IEarthDispatch)
	COM_INTERFACE_ENTRY2(IDispatch,IModel)
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

OBJECT_ENTRY_AUTO(__uuidof(Model), CModel)
