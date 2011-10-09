#ifndef SINGLETON_CALL_ONCE_TCC_INC
#define SINGLETON_CALL_ONCE_TCC_INC

#include <singleton/SingletonCallOnceBoost.hpp>

template<class T>
typename singleton::SingletonCallOnceBoost<T>::UniquePtr
singleton::SingletonCallOnceBoost<T>::m_singleton;

template<class T>
boost::once_flag
singleton::SingletonCallOnceBoost<T>::m_flag;

template<class T>
singleton::SingletonCallOnceBoost<T>::SingletonCallOnceBoost()
{
}

template<class T>
singleton::SingletonCallOnceBoost<T>::~SingletonCallOnceBoost()
{
}

template<class T>
T*
singleton::SingletonCallOnceBoost<T>::getInstance()
{
  boost::call_once( m_flag, SingletonCallOnceBoost::initialize );
  return m_singleton.get(); // warning, returns raw pointer
}

template<class T>
void
singleton::SingletonCallOnceBoost<T>::initialize()
{
  m_singleton.reset( new T );
}

#endif
