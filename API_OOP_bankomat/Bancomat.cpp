#include "stdafx.h"
#include "Bancomat.h"

Bancomat::Bancomat()
{
	banknotes[0] = 500;
	banknotes[1] = 200;
	banknotes[2] = 100;
	banknotes[3] = 50;
	banknotes[4] = 20;
	banknotes[5] = 10;
	banknotes[6] = 5;
	banknotes[7] = 2;
	banknotes[8] = 1;
	for (int i = 0; i < 9; i++)
		countOfBanknotes[i] = rand() % 10;
}


Bancomat::~Bancomat()
{
}


int Bancomat::getBanknotes(int i)
{
	return banknotes[i];
}


int Bancomat::getCountOfBanknotes(int i)
{
	return countOfBanknotes[i];
}


int Bancomat::checkMoney(int sum)
{
	int returnSum = 0, i;
	
	for (i = 0; i<9; i++)
		backupMoney[i] = 0;

	for (i = 0; i < 9; i++)
	{
		if (sum > banknotes[i] && countOfBanknotes[i] > 0)
		{
			while ((sum - returnSum) >= banknotes[i] && countOfBanknotes[i] > 0)
			{
				returnSum += banknotes[i];
				countOfBanknotes[i]--;
				backupMoney[i]++;
			}
		}
	}

	for (i = 0; i < 9; i++)
	{
		countOfBanknotes[i] += backupMoney[i];
		backupMoney[i] = 0;
	}

	if (sum == returnSum)
		return 0;
	else
		return 1;
}
