#pragma once
#include <vector>
#include <iostream>
#include <string>
#include <sstream>
#include <random>

std::vector<int> QuickSort(std::vector<int>& data)
{
	if (data.size() < 2) return data;

	int temp = data[0];
	std::vector<int> left;
	std::vector<int> right;
	for (size_t i = 1; i < data.size(); i++)
	{
		if (data[i] < temp)
		{
			left.push_back(data[i]);
		}
		else
		{
			right.push_back(data[i]);
		}
	}
	std::vector<int> temp1 = QuickSort(left);
	std::vector<int> temp2 = QuickSort(right);
	temp1.push_back(temp);
	temp1.insert(temp1.end(), temp2.begin(), temp2.end());
	return temp1;
}

std::string ToString(std::vector<int>& data)
{
	std::ostringstream buffer;
	buffer << "[";
	for (size_t i = 0; i < data.size(); i++)
	{
		buffer << data[i];
		if (i != data.size() - 1)
		{
			buffer << ",";
		}
	}
	buffer << "]";
	return buffer.str();
}

std::vector<int> random(const int size)
{
	if (size < 1)
	{
		throw std::out_of_range("Выход за пределы");
	}
	else
	{
		const int max = 9000;
		const int min = 0;
		std::random_device rd;

		//Standard mersenne_twister_engine seeded with rd()
		std::mt19937 gen(rd());

		std::uniform_int_distribution<> uniformIntDistribution(min, max);

		std::vector<int> array;
		for (size_t index = 0; index < size; index++)
		{
			array.push_back(uniformIntDistribution(gen));
		}

		return array;
	}
}

std::vector<int> InsertSort(const std::vector<int>& data)
{
	std::vector<int> sortedArr = data;
	auto n = sortedArr.size();

	for (int i = 1; i < n; ++i)
	{
		int key = sortedArr[i];
		int j = i - 1;

		while (j >= 0 && sortedArr[j] > key)
		{
			sortedArr[j + 1] = sortedArr[j];
			--j;
		}
		sortedArr[j + 1] = key;
	}

	return sortedArr;
}

std::vector<int> BubbleSort(const std::vector<int>& data)
{
	std::vector<int> sortedArr = data;
	auto n = sortedArr.size();
	bool swapped = true;

	for (int i = 0; i < n - 1 && swapped; ++i) {
		swapped = false;
		for (int j = 0; j < n - i - 1; ++j) {
			if (sortedArr[j] > sortedArr[j + 1]) {
				std::swap(sortedArr[j], sortedArr[j + 1]);
				swapped = true;
			}
		}
	}

	return sortedArr;
}
