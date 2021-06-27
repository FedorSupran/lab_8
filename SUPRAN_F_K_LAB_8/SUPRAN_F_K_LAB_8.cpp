#include <iostream>
#include <cmath>
#include <string>
#include <vector>
#include <functional>
/*
* Восьмая лабораторная работа
* Автор: Супран Федор Константинович
* Группа: ПИ2-2
*/

/*
* Составить программу, которая будет считывать введённое пятизначное число. 
* После чего, каждую цифру этого числа необходимо вывести в новой строке.
*/
void func1()
{
	system("cls");
	int x;
	std::cout << "Введите пятизначное число: ";
	std::cin >> x;
	std::cout << "Цифры данного числа: \n";
	for (int i = 4; i >= 0; i--)
		std::cout << (x / (int(pow(10, i)))) % 10 << std::endl;

	std::cout << "Для возврата в меню нажмите любую клавишу...";
	std::cin.ignore();
	std::cin.get();
}
/*
* Напишите программу, которая позволяет пользователю ввести в консоли 
* латинскую букву нижнего регистра, переводит её в верхний регистр и результат
* выводит в консоль
*/
void func2()
{
	system("cls");
	char ch;
	std::cout << "Введите латинскую букву нижнего регистра: ";
	std::cin >> ch;
	ch = toupper(ch);
	std::cout << "Введенная латинская буква в верхнем регистре: " << ch << std::endl;

	std::cout << "Для возврата в меню нажмите любую клавишу...";
	std::cin.ignore();
	std::cin.get();
}
/*
* Написать функцию, подсчитывающую среднее арифметическое целого массива. 
* Предварительно объявив и, при необходимости, инициализировав переменные.
*/
double arithmeticMeanofTheArray(double* arr, int size)
{
	double sum = 0;
	for (size_t i = 0; i < size; i++)
		sum += arr[i];
	return sum / size;
}
void func3()
{
	system("cls");
	int size;
	std::cout << "Введите размер массива: ";
	std::cin >> size;
	double* arr = new double[size];
	std::cout << "Заполните массив: ";
	for (size_t i = 0; i < size; i++)
		std::cin >> arr[i];
	std::cout << "Среднее арифметическое массива: " << arithmeticMeanofTheArray(arr, size) << std::endl;

	std::cout << "Для возврата в меню нажмите любую клавишу...";
	std::cin.ignore();
	std::cin.get();
}
/*
* Меню для выбора функций
*/
void showMenu(std::vector<std::string> titleVector, std::vector<std::function<void()>> fVector)
{
	while (true)
	{
		system("cls");
		int choice = 0;
		std::cout << "============================\n";
		std::cout << "============Меню============\n";
		std::cout << "============================\n";
		for (size_t i = 0; i < titleVector.size(); i++)
			std::cout << i + 1 << ") " << titleVector[i] << std::endl;
		std::cout << "Введите номер выбранной задачи: ";
		std::cin >> choice;
		if (choice - 1 < 0 || choice - 1 >= titleVector.size())
			break;
		else
			fVector[choice - 1]();
	}
}
int main()
{
	setlocale(LC_ALL, "ru");
	std::vector<std::string> titleVector =
	{
		"Вывод цифр пятизначного числа.",
		"Поменять регистр буквы с нижнего на верхний.",
		"Среднее арифметическое целого массива."
	};
	std::vector<std::function<void()>> fVector = { func1, func2, func3 };
	showMenu(titleVector, fVector);
	return 0;
}