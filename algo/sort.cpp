#include <bits/stdc++.h>
using namespace std;

// 待排序数组
vector<int> nums = {8,2,6,3,10,9,4,1,7,5};

// 选择排序
void selection_sort(vector<int> &nums)
{
    int n = nums.size();
    for(int i=0;i<n;i++)
    {
        int tmp = i;
        for(int j=i+1;j<n;j++)
        {
            if(nums[j]<nums[tmp])
            {
                tmp = j;
            }
        }
        swap(nums[i],nums[tmp]);
    }
}

// 冒泡排序
void bubble_sort(vector<int> &nums)
{
    int n = nums.size();
    for(int i = n-1;i>0;i--)
    {
        for (int j = 0;j<i;j++)
        {
            if(nums[j]>nums[j+1])
                swap(nums[j],nums[j+1]);
        }
    }
}

// 插入排序
void insertion_sort(vector<int> &nums)
{
    for(int i=1;i<nums.size();i++)
    {
        int j=i-1;
        int tmp =nums[i];
        while(j>=0 && nums[j]>tmp)
        {
            nums[j+1] = nums[j];
            j--;
        }
        nums[j+1]=tmp;
    }
}

// 快速排序
int partition(vector<int> &nums,int left,int right)
{
    int i = left, j = right;
    while(i<j)
    {
        while(i<j && nums[j]>=nums[left])
            j--;
        while(i<j && nums[i]<=nums[left])
            i++;
        swap(nums[i],nums[j]);
    }
    swap(nums[i],nums[left]);
    return i;
}
void quicksort(vector<int> &nums,int left,int right)
{
    if(right <= left) 
        return;
    
    int pivot = partition(nums,left,right);
    quicksort(nums,left,pivot-1);
    quicksort(nums,pivot+1,right);
}

// 归并排序
void merge(vector<int> &nums,int left,int mid,int right)
{
    vector<int> tmp;
    int i=left,j=mid+1;

    while(i<=mid && j<=right)
    {
        if(nums[i]<nums[j])
        {
            tmp.push_back(nums[i]);
            i++;
        }
        else
        {
            tmp.push_back(nums[j]);
            j++;
        }
    }

    for(;i<=mid;i++)
        tmp.push_back(nums[i]);
    for(;j<=right;j++)
        tmp.push_back(nums[j]);

    for(int k=0;k<tmp.size();k++)
    {
        nums[left+k] = tmp[k];
    }

}
void merge_sort(vector<int> &nums,int left,int right)
{
    if(left >= right)
        return;

    int mid =left + (right - left) / 2;
    merge_sort(nums,left,mid);
    merge_sort(nums,mid+1,right);

    merge(nums,left,mid,right);
}

// 堆排序
void shiftDown(vector<int> &nums,int n,int i)
{
    while(true)
    {
        int l = i * 2 + 1;
        int r = i * 2 + 2;
        int target = i;

        if(l<n && nums[l]>nums[target])
            target = l;
        if(r<n && nums[r]>nums[target])
            target = r;
        if(target == i) break;
        swap(nums[i],nums[target]);
        i = target;
    }
}
void heapSort(vector<int> &nums)
{
    size_t n =nums.size();
    for(int i=(n-2)/2;i>=0;i--)
        shiftDown(nums,n,i);

    for(int i=n-1;i>0;i--)
    {
        swap(nums[0],nums[i]);
        shiftDown(nums,i,0);
    }
}
int main()
{
    for(int i = 0;i<nums.size();i++)
    {
        cout << nums[i] << ' ';
    }
    cout << "\n";

    // selection_sort(nums);
    // bubble_sort(nums);
    // insertion_sort(nums);
    // quicksort(nums,0,nums.size()-1);
    // merge_sort(nums,0,nums.size()-1);
    // heapSort(nums);

    for(int i = 0;i<nums.size();i++)
    {
        cout << nums[i] << ' ';
    }
    return 0;
}