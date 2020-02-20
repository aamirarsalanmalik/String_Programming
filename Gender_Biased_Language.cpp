/* Write a program that can be used to train the user to use less gender baised language by suggesting alternative versions of sentences given 
by the user. The program will ask for a sentence, read the sentence into a string variable, and replace all occurrences of masculine pronouns 
with gender-neutral pronouns. For example, it will replace "he" with "she or he".
Thus, the input sentence.

See an adviser, talk to him, and listen to him.

should produce the following suggested changed version of the sentence:

See an adviser, talk to her or him, and listen to her or him.

Be sure to preserve uppercase letters for the first word of the sentence. The pronoun "his" can be replaced by "her (s)"; your program need not
decide between "her" and "hers". Allow the user to repeat this for more sentences until the user says she or he is done.

This will be a long program that requires a good deal of patience. Your program should not replace the string "he" when it occurs inside 
another word, such as "here". A word is any string consisting of the letters of the alphabet and delimited at each end by a blank, the end
of the line, or any other character that is not a letter. Allow your sentences to be up to 100 characters long.*/

#include<iostream>
#include<string>
#include<vector>
using namespace std;
string get_input();
string replace_word(string);
string one_word;
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
    string word;
    int counter=0;
    int index;
    string new_str;
    for(int i=0;i<=str.length();i++)
    //for(auto word_seperate:str)
        {
            if(str[i] ==' ' || int(str[i])==0)
            {
               // cout<<word<<endl;
                if(word == "him" || word == "her" || word == "Her" || word == "Him")
                {
                    if(int(word[0])>=97 && int(word[0])<=122)
                    new_str=new_str+" her or him";
                    if(int(word[0])>=65 && int(word[0])<=90)
                    new_str=new_str+" Her or Him";
                    word.erase();
                    //cout<<"New string is "<<new_str<<endl;
                    if(int(str[i])==0)
                    {
                        goto xyz; 
                    }
                    continue;
                }
                else if(word == "he" || word == "she" || word == "She" || word == "He")
                {
                    if(int(word[0])>=97 && int(word[0])<=122)
                    new_str=new_str+" she or he";
                    if(int(word[0])>=65 && int(word[0])<=90)
                    new_str=new_str+" She or He";
                    word.erase();
                    //cout<<"New string is "<<new_str<<endl;
                    if(int(str[i])==0)
                    {
                        goto xyz; 
                    }
                    continue;  
                }
                else if(word == "his" || word == "her" || word == "Her" || word == "His")
                {
                    if(int(word[0])>=97 && int(word[0])<=122)
                    new_str=new_str+" her or his";
                    if(int(word[0])>=65 && int(word[0])<=90)
                    new_str=new_str+" Her or His";
                    word.erase();
                    //cout<<"New string is "<<new_str<<endl;
                    if(int(str[i])==0)
                    {
                        goto xyz; 
                    }
                    continue;
                }
                else if (word == "himself" || word == "herself" || word == "Herself" || word == "Himself")
                {
                    if(int(word[0])>=97 && int(word[0])<=122)
                    new_str=new_str+" herself or himself";
                    if(int(word[0])>=65 && int(word[0])<=90)
                    new_str=new_str+" Herself or Himself";
                    word.erase();
                    //cout<<"New string is "<<new_str<<endl;
                    if(int(str[i])==0)
                    {
                        goto xyz; 
                    }
                    continue;
                }
                else
                {
                    new_str=new_str+' '+word;
                    word.erase();
                    //cout<<"New string is "<<new_str<<endl;
                    continue;
                }                
            }
            
            else
            {
                  word=word+str[i];
            }
        }
        
        cout<<word;

xyz: 
return new_str;
}
