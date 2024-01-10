#include <iostream>

void KeyExpension() {}
void InitialRound() {}

void SubBytes() {}
void ShiftRows() {}
void MixColums() {}
void AddRoundKey() {}


void AES_Encrypt()
{
	int numberOfRounds = 1;

	KeyExpension();
	InitialRound();

	//Rounds
	for (int i = 0; i < numberOfRounds;i++)
	{
		SubBytes();
		ShiftRows();
		MixColums();
		AddRoundKey();
	}
	//Final round
	SubBytes();
	ShiftRows();
	AddRoundKey();
}

int main()
{
	char message[] = "This is message that we will encrypt with AES";
	char key[16] =
	{
		1, 2, 3, 4,
		5, 6, 7, 8,
		9, 10, 11, 12,
		13, 14, 15, 16
	};

	AES_Encrypt();

	return 0;
}