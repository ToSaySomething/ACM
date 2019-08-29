#include <iostream>
#include <malloc.h>
using namespace std;

struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
		val(x), next(NULL) {}
};
int main(){
	/* 输入 */
	ListNode* qNode = NULL;
	ListNode* head = NULL;
	int t = 10;
	while (t--){
		ListNode* p = (struct ListNode *)malloc(sizeof(struct ListNode*));
		p->val = t;
		p->next = NULL;
		if (head == NULL){
			head = p;
		}
		else {
			qNode->next = p;
		}
		qNode = p;
	}
	qNode = NULL;
	free(qNode);
	int n = 2, m = 4;
	/*
	// 反转
	ListNode* newNode = (struct ListNode *)malloc(sizeof(struct ListNode*));
	newNode = NULL;
	ListNode* curNode = (struct ListNode *)malloc(sizeof(struct ListNode*));
	while (head != NULL) {
		curNode = head;
		head = head->next;
		curNode->next = newNode;
		newNode = curNode;
	}
	// 输出
	ListNode*x = newNode;
	while (x != NULL) {
	printf("%d ", x->val);
	x = x->next;
	}
	curNode = NULL;
	free(curNode);
	newNode = NULL;
	free(newNode);
	*/

	// 指定反转段
	ListNode* node = head;
	ListNode* newNode = (struct ListNode *)malloc(sizeof(struct ListNode*));
	newNode = NULL;
	ListNode* curNode = (struct ListNode *)malloc(sizeof(struct ListNode*));
	
	while (node != NULL) {
		curNode = node;
		node = node->next;
		curNode->next = newNode;
		newNode = curNode;
	}

	ListNode* nodex = (struct ListNode *)malloc(sizeof(struct ListNode*));
	nodex = NULL;
	for (int i = 1; head != NULL; i++) {
		if (i >= m-1 && i <= n-1){
			nodex = newNode->next;
		}
		else {
			nodex = head->next;
		}
		nodex = nodex->next;
		newNode = newNode->next;
		head = head->next;
	}

	ListNode*x = nodex;
	while (x != NULL) {
		printf("%d ", x->val);
		x = x->next;
	}
	node = NULL;
	free(node);
	curNode = NULL;
	free(curNode);
	newNode = NULL;
	free(newNode);
	
	
	getchar();
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