#define _CRT_SECURE_NO_WARNINGS
#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab_08_2it/Lab_08_2it.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest82Iter
{
	TEST_CLASS(UnitTest82Iter)
	{
	public:
		TEST_METHOD(TestRemoveSpaces)
		{
			char str[100] = "Hello  , world   !";
			char dest[100];
			RemoveSpaces(dest, str);
			Assert::AreEqual("Hello, world!", dest);
		}
	};
}