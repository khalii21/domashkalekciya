#include <iostream>

/*
Неявный интерфейс:
  Т должен иметь конструктор копирования
  Т должен иметь перегрузку оператора []
*/

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
size_t count(const BiList<T> * h)
{
  size_t res = 0;
  const BiList<T> * curr = h->next;
  while(curr!=head)
  {
    count++;
    curr = curr->next;
  }
  return res;
}

template< class T >
void clear(BiList<T> * h)
{
  BiList<T> * curr = h->next;
  while (curr != h)
  {
    BiList<T> * node = curr->next;
    delete curr;
    curr = node;
  }
  delete h;
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
    for(size_t i = 1; i < s; i++)
    {
      node = new BiList<T> {array[i], h, curr};
      curr->next = node;
      h->prev = node;
      curr = node;
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
