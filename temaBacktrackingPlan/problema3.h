using namespace std;
#include <iostream>
#include <fstream>
#pragma once

//a) sa se verifice daca fotografia este alcatuita doar dintr un singur obiect
//b) daca punctele fac parte din obiecte diferite, sa se afiseze obiectul cu dimensiunea cea mai mare
//c) sa se afiseze un punct din interiorului obiectului cu dim max

ifstream f("imagine.txt");

int imagine[20][20], n, m, sol[20][20], ct = 0;
int dx[8] = { -1, +1, 0, 0, -1, +1, +1, -1 };
int dy[8] = { 0, 0, -1, 1, +1, +1, -1, -1 };

void citire() {
	f >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			f >> imagine[i][j];
		}
	}
}

void afisare() {
	cout << "solutia " << ct << endl << endl;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << sol[i][j];
		}
		cout << endl;
	}
	cout << endl;
	ct++;
}

void rec() {

}

void solutie3() {
	citire();
}