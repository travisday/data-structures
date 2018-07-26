#include <iostream>
#include "heapSort.h"
#include <ctime>
#include <cstdlib>
#include <iomanip>
#include <string>

using namespace std;

int main()
{
    heapSort<int> sort;
    vector<int> list = {5, 7, 9, 20, 32, 1, 18};

    sort.itemsToSort(list);
    sort.print();
    sort.sort();
    cout<<endl;
    sort.print();
    return 0;
}