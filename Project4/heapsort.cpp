#include <iostream>
#include <vector>
using namespace std;
void hsort(vector<int> &str, int cur) {
	// if(cur==0)
	//     pass;
	//while (cur != 0) {
	if (cur != 0 && (str[cur] > str[(cur - 1) / 2])) {
		swap(str[cur], str[(cur - 1) / 2]);
		hsort(str, (cur - 1) / 2);
	}
	return;
}
vector<int> heapSort(vector<int> &str) {
	int str_len = str.size();
	int index = 0;
	while (index < str_len) {
		//每次加入一个元素
		hsort(str, index++);
	}
	return str;
}

int main()
{
	vector<int> pri_arr{ 2,3,1,6,5,4 };
	vector<int> nex_arr = heapSort(pri_arr);
	for (auto i : nex_arr)
		cout << i;
	return 0;
}

//左孩子2i+1,右孩子2i+2,父节点(i-1)/2