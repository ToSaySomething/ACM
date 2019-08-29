#include <iostream>
#include <vector>
using namespace std;
vector<vector<int> > matrix;
int main(){
	
	int cnt = 1;
	for (int i = 0; i < 4; i++) {
		vector<int> temp;
		//temp.push_back(cnt++);
		for (int j = 0; j < 4; j++) {
			temp.push_back(cnt++);
		}
		matrix.push_back(temp);
	}
	
	int n = matrix.size();
	int m = matrix[0].size();
	int max = n < m ? n : m;
	max = (max-1) / 2 + 1;
	vector<int> result;
	for (int i = 0; i <= max; i++) {
		for (int j = i; j <= m - i - 1 && i < n; j++) {
			result.push_back(matrix[i][j]);
		}
		for (int j = i + 1; j < n - i && m - i - 1 >= 0; j++) {
			result.push_back(matrix[j][m - i - 1]);
		}
		for (int j = m - i - 2; j >= i && n - i - 1 > 0; j--) {
			result.push_back(matrix[n - i - 1][j]);
		}
		for (int j = n - i - 2; j > i && i < m - 1; j--) {
			result.push_back(matrix[j][i]);
		}
	}
	return 0;
}
/*
[[1],[2],[3],[4],[5]  
1 5
*/
/*
vector<int> arr1 = { 2, 3, 1, 3, 2, 4, 6, 7, 9, 2, 19 };
vector<int> arr2 = { 2, 1, 4, 3, 9, 6 };

vector<int> temp;
for (int i = 0; i <= 1000; i++) {
temp.push_back(0);
}
for (int i = 0; i < arr1.size(); i++) {
temp[arr1[i]]++;
}
int cnt = 0;
for (int i = 0; i < arr2.size(); i++) {
for (int j = 0; j < temp[arr2[i]]; j++) {
arr1[cnt++] = arr2[i];
}
}
//return arr1;
return 0;
*/
/*
bool run(char doChar, bool first, bool temp){
	if (doChar == '!'){
		return !first;
	}
	else if (doChar == '&'){
		return first && temp;
	}
	else if (doChar == '|'){
		return first || temp;
	}
}

int main()
{
	struct  Node
	{
		bool charStr;
		int sum;
	};
	string expression;
	cin >> expression;
	stack<Node> numStack;
	stack<int> charStack;
	int sum = 0;
	for (int i = 0; i < expression.length(); i++) {
		if (expression[i] == '('){
			sum++;
			continue;
		}
		if (expression[i] == ')'){
			sum--;
			continue;
		}
		if (expression[i] == '!' || expression[i] == '&' || expression[i] == '|'){
			if
			charStack.push(expression[i]);
			continue;
		}
		if (expression[i] == 't') {
			Node node;
			node.charStr = true;
			node.sum = sum;
			numStack.push(node);
			continue;
		}
		if (expression[i] == 'f') {
			Node node;
			node.charStr = false;
			node.sum = sum;
			numStack.push(node);
			continue;
		}
		
	}

	for (int i = 0; i < charStack.size(); i++) {
		char charStr = charStack.top();
		charStack.pop();
		Node first = numStack.top();
		numStack.top();
		int doFlag = 0;
		while (numStack.size() != NULL){
			Node temp = numStack.top();
			if (temp.sum == first.sum){
				first.charStr = run(charStr, first.charStr, temp.charStr);
				charStack.pop();
				doFlag = 1;
			}
			else {
				break;
			}
		}
		if (!doFlag){
			first.charStr = run(charStr, first.charStr, 0);
		}
		first.sum--;
		numStack.push(first);
	}
	Node first = numStack.top();
	cout << first.charStr << endl;
}
*/