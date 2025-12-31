#include <iostream>
using namespace std;

void numbers(int i,int n)
{
    if(i<1)
    return ;
    
    cout << i << " " ;
    numbers(i-1,n);
}

int main() 
{
    int n = 6;
    
    numbers(n,n);

    return 0;
}
