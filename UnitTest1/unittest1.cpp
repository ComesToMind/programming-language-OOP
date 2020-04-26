#include "stdafx.h"
#include "CppUnitTest.h"
#include "../programming language OOP/Container.h"
#include "../programming language OOP/Functional.h"
#include "../programming language OOP/Language.h"
#include "../programming language OOP/ObjectOriented.h"
#include "../programming language OOP/Procedural.h"
#include "../programming language OOP/Container.cpp"
#include "../programming language OOP/Functional.cpp"
#include "../programming language OOP/Language.cpp"
#include "../programming language OOP/ObjectOriented.cpp"
#include "../programming language OOP/Procedural.cpp"
//#include "../UnitTest1/ContainerOutputIn.txt"
//#include "../UnitTest1/ContainerOutput.txt"
//#include "../UnitTest1/SortContainerExp.txt"



using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(YearsPassedM)
		{
			ObjectOriented language;
			language.SetmData(2014);
			int actual = language.YearsPassed();
			int expected = 2020 - language.GetmData();
			Assert::AreEqual(expected, actual);
		}
		TEST_METHOD(TestCompareM)
		{
	

			Functional language_new;
			Procedural language_old;
			language_new.SetmData(2020);
			language_old.SetmData(2010);
			bool actual = language_new.Compare(language_old);
			bool expected = true;
			Assert::AreEqual(expected, actual);


		}
		TEST_METHOD(ProceduralInputM)
		{
			ifstream fin("C:\\Users\\Данила\\source\\repos\\programming Versions\\oop3\\programming-language-OOP\\UnitTest1\\In_Proc_Test.txt");
			if (fin.is_open())
			{
				Procedural actual;
				actual.InData(fin);
				Procedural expected;
				expected.SetmAbstractDT(0);
				expected.SetmData(2000);
				expected.SetmRef(20000);
				Assert::AreEqual(expected.GetmAbstractDT(), actual.GetmAbstractDT());
				Assert::AreEqual(expected.GetmData(), actual.GetmData());
				Assert::AreEqual(expected.GetmRef(), actual.GetmRef());
			}
		}

		TEST_METHOD(ProceduralOutput)
		{
			ofstream fout("C:\\Users\\Данила\\source\\repos\\programming Versions\\oop3\\programming-language-OOP\\UnitTest1\\Out_Proc_Test_Act.txt");
			Procedural act;
			act.SetmAbstractDT(0);
			act.SetmData(2000);
			act.SetmRef(20000);

			act.Out(fout);
			fout.close();
			ifstream fin_act("C:\\Users\\Данила\\source\\repos\\programming Versions\\oop3\\programming-language-OOP\\UnitTest1\\Out_Proc_Test_Act.txt");
			ifstream fin_exp("C:\\Users\\Данила\\source\\repos\\programming Versions\\oop3\\programming-language-OOP\\UnitTest1\\Out_Proc_Test_Exp.txt");
			string expected, actual;
			getline(fin_act, actual, '\0');
			getline(fin_exp, expected, '\0');
			Assert::AreEqual(expected, actual);

		}
		TEST_METHOD(ContainerStream)
		{
			ifstream fin("C:\\Users\\Данила\\source\\repos\\programming Versions\\oop3\\programming-language-OOP\\UnitTest1\\ContainerOutputIn.txt");
			ofstream fout("C:\\Users\\Данила\\source\\repos\\programming Versions\\oop3\\programming-language-OOP\\UnitTest1\\ContainerOutput.txt");
			if (fin.is_open())
			{

			Container c;
			c.In(fin);
			c.Out(fout);
			fout.close();
			}
			ifstream fin_exp("C:\\Users\\Данила\\source\\repos\\programming Versions\\oop3\\programming-language-OOP\\UnitTest1\\ContainerOutputExp.txt");
			ifstream fin_act("C:\\Users\\Данила\\source\\repos\\programming Versions\\oop3\\programming-language-OOP\\UnitTest1\\ContainerOutput.txt");
			string expected((std::istreambuf_iterator<char>(fin_exp)), std::istreambuf_iterator<char>());
			string actual((std::istreambuf_iterator<char>(fin_act)), std::istreambuf_iterator<char>());
			Assert::AreEqual(expected, actual);
		}
		TEST_METHOD(SortContainer)
		{
			ifstream fin("C:\\Users\\Данила\\source\\repos\\programming Versions\\oop3\\programming-language-OOP\\UnitTest1\\ContainerOutputIn.txt");
			ofstream fout("C:\\Users\\Данила\\source\\repos\\programming Versions\\oop3\\programming-language-OOP\\UnitTest1\\ContainerOutput.txt");
			Container c;
			c.In(fin);
			c.Sort();
			c.Out(fout);
			fout.close();
			ifstream fin_exp("C:\\Users\\Данила\\source\\repos\\programming Versions\\oop3\\programming-language-OOP\\UnitTest1\\SortContainerExp.txt");
			ifstream fin_act("C:\\Users\\Данила\\source\\repos\\programming Versions\\oop3\\programming-language-OOP\\UnitTest1\\ContainerOutput.txt");
			string expected((std::istreambuf_iterator<char>(fin_exp)), std::istreambuf_iterator<char>());
			string actual((std::istreambuf_iterator<char>(fin_act)), std::istreambuf_iterator<char>());
			Assert::AreEqual(expected, actual);
		}
		TEST_METHOD(OnlyProc)
		{
			ifstream fin("C:\\Users\\Данила\\source\\repos\\programming Versions\\oop3\\programming-language-OOP\\UnitTest1\\ContainerOutputIn.txt");
			ofstream fout("C:\\Users\\Данила\\source\\repos\\programming Versions\\oop3\\programming-language-OOP\\UnitTest1\\ContainerOutput.txt");
			Container c;
			c.In(fin);
			c.OutProc(fout);
			fout.close();
			ifstream fin_exp("C:\\Users\\Данила\\source\\repos\\programming Versions\\oop3\\programming-language-OOP\\UnitTest1\\OnlyProcExp.txt");
			ifstream fin_act("C:\\Users\\Данила\\source\\repos\\programming Versions\\oop3\\programming-language-OOP\\UnitTest1\\ContainerOutput.txt");
			string expected((std::istreambuf_iterator<char>(fin_exp)), std::istreambuf_iterator<char>());
			string actual((std::istreambuf_iterator<char>(fin_act)), std::istreambuf_iterator<char>());
			Assert::AreEqual(expected, actual);
		}


	};
}