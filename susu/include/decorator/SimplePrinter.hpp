#ifndef DECORATOR_SIMPLE_PRINTER_HPP_INC
#define DECORATOR_SIMPLE_PRINTER_HPP_INC

#include <decorator/PrinterIf.hpp>

namespace decorator 
{
  class SimplePrinter : public PrinterIf
  {
    public:
      SimplePrinter();
      virtual ~SimplePrinter();
      virtual void print( const std::string & text );
  };
}


#endif
