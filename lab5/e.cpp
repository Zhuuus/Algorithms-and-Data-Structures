#include <iostream>
#include <vector>
using namespace std;

class MaxHeap {
public:
    vector<long long> cooks;
    long long size;
    long long sum;

    MaxHeap() {
        size = 0;
        sum = 0;
    }

    // int left(int i) {
    //     return i * 2 + 1;
    // }

    // int right(int i) {
    //     return i * 2 + 2;
    // }

    long long parent(int i) {
        return (i - 1) / 2;
    }

    void insert(long long num) {
        cooks.push_back(num);
        sum += num;
        // long long i = size;
        // while (i > 0 && cooks[parent(i)] < cooks[i]) {
        //     swap(cooks[parent(i)], cooks[i]);
        //     i = parent(i);
        // }
        size += 1;
    }

    void print() {
        cout << sum << endl;
    }
};

int main() {
    MaxHeap* maxHeap = new MaxHeap;
    long long n, m;
    cin >> n >> m;
    while (n > 0) {
        string s;
        cin >> s;
        if (s == "insert" && m > 0) {
            long long k;
            cin >> k;
            maxHeap->insert(k);
            m--;
        } else if (s == "print") {
            maxHeap->print();
        }
        n--;
    }
    delete maxHeap; 
    return 0;
}
