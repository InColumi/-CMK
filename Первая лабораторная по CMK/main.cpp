#include <iostream>

using namespace std;

void ShowNumbers(int * arr, int size)
{
	for(int i = 0; i < size; i++)
	{
		cout << arr[i] << ' ';
	}
	cout << '\n';
}

int main()
{
	int countOfNumbers = 50;
	int* arrayWhithNumbers = new int[countOfNumbers];

	// Заполнение массива числами от 1 до N
	for(int i = 0; i < countOfNumbers; i++)
	{
		arrayWhithNumbers[i] = i + 1;
	}
	ShowNumbers(arrayWhithNumbers, countOfNumbers);

	//начало методота "Решето Эратосфена"
	int countOfZero = 0;
	for(int i = 1; i < countOfNumbers; i++)
	{
		for(int j = i + 1; j < countOfNumbers; j++)
		{
			if(arrayWhithNumbers[i] != 0 &&
			   arrayWhithNumbers[j] != 0 &&
			   arrayWhithNumbers[j] % arrayWhithNumbers[i] == 0)
			{
				arrayWhithNumbers[j] = 0;
				countOfZero++;
			}
		}
	}

	//Удаление нулей из массива
	int size = countOfNumbers - countOfZero;
	int* newArrayWithNumbers = new int[size];
	int j = 0;
	for(int i = 0; i < countOfNumbers; i++)
	{
		if(arrayWhithNumbers[i] != 0)
		{
			newArrayWithNumbers[j++] = arrayWhithNumbers[i];
		}
	}
	arrayWhithNumbers = newArrayWithNumbers;

	// Вывод результат
	ShowNumbers(arrayWhithNumbers, size);
	return 0;
}


