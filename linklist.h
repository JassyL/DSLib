#ifndef LINKLIST_H
#define LINKLIST_H

#include "list.h"
#include "exception.h"

namespace DSLib
{

template<typename T>
class LinkList : public List<T>
{
protected:
    struct Node : public Object
    {
        T value;
        Node* next;
    };

    mutable Node m_header;
    int m_length;

public:
    LinkList()
    {
        m_header.next = NULL;
        m_length = 0;
    }

    bool insert(const T& e)
    {
        return insert(m_length, e);
    }
    bool insert(int i, const T& e)
    {
        bool ret = ((0 <= i) && (i <= m_length));
        if(ret)
        {
            Node* node = new Node();

            if( node != nullptr)
            {
                Node* current = &m_header;

                for(int p=0; p<i; i++)
                {
                    current = current->next;
                }

                node->value = e;
                node->next = current->next;
                current->next = node;

                m_length++;
            }
            else
            {
                THROW_EXCEPTION(NoEnoughMemoryException,"No enough memory to insert ...");
            }
        }

        return ret;
    }
    bool remove(int i)
    {
        bool ret = ((0 <= i) && (i < m_length));
        if(ret)
        {
            Node* current = &m_header;

            for(int p=0; p<i; i++)
            {
                current = current->next;
            }

            Node* toDel = current->next;

            current->next = toDel->next;

            delete toDel;

            m_length--;
        }

        return ret;
    }
    bool set(int i, const T& e)
    {
        bool ret = ((0 <= i) && (i < m_length));
        if(ret)
        {
          Node* current = &m_header;

          for(int p=0; p<i; i++)
          {
              current = current->next;
          }

          current->next->value = e;
        }

        return ret;
    }
    bool get(int i, T& e) const
    {
        bool ret = ((0 <= i) && (i < m_length));
        if(ret)
        {
            Node* current = &m_header;

            for(int p=0; p<i; i++)
            {
                current = current->next;
            }

            e = current->next->value;
        }

        return ret;
    }
    int length() const
    {
        return m_length;
    }
    void clear()
    {
        while( m_header.next )
       {
           Node* toDel = m_header.next;

           m_header.next = toDel->next;

           delete toDel;
       }

       m_length = 0;
    }
};

}

#endif // LINKLIST_H