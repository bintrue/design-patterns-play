#include "Pimpl.hpp"
#include <iostream>

struct Pimpl::thePimpl
{
  void publicFunctionInsidePimpl() const
  {
    std::cout << "this is inside pimpl" << std::endl;
  }

};


Pimpl::Pimpl()
  : m_pimpl( new thePimpl )
{
}


void
Pimpl::aPublicFunction() const
{
  m_pimpl->publicFunctionInsidePimpl();
}

