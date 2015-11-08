// EarthMap.h : CEarthMap ������

#pragma once
#include "resource.h"       // ������



#include "osgEarthX_COM_i.h"



#if defined(_WIN32_WCE) && !defined(_CE_DCOM) && !defined(_CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA)
#error "Windows CE ƽ̨(�粻�ṩ��ȫ DCOM ֧�ֵ� Windows Mobile ƽ̨)���޷���ȷ֧�ֵ��߳� COM ���󡣶��� _CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA ��ǿ�� ATL ֧�ִ������߳� COM ����ʵ�ֲ�����ʹ���䵥�߳� COM ����ʵ�֡�rgs �ļ��е��߳�ģ���ѱ�����Ϊ��Free����ԭ���Ǹ�ģ���Ƿ� DCOM Windows CE ƽ̨֧�ֵ�Ψһ�߳�ģ�͡�"
#endif

using namespace ATL;

//osgEarthX
#include <EarthMap/EarthMap.h>

#include <COM/Earth/RefEarthDispatchImpl.h>
// CEarthMap

class CEarthMap;
typedef 
	RefEarthDispatchImpl
	< 
	EarthClassType, 
	osgEarthX::EarthMap,
	CEarthMap, IEarthMap, 

	CLSID_EarthMap,
	IID_IEarthMap, 
	NULL, 
	CLSCTX_INPROC_SERVER,

	&LIBID_osgEarthX_COMLib, 
	/*wMajor =*/ 1, 
	/*wMinor =*/ 0 
	> 
	IEarthMapDispatchImpl;

class ATL_NO_VTABLE CEarthMap :
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CEarthMap, &CLSID_EarthMap>,
	public ISupportErrorInfo,
	public IEarthMapDispatchImpl
{
public:
	//IEarthMap
	STDMETHOD(get_maxThreadsNum)(UINT*pUiNum);
	STDMETHOD(put_maxThreadsNum)(UINT uiNum);
	STDMETHOD( getSRS )( ISpatialReference** ppISRS );

public:
	CEarthMap();
	CEarthMap(const CEarthMap&earthMap);

DECLARE_REGISTRY_RESOURCEID(IDR_EARTHMAP)


BEGIN_COM_MAP(CEarthMap)
	COM_INTERFACE_ENTRY(IEarthMap)
	COM_INTERFACE_ENTRY(IEarthDispatch)
	COM_INTERFACE_ENTRY2(IDispatch, IEarthMap)
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

OBJECT_ENTRY_AUTO(__uuidof(EarthMap), CEarthMap)
