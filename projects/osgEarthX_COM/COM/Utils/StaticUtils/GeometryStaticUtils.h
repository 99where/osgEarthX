#ifndef OSGEARTHX_COM_GEOMETRY_STATIC_UTILS_H
#define OSGEARTHX_COM_GEOMETRY_STATIC_UTILS_H 1

#include "osgEarthX_COM_i.h"

#include <osgEarthSymbology/Geometry>

class GeometryStaticUtils
{
public:

	/**
		����ClassType�������󣬿��ṩ��ʼ������innerParams
		���ppIDispatch
	*/
	static HRESULT createInstance( GeometryClassType classType, IDispatch** ppIDispatch, osgEarth::Symbology::Geometry* pGeometry = NULL );

	/**
		��ȡ��ͬIGeometryʵ�����ڲ���osgEarth::Symbology::Geometry
	*/
	static osgEarth::Symbology::Geometry* getInnerObject( IGeometry* pIGeometry, bool bCreateIfNull = false );

protected:
private:
};

#endif