#ifndef DECORATOR_PRINTERIF_HPP_INC
#define DECORATOR_PRINTERIF_HPP_INC

#include <string>

namespace decorator
{
  class PrinterIf 
  {
    public:
      virtual ~PrinterIf();
      virtual void print( const std::string & ) = 0;
  };
}

#endif
