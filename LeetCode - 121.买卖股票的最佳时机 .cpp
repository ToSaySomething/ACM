#include "iostream"
#include "vector"
using namespace std;

int main(){
	vector<int> prices;
	for (int i = 0; i < 2; i++){
		prices.push_back(i);
	}
	if (prices.size() == 0){
		return 0;
	}
	vector<int> max(prices.size());
	int sMax = 0;
	for (int i = prices.size() - 1; i >= 0; i--) {
		if (i == prices.size() - 1) {
			max[i] = sMax = prices[i];
		}
		else {
			if (sMax < prices[i]) {
				max[i] = prices[i];
				sMax = prices[i];
			}
			else {
				max[i] = max[i + 1];
			}
		}
	}
	int min = 0;
	int dis = 0;
	for (int i = 0; i < prices.size() - 1; i++) {
		if (i == 0) {
			min = prices[i];
		}
		else {
			if (min > prices[i]) {
				min = prices[i];
			}
		}
		dis = dis > (max[i + 1] - min) ? dis : (max[i + 1] - min);
	}
	return 0;
}