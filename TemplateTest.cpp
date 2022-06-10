#include <string>

template <char> int foo(std::string const &);      // no implementation

template <> int foo<'a'>(std::string const & s) { /* ... */ } 
template <> int foo<'b'>(std::string const & s) { /* ... */ }


int main()
{
    return 0;
}