#include <observer/Subject.hpp>
#include <observer/Observer.hpp>

observer::Subject::~Subject()
{
}

void
observer::Subject::attach( Observer* obs )
{
  m_observers.push_back( obs );
}
void
observer::Subject::detach( Observer* obs )
{
  m_observers.remove( obs );
}


void
observer::Subject::notify()
{
  for ( ObserverList::const_iterator ci = m_observers.begin();
        m_observers.end() != ci;
        ++ci )
  {
    (*ci)->update( this );
  }
}


