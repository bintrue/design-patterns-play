#include <iostream>

using namespace std;
// Without proxy:

class Image
{
  public:

    Image()
    {
      m_id = s_next++;
      cout << "   $$ ctor: " << m_id << '\n';
    }

    ~Image()
    {
      cout << "   dtor: " << m_id << '\n';
    }

    void draw()
    {
      cout << "   drawing image " << m_id << '\n';
    }

  private:

    int         m_id;
    static int  s_next;
};



int Image::s_next = 1;

int main()
{
  Image images[5];

  for (int i; true;)
  {
    cout << "Exit[0], Image[1-5]: ";
    cin >> i;
    if (i == 0)
      break;
    images[i - 1].draw();
  }
}




Output:

$$ ctor: 1
$$ ctor: 2
$$ ctor: 3
$$ ctor: 4
$$ ctor: 5
Exit[0], Image[1-5]: 2
drawing image 2
Exit[0], Image[1-5]: 4
drawing image 4
Exit[0], Image[1-5]: 2
drawing image 2
Exit[0], Image[1-5]: 0
dtor: 5
dtor: 4
dtor: 3
dtor: 2
dtor: 1



/******************************************************************/




// With proxy:

class RealImage
{
  public:

    RealImage(int i)
    {
      m_id = i;
      cout << "   $$ ctor: " << m_id << '\n';
    }

    ~RealImage()
    {
      cout << "   dtor: " << m_id << '\n';
    }
    
    void draw()
    {
      cout << "   drawing image " << m_id << '\n';
    }

  private:

    int m_id;

};



class Image
{
  public:

    Image()
    {
      m_id = s_next++;
      m_the_real_thing = 0;
    }

    ~Image()
    {
      delete m_the_real_thing;
    }

    void draw()
    {
      if (!m_the_real_thing)
        m_the_real_thing = new RealImage(m_id);
      m_the_real_thing->draw();
    }

  private:

    RealImage   *m_the_real_thing;
    int          m_id;
    static int   s_next;
};



int Image::s_next = 1;

int main()
{
  Image images[5];

  for (int i; true;)
  {
    cout << "Exit[0], Image[1-5]: ";
    cin >> i;
    if (i == 0)
      break;
    images[i - 1].draw();
  }
}




Output:

Exit[0], Image[1-5]: 2
$$ ctor: 2
drawing image 2
Exit[0], Image[1-5]: 4
$$ ctor: 4
drawing image 4
Exit[0], Image[1-5]: 2
drawing image 2
Exit[0], Image[1-5]: 0
dtor: 4
dtor: 2


