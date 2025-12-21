#include<bits/stdc++.h>
using namespace std;
int main(){
int n=4;
int at[]={0,0,0,0};
int bt[]={6,8,7,3};
int ct[n],ta[n],wt[n];
vector<int>v;
for(int i=0;i<n;i++)
{
    v.push_back(bt[i]);
}
sort(v.begin(),v.end());

ct[0] = at[0] + v[0];
    for(int i = 1; i < n; i++) {
        ct[i] = ct[i-1] + v[i];
    }


    for(int i = 0; i < n; i++) {
        ta[i] = ct[i] - at[i];
        wt[i] = ta[i] - v[i];
    }


    cout << "Process\tArrival\tBurst\tCompletion\tTurnaround\tWaiting\n";
    for(int i = 0; i < n; i++) {
        cout << "P" << i+1 << "\t" << at[i] << "\t" << v[i] << "\t"
             << ct[i] << "\t\t" << ta[i] << "\t\t" << wt[i] << endl;
    }

    return 0;
}

