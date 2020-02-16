/* Write a program to take a message as input and encrypt it using the following method:

If (OriginalChar + Key > 126) then
    EncryptedChar = ((OriginalChar + Key) - 127) + 32
Else 
    EncryptedChar = (OriginalChar + Key)

Key can have any value ranging from 1 to 100.

Next decrypt the message using the formula:
If (EncryptedChar - Key < 32) then
    DecryptedChar = ((EncryptedChar - Key) + 127) - 32
Else
    DecryptedChar = (EncryptedChar - Key)*/

#include<iostream>
#include<string>
#include<vector>
using namespace std;
string get_input(); //Function to take the message input from the user
vector<int> encrypted_message(string,int); //Function to encrypt the message recieved
vector<int> decrypted_message(vector<int>,int,int); //Function to decrypt the message recieved

int main()
{
    string input_val;
    int Key=100;
    vector<int> encrypted,decoded;
    cout<<"OPTION 1:  Do you want to encrpyt a meesage and then decrypt it?"<<endl;
    cout<<"\t \t \t \t  OR \t \t \t \t"<<endl;
    cout<<"OPTION 2:  Do you want to enter an encrypted message in order to decrypt it?"<<endl;
    cout<<"Enter 1 for OPTION 1 and 2 for OPTION 2 "<<endl;
    
    input_val = get_input();
    cout<<"The encrypted message is ";
    for (Key =1;Key<=100;Key++)
    {
        encrypted = encrypted_message(input_val,Key);
        cout<<"The ASCII codes for the encrypted message with Key = " <<Key << " is "<<endl;;
        
    cout<<endl;
    cout<<endl;
    decoded = decrypted_message(encrypted,input_val.length(),Key);
    cout<<endl;
    cout<<"The ASCII codes for the decrypted message with Key = " <<Key <<" is "<<endl;
    }
    
return 0;
}

string get_input()
{
    string message;
    cout<<"Enter the encrypted message you recieved from the enemy "<<endl;
    getline(cin, message);
    return message;
}


vector<int> encrypted_message(string message,int Key)
{
    vector<int> EncryptedChar (50); 
    string encrypted_mes;
    for(int i=0;i<=message.length();i++)
    {
        if(int(message[i])+Key>126)
        {
            EncryptedChar.at(i)= 32 + ((int(message[i]) + Key)-127);
            encrypted_mes[i] = static_cast<char>(EncryptedChar.at(i));
            cout<<encrypted_mes[i];
        }
        else
        {
            EncryptedChar.at(i) = int(message[i]) + Key;
            encrypted_mes[i] = static_cast<char>(EncryptedChar.at(i));
            cout<<encrypted_mes[i] ;
        }
    }
cout<<endl;
return EncryptedChar;
}

vector<int> decrypted_message(vector<int> v,int len,int Key)
{
    cout<<"The decrypted message is ";
    string decrypted_mes;
    vector<int> DecryptedChar (50);
    for (int i=0;i<len;i++)
    {
        if (v.at(i) - Key < 32)
            {
                DecryptedChar.at(i) = ((v.at(i) - Key) + 127) - 32; 
                decrypted_mes[i] = static_cast<char>(DecryptedChar.at(i));
                cout<<decrypted_mes[i];
            }  
        else
            {
            DecryptedChar.at(i) = (v.at(i) - Key);
            decrypted_mes[i] = static_cast<char>(DecryptedChar.at(i));
            cout<<decrypted_mes[i];
            }
    }
    cout<<endl;
    return DecryptedChar;
}