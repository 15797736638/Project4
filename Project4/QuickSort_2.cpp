//用荷兰国旗方法快排
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
void quickSort(vector<int>& arr, int left, int right);
void sort_arr(vector<int>& arr) {
	int left = 0;
	int right = arr.size() - 1;
	quickSort(arr,left,right);
}
//arr=[2,5,6,4,3,1]
void quickSort(vector<int>& arr, int left, int right) {
	int less = left - 1;
	int more = right + 1;
	int mid = (left + right) / 2;
	int cur = left;
	int flag = arr[right];
	while (cur < more) {
		if (arr[cur] < flag) {
			swap(arr[++less], arr[cur++]);
		}
		else if (arr[cur] > flag) {
			swap(arr[cur], arr[--more]);
		}
		else
			cur++;
	}
	if(left<less)
		quickSort(arr, left, less);
	if(more<right)
		quickSort(arr, more, right);
}

int main()
{
	vector<int> arr{ 3,2,4,3,2,5,2,6 };
	sort_arr(arr);
	for (int i = 0; i < arr.size(); ++i)
		cout << arr[i] << ' ';
	return 0;
}