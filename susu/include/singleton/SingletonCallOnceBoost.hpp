#ifndef SINGLETON_CALL_ONCE_HPP_INC
#define SINGLETON_CALL_ONCE_HPP_INC

#include <boost/interprocess/smart_ptr/unique_ptr.hpp>
#include <boost/thread/once.hpp>

namespace singleton
{
  template <class D>
  struct Deleter
  {
    void operator()( D *p )
    {
      delete p;
    }
  };

  template <class T>
  class SingletonCallOnceBoost
  {
    public:
      static T* getInstance();
      virtual ~SingletonCallOnceBoost();
      typedef boost::interprocess::unique_ptr< T, Deleter<T> > UniquePtr;
    protected:
      // instantation allowed from inside only
      SingletonCallOnceBoost();
    private:
      static void initialize();

      // forbid copying, use cool 0x features...
      SingletonCallOnceBoost( const SingletonCallOnceBoost & );
      const SingletonCallOnceBoost& operator=( const SingletonCallOnceBoost& );

      static UniquePtr m_singleton;
      static boost::once_flag     m_flag;
  };
}

// include template implementation
#include <singleton/SingletonCallOnceBoost.tcc>

#endif
