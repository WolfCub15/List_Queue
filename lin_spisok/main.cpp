#include <iostream>
#include<string>
#include <cstdlib>
#include "Element.h"
#include "Queue.h"
using namespace std;
void delenie_stroki_razn_delit(string *w, string st, string zn, int &k) {
	k = 0;
	for (int i = 0; i < st.size(); i++) {
		if (zn.find(st[i]) == -1) {
			w[k].push_back(st[i]);
		}
		else {
			if (w[k].size() > 0) {
				k++;
			}
			w[k][0] = st[i];
		}
	}
}
Queue *q=new Queue[10];
void Radix_Sort(int *a, int n, int t) {
	int m = 1;
	for (int i = 0; i <= t; i++) {
		for (int j = 0; j < n; j++) {
			q[((a[j])/m) % 10].push(a[j]);
		}
		for (int j = 0, k = 0; j<10; j++) {
			while (!q[j].empty()) {
				a[k++] = q[j].pop();
			}
		}
		m *= 10;
	}
}

int main() {
	/*Queue q1;
	for (int i = 1; i <= 10; i++) {
		q1.push(i);
	}
	Queue q2=q1;
	Queue q3 = q2;
	cout << q3 << endl;
	cout << q1 << endl;
	int k;
	cin >> k;
	q2.push(k);
	int m;
	cin >> m;
	q2.push(m);
	q2.pop();
	cout << q2 << endl;*/

	
	string s;
	getline(cin, s);
	string *w;
	w = new string[s.size() + 2];
	int k = 0;
	s += " ";
	string zn = " .,?!";
	delenie_stroki_razn_delit(w, s, zn, k);
	
	int *a;
	a = new int[k];
	for (int i = 0; i < k; i++) {
		a[i] = stoi(w[i]);
	}
	int t = 4;
	Radix_Sort(a, k, t);
	for (int i = 0; i < k; i++) {
		cout<< a[i]<<" ";
	}
	return 0;
}
