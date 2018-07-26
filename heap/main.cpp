#include "heap.h"

int main() {
    heap<int> data;
    data.push(4);
    data.push(9);
    data.push(2);
    data.push(23);
    data.push(66);
    data.push(1);
    data.push(45);
    data.push(11);
    data.push(90);
    data.push(7);

    data.print();



    return 0;
}