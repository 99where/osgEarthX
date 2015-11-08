/**
	@brief ���������������������̵߳���˳����ԭ�ȼ������һ���࣬ʹ���մ�����Ԥ�ڴ������
	@author Hao Luo
	@date 2014/12/20
*/

#ifndef OSGX_THREADS_ORDER_HOLDERS_CONTAINER_H
#define OSGX_THREADS_ORDER_HOLDERS_CONTAINER_H 1

#include <OpenThreads/Mutex>
#include <OpenThreads/ScopedLock>
#include <ThreadPool/LockMutex.h>
#include <ThreadPool/OrderHoldersContainer/OrderHolder.h>

#include <Utils/DynamicVector.h>
#include <list>

namespace osgXThreads
{
	template< class T >
    class OrderHoldersContainer
	{
	public:
		typedef std::list< OrderHolder* > OrderHolderPtrs;
		typedef OrderHolderPtrs::iterator OrderHolderIter;

	protected:
		DynamicVector< T > m_Original;//ԭʼ��������������
		OrderHolderPtrs* m_pArrival;//ʵ�ʵ���

		//m_pArrival�����̷߳��ʣ����Զ�˳��ĸ�����Ҫ�Ӵ���
		OpenThreads::Mutex m_Mutex;

	public:
		//���캯���������ڲ�����
		OrderHoldersContainer();
		virtual ~OrderHoldersContainer();

		//ΪpOrderHolder��Ӽ��ش��򲢼��뵽�ڲ��б���
		void push( T* pOrderHolder );//�ڲ�����
		void insert( T* pOrderHolder, unsigned int expectOrder );

		//���ص���󣬲����˳��
		//�豣֤pOrderHolder���ڲ��б���
		//���ص�ǰ����m_pArrival�б��еİ�������Order����Ĵ���
		// -1 : ���
		// -2 : ������Ҫ��
		int signArrival( T* pOrderHolder );

		/**
			@brief �ƶ�
			@param pOrderHolder ����,
			@param newOrder �´���λ�ã�
			@param outNewArrivalOrder ����ƶ��ɹ������Ѿ�������˵ģ��򷵻��µ���λ��
		*/
		bool move( T* pOrderHolder, unsigned int newOrder, unsigned int* outNewArrivalOrder = NULL );

		/**
			@brief �ƶ�
			@param oldOrder ��λ��,
			@param newOrder �´���λ�ã�
			@param outNewArrivalOrder ����ƶ��ɹ������Ѿ�������˵ģ��򷵻��µ���λ��
		*/
		bool move( unsigned int oldOrder, unsigned int newOrder, unsigned int* outNewArrivalOrder = NULL );

		//ɾ��
		bool remove( T* pOrderHolder );
		bool remove( unsigned int order );

		unsigned int size();

		T* operator [] ( unsigned int index );

	protected:
		//δ����

		//��ȡ�Ѿ������λ��
		int _signArrival( T* pOrderHolder );

		/**
			@brief �ƶ����Ѿ�arrival�Ľ����m_pArrival���Ƴ��������Ϊδarrival�������µ���signArrival����ȡ���µĲ���λ��
			@param oldIndex ��λ��,
			@param newOrder �´���λ�ã�
			@param outNewArrivalOrder ����ƶ��ɹ������Ѿ�������˵ģ��򷵻��µ���λ��
		*/
		bool _move( unsigned int oldIndex, unsigned int newOrder, unsigned int* outNewArrivalOrder = NULL );

		bool _remove( unsigned int order );
	};

    template< class T >
    OrderHoldersContainer< T >::OrderHoldersContainer()
	{
		m_pArrival = new OrderHolderPtrs;
	}

    template< class T >
    OrderHoldersContainer< T >::~OrderHoldersContainer()
	{
		delete m_pArrival;
	}

    template< class T >
    void OrderHoldersContainer< T >::push( T* pOrderHolder )
	{
		if ( pOrderHolder == NULL )
		{
			return;
		}

		SCOPEDLOCK_MUTEX( m_Mutex );
		pOrderHolder->uiOrder = m_Original.size();
		m_Original.pushBack( pOrderHolder );
	}

	template < class T >
    void OrderHoldersContainer< T >::insert( T* pOrderHolder, unsigned int expectOrder )
	{
		SCOPEDLOCK_MUTEX( m_Mutex );
		if ( pOrderHolder == NULL )
		{
			return;
		}

		for ( unsigned int i = expectOrder; i < m_Original.size(); i ++ )
		{
			m_Original[ i ]->uiOrder ++;
		}

		pOrderHolder->uiOrder = expectOrder >= m_Original.size() ? m_Original.size() : expectOrder;
		m_Original.insert( pOrderHolder, expectOrder );
	}

	template < class T >
    int OrderHoldersContainer< T >::signArrival( T* pOrderHolder )
	{
		SCOPEDLOCK_MUTEX( m_Mutex );
		return _signArrival( pOrderHolder );
	}

	template< class T >
	int OrderHoldersContainer< T >::_signArrival( T* pOrderHolder )
	{
		if ( pOrderHolder == NULL || pOrderHolder->bArrival == true )
		{
			return -2;
		}

        int pos = 0;
		OrderHolderIter itr = m_pArrival->begin();

		for ( ; itr != m_pArrival->end(); itr ++ )
		{
			if ( pOrderHolder->uiOrder < (*itr)->uiOrder )
			{
				break;
			}
			pos ++;
		}

		if ( itr == m_pArrival->end() )
		{
			m_pArrival->push_back( pOrderHolder );
			pos = -1;
		}
		else
		{
			m_pArrival->insert( itr, pOrderHolder );
		}
		pOrderHolder->bArrival = true;

		return pos;
	}

    template < class T >
    bool OrderHoldersContainer< T >::move( T* pOrderHolder, unsigned int newOrder, unsigned int* outNewArrivalOrder )
	{
		if ( pOrderHolder == NULL )
		{
			return false;
		}

		SCOPEDLOCK_MUTEX( m_Mutex );

		int oldIndex = m_Original.getIndex( pOrderHolder );
		if ( -1 >= oldIndex )
		{
			return false;
		}

		return _move( ( unsigned int ) oldIndex, newOrder, outNewArrivalOrder );
	}

	template < class T>
    bool OrderHoldersContainer< T >::move( unsigned int oldIndex, unsigned int newOrder, unsigned int* outNewArrivalOrder )
	{
		SCOPEDLOCK_MUTEX( m_Mutex );
		return _move( oldIndex, newOrder, outNewArrivalOrder );
	}

    template < class T >
    bool OrderHoldersContainer< T >::_move( unsigned int oldIndex, unsigned int newOrder, unsigned int* outNewArrivalOrder )
	{
		if ( oldIndex > m_Original.size() || newOrder >= m_Original.size() || oldIndex == newOrder )
		{
			return false;
		}

		if ( oldIndex < newOrder )
		{
			for ( unsigned int i = oldIndex + 1; i <= newOrder; i ++ )
			{
				m_Original[ i ]->uiOrder --;
			}
		}
		else
		{
			for ( unsigned int i = newOrder; i < oldIndex; i ++ )
			{
				m_Original[ i ]->uiOrder ++;
			}
		}

		T* pOrderHolder = m_Original[ oldIndex ];
		pOrderHolder->uiOrder = newOrder;
		bool bMove = m_Original.move( oldIndex, newOrder );

		//����Ѿ�arrival�����arrival��ɾ��
		if ( bMove && pOrderHolder->bArrival )
		{
			m_pArrival->remove( pOrderHolder );
			pOrderHolder->bArrival = false;//����Ϊδȷ��λ�õ�״̬

			//����������Ҫ��pOrderHolder�ٴ�signArrival( pOrderHolder )�Ի�ȡ����λ��
			int arrivalOrder = _signArrival( pOrderHolder );
			if ( outNewArrivalOrder )
			{
				*outNewArrivalOrder = arrivalOrder == -1 ? m_pArrival->size() - 1 : arrivalOrder;
			}
		}

		return bMove;
	}

    template < class T >
    bool OrderHoldersContainer< T >::remove( T* pOrderHolder )
	{
        if ( pOrderHolder == NULL )
		{
			return false;
		}

        SCOPEDLOCK_MUTEX( m_Mutex );

        int index = m_Original.getIndex( pOrderHolder );
		if ( -1 == index )
		{
			return false;
		}

		return _remove( ( unsigned int ) index );
	}


    template < class T >
    bool OrderHoldersContainer< T >::remove( unsigned int order )
	{
        SCOPEDLOCK_MUTEX( m_Mutex );
        return _remove( order );
	}

    template < class T >
    bool OrderHoldersContainer< T >::_remove( unsigned int order )
	{
        m_pArrival->remove( m_Original[ order ] );

		for ( unsigned int i = order + 1; i < m_Original.size(); i ++ )
		{
			m_Original[i]->uiOrder --;
		}

		return m_Original.remove(order);
	}

	template < class T >
    unsigned int OrderHoldersContainer< T >::size()
	{
		SCOPEDLOCK_MUTEX(m_Mutex);
		return m_Original.size();
	}

    template < class T >
    T* OrderHoldersContainer< T >::operator [] (  unsigned int index )
	{
        SCOPEDLOCK_MUTEX( m_Mutex );
        return m_Original[ index ];
	}
}

#endif
