#include <iostream>
#include <cstring>
using namespace std;
char a[2000030]; //函数内栈内存不够需全局
char b[2000030];
/**
 * 巧妙异或
 */
int main()
{
	while (cin>>a>>b){
		int cnt = 0;
		int bLen = strlen(b);
		int aLen = strlen(a);
		int sum = 0;
		for (int i = 0; i < bLen; i++){
			sum = sum ^ a[i] ^ b[i];
		}
		if ((sum & 1) == 0) cnt++;
		for (int j = bLen; j < aLen; j++){
			sum = sum ^ a[j] ^ a[j - bLen];
			if ((sum & 1) == 0) cnt++;
		}
		cout << cnt << endl;
	}
	return 0;
}

//char str[100];
//gets_s(str);
//printf("%s\n", str);
///getchar();