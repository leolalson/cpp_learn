#include <iostream>
#include <vector>
#include <numeric>

std::vector<int> multiplication_array(std::vector<int> weights)
{
	int multi = 1;
	for(int i=0;i<weights.size();++i)
	{
		multi = multi * weights[i];
	}
	std::vector<int> new_array(weights.size());
	for(int i=0;i<weights.size();++i)
	{
		new_array[i] = multi / weights[i]; 
	}
	return new_array;	
}

std::vector<int> multiplication_array2(std::vector<int> weights)
{
	int multi = 1;
	std::vector<int> new_array(weights.size(),1);
	for(int i=0;i<weights.size();++i)
	{
		for(int j=0;j<weights.size();++j)
		{
			if (i!=j)
			{
				new_array[i] = new_array[i] * weights[j];
			}
		}
	}

	return new_array;	
}

int main()
{
  std::vector<int> my_array = {10, 3, 2, 1};
	auto new_array = multiplication_array(my_array);
	auto new_array2 = multiplication_array2(my_array);
	std::cout << "New Array: ";
	for(int i=0;i<new_array.size();++i)
	{
		std::cout << new_array[i] << ", ";
	}
	std::cout << std::endl;
	std::cout << "New Array2: ";
	for(int i=0;i<new_array2.size();++i)
	{
		std::cout << new_array2[i] << ", ";
	}
	std::cout << std::endl;
	
  return 0;
}
