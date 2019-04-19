#include <bits/stdc++.h>
#include <sstream>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
	string line = "Senthilkumar is my name, you got it, Do you understand my name";
	for (int i = 0, len = line.size(); i < len; i++) 		//Removing Punctuation
    { 
        // check whether parsing character is punctuation or not 
        if (ispunct(line[i])) 
        { 
            line.erase(i--, 1); 
            len = line.size(); 
        } 
    } 
	
	
	// Vector
	cout << endl << "************Vector**************" << endl;
	vector <string> tokens;
	stringstream check1(line);       // breaking input into word using string stream, Used for breaking words
	string words;					 // Storing tokens which splitted
	
	while(getline(check1, words, ' '))
	{
		tokens.push_back(words);
	}
	cout << endl << "Splitted tokens are : " << endl;
	for(int i = 0; i<tokens.size(); i++)
	{
		cout << tokens[i] << endl;
	}
	

	//UnOrdered  Map
	cout << endl << "************Unordered Map**************" << endl;
	unordered_map<string, int> umap;
	stringstream check2(line);
	string words2;
	while(check2 >> words2)
	{
		cout << words2 << endl; 
		umap[words2]++;
	}
	cout << endl << "Count of each string" << endl << "________________________________" << endl << endl;;
	unordered_map<string, int>::iterator it; 
	for (it = umap.begin(); it != umap.end(); it++) 
		cout << it->first << " -> " << it->second << endl;
	
	
	return 0;
}