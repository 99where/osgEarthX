// Viewpoint.h : CViewpoint ������

#pragma once
#include "resource.h"       // ������



#include "osgEarthX_COM_i.h"



#if defined(_WIN32_WCE) && !defined(_CE_DCOM) && !defined(_CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA)
#error "Windows CE ƽ̨(�粻�ṩ��ȫ DCOM ֧�ֵ� Windows Mobile ƽ̨)���޷���ȷ֧�ֵ��߳� COM ���󡣶��� _CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA ��ǿ�� ATL ֧�ִ������߳� COM ����ʵ�ֲ�����ʹ���䵥�߳� COM ����ʵ�֡�rgs �ļ��е��߳�ģ���ѱ�����Ϊ��Free����ԭ���Ǹ�ģ���Ƿ� DCOM Windows CE ƽ̨֧�ֵ�Ψһ�߳�ģ�͡�"
#endif

using namespace ATL;

#include <COM/EarthObject/EarthObjectDispatchImpl.h>

//osgEarthX
#include <Externals/Viewpoint.h>

// CViewpoint
class CViewpoint;
typedef 
	EarthObjectDispatchImpl
	< 
	osgEarthX::Viewpoint, 
	CViewpoint, 
	IViewpoint, 

	CLSID_Viewpoint,
	IID_IViewpoint, 
	NULL, 
	CLSCTX_INPROC_SERVER,

	&LIBID_osgEarthX_COMLib, 
	/*wMajor =*/ 1, 
	/*wMinor =*/ 0 
	> 
	IViewpointDispatchImpl;

class ATL_NO_VTABLE CViewpoint :
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CViewpoint, &CLSID_Viewpoint>,
	public ISupportErrorInfo,
	public IViewpointDispatchImpl
{
public:
	//IViewpoint
	STDMETHOD( flyTo )( void );

	STDMETHOD( get_x )( DOUBLE* pX );
	STDMETHOD( put_x )( DOUBLE _x );

	STDMETHOD( get_y )( DOUBLE* pY );
	STDMETHOD( put_y )( DOUBLE _y);

	STDMETHOD( get_z )( DOUBLE* pZ );
	STDMETHOD( put_z )( DOUBLE _z );

	STDMETHOD( get_heading )( DOUBLE* pHeading );
	STDMETHOD( put_heading )( DOUBLE _heading );

	STDMETHOD( get_pitch )( DOUBLE* pPitch );
	STDMETHOD( put_pitch )( DOUBLE _pitch );

	STDMETHOD( get_range )( DOUBLE* pRange );
	STDMETHOD( put_range )( DOUBLE _range );

public:
	CViewpoint();
	CViewpoint( const CViewpoint& viewpoint );
	~CViewpoint();

DECLARE_REGISTRY_RESOURCEID(IDR_VIEWPOINT)


BEGIN_COM_MAP(CViewpoint)
	COM_INTERFACE_ENTRY(IViewpoint)
	COM_INTERFACE_ENTRY(IEarthObject)
	COM_INTERFACE_ENTRY(IEarthDispatch)
	COM_INTERFACE_ENTRY2(IDispatch, IViewpoint)
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

OBJECT_ENTRY_AUTO(__uuidof(Viewpoint), CViewpoint)
