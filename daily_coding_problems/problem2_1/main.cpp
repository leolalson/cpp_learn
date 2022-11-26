#include <iostream>
#include <vector>
#include <numeric>


class Baggage
{
	public:
		void swap_number(int &a, int &b)
		{
			int temp = a;
			a = b;
			b = temp;
		}
		int maximum_weights(std::vector<int> weights, int w1, int w2)
		{
			int max_weight = 0;
			int bag1 = 0;
			int bag2 = 0;
			int item1;
			int item2;
			if (!weights.empty())
			{
				for (int i=0;i<weights.size();++i)
				{ 
					item1 = 0;
					item2 = 0;
					if(bag1 + weights[i] <= w1)
					{
						this->swap_number(item1, weights[i]);
						bag1 = bag1 + weights[i];
					}
					
				}
			}
			return max_weight;
		}
		
};

int main()
{
  std::vector<int> weights = {10, 7, 8, 3, 12, 1};
	Baggage A;
  int max_weight = A.maximum_weights(weights, 10, 5);
	std::cout << max_weight << std::endl;
  return 0;
}
