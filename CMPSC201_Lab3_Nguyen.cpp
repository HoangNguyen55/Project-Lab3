#include <iostream>
#include <math.h>
#include <ctype.h>
#include <fstream>
#include <iomanip>
using namespace std;

double N_shares, P_shares, P_commission, A_return, Year;
double totalPaidNoComs, totalComsFee, totalPaid, totalTenYears;
char input;

int main()
{
    ifstream txt_input ("input.txt");
    if(!txt_input)
    {
        cout << "Error file can't be open";
    }
    txt_input >> N_shares;
    txt_input >> P_shares;
    txt_input >> P_commission;
    txt_input >> A_return;
    txt_input >> Year;
    txt_input.close();

    totalPaidNoComs = N_shares*P_shares;
    cout << "The amount you paid for the stock alone (without the commission): " << totalPaidNoComs << "\n";
    totalComsFee = (P_commission/100) * totalPaidNoComs;
    cout << "The amount of the commission fee: " << totalComsFee << "\n";
    totalPaid = totalComsFee + totalPaidNoComs;
    cout << "The total amount you paid(Coms fee incl): " << totalComsFee + totalPaidNoComs << "\n";
    totalTenYears = totalPaidNoComs * pow(1 + A_return/100, Year);
    cout << "After 10 years, all of your shares will worth: " << totalTenYears << "\n";
    
    cout << "Would you like a receipt? Y/N";
    cin >> input;
    if(tolower(input) == 'y')
    {
        ofstream output;
        output << setw(10) << "Hoang Nguyen";
    } 
    else if (tolower(input) == 'n') 
    {
        cout<<"Have a nice day";
    }

    return 0;
}