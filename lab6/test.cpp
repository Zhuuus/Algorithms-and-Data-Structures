#include <iostream>
#include <vector>
#include <cassert>
using namespace std;
class Solution {
public:

    int partition(vector<int>& vec, int low, int height) {
    int pivot = vec[height]; 
    int i = low - 1;

    for (int j = low; j < height; j++) {
        if (vec[j] < pivot) {
            i++;
            swap(vec[i], vec[j]);
        }
    }
    swap(vec[i + 1], vec[height]);
    return i + 1;
}

void quickSort(vector<int>& vec, int low, int height) {
    if (low < height) {
        int pi = partition(vec, low, height);
        quickSort(vec, low, pi - 1);
        quickSort(vec, pi + 1, height);
    }
}

    bool containsDuplicate(vector<int>& nums) {
        int bagin = 0,end = nums.size();
        quickSort(nums,0,nums.size());
        for(int i=0;i<nums.size()-1;i++){
            if( nums[i]!=nums[i+1]);
            else return false;
        }
        return true;


    }
};
int main() {
    Solution solution;

    // Test Case 1: Contains duplicate
    vector<int> nums1 = {1, 2, 3, 1};
    cout <<solution.containsDuplicate(nums1);
}
