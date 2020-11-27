#include <iostream>
#include <math.h>
#include <time.h>

class KeyGenerator 
{
private:
	int* SimpleNumber;
	int Length, p, q;
	void SieveOfEratosthenes()
	{
		srand(time(NULL));//
		Length = 3 + rand() % 3;// Создаем случайное число от 3 до 5
		Length = pow(10, Length);// Запишем в переменную Length 10 в степени случайного числа полученого выше
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
	}

	/*void SortSimpleNumber
	{

	}*/
public:	
	KeyGenerator()
	{
		SieveOfEratosthenes();
	}

	KeyGenerator(int MaxNumber) // Override конструктора
	{
		SieveOfEratosthenes(MaxNumber);
	}

	~KeyGenerator() //Деструктор
	{
		delete[] SimpleNumber; // Удалим указатель на динамический массив
	}

	/*void CreatePublicKey()
	{
		srand(clock());
		p = SimpleNumber[rand() % Length];
		q = SimpleNumber[rand() % Length];

		std::cout << p << std::endl;
		std::cout << q << std::endl;
	}*/

};

int main()
{
	KeyGenerator key; //Создание динамического объекта класса чтобы освободить нужную область памяти прямо во время вополнения программы
	//key.CreatePublicKey();
	return 1;
}