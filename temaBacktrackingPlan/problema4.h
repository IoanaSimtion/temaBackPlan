using namespace std;
#include <iostream>
#include <fstream>
#pragma once

//sa se determine nr de puncte de pe fontiera obiectului din care face parte punctul citit in planul XoY

ifstream f("imagine.txt");

int imagine[20][20], n, m, sol[20][20], ct = 0, nrPuncte = 0, x, y;
int dx[8] = { -1, +1, 0, 0, -1, +1, +1, -1 };
int dy[8] = { 0, 0, -1, 1, +1, +1, -1, -1 };

void citire() {
	f >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			f >> imagine[i][j];
		}
	}
	cout << "Introduceti coordonatele punctului: " << endl;
	cin >> x >> y;
}

//void afisare() {
//	cout << "solutia " << ct << endl << endl;
//	for (int i = 0; i < n; i++) {
//		for (int j = 0; j < n; j++) {
//			cout << sol[i][j];
//		}
//		cout << endl;
//	}
//	cout << endl;
//	ct++;
//}

void rec(int i, int j) {
	int imax, jmax, k;
	for (k = 0; k < 8; k++) {
		imax = i + dx[k];
		jmax = j + dy[k];
		if (imagine[imax][jmax] == 1) {
			nrPuncte++;
			rec(imax, jmax);
		}
	}
}

void solutie4() {
	citire();
	rec(x, y);
	cout << nrPuncte;
}