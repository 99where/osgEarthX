/**
	@brief RingGeometry dispatch implementation
	@author Hao Luo
	@date 2015/11/01
*/
#ifndef OSGEARTHX_COM_RING_GEOMETRY_DISPATCH_IMP_H
#define OSGEARTHX_COM_RING_GEOMETRY_DISPATCH_IMP_H 1

#include <COM/Basis/Geometry/Geometry/GeometryDispatchImpl.h>

#define RingGeometryDispatchImplTemplate GeometryDispatchImpl< T_InnerClass, T_ImplClass, T_IDispatch,rclsid, riid, pUnkOuter, dwClsContext, plibid, wMajor, wMinor, tihclass >
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
class ATL_NO_VTABLE RingGeometryDispatchImpl : public RingGeometryDispatchImplTemplate
{
public:
	RingGeometryDispatchImpl( GeometryClassType classType ) : RingGeometryDispatchImplTemplate( classType ){}
	RingGeometryDispatchImpl( const RingGeometryDispatchImpl& disp ) : RingGeometryDispatchImplTemplate( disp ){}
};

#endif