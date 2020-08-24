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
		    std::uniform_real_distribution<float>( -128.0f, 128.0f ),
		    num_elements );
	if constexpr( std::is_same_v<T, int32_t> )
		return generate_random<int32_t>(
		    std::uniform_int_distribution<int32_t>( -128, 128 ), num_elements );
	if constexpr( std::is_same_v<T, int8_t> )
		return generate_random<int8_t>(
		    std::uniform_int_distribution<int32_t>( -128, 128 ), num_elements );
}

int main()
{
	int num_elements = 1e7;
	auto start       = std::chrono::system_clock::now();
	auto float_data  = create_data<float>( num_elements );
	std::cout << "Time (float): "
	          << ( std::chrono::system_clock::now() - start ).count() << '\n';
	{
		std::ofstream fs{"float.csv", std::ios::out};
		for( auto&& e: float_data )
			fs << e << '\n';
		fs.close();
	}

	start          = std::chrono::system_clock::now();
	auto int8_data = create_data<int8_t>( num_elements );
	std::cout << "Time (int8): "
	          << ( std::chrono::system_clock::now() - start ).count() << '\n';
	{
		std::ofstream fs{"int8.csv", std::ios::out};
		for( auto&& e: int8_data )
			fs << (int)e << '\n';
		fs.close();
	}

	start           = std::chrono::system_clock::now();
	auto int32_data = create_data<int32_t>( num_elements );
	std::cout << "Time (int32_t): "
	          << ( std::chrono::system_clock::now() - start ).count() << '\n';
	{
		std::ofstream fs{"int32.csv", std::ios::out};
		for( auto&& e: int32_data )
			fs << e << '\n';
		fs.close();
	}

	return 0;
}
