#ifndef VECTOR_HPP
#define VECTOR_HPP
namespace seryj
{
  template<class T>
  class Vector
  {
  public:
    T operator[](size_t);
    void push_back(T);
    size_t end();
    void erase(size_t begin, size_t end);
  private:
    T* ptr_ = nullptr;
    size_t ptr_size_ = 0;
  };

  template<class T>
  inline T Vector<T>::operator[](size_t i)
  {
    return ptr_[i];
  }

  template<class T>
  inline void Vector<T>::push_back(T new_object)
  {
    ptr_size_++;
    T* new_ptr = new T[ptr_size_];
    for (size_t i = 0; i < ptr_size_ - 1; i++)
      new_ptr[i] = ptr_[i];
    new_ptr[ptr_size_ - 1] = new_object;
    if (ptr_)
      delete[] ptr_;
    ptr_ = new_ptr;
  }
  template<class T>
  inline size_t Vector<T>::end()
  {
    return ptr_size_;
  }
  template<class T>
  inline void Vector<T>::erase(size_t begin, size_t end)
  {
    size_t new_size = end - begin - 1;
    T* new_ptr = new T[new_size];
    for (size_t i = 0; i < ptr_size_; i++)
    {
      if (i < begin)
        new_ptr[i] = ptr_[i];
      if (i >= end)
        new_ptr[i - new_size - 1] = ptr_[i];
    }
    if (ptr_)
      delete[] ptr_;
    ptr_ = new_ptr;
  }
}
#endif