#include <iostream>
#include <cmath>

using namespace std;

int main2()
{
    int number = 0; /// номер задачи
    cout << "Please, enter the number of task ( 1, 2, 3, 4, 5 )" << endl;
    cout << "1. n = 2^x ?" << endl;
    cout << "2. x * 1.1n >= y : n = ?" << endl;
    cout << "3. n = ab..z : a + b + ... + z = ?" << endl;
    cout << "4. 1/0! + 1/1! + ... + 1/n! = ?" << endl;
    cout << "5. Input: current date. Output: tomorrow's date." << endl;
    /// Ввод номера задачи
    while (number == 0)
    {
        cin >> number;
        if (number < 1 || number > 5)
            number = 0;
    }
    /// Выбор задачи в соответствии со введенным номером
    switch (number)
    {
        case 1:
        {
            int n = 0; /// входное число
            bool even = true; /// флаг четности
            /// Ввод входного числа
            while (n == 0)
            {
                cout << "n = ";
                cin >> n;
                if (n < 1)
                    n = 0;
            }
            /// Проверка: является ли число степенью 2?
            while (n > 1)
            {
                if (n % 2)
                {
                    even = false;
                    break;
                }
                n /= 2;
            }
            /// Вывод результата
            if (even)
                cout << "YES" << endl;
            else
                cout << "NO" << endl;
            break;
        }
        case 2:
        {
            double x = 0; /// начальное значение пробега
            double y = 0; /// желаемое значение пробега
            double n = 1; /// номер дня, в который был достигнут желаемый пробег
            /// Ввод данных
            while (x == 0)
            {
                cout << "x = ";
                cin >> x;
                if (x <= 0)
                    x = 0;
            }
            while (y == 0)
            {
                cout << "y = ";
                cin >> y;
                if (y <= 0)
                    y = 0;
            }
            /// Проведение вычислений (если x >= y, желаемый пробег достигнут в 1 день)
            if (x < y)
                n = int(log(y / x) / log(1.1)) + 2;
            cout << n << endl;
            break;
        }
        case 3:
        {
            int n = 0; /// входное число
            int sum = 0; /// сумма цифр числа
            /// Ввод входного числа
            while (n == 0)
            {
                cout << "n = ";
                cin >> n;
                if (n < 1)
                    n = 0;
            }
            /// Обработка числа с вычислением суммы его цифр
            while (n > 0)
            {
                sum += n % 10;
                n /= 10;
            }
            cout << sum << endl;
            break;
        }
        case 4:
        {
            int i = 1; /// счетчик последовательности
            int factorial = 1; /// текущее значение факториала
            int n = -1; /// входное число
            double sum = 1; /// значение суммы последовательности
            /// Ввод входного числа
            while (n == -1)
            {
                cout << "n = ";
                cin >> n;
                if (n < 0 || n > 12)
                    n = -1;
                if (n == -1)
                    cout << "n = [0 , 12]" << endl;
            }
            /// Вычисления
            while (i <= n)
            {
                sum += 1./factorial;
                i++;
                factorial *= i;
            }
            cout << sum << endl;
            break;
        }
        case 5:
        {
            int day = 0; /// день
            int month = 0; /// месяц
            int year = 0; /// год
            /// Ввод данных
            cout << "Please, enter the date" << endl;
            cin >> day >> month >> year;
            if (year < 1)
            {
                cout << "Incorrect date" << endl;
                return 1;
            }
            /// Обработка данных в зависимости от месяца
            switch (month)
            {
                case 1:
                case 3:
                case 5:
                case 7:
                case 8:
                case 10:
                case 12:
                    {
                        if (day > 31)
                        {
                            cout << "Incorrect date" << endl;
                            return 1;
                        }
                        else
                        {
                            day++;
                            if (day == 32)
                            {
                                day = 1;
                                month++;
                            }
                        }
                        break;
                    }
                case 4:
                case 6:
                case 9:
                case 11:
                    {
                        if (day > 30)
                        {
                            cout << "Incorrect date" << endl;
                            return 1;
                        }
                        else
                        {
                            day++;
                            if (day == 31)
                            {
                                day = 1;
                                month++;
                            }
                        }
                        break;
                    }
                case 2:
                    {
                        if ((day > 28 && (year % 4 != 0 || (year % 100 == 0 && year % 400 != 0))) || (day > 29 && year % 4 == 0 && (year % 100 != 0 || year % 400 == 0)))
                        {
                            cout << "Incorrect date" << endl;
                            return 1;
                        }
                        else
                        {
                            day++;
                            if ((day == 29 && (year % 4 != 0 || (year % 100 == 0 && year % 400 != 0))) || (day == 30 && year % 4 == 0 && (year % 100 != 0 || year % 400 == 0)))
                            {
                                day = 1;
                                month++;
                            }
                        }
                        break;
                    }
                default:
                {
                    cout << "Incorrect date" << endl;
                    return 1;
                }
            }
            if (month == 13)
            {
                month = 1;
                year += 1;
            }
            /// Вывод в стандартном виде даты
            if (day < 10)
                cout << "0" << day << ".";
            else
                cout << day << ".";
            if (month < 10)
                cout << "0" << month << ".";
            else
                cout << month << ".";
            cout << year;
            break;
        }
    }
    return 0;
}

