/**
	@brief ISourceDispatch�ӿڵĲ���ʵ��ģ��
	@author Hao Luo
	@date 2015/03/25
*/

#ifndef OSGEARTHX_COM_SOURCE_DISPATCH_IMPL_H
#define OSGEARTHX_COM_SOURCE_DISPATCH_IMPL_H 1

#include <COM/Earth/PtrEarthDispatchImpl.h>

#define SourcePtrEarthDispatchImplTemplate PtrEarthDispatchImpl< SourceClassType, T_InnerClass, T_ImplClass, T_IDispatch, rclsid, riid, pUnkOuter, dwClsContext, plibid, wMajor, wMinor, tihclass >
template
	<
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
class ATL_NO_VTABLE SourceDispatchImpl : 
	public SourcePtrEarthDispatchImplTemplate
{
public:
	SourceDispatchImpl( SourceClassType classType ) : SourcePtrEarthDispatchImplTemplate( classType ){}
	virtual ~SourceDispatchImpl(){}

	//ISourceDispatch
	STDMETHOD( get_classType )( SourceClassType *pClassType )
	{
		*pClassType = m_ClassType;
		return S_OK;
	}

protected:
private:
};

#endif