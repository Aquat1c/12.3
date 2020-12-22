#include <iostream>
#include <windows.h>
#include <time.h>
#include <iomanip>
using namespace std;

struct Elem
{
    Elem* next;
    Elem* prev;
    int info;
};
void AddDoubleList(Elem*& first, Elem*& last, int N, int min, int max);
void Print(Elem* first);
int Sum(Elem* first);

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    srand((unsigned)time(NULL));
    Elem* first = NULL;
    Elem* last = NULL;

    int N, Low, High;
    cout << "Кількість елементів списку: "; cin >> N;
    cout << "Найменше значення елементу: "; cin >> Low;
    cout << "Найбільше значення елементу: "; cin >> High;
    cout << "Список:" << endl;
    AddDoubleList(first, last, N, Low, High);
    Print(first);
    cout << "Сума парних елементів: " << Sum(first) << endl;
    cout << endl;

    system("pause");
    return 0;
}

void AddDoubleList(Elem*& first, Elem*& last, int N, int Low, int High)
{
    for (int i = 1; i <= N; i++)
    {
        int infoElem = Low + rand() % (Low - High + 1);
        Elem* tmp = new Elem;
        tmp->info = infoElem;
        tmp->next = NULL;
        if (last != NULL)
            last->next = tmp;
        tmp->prev = last;
        last = tmp;
        if (first == NULL)
            first = tmp;
    }
}

void Print(Elem* first)
{
    while (first != NULL)
    {
        cout << first->info << "  ";
        first = first->next;
    }
    cout << endl;
}

int Sum(Elem* first)
{
    int S = 0;
    while (first != NULL)
    {
        if (first->info % 2 == 0)
            S += first->info;
        first = first->next;
    }
    return S;
}
