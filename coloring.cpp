// coloring.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "pch.h"
#include <iostream>
#include <tuple>
#include <algorithm>
#include <vector>
#include <array>
#include <cassert>
#include <limits>

#if 0
int color[3][3] = {
	{14,33,91},
	{8,29,78},
	{65,55,11}
};
int N = 3;
#else
int color[5][3] = {
	{14,32,18},
	{43,22,93},
	{9,12,16},
	{39,71,31},
	{14,16,28}
};
int N = 5;
#endif
int Paint(int sum, int last_color, int depth)
{
	if (depth == N)
	{
		return sum;
	}
	else
	{
		int min = std::numeric_limits<int>::max();
		int loop = depth == 0 ? 3 : 2;
		for (int i = 0; i < loop; i++)
		{
			int next_color = (last_color + 1 + i) % 3;
			int cost = Paint(sum + color[depth][next_color], next_color, depth + 1);
			if (cost < min) min = cost;
		}
		return min;
	}
}

int main()
{

	std::cout << "cost:" << Paint(0, 0, 0) << std::endl;

	return 0;
}