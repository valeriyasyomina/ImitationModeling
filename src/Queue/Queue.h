#ifndef QUEUE_H
#define QUEUE_H

#include "QueueElement.h"

template <class TypeName>
class Queue
{
private:
    QueueElement<TypeName>* head;
    int size;
    int maxSize;
public:
    //Queue() {}
    Queue(int maxSize);
    Queue(const Queue& queue);
    Queue operator=(const Queue& queue);
    ~Queue();

    void Add(TypeName value);
    TypeName Get();
    bool isEmpty() {return !size ? true : false;}
};

template <class TypeName>
Queue<TypeName>::Queue(int maxSize)
{
    if (maxSize <= 0)
    {
        // exception
    }
    this->maxSize = maxSize;
    size = 0;
    head = NULL;
}

template <class TypeName>
Queue<TypeName>::Queue(const Queue<TypeName>& queue)
{
    //for (int i = 0; i < queue.size; i++)
       // this->Add(queue.);
}

template <class TypeName>
Queue<TypeName> Queue<TypeName>::operator=(const Queue<TypeName>& queue)
{

}

template <class TypeName>
Queue<TypeName>::~Queue()
{
    if (head)
    {
        QueueElement<TypeName>* curPointer = head;
        for (; curPointer; curPointer = head)
        {
            head = head->next;
            delete head;
        }
        size = 0;
        maxSize = 0;
    }
}
template <class TypeName>
void Queue<TypeName>::Add(TypeName value)
{
    if (size >= maxSize)
    {
        //exc
    }
    if (!head)
    {
        head = new QueueElement<TypeName>(value);
        //exc
        size++;
    }
    else
    {
        QueueElement<TypeName>* curPointer = head;
        for (; curPointer->next; curPointer = curPointer->next)
            ;
        QueueElement<TypeName>* element = new QueueElement<TypeName>(value);
        //exception
        curPointer->next = element;
        size++;
    }
}
template <class TypeName>
TypeName Queue<TypeName>::Get()
{
    if (!size)
    {
        //exception
    }
    TypeName value = head->value;
    QueueElement<TypeName>* currentPointer = head;
    head = head->next;
    delete currentPointer;
    size--;
    return value;
}


#endif // QUEUE_H
