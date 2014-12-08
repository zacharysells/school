#include <iostream>
#include <sys/stat.h>
#include <dirent.h>
#include <errno.h>
#include <cstdio>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <stdint.h>
#include <algorithm>
#include <vector>
#include <iomanip>
using namespace std;

static int tab_delimeter = 0;

void print_dir(const string &s);
void print_inOrder(vector<string> v);


string min(const string &a, const string &b)
{
    if(a.size() > b.size()) return b;
    
    return a;
}

string order(const string &a, const string &b) //Returns which comes first
{
    for(unsigned i = 0; i < min(a, b).size(); i++)
    {
        if(a[i] > b[i]) return b;
        if(a[i] < b[i]) return a;
    }
    return min(a,b);
}

struct less_than_key
{
    inline bool operator() (const dirent * a, const dirent * b)
    {
        return order(a->d_name,b->d_name) == a->d_name;
    }
};

//Prints vector of files/directories in order.
void print_inOrder(vector<dirent*> v,string parent_dir)
{
	struct stat buf;
	DIR* test_directory;
	sort(v.begin(), v.end(), less_than_key());
	
	for(int i = 0; i < v.size(); ++i)
	{
		string full_name = parent_dir + "/" + v[i]->d_name;
		string temp = ctime(&buf.st_mtime);
		temp = temp.substr(0,temp.size()-1);
		
		for(int e = 0; e < tab_delimeter; e++) cout << "\t";
		if(test_directory = opendir(full_name.c_str()))
		{
			//Text formatting//
			stat(full_name.c_str(), &buf);
			cout << ((S_ISDIR(buf.st_mode)) ? "d" : "-");
			cout << ((buf.st_mode & S_IRUSR) ? "r" : "-");
			cout << ((buf.st_mode & S_IWUSR) ? "w" : "-");
			cout << ((buf.st_mode & S_IXUSR) ? "x" : "-");
			cout << ((buf.st_mode & S_IRGRP) ? "r" : "-");
			cout << ((buf.st_mode & S_IWGRP) ? "w" : "-");
			cout << ((buf.st_mode & S_IXGRP) ? "x" : "-");
			cout << ((buf.st_mode & S_IROTH) ? "r" : "-");
			cout << ((buf.st_mode & S_IWOTH) ? "w" : "-");
			cout << ((buf.st_mode & S_IXOTH) ? "x" : "-");
			
			cout << " " << buf.st_nlink << " ";
			cout << (intmax_t)buf.st_size;
			cout << " " << temp << " " << v[i]->d_name << endl;
			//End formatting//
			
			tab_delimeter++;
			print_dir(parent_dir + "/" + v[i]->d_name);
			tab_delimeter--;
			
		}
		else
		{
			stat(full_name.c_str(), &buf);
						//Text formatting//
			stat(full_name.c_str(), &buf);
			cout << ((S_ISDIR(buf.st_mode)) ? "d" : "-");
			cout << ((buf.st_mode & S_IRUSR) ? "r" : "-");
			cout << ((buf.st_mode & S_IWUSR) ? "w" : "-");
			cout << ((buf.st_mode & S_IXUSR) ? "x" : "-");
			cout << ((buf.st_mode & S_IRGRP) ? "r" : "-");
			cout << ((buf.st_mode & S_IWGRP) ? "w" : "-");
			cout << ((buf.st_mode & S_IXGRP) ? "x" : "-");
			cout << ((buf.st_mode & S_IROTH) ? "r" : "-");
			cout << ((buf.st_mode & S_IWOTH) ? "w" : "-");
			cout << ((buf.st_mode & S_IXOTH) ? "x" : "-");
			
			cout << " " << buf.st_nlink << " ";
			cout << (intmax_t)buf.st_size;
			cout << " " << temp << " " << v[i]->d_name << endl;
			//End formatting//
		}
		
	}
}

//Passes vector of files/folders in given directory to above function
void print_dir(const string &s)
{
	vector<dirent *> v;
	DIR* directory;
	directory = opendir(s.c_str());
	dirent * inner_dir;
	while(inner_dir = readdir(directory))
    {	
		if(inner_dir->d_name[0] == '.') continue;
		v.push_back(inner_dir);
	}
	print_inOrder(v,s);
	
}


int main(int argc, char* argv[])
{
	
	string s = ".";
	
	if(argc == 1)
	{
		s = ".";
		print_dir(s.c_str());
		return 0;
	}
	DIR* directory;
	directory = opendir(s.c_str());
	
	
	for(int i = 1; argv[i] != NULL; i++)
	{
		s = argv[i];
		if(directory = opendir(s.c_str()))
		{
			cout << argv[i] << ":" << endl;
			print_dir(s.c_str());
		}
		
		else if(directory = opendir(s.c_str()))
		{
			cout << s << ":" << endl;
			print_dir(s.c_str());
		}
		
		else
		{
			struct stat buf;
			if(stat(argv[i], &buf) == -1)
				cout << "Error Opening: " << argv[i] << endl;
			
			else
			cout << oct << buf.st_mode << " " << buf.st_nlink << " " << buf.st_size << " "
			<< buf.st_mtime << " " << argv[i] << endl;
		}
	}
	
	return 0;
}
