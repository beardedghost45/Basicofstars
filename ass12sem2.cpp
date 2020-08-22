#include<bits/stdc++.h>
#include<fstream>
#define SIZE 10
#define h(x) x%SIZE
using namespace std;

struct STUD
{
    int rno;
    char name[20];
    float marks;
    int stat;
    int link;
};

class probe
{
    char table[30];
    fstream tab;
    STUD rec;

    public:
            probe(){}
            probe(char *a);
            void displayall();
            void insert(STUD rec1);
            void Delete( int rno);
            int search(int rolno);

            void display(int recno)
            {
                int i = recno;
                tab.open(table, ios::binary | ios::in);
                tab.seekg(recno * sizeof(STUD), ios::beg);
                tab.read((char*)&rec, sizeof(STUD));

                if(rec.stat == 0)
                {
                    cout << "\n" << i << ") " << rec.rno << " " << rec.name << " " << setprecision(2) << rec.marks;
                    cout << " " << rec.link;
                }
                else
                {
                    cout << "\n" << i;
                }
                tab.close();
            }

            void read(int recno)
            {
                tab.open(table, ios::binary | ios::in);
                tab.seekg(recno * sizeof(STUD), ios::beg);
                tab.read((char*)&rec, sizeof(STUD));
                tab.close();
            }

            void write(int recno)
            {
                tab.open(table, ios::binary | ios::out | ios::in);
                tab.seekg(recno * sizeof(STUD), ios::beg);
                tab.write((char*)&rec, sizeof(STUD));
                tab.close();
            }
};

probe::probe(char *a)
{
    int i;
    strcpy(table, a);
    rec.stat = 1;
    rec.link = -1;
    tab.open(table, ios::binary | ios::out);
    tab.close();
    for(int i = 0; i < SIZE; i++)
        write(i);
}

void probe::displayall()//Display record-wise
{
    int i = 1, n;
    cout << "\n******Data******";
    for(i = 0; i <=SIZE; i++)
        display(i);
}

void probe::insert(STUD rec1)
{
    int n, i, j, k, start;
    rec1.stat = 0;
    rec1.link = -1;
    start = h(rec1.rno); // hashed location to be visited

    //Find starting position of chain
    for(i = 0; i < SIZE; i++)
    {
        j = (start + i)%SIZE;
        read(j);
        if((rec.stat == 0) && (h(rec.rno) == start))
            break;
    }
    //starting position found
    if(i < 10)
    {
        // if chain found, goto the end of chain
        while(rec.link != -1)
        {
            j = rec.link;
            read(j);
        }
        //search for empty location
        for(i = 0; i < SIZE; i++)
        {
            k = (start + i)%SIZE;
            read(k);
            if(rec.stat == 1)
            {
                rec = rec1;
                write(k);
                read(j);
                rec.link = k;
                write(j);
                return;
            }
        }
        //if not empty
        cout << "\nTable is full";
    }
    //not found
    else
    {
        for(i = 0; i < SIZE; i++)
        {
            k = (start + i)%SIZE;
            read(k);
            if(rec.stat == 1)
            {
                rec = rec1;
                write(k);
                return;
            }
        }
        cout << "\nTable is full";
    }
}

void probe::Delete(int rno) //Delete Record
{
    STUD rec1;
    int recno;
    int i, j, start, k;
    start = h(rno);//hashed location for given roll no

    //Search starting position of the chain
    for(i = 0; i < SIZE; i++)
    {
        j = (start + i)%SIZE;
        read(j);
        if((rec.stat == 0) && (h(rec.rno) == start))//synonym found
            break;
    }
    //if found
    if(i < 10)
    {
        if(rec.rno == rno) //found at the beginning of the chain
        {
            rec.stat = 1;
            write(j);
        }
        else
        {
            // locate the predecessor
            while(rec.rno != rno && rec.link != -1)
            {
                k = j;
                j = rec.link;
                read(j);
            }
            if(rec.rno == rno)
            {
                rec.stat = 1;
                write(j);
                int nextlink = rec.link;
                read(k);
                rec.link = nextlink;
                write(k);
            }
            else
                cout << "\nElement not found";
        }
    }
    //if not found
    else
        cout << "\nRecord not found";
}

int probe::search(int rno)//Search Records
{
    int start, i, j;
    start = h(rno);
    for(i = 0; i < SIZE; i++)
    {
        j = (start + i) % SIZE;
        read(j);
        if((rec.stat == 0) && (h(rec.rno) == start))//found
            break;
    }
    if(i < 10)//Search Successful
    {
        while(rec.rno != rno && rec.link != -1)
        {
            j = rec.link;
            read(j);
        }
        if(rec.rno == rno)
            return j;

        else
            return -1;
    }
    //Not found
    else
        return -1;
}

int main()
{
    probe object("table.txt");
    int rno, op, recno;
    STUD rec1;
    printf("\nSTUDENT RECORD\n");

    while(1)
    {
        cout<<"\n*****************************************\n";
        cout << "\n\n       1.Insert Data\n       2.Print Data\n       3.Delete Data\n       4.Search for a particular data\n       5.Exit";
        cout << "\n\nEnter Your Choice : ";
        cin >> op;
        switch(op)
        {
            case 1: cout << "\nEnter a record to be inserted(rno, name, marks) : ";
                    cin >> rec1.rno >> rec1.name >> rec1.marks;
                    object.insert(rec1);
                    break;

            case 2: object.displayall();
                    break;
            case 3: cout << "\nEnter the roll no : ";
                    cin >> rno;
                    object.Delete(rno);
                    break;
            case 4: cout << "\nEnter roll : ";
                    cin >> rno;
                    recno = object.search(rno);
                    if(recno >= 0)
                    {
                        cout << "\n Record No. : " << recno;
                        object.display(recno);
                    }
                    else
                        cout << "\nRecord not found";
                    break;
             case 5:cout<<"\nThank You!";
                    return 0;
        }
    }

    return 0;
}
