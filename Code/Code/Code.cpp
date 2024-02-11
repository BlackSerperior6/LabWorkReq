#include <iostream>
#include <iomanip>
#include <chrono>

using namespace std;


int factorial(int number) //Функция для нахождения факториала
{
	if (number == 0 || number == 1) //Если число = 1 или 0, то его факториал равен 1
		return 1;

	return sqrt(2 * 3.14 * number) * pow(number, number) * (0.46082949308); //Иначе рассчитываем примерный факториал по формуле Стирлинга, где 2 - константа формулы, 3,14 - число P, 0.46082949308 пимерно равно e^-1
}

double recursive(double x, int n) //Рекурсивная функция
{
	if (n <= 0) //Условие выхода - достижением счетчика n значения 0. В таком случае возвращаем 1.0
		return 1.0;

	double res = (((double) (n * n + 1)) / (factorial(n))) * pow(x / 2, n); //Считаем элемент последовательности по текущему n
	return res + recursive(x, n - 1); //Прибавляем к результату следующий элемент через рекурсивный вызов
}

int main()
{
	setlocale(LC_ALL, "rus"); //Подключаем русскую локализацию

	//Объявляем нужные переменные - x, кол-во элементов, переменную суммы и т.д.
	double x;
	int numberOfElements;
	int precition;
	double sum = 1.0;
	chrono::steady_clock::time_point startIterarive, endIterative;
	chrono::steady_clock::time_point startReqursive, endReqursive;

	cout << "Введите 3 параментра: x, кол-во элементов последовательности, кол-во цифр после запятой в ответе" << endl;

	cin >> x >> numberOfElements >> precition; //Пользователь вводит параметры

	if (numberOfElements < 1) //Проверка параметра кол-ва элементов последовательности на валидность
	{
		cout << "Кол-во элементов в последовательности должено быть >= 1" << endl;
		return 0;
	}

	cout << setprecision(precition); //Установка точности вывода в консоли

	startIterarive = chrono::high_resolution_clock::now(); //Включаем таймер на выполнение задачи итерационным циклом
	
	for (int i = 1; i < numberOfElements + 1; i++) //Сам цикл. Начинается с i = 1. Длится до тех пор, пока не прибавит к сумме все сгенерированные элементы последовательности
		sum += (((double) (i * i + 1)) / (factorial(i))) * pow(x / 2, i); 

	endIterative = chrono::high_resolution_clock::now(); //Выключаем таймер

	cout << "Сумма, полученная через итерационное решение: " << sum << endl;

	startReqursive = chrono::high_resolution_clock::now(); //Запускаем таймер для рекурсивной функции
	sum = recursive(x, numberOfElements); //Вызываем рекурсивную функцию
	endReqursive = chrono::high_resolution_clock::now(); //Выключаем таймер

	//Выводим данные в консоль (время работы, сумму, полученную через рекурсию и т.д.)
	cout << "Сумма, полученная через рекурсивное решение: " << sum << endl;

	cout << endl << endl;

	cout << "Время работы итерационного решения: " << (endIterative - startIterarive).count() << endl;
	cout << "Время работы рекурсивного решения: " <<  (endReqursive - startReqursive).count() << endl;
}
