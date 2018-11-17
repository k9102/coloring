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

#define COLOR_NUM 3
int color3[3][COLOR_NUM] = {
	{14, 33, 91},
	{8, 29, 78},
	{65, 55, 11}};

int color5[5][COLOR_NUM] = {
	{14, 32, 18},
	{43, 22, 93},
	{9, 12, 16},
	{39, 71, 31},
	{14, 16, 28}};

int color1k[1000][COLOR_NUM];

using namespace std;

class Coloring
{
  private:
	const int (*color_)[COLOR_NUM];
	int length_;
	map<pair<int, int>, int> cache_;

  public:
	Coloring(const int (*color)[COLOR_NUM],int length)
	{
		color_ = color;
		length_ = length;
	};
	int Paint(int last_color, int depth)
	{
		auto it = cache_.find(make_pair(depth, last_color));
		if (it != end(cache_))
		{
			return it->second;
		}
		if (depth == length_)
		{
			return 0;
		}
		else
		{
			int min_cost = std::numeric_limits<int>::max();
			int loop = depth == 0 ? COLOR_NUM : COLOR_NUM - 1;
			for (int i = 0; i < loop; i++)
			{
				int next_color = (last_color + 1 + i) % COLOR_NUM;
				int next_depth = depth + 1;
				int cost = Paint(next_color, next_depth) + color_[depth][next_color];
				min_cost = std::min(min_cost, cost);
			}
			cache_[make_pair(depth, last_color)] = min_cost;
			return min_cost;
		}
	}

};

template<int l> void DoColoring(const int (&color)[l][COLOR_NUM])
{
	Coloring coloring(color,l);
	std::cout << "cost:" << coloring.Paint(-1, 0) << std::endl;
}

int main()
{
	for (int i = 0; i < 1000; i++)
	{
		color1k[i][0] = 1;
		color1k[i][1] = 1;
		color1k[i][2] = 1;
	}

	DoColoring(color3);
	DoColoring(color5);
	DoColoring(color1k);

	return 0;
}