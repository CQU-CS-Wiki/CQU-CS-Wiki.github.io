#include "class.h"
void ATM::showmeun()
{
    cout<<"plesae input the account number: ";
}
void ATM::setpassword(string x)
{
    password=string(x.begin(),x.begin()+6);
}
void ATM::setbalance(int x)
{
    balance=x;
}
void ATM::unlock()
{
    locks=1;
}
void ATM::lockagain()
{
    locks=0;
}
void ATM::Proofreadpassword()
{
    string number1;
    while(time<=3){
    cout << "please input password: ";
    cin >> number1;
    if (number1!=password)
    {
        cout <<"Password is wrong, you have "<< 3-time << " times can try again."<<endl;
        wrongpw();
    }
    else
    {
        unlock();
        break;
    }
    }
    if (time>3)
    {
        cout <<"Your account is locked."<<endl;
    }
}
void ATM::show()
{
    cout<<"Main menu:"<<endl;
    cout<<"    1 - View my balance"<<endl;
    cout<<"    2 - Withdraw cash"<<endl;
    cout<<"    3 - Desposit funds"<<endl;
    cout<<"    4 - Transfer accounts"<<endl;
    cout<<"    5 - Change password"<<endl;
    cout<<"    6 - Exit"<<endl;
    cout<<"Enter a choice:";
}

void ATM::get_password(string filename)
{
    ifstream in;
    in.open(filename);
    char inpassword[20];
    int line=1;
    while (in.getline(inpassword,20))
    {
        if (line==4)
        {
            break;
        }
        line++;
    }
    string password1;
    password1=inpassword;
    setpassword(password1);
    in.close();
}
void ATM::get_balance(string filename)
{
    ifstream in;
    in.open(filename);

    int balance1,line=1;
    string y;
    while (getline(in,y))
    {
        if (line==5)
        {
            break;
        }
        line++;
    }
    balance1=atoi(y.c_str());
    setbalance(balance1);
    in.close();
}
void ATM::addbalance(int x,string filename)
{
    balance=balance+x*100;
    write_in_add(filename,x,balance);
    cout <<"balance is: "<<balance<<endl;
}
void ATM::cutbalance(int x,string filename)
{
    if (balance<x*100)
    {
        cout << "Sorry, your credit is running low."<<endl;
    }
    else
    {
        balance=balance-x*100;
        write_in_cut(filename,x,balance);
    }
    
}
void ATM::write_in_add(string filename,int x,int y)
{
        ifstream ind;
        ind.open(filename);
        string strFileData = "";
	    int line = 1;
	    char lineData[1024] = {0};
	    while(ind.getline(lineData, sizeof(lineData)))
	    {
		
        if (line==5)
        {
            strFileData += to_string(y);
			strFileData += "\n";
        }
        else{
            string n;
            n=lineData;
			strFileData += n;
			strFileData += "\n";
        }
		    line++;
	    }
        strFileData =strFileData + "add deposit is: "+ to_string(x*100) +"\n"+"balance becomes: "+to_string(y)+"\n";
        ind.close();

        ofstream out;
	    out.open(filename);
	    out.flush();
	    out<<strFileData;
	    out.close();
    

}
void ATM::write_in_cut(string filename,int x,int y)
{
    ifstream ind;
        ind.open(filename);
        string strFileData = "";
	    int line = 1;
	    char lineData[1024] = {0};
	    while(ind.getline(lineData, sizeof(lineData)))
	    {
		    if (line==5)
        {
            strFileData += to_string(y);
			strFileData += "\n";
        }
        else
        {
            string n;
            n=lineData;
			strFileData += n;
			strFileData += "\n";
        }
		    line++;
	    }
        strFileData =strFileData + "take out deposit is: "+ to_string(x*100) +"\n"+"balance becomes: "+to_string(y)+"\n";
        ind.close();

        ofstream out;
	    out.open(filename);
	    out.flush();
	    out<<strFileData;
	    out.close();
    cout <<"balance is: "<<y<<endl;
}
void ATM::showaccout()
{
    cout <<"you accout is: "<<balance<<endl;
}
int ATM::showlock()
{
    return locks;
}
void ATM::transfer(int x,string filename1,string filename2)
{
    filename1=filename1;
    ifstream ind;
        ind.open(filename1);
        string strFileData = "";
	    int line = 1,y;
	    char lineData[1024] = {0};
	    while(ind.getline(lineData, sizeof(lineData)))
	    {
		
        if (line==5)
        {
            y=atoi(lineData);
            y=x*100+y;
			
        }
        line++;
        }
        ind.close();
        write_in_add(filename1,x,y);

    if (balance<x*100)
    {
        cout << "Sorry, your credit is running low."<<endl;
    }
    else
    {
        balance=balance-x*100;
        write_in_cut(filename2,x,balance);
    }
    
}
void ATM::changep(string filename)
{
    int x,y;
    cout <<"Please input your new password: ";
    cin >> x;
    while(true)
    {
        if (x<100000||x>999999)
        {
            cout <<"Please enter six digits. "<<endl;
        }
        else
        {
            break;
        }
        cout <<"Please input your new password: ";
        cin >> x;
    }
    cout <<"Please input your new password again: ";
    cin >> y;
    if (x!=y)
    {
        cout <<"The two passwords are different. "<<endl;
    }
    else
    {
        ifstream ind;
        ind.open(filename);
        string strFileData = "";
	    int line = 1;
	    char lineData[1024] = {0};
	    while(ind.getline(lineData, sizeof(lineData)))
	    {
		    if (line == 4)
		    {
                strFileData +=to_string(x);
			    strFileData += "\n";
		    }
		    else
		    {
                string n;
                n=lineData;
			    strFileData += n;
			    strFileData += "\n";
		    }
		    line++;
	    }
        ind.close();

        ofstream out;
	    out.open(filename);
	    out.flush();
	    out<<strFileData;
	    out.close();
        cout <<"Password modified successfully"<<endl;
    }
    
    
}