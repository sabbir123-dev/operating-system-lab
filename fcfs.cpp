#include <iostream>
using namespace std;

int main() {
    int n = 3;
    int at[] = {0, 0, 0};
    int bt[] = {24, 3, 3};
    int ct[n], ta[n], wt[n];


    ct[0] = at[0] + bt[0];
    for(int i = 1; i < n; i++) {
        ct[i] = ct[i-1] + bt[i];
    }


    for(int i = 0; i < n; i++) {
        ta[i] = ct[i] - at[i];
    }


    for(int i = 0; i < n; i++) {
        wt[i] = ta[i] - bt[i];
    }

    cout << "Process\tArrival Time\tBurst Time\tCmp Time\tTurn Time\tWaiting Time\n";
    for(int i = 0; i < n; i++) {
        cout << "P" << i+1 << "\t\t" << at[i] << "\t\t" << bt[i] << "\t\t"
             << ct[i] << "\t\t" << ta[i] << "\t\t" << wt[i] << endl;
    }

    return 0;
}

