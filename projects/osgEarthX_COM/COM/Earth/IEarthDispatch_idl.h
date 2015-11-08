#ifndef I_EARTH_DISPATCH_IDL_H
#define I_EARTH_DISPATCH_IDL_H 1

#include <COM/Earth/EarthClassType_idl.h>

const INT IEarthDispatchIdsCount = 2;
const INT IEarthDispatchBeginId = 0;

[
	object,
	uuid(a19426b7-7677-442b-b0c4-3f7a7638ea2b),
	dual,
	nonextensible,
	pointer_default(unique)
]
interface IEarthDispatch : IDispatch
{
	[ id( IEarthDispatchBeginId + 1 ), propget, helpstring( "���ڴ洢�����Ϣ�Ķ����ṩ���ⲿʹ�ã�������޹�" ) ] HRESULT data( [ out,retval ] INT* piData );
	[ id( IEarthDispatchBeginId + 1 ), propput, helpstring( "���ڴ洢�����Ϣ�Ķ����ṩ���ⲿʹ�ã�������޹�" ) ] HRESULT data( [ in ] INT iData );

	[ id( IEarthDispatchBeginId + 2 ), helpstring( "�ж��ڲ����������Ƿ�һ��" ) ] HRESULT equal( [ in ]IEarthDispatch* pIEarthDispatch, [ out,retval ] VARIANT_BOOL* pIfEqual );

};

#endif