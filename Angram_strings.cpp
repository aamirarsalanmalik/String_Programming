/* Write a function that determines if two strings are anagrams. The function should not be case sensitive and should disregard any punctuation
or spaces. Two strings are anagrams if the letters can be rearranged to form each other. For example, “Eleven plus two” is an anagram of 
“Twelve plus one.” Each string contains one “v”, three “e’s”, two “l’s”, etc. Test your function with several strings that are anagrams and 
non-anagrams. You may use either the string class or a C-style string. */

#include<iostream>
#include<string>
#include<bits/stdc++.h> 
using namespace std;
bool string_angram(string, string);
int main()
{
string str1,str2;
cout<<"Enter the first string "<<endl;
getline(cin,str1);
cout<<"Enter the second string "<<endl;
getline(cin,str2);
bool check = string_angram(str1,str2);
if(check == 1)
    cout << "The two strings are anagram of each other"<<endl; 
    else
    cout << "The two strings are not anagram of each other"<<endl; 
return 0;
}

bool string_angram(string first,string second)
{
    int len_str1=first.length();
    int len_str2=second.length();
    int count_1 = 0;
    int count_2 = 0;
    for (int i=0;i<=len_str1;i++)
    {
        if(first[i] == ' ')
        {
            count_1++;
        }
    }
    
    for (int i=0;i<=len_str2;i++)
    {
        if(second[i] == ' ')
        {
            count_2++;
        }
    }
    int len_w_out_space_str1 = len_str1-count_1;
    int len_w_out_space_str2 = len_str2-count_2;
    
    if (len_w_out_space_str1==len_w_out_space_str2)
        return true;
    
    // Sort both the strings 
    sort(first.begin(), first.end()); 
    sort(second.begin(), second.end()); 
    
    // Compare sorted strings 
    for (int i = 0; i < len_str1; i++) 
        if (first[i] != second[i]) 
            return false; 
    return true; 

}
