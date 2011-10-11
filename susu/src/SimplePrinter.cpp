#include <decorator/SimplePrinter.hpp>

#include <iostream>


decorator::SimplePrinter::SimplePrinter()
{
}

decorator::SimplePrinter::~SimplePrinter()
{
}

decorator::SimplePrinter::print( const std::string & text )
{
  std::cout << text << std::endl;
}

