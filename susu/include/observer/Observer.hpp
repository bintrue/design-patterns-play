#ifndef OBSERVER_HPP_INC
#define OBSERVER_HPP_INC

namespace observer
{
  class Subject;
  class Observer
  {
    public:
      virtual ~Observer();
      virtual void update( observer::Subject* ) = 0;
  };
}

#endif
