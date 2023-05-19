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

int main()
{
	list mhs;
	int nim;
	char ch;
	while (1)
	{
		cout << endl << "menu";
		cout << endl << "1. menambah data kedalam list" << endl;
		cout << "2. menghapus data dari dalam list" << endl;
		cout << "3.menampilkan data dari dalam list" << endl;
		cout << "4. mencari data dalam list" << endl;
		cout << "5.keluar" << endl;
		cout << endl << "masukkan pilihan (1-5): ";
		cin >> ch;
		switch (ch)
		{
		case '1':
		{
			mhs.addNode();
		}
		break;

		case '2':
		{
			if (mhs.listempty())
			{
				cout << endl << "list kosong" << endl;
				break;
			}
			cout << endl << "\nmasukkan no mahasiswa yang dihapus : ";
			cin >> nim;
			if (mhs.delnode(nim) == false)
				cout << endl << "Data tidak ditemukan" << endl;
			else
				cout << endl << "Data dengan nomor mahasiswa" << nim << "berhasil disapus :";
		}
		break;
		case'3':
		{
			mhs.traverse();
		}
		break;
		case '4':
		{
			if (mhs.listempty() == true)
			{
				cout << "\nList kosong\n";
				break;
			}
			node* previous, * current;
			cout << endl << "Masukkan no mahasiswa yang dicari : ";
			cin >> nim;
			if (mhs.search(nim, &previous, &current) == false)
				cout << endl  << "Data tidak ditemukan" << endl;
			else
			{
				cout << endl << "Data ditemukan" << endl;
				cout << "\nNo mahasiswa: " << current->noMhs;
				cout << "\n\nNama: " << current->nama;
				cout << "\n";
			}

		}
		break;
		case '5':
		{
			exit(0);
		}
		break;
		default:
		{
			cout << "pilihan salah !." << endl;
		}





























		}

	}
}
	




