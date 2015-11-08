/**
	@brief ���IEarthDispatchʹ�õ���
	@author Hao Luo
	@date 2015/01/25
*/

#ifndef OSGEARTHX_COM_REF_EARTH_DISPATCH_IMPL_H
#define OSGEARTHX_COM_REF_EARTH_DISPATCH_IMPL_H 1

#include <COm/Earth/EarthDispatchImpl.h>

#include <osg/ref_ptr>

//RefEarthDispatch : T_InnerClass�����ڲ�Ӧ�á�
#define EarthDispatchTemplate EarthDispatch< T_InnerClass, T_ImplClass, T_IDispatch, rclsid, riid, pUnkOuter, dwClsContext >
template
	< 
		class T_ClassType, 
		class T_InnerClass,
		class T_ImplClass,//ʵ��T_IDispatch����
		class T_IDispatch,//IDispatch�ӿ�, T_IDispatch����̳���IEarthDispatch
		REFCLSID rclsid,//��ID
		REFIID riid,//�ӿ�ID
		LPUNKNOWN pUnkOuter = NULL,
		DWORD dwClsContext = CLSCTX_INPROC_SERVER
	>
class RefEarthDispatch : public EarthDispatchTemplate
{
public:
	static HRESULT createEarthDispatchInstance( IDispatch** ppIDispatch,T_InnerClass* pInnerObject = NULL )
	{
		HRESULT hr = S_FALSE;
		hr = EarthDispatchTemplate::createEarthDispatchInstance( ppIDispatch );
		if ( SUCCEEDED( hr ) && pInnerObject )
		{
			T_ImplClass* pDispatchInstance = dynamic_cast< T_ImplClass* >( *ppIDispatch );
			pDispatchInstance->setInnerObject( pInnerObject );
		}
		return hr;
	}

public:
	RefEarthDispatch( T_ClassType classType ) : m_ClassType( classType )
	{
	}

	RefEarthDispatch( const RefEarthDispatch& disp ) : m_ClassType( disp.m_ClassType )
	{
		m_refInnerObject = disp.m_refInnerObject;
	}

	virtual ~RefEarthDispatch()
	{

	}

	T_InnerClass* getInnerObject()
	{
		return m_refInnerObject;
	}

	virtual void setInnerObject( T_InnerClass* pObject )
	{
		m_refInnerObject = pObject;
	}

	T_InnerClass* getOrCreateInnerObject()
	{
		if ( m_refInnerObject.get() == NULL )
		{
			setInnerObject( new T_InnerClass() );
		}

		return m_refInnerObject;
	}

protected:
	const T_ClassType m_ClassType;
	osg::ref_ptr< T_InnerClass > m_refInnerObject;

protected:

private:
};

///RefEarthDispatchImpl
#define RefEarthDispatchTemplate RefEarthDispatch< T_ClassType, T_InnerClass, T_ImplClass, T_IDispatch, rclsid, riid, pUnkOuter, dwClsContext >

template
	< 
		/**
			�����ڲ������ģ�����
		*/
		class T_ClassType,//����ö��
		class T_InnerClass,//�ڲ�����
		class T_ImplClass,//ʵ��T_IDispatch����
		class T_IDispatch,//IDispatch�ӿ�, T_IDispatch����̳���IEarthDispatch

		/**
			�����ӿڶ���ģ�����
		*/
		REFCLSID rclsid,//��ID
		REFIID riid,//�ӿ�ID
		LPUNKNOWN pUnkOuter = NULL,
		DWORD dwClsContext = CLSCTX_INPROC_SERVER,

		/**
			�����ӿ���ģ�����
		*/
		const GUID* plibid = &CAtlModule::m_libid, 
		WORD wMajor = 1,
		WORD wMinor = 0,
		class tihclass = CComTypeInfoHolder
	>
class ATL_NO_VTABLE RefEarthDispatchImpl : 
	public RefEarthDispatchTemplate,
	public EarthDispatchImpl< T_IDispatch, &riid, plibid, wMajor, wMinor, tihclass >
{
public:
	RefEarthDispatchImpl( T_ClassType classType ) : RefEarthDispatchTemplate( classType )
	{
	}

	RefEarthDispatchImpl( const RefEarthDispatchImpl& disp ) : RefEarthDispatchTemplate( disp )
	{
	}

	//IEarthDispatch
	STDMETHOD( equal )( IEarthDispatch *pIEarthDispatch, VARIANT_BOOL *pIfEqual )
	{
		T_ImplClass* pImpClass = static_cast< T_ImplClass* >( pIEarthDispatch );
		*pIfEqual = VARIANT_FALSE;
		if ( pImpClass && pImpClass->getInnerObject() == this->getInnerObject() )
		{
			*pIfEqual = VARIANT_TRUE;
		}

		return S_OK;
	}

private:
};

///EarthDispatchStockPropImpl
template
	<
		class T_ClassType,//����ö��
		class T_InnerClass,//�ڲ�����
		class T_ImplClass,//����ʵ��IDispatch����
		class T_IDispatch,//�ӿ�

		/**
			�����ӿڶ���ģ�����
		*/
		REFCLSID rclsid,//��ID
		REFIID riid,//�ӿ�ID
		LPUNKNOWN pUnkOuter = NULL,
		DWORD dwClsContext = CLSCTX_INPROC_SERVER

	>
class ATL_NO_VTABLE RefEarthDispatchStockPropImpl :
	public RefEarthDispatchTemplate,
	public EarthDispatchStockPropImpl< T_ImplClass, T_IDispatch >
{
public:
	RefEarthDispatchStockPropImpl( T_ClassType classType ) : RefEarthDispatchTemplate( classType )
	{
	}

	RefEarthDispatchStockPropImpl( const RefEarthDispatchStockPropImpl& disp ) : RefEarthDispatchTemplate( disp )
	{
	}

	//IEarthDispatch
	STDMETHOD( equal )( IEarthDispatch *pIEarthDispatch, VARIANT_BOOL *pIfEqual )
	{
		T_ImplClass* pImpClass = static_cast< T_ImplClass* >( pIEarthDispatch );
		*pIfEqual = VARIANT_FALSE;
		if ( pImpClass && pImpClass->getInnerObject() == this->getInnerObject() )
		{
			*pIfEqual = VARIANT_TRUE;
		}

		return S_OK;
	}
protected:
private:
};

#endif