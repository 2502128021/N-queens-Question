#include <cstdio>
#include <cstdlib>
#include <cstring>
const int maxn = 11;
int n, P[maxn], hashTable[maxn] = { false };
void Generate(int index){
	if (index == n+1){
		for (int i = 1; i <= n; i++){
			printf("%d", P[i]);
		}
		printf("\n");
	}
	else{
		for (int j = 1; j <= n; j++){
			if (hashTable[j] == false){
				hashTable[j] = true;
				P[index] = j;
				Generate(index+1);
				hashTable[j] = false;
			}
		}
	}
};
int main(){
	n = 9;
	Generate(1);
	system("pause");
	return 0;
}