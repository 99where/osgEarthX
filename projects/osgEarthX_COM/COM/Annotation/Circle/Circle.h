// Circle.h : CCircle ������

#pragma once
#include "resource.h"       // ������



#include "osgEarthX_COM_i.h"



#if defined(_WIN32_WCE) && !defined(_CE_DCOM) && !defined(_CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA)
#error "Windows CE ƽ̨(�粻�ṩ��ȫ DCOM ֧�ֵ� Windows Mobile ƽ̨)���޷���ȷ֧�ֵ��߳� COM ���󡣶��� _CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA ��ǿ�� ATL ֧�ִ������߳� COM ����ʵ�ֲ�����ʹ���䵥�߳� COM ����ʵ�֡�rgs �ļ��е��߳�ģ���ѱ�����Ϊ��Free����ԭ���Ǹ�ģ���Ƿ� DCOM Windows CE ƽ̨֧�ֵ�Ψһ�߳�ģ�͡�"
#endif

using namespace ATL;

#include <COM/EarthObject/EarthObjectDispatchImpl.h>
#include <Annotation/Circle.h>

// CCircle
class CCircle;
typedef EarthObjectDispatchImpl
		< 
			osgEarthX::Circle, 
			CCircle, 
			ICircle, 

			CLSID_Circle,
			IID_ICircle, 
			NULL, 
			CLSCTX_INPROC_SERVER,

			&LIBID_osgEarthX_COMLib, 
			/*wMajor =*/ 1, 
			/*wMinor =*/ 0 
		> 
		ICircleDispatchImpl;

class ATL_NO_VTABLE CCircle :
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CCircle, &CLSID_Circle>,
	public ISupportErrorInfo,
	public ICircleDispatchImpl
{
public:
	STDMETHOD( setPosition )( IGeoPoint* pIGeoPoint );
	STDMETHOD( setRadius )( ILinear* pILinear );
	STDMETHOD( setArcStart )( IAngular* pIAngular );
	STDMETHOD( setArcEnd )( IAngular* pIAngular );
	STDMETHOD( setPie )( VARIANT_BOOL vbPie );

public:
	CCircle() : ICircleDispatchImpl( ANNOTATION_CIRCLE )
	{
	}

DECLARE_REGISTRY_RESOURCEID(IDR_CIRCLE)


BEGIN_COM_MAP(CCircle)
	COM_INTERFACE_ENTRY(ICircle)
	COM_INTERFACE_ENTRY(IEarthObject)
	COM_INTERFACE_ENTRY(IEarthDispatch)
	COM_INTERFACE_ENTRY2(IDispatch, ICircle)
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

OBJECT_ENTRY_AUTO(__uuidof(Circle), CCircle)
