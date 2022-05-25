// lab 9.1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
// Квецко Вікторії
//Варіант 32

#include <iostream>
#include <iomanip>
#include <Windows.h>

#include "extendFunctions.cpp"
#include "Student.cpp"

using namespace std;

struct ScoresCount {
    int one = 0;
    int two = 0;
    int three = 0;
    int four = 0;
    int five = 0;
};

ScoresCount getCountsScore(Student*, const int);
int CountStudents(Student*, const int);
void pause();

int main()
{
    setlocale(LC_CTYPE, "ukr");

    string specialtyList[] = {
      "Матем. та економіка",
      "Трудове навчання",
      "Фізика та інформ.",
      "Інформатика",
      "Комп’ютерні науки"
    };

    unsigned int N = 0;
    Student* students = nullptr;
    Student* temp = nullptr;

    Student forAutoFill[10] = {
      {"Moroz",     1, KN,  4, 4, 5},
      {"Tkachuk",   4, INF, 4, 3, 4},
      {"Petrenko",  1, ME,  5, 4, 2},
      {"Koval",     3, KN,  3, 3, 3},
      {"Tkachenko", 4, FI,  5, 5, 2},
      {"Rudenko",   1, INF, 3, 5, 5},
      {"Boyko",     5, FI,  2, 4, 4},
      {"Savchenko", 4, MF,  4, 3, 5},
      {"Lysenko",   2, INF, 4, 5, 3},
      {"Melnyk",    3, FI,  1, 3, 5},
    };

    ScoresCount scores;

    int menuItem;
    do {
        cout << endl << endl;
        cout << "Виберіть дію:" << endl << endl;
        cout << " [1] - введення даних з клавіатури" << endl;
        cout << " [2] - автоматичне введення даних" << endl;
        cout << " [3] - вивід даних на екран" << endl;
        cout << " [4] - вивід кількості кожної оціноки з фізики" << endl;
        cout << " [5] - вивід кількісті студентів в яких оцінка з фізики та математики 4 або 5" << endl;

        cout << endl << endl;

        cout << " [0] - вихід та завершення роботи програми" << endl << endl;
        cout << "Введіть значення: "; cin >> menuItem;
        cout << endl << endl << endl;

        switch (menuItem)
        {
        case 1:
            cout << "Введіть N: "; cin >> N;

            delete[] students;
            students = new Student[N];

            Fill(students, N);
            break;
        case 2:
            cout << "Введіть N(max 10): "; cin >> N;
            if (N > 10)
                N = 10;

            temp = new Student[N];

            for (unsigned i = 0; i < N; i++)
                temp[i] = forAutoFill[i];

            delete[] students;
            students = temp;
            break;
        case 3:
            Print(students, N, specialtyList);
            pause();
            break;
        case 4:
            scores = getCountsScore(students, N);

            cout << "Кількість 3 з фізики: " << scores.three << endl;
            cout << "Кількість 4 з фізики: " << scores.four << endl;
            cout << "Кількість 5 з фізики: " << scores.five << endl;

            pause();
            break;
        case 5:
            cout << "Кількість студентів в яких оцінка з фізики та математики 4 або 5: "
                << CountStudents(students, N);

            pause();
            break;
        case 0:
            break;
        default:
            cout << "Ви ввели помилкове значення! "
                "Слід ввести число - номер вибраного пункту меню" << endl;
        }
    } while (menuItem != 0);

    return 0;
}

void pause() {
    cout << endl << "Press Enter";

    cin.get(); getchar();
}

ScoresCount getCountsScore(Student* students, const int N)
{
    ScoresCount newCount{};

    for (int index = 0; index < N; index++) {
        switch (students[index].physics)
        {
        case (1):
            newCount.one++;
            break;

        case (2):
            newCount.two++;
            break;

        case (3):
            newCount.three++;
            break;

        case (4):
            newCount.four++;
            break;

        case (5):
            newCount.five++;
            break;
        }
    }

    return newCount;
}

int CountStudents(Student* students, const int N)
{
    int count = 0;

    for (int index = 0; index < N; index++) {
        int physicScore = students[index].physics;
        int mathScore = students[index].mathematics;

        bool physicCond = physicScore == 4 || physicScore == 5;
        bool mathCond = mathScore == 4 || mathScore == 5;

        count += mathCond && physicCond;
    }

    return count;
}