// standard_vector.h

// This class represents a dynamically sized array.

#include <cstddef>
#include <stdexcept>

#ifndef _STANDARD_VECTOR_
#define _STANDARD_VECTOR_

namespace standard
{

template <class T> class standard_vector
{
  std::size_t m_max_size;
  std::size_t m_size;
  std::size_t m_capacity;

  T *m_storage;

  enum
  {
    MAX_VECTOR_SIZE = 1000
  };

public:
  // Types
  typedef T value_type;
  typedef T &reference;
  typedef const T &const_reference;

  // Creators
  // Creates and empty standard vector.
  explicit standard_vector ();

  // Creates a standard vector of size 'n' and fills it with 'n' copies of
  // 'val'.
  explicit standard_vector (std::size_t n,
                            const value_type &val = value_type ());

  standard_vector (const standard_vector &x);
  // standard_vector &operator= (const standard_vector &x);

  // Capacity
  // Returns the number of element in the standard vector.
  std::size_t size () const;

  // Returns the maximum numbers of elements standard vector can hold.
  std::size_t max_size () const;

  // Resizes the standard vector to contain 'n' elements.
  // If 'n' is less than the `size()`, the number of elements in the standard
  // vector are reduced to 'n'. Other elements are removed. If 'n' is more than
  // the `size()`, the standard vector is expanded by inserting elements. If
  // 'val' is provided, copies of it are inserted in the container, otherwise
  // value-type is created. If 'n' is more than the `capacity()`, more storage
  // is allocated to the standard vector automatically.
  void resize (std::size_t n, value_type val = value_type ());

  // Returns the storage space allocated to the standard vector in term of
  // elements. It can be different from `size()`.
  std::size_t capacity () const;

  // Returns `true` if the container is empty.
  bool empty () const;

  // Requests that the standard vector is at least of capacity 'n'. If 'n' is
  // more than the `capacity()`, the storage space is reallocated. It has no
  // effect on `size()`, and does not destroy elements.
  void reserve (std::size_t n);

  // Requests the container to shrink its `capacity()` to fit its `size()`.
  void shrink_to_fit ();

  // Accessors
  // Returns a reference to element at index 'i'. If 'i' is greater than or
  // equal to `size()`, an `out_of_bound` exception is thrown.
  reference at (std::size_t i);
  const_reference at (std::size_t i) const;

  // Destroyers
  ~standard_vector ();
};

template <class T>
standard_vector<T>::standard_vector ()
    : m_max_size (MAX_VECTOR_SIZE), m_size (), m_storage ()
{
}

template <class T>
standard_vector<T>::standard_vector (std::size_t n, const value_type &val)
    : m_max_size (MAX_VECTOR_SIZE), m_size (n), m_storage ()
{
  m_storage = new T[m_size];
  for (unsigned i = 0; i < n; ++i)
    {
      m_storage[i] = val;
    }
}

template <class T>
standard_vector<T>::standard_vector (const standard_vector<T> &x)
    : m_max_size (MAX_VECTOR_SIZE), m_size (x.m_size), m_capacity (x.capacity)
{
}

template <class T>
std::size_t
standard_vector<T>::size () const
{
  return m_size;
}

template <class T>
std::size_t
standard_vector<T>::max_size () const
{
  return m_max_size;
}

template <class T>
void
standard_vector<T>::resize (std::size_t n, value_type val)
{
  return;
}

template <class T>
std::size_t
standard_vector<T>::capacity () const
{
  return m_capacity;
}

template <class T>
bool
standard_vector<T>::empty () const
{
  return m_size == 0;
}

template <class T>
void
standard_vector<T>::reserve (std::size_t n)
{
  return;
}

template <class T>
void
standard_vector<T>::shrink_to_fit ()
{
  return;
}

template <class T>
typename standard_vector<T>::reference
standard_vector<T>::at (std::size_t i)
{
  if (i >= m_size)
    {
      throw std::out_of_range ("i is out of bound");
    }

  return m_storage[i];
}

template <class T>
typename standard_vector<T>::const_reference
standard_vector<T>::at (std::size_t i) const
{
  if (i >= m_size)
    {
      throw std::out_of_range ("i is out of bound");
    }

  return m_storage[i];
}

template <class T> standard_vector<T>::~standard_vector () {}

} // close namespace standard.

#endif
