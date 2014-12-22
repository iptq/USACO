/*
ID: 1023meg2
LANG: C++
TASK: ride
*/

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

string checkSuccess(string comet, string group);

int main() {
    ifstream fin ("ride.in");
    ofstream fout ("ride.out");
    string comet, group;
    fin >> comet >> group;
    fout << checkSuccess(comet, group) << endl;
    return 0;
}

string checkSuccess(string comet, string group) {
    int cometScore = 1;
    for(int i=0; i<comet.length(); i++) {
        cometScore *= ((int)(comet[i])-(int)('A')+1);
    }
    int groupScore = 1;
    for(int i=0; i<group.length(); i++) {
        groupScore *= ((int)(group[i])-(int)('A')+1);
    }
    return (cometScore % 47 == groupScore % 47) ? "GO" : "STAY";
}