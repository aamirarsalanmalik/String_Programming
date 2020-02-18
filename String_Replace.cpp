/* Write a program that reads in a line of text and replaces all four-letter words with the word “love”. For example, the input string 
I hate you, you dodo!

should produce the output

I love you, you love!

Of course, the output will not always make sense. For example, the input string

John will run home.

should produce the output

Love love run love.

If the four-letter word starts with a capital letter, it should be replaced by "Love", not by "love". You need not check capitalization, except for the first 
letter of a word. A word is any string consisting of the letters of the alphabet and delimited at each end by a blank, the end of the line, or any other 
character that is not a letter. Your program should repeat this action until the user says to quit. */

#include<iostream>
#include<string>
#include<vector>
using namespace std;
string get_input();
string replace_word(string);
char ch[4] = {'l','o','v','e'};
char ch_upper[4] = {'L','o','v','e'};
int main()
{
    char choice;
    string in_received = get_input();
    string replaced_string = replace_word(in_received);
    cout<<"The replaced string is \n"<<replaced_string<<endl;
    return 0;
}

string get_input()
{
    string input_string;
    cout<<"Enter the string in which you want to replace all four character words "<<endl;
    getline(cin,input_string);
    return input_string;
}

string replace_word(string str)
{
    int index =0;
    int counter=0;
    vector<int> vec (4);
    int len_str =str.length();
    //int counter =0;
    
    for(int i=0;i<=len_str;i++)
    {
        int u = 0;
        if(str[i]!=' ' && int(str[i])!=0)
        {
            if((int(str[i])>=65 && int(str[i])<=90) || (int(str[i])>=97 && int(str[i])<=122))
            {
            vec.at(u)=str[i]; //store character in a vector
          //  cout<<"Vector is "<<vec.at(u)<<endl;
            counter+=1; // counting character
            if(counter==1) 
                {
                    index = i; //index of first character of each word. 
                }
            }
         }
        else
        {
            int count=0;
            if (counter == 4)
            {
                for(int j =index;j<index+4;j++)
                {
                    if(int(str[index])>=97 && int(str[index])<=122)
                        {
                            str[j]=ch[count];
           //                 cout<<"Replaced String is "<<str[j];
                            count+=1;
                        }
                        else if(int(str[index])>=65 && int(str[index]<=90))
                        {
                            str[j]=ch_upper[count];
             //               cout<<"Replaced String is "<<str[j];
                            count+=1;
                        }
                }
                counter=0;
            }
            else
                counter=0;
                continue;
        }
    }
    return str;
}
