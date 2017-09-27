#include <iostream>
#include <cmath>

using namespace std;

/// Суммирование всех возможных делителей числа (не равных самому числу)
int decomposition (int x)
{
    int i; /// счетчик (1 - делитель любого числа => начинаем с 2)
    int sum = 1; /// сумма делителей
    int sqrtX = sqrt(x); /// корень квадратный из х
    /// Нахождение делителей числа и их суммы
    for (i = 2; i <= sqrtX; i++)
        if (x % i == 0)
            sum += i + x/i;
    return sum;
}
/// Нахождение НОД (наибольшего общего делителя)
int gcd (int a, int b)
{
	if (b == 0)
		return a;
	else
		return gcd (b, a % b);
}
/// Подсчет количества различных цифр в числе
int function_1 (int N)
{
    int number = 0; /// количество различных цифр в числе
    bool digits[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}; /// массив флагов цифр
    /// Обработка входных данных
    while (N > 0)
    {
        if (!digits[N % 10])
        {
            digits[N % 10] = true;
            number++;
        }
        N /= 10;
    }
    return number;
}
/// Поиск автоморфных чисел меньших заданного числа
void function_2 (int N)
{
    int i; /// счетчик
    int i2; /// квадрат счетчика
    int coefficient; /// коэффициент разряда числа
    int  sum; /// сумма разрядных слагаемых
    /// 0 - автоморфное число, меньшее любого натурального
    cout << "0 ";
    /// Проверка на автоморфность всех натуральных чисел до N
    for (i = 1; i < N; i++)
    {
        i2 = i * i;
        sum = 0;
        coefficient = 1;
        /// Суммирование разрядных слагаемых квадрата счетчика
        while (i2 > 0)
        {
            sum += coefficient * (i2 % 10);
            if (i == sum)
            {
                cout << i << " ";
                break;
            }
            coefficient *= 10;
            i2 /= 10;
        }
    }
    cout << endl;
}
/// Поиск всех несократимых дробей, знаменатель которых меньше заданного числа
void function_3 (int N)
{
    int numerator; /// числитель
    int denominator; /// знаменатель
    int number = 0; /// количество искомых дробей
    /// Перебор возможных вариантов
    for (denominator = 2; denominator < N; denominator++)
    {
        for (numerator = 1; numerator < denominator; numerator++)
        {
            if (gcd(numerator, denominator) == 1)
            {
                cout << numerator << "/" << denominator << " ";
                number++;
            }
        }
    }
    if (number != 0)
        cout << endl;
    else cout << "Not found" << endl;
}
/// Поиск совершенных чисел, меньших заданного числа
void function_4 (int N)
{
    int i; /// счетчик
    int number = 0; /// количество искомых чисел
    /// Перебор возможных вариантов
    for (i = 2; i < N; i++)
        if (i == decomposition(i))
        {
            number++;
            cout << i << " ";
        }
    if (number != 0)
        cout << endl;
    else cout << "Not found" << endl;
}

bool function_5 (int day, int month, int year)
{
    if (year < 1)
    {
        cout << "Incorrect date" << endl;
        return 0;
    }
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
                    return 0;
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
                    return 0;
                }
                break;
            }
        case 2:
            {
                if ((day > 28 && (year % 4 != 0 || (year % 100 == 0 && year % 400 != 0))) || (day > 29 && year % 4 == 0 && (year % 100 != 0 || year % 400 == 0)))
                {
                    cout << "Incorrect date" << endl;
                    return 0;
                }
                break;
            }
        default:
        {
            cout << "Incorrect date" << endl;
            return 0;
        }
    }
    return 1;
}
int main3()
{
    int number = 0; /// номер задачи
    cout << "Please, enter the number of task ( 1, 2, 3, 4, 5 )" << endl;
    cout << "1. N : number of various digits?" << endl;
    cout << "2. N : all automorphic number < N" << endl;
    cout << "3. N : all nonreducible fractions, denominator < N" << endl;
    cout << "4. N : all perfect numbers < N" << endl;
    cout << "5. Input: date of birth, current date. Output: number of lived days, 1(number of lived days), 2(number of lived days), 4 (number of lived days)" << endl;
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
            int N = 0; /// входное число
            /// Ввод входного числа
            while (N == 0)
            {
                cout << "N = ";
                cin >> N;
                if (N < 1)
                    N = 0;
            }
            /// Вывод результата
            cout << function_1(N) << endl;
            break;
        }
        case 2:
        {
            int N = 0; /// входное число
            /// Ввод входного числа
            while (N == 0)
            {
                cout << "N = ";
                cin >> N;
                if (N < 1 || N > 46340)
                    N = 0;
            }
            /// Вывод результата через функцию обработки
            function_2(N);
            break;
        }
        case 3:
        {
            int N = 0; /// входное число
            /// Ввод входного числа
            while (N == 0)
            {
                cout << "N = ";
                cin >> N;
                if (N < 1)
                    N = 0;
            }
            /// Вывод результата через функцию обработки
            function_3(N);
            break;
        }
        case 4:
        {
            int N = 0; /// входное число
            /// Ввод входного числа
            while (N == 0)
            {
                cout << "N = ";
                cin >> N;
                if (N < 1 || N > 1000000)
                    N = 0;
            }
            /// Вывод результата через функцию обработки
            function_4(N);
            break;
        }
        case 5:
        {
            int d1; /// день рождения
            int d2; /// текущий день
            int m1; /// месяц рождения
            int m2; /// текущий месяц
            int y1; /// год рождения
            int y2; /// текущий год

            int month1[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}; /// распределение дней по месяцам в невисокосном году
            int month2[12] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}; /// распределение дней по месяцам в високосном году

            int i; /// счетчик
            int subproduct1 = 0; /// количество дней, прошедших в году рождения
            int subproduct2 = 0; /// количество дней, прошедших в текущем году
            int result = 0; /// количество прожитых дней
            /// Ввод данных и проверка их корректности
            cout << "Please, enter the date of birth" << endl;
            cin >> d1 >> m1 >> y1;

            while (!function_5(d1, m1, y1))
                cin >> d1 >> m1 >> y1;

            cout << "Please, enter the current date" << endl;
            cin >> d2 >> m2 >> y2;

            while (!function_5(d2, m2, y2))
                cin >> d2 >> m2 >> y2;
            /// Подсчет количества дней, прошедших в году рождения
            if (y1 % 4 != 0 || (y1 % 100 == 0 && y1 % 400 != 0))
                for (i = 0; i < m1-1; i++)
                    subproduct1+= month1[i];
            else
                for (i = 0; i < m1-1; i++)
                    subproduct1 += month2[i];
            subproduct1 += d1;
            /// Подсчет количества дней, прошедших в текущем году
            if (y2 % 4 != 0 || (y1 % 100 == 0 && y1 % 400 != 0))
                for (i = 0; i < m2-1; i++)
                    subproduct2 += month1[i];
            else
                for (i = 0; i < m2-1; i++)
                    subproduct2 += month2[i];
            subproduct2 += d2;
            /// Подсчет количества дней в промежуточных годах
            for (i = y1 + 1; i < y2; i++)
            {
                if (i % 4 != 0)
                    result += 365;
                else result += 366;
            }
            /// Получение результата в зависимости от входных данных
            if (y1 == y2)
                result += subproduct2 - subproduct1;
            else
            {
                if (y1 % 4 != 0 || (y1 % 100 == 0 && y1 % 400 != 0))
                    subproduct1 = 365 - subproduct1;
                else
                    subproduct1 = 366 - subproduct1;
                result += subproduct1 + subproduct2;
            }
            /// Вывод результа
            cout << result << endl;
            /// Вывод результатов обработки полученных данных функциями 1, 2 и 4
            cout << "1) " << function_1(result) << endl;
            cout << "2) ";
            if (result <= 46340)
                function_2(result);
            else
                cout << "Too large number" << endl;
            cout << "4) ";
            if (result < 1000000)
                function_4(result);
            else
                cout << "Too large number" << endl;
            break;
        }
    }
    return 0;
}

