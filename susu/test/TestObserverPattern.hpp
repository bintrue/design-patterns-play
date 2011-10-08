#include "cxxtest_ext.hpp"

#include <observer/Subject.hpp>
#include <observer/Observer.hpp>

#include <boost/thread/thread.hpp> 

#include <iostream>
#include <ctime>

class TestObserverPattern : public CxxTest::TestSuite
{
    class Timer : public observer::Subject
    {
      public:
        Timer( int interval ) :
            m_startTime( time(0) ),
            m_msInterval( interval ),
            m_msSleep( 100 ),
            m_until( 10 )
        {
        }
        // gave back elapsed time since start (= the object constructed)
        int getElapsedSecs() const
        {
          return ( time(0) - m_startTime );// * CLOCKS_PER_SEC;
        }
        void work()
        {
          int elapsed = 0;
          while( getElapsedSecs() < m_until )
          {
            //std::cout << "while..." << std::endl;
            if ( elapsed > m_msInterval ) 
            {
              // notifying observers
              notify( );
              elapsed = 0;
            }
            // sleep millisecs
            boost::this_thread::sleep(
              boost::posix_time::milliseconds( m_msSleep )
            );
            elapsed += m_msSleep;
          }
        }
      private:
        time_t  m_startTime;
        int     m_msInterval;
        int     m_msSleep;
        int     m_until;
    };

    class TextDisplay : public observer::Observer
    {
      public:
        TextDisplay( Timer* timer ) : m_timer( timer )
        {
        }
        void update( observer::Subject* subj )
        {
          if ( subj == m_timer ) {
            std::cout << "Elapsed since start: " << m_timer->getElapsedSecs() << std::endl;
          }
        }
      private:
        Timer* m_timer;
    };

    class AsciiDisplay : public observer::Observer
    {
      public:
        AsciiDisplay( Timer* timer ) : m_timer( timer )
        {
        }
        void update( observer::Subject* subj )
        {
        }
      private:
        Timer* m_timer;
    };
  public:
    void testObserverPattern()
    {
      TCH;
      std::cout << "Start timer" << std::endl;
      Timer* timer = new Timer( 2000 );
      //std::cout << "elapsed: " << timer->getElapsedSecs() << std::endl;
      TextDisplay* textDisplay = new TextDisplay( timer );
      timer->attach( textDisplay );

      timer->work();
      
      delete textDisplay;
      delete timer;
    }
};



