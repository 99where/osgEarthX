#include <ThreadPool/WorkThread.h>
#include <ThreadPool/IBeltline.h>

using namespace osgXThreads;

#include <iostream>
WorkThread::WorkThread( IBeltline* pBeltline /* = NULL */ )
{
	m_bDone = true;
	m_bDirty = false;

	setIBeltLine( pBeltline );
}

WorkThread::~WorkThread()
{
	dirty();
	cancel();
	std::cout<<"WorkThread distructing..."<<std::endl;
}

void WorkThread::setIBeltLine( IBeltline* pBeltline )
{
	m_pIBeltline = pBeltline;
}

void WorkThread::dirty()
{
	m_bDirty = true;
}

bool WorkThread::isDirty()
{
	return m_bDirty;
}

int WorkThread::cancel()
{
	m_bDone = true;

	while( OpenThreads::Thread::isRunning() )
	{
		OpenThreads::Thread::YieldCurrentThread();
	}

	return OpenThreads::Thread::cancel();
}

void WorkThread::run()
{
	if ( m_pIBeltline == NULL )
	{
		return;
	}

	m_bDone = false;
	osg::ref_ptr< Task > refTask = NULL;

	static bool tempB = false;

	//����ע�⣬ThreadPool pop up ֮��δ�ػ������˳���Ӧ�������˳����롣�����Ͳ�������ThreadPool��������Ϊ
	while( m_bDone == false )
	{
		refTask = m_pIBeltline->popTask();
		if ( ! refTask.valid() )
		{
			continue;
		}

		refTask->doTask();
	}

	m_pIBeltline->addAnIdleThread( this );
}