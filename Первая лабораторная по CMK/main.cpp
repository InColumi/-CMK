#include <iostream>
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
	for(int i = 2; i <= numberEnd; i++)
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

int GetBinaryPow(int number, int pow, int mod)
{
	vector<int> numberInBinary = GetNumberFromDecimalToBinary(pow);
	int result = 1;
	for(int i = 0; i < numberInBinary.size(); i++)
	{
		int result2 = Modul(result * result, mod);
		result = (numberInBinary[i] == 0) ? result2 : Modul(result2 * number, mod);
	}

	return result;
}
// Конец Бинарного возведение в степень

// Миллер Рабин

bool IsPositive(int number)
{
	if(number <= 0)
	{
		cout << "Number is not positive!\n";
		exit(1);
	}
	return true;
}

bool IsOddNumber(int number)
{
	IsPositive(number);
	if(number % 2 == 0)
	{
		cout << "Number is even!\n";
		exit(1);
	}
	return true;
}

int GetS(int number)
{
	IsOddNumber(number);
	int count = 0;
	number -= 1;
	while(number != 1)
	{
		number /= 2;
		++count;
	}
	return count;
}

void ShowMillerRabin(int number, int countOfTries, int x)
{
	int s = GetS(number);
	int t = number - 1;

	int randNumber;
	for(int i = 0; i < countOfTries; i++)
	{
		randNumber = x;
		int y = GetBinaryPow(randNumber, t, number);

		if(y == 1 || y == number - 1)
			continue;
		cout << "x = " << x << "\n";
		for(int j = 1; j < s; j++)
		{
			cout << "\ty" << j << " = " << y << "\n";
			y = Modul(y * y, number);

			if(y == 1)
				cout << number << " is  not prime!\n";

			if(y == number - 1)
				break;
		}

		if(y != number - 1)
			cout << number << " is not prime!\n";
	}
	cout << "" << number << " is prime!\n";
}
// Конец Миллера Рабина

int main()
{
	//ShowPrimeNumbers(9999999999);

	//GetBinaryPow(2, 5, 10);

	ShowMillerRabin(17, 1, 3);
	return 0;
}