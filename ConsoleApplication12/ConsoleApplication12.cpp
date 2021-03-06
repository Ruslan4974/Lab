﻿// Шифр Виженера
// Санников Руслан, гр. ИТ-41

#include <iostream>
#include <string>

using namespace std;

int main()
{
	setlocale(LC_ALL, "Rus");
	string word, key, count;
	string alf = "abcdefghijklmnopqrstuvwxyz";
	string ALF = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

	cout << "Введите слово: ";
	cin >> word;
	cout << "Введите ключ: ";
	cin >> key;
	int* w = new int[word.length()]; //хранение номера (длины) символов слова
	int* k = new int[word.length()]; //хранение номера (длины) символов ключа

	//подгоняем ключ до длины слова
	if (word.length() >= key.length())
	{
		for (int i = 0; i < (word.length() / key.length()); i++)
		{
			count += key;
		}
		for (int j = 0; j < (word.length() % key.length()); j++)
		{
			count += key[j];
		}
	}
	else
	{//для длинного ключа
		for (int i = 0; i < word.length(); i++)
		{
			count += key[i];
		}
	}

	for (int i = 0; i < word.length(); i++)
	{
		for (int j = 0; j < 26; j++)
		{
			if ((word[i] == alf[j]) || (word[i] == ALF[j]))
			{
				w[i] = j;
			}
			if ((count[i] == alf[j]) || (count[i] == ALF[j]))
			{
				k[i] = j;
			}
		}
	}

	cout << "Для шифрования нажмите 1, для дешифрования нажмите 2: ";
	int var;
	cin >> var;
	switch (var)
	{
	case 1:
		for (int i = 0; i < word.length(); i++)
		{
			int ci = ((w[i] + k[i]) % 26);
			word[i] = alf[ci];
		}
		cout << "Зашифрованное слово: " << word << endl;
		break;

	case 2:
		for (int i = 0; i < word.length(); i++)
		{
			int mi = ((w[i] + 26 - k[i]) % 26);
			(word[i] = alf[mi]);
		}
		cout << "Дешифрованное слово: " << word << endl;
	default:
		break;
	}

	system("pause");
	return 0;
}