#include <iostream>
#include <string>
#include <bitset>
#include <sstream>
#include <map>
#include <cctype>
 
class converter
{
public:
    virtual std::string convert(int) = 0;
    virtual ~converter() {}
};
 
class hex_converter : public converter
{
public:
    std::string convert(int i)
    {
        std::stringstream ss;
        ss << std::hex << i;
        return ss.str();
    }
};
 
class oct_converter : public converter
{
public:
    std::string convert(int i)
    {
        std::stringstream ss;
        ss << std::oct << i;
        return ss.str();
    }
};
 
class bin_converter : public converter
{
public:
    std::string convert(int i)
    {
        std::bitset< sizeof(i) * CHAR_BIT > bits(i);
        std::stringstream ss;
        ss << bits;
        return ss.str();
    }
};
 
class dictionary
{
    std::map<char, converter*> dict;
public:
    dictionary()
    {
        dict.insert( std::make_pair( 'B', new bin_converter ) );
        dict.insert( std::make_pair( 'O', new oct_converter ) );
        dict.insert( std::make_pair( 'H', new hex_converter ) );
    }
 
    converter* lookup(char x)
    {
        std::map<char, converter*>::const_iterator iter;
        iter = dict.find( toupper(x) );
        if( iter != dict.end() )
            return iter->second;
        else
            return NULL;
    }
 
    ~dictionary()
    {
        while( dict.begin() != dict.end() )
        {
            delete dict.begin()->second;
            dict.erase( dict.begin() );
        }
    }
};
 
int main()
{
    using namespace std;
 
    int num = 1234;
    char ch = 'h';
    string output = "";
    dictionary dict;
 
    converter* con = dict.lookup( ch );
 
    if( con != NULL )
        output = con->convert( num );
    else
        output = "Invalid";
    cout << "Result: " << output;
}
