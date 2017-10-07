//
//  main.cpp
//  PRG-5-16-Savings-Account-Balance
//
//  Created by Keith Smith on 10/7/17.
//  Copyright © 2017 Keith Smith. All rights reserved.
//
//
//  Write a program that calculates the balance of a savings account at the end of a period
//  of time. It should ask the user for the annual interest rate, the starting balance, and the
//  number of months that have passed since the account was established. A loop should
//  then iterate once for every month, performing the following:
//
//  A. Ask the user for the amount deposited into the account during the month. (Do not
//  accept negative numbers.) This amount should be added to the balance.
//  B. Ask the user for the amount withdrawn from the account during the month. (Do
//  not accept negative numbers.) This amount should be subtracted from the balance.
//  C. Calculate the monthly interest. The monthly interest rate is the annual interest rate
//  divided by 12. Multiply the monthly interest rate by the balance, and add the result
//  to the balance.
//
//  After the last iteration, the program should display the ending balance, the total
//  amount of deposits, the total amount of withdrawals, and the total interest earned.

#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    int intInterestAnnual,
        intMonthsCount;
    
    float fltBalanceTotal = 0,
          fltBalanceDeposit = 0,
          fltBalanceDepositTotal = 0,
          fltBalanceWithdrawl = 0,
          fltBalanceWithdrawlTotal = 0,
          fltBalanceInterest = 0,
          fltBalanceInterestTotal = 0,
          fltInterestMonthly = 0;
    
    // Set for precision for dollar output
    cout << setprecision(2) << fixed << showpoint;
    
    cout << "Please enter your annual interest rate in whole numbers (5%, 10%, 15%, etc.):\n";
    cin >> intInterestAnnual;
    
    while(!cin || intInterestAnnual <= 0 || intInterestAnnual > 100)
    {
        cout << "Please enter an interest rate between 1% and 100%\n";
        cin.clear();
        cin.ignore();
        cin >> intInterestAnnual;
    }
    
    // Convert whole number interest to fractional amount for use in calculations
    fltInterestMonthly = static_cast<float>(intInterestAnnual) / 100.0f;
    
    cout << "Please enter the starting balance of this account:\n";
    cin >> fltBalanceTotal;
    
    while(!cin || fltBalanceTotal < 0.0f || fltBalanceTotal > 1000000.0f)
    {
        cout << "Please enter a balance amount between $0.00 and $1000000:\n";
        cin.clear();
        cin.ignore();
        cin >> fltBalanceTotal;
    }
    
    cout << "Please enter the number of months since the account was established:\n";
    cin >> intMonthsCount;
    
    while(!cin || intMonthsCount <= 0 || intMonthsCount > 12)
    {
        cout << "Please select from 1 to 12 months as your value:\n";
        cin.clear();
        cin.ignore();
        cin >> intMonthsCount;
    }
    
    // Depending on number of months account has been open, this loop gets
    // deposits and withdrawls once for each month
    for(int i = 0 ; i < intMonthsCount ; i++)
    {
        cout << "Please enter the amount deposited during this month:\n";
        cin >> fltBalanceDeposit;
        
        while(!cin || fltBalanceDeposit < 0.0f || fltBalanceDeposit > 10000000.0f)
        {
            cout << "Please enter a positive value for the amount deposited:\n";
            cin.clear();
            cin.ignore();
            cin >> fltBalanceDeposit;
        }
        
        cout << "Please enter the amount withdrawn during this month:\n";
        cin >> fltBalanceWithdrawl;
        
        while(!cin || fltBalanceWithdrawl < 0.0f || fltBalanceWithdrawl > 10000000.0f)
        {
            cout << "Please enter a positive value for the amount withdrawn:\n";
            cin.clear();
            cin.ignore();
            cin >> fltBalanceWithdrawl;
        }
        
        // Keep running totals inside the for loop
        fltBalanceTotal += fltBalanceDeposit;
        fltBalanceTotal -= fltBalanceWithdrawl;
        
        fltBalanceInterest = fltBalanceTotal * fltInterestMonthly;
        
        fltBalanceTotal += fltBalanceInterest;
        
        fltBalanceDepositTotal += fltBalanceDeposit;
        fltBalanceWithdrawlTotal += fltBalanceWithdrawl;
        fltBalanceInterestTotal += fltBalanceInterest;
    }
    
    // Output formatted calculated values
    cout << setw(42) << "Your total balance after " << intMonthsCount << " months is\n"
         << setw(42) << "$" << fltBalanceTotal << endl
         << setw(42) << "You deposited $" << fltBalanceDepositTotal << endl
         << setw(42) << "You withdrew $" << fltBalanceWithdrawlTotal << endl
         << setw(42) << "And earned interest totaling $" << fltBalanceInterestTotal << endl;
    
    return 0;
}

