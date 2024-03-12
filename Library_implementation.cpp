#include <iostream>
#include <iomanip>
using namespace std;

const int N = 10;

struct Date {
    int day;
    int month;
    int year;
};

struct Book {
    int id;
    double price;
    Date date;
};

struct Library {
    Book books[N] = { 0 };
    Book boo[N] = { 0 };
    int num;
};

void add(Library* p);
void show(Library* p);
void del(Library* p);
void listOptions(Library* p);
void sort(Library* p);
void sort_id(Library* p);
void sort_date(Library* p);
void init(Library* p);

void listOptions(Library* p) {
    int opt;
    cout << "~~~~~~~~~Welcome!~~~~~~~~~~" << endl;
    cout << "0: Exit" << endl;
    cout << "1: Add" << endl;
    cout << "2: Show" << endl;
    cout << "3: Delete" << endl;
    cout << "4: Sort" << endl;
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;

    cin >> opt;

    if (opt == 0) {
        cout << "Bye!";
    }
    else if (opt == 1) {
        add(p);
        listOptions(p);
    }
    else if (opt == 2) {
        show(p);
        listOptions(p);
    }
    else if (opt == 3) {
        del(p);
        listOptions(p);
    }
    else if (opt == 4) {
        sort(p);
        listOptions(p);
    }
}

void add(Library* p) {
    int Id, dd, mm, yyyy;
    double Price;
    if (p->num == 10) {
        cout << "Library is full";
        cout << endl;
        return;
    }
    bool uniqueId = false;
    while (!uniqueId) {
        cout << "Input Book ID:" << endl;
        cin >> Id;
        uniqueId = true; // Assume ID is unique unless proven otherwise
        for (int i = 0; i < p->num; i++) {
            if (p->books[i].id == Id) {
                uniqueId = false; // Set flag to false if ID already exists
                break;
            }
        }
    }

    p->books[p->num].id = Id;                       p->boo[p->num].id = Id;
    cout << "Input Price:" << endl;
    cin >> Price;
    p->books[p->num].price = Price;                 p->boo[p->num].price = Price;

    cout << "Input Date (dd mm yyyy):" << endl;
    cin >> dd;
    p->books[p->num].date.day = (dd);               p->boo[p->num].date.day = (dd);
    cin >> mm;
    p->books[p->num].date.month = (mm);             p->boo[p->num].date.month = (mm);
    cin >> yyyy;
    p->books[p->num].date.year = (yyyy);            p->boo[p->num].date.year = (yyyy);
    (p->num)++;
    cout << endl;

}

void show(Library* p) {
    int i;
    for (i = 0; i < p->num; i++) {
        cout << setfill('0') << setw(3) << p->books[i].id;
        cout << "     ";
        if (i == p->num - 1) {
            cout << fixed << setprecision(2) << setw(5);
        }
        else {
            cout << setprecision(2) << fixed << setw(5);
        }
        cout << p->books[i].price;
        cout << "   ";
        cout << p->books[i].date.day << "-" << p->books[i].date.month << "-" << p->books[i].date.year;
        cout << endl;
    }
    cout << endl;
}

void del(Library* p) {
    cout << "Enter the ID to be deleted" << endl;
    int id_del;
    cin >> id_del;
    int i;
        for (i = 0; i < p->num; i++) {
            if (p->books[i].id == id_del) {
                p->books[i].id = 0;
                p->books[i].price = 0.0;
                p->books[i].date.day = 0;
                p->books[i].date.month = 0;
                p->books[i].date.year = 0;
                for (int w = i + 1; w < p->num; w++) {
                    p->books[w - 1] = p->books[w];
                }
                (p->num)--;
                cout << endl;
                return;
            }
        }
        cout << "The ID cannot be found" << endl;
        cout << endl;
        return;
}

void sort_id(Library* p) {
    int arr[10] = { 0 };
    int arr_copy[10] = { 0 };
    int k = 0;
    int i, j, temp;

    //I am copying the id in the books array into another array arr[10]
    for (i = 0; i < p->num; i++) {
        arr[k++] = p->books[i].id;
    }
    //I am making a duplicate of arr[10] so that it can be used later
    for (i = 0; i < p->num; i++) {
        arr_copy[i] = arr[i];
    }
    //I am doing bubblesort to sort the id in ascending order
    for (i = 0; i < p->num; i++) {
        for (j = p->num - 1; j > i; j--) {
            if (arr[j - 1] > arr[j]) {
                temp = arr[j];
                arr[j] = arr[j - 1];
                arr[j - 1] = temp;
            }
        }
    }
    int number = p->num;
    p->num = 0; // here i am again initailizing num=0 so that when show function is called it is shown with sorted id
    for (i = 0; i < number; i++) {
        p->books[p->num].id = arr[i];
        for (j = 0; j < number; j++) {
            if (arr[i] == arr_copy[j]) {
                p->books[p->num].price = p->boo[j].price;
                p->books[p->num].date.day = p->boo[j].date.day;
                p->books[p->num].date.month = p->boo[j].date.month;
                p->books[p->num].date.year = p->boo[j].date.year;
            }//IF I HAVE USED (Books) IN THIS IF STATEMENTS ON BOTH SIDES OF EQUAL SIGN THEN THE DATA OF THE BOOKS STRUCUTRE 
             // WOULD HAVE CHANGED SO I DUPLICATED THE (Books) INTO (Boo) SO THAT THE (Books) DATA ARE CHANGED DUE 
             //TO SORTING BUT THE (Boo) ONE REMAINS UNCHAGED.
        }
        (p->num)++;
    }
}


void sort_date(Library* p)
{
    for (int w = 0; w < p->num; w++)
    {
        for (int y = 0; y < p->num - 1; y++)
        {
            if (p->books[y].date.year > p->books[y + 1].date.year || (p->books[y].date.year == p->books[y + 1].date.year && p->books[y].date.month > p->books[y + 1].date.month) || (p->books[y].date.year == p->books[y + 1].date.year && p->books[y].date.month == p->books[y + 1].date.month && p->books[y].date.day > p->books[y + 1].date.day))
            {
                Book temp = p->books[y];
                p->books[y] = p->books[y + 1];
                p->books[y + 1] = temp;
            }
            else if (p->books[y].date.year == p->books[y + 1].date.year && p->books[y].date.month == p->books[y + 1].date.month && p->books[y].date.day == p->books[y + 1].date.day)
            {
                if (p->books[y].id > p->books[y + 1].id)
                {
                    Book temp = p->books[y];
                    p->books[y] = p->books[y + 1];
                    p->books[y + 1] = temp;
                }
            }
        }
    }
}

void sort(Library* p) {
    int n;
    cout << "1: Sort by ID" << endl;
    cout << "2: Sort by Date" << endl;
    cin >> n;
    cout << endl;
    if (n == 1) {
        sort_id(p);
    }
    else if (n == 2) {
        sort_date(p);
    }

}

void init(Library* p) {
    p->books[p->num].id = 3;            p->boo[p->num].id = 3;
    p->books[p->num].price = 10.5;      p->boo[p->num].price = 10.5;
    p->books[p->num].date.day = 15;     p->boo[p->num].date.day = 15;
    p->books[p->num].date.month = 1;        p->boo[p->num].date.month = 1;
    p->books[p->num].date.year = 1990;      p->boo[p->num].date.year = 1990;
    (p->num)++;

    p->books[p->num].id = 2;            p->boo[p->num].id = 2;
    p->books[p->num].price = 20.55;     p->boo[p->num].price = 20.55;
    p->books[p->num].date.day = 15;     p->boo[p->num].date.day = 15;
    p->books[p->num].date.month = 2;        p->boo[p->num].date.month = 2;
    p->books[p->num].date.year = 2024;      p->boo[p->num].date.year = 2024;
    (p->num)++;

    p->books[p->num].id = 4;        p->boo[p->num].id = 4;
    p->books[p->num].price = 10.5;      p->boo[p->num].price = 10.5;
    p->books[p->num].date.day = 20;     p->boo[p->num].date.day = 20;
    p->books[p->num].date.month = 2;        p->boo[p->num].date.month = 2;
    p->books[p->num].date.year = 2021;      p->boo[p->num].date.year = 2021;
    (p->num)++;

    p->books[p->num].id = 1;         p->boo[p->num].id = 1;
    p->books[p->num].price = 30.1;        p->boo[p->num].price = 30.1;
    p->books[p->num].date.day = 20;      p->boo[p->num].date.day = 20;
    p->books[p->num].date.month = 2;        p->boo[p->num].date.month = 2;
    p->books[p->num].date.year = 2021;      p->boo[p->num].date.year = 2021;
    (p->num)++;

}

int main() {
    Library lib;
    lib.num = 0;

    init(&lib);
    listOptions(&lib);

    return 0;
}