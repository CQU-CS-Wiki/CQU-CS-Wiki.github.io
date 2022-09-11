#include <iostream>
#include "class.h"
#include "function.h"

int main()
{
    ATM one;
    string filename;
    while (1)
    {
        one.showmeun();
        cin >> filename;
        filename=filename+".txt";
        ifstream in;
        in.open(filename);
        if (!in)
        {
            cout<<"This account does not exist"<<endl;
            in.close();
        }
        else
        {
            in.close();
            break;
        }
    }
    
    one.get_password(filename);
    one.get_balance(filename);
    one.Proofreadpassword();
    
    while(one.showlock()==1)
    {
        int nu;
        one.show();
        cin >> nu;
        switch(nu){
            case 1:
            {
                one.showaccout();
                break;
            }
            case 2:
            {
                int x;
                cout<<"-------------------------------------------------"<<endl;
                cout<<"Please enter the amount to be withdrawn (*100): ";
                cin >>x;
                one.cutbalance(x,filename);
                break;
            }
            case 3:
            {
                int x;
                cout<<"-------------------------------------------------"<<endl;
                cout <<"Please enter the amount to be deposit (*100): ";
                cin >>x;
                one.addbalance(x,filename);
                break;
            }
            case 4:
            {
                cout<<"-------------------------------------------------"<<endl;
                cout <<"Please enter the transfer account number: ";
                string filename1,filename2;
                cin >> filename1;
                filename1=filename1+".txt";
                ifstream ine;
                ine.open(filename1);
                if (!ine)
                {
                    cout<<"This account does not exist"<<endl;
                    ine.close();
                }
                else{
                    cout<<"Please enter the number of transfers (*100): ";
                    int num;
                    cin >>num;
                    cout <<"Please enter the transfer account number again: ";
                    cin >>filename2;
                    filename2=filename2+".txt";
                    if (filename1!=filename2)
                    {
                        cout <<"The account number entered twice is different."<<endl;
                    }
                    else{
                    one.transfer(num,filename1,filename);
                    }
                }
                break;
            }
            case 5:
            {
                cout<<"-------------------------------------------------"<<endl;
                one.changep(filename);
                break;
            }
            case 6:
            {
                cout <<"Thanks for using. "<<endl;
                return 0;
                
            }
            default:
            {
                cout<<"-------------------------------------------------"<<endl;
                cout<<"Please enter a valid number. ";
                break;
            }
            }
        
        
        
    }
    cout <<"Thanks for using. "<<endl;
    return 0;
}