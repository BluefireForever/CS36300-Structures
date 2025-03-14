   // -*- C++ -*-
// $Id: Stack.h 380 2010-02-08 05:10:33Z hillj $

//==============================================================================
/**
 * Honor Pledge:
 *
 * I pledge that I have neither given nor received any help
 * on this assignment.
 */
//==============================================================================

#ifndef _CS507_STACK_H_
#define _CS507_STACK_H_

#include <exception>
#include "Array.h"

//A default size is not mentioned, nor required. However, instead of increasing the array
//size every time something is pushed onto the stack, I defined a default size that will
//hopefully be large enough to accomodate some work before needing to resize
#define defaultSize 100


/**
 * @class Stack
 *
 * Basic stack for abitrary elements.
 */
template <typename T>
class Stack
{
public:
  /// Type definition of the type.
  typedef T type;

  //I don't know if this is an acceptable solution, but I just got rid of the
  //custom exception all together. I instead simply use throw.

  /// Default constructor.
  Stack (void);

  /// Copy constructor.
  Stack (const Stack & s);

  /// Destructor.
  ~Stack (void);

  /**
   * Assignment operator
   *
   * @param[in]      rhs           Right-hand side of operator
   * @return         Reference to self
   */
  const Stack & operator = (const Stack & rhs);

  /**
   * Push a new \a element onto the stack. The element is inserted
   * before all the other elements in the list.
   *
   * @param[in]      element       Element to add to the list
   */
  void push (T element);

  /**
   * Remove the top-most element from the stack.
   *
   * @exception      empty_exception    The stack is empty.
   */
  void pop (void);

  /**
   * Get the top-most element on the stack. If there are no element 
   * on the stack, then the stack_is_empty exception is thrown.
   *
   * @return         Element on top of the stack.
   * @exception      empty_exception    The stack is empty
   */
  T top (void) const;

  /**
   * Test if the stack is empty
   *
   * @retval         true          The stack is empty
   * @retval         false         The stack is not empty
   */
  bool is_empty (void) const;

  /**
   * Number of element on the stack.
   *
   * @return         Size of the stack.
   */
  size_t size (void) const;

  /// Remove all elements from the stack.
  void clear (void);

private:
    // COMMENT You can simplify your design by keeping location
    // (or size) variable in the stack class instead of trying to
    // use the current size of the array. Your current approach is
    // introducing a layer of complexity that can easily result in
    // unintended consequences if the array changes since you are
    // dependent on its internal variables (i.e., going inside the
    // Wrapper Facade).

    // FIX I'm not quite sure what this means. The size of the stack
    // IS internal to the stack class. It is increased and decreased
    // independently of the of the array class using current index.
    // Current index acts as the current index AND the size, since
    // current index will always indicate the top of the stack.
    // However, based on the queue comment, I'm making the arrayData
    // on the stack instead of the heap.

  // add member variable here
  Array<T> arrayData;
  size_t currentIndex;
};

// include the inline files
#include "Stack.inl"

// include the source file since template class
#include "Stack.cpp"

#endif  // !defined _CS507_STACK_H_
