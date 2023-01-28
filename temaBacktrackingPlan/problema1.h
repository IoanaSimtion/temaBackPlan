using namespace std;
#include <iostream>
#include <fstream>
#pragma once

//matrice - tabla de sah
//2 puncte de coord XoY - poz unui cal si a reginei adversarului
//sa se afisdeze toate drumurile pe care le poate parcurge calul ai sa ajunga la poz reginei
//care este nr de pasi pt cel mai scurt drum?

ifstream f("sah.txt");

int n, sah[20][20], xC, yC, xR, yR, ct, sol[20][20];
int dx[] = { -2,-1,1,2,2,1,-1,-2 }, dy[] = { 1,2,2,1,-1,-2,-2,-1 };


void citire() {
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			f >> sah[i][j];
		}
	}
	cout << "Introduceti pozitia calului: " << endl;
	cin >> xC >> yC;
	cout << "Introduceti pozitia reginei: " << endl;
	cin >> xR >> yR;
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
			if (imax == xR && jmax == yR) {
				afisare();
			}
			rec(imax, jmax, pas + 1);
			sol[imax][jmax] = 0;
		}
	}
}

void solutie1() {
	citire();
	sol[xC][yC] = 1;
	rec(xC, yC, 2);
}