#pragma once
#include <iostream>

class mod
{
private:
	int n;    // ������ �� ������ ������
	int a;    // �������� �����

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
		std::cout << "��������� �� ����������" << std::endl;
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
		return (n == b.n) ? ((a - b.a) % n) : n; // ��� ���������� ������ ��������� ������� ������� �� ������ n, ������ ��� ����� �������� �� ������
	}

	int operator+(const mod & b)
	{
		return (n == b.n) ? ((a + b.a) % n) : n; // ��� ���������� ������ ��������� ������� ������� �� ������ n, ������ ��� ����� �������� �� ������
	}

	int operator*(const mod & b)
	{
		return (n == b.n) ? ((a * b.a) % n) : n; // ��� ���������� ������ ��������� ������� ������� �� ������ n, ������ ��� ����� �������� �� ������
	}

	~mod()
	{
		std::cout << "destroy" << std::endl;
	}

};

