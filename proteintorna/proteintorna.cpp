#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>
using namespace std;

void percent(string seq)
{
    unordered_map<char, string> umap = {
        {'F', "UUU UUC"},
        {'L', "CUU CUC UUA CUA UUG CUG"},
        {'I', "AUU AUC AUA"},
        {'V', "GUU GUC GUA GUG"},
        {'M', "AUG"},
        {'S', "UCU UCC UCA UCG AGU AGC"},
        {'P', "CCU CCC CCA CCG"},
        {'T', "ACU ACC ACA ACG"},
        {'A', "GCU GCC GCA GCG"},
        {'Y', "UAU UAC"},
        {'H', "CAU CAC"},
        {'N', "AAU AAC"},
        {'D', "GAU GAC"},
        {'*', "UAA UAG UGA"},
        {'Q', "CAA CAG"},
        {'K', "AAA AAG"},
        {'E', "GAA GAG"},
        {'C', "UGU UGC"},
        {'R', "CGU CGC CGA AGA CGG AGG"},
        {'G', "GGU GGC GGA GGG"},
        {'W', "UGG"} };
    vector<string> codons = {};
    for (size_t i = 0; i < seq.length(); i++)
    {
        codons.push_back(umap[seq[i]]);
    }
    string str = "";
    //codons position
    int i = 0;
    //codons[i] position
    int k = 0; //codons[i].size() - 1;
    //codons[i+1] position
    int f = 0; //codons[i + 1].size() - 1;
    //number of cases
    int n = 1;
    for (int j = 0; j < (codons[i].size() + 1) / 2 * (codons[i + 1].size() + 1) / 2; j++)
    {
        if (k + 3 * n == codons[i].size() && f + 3 == codons[i + 1].size())
        {
            str += codons[i].substr(k, 3 * n) + codons[i + 1].substr(f, 3);
            codons[i + 1] = str;
            i++;
            n++;
            str = "";
            k = 0;
            f = 0;
            j = 0;
            if (i + 1 == codons.size())
            {
                break;
            }
        }
        else if (f + 3 == codons[i + 1].size())
        {
            str += codons[i].substr(k, 3 * n) + codons[i + 1].substr(f, 3) + " ";
            k += 3 * n + 1;
            f = 0;
        }
        else
        {
            str += codons[i].substr(k, 3 * n) + codons[i + 1].substr(f, 3) + " ";
            f += 4;
        }
    }

    for (size_t l = 0; l < codons[i].size(); l++)
    {
        if (codons[i][l] == ' ')
        {
            cout << endl
                << endl;
        }
        else
        {
            cout << codons[i][l];
        }
    }
}

int main()
{
    string str;
    cout << "=====================================================================================================" << endl;
    cout << "Welcome to Protein to mRNA Calculator!Here you will be able to find all possible codons combinations!" << endl;
    cout << "======================================================================" << endl;
    cout << "Warning!!!Do not enter protein sequences with too many combinations!!!" << endl;
    cout << "======================================================================" << endl;
    cout << "Enter your protein sequence: " << endl;
    cin >> str;
    percent(str);
    cout << endl;
    system("Pause");
}