#include<iostream>
#include<vector>
#include <windows.h>
#include <iomanip>
using namespace std;
int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int k;
	double sum,s=0;

	vector<int> kef;
	cout << "Введите колличество критериев: " << endl;
input:
	cin >> k;
	if (!cin)
	{
		cin.clear();
		cin.ignore(50, '\n');
		cout << "Ошибка в вводе кол-ва критериев, попробуйте снова." << endl;
		goto input;
	}
	double**A = new double* [k];
	double* B = new double[k];
	for (int i = 0;i < k;i++)
	A[i] = new double[k];
	for (int i = 0;i < k;i++)
		A[i][i] = 1;
	inputel:
		for(int i=0;i<k;i++)
			for (int j = i + 1;j < k;j++)
			{
				cout << "Введите отношение элемента " << (i + 1) << " к элементу " << (j + 1) << ": " <<endl;
				cin >> A[i][j];
				if (!cin)
				{
					cin.clear();
					cin.ignore(50, '\n');
					cout << "Ошибка в вводе отношения элементов, попробуйте снова." << endl << endl;
					goto inputel;
				}
				A[j][i] = 1 / A[i][j];
				
			}
		for (int j = 0;j < k;j++)
		{
			sum = 0;
			for (int i = 0;i < k;i++)
			{
				sum += A[i][j];
			}
			B[j] = sum;
			s += sum;
		}
		sum = 0;
		cout << endl;
		for (int i = 0;i < k;i++)
		{
			B[i] /= s;
			cout << "Весовой коэффицент элемента " << i + 1 << " равен: " << fixed << setprecision(2) << B[i] <<endl;
		}
}