#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int boysNumber; cin >> boysNumber;
    vector<int> boysSkills(boysNumber);
    for (int b = 0; b < boysNumber; b++) {
        cin >> boysSkills[b];
    }
    int girlsNumber; cin >> girlsNumber;
    vector<int> girlsSkills(girlsNumber);
    for (int g = 0; g < girlsNumber; g++) {
        cin >> girlsSkills[g];
    }
    sort(boysSkills.begin(), boysSkills.end());
    sort(girlsSkills.begin(), girlsSkills.end());
    int pairsNumber = 0;
    for (int i = 0, j = 0; i < boysNumber && j < girlsNumber;) {
        if (abs(boysSkills[i] - girlsSkills[j]) < 2) {
            pairsNumber++; i++; j++;
        } else if (boysSkills[i] > girlsSkills[j]) {
            j++;
        } else if (boysSkills[i] < girlsSkills[j]) {
            i++;
        }
    }
    cout << pairsNumber << endl;
    return 0;
}
