#include <chrono>
#include <fstream>
#include <iostream>
#include <random>

std::mt19937 random_engine{std::random_device()()};

int main()
{
	int num_elements = 1e8;

	{
		std::vector<float> data;
		data.reserve( num_elements );
		auto start = std::chrono::system_clock::now();
		for( int i = 0; i < num_elements; ++i )
			data.push_back( random_engine() );
		std::cout << "Time (float): "
		          << std::chrono::duration_cast<std::chrono::milliseconds>(
		                 ( std::chrono::system_clock::now() - start ) )
		                 .count()
		          << '\n';
	}

	return 0;
}
