#include <iostream>
#include <math.h>
#include <ctype.h>
#include <fstream>
#include <iomanip>
using namespace std;

double N_shares, P_shares, P_commission, A_return, Year;
double totalPaidNoComs, totalComsFee, totalPaid, totalYears;
char input;

int main()
{
    ifstream txt_input ("sample.txt");
    if(!txt_input)
    {
      cout << "Error file can't be open\n";
      return 1;
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
    totalYears = totalPaidNoComs * pow(1 + A_return/100, Year);
    cout << "After 10 years, all of your shares will worth: " << totalYears << "\n";
    
    cout << "Would you like a receipt? Y/N\n";
    cin >> input;
    if(tolower(input) == 'y')
    {
        ofstream output("receipt.txt");
        if(!output){cout<<"Trying to write fail."; return 1;}
        output << setfill(' ') << setw(30) << left << "Hoang Nguyen";
        output << setfill('-') << setw(42) << "\n-";
        output << setfill(' ') << setw(31) << "\nTotal Stock: " << setprecision(2) << fixed << right << setw(1) << "$" << setw(10) << totalPaidNoComs << "\n";
        output << setw(30) << left << "Commission: " << right << setw(1) << "$" << setw(10) << totalComsFee << "\n";
        output << setw(30) << left << "Total amount: " << right << setw(1) << "$" << setw(10) << totalPaid << "\n";
        string str = "Net worth in " + to_string((int)Year) + " years: ";
        output << setw(30) << left << str << right << setw(1) << "$" << setprecision(2) << setw(10) << totalYears << "\n";
        cout << "Receipt printed";
        output.close();
    } 
    else
    {
        cout<<"Have a nice day";
    }

    return 0;
}