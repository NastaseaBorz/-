#pragma once
#include <iostream>

class mod
{
private:
	int n;    // ������ �� ������ ������ // module
	int a;    // �������� ����� // entered number

public:
	mod()
		:n(0), a(0)
	{}

	mod(int _n, int _a)
		:n(_n), a(_a)
	{}
	
	mod(const mod &) = default;

	mod& operator=(const mod &) = default;

	bool ifequival(const mod & b) const
	{
		if ((a % n) == (b.a % n))
		{
			return true;

		}
		else
		{
			return false;
		}
	}

	mod & inverse()
	{
		for (int i = 0; i < n; i++)
		{
			if (((a * i) % n) == 1)
			{
				a = i;
				return *this;
			}
		}
		std::cout << "doesn't exist " << std::endl;
		return *this;
	}

	mod & sum_equival()
	{
		for (int i = 0; i < n; i++)
			if (((a + i) % n) == 0)
			{
				a = i;
				return *this;
			}
	}

	int operator-(const mod & b)
	{
		return (n == b.n) ? ((a - b.a) % n) : n; // function never returns n working properly, then it would be an error signal
	}

	int operator+(const mod & b)
	{
		return (n == b.n) ? ((a + b.a) % n) : n; // function never returns n working properly, then it would be an error signal
	}

	int operator*(const mod & b)
	{
		return (n == b.n) ? ((a * b.a) % n) : n; // function never returns n working properly, then it would be an error signal
	}

	~mod()
	{
		std::cout << "destroy" << std::endl;
	}

};

