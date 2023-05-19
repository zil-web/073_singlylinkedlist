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
		current = current->next;


	}
		/*jika Loop diatas dieksekusi, previous dan current akan menempati posisi dimana*/
	nodeBaru->next = current;
	previous->next = nodeBaru;			

}

bool list::search(int nim, node** previous, node** current)
{
	if (START == NULL)
		return true;
	else
		return false;	
}
bool list::delnode(int nim)/*menghapus node dari dalam list*/
{
	node* current, * previous;
	if (search(nim, &previous, &current) == false)
		return false;
	previous->next = current->next;
	if (current == START)
		START = START->next;

	delete current;
	return true;
}
/*check apakah node yang dimaksud ada didalam list atau tidak*/
bool list::search(int nim, node** previous, node** current)
{
	*previous = START;
	*current = START;
	while ((*current != NULL) && (nim != (*current)->noMhs))
	{
		*previous = *current;
		*current = (*current)->next;
	}
	return(*current != NULL);
}

void list::traverse()/*mengunjungi dan membaca dalam list*/
{

	if (listempty())
		cout << "\nlist kosong\n";
	else
	{
		cout << endl << "Data didalam list adalah:" << endl;
		node* currentNode;
		for (currentNode = START; currentNode != NULL; currentNode = currentNode->next) {
			cout << currentNode->noMhs << "  " << currentNode->nama << "\n";
		}
		cout << endl;

	}
}
	




