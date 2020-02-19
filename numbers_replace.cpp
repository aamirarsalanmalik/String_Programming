/* Write a program that reads in a line of text and outputs the line with all the digits in all integer numbers replaced with 'x'. 
For example,
Input:
My userID is john17 and my 4 digit pin is 1234 which is secret.
Output:
My userID is john17 and my x digit pin is xxxx which is secret.
Note that if a digit is part of a word, then the digit is not changed to an 'x'. For example, note that john17 is NOT changed to johnxx. 
Include a loop that allows the user to repeat this calculation again until the user says she or he wants to end the program.*/

#include<iostream>
#include<string>
#include<vector>
using namespace std;
string get_input();
string replace_word(string);
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
    cout<<"Enter the string in which you want to replace only numeric words with X "<<endl;
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
            //cout<<"ASCII of char is "<<int(str[i])<<endl;
            if((int(str[i])>=65 && int(str[i])<=90) || (int(str[i])>=97 && int(str[i])<=122))
            {
                counter+=1;
                continue;
            }
            else
            {
                if(counter>0)
                {
                    if(counter>0 && str[i+1]== ' ')
                    counter=0;
                continue;
                }
                else
                    str[i] = 'X';
            }
        }
        else
            counter=0;
    }

    return str;
}
