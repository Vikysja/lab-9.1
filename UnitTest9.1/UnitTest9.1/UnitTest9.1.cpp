#include "pch.h"
#include "CppUnitTest.h"

#include "../lab_9.1/Student.cpp"
#include "../lab_9.1/extendFunctions.cpp"
#include "../lab_9.1/lab_9.1.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest91
{
    TEST_CLASS(UnitTest91)
    {
    public:

        TEST_METHOD(TestGetCountScore)
        {
            const int N = 10;

            Student students[N] = {
              {"Moroz",     4, KN,  4, 4, 5},
              {"Tkachuk",   4, INF, 4, 3, 4},
              {"Petrenko",  4, ME,  5, 4, 2},
              {"Koval",     4, KN,  3, 3, 3},
              {"Tkachenko", 4, FI,  5, 5, 2},
              {"Rudenko",   4, INF, 3, 5, 5},
              {"Boyko",     4, FI,  2, 4, 4},
              {"Savchenko", 4, MF,  4, 3, 5},
              {"Lysenko",   4, INF, 4, 5, 3},
              {"Melnyk",    4, FI,  1, 3, 5},
            };

            ScoresCount scores = getCountsScore(students, N);

            Assert::AreEqual(2, scores.three);
            Assert::AreEqual(4, scores.four);
            Assert::AreEqual(2, scores.five);
        };

        TEST_METHOD(TestGetCountScoreEmpty)
        {
            const int N = 0;

            Student* students = {};

            ScoresCount scores = getCountsScore(students, N);

            Assert::AreEqual(0, scores.three);
            Assert::AreEqual(0, scores.four);
            Assert::AreEqual(0, scores.five);
        };

        TEST_METHOD(TestCountStudents)
        {
            const int N = 10;

            Student students[N] = {
              {"Moroz",     4, KN,  4, 4, 5},
              {"Tkachuk",   4, INF, 4, 3, 4},
              {"Petrenko",  4, ME,  5, 4, 2},
              {"Koval",     4, KN,  3, 3, 3},
              {"Tkachenko", 4, FI,  5, 5, 2},
              {"Rudenko",   4, INF, 3, 5, 5},
              {"Boyko",     4, FI,  2, 4, 4},
              {"Savchenko", 4, MF,  4, 3, 5},
              {"Lysenko",   4, INF, 4, 5, 3},
              {"Melnyk",    4, FI,  1, 3, 5},
            };

            Assert::AreEqual(4, CountStudents(students, N));
        };

        TEST_METHOD(TestCountStudentsEmpty)
        {
            const int N = 0;

            Student* students = {};

            Assert::AreEqual(0, CountStudents(students, N));
        };
    };
}
