#pragma once

#include <iostream>
using namespace std;

namespace MyInputLib
{
	int ReadNumber()
	{
		int Number;

		cout << "Please,Enter Your Number?" << endl;
		cin >> Number;

		return Number;
	}
}