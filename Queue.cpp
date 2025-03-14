#include "Queue.h"


template <typename T>
Queue <T>::Queue (void)
:arrayData (Array<T>(defaultQueueSize)),
back (-1),
front (-1),
elements(0)
{

}

template <typename T>
Queue <T>::Queue (const Queue & queue)
:arrayData (queue.arrayData),
back (queue.back),
front (queue.front),
elements(queue.elements)
{
    
}

template <typename T>
Queue <T>::~Queue (void)
{
    //Since the array is on the stack, no need to delete anything.
}

template <typename T>
const Queue <T> & Queue <T>::operator = (const Queue & rhs)
{
    //First checks if the queues are the same
    if(this == &rhs){
        return *this;
    }
    else{
        this->elements = rhs.elements;
        this->arrayData = rhs.arrayData;
        this->front = rhs.front;
        this->back = rhs.back;
        return *this;
    }
}

template <typename T>
void Queue <T>::enqueue (T element)
{
    // COMMENT You are resizing the queue, but you are wasting space at the front of
    // the array. Fix your design so you use all the space in the array.

    // FIX I didn't think that we were implementing a circular queue, which is why I
    // did the initial design the way I did. However, I've now made the queue a circular
    // one instead of a resizable one, which is what I had originally.

    //Checks if the queue is full by seeing if front is == to 0 and the back+1 is equal to the default size.
    //If so, then the queue is full.
    if(this->back + 1 == defaultQueueSize && this->front == 0){
        throw("Queue is full, cannot enqueue element.");
    }
    //Checks if adding to back will make back and front equal. If so, then the queue is full.
    else if(this->back + 1 == this->front){
        throw("Queue is full, cannot enqueue element.");
    }
    else{
        //Increase back and if it's == to the max size, then we set it to 0 instead
        this->back++;
        if(this->back == defaultQueueSize){
            this->back = 0;
        }
        //If the queue is empty, then we increase front as well.
        if(this->front == -1){
            this->front++;
        }
        //Set the back spot to the element
        arrayData.set(back, element);
        this->elements++;
    }
    
    
}

template <typename T>
T Queue <T>::dequeue (void)
{
    if(this->is_empty()){
        throw ("Cannot dequeue because queue is empty");
    }
    else{
        // COMMENT This solution will work, but you are wasting space at the front
        // of the array since those "unused" spaces will never be used again. Please
        // come up with a better design that uses memory more efficiently.

        // FIX I didn't initially think we were doing a circular queue, but I've now
        // implemented a circular queue to ensure the array has no dead space. It is
        // no longer resizable as it was originally, but it's more memory efficient.
        
        //Set the return then change appropriate variables
        T toReturn = arrayData.get(front);
        if(this->front == this->back){
            this->front = -1;
            this->back = -1;
        }
        else{
            if(this->front == defaultQueueSize - 1){
                this->front = 0;
            }
            else{
                this->front++;
            }
        }
        this->elements--;
        return toReturn;
    }     
}

template <typename T>
bool Queue <T>::is_empty (void) const
{
    if(elements == 0){
        return true;
    }
    else{
        return false;
    }
}

template <typename T>
size_t Queue <T>::size(void) const
{
    return elements;
}

template <typename T>
void Queue <T>::clear (void)
{
    //Resizes the array to 0 then shrinks it. Lastly, set the 0th element to a null terminator
    arrayData.resize(0);
    arrayData.shrink();
    back = -1;
    front = -1;
    elements = 0;
}
