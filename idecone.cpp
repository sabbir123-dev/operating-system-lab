#include <iostream>
#include <vector>
using namespace std;

int main() {

    int totalNumOfProcesses = 5;

    int totalNumOfResources = 3;
    vector<vector<int>> allocated = {{0, 1, 0}, {2, 0, 0}, {3, 0, 2}, {2, 1, 1}, {0, 0, 2}};
    vector<vector<int>> maxNeed = {{7, 5, 3},{3, 2, 2},{9, 0, 2},{4, 2, 2},{5, 3, 3}};
    vector<int> totalResources = {10, 5, 7};
    vector<int> available(3); // = {3, 3, 2};
    vector<bool> tracking(totalNumOfProcesses, false);
    vector<int> safeSequence(totalNumOfProcesses);
    vector<vector<int>> remainingNeed(totalNumOfProcesses, vector<int>(totalNumOfResources));


    for(int j=0; j<totalNumOfResources; j++) {
    	int sum = 0;
    	cout<<"Allocated Resources\n";
    	for(int i=0; i<totalNumOfProcesses; i++) {
    		cout<<allocated[i][j]<<" ";
    		sum += allocated[i][j];
    	}
    	sum = totalResources[j]-sum;
    	available[j]=sum;
    }
    cout<<"\n";
    cout<<"Available Resources\n";
    for(int i=0; i<totalNumOfResources; i++){
    	cout<<available[i]<<"\t";
    }
    cout<<"\n";


    for (int i = 0; i < totalNumOfProcesses; i++) {
        for (int j = 0; j < totalNumOfResources; j++) {
            remainingNeed[i][j] = maxNeed[i][j] - allocated[i][j];
        }
    }

    int index = 0;
    for (int k = 0; k < totalNumOfProcesses; k++) {
        for (int i = 0; i < totalNumOfProcesses; i++) {
            if (tracking[i] == false) {
                int flag = 0;
                for (int j = 0; j < totalNumOfResources; j++) {
                    if (remainingNeed[i][j] > available[j]) {
                        flag = 1;
                        break;
                    }
                }

                if (flag == 0) {
                    safeSequence[index++] = i;
                    for (int j = 0; j < totalNumOfResources; j++) {
                        available[j] += allocated[i][j];
                    }
                    tracking[i] = true;
                }
            }
        }
    }

    cout << "The Safe Sequence is: ";
    for (int i = 0; i < totalNumOfProcesses ; i++) {
        cout << "\tP" << safeSequence[i];
    }
    cout<<"\n";
    return 0;
}
