#include <iostream>
#include "myqueue.h"

using namespace std;
using namespace myqueue;

int main()
{
    char data;
    myQueue<char> queue(26);
    for(char i = 'A' ;i<='Z';++i)
        queue.enqueue(i);
    while(!queue.empty())
        cout<<queue.dequeue()<<endl;
    return 0;
}