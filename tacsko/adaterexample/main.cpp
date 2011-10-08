#include <iostream>
#include <string>

/*
 * Adaptee 1.
 */
class Car
{
  public:
    Car( const std::string& registrationNumber )
      : m_registrationNumber( registrationNumber )
    {
    }

    std::string getNumber() const
    {
      return m_registrationNumber;
    }

  private:
    std::string m_registrationNumber;
};

/*
 * Adaptee 2.
 */
class Person
{
  public:
    Person( const std::string& name )
      : m_name( name )
    {
    }

    std::string getName() const
    {
      return m_name;
    }

  private:
    std::string m_name;
};

class IdAdapter
{
  public:
    virtual std::string getId() = 0;
    virtual ~IdAdapter()
    {
    }
};


/*
 * Adapter 1.
 */
class CarIdAdapter : public IdAdapter
{
  public:
    CarIdAdapter( Car& car )
      : IdAdapter()
      , m_car( car )
    {
    }

    virtual std::string getId()
    {
      return m_car.getNumber();
    }

  private:
    Car&  m_car;
};

/*
 * Adapter 2.
 */
class PersonIdAdapter : public IdAdapter
{
  public:
    PersonIdAdapter( Person& person )
      : IdAdapter()
      , m_person( person )
    {
    }

    virtual std::string getId()
    {
      return m_person.getName();
    }

  private:
    Person&  m_person;
};

/*
 * Our main function is the client calling the adapter interface.
 * enhancement: Adapter classes can be manufactured by a factory according to
 * the adaptee and adaptor types.
 */
int main()
{
  Car car( "123456" );
  Person person( "Hajdu Sarkanyolo Peter Ferenc" );

  IdAdapter* carAdapter( new CarIdAdapter( car ) );
  IdAdapter* personAdapter( new PersonIdAdapter( person ) );

  std::cout << carAdapter->getId() << std::endl;
  std::cout << personAdapter->getId() << std::endl;

  delete carAdapter;
  delete personAdapter;

  return 0;
}

