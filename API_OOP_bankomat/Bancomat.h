#pragma once
class Bancomat
{
private:
	int banknotes[9];
	int countOfBanknotes[9];
	int backupMoney[9];
public:
	Bancomat();
	virtual ~Bancomat();
	int getBanknotes(int);
	int getCountOfBanknotes(int);
	int checkMoney(int sum);
};

