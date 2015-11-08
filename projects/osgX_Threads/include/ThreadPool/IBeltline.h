/**
	@brief �����߽ӿ�
	@author Hao Luo
	@date 2015/03/17
	@description һ�������߿�����һ���Ͷ��������ִ��һ�����߶������
*/

#ifndef OSGX_THREADS_I_BELTLINE_H
#define OSGX_THREADS_I_BELTLINE_H 1

#include <osgXThreadsExport/Export.h>

#include <ThreadPool/TasksManager.h>

namespace osgXThreads
{
	class WorkThread;

	class OSGX_THREADS_EXPORT IBeltline : public TasksManager
	{
	public:
		IBeltline();
		virtual ~IBeltline();

		/**
			����˯���еĹ����߳�
		*/
		virtual void wakeUp() = 0;

		///������񣬲������̳߳�
		virtual void addTaskAndWakeUp( Task* pTask );

	protected:
		friend WorkThread;
		///��ӿ����̣߳�����������WorkThread�����굱ǰ����ʱ�������ô˷���֪ͨ�����߸�WorkThread�Ѿ����ڿ���״̬
		virtual void addAnIdleThread( WorkThread* pWorkThread ) = 0;

	private:
	};
}

#endif