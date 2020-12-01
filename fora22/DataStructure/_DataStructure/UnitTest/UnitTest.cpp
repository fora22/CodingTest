#include "pch.h"
#include "CppUnitTest.h"
#include "../VS/main.cpp"
#include <vector>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{
	TEST_CLASS(UnitTest)
	{
	public:
		vector<int> inputData_1{ 1, 3, 4, 7, 8, 13, 17 };

		TEST_METHOD(TestMethod1)
		{
			Assert::AreEqual(5, BinarySearch(inputData_1, inputData_1.size(), 8));
		}
	};
}
