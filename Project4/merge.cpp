//mergesort.cpp
#include <iostream>
#include <vector>
using namespace std;

void sort(vector<int>& arr2, int l, int m, int m1, int r) {
    vector<int> sup(arr2.size());
    // int sup[r-l+1];
    int p = l, q = m1;
    int i = 0;
    while (p <= m && q <= r) {
        sup[i++] = ((arr2[p] < arr2[q]) ? arr2[p++] : arr2[q++]);
    }
    while (q <= r) {
        sup[i++] = arr2[q++];
    }
    while (p <= m) {
        sup[i++] = arr2[p++];
    }
    for (int i = 0; i < arr2.size(); i++) {
        arr2[l + i] = sup[i++];
    }
}

void merge(vector<int>& arr1, int left, int right) {
    while (left < right) {
        int mid = (right + left) / 2;//+д����-
        merge(arr1, left, mid);
        merge(arr1, mid + 1, right);
        sort(arr1, left, mid, mid + 1, right);
    }
}
//[1,5,6,4,3,7]
vector<int> mergesort(vector<int>& arr) {
    // int size_arr=arr.size();
    // vector<int> support(size_arr);//����һ����Ԫ����ȳ��ĸ�������
    int left = 0;
    int right = arr.size() - 1;
    merge(arr, left, right);
    return arr;
}

int main()
{
    vector<int> a;
    int a[6] = {1,3,5,2,4,6};
    mergesort(a);
    for (int i = 0; i < a.size(); i++) {
        cout << a[i] << ' ';
    }
}



//  void sort(vector<int>&nums,int L1,int R1,int L2,int R2)//L1,R1�ǵ�һ�������������L2R2ͬ����������ϲ�
// {
//     int temp[R2-L1+1];//��źϲ�����������飨����û��vector�����˻���ʾ�ڴ治�㣩
//     int i=L1;
//     int j=L2;
//     int k=0;
//     while(i<=R1 && j<=R2){
//         if(nums[i]<nums[j])
//         {
//             temp[k++]=nums[i++];
//         }
//         else
//         {
//             temp[k++]=nums[j++];
//         }
//     }//while����֮������ĳ��û�����꣨��һ��϶��Ѿ������꣩��ʣ�µ���ֱ�Ӹ�ֵ
//     while(i<=R1) temp[k++]=nums[i++];
//     while(j<=R2) temp[k++]=nums[j++];
//     for(int i=0;i<k;i++)//�ϲ��������ֵ��ԭ��������
//         nums[L1+i]=temp[i];
// }