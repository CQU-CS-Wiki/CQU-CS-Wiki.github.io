//file_main.cpp
#include "file.cpp"
using namespace std;

int main(int argc,char **argv)
{
	cout<<"####################################################"<<endl;
	cout<<"          Welcome to the file manager"<<endl;
	cout<<"####################################################"<<endl;
	cout<<"\n[options]:"<<endl<<endl;
	cout<<"        [md]  :make dictionary"<<endl;
	cout<<"        [rd]  :remove dictionary"<<endl;
	cout<<"        [cd]  :change dictionary "<<endl;
	cout<<"        [ld]  :list dictionary"<<endl;
	cout<<"        [cp]  :copy"<<endl;
	cout<<"        [rf]  :remove file"<<endl;
	cout<<"        [q]   :quit"<<endl;
	cout<<"-----------------------------------------------------"<<endl;
	cout<<"-";
	
	string Line;
	vector<string> Args;
	
	getline(cin,Line);	
	Args = str_split(Line);
	
	file one(Args);
	
	while(Args.size() && Args[0] != "q")
	{
		if(Args[0] == "md")
		{			
			one.md() ;
		}
		else if(Args[0] == "rd")
		{
			one.rd() ;
		}
		else if(Args[0] == "rf")
		{
			one.rf() ;
		}
		else if(Args[0] == "cd")
		{
			one.cd() ;
		}
		else if(Args[0] == "ld")
		{
			one.ld() ;
		}
		else if(Args[0] == "cp")
		{
			one.cp();
		}
		else
		{
			cout<<"error: error command"<<endl;
		}
		
		cout<<"-----------------------------------------------------"<<endl;
		cout<<"-";
		
		getline(cin,Line);	
		Args = str_split(Line);
		one.value = Args;

	}
	
	return 0;
}






