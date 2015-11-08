// ObjectFactory.h : CObjectFactory ������

#pragma once
#include "resource.h"       // ������



#include "osgEarthX_COM_i.h"



#if defined(_WIN32_WCE) && !defined(_CE_DCOM) && !defined(_CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA)
#error "Windows CE ƽ̨(�粻�ṩ��ȫ DCOM ֧�ֵ� Windows Mobile ƽ̨)���޷���ȷ֧�ֵ��߳� COM ���󡣶��� _CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA ��ǿ�� ATL ֧�ִ������߳� COM ����ʵ�ֲ�����ʹ���䵥�߳� COM ����ʵ�֡�rgs �ļ��е��߳�ģ���ѱ�����Ϊ��Free����ԭ���Ǹ�ģ���Ƿ� DCOM Windows CE ƽ̨֧�ֵ�Ψһ�߳�ģ�͡�"
#endif

using namespace ATL;


// CObjectFactory

class ATL_NO_VTABLE CObjectFactory :
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CObjectFactory, &CLSID_ObjectFactory>,
	public ISupportErrorInfo,
	public IDispatchImpl<IObjectFactory, &IID_IObjectFactory, &LIBID_osgEarthX_COMLib, /*wMajor =*/ 1, /*wMinor =*/ 0>
{
public:
	STDMETHOD( createByEarthObjectClassType )( EarthObjectClassType classType, IDispatch**ppIDispatch );
	STDMETHOD( createByEarthClassType )( EarthClassType classType, IDispatch**ppIDispatch );
	STDMETHOD( createBySourceClassType )( SourceClassType classType, IDispatch** ppIDispatch );
	STDMETHOD( createByGeoClassType )( GeoClassType classType, IDispatch **ppIDisaptch );
	STDMETHOD( createByUnitClassType )( UnitClassType classType, IDispatch** ppIDispatch );

public:
	CObjectFactory()
	{
	}

DECLARE_REGISTRY_RESOURCEID(IDR_OBJECTFACTORY)


BEGIN_COM_MAP(CObjectFactory)
	COM_INTERFACE_ENTRY(IObjectFactory)
	COM_INTERFACE_ENTRY(IDispatch)
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

OBJECT_ENTRY_AUTO(__uuidof(ObjectFactory), CObjectFactory)
