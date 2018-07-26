#include <iostream>
#include "mystack.h"

using namespace std;
using namespace x;
int main()
{
    x::myStack<char> stack(26);
    for(char i = 'A'; i <= 'Z'; ++i)
        stack.push(i);
    while(!stack.empty())
        cout<<stack.pop()<<endl;
    return 0;
}
