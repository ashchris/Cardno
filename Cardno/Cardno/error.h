#pragma once
#include <iostream>
#include <string>

using namespace std;

void error_rep(string er_r);

void error_rep(string er_r) {
	string cont_er;
	cout << "An error has occurred:" << endl;
	cout << er_r << endl;
	cin >> cont_er;
}