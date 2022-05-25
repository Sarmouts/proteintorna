#include <iostream>
#include <unordered_map>
#include <fstream>
#include <string>
#include <vector>

std::unordered_map<char, std::vector<std::string>> Gcod = {
		{'F', {"UUU","UUC"}},
		{'L', {"CUU","CUC","UUA","CUA","UUG","CUG"}},
		{'I', {"AUU","AUC","AUA"}},
		{'V', {"GUU","GUC","GUA","GUG"}},
		{'M', {"AUG"}},
		{'S', {"UCU","UCC","UCA","UCG","AGU","AGC"}},
		{'P', {"CCU","CCC","CCA","CCG"}},
		{'T', {"ACU","ACC","ACA","ACG"}},
		{'A', {"GCU","GCC","GCA","GCG"}},
		{'Y', {"UAU","UAC"}},
		{'H', {"CAU","CAC"}},
		{'N', {"AAU","AAC"}},
		{'D', {"GAU","GAC"}},
		{'*', {"UAA","UAG","UGA"}},
		{'Q', {"CAA","CAG"}},
		{'K', {"AAA","AAG"}},
		{'E', {"GAA","GAG"}},
		{'C', {"UGU","UGC"}},
		{'R', {"CGU","CGC","CGA","AGA","CGG","AGG"}},
		{'G', {"GGU","GGC","GGA","GGG"}},
		{'W', {"UGG"}}
};
void protein(std::string seq)
{
	int k = seq.size();
	int a = 0;
	std::vector<int> pos(k);
	std::ofstream rna{ "result.txt" };
	while (a != k)
	{
		a = 0;
		for (int i = 0; i < k; i++)
		{
			rna << Gcod[seq[i]][pos[i]];
		}
		rna << "\n";
		for (int j = 0; j < k; j++)
		{
			if (pos[j] == Gcod[seq[j]].size() - 1)
			{
				a++;
				pos[j] = 0;
				continue;
			}
			pos[j]++;
			break;
		}
	}
	rna.close();
}

int main()
{
	std::ifstream in{ "inputseq.txt" };
	std::string seq;
	in >> seq;
	protein(seq);
	in.close();
}