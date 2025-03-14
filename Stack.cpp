// $Id: Stack.cpp 827 2011-02-07 14:20:53Z hillj $

// Honor Pledge:
//
// I pledge that I have neither given nor received any help
// on this assignment.

#include "Stack.h"

//
// Stack Default
//
template <typename T>
Stack <T>::Stack (void)
:currentIndex(0),
arrayData(Array<T>(defaultSize))
{
    
}

//
// Stack Copy
//
template <typename T>
Stack <T>::Stack (const Stack & stack)
:currentIndex(0),
arrayData(Array<T>(stack.size()))
{
    //Push every element from the stack to this. We do stack.size() + 1 to grab the current top element
    for(size_t i = 0; i < stack.size() + 1; i++){
        this->push(stack.arrayData.get(i));
    }
}

//
// ~Stack Destructor
//
template <typename T>
Stack <T>::~Stack (void)
{
    //Since we don't have anything from the Stack on the heap, we can leave this blank.
}

//
// push
//
template <typename T>
void Stack <T>::push (T element)
{
    //The instructions say before all other items. Does this mean it's inserted at position 0 and we shift all other items over?
    //If so, isn't that horribly inefficient, since we could just put the pushed item in the front of the array and get the exact
    //same result with much much less processing power (by having to swap the entire array). I'm going to do it the way I believe
    //is the more efficient way, but if you want me to do it the other way, let me know and I will.

    //Additionally, this check doesn't seem to work. I try to check if the types of data are the same, but I can never get this to
    //be anything but true. Any insight on that?
    if(typeid(element) == typeid(arrayData.get(currentIndex - 1))){
        currentIndex++;
        //Checks if we need to resize. If we do, then we add an additional 10 elements to the stack to hopefully avoid resizing later
        if(arrayData.size() <= currentIndex){
            arrayData.resize(currentIndex + 10);
        }
        //For some reason, this is is trying to call the set 2 arrays equal instead of returning the value of
        //the specified index:
        //arrayData[currentIndex] = element;
        //Needed to do it the following way instead
        arrayData.set(currentIndex, element);
    }
    else{
        throw ("The data types don't match");
    }
}

//
// pop
//
template <typename T>
void Stack <T>::pop (void)
{
    //I think in a normal stack that pop is supposed to return a value, but here it's void. I'll leave it as is,
    //but if I need to change it let me know and I can fairly easily.
    
    if(this->is_empty()){
        throw ("The stack is empty");
    }
    //All we need to do is decrement the index. Now the top will point below the previous value and it will never
    //increase until something is pushed, where the value will be overwritten anyway.
    currentIndex--;
}

//
// operator =
//
template <typename T>
const Stack <T> & Stack <T>::operator = (const Stack & rhs)
{
    //First checks if the stacks are the same
    if(this == &rhs){
        return *this;
    }
    // COMMENT It would be easier if you just use the assignment operator
    // on the array to copy things from rhs.

    // FIX I needed to add an assignment operator to the resizable array,
    // but it now works much better.
    else{
        this->currentIndex = rhs.currentIndex;
        this->arrayData = rhs.arrayData;
        return *this;
    }
}

//
// clear
//
template <typename T>
void Stack <T>::clear (void)
{
    //Resize the array to 0, shrink for space, then set the index to 0
    arrayData.resize(0);
    arrayData.shrink();
    this->currentIndex = 0;
}

//
// is_empty
//
//Moved from inline to here.
template <typename T>
bool Stack <T>::is_empty (void) const
{
    //Checks if the current index is less than 0, which means it's empty. Otherwise, there's something there.
    if(this->currentIndex < 1){
        return true;
    }
    else{
        return false;
    }
}

//
// top
//
//I moved from inline to here, because more than one line of code is needed. I think.
template <typename T>
T Stack <T>::top (void) const
{
    //Checks if empty first. Otherwise, return the top element
    if(this->is_empty()){
        throw ("Stack is empty");
    }
    else{
        return arrayData.get(currentIndex);
    }
    
}
