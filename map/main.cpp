#include <iostream>
#include "mymap.h"

using namespace std;

int main()
{
    x::myMap<char, int> theMap;
    theMap.insert(x::pair<char,int>('a',1));
    theMap.insert(x::pair<char,int>('z',26));
    theMap['d'] = 3;
    theMap['f'] = 3;
    theMap['y'] = 3;
    theMap['i'] = 3;
    for(x::myMap<char,int>::iterator it = theMap.begin(); it != theMap.end(); it++)
        cout<<it->first<<" = "<<it->second<<endl;
    cout<<endl<<endl;
    for(x::myMap<char,int>::iterator it = theMap.begin(); it != theMap.end(); it++)
        cout<<it->first<<" = "<<it->second<<endl;


    return 0;
}
