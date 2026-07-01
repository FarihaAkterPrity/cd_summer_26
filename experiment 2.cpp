#include <iostream>
using namespace std;

void tokenize(string input)
{
    string op[] = {"+", "-", "*", "/", "<<", "="};
    char punc[] = {';', ',', '(', ')', '{', '}'};
    string key[] = {"int", "float", "void", "cout", "cin"};

    string token = "";

    for (int i = 0; i <= input.length(); i++)
    {
        if (i == input.length() || input[i] == ' ')
        {
            if (token == "")
                continue;

            bool matched = false;


            for (int j = 0; j < 5; j++)
            {
                if (token == key[j])
                {
                    cout << "Keyword -> " << token << endl;
                    matched = true;
                    break;
                }
            }
            if (matched) { token = ""; continue; }


            for (int j = 0; j < 6; j++)
            {
                if (token == op[j])
                {
                    cout << "Operator -> " << token << endl;
                    matched = true;
                    break;
                }
            }
            if (matched) { token = ""; continue; }

            if (token.length() == 1)
            {
                for (int j = 0; j < 6; j++)
                {
                    if (token[0] == punc[j])
                    {
                        cout << "Punctuation -> " << token << endl;
                        matched = true;
                        break;
                    }
                }
            }
            if (matched) { token = ""; continue; }

            bool isNum = true;
            for (int j = 0; j < token.length(); j++)
            {
                if (!((token[j] >= '0' && token[j] <= '9') || token[j] == '.'))
                {
                    isNum = false;
                    break;
                }
            }

            if (isNum)
            {
                cout << "Number -> " << token << endl;
            }
            else
            {

                bool isId = ((token[0] >= 'a' && token[0] <= 'z') ||
                             (token[0] >= 'A' && token[0] <= 'Z'));

                for (int j = 1; j < token.length() && isId; j++)
                {
                    if (!((token[j] >= 'a' && token[j] <= 'z') ||
                          (token[j] >= 'A' && token[j] <= 'Z') ||
                          (token[j] >= '0' && token[j] <= '9')))
                    {
                        isId = false;
                    }
                }

                if (isId)
                    cout << "Identifier -> " << token << endl;
                else
                    cout << "Lexical Error -> " << token << endl;
            }

            token = "";
        }
        else
        {
            token += input[i];
        }
    }
}

int main()
{
    string input = "cout << 20 + a * 60.5 ; @ 123abc";
    tokenize(input);
}
