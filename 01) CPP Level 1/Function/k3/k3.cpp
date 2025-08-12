
#include <iostream> 
#include <string>
using namespace std;

double Function(double N1, double N2)
{ 
	double const PI = 3.14;
	return PI * (pow(N2, 2) / 4) * (((2 * N1) - N2) / ((2 * N1) + N2));

}

	int main()
	{

		double N1, N2;
		cin >> N1;
		cin >> N2;
		cout << Function(N1, N2);


	}