#include <iostream>
#include <unordered_map>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

void percent(string seq)
{
	unordered_map<char, string> umap = {
		{'F', "UUUUUC"},
		{'L', "CUUCUCUUACUAUUGCUG"},
		{'I', "AUUAUCAUA"},
		{'V', "GUUGUCGUAGUG"},
		{'M', "AUG"},
		{'S', "UCUUCCUCAUCGAGUAGC"},
		{'P', "CCUCCCCCACCG"},
		{'T', "ACUACCACAACG"},
		{'A', "GCUGCCGCAGCG"},
		{'Y', "UAUUAC"},
		{'H', "CAUCAC"},
		{'N', "AAUAAC"},
		{'D', "GAUGAC"},
		{'*', "UAAUAGUGA"},
		{'Q', "CAACAG"},
		{'K', "AAAAAG"},
		{'E', "GAAGAG"},
		{'C', "UGUUGC"},
		{'R', "CGUCGCCGAAGACGGAGG"},
		{'G', "GGUGGCGGAGGG"},
		{'W', "UGG"} };
	ofstream temp{ "codons.txt" };
	for (size_t i = 0; i < seq.length(); i++)
	{
		temp << umap[seq[i]] << endl;
	}
	temp.close();
	ifstream codons{ "codons.txt" };
	string aminoA = "";
	string aminoB = "";
	codons >> aminoA >> aminoB;
	string help = "";
	int n = 1;
	int a = 0;
	int b = 0;
	for (size_t i = 0; i < (aminoA.size() / 3) * (aminoB.size() / 3); i++)
	{
		if (a + 3 * n == aminoA.size() && b + 3 == aminoB.size())
		{
			help += aminoA.substr(a, 3 * n) + aminoB.substr(b, 3);
			aminoA = help;
			n++;
			a = 0;
			b = 0;
			help = "";
			aminoB = "";
			codons >> aminoB;
		}
		else if (b + 3 == aminoB.size())
		{
			help += aminoA.substr(a, 3 * n) + aminoB.substr(b, 3);
			b = 0;
			a += 3 * n;
		}
		else
		{
			help += aminoA.substr(a, 3 * n) + aminoB.substr(b, 3);
			b += 3;
		}
	}
	codons.close();
	ofstream result{ "result.txt" };
	for (size_t i = 0; i < aminoA.length(); i += n * 3)
	{
		result << aminoA.substr(i, n * 3) << endl << endl;
	}
	result.close();
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
/* vector<string> codons = {};
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
	 }*/