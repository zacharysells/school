#include <iostream>
#include <fstream>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <sys/stat.h>
#include <cstdlib>
#include "timer.h"

using namespace std;

void get_put_copy(char * write, char * read)
{
	ofstream write_file;
	write_file.open(write);

	if(!write_file.good())
	{
		cout << "Error with write_file" << endl;
		exit(1);
	}
	
	ifstream read_file;
	read_file.open(read);
	
	if(!read_file.good())
	{
		cout << "Error with read_file" << endl;
		exit(1);
	}
	
	char c = read_file.get();
	while(!read_file.eof())
	{
		write_file.put(c);
		c = read_file.get();
	}
}

void unix_read_write(char * write_file, char * read_file)
{
	int fd_read, fd_write;
	
	fd_read = open(read_file, O_RDONLY);
	if(fd_read < 0)
	{
		cout << "Error with read_file" << endl;
		exit(1);
	}
	
	fd_write = open(write_file, O_RDWR | O_CREAT | O_TRUNC,  S_IREAD | S_IWRITE );
	if(fd_write < 0)
	{
		cout << "Error with write_file" << endl;
		exit(1);
	}
	
	int n;
	char buf[1];
	while(n = read(fd_read, buf, 1))
	{
		if(n < 0) 
		{
			cout << "FAILED" << endl;
			exit(1);
		}
		if(write(fd_write, buf, n) < 0) 
		{
			cout << "FAILED" << endl;
			exit(1);
		}
	}
	if(close(fd_read) < 0) cout << "Error closing read file. " << endl;
	if(close(fd_write) < 0) cout << "Error closing write file. " << endl;
}

void unix_read_write_bufsiz(char * write_file, char * read_file)
{
	int fd_read, fd_write;
	
	fd_read = open(read_file, O_RDONLY);
	if(fd_read < 0)
	{
		cout << "Error with read_file" << endl;
		exit(1);
	}
	
	fd_write = open(write_file, O_RDWR | O_CREAT | O_TRUNC,  S_IREAD | S_IWRITE );
	if(fd_write < 0)
	{
		cout << "Error with write_file" << endl;
		exit(1);
	}
	
	int n;
	char buf[BUFSIZ];
	while(n = read(fd_read, buf, BUFSIZ))
	{
		if(n < 0) 
		{
			cout << "FAILED" << endl;
			exit(1);
		}
		if(write(fd_write, buf, n) < 0) 
		{
			cout << "FAILED" << endl;
			exit(1);
		}
	}
	if(close(fd_read) < 0) cout << "Error closing read file. " << endl;
	if(close(fd_write) < 0) cout << "Error closing write file. " << endl;
}


//First param is file to read
//Second param is file to write to
//Third param is how many times to call each function
int main(int argc, char *argv[])
{
	if(argc < 3) 
	{
		cout << "Error, two arguments needed."<< endl;
		cout << "1st arg) File to read." << endl;
		cout << "2nd arg) File to write to." << endl;
		exit(1);
	}
	

	char * read_file = argv[2];
	char * write_file = argv[1];
	
	int n = 0;
	if(argc < 4) n = 1;
	else n = atoi(argv[3]);
	Timer t;
	double eTime;
	
	//Testing get_put_copy()
	cout << "Timing how long " << n << " function calls takes for get and put function..." << endl;
	t.start();
	for(int i = 0; i < n; i++)
	{
		get_put_copy(read_file, write_file);
	}
	t.elapsedWallclockTime(eTime);
	cout << "Elapsed Wall Clock Time: " << eTime << " seconds" << endl;
	t.elapsedUserTime(eTime);
	cout << "Elapsed User Time: " << eTime << " seconds" << endl;
	t.elapsedSystemTime(eTime);
	cout << "Elapsed System Time: " << eTime << " seconds" << endl << endl;
	
	//Testing unix_read_write()
	cout << "Timing how long " << n << " function calls takes for read and write function " 
	<< endl <<"one char at a time..." << endl;
	t.start();
	for(int i = 0; i < n; i++)
	{
		unix_read_write(read_file, write_file);
	}
	t.elapsedWallclockTime(eTime);
	cout << "Elapsed Wall Clock Time: " << eTime << " seconds" << endl;
	t.elapsedUserTime(eTime);
	cout << "Elapsed User Time: " << eTime << " seconds" << endl;
	t.elapsedSystemTime(eTime);
	cout << "Elapsed System Time: " << eTime << " seconds" << endl << endl;
	
	
	//Testing unix_read_write_bufsiz()
	cout << "Timing how long " << n << " function calls takes for read and write function " 
	<< endl << "one buffer(BUFSIZ) at a time..." << endl;
	t.start();
	for(int i = 0; i < n; i++)
	{
		unix_read_write_bufsiz(read_file, write_file);
	}
	t.elapsedWallclockTime(eTime);
	cout << "Elapsed Wall Clock Time: " << eTime << " seconds" << endl;
	t.elapsedUserTime(eTime);
	cout << "Elapsed User Time: " << eTime << " seconds" << endl;
	t.elapsedSystemTime(eTime);
	cout << "Elapsed System Time: " << eTime << " seconds" << endl << endl;
	
	
	
	
	return 0;
}
