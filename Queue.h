#ifndef _QUEUE_H_
#define _QUEUE_H_

#include "Array.h"

#define defaultQueueSize 100

template <typename T>
class Queue{
    public:
        //Type definition
        typedef T type;

        //Default Constructor
        Queue (void);

        //Copy Constructor
        Queue (const Queue & queue);

        //Destructor
        ~Queue (void);

        //Assignment operator
        const Queue & operator = (const Queue & rhs);

        //Enqueue an element into the queue
        void enqueue (T element);

        //Dequeue an element
        T dequeue (void);

        //Checks if the queue is empty
        bool is_empty(void) const;

        //Return the size of the queue
        size_t size(void) const;

        //Clear the queue
        void clear(void);

    private:
        size_t back;
        size_t front;
    
    // COMMENT There is no need to allocate the array on the heap. Always try to
    // allocate on the stack to reduce the complexity of your code.

    // FIX Changed arrayData to put it on the stack instead of the heap.
    
        Array<T> arrayData;
        size_t elements;
};

#include "Queue.cpp"
#endif
