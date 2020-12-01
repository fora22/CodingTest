#include "pch.h"
#include "CppUnitTest.h"
#include "../VS/main.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{
	TEST_CLASS(UnitTest)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			Assert::AreEqual(0, BinarySearch(0));
		}
	};
}
