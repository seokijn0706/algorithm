#include <iostream>
using namespace std;

bool isPrime(int n) {
	if (n <= 1) return false;
	for (int i = 2; i * i <= n; i++) {
		if (n % i == 0) return false;
	}
	return true;
}

int main(void) {
	cout << "input N : ";
	int n;
	cin >> n;
	if (isPrime(n)) {
		cout << n << " is prime number";
	}
	else {
		cout << n << " is composite number";
	}
	return 0;
}
