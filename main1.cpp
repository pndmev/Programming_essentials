#include <iostream>
#include <cmath>

using namespace std;

const float PI = 3.14;

int main1()
{
	int number = 0; /// номер задачи
	cout << "Please, enter the number of task ( 1, 2, 3 )" << endl;
	cout << "1. Square in circle/circle in square" << endl;
	cout << "2. ax^2 + bx + c = 0 : x1,2 = ?" << endl;
	cout << "3. max_even(a1, a2, ..., an) = ?" << endl;
	/// Ввод номера задачи
	while (number == 0)
	{
		cin >> number;
		if (number < 1 || number > 3)
			number = 0;
	}
	/// Выбор задачи в соответствии со введенным номером
	switch (number)
	{
        case 1:
        {
            double sSquare = 0; /// площадь квадрата
            double sCircle = 0; /// площадь круга
            /// Ввод данных
            while (1)
            {
                cout << "Please, enter the square of a square" << endl;
                cin >> sSquare;
                if (sSquare > 0)
                    break;
                else cout << "Square > 0" << endl;
            }
            while (1)
            {
                cout << "Please, enter the square of a circle" << endl;
                cin >> sCircle;
                if (sCircle > 0)
                    break;
                else cout << "Square > 0" << endl;
            }
            double r2 = sCircle / PI; /// квадрат радиуса
            /// Проверка: уместится ли квадрат в круге?
            if (sSquare <= 2 * r2)
                cout << "a) YES" << endl;
            else cout << "a) NO" << endl;
            /// Проверка: уместится ли круг в квадрате?
            if (sSquare >= 4 * r2)
                cout << "b) YES" << endl;
            else cout << "b) NO" << endl;
            break;
        }
        case 2:
        {
            double a; /// старший коэффициент
            double b; /// средний коэфициент
            double c; /// свободный член
            /// Ввод данных
            cout << "ax^2 + bx + c = 0" << endl;
            cout << "a = ";
            cin >> a;
            cout << "b = ";
            cin >> b;
            cout << "c = ";
            cin >> c;
            /// Рассмотрение случаев линейного уравнения
            if (a == 0)
            {
                if (b != 0)
                    cout << (-1 * c) / b;
                else
                    if (c == 0)
                        cout << "x = R" << endl;
                    else
                        cout << "There aren't solutions of an equation" << endl;
            }
            /// Рассмотрение случаев квадратного уравнения
            else
            {
                double d = b * b - 4 * a * c;
                if (d >= 0)
                {
                    double x1;
                    double x2;
                    x1 = (-1 * b + sqrt(d)) / (2 * a);
                    x2 = (-1 * b - sqrt(d)) / (2 * a);
                    if (x1 == x2)
                        cout << x1;
                    else
                        cout << x1 << " " << x2;
                }
                else
                    cout << "There aren't solutions of an equation" << endl;
            }
            break;
        }
        case 3:
        {
            cout << "Please, enter integers. If you want to finish input, enter 0" << endl;
            int max = -1; /// максимальное значение
            int x; /// переменная
            bool flag; /// флаг
            /// Ввод данных и их обработка
            cin >> x;
            while (x != 0)
            {
                flag = !(x % 2);
                if (flag && ((max != -1 && x > max) || (max == -1)))
                    max = x;
                cin >> x;
            }
            if (max == -1)
                cout << "Not found" << endl;
            else
                cout << max << endl;
            break;
        }
	}
}
