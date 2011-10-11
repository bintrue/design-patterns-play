#ifndef DECORATOR_PRINTER_DECORATOR_HPP_INC
#define DECORATOR_PRINTER_DECORATOR_HPP_INC

#include <decorator/PrinterIf.hpp>

namespace decorator
{
  class PrinterDecorator
  {
    public:
      PrinterDecorator( PrinterIf* printer );
      virtual ~PublicDecorator();
      virtual void print( const std::string & text );
    private:
      PrinterIf* m_printer;
  };
}

#endif
