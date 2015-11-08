/**
	@brief ���IEarthDispatchʹ�õ���
	@author Hao Luo
	@date 2015/03/31
*/

#ifndef OSGEARTHX_COM_EARTH_DISPATCH_IMPL_H
#define OSGEARTHX_COM_EARTH_DISPATCH_IMPL_H 1

#include "stdafx.h"
#include "osgEarthX_COM_i.h"

//��IEarthDispatchʵ�����Ӧ���ڲ���Ļ���ģ��
//�ɷ��ʽӿ��ڲ���osgEarth����
/**
	��ȡIEarthDispatchʵ������ڲ�����
	T_ImplClassTypeΪIEarthDispatch�����ӿڵ�ʵ��������
	T_IDispatchΪCOM�ӿ�
	T_InnerClassΪ�ڲ�ʵ��osgEarthX����osgEarth���������
*/
template
	< 
		class T_InnerClass, 
		class T_ImplClassType, 
		class T_IDispatch,
		REFCLSID rclsid,//��ID
		REFIID riid,//�ӿ�ID
		LPUNKNOWN pUnkOuter = NULL,
		DWORD dwClsContext = CLSCTX_INPROC_SERVER
	>
class EarthDispatch
{
public:
	static HRESULT createEarthDispatchInstance( IDispatch** ppIDispatch )
	{
		return CoCreateInstance( rclsid, pUnkOuter, dwClsContext, riid, ( void** ) ppIDispatch );
	}

	//��̬��
	//ͨ���ӿڷ��ʽӿ�ʵ������ڲ�ʵ�ʶ���
	static T_InnerClass* getEarthDispatchInnerObject( IDispatch* pIEarthDispatch, bool ifCreate = false )
	{
		T_ImplClassType* pEarthDispatchObject = dynamic_cast< T_ImplClassType * >( pIEarthDispatch );
		if( pEarthDispatchObject != NULL )
		{
			if( ifCreate )
			{
				return pEarthDispatchObject->getOrCreateInnerObject();
			}
			else
			{
				return pEarthDispatchObject->getInnerObject();
			}
		}

		return NULL;
	}

protected:
private:
};

template
	<
		class T_IDispatch,//IDispatch�ӿ�, T_IDispatch����̳���IEarthDispatch
		const IID* piid = &__uuidof(T),
		const GUID* plibid = &CAtlModule::m_libid, 
		WORD wMajor = 1,
		WORD wMinor = 0,
		class tihclass = CComTypeInfoHolder
	>
class ATL_NO_VTABLE EarthDispatchImpl :
	public IDispatchImpl< T_IDispatch, piid, plibid, wMajor, wMinor, tihclass >
{
private:
	INT m_iData;

public:
	EarthDispatchImpl()
	{
		m_iData = 0;
	}

	virtual ~EarthDispatchImpl()
	{

	}

public:
	STDMETHOD( get_data )( INT* piData )
	{
		*piData = m_iData;
		return S_OK;
	}

	STDMETHOD( put_data )( INT iData )
	{
		m_iData = iData;
		return S_OK;
	}

protected:
private:
};

template
	<
		class T_ImplClass,//����ʵ��IDispatch����
		class T_IDispatch//IDispatch�ӿ�, T_IDispatch����̳���IEarthDispatch
	>
class ATL_NO_VTABLE EarthDispatchStockPropImpl :
	public CStockPropImpl< T_ImplClass, T_IDispatch >
{
private:
	INT m_iData;

public:
	EarthDispatchStockPropImpl()
	{
		m_iData = 0;
	}

	virtual ~EarthDispatchStockPropImpl()
	{

	}

public:
	STDMETHOD( get_data )( INT* piData )
	{
		*piData = m_iData;
		return S_OK;
	}

	STDMETHOD( put_data )( INT iData )
	{
		m_iData = iData;
		return S_OK;
	}

protected:
private:
};

#endif