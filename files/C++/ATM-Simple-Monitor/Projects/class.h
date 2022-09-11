#ifndef _CLASS_H_
#define _CLASS_H_
#include <iostream>
#include <string>
#include <fstream>
using namespace std;
class ATM
{
private:
    string accoutNunmber;
    string password;
    int balance;
    char name[20];
    int time=0;
    int locks=0;
    void wrongpw(){time+=1;};
public:
    void showmeun();
    void showaccout();
    int showlock();
    void show();
    void unlock();
    void lockagain();
    void setpassword(string x) ;
    void setbalance(int x);
    void Proofreadpassword();
    void jugepassword();
    void get_password(string filenamed);
    void get_balance(string filenamed);
    void addbalance(int x,string filename);
    void cutbalance(int x,string filename);
    void write_in_add(string filename,int x,int y);
    void write_in_cut(string filename,int x,int y);
    void transfer(int x,string filename1,string filename2);
    void changep(string filename);
};
#endif