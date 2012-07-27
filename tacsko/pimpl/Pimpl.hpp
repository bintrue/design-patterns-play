#ifndef PIMPL_HPP
#define PIMPL_HPP

#include <memory>

class Pimpl
{
  public:
    Pimpl();
    void aPublicFunction() const;

  private:
    Pimpl( const Pimpl& );
    Pimpl& operator=( const Pimpl& );

    struct thePimpl;
    std::auto_ptr< thePimpl > m_pimpl;
};

#endif

