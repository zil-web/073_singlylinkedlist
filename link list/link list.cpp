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
	node* START;
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
	START = NULL;
}
void list::addNode()/*menambah sebuah node kedalam list*/
{
	int nim;
	char nm[20];
	cout << "\nMasukkan nomor mahasiswa: ";
	cin >> nim;
	cout << "\nMasukkan nama: ";
	cin >> nim;

	node* nodeBaru = new node;
	nodeBaru->noMhs = nim;
	strcpy_s(nodeBaru->nama, nm);

	if (START == NULL || nim <= START->noMhs)
	{
		if ((START == NULL || nim <= START->noMhs)){
			cout << "\nDuplikasi noMhs tidak diijinkan\n";
			return;
		}
		nodeBaru->next = START;
		START = nodeBaru;
		return;
	}
	node* previous, * current;

	current = START;
	previous = START;

	while ((current != NULL) && (nim >= current->noMhs))
	{
		if (nim == current->noMhs)
		{
			cout << "\nDuplikasi noMhs tidak diijinkan\n";
			return;
		}
		previous = current;

	}
			
			

}
