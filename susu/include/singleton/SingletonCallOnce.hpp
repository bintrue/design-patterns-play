#ifndef SINGLETON_CALL_ONCE_HPP_INC
#define SINGLETON_CALL_ONCE_HPP_INC

//
// WARNING !!!!
// contains C++0x features! Compile with -std=c++0x!
//

#include <memory>
#include <mutex>

namespace singleton
{
  template <class T>
  class SingletonCallOnce
  {
    public:

      static
      const std::shared_ptr<T> getInstance();

      virtual ~SingletonCallOnce();

    protected:
      // instantation allowed from inside only
      SingletonCallOnce();
    private:
      static void initialize();

      // forbid copying, use cool 0x features...
      SingletonCallOnce( const SingletonCallOnce & )                 = delete;
      const SingletonCallOnce& operator=( const SingletonCallOnce& ) = delete;
      
      static std::shared_ptr<T> m_singleton;
      static std::once_flag     m_flag;
  };
}

// include template implementation
#include <singleton/SingletonCallOnce.tcc>

#endif
