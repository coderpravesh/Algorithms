#include <bits/stdc++.h>
using namespace std ;
const int M = 3e5+5;

int bit[M];
int bit1[M];
 
int get(int x){
    int res=0;
    for(;x>0;x-=(x&-x))
        res+=bit[x];
    return res;
}
 
void add(int x,int d){
    for(;x<M;x+=(x&-x))
        bit[x]+=d;
}

int main() {
	add(x,d); // for adding value 
	get(x) ; // for getting sum 
	return 0 ;
}
