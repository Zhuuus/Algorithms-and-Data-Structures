#include <iostream>
#include <vector>
using namespace std;

int partition(vector<long long>& vec, int low, int height) {
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

void quickSort(vector<long long>& vec, int low, int height) {
    if (low < height) {
        int pi = partition(vec, low, height);
        quickSort(vec, low, pi - 1);
        quickSort(vec, pi + 1, height);
    }
}

int main() {
    int n, m, num;
    cin >> n >> m;
    vector<long long> vec1;
    vector<long long> vec2;
    
    while (n--) {
        cin >> num;
        vec1.push_back(num);
    }
    
    while (m--) {
        cin >> num;
        vec2.push_back(num);
    }
    
    quickSort(vec1, 0, vec1.size() - 1);
    quickSort(vec2, 0, vec2.size() - 1);
    
    long i = 0, j = 0;
    
    while (i < vec1.size() && j < vec2.size()) {
        if (vec1[i] == vec2[j]) {
            cout << vec1[i] << ' ';
            i++;
            j++;
        } else if (vec1[i] > vec2[j]) {
            j++;
        } else {
            i++;
        }
    }

    return 0;
}
