#include "pch.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace TestingModule
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestModuleCustomConstructor)
		{
			// Arrange
			std::string mTitle = "Object Oriented Programming", mCode = "COM 326";
			int mCredit = 25, mMark = 95;
			int counter1 = 0;

			Module mTmp1{ mTitle, mCode, mCredit, mMark };

			// Act
			if (mTitle != mTmp1.getModuleTitle() || mCode != mTmp1.getModuleCode() || mCredit != mTmp1.getModuleCreditPoints() || mMark != mTmp1.getModuleMark()) {
				counter1++;
			}

			//Assert
			Assert::AreEqual(0, counter1);

		}
		TEST_METHOD(TestGetModuleCode)
		{
			// Arrange
			Module mTmp1;
			std::string mCode{"COM 326"};

			// Act
			mTmp1.setModuleCode(mCode);
			std::string actual = mTmp1.getModuleCode();

			//Assert
			Assert::AreEqual(actual, mCode);

		}
		TEST_METHOD(TestSetModuleCode)
		{
			// Arrange
			Module mTmp1;
			std::string mCode{ "COM 326" };

			// Act
			mTmp1.setModuleCode(mCode);
			std::string actual = mTmp1.getModuleCode();

			//Assert
			Assert::AreEqual(actual, mCode);

		}
		TEST_METHOD(TestGetModuleCreditPoint)
		{
			// Arrange
			Module mTmp1;
			int mCreditPoints{ 25 };

			// Act
			mTmp1.setModuleCreditPoints(mCreditPoints);
			int actual = mTmp1.getModuleCreditPoints();

			//Assert
			Assert::AreEqual(actual, mCreditPoints);

		}
		TEST_METHOD(TestSetModuleCreditPoint)
		{
			// Arrange
			Module mTmp1;
			int mCreditPoints{ 25 };

			// Act
			mTmp1.setModuleCreditPoints(mCreditPoints);
			int actual = mTmp1.getModuleCreditPoints();

			//Assert
			Assert::AreEqual(actual, mCreditPoints);

		}
	};
}

namespace TestingStudent
{
	TEST_CLASS(UnitTest1)
	{
	public:

		TEST_METHOD(TestStudentCustomConstructor)
		{
			// Arrange
			std::string mTitle1 = "Object Oriented Programming", mCode1 = "COM 326";
			int mCredit1 = 25, mMark1 = 95;

			std::string mTitle2 = "UX", mCode2 = "COM 321";
			int mCredit2 = 25, mMark2 = 95;

			std::string sName = "Shane Wilson", sRegistration = "B00769147", sCourse = "BSc Computer Science";
			int sYearOfStudy = 25;
			int counter1 = 0;

			std::vector<Module> sM{ Module{ mTitle1, mCode1, mCredit1, mMark1 }, Module{ mTitle2, mCode2, mCredit2, mMark2 } };

			Student mTmp1{ sName, sRegistration, sCourse, sYearOfStudy, sM};

			// Act
			if (sName != mTmp1.GetName() || sRegistration != mTmp1.GetRegistrationID() || sCourse != mTmp1.GetCourse() || sYearOfStudy != mTmp1.GetYearofStudy()) {
				counter1++;
			}

			//Assert
			Assert::AreEqual(0, counter1);

		}
		TEST_METHOD(TestStudentAddModuleObject)
		{
			// Arrange
			std::string mTitle1 = "Object Oriented Programming", mCode1 = "COM 326";
			int mCredit1 = 25, mMark1 = 95;

			std::string mTitle2 = "UX", mCode2 = "COM 321";
			int mCredit2 = 25, mMark2 = 95;

			std::string sName = "Shane Wilson", sRegistration = "B00769147", sCourse = "BSc Computer Science";
			int sYearOfStudy = 25;
			int counter1 = 0;

			std::vector<Module> sM{ Module{ mTitle1, mCode1, mCredit1, mMark1 }, Module{ mTitle2, mCode2, mCredit2, mMark2 } };

			//Student mTmp1{ sName, sRegistration, sCourse, sYearOfStudy, sM };

			// Act
			/*if (mTmp1.GetModuleMarks().at(0) != sM.at(0) || mTmp1.GetModuleMarks().at(1) != sM.at(1)) {
				counter1++;
			}*/
			Student mTmp1{ sName, sRegistration, sCourse, sYearOfStudy, sM };

			//Assert
			Assert::AreEqual(mTmp1.GetModuleMarks().at(0).getModuleTitle(), sM.at(0).getModuleTitle());

		}
		TEST_METHOD(TestStudentAddModuleArgs)
		{
			// Arrange
			std::string mTitle1 = "Object Oriented Programming", mCode1 = "COM 326";
			int mCredit1 = 25, mMark1 = 95;

			std::string mTitle2 = "UX", mCode2 = "COM 321";
			int mCredit2 = 25, mMark2 = 95;

			std::string sName = "Shane Wilson", sRegistration = "B00769147", sCourse = "BSc Computer Science";
			int sYearOfStudy = 25;
			int counter1 = 0;

			std::vector<Module> sM{ Module{ mTitle1, mCode1, mCredit1, mMark1 }, Module{ mTitle2, mCode2, mCredit2, mMark2 } };

			//Student mTmp1{ sName, sRegistration, sCourse, sYearOfStudy, sM };

			// Act
			/*if (mTmp1.GetModuleMarks().at(0) != sM.at(0) || mTmp1.GetModuleMarks().at(1) != sM.at(1)) {
				counter1++;
			}*/
			Student mTmp1{ sName, sRegistration, sCourse, sYearOfStudy, sM };

			//Assert
			Assert::AreEqual(mTmp1.GetModuleMarks().at(0).getModuleCode(), sM.at(0).getModuleCode());

		}
		TEST_METHOD(TestStudentClassification)
		{
			// Arrange
			std::string mTitle1 = "Object Oriented Programming", mCode1 = "COM 326";
			int mCredit1 = 25, mMark1 = 95;

			std::string mTitle2 = "UX", mCode2 = "COM 321";
			int mCredit2 = 25, mMark2 = 95;

			std::string sName = "Shane Wilson", sRegistration = "B00769147", sCourse = "BSc Computer Science";
			int sYearOfStudy = 25;
			int counter1 = 0;

			std::vector<Module> sM{ Module{ mTitle1, mCode1, mCredit1, mMark1 }, Module{ mTitle2, mCode2, mCredit2, mMark2 } };

			std::string expected{ "1st class" };

			Student mTmp1{ sName, sRegistration, sCourse, sYearOfStudy, sM };

			// Act
			std::string actual = mTmp1.CalculateClassification();

			//Assert
			Assert::AreEqual(actual, expected);
		}
		TEST_METHOD(TestDeleteModule)
		{
			// Arrange
			std::string mTitle1 = "Object Oriented Programming", mCode1 = "COM 326";
			int mCredit1 = 25, mMark1 = 95;

			std::string mTitle2 = "UX", mCode2 = "COM 321";
			int mCredit2 = 25, mMark2 = 95;

			std::string sName = "Shane Wilson", sRegistration = "B00769147", sCourse = "BSc Computer Science";
			int sYearOfStudy = 25;
			int counter1 = 0;

			std::vector<Module> sM{ Module{ mTitle1, mCode1, mCredit1, mMark1 }, Module{ mTitle2, mCode2, mCredit2, mMark2 } };

			std::string expected{ "1st class" };

			Student mTmp1{ sName, sRegistration, sCourse, sYearOfStudy, sM };

			// Act
			mTmp1.DeleteModule("COM 321");
			int actual = mTmp1.GetModuleMarks().size();

			//Assert
			Assert::AreEqual(actual, int(sM.size() - 1));

		}
	};
}