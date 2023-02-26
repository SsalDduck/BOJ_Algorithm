#include<bits/stdc++.h>
using namespace std;

stack<long long> s;
long long temp, res;
int n;

int main(){
    scanf("%d", &n);

    for(int i = 0; i < n; i++){
        scanf("%lld", &temp);
        while (!s.empty() && s.top() <= temp){
            s.pop();
        }
        s.push(temp);
        res += s.size() -1;
    }
    printf("%lld\n", res);
}