#ifndef OBSERVER_SUBJECT_HPP_INC
#define OBSERVER_SUBJECT_HPP_INC

#include <list>

namespace observer
{
  class Observer;
  class Subject
  {
    public:
      virtual ~Subject();
      
      virtual void attach( Observer* );
      virtual void detach( Observer* );
      virtual void notify();
    private:
      typedef std::list< Observer* > ObserverList;
      ObserverList m_observers;
  };
}

#endif
