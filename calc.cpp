#include<iostream>
using namespace std;

int hour_1, min_1, sec_1, hour_2, min_2, sec_2; //�����

int diff;

float hour, minute, second;

char operation; int edin; int perevod;//��� ������

int main()
{

	setlocale(LC_ALL, "Russian");

	cout << "������! ����� ���������� � 'Time calculator' ������ 1.0!\n\n ";
	cout << "�������� ������� ��������� �������, ������� ������ ������: \n ";
	cout<<" 1 - ���, 2 - ������, 3 - �������. \n >> ";
		cin >> edin;
	
	switch (edin)
	{
	case 1:
		cout << "������� 1�� ���: ";
		cin >> hour_1;
		cout << "������� 2�� ���: ";
		cin >> hour_2;
		break;

	case 2:
		cout << "������� 1�� ������: ";
		cin >> min_1;
		cout << "������� 2�� ������: ";
		cin >> min_2;
		break;
	case 3:
		cout << "������� 1�� �������: ";
		cin >> sec_1;
		cout << "������� 2�� �������: ";
		cin >> sec_2;
		break;

	default:
		cout << "Error\n";
		break;
	}
	

	//��� �� ��������� �� ����� � �������, ����� ����� ��������� � ������ ��:��:��.
	int in_sec_1 = hour_1 * 3600 + min_1 * 60 + sec_1;
	int in_sec_2 = hour_2 * 3600 + min_2 * 60 + sec_2;
	
	
	cout << "'+' ��� '-'\n >>";
	cin >> operation;

	switch (operation) 
	{
	
	case '-':
		cout << "��������: ";
		diff = in_sec_1 - in_sec_2;
		hour = diff / 3600;
		diff %= 3600;
		 minute = diff / 60;
		diff %= 60;
		 second = diff;
		break;
	
	case '+':
		cout << "�����: ";
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

	cout << "�������� � ����� ������� ��������� ������� ����� �������������, ���������� �����: \n";
	cout << "1 - � ����, 2 - � ������, 3 - � �������.\n >> ";
	cin >> perevod;
	
	switch (perevod)
	{
		cout << "Time: ";
	
	case 1:
		cout << "���� >> ";
		cout << hour + (minute/60) + (second/3600);
		break;
	
	case 2:
		cout << "������ >> ";
		cout << (hour*60) + minute + (second/60);
		break;
	
	case 3:
		cout << "������ >> ";
		cout << (hour * 3600) + (minute*60) + second;
		break;
	
	default:
		cout << "Error\n";
		break;
	}

	return hour, minute, second;
	
}