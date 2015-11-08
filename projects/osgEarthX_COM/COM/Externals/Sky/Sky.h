// Sky.h : CSky ������

#pragma once
#include "resource.h"       // ������



#include "osgEarthX_COM_i.h"



#if defined(_WIN32_WCE) && !defined(_CE_DCOM) && !defined(_CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA)
#error "Windows CE ƽ̨(�粻�ṩ��ȫ DCOM ֧�ֵ� Windows Mobile ƽ̨)���޷���ȷ֧�ֵ��߳� COM ���󡣶��� _CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA ��ǿ�� ATL ֧�ִ������߳� COM ����ʵ�ֲ�����ʹ���䵥�߳� COM ����ʵ�֡�rgs �ļ��е��߳�ģ���ѱ�����Ϊ��Free����ԭ���Ǹ�ģ���Ƿ� DCOM Windows CE ƽ̨֧�ֵ�Ψһ�߳�ģ�͡�"
#endif

using namespace ATL;

#include <COM/EarthObject/EarthObjectDispatchImpl.h>

//osgEarthX
#include <Externals/Sky.h>

// CSky
class CSky;
typedef 
	EarthObjectDispatchImpl
	< 
	osgEarthX::Sky, 
	CSky, 
	ISky, 

	CLSID_Sky,
	IID_ISky, 
	NULL, 
	CLSCTX_INPROC_SERVER,

	&LIBID_osgEarthX_COMLib, 
	/*wMajor =*/ 1, 
	/*wMinor =*/ 0 
	> 
	ISkyDispatchImpl;

class ATL_NO_VTABLE CSky :
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CSky, &CLSID_Sky>,
	public ISupportErrorInfo,
	public ISkyDispatchImpl
{
public:
	//ISky
	STDMETHOD( get_enableLighting )( VARIANT_BOOL* pEnableLighting );
	STDMETHOD( put_enableLighting )( VARIANT_BOOL ifEnable );
	STDMETHOD( get_ambient )( FLOAT *pAmbient );
	STDMETHOD( put_ambient )( FLOAT fAmbient );
	STDMETHOD( get_hours )( FLOAT *pHours );
	STDMETHOD( put_hours )( FLOAT fHours );

public:
	CSky();
	CSky( const CSky& sky);
	virtual ~CSky();

DECLARE_REGISTRY_RESOURCEID(IDR_SKY)


BEGIN_COM_MAP(CSky)
	COM_INTERFACE_ENTRY(ISky)
	COM_INTERFACE_ENTRY(IEarthObject)
	COM_INTERFACE_ENTRY(IEarthDispatch)
	COM_INTERFACE_ENTRY2(IDispatch, ISky)
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

OBJECT_ENTRY_AUTO(__uuidof(Sky), CSky)
