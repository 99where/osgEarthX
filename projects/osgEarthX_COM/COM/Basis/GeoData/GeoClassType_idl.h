#ifndef OSGEARTHX_COM_GEO_CLASS_TYPE_IDL_H
#define OSGEARTHX_COM_GEO_CLASS_TYPE_IDL_H 1

[
	uuid(9ecc1b1b-6276-401c-82dc-b9bd87f4ccf6)
]
typedef enum GeoClassType
{
	GEO_CLASS_SPATIAL_REFERENCE = 0,
	GEO_CLASS_GEO_POINT = 1,
	GEO_CLASS_FEATURE
}GeoClassType;

#endif