#include "SortArray.h"


int main()
{
	setlocale(LC_ALL, "RU");
	try {
		std::vector<int> A = random(1000);
		auto result = BubbleSort(A);
		std::cout << ToString(A) << '\n' << std::endl;
		std::cout << ToString(result);
		return 0;
	}
	catch (std::exception& e)
	{
		std::cerr << e.what();
		return 1;
	}
};
