#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
const int maxn = 11;
int n, P[maxn];
bool hashTable[maxn] = { false };
int count = 0;
void Generate(int index){
	if (index == n + 1){
		for (int i = 1; i <= n; i++){
			for (int j = i + 1; j <= n; j++){
				if (abs(P[j] - P[i]) == abs(j - i)){
					return;
				}
			}
		}
		for (int i = 1; i <= n; i++){
			printf("%d", P[i]);
		}
		printf("\n");
		count++;
	}
	else{
		for (int j = 1; j <= n; j++){
			if (hashTable[j] == false){
				hashTable[j] = true;
				P[index] = j;
				Generate(index + 1);
				hashTable[j] = false;
			}
		}
	}
};
void Generate1(int index){
	for (int i = 1; i <= index - 2; i++){
		if (abs(P[index - 1] - P[i]) == index - 1 - i){
			return;
		}
	}
	if (index == n + 1){
		for (int i = 1; i <= n; i++){
			printf("%d", P[i]);
		}
		printf("\n");
		count++;
		return;
	}
	
	for (int j = 1; j <= n; j++){
		if (hashTable[j] == false){
			hashTable[j] = true;
			P[index] = j;
			Generate1(index + 1);
			hashTable[j] = false;
		}
	}
};
void Generate2(int index){
	if (index == n + 1){
		for (int i = 1; i <= n; i++){
			printf("%d", P[i]);
		}
		printf("\n");
		count++;
		return;
	}

	for (int j = 1; j <= n; j++){
		if (hashTable[j] == false){
			hashTable[j] = true;
			P[index] = j;
			for (int k = 1; k < j; k++){
				if (abs(P[j] - P[k]) == j - k){
					break;
				}
			}
			Generate1(index + 1);
			hashTable[j] = false;
		}
	}
};
int main(){
	n = 8;
	Generate2(1);
	printf("%d\n", count);
	system("pause");
	return 0;
}