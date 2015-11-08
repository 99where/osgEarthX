// Linear.h : CLinear ������

#pragma once
#include "resource.h"       // ������



#include "osgEarthX_COM_i.h"



#if defined(_WIN32_WCE) && !defined(_CE_DCOM) && !defined(_CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA)
#error "Windows CE ƽ̨(�粻�ṩ��ȫ DCOM ֧�ֵ� Windows Mobile ƽ̨)���޷���ȷ֧�ֵ��߳� COM ���󡣶��� _CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA ��ǿ�� ATL ֧�ִ������߳� COM ����ʵ�ֲ�����ʹ���䵥�߳� COM ����ʵ�֡�rgs �ļ��е��߳�ģ���ѱ�����Ϊ��Free����ԭ���Ǹ�ģ���Ƿ� DCOM Windows CE ƽ̨֧�ֵ�Ψһ�߳�ģ�͡�"
#endif

using namespace ATL;

#include <COM/Earth/PtrEarthDispatchImpl.h>
#include <osgEarth/Units>



// CLinear
class CLinear;
typedef 
	PtrEarthDispatchImpl
	< 
	UnitClassType, 
	osgEarth::Linear, 
	CLinear, 
	ILinear, 

	CLSID_Linear,
	IID_ILinear, 
	NULL, 
	CLSCTX_INPROC_SERVER,

	&LIBID_osgEarthX_COMLib, 
	/*wMajor =*/ 1, 
	/*wMinor =*/ 0
	> 
	ILinearDispatchImpl;

class ATL_NO_VTABLE CLinear :
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CLinear, &CLSID_Linear>,
	public ISupportErrorInfo,
	public ILinearDispatchImpl
{
public:
	STDMETHOD( set )( DOUBLE dValue, UnitsType eUnitsType );

public:
	CLinear(): ILinearDispatchImpl( UNIT_CLASS_LINEAR )
	{
	}

DECLARE_REGISTRY_RESOURCEID(IDR_LINEAR)


BEGIN_COM_MAP(CLinear)
	COM_INTERFACE_ENTRY(ILinear)
	COM_INTERFACE_ENTRY(IEarthDispatch)
	COM_INTERFACE_ENTRY2(IDispatch, ILinear)
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

OBJECT_ENTRY_AUTO(__uuidof(Linear), CLinear)
