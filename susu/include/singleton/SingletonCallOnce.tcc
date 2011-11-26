#ifndef SINGLETON_CALL_ONCE_TCC_INC
#define SINGLETON_CALL_ONCE_TCC_INC

#include <singleton/SingletonCallOnce.hpp>

#include <mutex>
#include <memory>

template<class T>
std::shared_ptr<T> singleton::SingletonCallOnce<T>::m_singleton;

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
const std::shared_ptr<T>
singleton::SingletonCallOnce<T>::getInstance()
{
  std::call_once( m_flag, SingletonCallOnce::initialize );
  return m_singleton;
}

template<class T>
void
singleton::SingletonCallOnce<T>::initialize()
{
  m_singleton.reset( new T );
}

#endif
