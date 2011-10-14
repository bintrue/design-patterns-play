#include <decorator/PrinterDecorator.hpp>


decorator::PrinterDecorator::PrinterDecorator( decorator::PrinterIf * printer )
    : m_printer( printer )
{
}

decorator::PrinterDecorator::~PrinterDecorator()
{
}

void
decorator::PrinterDecorator::print( const std::string & text )
{
  m_printer->print( text );
}


