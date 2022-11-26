#include<iostream>
#include<queue>
#include<cstring>
#include<vector>

using namespace std;

std::pair<int, int> cons(int a, int b)
{
	std::pair<int, int> mp = std::make_pair(a, b);
	return mp;
}

int car(std::pair<int, int> mp)
{
	return mp.first;
}
int cdr(std::pair<int, int> mp)
{
	return mp.second;
}
	
int main()
{
	std::cout << cdr(cons(3,4)) << std::endl;
	std::cout << car(cons(3,4)) << std::endl;
	return 0;
}