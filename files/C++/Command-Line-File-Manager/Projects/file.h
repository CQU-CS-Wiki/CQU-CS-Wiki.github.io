//file.h
#ifndef FILE_H
#define FILE_H
#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <dirent.h>

using namespace std;

class file
{
	public:
	
		
		void md();
		void rd();
		void rf();
		void cd();
		void ld();
		void cp();
		vector <string> value;
		file(vector <string> value){
			this -> value = value;
		}
		
};

#endif