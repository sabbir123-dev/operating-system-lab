#include <iostream>
using namespace std;

int main() {
    int n = 3;
    int pid[] = {1, 2, 3};
    int bt[] = {24, 3, 3};
    int ct[3], ta[3], wt[3];


    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (bt[i] > bt[j]) {

                swap(bt[i], bt[j]);

                swap(pid[i], pid[j]);
            }
        }
    }


    int currentTime = 0;
    for (int i = 0; i < n; i++) {
        currentTime += bt[i];
        ct[i] = currentTime;
        ta[i] = ct[i];
        wt[i] = ta[i] - bt[i];
    }


    cout << "Process\tBurst\tCompletion\tTurnaround\tWaiting\n";
    for (int i = 0; i < n; i++) {
        cout << "P" << pid[i] << "\t" << bt[i] << "\t"
             << ct[i] << "\t\t" << ta[i] << "\t\t" << wt[i] << endl;
    }

    return 0;
}
