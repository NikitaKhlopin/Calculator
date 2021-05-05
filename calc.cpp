#include<iostream>
using namespace std;

int hour_1, min_1, sec_1, hour_2, min_2, sec_2; //Время

int diff;

float hour, minute, second;

char operation; int edin; int perevod;//Для кейсов

int main()
{

	setlocale(LC_ALL, "Russian");

	cout << "Привет! Добро пожаловать в 'Time calculator' версия 1.0!\n\n ";
	cout << "Выберите единицу измерения времени, которую хотите ввести: \n ";
	cout<<" 1 - час, 2 - минута, 3 - секунда. \n >> ";
		cin >> edin;
	
	switch (edin)
	{
	case 1:
		cout << "Введите 1ый час: ";
		cin >> hour_1;
		cout << "Введите 2ой час: ";
		cin >> hour_2;
		break;

	case 2:
		cout << "Введите 1ые минуты: ";
		cin >> min_1;
		cout << "Введите 2ые минуты: ";
		cin >> min_2;
		break;
	case 3:
		cout << "Введите 1ые секунды: ";
		cin >> sec_1;
		cout << "Введите 2ые секунды: ";
		cin >> sec_2;
		break;

	default:
		cout << "Error\n";
		break;
	}
	

	//Тут мы переводим всё время в секунды, чтобы потом перевести в формат ЧЧ:ММ:СС.
	int in_sec_1 = hour_1 * 3600 + min_1 * 60 + sec_1;
	int in_sec_2 = hour_2 * 3600 + min_2 * 60 + sec_2;
	
	
	cout << "'+' или '-'\n >>";
	cin >> operation;

	switch (operation) 
	{
	
	case '-':
		cout << "Разность: ";
		diff = in_sec_1 - in_sec_2;
		hour = diff / 3600;
		diff %= 3600;
		 minute = diff / 60;
		diff %= 60;
		 second = diff;
		break;
	
	case '+':
		cout << "Сумма: ";
		diff = in_sec_2 + in_sec_1;
		 hour = diff / 3600;
		diff %= 3600;
		 minute = diff / 60;
		diff %= 60;
		 second = diff;

		break;

	default:
		cout << "Error\n";
	}

	cout << hour << ":" << minute << ":" << second << '\n';

	cout << "Выберите в какую единицу измерения времени нужно преобразовать, полученное время: \n";
	cout << "1 - в часы, 2 - в минуты, 3 - в секунды.\n >> ";
	cin >> perevod;
	
	switch (perevod)
	{
		cout << "Time: ";
	
	case 1:
		cout << "Часы >> ";
		cout << hour + (minute/60) + (second/3600);
		break;
	
	case 2:
		cout << "Минуты >> ";
		cout << (hour*60) + minute + (second/60);
		break;
	
	case 3:
		cout << "Минуты >> ";
		cout << (hour * 3600) + (minute*60) + second;
		break;
	
	default:
		cout << "Error\n";
		break;
	}
system("cls");
	return hour, minute, second;
	
}
