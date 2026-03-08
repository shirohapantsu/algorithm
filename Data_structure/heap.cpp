#include <bits/stdc++.h>
using namespace std;

class heap
{
    public:
        void push(int val) {
            maxHeap.push_back(val);
            shiftUp(maxHeap.size()-1);
        }

        void pop(){
            if(!maxHeap.empty())
            {
                swap(maxHeap[0],maxHeap[maxHeap.size()-1]);
                maxHeap.pop_back();
                shiftDown(0);
            }
        }
        vector<int> build_heap(vector<int> nums)
        {
            maxHeap = nums;
            for(int i=maxHeap.size()-1;i>=0;i--)
            {
                shiftDown(i);
            }
            return maxHeap;
        }
    private:
        vector<int> maxHeap{};

        int left(int i){
            return 2*i +1;
        }
        int right(int i){
            return 2*i +2;
        }
        int parent(int i){
            return (i-1)/2;
        }

        int peek(){
            return maxHeap[0];
        }

        void shiftUp(int i){
            int p =parent(i);
            if(maxHeap[p]<maxHeap[i] && p>=0)
            {
                swap(maxHeap[p],maxHeap[i]);
                shiftUp(p);
            }
            return;
        }

        void shiftDown(int i)
        {
            while(1)
            {
                int l=left(i),r=right(i),target=i;
                if(l<maxHeap.size() && maxHeap[l]>maxHeap[target])
                    target = l;
                if(r<maxHeap.size() && maxHeap[r]>maxHeap[target])
                    target = r;
                if(target == i) break;
                swap(maxHeap[i],maxHeap[target]);
                i = target;
            }
        }

};

int main()
{

}
