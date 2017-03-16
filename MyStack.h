/*

  Tanner Gower
  10/1/2016
  Project 3: Static Stack
  
  Modified on 3/16/2017 for Towers of Hanoi

*/

#ifndef MYSTACK_H
#define MYSTACK_H

using namespace std;

template <class T>
class MyStack
{
  private:
    T* elements;
    int size;
    int top;

  public:
    MyStack<T>();
    MyStack<T>(int);
    MyStack<T>(const MyStack&);
    ~MyStack<T>();

    void push(T const);
    T pop();
    T* getElements() const;
    int getSize() const;
    void reset(int);
    bool isFull() const;
    bool isEmpty() const;
    
};

template <class T>
MyStack<T>::MyStack()
{
  elements = new T[3];
  size = 3;
  top = -1; // no top yet
}

template <class T>
MyStack<T>::MyStack(int stackSize)
{
  elements = new T[stackSize];
  size = stackSize;
  top = -1; // no top yet
}

template <class T>
MyStack<T>::MyStack(const MyStack &rhs)
{
  delete [] elements;

  if (rhs.size == 0)
    elements = NULL;
  else
    elements = new T[rhs.size];

  size = rhs.size;

  for (int i = 0; i < rhs.size; i++)
    elements[i] = rhs.elements[i];

  top = rhs.top;
}

template <class T>
MyStack<T>::~MyStack()
{
  delete [] elements;
}

template <class T>
void MyStack<T>::push(T s)
{
  if (isFull()) {
    cout << "Stack is full!" << endl;
  } else {
    elements[++top] = s;
  }
}

template <class T>
T MyStack<T>::pop()
{
  T r;
  if (isEmpty()) {
    cout << "Stack is empty!" << endl;
  } else {
    r = elements[top];
    elements[top--] = 0;
  }
  return r;
}

template <class T>
T* MyStack<T>::getElements() const
{
  return elements;  
}

template <class T>
bool MyStack<T>::isFull() const
{
  return top == (size - 1);
}

template <class T>
bool MyStack<T>::isEmpty() const
{
  return top == -1;
}

template <class T>
int MyStack<T>::getSize() const
{
  return size;
}

template <class T>
void MyStack<T>::reset(int stackSize)
{
  delete [] elements;
  elements = new T[stackSize];
  size = stackSize;
  top = -1; // no top yet
}

#endif // MYSTACK_H
