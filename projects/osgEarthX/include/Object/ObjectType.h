/**
	@brief 物体类型枚举
	@author Hao Luo
	@date 2014/11/06
*/

#ifndef OSGEARTHX_OBJECT_TYPE_H
#define OSGEARTHX_OBJECT_TYPE_H 1

#include <osgEarthXExport/Export.h>

namespace osgEarthX
{
	enum OSGEARTHX_EXPORT ObjectType
	{
		OBJECT = 1,
		GROUP,

		IMAGE_SURFACE_LAYER,
		VECTOR_SURFACE_LAYER,
		ELEVATION_SURFACE_LAYER,
		TERMASK_SURFACE_LAYER,

		GRATICULE,
		SKY,
		VIEWPOINT,

		TEXT_LABEL,
		MODEL,
		IMAGE_OVERLAY,
		FEATURE_PRIMITIVE,
		PLACE,
		CIRCLE,
		RECTANGLE_PRIMITIVE,
		ELLIPSE_PRIMITIVE,

		LABEL_SET_LAYER,
		MODEL_SET_LAYER,
		OVERLAY_IMAGE_SET_LAYER,
		SHAPE_SET_LAYER,
		PLACE_SET_LAYER,
		VIEWPOINT_SET_LAYER
	};
}

#endif