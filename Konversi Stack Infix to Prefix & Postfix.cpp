#include <iostream>
#include <stack>
#include <string>
#include <algorithm>

using namespace std;

bool Op(char c)
{
    if (c == '+' || c == '-' || c == '*' || c == '/' || c == '^')
        return true;
    return false;
}

int Operator(char c)
{
    if (c == '^')
        return 3;
    else if (c == '*' || c == '/')
        return 2;
    else if (c == '+' || c == '-')
        return 1;
    else
        return 0;
}

// InfixkePrefix
string InfixKePrefix(string infix)
{
    string prefix;
    stack<char> stack;

    reverse(infix.begin(), infix.end());

    for (char &c : infix)
    {
        if (c == ' ' || c == ',')
            continue;
        else if (Op(c))
        {
            while (!stack.empty() && Operator(stack.top()) > Operator(c))
            {
                prefix += stack.top();
                stack.pop();
            }
            stack.push(c);
        }
        else if (c == ')')
        {
            stack.push(c);
        }
        else if (c == '(')
        {
            while (!stack.empty() && stack.top() != ')')
            {
                prefix += stack.top();
                stack.pop();
            }
            stack.pop();
        }
        else
        {

            prefix += c;
        }
    }

    while (!stack.empty())
    {
        prefix += stack.top();
        stack.pop();
    }

    reverse(prefix.begin(), prefix.end());

    return prefix;
}

// InfixkePostfix
string infixToPostfix(const string &infix)
{
    string postfix;
    stack<char> stack;

    for (char c : infix)
    {
        if (isalnum(c))
        {

            postfix += c;
        }
        else if (c == '(')
        {

            stack.push(c);
        }
        else if (c == ')')
        {

            while (!stack.empty() && stack.top() != '(')
            {
                postfix += stack.top();
                stack.pop();
            }

            if (!stack.empty())
            {
                stack.pop();
            }
        }
        else if (Operator(c))
        {

            while (!stack.empty() && stack.top() != '(' && Operator(stack.top()) >= Operator(c))
            {
                postfix += stack.top();
                stack.pop();
            }

            stack.push(c);
        }
    }

    while (!stack.empty())
    {
        postfix += stack.top();
        stack.pop();
    }

    return postfix;
}

int main()
{
    char ulang;

    do
    {
        int pilih;

        cout << "==========\tMenu Utama\t==========" << endl;
        cout << "1.\tInfix to Prefix" << endl;
        cout << "2.\tInfix to Postfix" << endl;
        cout << "==================================" << endl;
        cout << "Masukkan Pilihan Anda: ";
        cin >> pilih;
        cin.ignore();

        if (pilih == 1)
        {

            cout << "\n==========\tInfix to Prefix\t==========" << endl;
            string infixExpression;
            cout << "Masukkan ekspresi infix: ";
            getline(cin, infixExpression);

            string prefixExpression = InfixKePrefix(infixExpression);

            cout << "Ekspresi prefix: " << prefixExpression << endl;
        }

        if (pilih == 2)
        {
            cout << "==========\tInfix to Postfix\t==========" << endl;
            string infixExpression;
            cout << "Masukkan ekspresi infix: ";
            getline(cin, infixExpression);

            string postfixExpression = infixToPostfix(infixExpression);
            cout << "Ekspresi postfix: " << postfixExpression << endl;
        }

        cout << "Apakah ingin mengulang lagi? (y/n): ";
        cin >> ulang;

    } while (ulang == 'y' || ulang == 'Y');

    return 0;
}