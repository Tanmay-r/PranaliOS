#include <iostream>
using namespace std;

int main(){
	syscall(408, "root/d1");
	syscall(408, "root/d2");
	syscall(408, "root/d3");
	syscall(408, "root/d4");
	syscall(408, "root/d5");
	syscall(408, "root/d5/d6");

	int file = syscall(402, "root/d2/f1", 'w');
	syscall(405, file, "hello", 6);
	syscall(403, file);

	file = syscall(402, "root/d1/f2", 'w');
	syscall(405, file, "hello", 6);
	syscall(403, file);

	file = syscall(402, "root/d1/f3", 'w');
	syscall(405, file, "hello", 6);
	syscall(403, file);

	file = syscall(402, "root/d1/f4", 'w');
	syscall(405, file, "hello", 6);
	syscall(403, file);

	file = syscall(402, "root/d5/d6/f5", 'w');
	syscall(405, file, "hello", 6);
	syscall(403, file);

	syscall(411, "root/d2/f1", 0);

	file = syscall(402, "root/d5/d6/f6", 'w');
	syscall(405, file, "hello", 6);
	syscall(403, file);

	cout<< "WRITE DONE\n";
	file = syscall(402, "root/d2/f1", 'r');
	char data[500];
	syscall(404, file, data, 6);
	cout<<data<<"  here I am.  "<<file<<endl;
	syscall(403, file);

	syscall(409, "root");
	// syscall(409, "root/d1/f1");
	syscall(409, "root/d1");

	syscall(410, "root/d2");
	file = syscall(402, "f8", 'w');
	syscall(405, file, "whats", 5);
	syscall(403, file);

	file = syscall(402, "f8", 'a');
	syscall(405, file, "world", 6);
	syscall(403, file);

	file = syscall(402, "f8", 'r');
	syscall(404, file, data, 11);
	cout<<data<<"  here I am.  "<<file<<endl;
	syscall(403, file);
	syscall(409, "f8");

	return 0;
}