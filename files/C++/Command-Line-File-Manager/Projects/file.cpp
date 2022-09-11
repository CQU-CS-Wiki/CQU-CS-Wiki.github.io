//file.cpp
#include "file.h"

vector<string> str_split(string s)			
{
	string x;
	vector<string> res;	
	istringstream stream(s);
	stream >> x;
	res.push_back(x);
	while(stream >> x){
		res.push_back(x);
	}
    
    
    return res;
}

vector<string> value;

void file::md(){

			if(value.size()<2)
			{
				cout<<"error: please enter the name of dictionary"<<endl;
			}
			else
			{
				string dirName = value[1];
		    	mode_t mode = 0775;
		    	if(mkdir(dirName.c_str(),mode) == 0)
    			{
    				cout<<"make dictionary‘"<<dirName<<"’succeeded"<<endl;
    			}
    			else
    			{
    				cout<<"error: make dictionary‘"<<dirName<<"’failed"<<endl;
    			}
			}	
}

void file::rd(){

			if(value.size() < 2)
			{
				cout<<"error: please enter the name of dictionary"<<endl;
			}
			else
			{
				string dirName = value[1];
				if(rmdir(dirName.c_str()) == 0 )
				{
					cout<<"remove dictionary‘"<<dirName<<"’succeeded"<<endl;
				}
    			else
    			{
    				cout<<"error:remobve dictionary‘"<<dirName<<"’failed"<<endl;
    			}	
    		}
}

void file::rf(){
	
			if(value.size()<2)
			{
				cout<<"error: please enter the name of file"<<endl;
			}
			else
			{
				string fileName = value[1];
				if(remove(fileName.c_str()) == 0 )
				{
					cout<<"remove file‘"<<fileName<<"’succeeded"<<endl;
				}
    			else
    			{
    				cout<<"error: remove file‘"<<fileName<<"’failed"<<endl;
    			}	
			}
}


void file::cd(){

			if(value.size()<2)
			{
				cout<<"error: please enter the name of dictionary"<<endl;
			}
			else
			{
				string dirName = value[1];
				if(chdir(dirName.c_str())==0)
    			{
    				char curDir[300];
    				getcwd(curDir,300);
    				cout<<"changed the dictionary to"<<curDir<<endl;
    			}
    			else
    			{
    				cout<<"error: failed to change the dictioanry."<<endl;
    			}
			}
}

void file::ld(){

		DIR * curDir;
		struct dirent *ent;
		struct stat entStat;
		if((curDir=opendir("."))==NULL)
    	{
    		cout<<"error: failed to open the dictionary"<<endl;
    	}
    	else
    	{
			while((ent=readdir(curDir)) != NULL)
			{   			
				if(stat(ent->d_name, &entStat) == 0)
				{
					if(entStat.st_mode & S_IFDIR)
					{
						cout<<setw(6)<<left<<"d";
						cout<<right<<setw(10)<<entStat.st_size<<left<<setw(8)<<" bytes";
						cout<<ent->d_name<<"/"<<endl;
					}
					else if(entStat.st_mode & S_IFREG)
					{
						cout<<setw(6)<<left<<"-";
						cout<<right<<setw(10)<<entStat.st_size<<left<<setw(8)<<" bytes";
						cout<<ent->d_name<<endl;
					}						
	   			}	   			 	
			}
			closedir(curDir);
    	}
}

void file::cp(){

			if(value.size() < 3)
			{
				cout<<"error: Please enter the source file / folder name and the destination file / folder name"<<endl;
			}
			else
			{
				string sourceFileName = value[1];
				string targetFileName = value[2];
				ifstream sourceFile(sourceFileName.c_str(), ios::binary);
				ofstream targetFile(targetFileName.c_str(), ios::binary);
				targetFile<<sourceFile.rdbuf();
				targetFile.close();
				sourceFile.close();
				cout<<"copy succeeded."<<endl;			
			}
}
