#pragma once
#include <iostream>

class mod
{
private:
	int n;    // вычеты по какому модулю
	int a;    // вводимое число

public:
	mod()
		:n(0), a(0)
	{}

	mod(int _n, int _a)
		:n(_n), a(_a)
	{}
	
	mod(const mod &) = default;

	mod& operator=(const mod &) = default;

	int inverse()
	{
		for (int i = 0; i < n; i++)
		{
			if (((a * i) % n) == 1)
			{
				return i;
			}
		}
		std::cout << "обратного не существует" << std::endl;
		return 0;
	}

	int equival()
	{
		for (int i = 0; i < n; i++)
			if (((a + i) % n) == 0)
			{
				return i;
			}
	}

	int operator-(const mod & b)
	{
		return (n == b.n) ? ((a - b.a) % n) : n; // при правильной работе оператора функция никогда не вернет n, значит это будет сигналом об ошибке
	}

	int operator+(const mod & b)
	{
		return (n == b.n) ? ((a + b.a) % n) : n; // при правильной работе оператора функция никогда не вернет n, значит это будет сигналом об ошибке
	}

	int operator*(const mod & b)
	{
		return (n == b.n) ? ((a * b.a) % n) : n; // при правильной работе оператора функция никогда не вернет n, значит это будет сигналом об ошибке
	}

	~mod()
	{
		std::cout << "destroy" << std::endl;
	}

};

