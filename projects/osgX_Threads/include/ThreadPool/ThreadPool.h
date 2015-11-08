/**
	@brief �̳߳���
	@author Hao Luo
	@date 2014/11/04
	@description �̳߳ؾ߱���̬��ӹ����̣߳�ֱ���趨���������ֵ������̬�������Ĺ���
*/

#ifndef OSGX_THREADS_THREAD_POOL_H
#define OSGX_THREADS_THREAD_POOL_H 1

#include <osgXThreadsExport/Export.h>

#include <ThreadPool/IBeltline.h>
#include <ThreadPool/WorkThread.h>

#include <list>
#include <queue>

namespace osgXThreads
{
	class OSGX_THREADS_EXPORT ThreadPool : 
		public IBeltline
	{
	public:
		typedef std::list< osg::ref_ptr< WorkThread > > WorkThreadRefList;
		typedef WorkThreadRefList::iterator WorkThreadRefListIterator;
		typedef std::queue< WorkThread* > IdleWorkThreadPtrQueue;

	public:
		ThreadPool( unsigned int threadNum = 1 );
		virtual ~ThreadPool();

		///����������߳�
		void setMaxThreadsNum( unsigned int num );
		unsigned int getMaxThreadsNum();

		virtual void wakeUp();

	protected:
		virtual void addAnIdleThread( WorkThread*pWorkThread );

		///��ȡ�����߳���Ŀ
		unsigned int getIdleThreadsQueueNum();

		///��ȡһ�������߳�
		WorkThread* getAnIdleThread();

	protected:
		///�����߳��б�����Ϊ�����߳���������ΪWorkThreadList���漰���̷߳��ʣ�������������߳���
		WorkThreadRefList m_ThreadsRefList;

		///����״̬�е��߳�ָ�����
		IdleWorkThreadPtrQueue m_IdleThreadPtrsQueue;
		OpenThreads::ReadWriteMutex m_IdleThreadPtrsQueueMutex;

	private:
		unsigned int m_uiMaxThreadsNum;
	};
}

#endif