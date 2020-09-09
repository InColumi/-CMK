#include <iostream>
#include <list>

using namespace std;
// Вспомогательные функции

// Вывести массив
void ShowArray(int* arr, int size)
{
	for(int i = 0; i < size; i++)
	{
		cout << arr[i] << " ";
	}
}

// Деление по модулю
int Modul(int number, int modul)
{
	int newNumber = number % modul;
	return (newNumber < 0)? newNumber + modul : newNumber;
}
// Конец вспомогательных функций

// Алгоритм Эратосфена
bool IsPrime(int number)
{
	for(int i = 2; i <= (int) sqrt(number); i++)
	{
		if(number % i == 0)
		{
			return false;
		}
	}
	return true;
}
void ShowPrimeNumbers(int numberEnd)
{
	for(int i = 2; i < numberEnd; i++)
	{
		if(IsPrime(i))
		{
			cout << i << ", ";
		}
	}
	cout << '\n';
}
// Конец алгоритма Эратосфена

// Бинарное возведение в степень
void AddToArray(int*& arr, int size, int newElement)
{
	int* newArray = new int[size + 1];
	for(int i = 0; i < size; i++)
	{
		newArray[i] = arr[i];
	}
	newArray[size] = newElement;
	arr = newArray;
}

void ReverseArray(int*& arr, int size)
{
	int* newArray = new int[size];
	for(int i = 0; i < size; i++)
	{
		newArray[i] = arr[size - i - 1];
	}
	arr = newArray;
}

int* GetNumberFromDecimalToBinary(int numberDecimal, int& sizeNewArray)
{
	int size = 0;
	int* numberInBinary = new int[size];
	int number10 = numberDecimal;
	while(number10 >= 1)
	{
		AddToArray(numberInBinary, size, number10 % 2);
		size++;
		number10 /= 2;
	}
	ReverseArray(numberInBinary, size);
	sizeNewArray = size;
	return numberInBinary;
}

void ShowBinaryPow(int number, int pow, int mod)
{
	int sizeNumberInBinary;
	int* numberInBinary = GetNumberFromDecimalToBinary(number, sizeNumberInBinary);
	int result = 1;
	for(int i = 0; i < sizeNumberInBinary; i++)
	{
		int result2 = Modul(result * result, mod);
		if(numberInBinary[i] == 0)
		{
			result = result2;
		}
		else
		{
			result = Modul(result2 * number, mod);
		}
	}

	cout << result << '\n';
}
// Конец Бинарного возведение в степень



int main()
{
	int countOfNumbers = 50;

	ShowPrimeNumbers(10);

	//ShowBinaryPow(33, 9, 5);
	return 0;
}


