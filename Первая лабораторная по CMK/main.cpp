#include <iostream>
#include <list>
#include <vector>

using namespace std;
// Вспомогательные функции

// Вывести массив
template<class T>
void ShowArray(vector<T> arr)
{
	for(int i = 0; i < arr.size(); i++)
	{
		cout << arr[i] << " ";
	}
	cout << '\n';
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
vector<int> GetNumberFromDecimalToBinary(int numberDecimal)
{
	vector<int> numberInBinary;
	int number10 = numberDecimal;

	while(number10 >= 1)
	{
		numberInBinary.push_back(number10 % 2);
		number10 /= 2;
	}
	// инверсия вектора
	int size = numberInBinary.size();
	for(int i = 0; i < size / 2; i++)
	{
		int temp = numberInBinary[i];
		numberInBinary[i] = numberInBinary[size - 1 - i];
		numberInBinary[size - 1 - i] = temp;
	}
	return numberInBinary;
}

void ShowBinaryPow(int number, int pow, int mod)
{
	vector<int> numberInBinary = GetNumberFromDecimalToBinary(pow);
	int result = 1;
	for(int i = 0; i < numberInBinary.size(); i++)
	{
		int result2 = Modul(result * result, mod);
		result = (numberInBinary[i] == 0) ? result2 : Modul(result2 * number, mod);
	}

	cout << result << '\n';
}
// Конец Бинарного возведение в степень



int main()
{
	int countOfNumbers = 50;
	//ShowPrimeNumbers(10);

	ShowBinaryPow(2, 16, 100000);
	return 0;
}


