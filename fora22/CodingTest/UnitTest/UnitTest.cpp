#include "pch.h"
#include "CppUnitTest.h"
#include "../VS/main.cpp"
#include <fstream>

using namespace std;
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{

	TEST_CLASS(UnitTest)
	{
	public:

		TEST_METHOD(TestMethod1)
		{
			ifstream readfile("input.txt");
			
			Assert::AreEqual(solve(&readfile), 3);
		}
		//TEST_METHOD(TestMethod2)
		//{
		//	Assert::AreEqual(solve("h2"), 3);
		//}
		//TEST_METHOD(TestMethod3)
		//{
		//	Assert::AreEqual(solve("b7"), 4);
		//}
		//TEST_METHOD(TestMethod4)
		//{
		//	Assert::AreEqual(solve("g3"), 6);
		//}
		//TEST_METHOD(TestMethod5)
		//{
		//	Assert::AreEqual(solve("e5"), 8);
		//}
	};

}
