// dllmain.h : ģ�����������

class CosgEarthX_COMModule : public ATL::CAtlDllModuleT< CosgEarthX_COMModule >
{
public :
	DECLARE_LIBID(LIBID_osgEarthX_COMLib)
	DECLARE_REGISTRY_APPID_RESOURCEID(IDR_OSGEARTHX_COM, "{5694FCB5-6C64-4303-8FF1-C158EFC837F6}")
};

extern class CosgEarthX_COMModule _AtlModule;
