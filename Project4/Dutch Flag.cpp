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
		else if (arr[cur] > flag) {//д��ʱ�����������⣬����û��else,�����else ֻ�����if������
			swap(arr[cur], arr[--more]);
		}
		else //cur==flag;
			++cur;
	}
}
//����һ�����飬С�ڷ���ߣ����ڷ��м䣬���ڷ��ұ�
int main()
{
	vector<int> arr1{ 3, 2, 4, 6, 8, 5 };
	int flag = 2;
	func(arr1,6);
	for (int i = 0; i < arr1.size(); ++i)
		cout << arr1[i] << ' ';
	return 0;
}