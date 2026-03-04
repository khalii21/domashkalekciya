#include <iostream>

template< class T >
struct BiList
{
  T val;
  BiList<T> * next;
  BiList<T> * prev;
};

template< class T >
BiList<T> * begin(T * array)
{
  BiList<T> * h = new BiList<T> {array[0], nullptr, nullptr};
  h->next = h;
  h->prev = h;
  return h;
}

template< class T >
BiList<T> * convert(const T * array, size_t s)
{
  BiList<T> * h = begin(array);
  BiList<T> * node;
  BiList<T> * curr;
  try
  {
    curr = h;
    for(size_t i = 1; i < s-1; i++)
    {
      node = new BiList<T> {array[i]; h; curr};
      curr->next = node;
      h->prev = node;
      current = node;
    }
  }
  catch(...)
  {
    clear(h);
    throw;
  }
  return h;
}




int main()
{}
