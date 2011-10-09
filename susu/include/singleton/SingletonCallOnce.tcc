#ifndef SINGLETON_CALL_ONCE_TCC_INC
#define SINGLETON_CALL_ONCE_TCC_INC

#include <singleton/SingletonCallOnce.hpp>

#include <mutex>
#include <memory>

template<class T>
std::unique_ptr<T> singleton::SingletonCallOnce<T>::m_singleton;

template<class T>
std::once_flag     singleton::SingletonCallOnce<T>::m_flag;

template<class T>
singleton::SingletonCallOnce<T>::SingletonCallOnce()
{
}

template<class T>
singleton::SingletonCallOnce<T>::~SingletonCallOnce()
{
}

template<class T>
T*
singleton::SingletonCallOnce<T>::getInstance()
{
  std::cout << "entered." << std::endl;
  std::call_once( m_flag, SingletonCallOnce::initialize );
  std::cout << "initialized." << std::endl;
  return m_singleton.get(); // warning, returns raw pointer
}

template<class T>
void
singleton::SingletonCallOnce<T>::initialize()
{
  std::cout << "entered, " << __FUNCTION__ << std::endl;
  m_singleton.reset( new T );
}

#endif
