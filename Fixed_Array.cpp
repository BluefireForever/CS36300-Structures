// $Id: Fixed_Array.cpp 827 2011-02-07 14:20:53Z hillj $

// Honor Pledge:
//
// I pledge that I have neither given nor received any help
// on this assignment.

//
// Fixed_Array
//

#include "Fixed_Array.h"
#include <typeinfo>

template <typename T, size_t N>
Fixed_Array<T, N>::Fixed_Array (void)
{
    this->max_size_ = N;
    this->cur_size_ = N;
    this->data_ = new T[N];
}

//
// Fixed_Array
//
template <typename T, size_t N>
Fixed_Array<T, N>::Fixed_Array (const Fixed_Array <T, N> & arr)
{
    this->max_size_ = N;
    this->cur_size_ = N;
    this->data_ = new T[N];

	//Doesn't ask for a deep or shallow copy. I'm going with deep copy, since the user probably
    //wants to have 2 separate sets of data to work with.
    for(size_t i = 0; i < N; i++){
        this->set(i, arr.get(i));
    }
}

//
// Fixed_Array
//
template <typename T, size_t N>
Fixed_Array <T, N>::Fixed_Array (T fill)
{
    this->max_size_ = N;
    this->cur_size_ = N;
    this->data_ = new T[N];
    this->fill(fill);
}

//
// ~Fixed_Array
//
template <typename T, size_t N>
Fixed_Array <T, N>::~Fixed_Array (void)
{
    delete [] this->data_;
}

//
// operator =
//
template <typename T, size_t N>
const Fixed_Array<T, N> & Fixed_Array<T, N>::operator = (const Fixed_Array <T, N> & rhs)
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
