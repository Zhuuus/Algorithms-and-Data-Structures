// #include <iostream>

// using namespace std;

// struct Heap {
//     int* arr;
//     int capacity;
//     int length;

//     void _add(int val) {
//         arr[length] = val;
//         length++;
//         heap_up(length - 1);
//     }

//     void heap_up(int i) {
//         if(i > 0) {
//             int p_pos = (i - 1) / 2;
//             if(arr[p_pos] > arr[i]) {
//                 swap(arr[p_pos], arr[i]);
//                 heap_up(p_pos);
//             }
//         }
//     }

//     void heap_down(int i) {
//         int l = 2 * i + 1;
//         int r = 2 * i + 2;
//         int min_pos = i;
//         if(l < length and arr[l] < arr[min_pos]) min_pos = l;
//         if(r < length and arr[r] < arr[min_pos]) min_pos = r;
//         if(min_pos != i) {
//             swap(arr[min_pos], arr[i]);
//             heap_down(min_pos);
//         }
//     }
    
//     Heap(int capacity) {
//         arr = new int[capacity];
//         this->capacity = capacity;
//         length = 0;
//     }

//     void insert(int val, int k) {
//         if(length < k) _add(val);
//         else if(length == k and arr[0] < val) {
//             arr[0] = val;
//             heap_down(0);
//         }
//     }

//     long long print(int k) {
//         long long sum = 0;
//         if(length < k) k = length;
//         for(int i = 0; i < k; i++) {
//             sum += arr[i];
//         }
//         return sum;
//     }
// };


// int main() {
//     int q, k;
//     cin >> q >> k;

//     Heap heap(100001);

//     while(q--) {
//         string s;
//         int val;
//         cin >> s;
//         if(s == "print") cout << heap.print(k) << endl;
//         else if(s == "insert") {
//             cin >> val;
//             heap.insert(val, k);
//         }
//     }
// }










#include <iostream>
#include <vector> 
using namespace std;

struct MinHeap {
    vector<long long> heap;

    long long parent(long long i) {
        return (i - 1) / 2;
    }
    long long left(long long i) {
        return 2 * i + 1;
    }
    long long right(long long i) {
        return 2 * i + 2;
    }
    void insert(long long value) {
        heap.push_back(value);
        long long i = heap.size() - 1;
        while (i != 0 && this->heap[parent(i)] > this->heap[i]) {
            swap(this->heap[parent(i)], this->heap[i]);
            i = parent(i);
        } //sift up
    }
    void heapify(long long i) {
        long long l = this->left(i);
        long long r = this->right(i);
        int smallest = i;
        if (l < this->heap.size() && this->heap[l] < this->heap[i])
            smallest = l;
        if (r < this->heap.size() && this->heap[r] < this->heap[smallest])
            smallest = r;
        if (smallest != i) {
            swap(this->heap[i], this->heap[smallest]);
            this->heapify(smallest);
        }
    }   //sift down
    void print(){
        for(long long i = 0; i < heap.size(); i++){
            cout << heap[i] << ' ';
        }
        cout << endl;
    }

    long long extractMin() {
        if (this->heap.size() == 0) return 0;
        if (this->heap.size() == 1) {
            long long root = this->heap[0];
            this->heap.pop_back();
            return root;
        }
        long long root = this->heap[0];
        this->heap[0] = this->heap[this->heap.size() - 1];
        this->heap.pop_back();
        this->heapify(0);
        return root;
    }

    long long answer(int m) {
        long long answer = 0;
        while (heap.size() > 1) {   

            long d1 = extractMin();
            long d2 = extractMin();       

            if(d1 >= m) {
                return answer;
            }
            long long d = d1 + (2 * d2);
            answer+=1;
            insert(d);
        }
        return -1;
    }
};


int main() {
    MinHeap heap;
    long long n, m; cin >> n >> m;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        heap.insert(x);
    }

    cout << heap.answer(m);

    // cout << heap->answer();
}