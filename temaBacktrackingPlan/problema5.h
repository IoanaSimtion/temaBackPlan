using namespace std;
#include <iostream>
#include <fstream>
#pragma once

ifstream f("sah.txt");

//toate punctele pe care un cal le poate atinge in matrice, pe tabla de sah

int n, sah[20][20], x, y, ct, sol[20][20];
int dx[] = { -2,-1,1,2,2,1,-1,-2 }, dy[] = { 1,2,2,1,-1,-2,-2,-1 };
 


void citire() {
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			f >> sah[i][j];
		}
	}
	cout << "Introduceti pozitia calului: " << endl;
	cin >> x >> y;
}

void afisare() {
	cout << "solutia " << ct << endl << endl;
	int i, j;
	for (i = 0; i < 8; i++) {
		for (j = 0; j < 8; j++) {
			cout << sol[i][j];
		}
		cout << endl;
	}
	cout << endl;
	ct++;
}

void rec(int i, int j, int pas) {
	int imax, jmax, k;
	for (k = 0; k < 8; k++) {
		imax = i + dx[k];
		jmax = j + dy[k];
		if (sah[imax][jmax] < 2 && sol[imax][jmax] == 0) {
			sol[imax][jmax] = pas;
			/*if () {

			}*/
			rec(imax, jmax, pas + 1);
			sol[imax][jmax] = 0;
		}
	}
}

void solutie5() {
	citire();
	sol[x][y] = 1;
	rec(x, y, 2);
}