#include <iostream>
#include <string>
#include <cmath>

using namespace std;

double fracValue(string frac)
{
    double sum = 0;
    
    for(int i =0; i < frac.length(); i++)
    {
        if(frac[i] == '1')
        {
            sum += (1.0) / pow(2, i);
        }
    }
    
    return sum;
}

int expValue(string exp)
{
    int sum = 0;
    
    for(int i =0; i < exp.length(); i++)
    {
        if(exp[i] == '1')
        {
            sum += pow(2, exp.length() - (i + 1));
        }
    }
    
    return sum;
}

bool checkInfinity(string exp, string frac)
{
    if (exp.find('0') == string::npos)
        if(frac.find('1') == string::npos)
            return true;
            
    return false;
}

bool checkNaN(string exp, string frac)
{
    if (exp.find('0') == string::npos)
        if(frac.find('1') != string::npos)
            return true;
            
    return false;
}

bool check0(string in)
{
    if(in.find('1') == string::npos)
        return true;
        
    return false;      
}

int main()
{
    int bias, e;
    string exp, frac;
    int expV;
    double fracV;
    
    double answer;
    
    bool normalized;
    bool signbit;
    
    cout << "Welcome to the floating point interpreter!" << endl;
    
    cout << "Please enter the sign bit of the number: ";
    cin >> signbit;
    
    cout << "Please enter the exponent bits: ";
    cin >> exp;
    
    cout << "Please enter the fraction bits: ";
    cin >> frac;
    
    cout << "The binary representation is: ";
    cout << signbit << exp << frac << endl;
    
    if(checkInfinity(exp, frac))
    {
        cout << "Value: infinity";
        cin.ignore();
        cin.ignore();
        
        return 0;
    }
    
    if(checkNaN(exp, frac))
    {
        cout << "Value: NaN";
        cin.ignore();
        cin.ignore();
        
        return 0;
    }
    
    bias = pow(2, exp.length() - 1) - 1;
    expV = expValue(exp);
    fracV = fracValue(frac);
    
    if(expV == 0)
        e = 1 - bias;
    else
        e = expV - bias;
        
    answer = (-(int)signbit) * (fracV + (int)check0(frac)) * pow(2, e);
    
    cout << "Value: " << answer << endl;
    cin.ignore();
    cin.ignore();
    
}
