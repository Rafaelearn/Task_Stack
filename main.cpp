#include <iostream>
#include "Stack.h"


using namespace std;
bool CheckEpression(string input);
bool CheckArrangement(string input, char openChar, char closeChar);


int main() {
	setlocale(LC_ALL, "rus");
	string input;
	cout<< "������� ���������: ";
	cin >> input;
	if (CheckEpression(input)) {
		cout << "��������� ���������!";
	}

	return 0;
}
bool CheckEpression(string input) {
	bool flagCorrect = true;
	if (!CheckArrangement(input, '(', ')')) flagCorrect = false;
	if (!CheckArrangement(input, '{', '}')) flagCorrect = false;
	if (!CheckArrangement(input, '[', ']')) flagCorrect = false;
	if (!CheckArrangement(input, '<', '>')) flagCorrect = false;
	return flagCorrect;
}
bool CheckArrangement(string input, char openChar, char closeChar)
{
	elem* stack = nullptr;// ��� �������� ����������� ������
	int lastOpenChar = 0;
	for (int i = 0; i <= input.size(); i++)
	{
		if (input[i] == openChar)
		{
			push(*&stack, openChar);
			lastOpenChar == i;
		}
		if (input[i] == closeChar)
		{
			if (stack)
			{
				pop(*&stack);
			}
			else
			{
				cout << "��� ������: ������������� ������ ' " << closeChar << " '" <<
					endl << "\t����� �������������� ������: " << i<< endl;
				return false;
			}
		}
	}
	if (stack)
	{
		cout << "��� ������: ������ ������������� ������ ' " << closeChar << " '"<<
			endl << "\t����� �������������� ������: " << lastOpenChar<<endl;
		return false;
	}
	return true;
}