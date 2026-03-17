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

// 希尔排序
void shell_sort(vector<int> &nums)
{
    int n = nums.size();
    int gap = n / 2;

    while(gap > 0)
    {
        for(int i=gap;i<n;i++)
        {
            for(int j=i;j>=gap && nums[j]<nums[j-gap];j-=gap)
            {
                swap(nums[j],nums[j-gap]);
            }
        }
        gap = gap / 2;
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

// 桶排序
void bucketSort(vector<int> &nums,int bucket_size)
{
    int max = *max_element(nums.begin(),nums.end());
    int min = *min_element(nums.begin(),nums.end());

    int n =(max - min) / bucket_size + 1;
    vector<vector<int>> buckets(n);

    for(int num :nums)
    {
        buckets[(num-min)/bucket_size].push_back(num);
    }
    int p = 0;
    for(auto &bucket:buckets)
    {
        insertion_sort(bucket);
        for(int x : bucket)
        {
            nums[p] = x;
            p++;
        }
    }
}

// 计数排序
void counting_sort(vector<int> &nums)
{
    int max = *max_element(nums.begin(),nums.end());
    int min = *min_element(nums.begin(),nums.end());
    vector<int> counter(max - min +1,0);

    // 统计每个数出现了几次
    for(int num : nums)
    {
        counter[num - min]++;
    }

    //统计前缀和，将出现次数转换为尾索引
    for(int i=0;i<max-min+1;i++)
    {
        counter[i+1] += counter[i];
    }

    //转化为结果数组
    vector<int> res(nums.size());
    for(auto num = nums.rbegin();num!=nums.rend();num++)
    {
        res[counter[*num-min]-1] = *num;
        counter[*num-min]--;
    }
    nums = res;

}

// 基数排序
void radix_sort(vector<int> &nums)
{
    int max = *max_element(nums.begin(), nums.end());
    int min = *min_element(nums.begin(), nums.end());

    // 将所有数平移到非负区间，便于按位取 digit
    long long offset = (min < 0) ? -(long long)min : 0;

    vector<int> res(nums.size());

    // 找到平移后的最大值，决定需要做多少轮（个位、十位、百位...）
    long long shifted_max = (long long)max + offset;

    for (long long exp = 1; shifted_max / exp > 0; exp *= 10)
    {
        vector<int> counter(10, 0);

        // 统计当前位(0-9)出现次数
        for (int num : nums)
        {
            long long x = (long long)num + offset;
            int digit = (int)((x / exp) % 10);
            counter[digit]++;
        }

        // 前缀和：counter[d] 变成 digit<=d 的元素总数（尾索引）
        for (int i = 1; i < 10; i++)
        {
            counter[i] += counter[i - 1];
        }

        // 从后往前稳定回填
        for (auto it = nums.rbegin(); it != nums.rend(); ++it)
        {
            long long x = (long long)(*it) + offset;
            int digit = (int)((x / exp) % 10);

            res[counter[digit] - 1] = *it;
            counter[digit]--;
        }

        nums = res; // 或者 nums.swap(res);
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
    // bucketSort(nums,2);
    // shell_sort(nums);
    // counting_sort(nums);
    // radix_sort(nums);

    for(int i = 0;i<nums.size();i++)
    {
        cout << nums[i] << ' ';
    }
    return 0;
}