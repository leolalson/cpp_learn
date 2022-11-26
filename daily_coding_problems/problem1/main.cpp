#include <iostream>
#include <vector>
#include <numeric>

bool check_bisum(std::vector<int> v1, int key)
{
  int bisum;
  for (int i=0;i<v1.size();++i)
  {
	for(int j=0;j<v1.size();++j)
	{
	  if (i!=j)
	  {
		bisum = v1[i] + v1[j];
		if (bisum == key)
		{
		  return true;
		}
	  }
	}
  }
	  
  return false;
}
int main()
{
  std::vector<int> vec = {10, 15, 3, 7};
  int key = 20;
  bool check = check_bisum(vec, key);
  std::cout << "check: " << check << std::endl;
  return 0;
}
