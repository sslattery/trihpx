//---------------------------------------------------------------------------//
#include <Foo.hpp>
#include <Bar.hpp>

#include <boost/program_options.hpp>
#include <boost/range/irange.hpp>

#include <hpx/hpx_init.hpp>
#include <hpx/parallel/execution_policy.hpp>
#include <hpx/include/parallel_algorithm.hpp>

#include <assert>
#include <vector>

//---------------------------------------------------------------------------//
// hpx main
int hpx_main( boost::program_options::variables_map& vm )
{
    // get the problem size
    int size = vm["size"].as<int>();

    // Create set of foos
    double value = 1.1;
    std::vector<trihpx::Foo> foo_vec( size );
    for ( auto& f : foo_vec ) f.set_data( value );

    // Create a vector of bars
    std::vector<trihpx::Bar> bar_vec( size );

    // Assign the foos to the bars in parallel
    auto range = boost::irange( 0, size );
    auto assign_func = [&]( const int i )
		    { bar_vec[i].set_data( foo_vec[i] ); };
    hpx::parallel::for_each(
	hpx::parallel_execution_policy(),
	std::begin(range),
	std::end(range),
	assign_func );

    // Check the assignment of correctness
    for ( const auto& b : bar_vec ) assert( value == b.get_data() );

    // Return hpx result.
    return hpx::finalize();
}

//---------------------------------------------------------------------------//
// program main
int main(int argc, char *argv[])
{

    // Configure application-specific options
    boost::program_options::options_description
       desc_commandline("Usage: " HPX_APPLICATION_STRING " [options]");
    desc_commandline.add_options()
        ( "size",
          boost::program_options::value<int>()->default_value(1),
          "problem size")
        ;

    // Run main through hpx
    return hpx::init(desc_commandline, argc, argv);
}

//---------------------------------------------------------------------------//
