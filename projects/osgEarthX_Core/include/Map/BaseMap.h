/**
	@brief Base Class Of Map
	@author Hao Luo
	@date 2015/01/07
*/

#ifndef OSGEARTHX_CORE_BASE_MAP_H
#define OSGEARTHX_CORE_BASE_MAP_H 1

#include <osgEarthXCoreExport/Export.h>

#include <ThreadPool/ThreadPool.h>
#include <Viewer/MapViewer.h>

#include <OpenThreads/ReadWriteMutex>
#include <osgEarth/MapNode>

namespace osgEarthXCore
{
	class OSGEARTHX_CORE_EXPORT BaseMap : 
		virtual public osg::Referenced
	{
	public:
		friend MapViewer;

	protected:
		MapViewer* m_pMapViewer;

		osg::ref_ptr<osg::Group> m_refRoot;
		osg::ref_ptr<osgEarth::MapNode> m_refMapNode;
		osg::ref_ptr<osgEarth::Map> m_refMap;
		OpenThreads::ReadWriteMutex m_MapMutex;

	private:
		osgXThreads::ThreadPool* m_pThreadPool;///Ӧ��ʹ��getOrCreateThreadPool�������ʸ�ָ�룬��Ӧֱ�ӵ���

	public:
		BaseMap();
		virtual ~BaseMap();

		osg::Group* getMapRoot();
		osgEarth::Map* getOsgEarthMap();
		osgEarth::MapNode* getMapNode();
		OpenThreads::ReadWriteMutex& getMapMutex();
		const osgEarth::SpatialReference* getSRS();

	public:
		///�߳����
		///��������߳���
		void setMaxThreadsNum(unsigned int num);
		unsigned int getMaxThreadsNum();

	protected:
		virtual void initMapViewer( MapViewer* pMapViewer );

		///��ȡ���ߴ����̳߳�
		osgXThreads::ThreadPool* getOrCreateThreadPool();

		void addGroupObject( osg::Group* pGroup, osg::Node* pNode );
		void removeGroupObjet( osg::Group* pGroup, osg::Node* pNode );
	};

	class OSGEARTHX_CORE_EXPORT AddGroupObjectOperation : public osg::Operation
	{
	public:
		AddGroupObjectOperation( osg::Group* pGroup, osg::Node* pNode );

		virtual void operator()( osg::Object* );

	protected:
		virtual ~AddGroupObjectOperation();

	protected:
		osg::ref_ptr<osg::Group> m_refGroup;
		osg::ref_ptr<osg::Node> m_refNode;

	private:
	};

	class OSGEARTHX_CORE_EXPORT RemoveGroupObjectOperation : public osg::Operation
	{
	public:
		RemoveGroupObjectOperation( osg::Group* pGroup, osg::Node* pNode );
		virtual void operator()( osg::Object* );

	protected:
		virtual ~RemoveGroupObjectOperation();

	protected:
		osg::ref_ptr<osg::Group> m_refGroup;
		osg::ref_ptr<osg::Node> m_refNode;

	private:
	};
}

#endif