//Write a program that prompts the user to input a string and outputs the string in uppercase letters.
#include<iostream>
#include<string>

using namespace std;

int main()
{
    string s1;
    cout<<"Please enter a string which you need to convert to upper case "<<endl;
    getline(cin,s1);
    
    cout<<"Upper case string is "<<endl;
    for (int i=0;i<s1.length();i++)
    {
        s1[i] = toupper(s1[i]);
        cout<<s1[i];
    }
    cout<<endl;

    return 0;
}