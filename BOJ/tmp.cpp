#include <cstdio>
#include <vector>
#include <functional>

using namespace std;

template <typename T, typename CMP=less<T>>
class Heap{
public:
    Heap(): arr() { }

    void push(T&& v) {
        arr.push_back(forward<T>(v));
        size_t cur = arr.size() - 1;
        
        while (cur != 0) {
            auto p = parent(cur);
            if (!cmp(arr[cur], arr[p])) break;
            swap(arr[cur], arr[p]);
            cur = p;
        }
    }

    T pop() {
        T ret = move(arr[0]);
        arr[0] = move(arr[arr.size() - 1]);
        arr.pop_back();

        size_t cur = 0;
        while (true) {
            auto c = child(cur);
            if (c >= arr.size()) break;
            if (c + 1 < arr.size() &&
                !cmp(arr[c], arr[c + 1])) ++c;
            if (cmp(arr[cur], arr[c])) break;
            swap(arr[cur], arr[c]);
            cur = c;
        }

        return ret;
    }

private:
    size_t parent(size_t child) {
        return child / 2;
    }
    size_t child(size_t parent) {
        return parent * 2 + 1;
    }

private:
    vector<T> arr;
    CMP cmp;
};

int main() {
    Heap<int> h;

    h.push(4);
    h.push(5);
    h.push(2);
    h.push(1);
    h.push(3);

    printf("%d\n", h.pop());
    printf("%d\n", h.pop());
    printf("%d\n", h.pop());
    printf("%d\n", h.pop());
    printf("%d\n", h.pop());
}
