#include <iostream>
#include "Array.h"
#include "Stack.h"
#include "Queue.h"
#include "Fixed_Array.h"
#include "Base_Array.h"

#include <iostream>

template<typename T>
void output(Array<T> & array){
  for(int i = 0; i < array.size(); i++){
    std::cout << array.get(i);
  }
  std::cout << std::endl;
}

template<typename T>
void output(Base_Array<T> & array){
  for(int i = 0; i < array.size(); i++){
    std::cout << array.get(i);
  }
  std::cout << std::endl;
}
/*
template<typename T>
void push(Stack<T> & stack, int number){
  for(int i = 0; i < number; i++){
    stack.push(i);
  }
}

template<typename T>
void pop(Stack<T> & stack){
  for(int i = 1; !(stack.is_empty()); i++){
    std::cout << stack.top() << std::endl;
    stack.pop();
  }
}
*/
void TestArray();
void TestStack();
void TestQueue();
void TestFixedArray();
void TestBaseArray();


int main(){
  TestBaseArray();
  TestArray();
  TestStack();
  TestQueue();
  TestFixedArray();
  return 1; 
}

void TestFixedArray(){
  std::cout << "___Test Constructors___" << std::endl;
  Fixed_Array<int, 10> test1;
  Fixed_Array<int, 10> test2(5);
  Fixed_Array<char, 5> test3;
  Fixed_Array<char, 5> test4(test3);
  std::cout << "***All Constructed***" << std::endl;
  test1.fill(0);
  std::cout << "___Test =___" << std::endl;
  std::cout << "test1:" << std::endl;
  output(test1);
  std::cout << "test2:" << std::endl;
  output(test2);
  std::cout << "test1 = test2" << std::endl;
  test1 = test2;
  output(test1);
  std::cout << "***Assignment Completed***" << std::endl;
  std::cout << "___Test Sizes___" << std::endl;
  std::cout << "test2 size: " << test2.size() << std::endl;
  std::cout << "test2 max size: " << test2.max_size() << std::endl;
  std::cout << "***Size Check Completed***" << std::endl;
  std::cout << "___Test [] operators___" << std::endl;
  std::cout << "test2 [1]: " << test2[1] << std::endl;
  const int x = test2[1];
  std::cout << "test2 [1] const: " << x << std::endl;
  std::cout << "***[] Completed***" << std::endl;
  std::cout << "___Test set/get___" << std::endl;
  std::cout << "test2 set 2 = 1:";
  test2.set(2, 1);
  std::cout << test2.get(2) << std::endl;
  std::cout << "***set/get Completed***" << std::endl;
  std::cout << "___Test find___" << std::endl;
  std::cout << "9 @ 2" << std::endl;
  test2.set(2, 9);
  std::cout << "Find with no index: " << test2.find(9) << std::endl;
  std::cout << "Find with index 3: " << test2.find(9, 3) << std::endl;
  std::cout << "***Find Completed***" << std::endl;
  std::cout << "___Test == and !=___" << std::endl;
  std::cout << "test3: ";
  output(test3);
  std::cout << "\ntest4: ";
  output(test4);
  std::cout << "==" << std::endl;
  if(test3 == test4){
    std::cout << "\ntrue" << std::endl;
  }
  else{
    std::cout << "\nfalse" << std::endl;
  }
  std::cout << "!=" << std::endl;
  if(test3 != test4){
    std::cout << "\ntrue" << std::endl;
  }
  else{
    std::cout << "\nfalse" << std::endl;
  }
  test4.fill('V');
  std::cout << "test3: ";
  output(test3);
  std::cout << "\ntest4: ";
  output(test4);
  std::cout << "==" << std::endl;
  if(test3 == test4){
    std::cout << "\ntrue" << std::endl;
  }
  else{
    std::cout << "\nfalse" << std::endl;
  }
  std::cout << "!=" << std::endl;
  if(test3 != test4){
    std::cout << "\ntrue" << std::endl;
  }
  else{
    std::cout << "\nfalse" << std::endl;
  }
  std::cout << "***==/!= Completed***" << std::endl;
  std::cout << "___Test reverse___" << std::endl;
  test4.set(0, 'P');
  test4.set(1, 'e');
  test4.set(2, 't');
  test4.set(3, 'e');
  test4.set(4, 'r');
  std::cout << "test4: ";
  output(test4);
  std::cout << "\nreversed: ";
  test4.reverse();
  output(test4);
  std::cout << "\n***Reverse Completed***" << std::endl;
  std::cout << "___Test slice___" << std::endl;
  std::cout << "\nSlicing test4 starting at 1, ending at 3: " << std::endl;
  Base_Array<char> slize2 = test4.slice(1, 3);
  output(slize2);
  std::cout << "Slicing test4 starting at 3: " << std::endl;
  Base_Array<char> slize = test4.slice(3);
  output(slize);
  std::cout << "\n***Slice Completed***" << std::endl;

}

void TestQueue(){
  std::cout << "___Test Constructors___" << std::endl;
  Queue<int> queue1;
  Queue<int> queue2(queue1);
  Queue<char> queue3;
  std::cout << "***All Constructed***" << std::endl;
  std::cout << "___Test enqueue/dequeue___" << std::endl;
  std::cout << "Enqueue 3 elements into queue1 and 5 elements into queue2" << std::endl;
  queue1.enqueue(1);
  queue1.enqueue(2);
  queue1.enqueue(4);
  queue2.enqueue(16);
  queue2.enqueue(8);
  queue2.enqueue(4);
  queue2.enqueue(2);
  queue2.enqueue(1);
  std::cout << "queue1: " << queue1.size() << std::endl;
  std::cout << "queue2: " << queue2.size() << std::endl;
  std::cout << "Dequeue 1 element each" << std::endl;
  std::cout << "queue1: " << queue1.dequeue() << std::endl;
  std::cout << "queue2: " << queue2.dequeue() << std::endl;
  std::cout << "***Enqueue and Dequeue tested***" << std::endl;
  std::cout << "___Test = operator___" << std::endl;
  std::cout << "queue1 size: " << queue1.size() << "\nqueue2 size: " << queue2.size() << std::endl;
  std::cout << "queue1 = queue2" << std::endl;
  queue1 = queue2;
  std::cout << "queue1 size: " << queue1.size() << "\nqueue2 size: " << queue2.size() << std::endl;
  std::cout << "***= operator tested***" << std::endl;
  std::cout << "___Test clear/is_empty___" << std::endl;
  if(queue1.is_empty()){
    std::cout << "queue1 is empty" << std::endl;
  }
  else{
    std::cout << "queue1 has elements" << std::endl;
  }
  std::cout << "Now clear" << std::endl;
  queue1.clear();
  if(queue1.is_empty()){
    std::cout << "queue1 is empty" << std::endl;
  }
  else{
    std::cout << "queue1 has elements" << std::endl;
  }
  std::cout << "***clear/is_empty tested***" << std::endl;

}

void TestStack(){
  std::cout << "___Test Constructors___" << std::endl;
  Stack<char> stack1;
  std::cout << "push 2 elements onto test1 to copy" << std::endl;
  stack1.push('d');
  stack1.push('o');
  Stack<char>stack2(stack1);
  Stack<int>stack3;
  std::cout << "***All Constructed***" << std::endl;
  std::cout << "___Test push___" << std::endl;
  std::cout << "Current top stack1: " << stack1.top() << std::endl;
  std::cout << "Current top stack2: " << stack2.top() << std::endl;
  std::cout << "Pushing values" << std::endl;
  stack1.push('p');
  stack2.push('l');
  std::cout << "Current top stack1: " << stack1.top() << std::endl;
  std::cout << "Current top stack2: " << stack2.top() << std::endl;
  std::cout << "Push int onto char stack" << std::endl;
  stack1.push(1);
  std::cout << "Current top: " << stack1.top() << std::endl;
  std::cout << "***Push done***" << std::endl;
  std::cout << "___Test =___" << std::endl;
  stack1.pop();
  std::cout << "stack 1 size: " << stack1.size() << " top: " << stack1.top() << std::endl;
  std::cout << "stack 2 size: " << stack2.size() << " top: " << stack2.top() << std::endl;
  stack1 = stack2;
  std::cout << "stack 1 size: " << stack1.size() << " top: " << stack1.top() << std::endl;
  std::cout << "stack 2 size: " << stack2.size() << " top: " << stack2.top() << std::endl;
  std::cout << "***= done***" << std::endl;
  std::cout << "___Test clear/is_empty___" << std::endl;
  if(stack1.is_empty()){
    std::cout << "stack 1 is empty" << std::endl;
  }
  else{
    std::cout << "stack has elements" << std::endl;
  }
  stack1.clear();
  if(stack1.is_empty()){
    std::cout << "stack 1 is empty" << std::endl;
  }
  else{
    std::cout << "stack has elements" << std::endl;
  }
  std::cout << "***Clear/Empty done***" << std::endl;

}

void TestArray(){
  std::cout << "___Test Constructors___" << std::endl;
  //Array<int> test1();
  Array<int> test2(10);
  Array<int> test3(10);
  Array<char> test4(5, 'p');
  Array<char> test5(test4);
  std::cout << "***All Constructed***" << std::endl;
  test3.fill(0);
  test2.fill(5);
  std::cout << "___Test =___" << std::endl;
  std::cout << "test3:" << std::endl;
  output(test3);
  std::cout << "test2:" << std::endl;
  output(test2);
  std::cout << "test3 = test2" << std::endl;
  test3 = test2;
  output(test3);
  std::cout << "***Assignment Completed***" << std::endl;
  std::cout << "___Test Sizes___" << std::endl;
  std::cout << "test2 size: " << test2.size() << std::endl;
  std::cout << "test2 max size: " << test2.max_size() << std::endl;
  std::cout << "***Size Check Completed***" << std::endl;
  std::cout << "___Test [] operators___" << std::endl;
  std::cout << "test2 [1]: " << test2[1] << std::endl;
  const int x = test2[1];
  std::cout << "test2 [1] const: " << x << std::endl;
  std::cout << "***[] Completed***" << std::endl;
  std::cout << "___Test set/get___" << std::endl;
  std::cout << "test2 set 2 = 1:";
  test2.set(2, 1);
  std::cout << test2.get(2) << std::endl;
  std::cout << "***set/get Completed***" << std::endl;
  std::cout << "___Test resize/shrink___" << std::endl;
  std::cout << "test2 cur/max size: " << test2.size() << ", " << test2.max_size() << std::endl;
  test2.resize(5);
  output(test2);
  std::cout << "test2 cur/max size: " << test2.size() << ", " << test2.max_size() << std::endl;
  test2.shrink();
  std::cout << "test2 shrink: " << test2.size() << ", " << test2.max_size() << std::endl;
  test2.resize(15);
  test2.fill(8);
  output(test2);
  std::cout << "test2 resize/fill 15 cur/max size: " << test2.size() << ", " << test2.max_size() << std::endl;
  std::cout << "***resize/shrink Completed***" << std::endl;
  std::cout << "___Test find___" << std::endl;
  std::cout << "9 @ 10" << std::endl;
  test2.set(10, 9);
  std::cout << "Find with no index: " << test2.find(9) << std::endl;
  std::cout << "Find with index 10: " << test2.find(9, 11) << std::endl;
  std::cout << "***Find Completed***" << std::endl;
  std::cout << "___Test == and !=___" << std::endl;
  std::cout << "test2: ";
  output(test2);
  std::cout << "\ntest3: ";
  output(test3);
  std::cout << "==" << std::endl;
  if(test2 == test3){
    std::cout << "\ntrue" << std::endl;
  }
  else{
    std::cout << "\nfalse" << std::endl;
  }
  std::cout << "!=" << std::endl;
  if(test2 != test3){
    std::cout << "\ntrue" << std::endl;
  }
  else{
    std::cout << "\nfalse" << std::endl;
  }
  test3.resize(15);
  test2 = test3;
  std::cout << "test2: ";
  output(test2);
  std::cout << "\ntest3: ";
  output(test3);
  std::cout << "==" << std::endl;
  if(test2 == test3){
    std::cout << "\ntrue" << std::endl;
  }
  else{
    std::cout << "\nfalse" << std::endl;
  }
  std::cout << "!=" << std::endl;
  if(test2 != test3){
    std::cout << "\ntrue" << std::endl;
  }
  else{
    std::cout << "\nfalse" << std::endl;
  }
  std::cout << "***==/!= Completed***" << std::endl;
  std::cout << "___Test reverse___" << std::endl;
  test4.set(1, 'e');
  test4.set(2, 't');
  test4.set(3, 'e');
  test4.set(4, 'r');
  std::cout << "test4: ";
  output(test4);
  std::cout << "\nreversed: ";
  test4.reverse();
  output(test4);
  std::cout << "\n***Reverse Completed***" << std::endl;
  std::cout << "___Test slice___" << std::endl;
  std::cout << "\nSlicing test4 starting at 1, ending at 3: " << std::endl;
  Array<char> slize2 = test4.slice(1, 3);
  output(slize2);
  std::cout << "Slicing test4 starting at 3: " << std::endl;
  Array<char> slize = test4.slice(3);
  output(slize);
  std::cout << "\n***Slice Completed***" << std::endl;
}

void TestBaseArray(){
  std::cout << "___Test Constructors___" << std::endl;
  Base_Array<int> test1;
  Base_Array<int> test2(10);
  Base_Array<int> test3(10);
  Base_Array<char> test4(5, 'p');
  Base_Array<char> test5(test4);
  std::cout << "***All Constructed***" << std::endl;
  test3.fill(0);
  test2.fill(5);
  std::cout << "___Test =___" << std::endl;
  std::cout << "test3:" << std::endl;
  output(test3);
  std::cout << "test2:" << std::endl;
  output(test2);
  std::cout << "test3 = test2" << std::endl;
  test3 = test2;
  output(test3);
  std::cout << "***Assignment Completed***" << std::endl;
  std::cout << "___Test Sizes___" << std::endl;
  std::cout << "test2 size: " << test2.size() << std::endl;
  std::cout << "test2 max size: " << test2.max_size() << std::endl;
  std::cout << "***Size Check Completed***" << std::endl;
  std::cout << "___Test [] operators___" << std::endl;
  std::cout << "test2 [1]: " << test2[1] << std::endl;
  const int x = test2[1];
  std::cout << "test2 [1] const: " << x << std::endl;
  std::cout << "***[] Completed***" << std::endl;
  std::cout << "___Test set/get___" << std::endl;
  std::cout << "test2 set 2 = 1:";
  test2.set(2, 1);
  std::cout << test2.get(2) << std::endl;
  std::cout << "***set/get Completed***" << std::endl;
  std::cout << "___Test find___" << std::endl;
  std::cout << "9 @ 2" << std::endl;
  test2.set(2, 9);
  std::cout << "Find with no index: " << test2.find(9) << std::endl;
  std::cout << "Find with index 3: " << test2.find(9, 3) << std::endl;
  std::cout << "***Find Completed***" << std::endl;
  std::cout << "___Test == and !=___" << std::endl;
  std::cout << "test2: ";
  output(test2);
  std::cout << "\ntest3: ";
  output(test3);
  std::cout << "==" << std::endl;
  if(test2 == test3){
    std::cout << "\ntrue" << std::endl;
  }
  else{
    std::cout << "\nfalse" << std::endl;
  }
  std::cout << "!=" << std::endl;
  if(test2 != test3){
    std::cout << "\ntrue" << std::endl;
  }
  else{
    std::cout << "\nfalse" << std::endl;
  }
  test2 = test3;
  std::cout << "test2: ";
  output(test2);
  std::cout << "\ntest3: ";
  output(test3);
  std::cout << "==" << std::endl;
  if(test2 == test3){
    std::cout << "\ntrue" << std::endl;
  }
  else{
    std::cout << "\nfalse" << std::endl;
  }
  std::cout << "!=" << std::endl;
  if(test2 != test3){
    std::cout << "\ntrue" << std::endl;
  }
  else{
    std::cout << "\nfalse" << std::endl;
  }
  std::cout << "***==/!= Completed***" << std::endl;
  std::cout << "___Test reverse___" << std::endl;
  test4.set(1, 'e');
  test4.set(2, 't');
  test4.set(3, 'e');
  test4.set(4, 'r');
  std::cout << "test4: ";
  output(test4);
  std::cout << "\nreversed: ";
  test4.reverse();
  output(test4);
  std::cout << "\n***Reverse Completed***" << std::endl;
  std::cout << "___Test slice___" << std::endl;
  std::cout << "\nSlicing test4 starting at 1, ending at 3: " << std::endl;
  Base_Array<char> slize2 = test4.slice(1, 3);
  output(slize2);
  std::cout << "Slicing test4 starting at 3: " << std::endl;
  Base_Array<char> slize = test4.slice(3);
  output(slize);
  std::cout << "\n***Slice Completed***" << std::endl;
}

