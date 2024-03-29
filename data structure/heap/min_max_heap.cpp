#include <iostream>
#include <vector>
#include <functional>
#include <bit>
#include <cassert>

using namespace std;

template <typename I, typename CMP>
size_t most_elem_idx(I first, size_t sz, CMP cmp) {
    auto m = first;
    for (auto i = next(first); sz-- > 1; ++i) {
        if (cmp(*i, *m)) m = i;
    }
    return m - first;
}

template <typename T>
class MinMaxHeap{
public:
    MinMaxHeap(): arr() { }

    const T& max() const {
        size_t i =
            num_of_child(0)
            ? most_child(0, greater<>())
            : 0;

        return arr[i];
    }

    T pop_max() {
        size_t cur =
            num_of_child(0)
            ? most_child(0, greater<>())
            : 0;

        return pop(cur);
    }

    const T& min() const {
        return arr[0];
    }

    T pop_min() {
        return pop(0);
    }

    void push(const T& v) {
        return push(T(v));
    }

    void push(T&& v) {
        arr.push_back(move(v));
        size_t cur = arr.size() - 1;

        if (cur == 0) return;
        if (!is_valid_parent(cur)) {
            auto p = parent(cur);
            swap(arr[cur], arr[p]);
            cur = p;
        }
        
        while (parent(cur) != 0) {
            if (is_valid_grand_parent(cur)) break;
            auto gp = grand_parent(cur);
            swap(arr[cur], arr[gp]);
            cur = gp;
        }
    }

    bool empty() const {
        return arr.empty();
    }

    void print_elems() const {
        for (size_t i = 0; i < arr.size(); ++i) {
            cout << arr[i] << ' ';
            auto tmp = i + 2;
            if (!(tmp & (tmp - 1)))
                cout << '\n';
        }
        cout << endl;
    }

private:

    T pop (size_t idx) {
        if (is_min_level(idx)) {
            return pop(idx, less<>());
        }
        return pop(idx, greater<>());
    }

    template <typename CMP>
    T pop(size_t idx, CMP cmp) {
        size_t cur = idx;
        T ret = move(arr[cur]);
        arr[cur] = move(arr.back());
        arr.pop_back();

        while (num_of_child(cur) > 0) {
            if (cur != 0) {
                auto p = parent(cur);
                if (cmp(arr[p], arr[cur]))
                    swap(arr[p], arr[cur]);
            }
            size_t mn =
                num_of_grand_child(cur)
                ? most_grand_child(cur, cmp)
                : most_child(cur, cmp);
            if (cmp(arr[cur], arr[mn])) break;
            swap(arr[cur], arr[mn]);
            cur = mn;
        }

        return ret;
    }

    bool is_valid_parent(size_t child) const {
        return (arr[child] < arr[parent(child)]) ^ is_max_level(child);
    }
    bool is_valid_grand_parent(size_t grand_child) const {
        return (arr[grand_child] < arr[grand_parent(grand_child)])
            ^ is_min_level(grand_child);
    }

    size_t parent(size_t child) const {
        return child ? (child - 1) / 2 : 0;
    }
    size_t grand_parent(size_t grand_child) const {
        return parent(parent(grand_child));
    }
    size_t child(size_t parent) const {
        return parent * 2 + 1;
    }
    size_t grand_child(size_t grand_parent) const {
        return child(child(grand_parent));
    }

    bool is_min_level(size_t i) const {
        return (sizeof(size_t) * 8 - countl_zero<size_t>(i + 1)) & 1;
    }
    bool is_max_level(size_t i) const {
        return !is_min_level(i);
    }

    size_t num_of_child(size_t parent) const {
        auto ch = child(parent);
        if (arr.size() <= ch) return 0;
        return ::min<size_t>(2, arr.size() - ch);
    }

    size_t num_of_grand_child(size_t grand_parent) const {
        auto gch = grand_child(grand_parent);
        if (arr.size() <= gch) return 0;
        return ::min<size_t>(4, arr.size() - gch);
    }

    template <typename CMP>
    size_t most_grand_child(size_t grand_parent, CMP cmp) const {
        auto gch = grand_child(grand_parent);
        return most_elem_idx(arr.begin() + gch,
            num_of_grand_child(grand_parent), cmp) + gch;
    }

    template <typename CMP>
    size_t most_child(size_t parent, CMP cmp) const {
        auto ch = child(parent);
        return most_elem_idx(arr.begin() + ch,
            num_of_child(parent), cmp) + ch;
    }

public:
#include "min_max_heap_test.cpp"

private:
    vector<T> arr;
};

#if 0
int main() {
    MinMaxHeap<int>::test();
}
#endif

#if 0
int main() {
    MinMaxHeap<long> heap;

    heap.push(1);
    heap.print_elems();
    cout << "====================\n";
    heap.push(4);
    heap.print_elems();
    cout << "====================\n";
    heap.push(2);
    heap.print_elems();
    cout << "====================\n";
    heap.push(1);
    heap.print_elems();
    cout << "====================\n";
    heap.push(3);
    heap.print_elems();
    cout << "====================\n";
    heap.push(4);
    heap.print_elems();
    cout << "====================\n";
    heap.push(5);
    heap.print_elems();
    cout << "====================\n";
    heap.push(1);
    heap.print_elems();
    cout << "====================\n";

    cout << heap.pop_max() << '\n';
    cout << heap.pop_min() << '\n';
    cout << heap.pop_max() << '\n';
    cout << heap.pop_min() << '\n';
    cout << heap.pop_max() << '\n';
    cout << heap.pop_min() << '\n';
    cout << heap.pop_max() << '\n';
    cout << heap.pop_min() << '\n';
}
#endif

#if 1
int main() {
    MinMaxHeap<int> heap;

    heap.push(1);
    heap.push(5);
    heap.push(3);
    heap.push(2);
    heap.push(4);
    heap.push(7);
    heap.push(6);

    heap.print_elems();

#if 0 // pop_max & pop_min
    cout << heap.pop_max() << '\n';
    cout << heap.pop_min() << '\n';
    cout << heap.pop_max() << '\n';
    cout << heap.pop_min() << '\n';
    cout << heap.pop_max() << '\n';
    cout << heap.pop_min() << '\n';
    cout << heap.pop_max() << '\n';
#endif // pop_max & pop_min

#if 1 // pop_max
    cout << heap.pop_max() << '\n';
    cout << heap.pop_max() << '\n';
    cout << heap.pop_max() << '\n';
    cout << heap.pop_max() << '\n';
    cout << heap.pop_max() << '\n';
    cout << heap.pop_max() << '\n';
    cout << heap.pop_max() << '\n';
#endif // pop_max

#if 0 //pop_min
    cout << heap.pop_min() << '\n';
    cout << heap.pop_min() << '\n';
    cout << heap.pop_min() << '\n';
    cout << heap.pop_min() << '\n';
    cout << heap.pop_min() << '\n';
    cout << heap.pop_min() << '\n';
    cout << heap.pop_min() << '\n';
#endif // pop_min
}
#endif

#if 0
int main() {
    MinMaxHeap<int> heap;

    heap.push(3);
    heap.print_elems();
    cout << "================\n";
    heap.push(2);
    heap.print_elems();
    cout << "================\n";
    heap.push(1);
    heap.print_elems();
    cout << "================\n";
}
#endif
