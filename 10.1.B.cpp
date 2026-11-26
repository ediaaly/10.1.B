#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

enum Spec { KN, IN, ME, FI, TN };

struct Student
{
    string prizv;
    int kurs;
    Spec spec;
    int physics;
    int math;

    union
    {
        int programming;
        int numerical;
        int pedagogy;
    };
};

void Create(Student* p, int N)
{
    int s;

    for (int i = 0; i < N; i++)
    {
        cout << "\nStudent " << i + 1 << endl;

        cout << "Surname: ";
        cin >> p[i].prizv;

        cout << "Course: ";
        cin >> p[i].kurs;

        cout << "0-KN, 1-IN, 2-ME, 3-FI, 4-TN: ";

        do
        {
            cin >> s;
        } while (s < 0 || s > 4);

        p[i].spec = (Spec)s;

        cout << "Physics: ";
        cin >> p[i].physics;

        cout << "Math: ";
        cin >> p[i].math;

        if (p[i].spec == KN)
        {
            cout << "Programming: ";
            cin >> p[i].programming;
        }
        else if (p[i].spec == IN)
        {
            cout << "Numerical methods: ";
            cin >> p[i].numerical;
        }
        else
        {
            cout << "Pedagogy: ";
            cin >> p[i].pedagogy;
        }
    }
}

void Print(Student* p, int N)
{
    string spec[] = { "KN", "IN", "ME", "FI", "TN" };

    cout << "\nStudents" << endl;
    cout << "+----+------------+------+-------+---------+------+--------+--------+----------+" << endl;
    cout << "| No |    Surname |Course|  Spec | Physics | Math |  Prog  |Numeric | Pedagogy |" << endl;
    cout << "+----+------------+------+-------+---------+------+--------+--------+----------+" << endl;

    for (int i = 0; i < N; i++)
    {
        cout << "|" << setw(4) << i + 1
            << "|" << setw(12) << p[i].prizv
            << "|" << setw(6) << p[i].kurs
            << "|" << setw(7) << spec[p[i].spec]
            << "|" << setw(9) << p[i].physics
            << "|" << setw(6) << p[i].math;

        if (p[i].spec == KN)
            cout << "|" << setw(8) << p[i].programming
            << "|" << setw(8) << "-"
            << "|" << setw(10) << "-" << "|";

        else if (p[i].spec == IN)
            cout << "|" << setw(8) << "-"
            << "|" << setw(8) << p[i].numerical
            << "|" << setw(10) << "-" << "|";

        else
            cout << "|" << setw(8) << "-"
            << "|" << setw(8) << "-"
            << "|" << setw(10) << p[i].pedagogy << "|";

        cout << endl;
    }

    cout << "+----+------------+------+-------+---------+------+--------+--------+----------+" << endl;
}

double Percent(Student* p, int N)
{
    int k = 0;

    for (int i = 0; i < N; i++)
    {
        if (p[i].physics == 5)
            k++;
    }

    if (N == 0)
        return 0;

    return 100.0 * k / N;
}

int main()
{
    int N;

    cout << "Enter N: ";
    cin >> N;

    if (N <= 0)
        return 0;

    Student* p = new Student[N];

    Create(p, N);
    Print(p, N);

    cout << "Percent: " << fixed << setprecision(2)
        << Percent(p, N) << "%" << endl;

    delete[] p;

    return 0;
}