// Vec3d.h : CVec3d ������

#pragma once
#include "resource.h"       // ������



#include "osgEarthX_COM_i.h"



#if defined(_WIN32_WCE) && !defined(_CE_DCOM) && !defined(_CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA)
#error "Windows CE ƽ̨(�粻�ṩ��ȫ DCOM ֧�ֵ� Windows Mobile ƽ̨)���޷���ȷ֧�ֵ��߳� COM ���󡣶��� _CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA ��ǿ�� ATL ֧�ִ������߳� COM ����ʵ�ֲ�����ʹ���䵥�߳� COM ����ʵ�֡�rgs �ļ��е��߳�ģ���ѱ�����Ϊ��Free����ԭ���Ǹ�ģ���Ƿ� DCOM Windows CE ƽ̨֧�ֵ�Ψһ�߳�ģ�͡�"
#endif

using namespace ATL;

#include <COM/Earth/PtrEarthDispatchImpl.h>
#include <osg/Vec3d>

// CVec3d
class CVec3d;
typedef 
	PtrEarthDispatchImpl
	< 
	VecClassType, 
	osg::Vec3d, 
	CVec3d, 
	IVec3d, 

	CLSID_Vec3d,
	IID_IVec3d, 
	NULL, 
	CLSCTX_INPROC_SERVER,

	&LIBID_osgEarthX_COMLib, 
	/*wMajor =*/ 1, 
	/*wMinor =*/ 0
	> 
	IVec3dDispatchImpl;

class ATL_NO_VTABLE CVec3d :
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CVec3d, &CLSID_Vec3d>,
	public ISupportErrorInfo,
	public IVec3dDispatchImpl
{
public:
	STDMETHOD( set )( DOUBLE dX, DOUBLE dY, DOUBLE dZ );
	STDMETHOD( put_x )( DOUBLE dX );
	STDMETHOD( get_x )( DOUBLE* pX );
	STDMETHOD( put_y )( DOUBLE dY );
	STDMETHOD( get_y )( DOUBLE* pY );
	STDMETHOD( put_z )( DOUBLE dZ );
	STDMETHOD( get_z )( DOUBLE* pZ );

public:
	CVec3d():IVec3dDispatchImpl( VEC_CLASS_VEC3D )
	{
	}

DECLARE_REGISTRY_RESOURCEID(IDR_VEC3D)


BEGIN_COM_MAP(CVec3d)
	COM_INTERFACE_ENTRY(IVec3d)
	COM_INTERFACE_ENTRY(IEarthDispatch)
	COM_INTERFACE_ENTRY2(IDispatch, IVec3d)
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

OBJECT_ENTRY_AUTO(__uuidof(Vec3d), CVec3d)
