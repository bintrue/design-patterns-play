#include <iostream>
#include <string>

class PrinterStrategy
{
  public:
    virtual void printString( const std::string& text ) const = 0;
};

class SimplePrinter : public PrinterStrategy
{
  public:
    virtual void printString( const std::string& text ) const
    {
      std::cout << text << std::endl;
    }
};

class UnderlinePrinter : public PrinterStrategy
{
  public:
    virtual void printString( const std::string& text ) const
    {
      std::string underline( text.length(), '-' );
      std::cout << text << std::endl << underline << std::endl;
    }
};

class Person
{
  public:
    Person( const std::string& name )
      : m_name( name )
    {
    }

    void printName( const PrinterStrategy& printer )
    {
      printer.printString( m_name );
    }
  private:
    std::string m_name;

};


int main()
{
  Person peti( "Hajdu Sarkanyolo Peter Ferenc" );
  UnderlinePrinter underlinePrinter;
  SimplePrinter simplePrinter;

  peti.printName( underlinePrinter );
  peti.printName( simplePrinter );
  return 0;
}

