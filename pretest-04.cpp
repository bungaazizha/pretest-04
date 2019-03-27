/*
Author		: Bunga Azizha N
NPM			: 140810180016
Deskripsi	: Data Mahasiswa
Tahun		: 2019
*/
//exercise

#include<iostream>
using namespace std;

struct ElemtList{
	char npm[14];
	char nama[40];
	float ipk;
	ElemtList* next;
};
typedef ElemtList* pointer;
typedef pointer List;

void createList(List& First);
void createElmt(pointer& pBaru);
void insertFirst (List& First, pointer pBaru);
void insertLast (List& First, pointer pBaru);
void insertSortNPM(List& first, pointer pBaru);
void traversal (List First);

main()
{
    pointer pBaru;
    List first;
    int pilihan;

    createList(first);
    while(1){
        system("cls");
        cout<<"=-=-=-=-=-=-=-=-=-=-=-=-="<<endl;
        cout<<"\tMenu"<<endl;
        cout<<"=-=-=-=-=-=-=-=-=-=-=-=-="<<endl;
        cout<<"|1. Tambah Data Di Awal	|"<<endl;
        cout<<"|2. Tambah Data Di Akhir|"<<endl;
        cout<<"|3. Tampilkan Data	|"<<endl;
        cout<<"|4. Exit		|"<<endl;
        cout<<"=-=-=-=-=-=-=-=-=-=-=-=-="<<endl;
        cout << "Masukan Pilihan : "; cin >> pilihan;
        cout<<endl;
        switch(pilihan){
        case 1:
            createElmt(pBaru);
            insertLast(first, pBaru);
        break;

        case 2:
            createElmt(pBaru);
            insertLast(first, pBaru);
        break;

        case 3:
        	//insertSortNPM(first, pBaru);
            traversal(first);
        break;

        case 5:
            return 0;
            break;

        }
        system("pause");
    }
}


void createList(List& First){
    First = NULL;
    }

void createElmt (pointer& pBaru){
    pBaru = new ElemtList;
    cout<<"NPM	: "; cin>>pBaru->npm;  cin.ignore();
    cout<<"Nama	: "; cin.getline(pBaru->nama, 40);
    cout<<"IPK	: "; cin>>pBaru->ipk;
    pBaru->next=NULL;
}

void insertFirst (List& First, pointer pBaru){
    if(First==NULL){
        First=pBaru;
    }
    else{
        pBaru->next=First;
        First=pBaru;
    }
}

void insertLast (List& First, pointer pBaru){
    pointer Last;
    if (First==NULL){
        First=pBaru;
    }
    else {
        Last=First;
        while (Last->next!=NULL){
            Last=Last->next;
        }
        Last->next=pBaru;
    }
}
void traversal (List First){
    pointer pBantu;
    pBantu=First;
    int counter=1;
    cout<<"	\t	DATA MAHASISWA"<<endl;
    cout<<"=========================================================="<<endl;
    cout<<"No\t\tNPM\t\tNama\t\tIPK"<<endl;
    cout<<"----------------------------------------------------------"<<endl;
    while(pBantu != NULL){
    		cout<<counter<<"\t\t"<<pBantu->npm<<"\t\t"<<pBantu->nama<<"\t\t"<<pBantu->ipk<<endl;
        pBantu=pBantu->next;
        counter++;
    }
    cout<<"=========================================================="<<endl;
}

/*
void insertSortNPM(List& First, pointer pBaru){
	pointer pBantu;
	List& tempList = NULL;
	List& tempFirst = First;
	List& tempNext = First->next;
	
	while(tempNext != NULL){
		
		if(tempFirst->nama > tempNext->nama ) {
			tempList = tempFirst;
			tempFirst = tempNext;
			tempList->next = tempList->next->next;
			tempFirst->next = tempList;
			tempNext = tempFirst->next;
			print_list(tempFirst);
		}
		else{
			tempFirst = tempFirst->next;
			tempNext = tempNext->next;
		}
		}
		return First;
	}

}
*/

//sorting belum sempurna, kalo tanpa sorting jalan ko
