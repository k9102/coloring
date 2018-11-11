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
#include <map>


int color3[3][3] = {
	{14,33,91},
	{8,29,78},
	{65,55,11}
};

int color5[5][3] = {
	{14,32,18},
	{43,22,93},
	{9,12,16},
	{39,71,31},
	{14,16,28}
};

using namespace std;
int(*color)[3] = color5;
int N = 5;
map<pair<int,int>, int> mem;

int Paint(int last_color, int depth)
{
	auto it = mem.find(make_pair(depth,last_color));
	if (it != end(mem))
	{
		return it->second;
	}
	if (depth == N)
	{
		return 0;
	}
	else
	{
		int min_cost = std::numeric_limits<int>::max();
		int loop = depth == 0 ? 3 : 2;
		for (int i = 0; i < loop; i++)
		{
			int next_color = (last_color + 1 + i) % 3;
			int next_depth = depth + 1;
			int cost = Paint(next_color,next_depth)+color[depth][next_color];
			if (cost < min_cost) 
			{
				min_cost = cost;
			}
		}
		mem[make_pair(depth, last_color)] = min_cost;
		return min_cost;
	}
}

int main()
{
#if 1
	N = 1000;
	color = new int[N][3];
	for (int i = 0; i < N; i++)
	{
		color[i][0] = 1;
		color[i][1] = 1;
		color[i][2] = 1;
	}
#endif
	std::cout << "cost:" << Paint(0, 0) << std::endl;

	return 0;
}