// TileSourceNoise.h : CTileSourceNoise ������

#pragma once
#include "resource.h"       // ������



#include "osgEarthX_COM_i.h"



#if defined(_WIN32_WCE) && !defined(_CE_DCOM) && !defined(_CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA)
#error "Windows CE ƽ̨(�粻�ṩ��ȫ DCOM ֧�ֵ� Windows Mobile ƽ̨)���޷���ȷ֧�ֵ��߳� COM ���󡣶��� _CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA ��ǿ�� ATL ֧�ִ������߳� COM ����ʵ�ֲ�����ʹ���䵥�߳� COM ����ʵ�֡�rgs �ļ��е��߳�ģ���ѱ�����Ϊ��Free����ԭ���Ǹ�ģ���Ƿ� DCOM Windows CE ƽ̨֧�ֵ�Ψһ�߳�ģ�͡�"
#endif

using namespace ATL;

#include <COM/Source/SourceDispatchImpl.h>
#include <osgEarthDrivers/noise/NoiseOptions>

// CTileSourceNoise
class CTileSourceNoise;
typedef 
	SourceDispatchImpl
	< 
	osgEarth::Drivers::Noise::NoiseOptions, 
	CTileSourceNoise, 
	ITileSourceNoise, 

	CLSID_TileSourceNoise,
	IID_ITileSourceNoise, 
	NULL, 
	CLSCTX_INPROC_SERVER,

	&LIBID_osgEarthX_COMLib, 
	/*wMajor =*/ 1, 
	/*wMinor =*/ 0 
	> 
	ITileSourceNoiseDispatchImpl;

class ATL_NO_VTABLE CTileSourceNoise :
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CTileSourceNoise, &CLSID_TileSourceNoise>,
	public ISupportErrorInfo,
	public ITileSourceNoiseDispatchImpl
{
public:
	//ITileSourceNoise
	STDMETHOD( put_resolution )( DOUBLE dResolution );
	STDMETHOD( put_scale )( DOUBLE dScale );
	STDMETHOD( put_bias )( DOUBLE dBias );
	STDMETHOD( put_octaves )( INT iOctaves );
	STDMETHOD( put_frequency )( DOUBLE dFrequency );
	STDMETHOD( put_persistence )( DOUBLE dPersistence );
	STDMETHOD( put_lacunarity )( DOUBLE dLacunarity );
	STDMETHOD( put_seed )( INT iSeed );
	STDMETHOD( put_normalMap )( VARIANT_BOOL bNormalMap );
	STDMETHOD( put_minElevation )( FLOAT fMinElevation );
	STDMETHOD( put_maxElevation )( FLOAT fMaxElevation );

public:
	CTileSourceNoise() : ITileSourceNoiseDispatchImpl( TILE_SOURCE_NOISE )
	{
	}

DECLARE_REGISTRY_RESOURCEID(IDR_TILESOURCENOISE)


BEGIN_COM_MAP(CTileSourceNoise)
	COM_INTERFACE_ENTRY(ITileSourceNoise)
	COM_INTERFACE_ENTRY(ITileSourceDispatch)
	COM_INTERFACE_ENTRY(ISourceDispatch)
	COM_INTERFACE_ENTRY(IEarthDispatch)
	COM_INTERFACE_ENTRY2(IDispatch, ITileSourceNoise)
	COM_INTERFACE_ENTRY(ISupportErrorInfo)
END_COM_MAP()

// ISupportsErrorInfo
	STDMETHOD(InterfaceSupportsErrorInfo)(REFIID riid);


	DECLARE_PROTECT_FINAL_CONSTRUCT()

	HRESULT FinalConstruct()
	{
		return S_OK;
	}

	void FinalRelease()
	{
	}

public:



};

OBJECT_ENTRY_AUTO(__uuidof(TileSourceNoise), CTileSourceNoise)
