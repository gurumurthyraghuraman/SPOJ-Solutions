#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


/*string winner(vector<int> ngStrength, vector<int> nmStrength) {
    if (ngStrength.size() == 0 && nmStrength.size() == 0)
            return "uncertain";

     int p =0;
     int q = 0;
     while(p < ngStrength.size() && q < nmStrength.size()) {
        if (ngStrength[p] < nmStrength[q])
            p++;
        if (nmStrength[q] <= ngStrength[p])
            q++;
     }
     if (p == ngStrength.size())
        return "MechaGodzilla";

     return "Godzilla";

}*/

string winner(vector<int> ngStrength, vector<int> nmStrength) {
        if (ngStrength.size() == 0 && nmStrength.size() == 0)
            return "uncertain";

        int ngMax = *max_element(ngStrength.begin(), ngStrength.end());
        int nmMax = *max_element(nmStrength.begin(), nmStrength.end());

        if (ngMax >= nmMax) {
            return "Godzilla";
        }
        return "MechaGodzilla";
}


int main() {
    int ng, nm;
    int t;
    int temp;
    vector<int> ngStrength;
    vector<int> nmStrength;
    cin>>t;
    for (int i = 0; i < t; i++) {
        cin>>ng>>nm;
        ngStrength.clear();
        nmStrength.clear();
        for (int j = 0; j < ng ; j++) {
            cin>>temp;
            ngStrength.push_back(temp);
        }
        for (int k = 0; k < nm; k++) {
            cin>>temp;
            nmStrength.push_back(temp);
        }
        cout<<winner(ngStrength, nmStrength)<<endl;
    }
    return 0;
}
