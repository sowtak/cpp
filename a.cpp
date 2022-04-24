#include <bits/stdc++.h>
using namespace std;

int main() {
	int N,X,Y;
	cin>>N>>X>>Y;

}

int general_term(int prev, int curr, int* count) {
	int next = (prev + curr) % 100;
	++count;
	int general_term(curr, next, &count);
}
