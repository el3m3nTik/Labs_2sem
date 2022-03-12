// Лаб. работа 3 (2 семестр).cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
/*
1.Реализуйте алгоритм бинарного поиска, о котором шла речь на лекции.
Решите задачу выполнения M (0<M<10000) поисковых запросов над массивом из N (0<N<100000) элементов,
используя проход по массиву циклом и бинарный поиск. Сравните время работы этих двух подходов.
2.Найдите корень уравнения x^2 - 10 = 0 на отрезке [0; +беск] с точностью до 10^-4 с помощью бисекции.
*/

#include <iostream>
#include <vector>
#include <chrono>
class Timer
{
private:
    // Псевдонимы типов используются для удобного доступа к вложенным типам
    using clock_t = std::chrono::high_resolution_clock;
    using second_t = std::chrono::duration<double, std::ratio<1> >;
    std::chrono::time_point<clock_t> m_beg;
public:
    Timer() : m_beg(clock_t::now())
    {
    }
    void reset()
    {
        m_beg = clock_t::now();
    }
    double elapsed() const
    {
        return std::chrono::duration_cast<second_t>(clock_t::now() - m_beg).count();
    }
};
#define N 100000
using namespace std;

void Blender(vector<int>& vec)
{
    srand(time(0));
    int len = vec.size();
    int r = 0;
    for (int i = 0; i < len; i++)
    {
        r = rand() % len;
        if (r != i)
        {
            swap(vec[i], vec[r]);
        }
    }
}

void Printer(std::vector<int>& vec)
{
    int len = vec.size();
    if (len <= 2000)
    {
        for (int i = 0; i < len; i++)
        {
            std::cout << vec[i] << " ";
        }
    }
    cout << endl << endl;
}

int Slow_Search(std::vector<int>& vec, int key)
{
    int l = vec.size();
    for (int i = 0; i < l; i++)
    {
        if (vec[i] == key)
        {
            return 1;
        }
    }
    return -1;
}

int Search(std::vector<int>& vec, int key)
{
    bool flag = false;
    int len = 0;
    int r = vec.size();
    int m;

    while ((len <= r) && (flag != true)) {
        m = (len + r) / 2;

        if (vec[m] == key) flag = true;
        if (vec[m] > key) r = m - 1;
        else len = m + 1;
    }
    if (flag) return 1;
    else return -1;
}


double f(double x)
{
    return x * x - 10;
}
double Bisection(double a, double b, double e) // функция, которая ищет ноль на промежутке от a до b
{
    while (b - a > e) 
    {
        if (f(a) * f((b + a) / 2) == 0)
            break;
        else if (f(a) * f((b + a) / 2) > 0)
            a = (b + a) / 2;
        else
            b = (b + a) / 2;
    }
    return (b + a) / 2;
}


int main()
{
    setlocale(LC_ALL, "Rus");
    srand(time(0));
    std::vector<int> arr; 
    int count = 0;
    for (int i = 0; i < N; i++)
    {
        arr.push_back(i);
    }
    std::vector<int> vkey = arr;
    Blender(vkey);
    for (int i = 0; i < (N - (N / 10)); i++)
    {
        vkey.erase(vkey.begin());
    }
    std::cout << "Binary search" << std::endl;
    Timer t1;
    std::cout << "Elapsed time: " << t1.elapsed() << std::endl;
    std::cout << "Loop search" << std::endl;
    Timer t2;
    std::cout << "Elapsed time: " << t2.elapsed() << std::endl;
    cout << endl << Bisection(0, 100, 0.0001); // Ответ 3.16224
 
    return 0;
}