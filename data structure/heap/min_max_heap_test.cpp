static void test() {
    MinMaxHeap<int> heap;

    /* level check */
    assert(heap.is_min_level(0));
    assert(heap.is_min_level(3));

    assert(heap.is_max_level(1));
    assert(heap.is_max_level(7));

    /* parent and child */
    assert(heap.parent(1) == 0);
    assert(heap.parent(5) == 2);
    assert(heap.parent(2) == 0);
    assert(heap.parent(3) == 1);
    assert(heap.child(0) == 1);
    assert(heap.child(3) == 7);

    /* valiad parent check */
    heap.arr.resize(4);
    heap.arr[0] = 1, heap.arr[1] = 2;
    assert(heap.is_valid_parent(1) == true);
    heap.arr[0] = 2, heap.arr[1] = 1;
    assert(heap.is_valid_parent(1) == false);
    heap.arr[1] = 2, heap.arr[3] = 1;
    assert(heap.is_valid_parent(3) == true);
    heap.arr[1] = 1, heap.arr[3] = 2;
    assert(heap.is_valid_parent(3) == false);

    /* grand parent and grand child */
    assert(heap.grand_parent(4) == 0);
    assert(heap.grand_parent(9) == 1);
    assert(heap.grand_child(0) == 3);
    assert(heap.grand_child(6) == 27);

    /* valiad grand parent check */
    heap.arr.resize(8);
    heap.arr[0] = 1, heap.arr[4] = 2;
    assert(heap.is_valid_grand_parent(4) == true);
    heap.arr[0] = 2, heap.arr[4] = 1;
    assert(heap.is_valid_grand_parent(4) == false);
    heap.arr[1] = 2, heap.arr[9] = 1;
    assert(heap.is_valid_grand_parent(9) == true);
    heap.arr[1] = 1, heap.arr[9] = 2;
    assert(heap.is_valid_grand_parent(9) == false);

    /* number of child */
    heap.arr.resize(1);
    assert(heap.num_of_child(0) == 0);
    heap.arr.resize(2);
    assert(heap.num_of_child(0) == 1);
    heap.arr.resize(3);
    assert(heap.num_of_child(0) == 2);

    /* number of grand child */
    heap.arr.resize(1);
    assert(heap.num_of_grand_child(0) == 0);
    heap.arr.resize(2);
    assert(heap.num_of_grand_child(0) == 0);
    heap.arr.resize(3);
    assert(heap.num_of_grand_child(0) == 0);
    heap.arr.resize(4);
    assert(heap.num_of_grand_child(0) == 1);
    heap.arr.resize(32);
    assert(heap.num_of_grand_child(0) == 4);
}
