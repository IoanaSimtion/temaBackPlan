using namespace std;
#include <iostream>
#include <fstream>
#pragma once

//cel mai scurt drum pe care il poate prcurge pisica pt a ajunge la soarece

int labirint[10][20], xS, yS, xP, yP, n, m, sol[10][20];
int dx[] = { -1,1,0,0 }, dy[] = { 0,0,-1,1 };

ifstream f("labirint.txt");

void citire() {
	f >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			f >> labirint[i][j];
		}
	}
	cout << "Intorduceti pozitia soarecelui: ";
	do {
		cin >> xS >> yS;
	} while (labirint[xS][yS] == 1);
	cout << "Introduceti pozitia piscii: ";
	do {
		cin >> xP >> yP;
	} while (labirint[xP][yP] == 1);
}

void afisare() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << sol[i][j] << ' ';
		}
		cout << endl;
	}
	cout << endl;
}

void rec(int i, int j, int pas) {
	int imax, jmax, k;
	for (k = 0; k < 4; j++) {
		imax = i + dx[k];
		jmax = j + dy[k];
		if (labirint[imax][jmax] == 0 && sol[imax][jmax] == 1) {
			sol[imax][jmax] = pas;
			if (imax == xP && jmax == yP) {
				afisare();
			}
			rec(imax, jmax, pas + 1);
			sol[imax][jmax] = 1;
		}
	}
}

void solutie2() {
	citire();
	sol[xS][yS] = 1;
	rec(xS, yS, 1);
}