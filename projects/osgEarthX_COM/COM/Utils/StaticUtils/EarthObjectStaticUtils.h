/**
	@brief �ڲ�EarthObject����ྲ̬������
	@author Hao Luo
	@date 2014/11/26
*/

#ifndef EARTH_OBJECT_STATIC_UTILS_H
#define EARTH_OBJECT_STATIC_UTILS_H 1

#include "osgEarthX_COM_i.h"

//osgEarthX
#include <Object/Object.h>

class EarthObjectStaticUtils
{
public:

	/**
		����ClassType�������󣬿��ṩ��ʼ������innerParams
		���ppIDispatch
	*/
	static HRESULT createInstance( EarthObjectClassType classType, IDispatch** ppIDispatch, osgEarthX::Object* pInnerObject = NULL );

	/**
		��ȡ��ͬIEarthObjectʵ�����ڲ���osgEarthX::Object
	*/
	static osgEarthX::Object* getInnerObject( IEarthObject* pIEarthObject, bool bCreateIfNull = false );

protected:
private:
};
#endif