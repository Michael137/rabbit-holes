#include <chrono>
#include <fstream>
#include <iostream>
#include <random>

std::mt19937 random_engine{std::random_device()()};

// Generate one million random numbers
template<typename T, typename Distribution>
std::vector<T> generate_random( Distribution distribution, int num_elements )
{
	std::vector<T> data( num_elements );

	std::generate_n( data.begin(), num_elements,
	                 [&]() { return distribution( random_engine ); } );
	return data;
}

template<typename T> std::vector<T> create_data( int num_elements )
{
	if constexpr( std::is_same_v<T, float> )
		return generate_random<float>(
		    std::uniform_real_distribution<float>( -128.0f, 127.0f ),
		    num_elements );
	if constexpr( std::is_same_v<T, int32_t> )
		return generate_random<int32_t>(
		    std::uniform_int_distribution<int32_t>( -128, 127 ), num_elements );
	if constexpr( std::is_same_v<T, int8_t> )
		return generate_random<int8_t>(
		    std::uniform_int_distribution<int32_t>( -128, 127 ), num_elements );
}

template<typename T> void maybe_exit( std::vector<T> const& data )
{
	if( data.size() > 0 )
		return;

	std::terminate();
}

int main()
{
	int num_elements = 1e8;

#ifdef PROFILE_FLOAT
	{
#	ifdef PRINT_TIME
		auto start = std::chrono::system_clock::now();
#	endif
		auto float_data = create_data<float>( num_elements );
#	ifdef PRINT_TIME
		std::cout << "Time (float): "
		          << std::chrono::duration_cast<std::chrono::milliseconds>(
		                 ( std::chrono::system_clock::now() - start ) )
		                 .count()
		          << '\n';
#	endif
#	ifdef WRITE_RESULTS
		{
			std::ofstream fs{"float.csv", std::ios::out};
			for( auto&& e : float_data )
				fs << e << ',' << '\n';
			fs.close();
		}
#	endif
		maybe_exit( float_data );
	}
#endif

#ifdef PROFILE_INT
	{
#	ifdef PRINT_TIME
		auto start = std::chrono::system_clock::now();
#	endif
		auto int8_data = create_data<int8_t>( num_elements );
#	ifdef PRINT_TIME
		std::cout << "Time (int8): "
		          << std::chrono::duration_cast<std::chrono::milliseconds>(
		                 ( std::chrono::system_clock::now() - start ) )
		                 .count()
		          << '\n';
#	endif
#	ifdef WRITE_RESULTS
		{
			std::ofstream fs{"int8.csv", std::ios::out};
			for( auto&& e : int8_data )
				fs << e << ',' << '\n';
			fs.close();
		}
#	endif
		maybe_exit( int8_data );
	}
#endif

	return 0;
}
