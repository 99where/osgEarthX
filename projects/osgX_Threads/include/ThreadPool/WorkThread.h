/**
	@brief �����߳�
	@author Hao Luo
	@date 2014/11/04
*/

#ifndef OSGX_THREADS_WORK_THREAD_H
#define OSGX_THREADS_WORK_THREAD_H 1

#include <osgXThreadsExport/Export.h>

#include <OpenThreads/Thread>
#include <osg/Referenced>

namespace osgXThreads
{
	class IBeltline;

	class OSGX_THREADS_EXPORT WorkThread : 
		public OpenThreads::Thread,
		virtual public osg::Referenced
	{
	public:
		///���캯����TasksManagerָ��Ĭ��ΪNULL
		WorkThread( IBeltline* pBeltline = NULL );

		///����TasksManager
		void setIBeltLine( IBeltline* pBeltline );

		///����OpenThreads::Thread�麯��
		virtual int cancel();///�˳��߳�
		virtual void run();///�����߳�

		void dirty();
		bool isDirty();

	protected:
		virtual ~WorkThread();

	protected:
		IBeltline* m_pIBeltline;
		bool m_bDone;

	private:
		bool m_bDirty;//�����ǰWorkThread��ThreadPoolɾ������m_bDirty = true;
	};
}

#endif