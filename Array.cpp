// $Id: Array.cpp 827 2011-02-07 14:20:53Z hillj $

// Honor Pledge:
//
// I pledge that I have neither given nor receieved any help
// on this assignment.

#include "Array.h"
#include <typeinfo>

//
// Array
//
template <typename T>
Array<T>::Array (void)
{
    this->cur_size_ = 0;
    this->max_size_ = 0;
    this->data_ = new T[this->max_size()];
}

//
// Array (size_t)
//
template <typename T>
Array<T>::Array (size_t length)
{
    this->cur_size_ = length;
    this->max_size_ = length;
    this->data_ = new T[length];
}

//
// Array (size_t, char)
//
template <typename T>
Array<T>::Array (size_t length, T fills)
{
    this->max_size_ = length;
    this->cur_size_ = length;
    this->data_ = new T[this->max_size_];
    this->fill(fills);
}

//
// Array (const Array &)
//
template <typename T>
Array<T>::Array (const Array & array)
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
Array<T>::~Array (void)
{
    delete[] this->data_;
    this->data_ = nullptr;
}

//
// resize
//
template <typename T>
void Array<T>::resize (size_t new_size)
{
    //If the new size is greater than the max size
    if(new_size > this->max_size_){
        //Create a new array and fill it with the old array's values.
        T * newArray = new T[new_size];
        for(size_t i = 0; i < new_size; i++){
            //Once the size of the initial array has been exceeded, then we fill the rest with spaces to avoid having junk data
            if(this->max_size_ <= i){
                newArray[i] = '\0';
            }
            //Fills the new array with the previous values
            else{
                newArray[i] = *(this->data_ + i);
            }
        }
        //Delete the old array to free up memory, then set the new parameters 
        delete [] this->data_;
        this->data_ = newArray;
        this->max_size_ = new_size;
        this->cur_size_ = new_size;
    }
    else{
        //If the new size is smaller than the max size, then we simply set the current size to new size, without worrying about changing the actual size of the array
        this->cur_size_ = new_size;
    }
}

template <typename T>
void Array<T>::shrink (void){
    //Creates a new T array on the heap with the current size
    T * newArray = new T[this->cur_size_];
    //Fills the new array with the data of the current array
    for(int i = 0; i < this->size(); i++){
        newArray[i] = *(this->data_ + i);
    }
    //Deletes the old data and sets the current array to appropriate values
    delete [] this->data_;        
    this->data_ = newArray;
    this->max_size_ = this->cur_size_;
}

template <typename T>
Array<T> Array<T>::slice (size_t begin) const
{
    //Makes sure that begin is within the bounds of the array
    if(begin >= this->cur_size_){
        throw std::out_of_range("Index is out of range of the array");
        exit(-1);
    }
    else{
        //Sets the size of the new array
        size_t newSize = 1 + (this->size() - begin);
        //Creates a a pointer to a new array on the heap
        Array<T> * newArray = new Array<T>(newSize);
        //Gets the starting point of the data by adding the index to the first element
        T * values = this->get_data() + begin;
        //Sets the data starting point of the new array and then returns the value at that position
        newArray->set_data(values);
        return Array(*newArray);
    }
}

template <typename T>
Array<T> Array<T>::slice (size_t begin, size_t end) const
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
        Array<T> * newArray = new Array<T>(newSize);
        //Gets the starting point of the data by adding the index to the first element
        T * values = this->get_data() + begin;
        //Sets the data starting point of the new array and then returns the value at that position
        newArray->set_data(values);
        return Array(*newArray);
    }
}

//
// operator =
//
template <typename T>
const Array <T> & Array <T>::operator = (const Array & rhs)
{
    //Checks if the 2 arrays are actully the same array
    if (this == &rhs){
        return * this;
    }
    else{
        //Resize the array to the rhs size and shrink
        this->resize(rhs.size());
        this->shrink();
        //Populate the array with rhs side elements
        for(size_t i = 0; i < this->size(); i ++){
            this->set(i, rhs.get(i));
        }
        return * this;
    }    
}