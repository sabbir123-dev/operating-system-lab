#include <bits/stdc++.h>
using namespace std;

int main() {
    int n = 4;
    int at[] = {0, 1, 2,3};
    int bt[] = {8, 4, 9,5};
    int ct[n], ta[n], wt[n];

    // Create vector of pairs {burst time, arrival time}
    vector<pair<int,int>> p;
    for(int i = 0; i < n; i++) {
        p.push_back({bt[i], at[i]});
    }

    // Sort by burst time automatically (first element of pair)
    sort(p.begin(), p.end());

    // Assign sorted burst time and arrival time back to arrays
    for(int i = 0; i < n; i++) {
        bt[i] = p[i].first;
        at[i] = p[i].second;
    }

    // Completion Time
    ct[0] = at[0] + bt[0];
    for(int i = 1; i < n; i++) {
        ct[i] = ct[i-1] + bt[i];
    }

    // Turnaround Time
    for(int i = 0; i < n; i++) {
        ta[i] = ct[i] - at[i];
    }

    // Waiting Time
    for(int i = 0; i < n; i++) {
        wt[i] = ta[i] - bt[i];
    }

    cout << "Process\tArrival Time\tBurst Time\tCompletion Time\tTurnaround Time\tWaiting Time\n";
    for(int i = 0; i < n; i++) {
        cout << "P" << i+1 << "\t\t"
             << at[i] << "\t\t"
             << bt[i] << "\t\t"
             << ct[i] << "\t\t"
             << ta[i] << "\t\t"
             << wt[i] << endl;
    }

    return 0;
}

