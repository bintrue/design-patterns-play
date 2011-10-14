#include <decorator/UnderlineDecorator.hpp>

#include <iostream>

decorator::UnderlineDecorator::UnderlineDecorator( PrinterIf * printer )
    : PrinterDecorator( printer )
{
}

decorator::UnderlineDecorator::~UnderlineDecorator()
{
}

void
decorator::UnderlineDecorator::print( const std::string & text )
{
  PrinterDecorator::print( text );
  std::cout << std::string( text.length(), '=' ) << std::endl;
}


