//---------------------------------------------------------------------------//
#ifndef TRIHPX_FOO_HPP
#define TRIHPX_FOO_HPP

namespace trihpx
{

//---------------------------------------------------------------------------//
class Foo
{
  public:
    Foo();
    explicit Foo( const double data );
    void set_data( const double data );
    double get_data() const;
  private:
    double d_data;
};

//---------------------------------------------------------------------------//

} // end namespace trihpx

#endif // end TRIHPX_FOO_HPP

//---------------------------------------------------------------------------//
