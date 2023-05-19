#include <iostream>
#include <string>
using namespace std;

class node
{
public:
	int noMhs;
	char nama[20];
	node* next;
};

class list
{
	node* start;
	public :
		list();
		void addNode();
		bool search(int nim, node** current, node** previous);
		bool listempty();
		bool delnode(int element);
		void traverse();
};

list::list()
{
	start = NULL;
}

