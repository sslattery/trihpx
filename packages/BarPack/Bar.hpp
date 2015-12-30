//---------------------------------------------------------------------------//
#ifndef TRIHPX_BAR_HPP
#define TRIHPX_BAR_HPP

#include <Foo.hpp>

namespace trihpx
{

//---------------------------------------------------------------------------//
class Bar
{
  public:
    Bar();
    void set_data( const Foo& foo );
    double get_data() const;
  private:
    double d_data;
};

//---------------------------------------------------------------------------//

} // end namespace trihpx

#endif // end TRIHPX_BAR_HPP

//---------------------------------------------------------------------------//
