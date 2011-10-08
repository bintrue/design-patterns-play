#include "cxxtest_ext.hpp"

#include <algorithm>

// hack
#define private public
#define protected public

#include <observer/Subject.hpp>
#include <observer/Observer.hpp>



class TestSubject : public CxxTest::TestSuite
{
  class DummyObserver : public observer::Observer
  {
    public:
      DummyObserver() : m_updateCounter( 0 )
      {
      }
      virtual void update( observer::Subject* subj )
      {
        ++m_updateCounter;
      }
      int getUpdateCounter() const
      {
        return m_updateCounter;
      }
    private:
      int m_updateCounter;
  };

  class DummySubject : public observer::Subject
  {
    public:
      DummySubject()
      {
      }
      bool isAttached( observer::Observer* obs )
      {
        return std::find( m_observers.begin(),
                          m_observers.end(),
                          obs )
                    != m_observers.end();
      }
  };
  public:
    void testCtor()
    {
      TCH;
      DummySubject subject;
    }

    void testAttachObservers()
    {
      TCH;
      DummySubject subject;
      DummyObserver obs, obs2, obs3;
      subject.attach( &obs );
      subject.attach( &obs2 );
      subject.attach( &obs3 );

      TS_ASSERT( subject.isAttached( &obs ) );
      TS_ASSERT( subject.isAttached( &obs2 ) );
      TS_ASSERT( subject.isAttached( &obs3 ) );
    }

    void testDetachObservers()
    {
      TCH;
      DummySubject subject;
      DummyObserver obs, obs2, obs3;
      subject.attach( &obs );
      subject.attach( &obs2 );
      subject.attach( &obs3 );

      TS_ASSERT( subject.isAttached( &obs ) );
      TS_ASSERT( subject.isAttached( &obs2 ) );
      TS_ASSERT( subject.isAttached( &obs3 ) );

      subject.detach( &obs );
      TS_ASSERT( !subject.isAttached( &obs ) );
      TS_ASSERT( subject.isAttached( &obs2 ) );
      TS_ASSERT( subject.isAttached( &obs3 ) );

      subject.detach( &obs2 );
      subject.detach( &obs3 );

      TS_ASSERT( !subject.isAttached( &obs ) );
      TS_ASSERT( !subject.isAttached( &obs2 ) );
      TS_ASSERT( !subject.isAttached( &obs3 ) );
    }

    void testNotifyObservers()
    {
      TCH;
      DummySubject subject;
      DummyObserver obs, obs2, obs3;
      subject.attach( &obs );
      subject.attach( &obs2 );
      subject.attach( &obs3 );

      TS_ASSERT_EQUALS( 0, obs.getUpdateCounter() );
      TS_ASSERT_EQUALS( 0, obs2.getUpdateCounter() );
      TS_ASSERT_EQUALS( 0, obs3.getUpdateCounter() );

      subject.notify();
      
      TS_ASSERT_EQUALS( 1, obs.getUpdateCounter() );
      TS_ASSERT_EQUALS( 1, obs2.getUpdateCounter() );
      TS_ASSERT_EQUALS( 1, obs3.getUpdateCounter() );
    }
};
