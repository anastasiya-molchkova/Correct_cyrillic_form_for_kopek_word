/* Напишите программу, которая при вводе пользователем числа из диапазона от 1 до 99, 
   добавляет к нему слово копейка в правильной форме. */

#include <iostream>
#include <string>
using std::cout; using std::cin; using std::endl;
using std::string;

const unsigned short get_number_from_1_to_99()
{
	cout << "Введите целое число от 1 до 99: ";
	int number{ 0 };
	cin >> number;
	while (cin.fail() || (number < 1) || (number > 99))
	{
		cin.clear();
		cin.ignore(1000, '\n');
		cout << "Вы ввели что-то не то, введите целое число от 1 до 99: ";
		cin >> number;
	}
	return static_cast<unsigned short>(number);
}

const string word_kopeyka_in_the_right_form(const unsigned short number)
{
	if ((number == 1) || ((number > 20) && ((number % 10) == 1)))
		return "копейка";
	if ((number < 5) || ((number > 20) && ((number % 10) < 5)))
		return "копейки";
	return "копеек";
}

int main()
{
	setlocale(LC_CTYPE, "rus"); // для вывода сообщений на кириллице
	
	while (true)
	{ 
		unsigned int number{ get_number_from_1_to_99() };
		cout << number << " " << word_kopeyka_in_the_right_form(number) << endl << endl;
	}
	return 0;
}