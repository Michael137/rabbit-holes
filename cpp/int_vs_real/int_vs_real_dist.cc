#include <chrono>
#include <iostream>
#include <random>

std::mt19937 random_engine{std::random_device()()};

// Generate one million random numbers
template<typename T, typename Distribution>
std::vector<T> generate_random( Distribution distribution, int num_elements )
{
	std::vector<T> data( num_elements );

	std::generate_n( data.begin(), num_elements, [&]() {
		return static_cast<T>( distribution( random_engine ) );
	} );
	return data;
}

template<typename T> std::vector<T> create_data( int num_elements )
{
	if constexpr( std::is_same_v<T, float> )
		return generate_random<float>(
		    std::uniform_real_distribution<float>( -127.0f, 127.0f ),
		    num_elements );
	if constexpr( std::is_same_v<T, int8_t> )
		return generate_random<int8_t>(
		    std::uniform_int_distribution<int32_t>( -127, 127 ), num_elements );
}

int main()
{
	int num_elements = 1e7;
	auto start       = std::chrono::system_clock::now();
	auto float_data  = create_data<float>( num_elements );
	std::cout << "Time (float): "
	          << ( std::chrono::system_clock::now() - start ).count() << '\n';

	start          = std::chrono::system_clock::now();
	auto int8_data = create_data<int8_t>( num_elements );
	std::cout << "Time (int8): "
	          << ( std::chrono::system_clock::now() - start ).count() << '\n';

	return 0;
}
