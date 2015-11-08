#include <ThreadPool/LockMutex.h>
#include <ThreadPool/ThreadPool.h>
using namespace osgXThreads;

#include <iostream>
ThreadPool::ThreadPool( unsigned int threadNum /* = 1 */ )///Ĭ���߳���Ϊ1
{
	setMaxThreadsNum( threadNum );
}

ThreadPool::~ThreadPool()
{
	m_IdleThreadPtrsQueue.empty();
	m_ThreadsRefList.empty();
	std::cout<<"ThreadPool distructing..."<<std::endl;
}

void ThreadPool::setMaxThreadsNum( unsigned int num )
{
	int dist = ( int ) num - m_ThreadsRefList.size();

	if ( dist < 0 )///Ҫ��ThreadsList�м���
	{
		//��ס���ж��У���ʱ������ӿ����߳�
		SCOPEDLOCK_WRITE_MUTEX( m_IdleThreadPtrsQueueMutex );

		//�ȼ��ٿ��е��߳�
		WorkThread* pTempWorkThread = NULL;
		while( m_IdleThreadPtrsQueue.size() > 0 && ( pTempWorkThread = m_IdleThreadPtrsQueue.front(), pTempWorkThread != NULL) )
		{
			m_IdleThreadPtrsQueue.pop();//�ӿ��ж����е�����ǰpTempWorkThread
			m_ThreadsRefList.remove( pTempWorkThread );//���߳��б���ɾ��pTempWorkThread

			dist ++;
			if (dist == 0)
			{
				break;
			}
		}

		//���û�п��е��̣߳���ֱ��������Ŀ
		if ( dist < 0 )
		{
			WorkThread* pTempWorkThread = NULL;
			for ( int i = dist; i < 0; i ++ )
			{
				m_ThreadsRefList.pop_front();
			}
		}

	}

	m_uiMaxThreadsNum = num;
}

unsigned int ThreadPool::getMaxThreadsNum()
{
	return m_uiMaxThreadsNum;
}

void ThreadPool::wakeUp()
{
	//////////////////////////////////////////////////////////////////////////
	///����Ӧ�ÿ����Ƿ����

	///�̳߳��߳�ʣ������
	unsigned int notRealizedThreadsNum = m_uiMaxThreadsNum - m_ThreadsRefList.size();

	//���û���������û�п��еĹ����߳��򷵻�
	if ( TasksManager::getTasksNum() == 0 || getIdleThreadsQueueNum() + notRealizedThreadsNum == 0 )
	{
		return;
	}

	WorkThread* pTempWorkThread = NULL;

	//Ҫͬʱִ���������񣬻���Ҫ���߳���
	unsigned int threadsWanted = TasksManager::getTasksNum() - getIdleThreadsQueueNum();

	//������������ڿ����߳����������߳���δ�����ֵ�������ӹ����߳�
	if ( threadsWanted > 0 && m_ThreadsRefList.size() < m_uiMaxThreadsNum )
	{
		//���̳߳�������Χ�ڣ�׼���������߳�
		unsigned int newThreadsNum = threadsWanted >= notRealizedThreadsNum ? notRealizedThreadsNum : threadsWanted;

		for ( unsigned int i = 0; i < newThreadsNum; i++ )
		{
			pTempWorkThread = new WorkThread( this );
			m_ThreadsRefList.push_front( pTempWorkThread );
			addAnIdleThread( pTempWorkThread );
		}
	}

	///���ѿ����߳̽��й���
	while( ( pTempWorkThread = getAnIdleThread(), pTempWorkThread != NULL ) && TasksManager::getTasksNum() > 0 )
	{
		pTempWorkThread->start();
	}
}

unsigned int ThreadPool::getIdleThreadsQueueNum()
{
	SCOPEDLOCK_READ_MUTEX( m_IdleThreadPtrsQueueMutex );
	return m_IdleThreadPtrsQueue.size();
}

void ThreadPool::addAnIdleThread( WorkThread*pWorkThread )
{
	if ( pWorkThread == NULL || pWorkThread->isDirty() == true )
	{
		return;
	}

	SCOPEDLOCK_WRITE_MUTEX( m_IdleThreadPtrsQueueMutex );
	m_IdleThreadPtrsQueue.push( pWorkThread );
}

WorkThread* ThreadPool::getAnIdleThread()
{
	SCOPEDLOCK_WRITE_MUTEX( m_IdleThreadPtrsQueueMutex );
	WorkThread* pWorkThread = NULL;
	if ( m_IdleThreadPtrsQueue.size() > 0 )
	{
		pWorkThread = m_IdleThreadPtrsQueue.front();
		m_IdleThreadPtrsQueue.pop();
	}

	return pWorkThread;
}