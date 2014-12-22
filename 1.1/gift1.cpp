/*
ID: 1023meg2
LANG: C++
TASK: gift1
*/

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    ifstream fin ("gift1.in");
    ofstream fout ("gift1.out");
    int NP;
    fin >> NP;
    
    string names[NP];
    int muhnee[NP];
    
    for(int i=0; i<NP; i++) {
        fin >> names[i];
        muhnee[i] = 0;
    }
    
    for(int i=0; i<NP; i++) {
        string name;
        fin >> name;
        int amt, ppl;
        fin >> amt >> ppl;
        if (ppl > 0) {
            int each = amt / ppl;
            int remain = amt % ppl;
            for(int j=0; j<NP; j++) {
                if (names[j] == name) {
                    muhnee[j] -= amt;
                    muhnee[j] += remain;
                    break;
                }
            }
            for(int j=0; j<ppl; j++) {
                string recipient;
                fin >> recipient;
                for(int k=0; k<NP; k++) {
                    if (names[k] == recipient) {
                        muhnee[k] += each;
                    }
                }
            }
        }
    }
    
    for(int i=0; i<NP; i++) {
        fout << names[i] << " " << muhnee[i] << endl;
    }
    return 0;
}