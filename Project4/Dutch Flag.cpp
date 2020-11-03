#include <iostream>
#include <vector>
using namespace std;

void func(vector<int>& arr,int flag) {
	int cur = 0;
	int less = -1;
	int more = arr.size() ;
	while (cur < more) {
		if (arr[cur] < flag)
		{
			swap(arr[++less],arr[cur++]);
		}
		else if (arr[cur] > flag) {//写的时候遇到的问题，这里没加else,下面的else 只对这个if起作用
			swap(arr[cur], arr[--more]);
		}
		else //cur==flag;
			++cur;
	}
}
//给定一个数组，小于放左边，等于放中间，大于放右边
int main()
{
	vector<int> arr1{ 3, 2, 4, 6, 8, 5 };
	int flag = 2;
	func(arr1,6);
	for (int i = 0; i < arr1.size(); ++i)
		cout << arr1[i] << ' ';
	return 0;
}