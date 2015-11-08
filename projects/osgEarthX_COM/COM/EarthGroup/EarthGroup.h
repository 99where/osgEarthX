// E:\OpenSceneGraph\osgEarthX\projects\osgEarthX_COM\COM\EarthGroup\EarthGroup.h : CEarthGroup ������

#pragma once
#include "resource.h"       // ������



#include "osgEarthX_COM_i.h"



#if defined(_WIN32_WCE) && !defined(_CE_DCOM) && !defined(_CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA)
#error "Windows CE ƽ̨(�粻�ṩ��ȫ DCOM ֧�ֵ� Windows Mobile ƽ̨)���޷���ȷ֧�ֵ��߳� COM ���󡣶��� _CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA ��ǿ�� ATL ֧�ִ������߳� COM ����ʵ�ֲ�����ʹ���䵥�߳� COM ����ʵ�֡�rgs �ļ��е��߳�ģ���ѱ�����Ϊ��Free����ԭ���Ǹ�ģ���Ƿ� DCOM Windows CE ƽ̨֧�ֵ�Ψһ�߳�ģ�͡�"
#endif

using namespace ATL;

//osgEarthX
#include <Group/Group.h>

//osgEarthX_COM
#include <COM/EarthObject/EarthObjectDispatchImpl.h>

// CEarthGroup
class CEarthGroup;
typedef 
	EarthObjectDispatchImpl
	< 
	osgEarthX::Group, 
	CEarthGroup, 
	IEarthGroup, 

	CLSID_EarthGroup,
	IID_IEarthGroup, 
	NULL, 
	CLSCTX_INPROC_SERVER,

	&LIBID_osgEarthX_COMLib, 
	/*wMajor =*/ 1, 
	/*wMinor =*/ 0
	> 
	IEarthGroupDispatchImpl;

class ATL_NO_VTABLE CEarthGroup :
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CEarthGroup, &CLSID_EarthGroup>,
	public ISupportErrorInfo,
	public IEarthGroupDispatchImpl
{
public:
	//IEarthGroup
	STDMETHOD( addChild )( IEarthObject* pIEarthObject );
	STDMETHOD( removeChild )( IEarthObject* pIEarthObject );
	STDMETHOD( removeChildByPos )( UINT uiPos );
	STDMETHOD( getChild )( UINT uiPos, IEarthObject**ppIEarthObject );
	STDMETHOD( getPosOfChild )( IEarthObject* pIEarthObject, UINT*pPos );
	STDMETHOD( moveChild )( IEarthObject*pIEarthObject, UINT uiNewPos );
	STDMETHOD( moveChildFromCurPos )( UINT uiCurPos, UINT uiNewPos );
	STDMETHOD( getChildrenCount )( UINT* pCount );
	STDMETHOD( removeChildren )();

	STDMETHOD( insertChild )( IEarthObject* pIEarthObject, UINT uiInsertPos );

public:
	CEarthGroup();
	CEarthGroup(const CEarthGroup&earthGroup);

DECLARE_REGISTRY_RESOURCEID(IDR_EARTHGROUP)


BEGIN_COM_MAP(CEarthGroup)
	COM_INTERFACE_ENTRY(IEarthGroup)
	COM_INTERFACE_ENTRY(IEarthObject)
	COM_INTERFACE_ENTRY(IEarthDispatch)
	COM_INTERFACE_ENTRY2(IDispatch, IEarthGroup)
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

OBJECT_ENTRY_AUTO(__uuidof(EarthGroup), CEarthGroup)
