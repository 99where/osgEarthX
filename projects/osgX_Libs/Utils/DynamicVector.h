/*
	@brief ��̬������
	@author Hao Luo
	@date 2014/11/26
*/

#ifndef OSGX_LIBS_DYNAMIC_VECTOR_H
#define OSGX_LIBS_DYNAMIC_VECTOR_H 1

#include <vector>
#include <osg/Referenced>
#include <osg/ref_ptr>

template<class VectorItem = osg::Referenced>
class DynamicVector
{
public:
	typedef std::vector< osg::ref_ptr< VectorItem >* > PtrVectorOfRefPtr;//ָ��VectorItem��ref_ptrָ���ָ��

	DynamicVector()
	{
		m_pPtrVectorOfRefPtr = NULL;
	}

	virtual ~ DynamicVector()
	{
		clear();
		delete m_pPtrVectorOfRefPtr;
	}

	PtrVectorOfRefPtr* getOrCreateVector()
	{
		if ( m_pPtrVectorOfRefPtr == NULL )
		{
			m_pPtrVectorOfRefPtr = new PtrVectorOfRefPtr;
		}

		return m_pPtrVectorOfRefPtr;
	}

	bool valid()
	{
		return m_pPtrVectorOfRefPtr == NULL ? false : true;
	}

	void clear()//�������
	{
		if ( m_pPtrVectorOfRefPtr )
		{
			for ( unsigned int i = 0, vectorSize = size(); i < vectorSize; i++ )
			{
				delete m_pPtrVectorOfRefPtr->at( i );
			}
			m_pPtrVectorOfRefPtr->clear();
		}
	}

	void pushBack( VectorItem* pVectorItem )
	{
		getOrCreateVector()->push_back( new osg::ref_ptr<VectorItem>( pVectorItem ) );
	}

	void insert( VectorItem* pVectorItem, unsigned int pos )
	{
		if ( pos >= getOrCreateVector()->size() )
		{
			pushBack( pVectorItem );
		}
		else
		{
			getOrCreateVector()->insert( getOrCreateVector()->begin() + pos, new osg::ref_ptr<VectorItem>( pVectorItem ) );
		}
	}

	bool remove( VectorItem* pVectorItem )
	{
		int index = getIndex( pVectorItem );
		if ( -1 == index )
		{
			return false;
		}

		return remove( ( unsigned int ) index );
	}

	bool remove( unsigned int index )
	{
		if ( ! valid() || index >= size() )
		{
			return false;
		}
		delete m_pPtrVectorOfRefPtr->at( index );//ɾ��new��ref_ptr����

		m_pPtrVectorOfRefPtr->erase( m_pPtrVectorOfRefPtr->begin() + index );
		return true;
	}

	bool move( VectorItem* pVectorItem, unsigned int newIndex )
	{
		int index = getIndex( pVectorItem );
		if ( -1 == index )
		{
			return false;
		}

		return move( ( unsigned int ) index, newIndex );
	}

	bool move( unsigned int curIndex,unsigned int newIndex )
	{
		unsigned int vectorSize = size();
		if ( !valid() || curIndex >= vectorSize || newIndex >= vectorSize || curIndex == newIndex )
		{
			return false;
		}

		osg::ref_ptr<VectorItem>* pRefPtr = m_pPtrVectorOfRefPtr->at( curIndex );
		m_pPtrVectorOfRefPtr->erase( m_pPtrVectorOfRefPtr->begin() + curIndex );

		if ( newIndex >= vectorSize -1 )//newIndex����curIndex, ����ɾ��curIndex֮��newIndex�����size()�����Է������
		{
			m_pPtrVectorOfRefPtr->push_back( pRefPtr );
		}
		else
		{
			m_pPtrVectorOfRefPtr->insert( m_pPtrVectorOfRefPtr->begin() + newIndex, pRefPtr );
		}

		return true;
	}

	// -1 : û����
	int getIndex( VectorItem* pVectorItem )
	{
		//�����ȡһ������ΪpVectorItem = NULL��λ�������������������
		if ( ! valid() )
		{
			return -1;
		}

		for ( unsigned int i = 0, vectorSize = size(); i < vectorSize; i ++ )
		{
			if ( pVectorItem == *( ( *m_pPtrVectorOfRefPtr )[ i ] ) )
			{
				return i;
			}
		}

		return -1;
	}

	VectorItem* operator [] (unsigned int index)
	{
		if (!valid() || index >= size())
		{
			return NULL;
		}

		return *( *m_pPtrVectorOfRefPtr )[ index ];
	}

	unsigned int size()
	{
		if (!valid())
		{
			return 0;
		}

		return m_pPtrVectorOfRefPtr->size();
	}

private:
	PtrVectorOfRefPtr* m_pPtrVectorOfRefPtr;
};
#endif