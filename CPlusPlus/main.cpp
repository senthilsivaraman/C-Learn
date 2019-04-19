#include <bits/stdc++.h>
#include<iostream>
#include<string>
using namespace std;

bool areRotations(string str1, string str2)
{
	if(str1.length() != str2.length())
	{
		return false;
	}
	else
	{
		string temp = str1 + str1;
		return(temp.find(str2) != -1);
	}
}

bool areAnagram(string s1, string s2)
{
	sort(s1.begin(), s1.end());
	sort(s2.begin(), s2.end());
	
	if(s1.length() != s2.length())
	{
		return false;
	}
	else
	{
		for(int i=0; i<s1.length(); i++)
		{
			if(s1[i] == s2[i])
			{
				return true;
			}
		}
	}
}


int main()
{
	// Initializing string 
    string str = "geeksforgeeks is for geeks"; 
  
    // Displaying string 
    cout << "The initial string is : "; 
    cout << str << endl; 
  
    // Resizing string using resize() 
    str.resize(13); 
  
    // Displaying string 
    cout << "The string after resize operation is : "; 
    cout << str << endl; 
  
    // Displaying capacity of string 
    cout << "The capacity of string is : "; 
    cout << str.capacity() << endl; 
  
    // Decreasing the capacity of string 
    // using shrink_to_fit() 
    str.shrink_to_fit(); 
  
    // Displaying string 
    cout << "The new capacity after shrinking is : "; 
    cout << str.capacity() <<"   " << str << endl; 
	
	string s2("This is new string");
	cout <<"S2:" << s2 << "\n";
	
	//(NumberofTimes, Letter to be printed)
	string str1(5, 'F');
	cout << "STR1:" << str1 <<endl;
	
	
	//String are rotation of each other
	string a1 = "THIS", a2 = "ISTH";
	if(areRotations(a1, a2))
	{
		cout << "THIS and ISTH are Rotation of each other" << endl;
	}
	else
	{
		cout << "THIS and ISTH are not rotation of each other" << endl;
	}
	
	
	//Finding whether anagram or not
	string s11 = "LISTEN";
	string s12 = "SILENT";
	if(areAnagram(s11, s12))
	{
		cout << "LISTEN and SILENT are Anagram of each other" << endl;
	}
	else
	{
		cout << "LISTEN and SILENT are not Anagram of each other" << endl;
	}
	
	
	//Manual Sorting of String
	string sentence;
	cout << " Enter the sentence : ";
	getline(cin, sentence);
	cout << sentence << endl;
	remove(sentence.begin(), sentence.end(), ' ');
	cout << sentence << endl;
	sort(sentence.begin(), sentence.end());
	cout << sentence << endl;
	
	
	//Iterator - Removing space from string
	string temp("Senthil kumar Siva Raman");
	cout << "Printing the string" << endl;
	for(string::iterator it = temp.begin(); it != temp.end(); it++)
	{
		if(*it ==' ')
		{
		}
		else
		{
			cout << *it << endl;
		}
	}
	cout << "Reverse Printing" << endl;
	for(string::reverse_iterator rit = temp.rbegin(); rit != temp.rend(); rit++)
	{
		if(*rit ==' ')
		{
		}
		else
		{
			cout << *rit << endl;
		}
	}
	
	
	//String Functions - At, swap, Compare, Capacity, Clear & Empty 
	string s222 = "This is my";
	cout << "String at 3 is : " << s222.at(3) << endl;
	
	string temp1 ("senthil");
	string temp2 ("Senthil");
	temp1.swap(temp2);
	cout << "After Swapping : " << temp1 << " " << temp2 << endl;
	
	if(temp1.compare(temp2) != 0)
	{
		cout << "Strings are not same" << endl;
	}
	else
	{
		cout << "Strings are identical" << endl;
	}
	
	cout << "Size" << s222.capacity() << endl;
	
	s222.clear();
	cout << "String After clear : " << s222 << endl;
	cout << "Size after clear : " << s222.capacity() << endl;
	
	if(s222.empty())
	{
		cout << "s222 is empty" << endl;
	}
	else{
		cout << "S222 is not empty";
	}
	
	
	//Splitting words in a string / Tokenizing
	
	string line = "Senthilkumar is my name, you got it, Do you understand my name";
	vector <string> tokens;
	stringstream check1(line);       // breaking input into word using string stream, Used for breaking words
	string words;					 // Storing tokens which splitted
	
	while(getline(check1, words, ' '))
	{
		tokens.push_back(words);
	}
	cout << " Splitted tokens are : ";
	for(int i = 0; i<tokens.size(); i++)
	{
		cout << tokens[i] << endl;
	}
	cout << "Token[4] : " << tokens[4] << endl;		//Accessing specific token
	
	//Finding duplicates in token
	
	
	
	
	
	return 0;
	
}