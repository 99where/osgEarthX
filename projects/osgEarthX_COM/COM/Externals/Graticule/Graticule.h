// Graticule.h : CGraticule ������

#pragma once
#include "resource.h"       // ������



#include "osgEarthX_COM_i.h"



#if defined(_WIN32_WCE) && !defined(_CE_DCOM) && !defined(_CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA)
#error "Windows CE ƽ̨(�粻�ṩ��ȫ DCOM ֧�ֵ� Windows Mobile ƽ̨)���޷���ȷ֧�ֵ��߳� COM ���󡣶��� _CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA ��ǿ�� ATL ֧�ִ������߳� COM ����ʵ�ֲ�����ʹ���䵥�߳� COM ����ʵ�֡�rgs �ļ��е��߳�ģ���ѱ�����Ϊ��Free����ԭ���Ǹ�ģ���Ƿ� DCOM Windows CE ƽ̨֧�ֵ�Ψһ�߳�ģ�͡�"
#endif

using namespace ATL;

#include <COM/EarthObject/EarthObjectDispatchImpl.h>

#include <Externals/Graticule.h>

// CGraticule
class CGraticule;
typedef 
	EarthObjectDispatchImpl
	< 
	osgEarthX::Graticule, 
	CGraticule, 
	IGraticule, 

	CLSID_Graticule,
	IID_IGraticule, 
	NULL, 
	CLSCTX_INPROC_SERVER,

	&LIBID_osgEarthX_COMLib, 
	/*wMajor =*/ 1, 
	/*wMinor =*/ 0  
	> 
	IGraticuleDispatchImpl;

class ATL_NO_VTABLE CGraticule :
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CGraticule, &CLSID_Graticule>,
	public ISupportErrorInfo,
	public IGraticuleDispatchImpl
{
public:
	CGraticule() : IGraticuleDispatchImpl( EXTERNAL_GRATICULE )
	{
	}

DECLARE_REGISTRY_RESOURCEID(IDR_GRATICULE)


BEGIN_COM_MAP(CGraticule)
	COM_INTERFACE_ENTRY(IGraticule)
	COM_INTERFACE_ENTRY(IEarthObject)
	COM_INTERFACE_ENTRY(IEarthDispatch)
	COM_INTERFACE_ENTRY2(IDispatch, IGraticule)
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

OBJECT_ENTRY_AUTO(__uuidof(Graticule), CGraticule)
