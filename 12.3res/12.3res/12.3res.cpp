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
void AddDoubleList(Elem*& first, Elem*& last, int N, int Low, int High, int i);
void Print(Elem* first);
int EvenSum(Elem* first, int S);

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    srand((unsigned)time(NULL));
    Elem* first = NULL;
    Elem* last = NULL;

    int N, Low, High;
    cout << "Кількість елементів: "; cin >> N;
    cout << "Найбільше значення елементів: "; cin >> Low;
    cout << "Найменше значення елементів: "; cin >> High;
    cout << "Список:" << endl;
    AddDoubleList(first, last, N, Low, High, 1);
    Print(first);
    cout << endl;
    cout << "Сума парних елементів списку:" << EvenSum(first, 0) << endl;
    cout << endl;

    system("pause");
    return 0;
}

void AddDoubleList(Elem*& first, Elem*& last, int N, int Low, int High, int i)
{
    if (i <= N)
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
        AddDoubleList(first, last, N, Low, High, i + 1);
    }
}

void Print(Elem* first)
{
    if (first != NULL)
    {
        cout << first->info << "  ";
        Print(first->next);
    }
}

int EvenSum(Elem* first, int S)
{
    if (first != NULL)
    {
        if (first->info % 2 == 0)
            S += first->info;
        return EvenSum(first->next, S);
    }
    else
        return S;
}
