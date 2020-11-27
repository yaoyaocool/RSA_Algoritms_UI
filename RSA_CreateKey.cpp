#include <iostream>
#include <math.h>
#include <time.h>

class KeyGenerator 
{
private:
	int* SimpleNumber;
	int Length = 0, p = 0, q = 0, n = 0, Euler = 0, e = 0;
	void SieveOfEratosthenes()
	{
		srand(clock());//
		Length = 3 + rand() % 3;// Создаем случайное число от 3 до 5!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
		Length = 1000*(1+rand() % 2);// Запишем в переменную Length 10 в степени случайного числа полученого выше
		SimpleNumber = new int[Length];// Создание динамического массива с размером Length
		for(int i = 0; i < Length; i++) // Заполняем динамический массив числами от 1 до Length включительно
		{
			if(i == 0) SimpleNumber[i] = -1; // Вычеркиваем первый эллемент из списка(однерка вычеркивается самая первая)
			else SimpleNumber[i] = i+1;
		}

		for(int i = 0; i < Length; i++)
		{
			if(SimpleNumber[i] == -1) continue; // если элемент вычеркнут идем дальше по списку
			for(int j = i+1; j < Length; j++) //Делим все элементы кратные SimpleNumber[i] и большие чем SimpleNumber[i] в квадрате, начиная со следующего эллемента от SimpleNumber[i]
			{
				if((SimpleNumber[i]*SimpleNumber[i]) > SimpleNumber[j]) continue; // Если проверяемое число меньше квадрата числа SimpleNumber[i], пропускаем т.к не подходит по условию
				if(SimpleNumber[j] % SimpleNumber[i] == 0) SimpleNumber[j] = -1;// Вычеркиваем т.к число не простое
			}
		}
	}

	void SieveOfEratosthenes(int _Length) // Override функции SieveOfEratosthenes
	{
		Length = _Length;
		SimpleNumber = new int[Length];// Создание динамического массива с размером Length

		for(int i = 0; i < Length; i++) // Заполняем динамический массив числами от 1 до Length включительно
		{
			if(i == 0) SimpleNumber[i] = -1; // Вычеркиваем первый эллемент из списка(однерка вычеркивается самая первая)
			else SimpleNumber[i] = i+1;
		}

		for(int i = 0; i < Length; i++)
		{
			if(SimpleNumber[i] == -1) continue; // если элемент вычеркнут идем дальше по списку
			for(int j = i+1; j < Length; j++) //Делим все элементы кратные SimpleNumber[i] и большие чем SimpleNumber[i] в квадрате, начиная со следующего эллемента от SimpleNumber[i]
			{
				if((SimpleNumber[i]*SimpleNumber[i]) > SimpleNumber[j]) continue; // Если проверяемое число меньше квадрата числа SimpleNumber[i], пропускаем т.к не подходит по условию
				if(SimpleNumber[j]%SimpleNumber[i] == 0) SimpleNumber[j] = -1;// Вычеркиваем т.к число не простое
			}
		}

		for(int i = 0; i < Length; i++) std::cout  << SimpleNumber[i] << std::endl;;
	}

	void SortSimpleNumber()
	{
		int CountSimpleNumber = 0;

		for(int i = 0; i < Length; i++)
		{
			if(SimpleNumber[i] == -1)
			{
				for(int j = i+1; j < Length; j++)
				{
					if(SimpleNumber[j] != -1)
					{
						SimpleNumber[i] = SimpleNumber[j];
						SimpleNumber[j] = -1;
						CountSimpleNumber++;
						break;
					}
				}
			}
		}
		Length = CountSimpleNumber;
	}

	int EulerFunction(int p, int q)
	{
		return (p-1)*(q-1);
	}

public:	
	KeyGenerator()
	{
		SieveOfEratosthenes();
		SortSimpleNumber();
	}

	KeyGenerator(int MaxNumber) // Override конструктора
	{
		SieveOfEratosthenes(MaxNumber);
		SortSimpleNumber();
	}

	~KeyGenerator() //Деструктор
	{
		delete[] SimpleNumber; // Удалим указатель на динамический массив
	}

	void CreatePublicKey()
	{
		srand(clock());
		p = SimpleNumber[rand() % Length];
		srand(clock());
		q = SimpleNumber[rand() % Length];
		n = p*q;

		std::cout << "p: " << p << std::endl;
		std::cout << "q: " << q << std::endl;
		std::cout << "n: " << n << std::endl;

		Euler = EulerFunction(p, q);
		std::cout << "Euler: " << Euler << std::endl;
		delete[] SimpleNumber;
		SieveOfEratosthenes(Euler-1);
		SortSimpleNumber();
		srand(clock());
		e = SimpleNumber[rand() % Length];




		std::cout << "e: " << e << std::endl;

	}

};

int main()
{
	KeyGenerator key; //Создание динамического объекта класса чтобы освободить нужную область памяти прямо во время вополнения программы
	key.CreatePublicKey();
	return 1;
}