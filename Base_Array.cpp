// $Id: Array.cpp 827 2011-02-07 14:20:53Z hillj $

// Honor Pledge:
//
// I pledge that I have neither given nor receieved any help
// on this assignment.

#include "Base_Array.h"
#include <typeinfo>

//
// Array
//
template <typename T>
Base_Array <T>::Base_Array (void)
: data_ (nullptr), 
cur_size_ (0), 
max_size_ (0)
{
    this->data_ = new T[max_size_];
}

//
// Array (size_t)
//
template <typename T>
Base_Array <T>::Base_Array (size_t length)
: data_ (nullptr), 
cur_size_ (length), 
max_size_ (length)
{
   this->data_ = new T[length];
}

//
// Array (size_t, char)
//
template <typename T>
Base_Array <T>::Base_Array (size_t length, T fills)
: data_ (nullptr), 
cur_size_ (length), 
max_size_ (length)
{
    this->data_ = new T[max_size_];
    fill(fills);
}

//
// Array (const Array &)
//
template <typename T>
Base_Array <T>::Base_Array (const Base_Array<T> & array)
: data_ (nullptr), 
cur_size_ (5), 
max_size_ (5)
{
    //I initially tried to check for types to make sure the array being copied was of the same type, but I couldn't get it to work
    //Additionally, I noticed that it caused an error to try and sent it anyways, so the compiler should make sure the user doesn't
    //enter an incorrect array type.
    
    //Gets the size of the array to be copied, then sets the initial values 
    size_t length = array.size();
    this->max_size_ = length;
    this->cur_size_ = length;
    this->data_ = new T[length];
    //The header and instructions didn't mention whether to make this a shallow or deep copy. On my eyes, the user would probably want to
    //Have a separate copy of the array, so I'm going to make a deep copy. I remember we discussed shallow vs deep copy in class, but I
    //think it was for slice, not this constructor
    for(size_t i = 0; i < length; i++){
        *(this->data_ + i) = array.get(i);
    }
}

//
// ~Array
//
template <typename T>
Base_Array <T>::~Base_Array (void)
{
    delete[] this->data_;
    this->data_ = nullptr;
}

//
// operator =
//
template <typename T>
const Base_Array <T> & Base_Array <T>::operator = (const Base_Array & rhs)
{
    //Checks if the 2 arrays are actully the same array
    if (this == &rhs){
        return * this;
    }
    //Makes sure the 2 arrays are the same size. Otherwise, we can't set the values of one to the other
    else if(this->cur_size_ == rhs.size()){
        //Sets every value in the left side of the array to every value in the rhs
        for(size_t i = 0; i < this->size(); i ++){
            this->set(i, rhs.get(i));
        }
        return * this;
    }
    //Throws an error since the 2 arrays cannot be set equal to each other
    else{
        throw("Cannot set the arrays equal, as they aren't the same size");
        exit(-1);
    }    
}

//
// operator []
//
template <typename T>
T & Base_Array <T>::operator [] (size_t index)
{
    //Checks if the index is greater than the current size, which will throw an error. Otherwise, returns the data at the index.
    if(index >= cur_size_){
        throw std::out_of_range("Index is out of range of the array");
    }
    //Returns the value at index
    return *(this->data_ + index);
}

//
// operator [] 
//
template <typename T>
const T & Base_Array <T>::operator [] (size_t index) const
{
    //Checks if the index is greater than the current size, which will throw an error. Otherwise, returns the data at the index.
    if(index >= cur_size_){
        throw std::out_of_range("Index is out of range of the array");
    }
    //Returns the value at index
    return *(this->data_ + index);
}

//
// get
//
template <typename T>
T Base_Array <T>::get (size_t index) const
{
    //Checks if the index is greater than the current size, which will throw an error. Otherwise, returns the data at the index.
    if(index >= cur_size_){
        throw std::out_of_range("Index is out of range of the array");
    }
    else{
        return *(data_ + index);
    }
}

//
// set
//
template <typename T>
void Base_Array <T>::set (size_t index, T value)
{
    //Checks if index is out of bounds
    if(index >= cur_size_){
        throw std::out_of_range("Index is out of range of the array");
    }
    //Sets the data to value
    else{
        *(data_ + index) = value;
    }
}

//
// find (char)
//
template  <typename T>
int Base_Array <T>::find (T value) const
{
    try{
        return this->find(value, 0);
    }
    catch(...){
        return -1;
    }
}

//
// find (char, size_t) 
//
template <typename T>
int Base_Array <T>::find (T val, size_t start) const
{
    //Checks if the start is out of range and throws an exception if it is.
    if(start >= this->cur_size_){
        throw std::out_of_range("Index is out of range of the array");
    }
    //i starts at start
    for(size_t i = start; i < this->cur_size_; i++){
        //Compares each element from start to the target ch. Returns i if found.
        if(*(data_ + i) == val){
            return i;
        }
    }
    //If the loop completed without returning, then the val didn't exist, so return -1
    return -1;
}

//
// operator ==
//
template <typename T>
bool Base_Array <T>::operator == (const Base_Array & rhs) const
{
    if(this == &rhs){
        return true;
    }
    else{
        //Checks if the 2 arrays are the same size
        if(rhs.size() == this->cur_size_){
            //Loops through each element in this array
            for(size_t i = 0; i < this->cur_size_; i++){
                //If this array and rhs are NOT equal, then return false
                if(!(*(this->data_ + i) == rhs.get(i))){
                    return false;
                }
            }
            //If the for loop completes without returning false, then the arrays are the same size and contain the same elements, so return true
            return true;
        }
        //If the arrays are not the same size, then return false, since they are not equal
        return false;
    }
}

//
// operator !=
//
template <typename T>
bool Base_Array <T>::operator != (const Base_Array & rhs) const
{
    //Checks if the 2 arrays are equal. If so, return false, else return true
    if(*this == rhs){
        return false;
    }
    else{
        return true;
    }
}

//
// fill
//
template <typename T>
void Base_Array <T>::fill (T value)
{
    //Runs through each element and sets it to ch
    for(size_t i = 0; i < cur_size_; i++){
        *(this->data_ + i) = value;
    }
}

//The instructions didn't specify cases where the max size is greater than the current size. If there's data in the unaccessible part of the array,
//then that would get flipped over too. However, in my eyes, the user wants to reverse the array they currently have, so I'm only reversing from
//cur_size_. This prevents surprising data from showing up, or from users "losing" now unaccessible data.
template <typename T>
void Base_Array <T>::reverse (void)
{
    T temp;
    //Sets up 2 variables, up and down. Up starts at the begining of the array and down starts at the end.
    //When up = down or exceeds down, then the points have crossed and we can exit the loop
    for(size_t up = 0, down = cur_size_ - 1; up <= down; up++, down--){
        //Puts up in temp, then sets up to down, and down to temp, swapping the values.
        temp = *(data_ + up);
        *(data_ + up) = *(data_ + down);
        *(data_ + down) = temp;
    }
}

template <typename T>
Base_Array<T> Base_Array <T>::slice (size_t begin) const
{
    //Makes sure that begin is within the bounds of the array
    if(begin >= this->cur_size_){
        throw std::out_of_range("Index is out of range of the array");
        exit(-1);
    }
    else{
        //Sets the size of the new array
        size_t newSize = 1 + (size() - begin);
        //Creates a a pointer to a new array on the heap
        Base_Array<T> * newArray = new Base_Array<T>(newSize);
        //Gets the starting point of the data by adding the index to the first element
        T * values = this->get_data() + begin;
        //Sets the data starting point of the new array and then returns the value at that position
        newArray->set_data(values);
        return Base_Array(*newArray);
    }
}

template <typename T>
Base_Array<T> Base_Array <T>::slice (size_t begin, size_t end) const
{
    //Checks if the end and begin points don't cross the wrong way
    if(end < begin){
        throw ("The end point is greater than the begining point");
        exit(-1);
    }
    //Makes sure we stay within the bounds of the array
    else if(end > this->max_size_){
        throw ("The end point is greater than the current size of the array");
        exit(-1);
    }
    else{
        //Sets the size of the new array
        size_t newSize = 1 + (end - begin);
        //Creates a a pointer to a new array on the heap
        Base_Array<T> * newArray = new Base_Array<T>(newSize);
        //Gets the starting point of the data by adding the index to the first element
        T * values = this->get_data() + begin;
        //Sets the data starting point of the new array and then returns the value at that position
        newArray->set_data(values);
        return Base_Array(*newArray);
    }
}

template <typename T>
T * Base_Array<T>::get_data() const{
    return this->data_;
}

template <typename T>
void Base_Array<T>::set_data(T * data){
    this->data_ = data;
}
