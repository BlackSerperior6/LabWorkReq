#include <iostream>
#include <iomanip>

using namespace std;


int factorial(int number) //Функция для нахождения факториала
{
	if (number == 0 || number == 1) //Если число = 1 или 0, то его факториал равен 1
		return 1;

	return sqrt(2 * 3.14 * number) * pow(number, number) * (0.46082949308); //Иначе рассчитываем примерный факториал по формуле Стирлинга, где 2 - константа формулы, 3,14 - число P, 0.46082949308 пимерно равно e^-1
}

double recursive(double x, int maxN, int n = 1) //Рекурсивная функция
{
	if (n >= maxN) //Условие выхода - достижением счетчика n последнего номера в последовательности. В таком случае возвращаем 1.0
		return 1.0;

	double res = (((double) (n * n + 1)) / (factorial(n))) * pow(x / 2, n); //Считаем элемент последовательности по текущему n
	return res += recursive(x, maxN, ++n); //Прибавляем к результату следующий элемент через рекурсивный вызов
}

int main()
{
	setlocale(LC_ALL, "rus"); //Подключаем русскую локализацию

	//Объявляем нужные переменные - x, кол-во элементов, переменную суммы и т.д.
	double x;
	int numberOfElements;
	int precition;
	double sum = 1.0;
	time_t startIterarive, endIterative;
	time_t startReqursive, endReqursive;

	cout << "Введите 3 параментра: x, кол-во элементов последовательности, кол-во цифр после запятой в ответе" << endl;

	cin >> x >> numberOfElements >> precition; //Пользователь вводит параметры

	if (numberOfElements < 1) //Проверка параметра кол-ва элементов последовательности на валидность
	{
		cout << "Кол-во элементов в последовательности должено быть >= 1" << endl;
		return 0;
	}

	cout << setprecision(precition); //Установка точности вывода в консоль

	time(&startIterarive); //Включаем таймер на выполнение задачи итерационным циклом
	
	for (int i = 1; i < numberOfElements + 1; i++) //Сам цикл. Начинается с i = 1. Длится до тех пор, пока не прибавит к сумме все сгенерированные элементы последовательности
		sum += (((double) (i * i + 1)) / (factorial(i))) * pow(x / 2, i); 

	time(&endIterative); //Выключаем таймер

	cout << "Сумма, полученная через итерационное решение: " << sum << endl;

	time(&startReqursive); //Запускаем таймер для рекурсивной функции
	sum = recursive(x, numberOfElements + 1); //Вызываем рекурсивную функцию
	time(&endReqursive); //Выключаем таймер

	//Выводим данные в консоль (время работы, сумму, полученную через рекурсию и т.д.)
	cout << "Сумма, полученная через рекурсивное решение: " << sum << endl;

	cout << endl << endl;

	cout << "Время работы итерационного решения: " << difftime(endIterative, startIterarive) << endl;
	cout << "Время работы рекурсивного решения: " <<  difftime(endReqursive, startReqursive) << endl;
}
