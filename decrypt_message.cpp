/* Your country is at war and your enemies are using a secret code to communicate with each other. You have managed to intercept a message 
that read as follows:
:mmZ\dxZmx]Zpgy
The message is obviously encrypted using the enemy’s secret code. You have just learned that their encryption method is based upon the ASCII 
code (you can find this set easily by searching online). Individual characters in a string are encoded using this system. For example, the 
letter ‘A’ is encoded using the number 65 and ‘B’ is encoded using the number 66.
Your enemy’s secret code takes each letter of the message and encrypts it as follows (using a secret key):
If (OriginalChar + Key > 126) then
    EncryptedChar = ((OriginalChar + Key) - 127) + 32
Else 
    EncryptedChar = (OriginalChar + Key)
 
For example, if the enemy uses Key = 10 then the message ”Hey” would be encrypted as:

Character   ASCII
H         72
e         101
y         121

Encrypted H = (72 + 10) = 82 = R in ASCII
Encrypted e = (101 + 10) = 111 = o in ASCII
Encrypted y = 32 + ((121 + 10) - 127) = 36 = $ in ASCII

Consequently, “Hey” would be transmitted as “Ro$”.

Write a program that decrypts the intercepted message. You only know that the key used is a number between 1 and 100. Your program should try 
to decode the message using all possible keys between 1 and 100. When you try the valid key, the message will make sense. For all other keys, 
the message will appear as gibberish. */

#include<iostream>
#include<string>
#include<vector>
using namespace std;
string get_input(); //Function to take the message input from the user
vector<int> decrypted_message(string,int,int); //Function to decrypt the message recieved

int main()
{
    string input_val;
    vector<int> encrypted,decoded;
    input_val = get_input();
    for (int Key =1;Key<=100;Key++)
    {
        decoded = decrypted_message(input_val,input_val.length(),Key);
        cout<<endl;
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



vector<int> decrypted_message(string v,int len,int Key)
{
    cout<<"The decrypted message is with key = "<<Key<<" is "<<endl;;
    string decrypted_mes;
    vector<int> DecryptedChar (50);
    for (int i=0;i<len;i++)
    {
        if (int(v[i]) - Key < 32)
            {
                DecryptedChar.at(i) = ((v[i] - Key) + 127) - 32; 
                decrypted_mes[i] = static_cast<char>(DecryptedChar.at(i));
                cout<<decrypted_mes[i];
            }  
        else
            {
            DecryptedChar.at(i) = (int(v[i]) - Key);
            decrypted_mes[i] = static_cast<char>(DecryptedChar.at(i));
            cout<<decrypted_mes[i];
            }
    }
    cout<<endl;
    return DecryptedChar;
}





