// Angular.h : CAngular ������

#pragma once
#include "resource.h"       // ������



#include "osgEarthX_COM_i.h"



#if defined(_WIN32_WCE) && !defined(_CE_DCOM) && !defined(_CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA)
#error "Windows CE ƽ̨(�粻�ṩ��ȫ DCOM ֧�ֵ� Windows Mobile ƽ̨)���޷���ȷ֧�ֵ��߳� COM ���󡣶��� _CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA ��ǿ�� ATL ֧�ִ������߳� COM ����ʵ�ֲ�����ʹ���䵥�߳� COM ����ʵ�֡�rgs �ļ��е��߳�ģ���ѱ�����Ϊ��Free����ԭ���Ǹ�ģ���Ƿ� DCOM Windows CE ƽ̨֧�ֵ�Ψһ�߳�ģ�͡�"
#endif

using namespace ATL;

#include <COM/Earth/PtrEarthDispatchImpl.h>
#include <osgEarth/Units>


// CAngular
class CAngular;
typedef 
	PtrEarthDispatchImpl
	< 
	UnitClassType, 
	osgEarth::Angular, 
	CAngular, 
	IAngular, 

	CLSID_Angular,
	IID_IAngular, 
	NULL, 
	CLSCTX_INPROC_SERVER,

	&LIBID_osgEarthX_COMLib, 
	/*wMajor =*/ 1, 
	/*wMinor =*/ 0
	> 
	IAngularDispatchImpl;

class ATL_NO_VTABLE CAngular :
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CAngular, &CLSID_Angular>,
	public ISupportErrorInfo,
	public IAngularDispatchImpl
{
public:
	STDMETHOD( set )( DOUBLE dValue, UnitsType eUnitsType );

public:
	CAngular():IAngularDispatchImpl( UNIT_CLASS_ANGULAR )
	{
	}

DECLARE_REGISTRY_RESOURCEID(IDR_ANGULAR)


BEGIN_COM_MAP(CAngular)
	COM_INTERFACE_ENTRY(IAngular)
	COM_INTERFACE_ENTRY(IEarthDispatch)
	COM_INTERFACE_ENTRY2(IDispatch, IAngular)
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

OBJECT_ENTRY_AUTO(__uuidof(Angular), CAngular)
