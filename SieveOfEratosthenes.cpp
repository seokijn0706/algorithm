#include <iostream>
using namespace std;

#define MAX 100
int isPrime[MAX + 1];

void SieveOfEratosthenes() {
   for (int i = 2; i <= MAX; i++) {
      isPrime[i] = true; // 처음에 모두 소수라고 가정
   }
   for (int i = 2; i <= MAX; i++) { //2 부터 n 까지
      if (!isPrime[i]) continue; //이미 지워진 수는 무시
      for (int j = i * i; j <= MAX; j += i) { // 자기자신을 제외한 배수를 모두
         isPrime[j] = false; // 지운다
      }
   }
}
int main(void) {
	SieveOfEratosthenes();
	for (int i = 1; i <= MAX; i++) {
		if (isPrime[i])cout << i << ", ";
	}
   return 0;
}
