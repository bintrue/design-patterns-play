#ifndef DECORATOR_UNDERLINE_DECORATOR_HPP_INC
#define DECORATOR_UNDERLINE_DECORATOR_HPP_INC

#include <decorator/PrinterDecorator.hpp>

namespace decorator
{
  class UnderlineDecorator : public PrinterDecorator
  {
    public:
      UnderlineDecorator( PrinterIf* printer );
      virtual ~UnderlineDecorator();
      virtual void print( const std::string & text );
  };
}

#endif
