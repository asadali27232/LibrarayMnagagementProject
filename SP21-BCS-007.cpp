#include<iostream>
#include<fstream>
#include<iomanip>
#include<stdlib.h>
#include<string>
#include<cstring>
#include<cmath>
#include<cctype>

using namespace std;

int countBooks=0;
char garbage;

struct book{
    int ID;
    string title;
    string author;
    double price;
    bool issue;
};

book Library [1000];

void addBooks ();
void displayBooks ();
void authorBooks ();
void unissuedBooks ();
void sortBooks ();
void loadBooks ();
void exportBooksInfo();

//Ignore these functions. They are just manipulating the output of above functions.
void output_addBooks ();
void output_displayBooks ();
void output_authorBooks ();
void output_unissuedBooks ();
void output_sortBooks ();
void output_loadBooks ();
void output_exportBooksInfo(ofstream& outdata);

int main()
{
    while(1)
    {
        system("CLS");
        cout << setw(25) << setfill(' ') << " " <<  "|" << setw(68) << setfill('=') << "=" << "|" << endl;
        cout << setw(25) << setfill(' ') << " " << "|" << setw(19) << setfill(' ') << " " << setw(29) << "007-Library Management System" << setw(21) << setfill(' ') << right << "|" << endl;
        cout << setw(25) << setfill(' ') << " " << "|" << setw(68) << setfill('=') << "=" << "|" << endl;

        cout << setw(25) << setfill(' ') << " " <<  "|" << setw(68) << setfill('=') << "=" << "|" << endl;
        cout << setw(25) << setfill(' ') << " " << "|" << setw(30) << setfill(' ') << " " << setw(8) << "Main Manu" << setw(30) << setfill(' ') << right << "|" << endl;
        cout << setw(25) << setfill(' ') << " " << "|" << setw(68) << setfill('=') << "=" << "|" << endl;
        cout << endl;

        cout << setw(25) << setfill(' ') << " " <<  "|" << setw(68) << setfill('-') << "-" << "|" << endl;
        cout << setw(25) << setfill(' ') << " " << "|" << setw(8) << setfill(' ') <<  "Sr No. " << "|" << setw(45) << setfill(' ') << left <<  " Library Management Tools" << "|" << setw(13) << setfill(' ') << right <<  "Options   " << "|" << endl;
        cout << setw(25) << setfill(' ') << " " <<  "|" << setw(68) << setfill('-') << "-" << "|" << endl;
        cout << setw(25) << setfill(' ') << " " <<  "|" << setw(68) << setfill('-') << "-" << "|" << endl;

        cout << setw(25) << setfill(' ') << " " << "|" << setw(8) << setfill(' ') <<  "1.   " << "|" << setw(45) << setfill(' ') << left <<  " Add Books Information" << "|" << setw(13) << setfill(' ') << right <<  "[ A ]    " << "|" << endl;
        cout << setw(25) << setfill(' ') << " " <<  "|" << setw(68) << setfill('-') << "-" << "|" << endl;

        cout << setw(25) << setfill(' ') << " " << "|" << setw(8) << setfill(' ') <<  "2.   " << "|" << setw(45) << setfill(' ') << left <<  " Display Books Information" << "|" << setw(13) << setfill(' ') << right <<  "[ D ]    " << "|" << endl;
        cout << setw(25) << setfill(' ') << " " <<  "|" << setw(68) << setfill('-') << "-" << "|" << endl;

        cout << setw(25) << setfill(' ') << " " << "|" << setw(8) << setfill(' ') <<  "3.   " << "|" << setw(45) << setfill(' ') << left <<  " List all Books of an Author" << "|" << setw(13) << setfill(' ') << right <<  "[ R ]    " << "|" << endl;
        cout << setw(25) << setfill(' ') << " " <<  "|" << setw(68) << setfill('-') << "-" << "|" << endl;

        cout << setw(25) << setfill(' ') << " " << "|" << setw(8) << setfill(' ') <<  "4.   " << "|" << setw(45) << setfill(' ') << left <<  " Display Unissued Books" << "|" << setw(13) << setfill(' ') << right <<  "[ U ]    " << "|" << endl;
        cout << setw(25) << setfill(' ') << " " <<  "|" << setw(68) << setfill('-') << "-" << "|" << endl;

        cout << setw(25) << setfill(' ') << " " << "|" << setw(8) << setfill(' ') <<  "5.   " << "|" << setw(45) << setfill(' ') << left <<  " Sort Books by Book ID" << "|" << setw(13) << setfill(' ') << right <<  "[ S ]    " << "|" << endl;
        cout << setw(25) << setfill(' ') << " " <<  "|" << setw(68) << setfill('-') << "-" << "|" << endl;

        cout << setw(25) << setfill(' ') << " " << "|" << setw(8) << setfill(' ') <<  "6.   " << "|" << setw(45) << setfill(' ') << left <<  " Laod Books Information from a File" << "|" << setw(13) << setfill(' ') << right <<  "[ I ]    " << "|" << endl;
        cout << setw(25) << setfill(' ') << " " <<  "|" << setw(68) << setfill('-') << "-" << "|" << endl;

        cout << setw(25) << setfill(' ') << " " << "|" << setw(8) << setfill(' ') <<  "7.   " << "|" << setw(45) << setfill(' ') << left <<  " Get Books Information in a File" << "|" << setw(13) << setfill(' ') << right <<  "[ O ]    " << "|" << endl;
        cout << setw(25) << setfill(' ') << " " <<  "|" << setw(68) << setfill('-') << "-" << "|" << endl;

        cout << setw(25) << setfill(' ') << " " << "|" << setw(8) << setfill(' ') <<  "8.   " << "|" << setw(45) << setfill(' ') << left <<  " Exit" << "|" << setw(13) << setfill(' ') << right <<  "[ E ]    " << "|" << endl;
        cout << setw(25) << setfill(' ') << " " <<  "|" << setw(68) << setfill('-') << "-" << "|" << endl;

        char option;
        cout << setw(25) << setfill(' ') << " " <<  "|" << setw(68) << setfill('-') << "-" << "|" << endl;
        cout << setw(25) << setfill(' ') << " " << "|" << setw(8) << setfill(' ') <<  "==>  " << "|" << setw(45) << setfill(' ') << left <<  " Enter an Option" << "|" << setw(5) << setfill(' ') << left <<  "    [ " ;
        cin >> option;
        option = toupper(option);

        switch(option)
        {
        case 'A':
            addBooks();
            break;
        case 'D':
            displayBooks();
            break;
        case 'R':
            authorBooks();
            break;
        case 'U':
            unissuedBooks();
            break;
        case 'S':
            sortBooks();
            break;
        case 'I':
            loadBooks();
            break;
        case 'O':
            exportBooksInfo();
            break;
        case 'E':
            return 1;
            break;
        default:
            cout << setw(25) << setfill(' ') << " " <<  "|" << setw(68) << setfill('-') << "-" << "|" << endl;
            cout << setw(25) << setfill(' ') << " " << "|" << setw(8) << setfill(' ') << right <<  "==>  " << "|" << setw(45) << setfill(' ') << left <<  " Entered an Invalid Option!" << "|" << setw(14) << setfill(' ') << right << "|" << endl;
            cout << setw(25) << setfill(' ') << " " << "|" << setw(8) << setfill(' ') <<  "==>  " << "|" << setw(45) << setfill(' ') << left <<  " Press Enter Key to Enter Main Menu Again...!" << "|" << setw(14) << setfill(' ') << right << "|" << endl;
            cout << setw(25) << setfill(' ') << " " <<  "|" << setw(68) << setfill('-') << "-" << "|" << endl;
            cout << endl;
            cin.get(garbage);
            cin.get(garbage);
    }
    }
}

void addBooks ()
{
    output_addBooks ();
    string issueFlag;
    char addMore;
    bool addMoreFlag;
    int i = countBooks;
    do
    {
    cout << setw(25) << setfill(' ') << " " <<  "|" << setw(68) << setfill('-') << "-" << "|" << endl;
    cout << setw(25) << setfill(' ') << " " << "|" << setw(8) << setfill(' ') << right <<  "==>  " << "|" << setw(59) << setfill(' ') << left <<  " Enter Book ID:"  << right << "|" << endl;
    cout << setw(25) << setfill(' ') << " " <<  "|" << setw(68) << setfill('-') << "-" << "|" << endl;
    cout << setw(25) << setfill(' ') << " " << "|" << setw(8) << setfill(' ') << right <<  "==>  " << "| ";
    cin >> Library[i].ID;
    cin.get(garbage);

    cout << setw(25) << setfill(' ') << " " <<  "|" << setw(68) << setfill('-') << "-" << "|" << endl;
    cout << setw(25) << setfill(' ') << " " << "|" << setw(8) << setfill(' ') << right <<  "==>  " << "|" << setw(59) << setfill(' ') << left <<  " Enter Book Title:"  << right << "|" << endl;
    cout << setw(25) << setfill(' ') << " " <<  "|" << setw(68) << setfill('-') << "-" << "|" << endl;
    cout << setw(25) << setfill(' ') << " " << "|" << setw(8) << setfill(' ') << right <<  "==>  " << "| ";
    getline(cin, Library[i].title);

    cout << setw(25) << setfill(' ') << " " <<  "|" << setw(68) << setfill('-') << "-" << "|" << endl;
    cout << setw(25) << setfill(' ') << " " << "|" << setw(8) << setfill(' ') << right <<  "==>  " << "|" << setw(59) << setfill(' ') << left <<  " Enter Author Name:"  << right << "|" << endl;
    cout << setw(25) << setfill(' ') << " " <<  "|" << setw(68) << setfill('-') << "-" << "|" << endl;
    cout << setw(25) << setfill(' ') << " " << "|" << setw(8) << setfill(' ') << right <<  "==>  " << "| ";
    getline(cin, Library[i].author);

    cout << setw(25) << setfill(' ') << " " <<  "|" << setw(68) << setfill('-') << "-" << "|" << endl;
    cout << setw(25) << setfill(' ') << " " << "|" << setw(8) << setfill(' ') << right <<  "==>  " << "|" << setw(59) << setfill(' ') << left <<  " Enter Book Price:"  << right << "|" << endl;
    cout << setw(25) << setfill(' ') << " " <<  "|" << setw(68) << setfill('-') << "-" << "|" << endl;
    cout << setw(25) << setfill(' ') << " " << "|" << setw(8) << setfill(' ') << right <<  "==>  " << "| ";
    cin >> Library[i].price;
    cin.get(garbage);

    cout << setw(25) << setfill(' ') << " " <<  "|" << setw(68) << setfill('-') << "-" << "|" << endl;
    cout << setw(25) << setfill(' ') << " " << "|" << setw(8) << setfill(' ') << right <<  "==>  " << "|" << setw(59) << setfill(' ') << left <<  " Is Book Issued or Unissued:"  << right << "|" << endl;
    cout << setw(25) << setfill(' ') << " " <<  "|" << setw(68) << setfill('-') << "-" << "|" << endl;
    cout << setw(25) << setfill(' ') << " " << "|" << setw(8) << setfill(' ') << right <<  "==>  " << "| ";
    getline(cin, issueFlag);
        if (issueFlag=="Issued" || issueFlag=="issued")
            Library[countBooks].issue = true;
        if (issueFlag=="Unissued" || issueFlag=="unissued")
            Library[countBooks].issue = false;

    cout << setw(25) << setfill(' ') << " " <<  "|" << setw(68) << setfill('-') << "-" << "|" << endl;
    cout << setw(25) << setfill(' ') << " " << "|" << setw(8) << setfill(' ') << right <<  "==>  " << "|" << setw(59) << setfill(' ') << left <<  " Above Book Information has been Added." <<  right << "|" << endl;
    cout << setw(25) << setfill(' ') << " " <<  "|" << setw(68) << setfill('-') << "-" << "|" << endl;
    cout << setw(25) << setfill(' ') << " " <<  "|" << setw(68) << setfill('-') << "-" << "|" << endl;
    cout << setw(25) << setfill(' ') << " " << "|" << setw(8) << setfill(' ') << right <<  "==>  " << "|" << setw(59) << setfill(' ') << left <<  " Do you want to Enter an other Book..? [Y/N]" <<  right << "|" << endl;
    cout << setw(25) << setfill(' ') << " " <<  "|" << setw(68) << setfill('-') << "-" << "|" << endl;
    cout << setw(25) << setfill(' ') << " " << "|" << setw(8) << setfill(' ') << right <<  "==>  " << "| ";
    cin >> addMore;
    if (addMore=='Y' || addMore=='y')
            addMoreFlag = true;
    if (addMore=='N' || addMore=='n')
            addMoreFlag = false;
    i++;
    } while(addMoreFlag);
    countBooks = i;
    cin.get(garbage);
    cin.clear();
    cin.ignore(100, '\n');
}
void displayBooks ()
{
    output_displayBooks ();
    for (int i=0; i<countBooks; i++)
    {
    cout << setw(9) << setfill(' ') << " " << "|"
         << " " << setw(8) << setfill(' ') << left << Library[i].ID << "|"
         << " " << setw(45) << setfill(' ') << left << Library[i].title<< "|"
         << " " << setw(27) << setfill(' ') << left << Library[i].author << "|"
         << " " << setw(6) << setfill(' ') << left << setprecision(1) << showpoint << fixed << Library[i].price << "|";
    if (Library[i].issue == 0)
        cout << " " << setw(9) << setfill(' ') << left << "Issued" << "|"<< endl;
    else
        cout << " " << setw(9) << setfill(' ') << left << "Unissued" << "|"<< endl;
    cout << setw(9) << setfill(' ') << " " <<  "|" << setw(104) << setfill('-') << "-" << "|" << endl;
    }
    cout << setw(25) << setfill(' ') << " " <<  "|" << setw(68) << setfill('-') << "-" << "|" << endl;
    cout << setw(25) << setfill(' ') << " " << "|" << setw(8) << setfill(' ') << right <<  "==>  " << "|" << setw(59) << setfill(' ') << left <<  " All Books are Displayed Successfully." <<  right << "|" << endl;
    cout << setw(25) << setfill(' ') << " " << "|" << setw(8) << setfill(' ') <<  "==>  " << "|" << setw(59) << setfill(' ') << left <<  " Press Enter Key to Enter Main Menu Again...!" << right << "|" << endl;
    cout << setw(25) << setfill(' ') << " " <<  "|" << setw(68) << setfill('-') << "-" << "|" << endl;
    cin.get(garbage);
    cin.clear();
    cin.ignore(100, '\n');
}
void authorBooks ()
{
    output_authorBooks();
    string authorName;
    cout << setw(25) << setfill(' ') << " " <<  "|" << setw(68) << setfill('-') << "-" << "|" << endl;
    cout << setw(25) << setfill(' ') << " " << "|" << setw(8) << setfill(' ') << right <<  "==>  " << "|" << setw(59) << setfill(' ') << left <<  " Enter Author Name:"  << right << "|" << endl;
    cout << setw(25) << setfill(' ') << " " <<  "|" << setw(68) << setfill('-') << "-" << "|" << endl;
    cout << setw(25) << setfill(' ') << " " << "|" << setw(8) << setfill(' ') << right <<  "==>  " << "| ";
    cin.get(garbage);
    getline(cin, authorName);
    cout << setw(9) << setfill(' ') << " " <<  "|" << setw(104) << setfill('-') << "-" << "|" << endl;
    cout << setw(9) << setfill(' ') << " " << "|"
         << " " << setw(8) << setfill(' ') << left <<  "ID" << "|"
         << " " << setw(45) << setfill(' ') << left <<  "Title" << "|"
         << " " << setw(27) << setfill(' ') << left <<  "Author" << "|"
         << " " << setw(6) << setfill(' ') << left <<  "Price" << "|"
         << " " << setw(9) << setfill(' ') << left <<  " Status" << "|"<< endl;
    cout << setw(9) << setfill(' ') << " " <<  "|" << setw(104) << setfill('-') << "-" << "|" << endl;
    cout << setw(9) << setfill(' ') << " " <<  "|" << setw(104) << setfill('-') << "-" << "|" << endl;
    for (int i=0; i<countBooks; i++)
    {
    if (Library[i].author == authorName)
    {
    cout << setw(9) << setfill(' ') << " " << "|"
         << " " << setw(8) << setfill(' ') << left << Library[i].ID << "|"
         << " " << setw(45) << setfill(' ') << left << Library[i].title<< "|"
         << " " << setw(27) << setfill(' ') << left << Library[i].author << "|"
         << " " << setw(6) << setfill(' ') << left << setprecision(1) << showpoint << fixed << Library[i].price << "|";
    if (Library[i].issue == 0)
        cout << " " << setw(9) << setfill(' ') << left << "Issued" << "|"<< endl;
    else
        cout << " " << setw(9) << setfill(' ') << left << "Unissued" << "|"<< endl;
    cout << setw(9) << setfill(' ') << " " <<  "|" << setw(104) << setfill('-') << "-" << "|" << endl;
    }
    }
    cout << setw(25) << setfill(' ') << " " <<  "|" << setw(68) << setfill('-') << "-" << "|" << endl;
    cout << setw(25) << setfill(' ') << " " << "|" << setw(8) << setfill(' ') << right <<  "==>  " << "|" << setw(59) << setfill(' ') << left <<  " All Books of given Author are Displayed Successfully." <<  right << "|" << endl;
    cout << setw(25) << setfill(' ') << " " << "|" << setw(8) << setfill(' ') <<  "==>  " << "|" << setw(59) << setfill(' ') << left <<  " Press Enter Key to Enter Main Menu Again...!" << right << "|" << endl;
    cout << setw(25) << setfill(' ') << " " <<  "|" << setw(68) << setfill('-') << "-" << "|" << endl;

    cin.clear();
    cin.ignore(100, '\n');
}
void unissuedBooks ()
{
    output_unissuedBooks ();
    for (int i=0; i<countBooks; i++)
    {
    if (Library[i].issue == true )
    {
    cout << setw(9) << setfill(' ') << " " << "|"
         << " " << setw(8) << setfill(' ') << left << Library[i].ID << "|"
         << " " << setw(45) << setfill(' ') << left << Library[i].title<< "|"
         << " " << setw(27) << setfill(' ') << left << Library[i].author << "|"
         << " " << setw(6) << setfill(' ') << left << setprecision(1) << showpoint << fixed << Library[i].price << "|";
    if (Library[i].issue == 0)
        cout << " " << setw(9) << setfill(' ') << left << "Issued" << "|"<< endl;
    else
        cout << " " << setw(9) << setfill(' ') << left << "Unissued" << "|"<< endl;
    cout << setw(9) << setfill(' ') << " " <<  "|" << setw(104) << setfill('-') << "-" << "|" << endl;
    }
    }
    cout << setw(25) << setfill(' ') << " " <<  "|" << setw(68) << setfill('-') << "-" << "|" << endl;
    cout << setw(25) << setfill(' ') << " " << "|" << setw(8) << setfill(' ') << right <<  "==>  " << "|" << setw(59) << setfill(' ') << left <<  " All Unissued Books are Displayed Successfully." <<  right << "|" << endl;
    cout << setw(25) << setfill(' ') << " " << "|" << setw(8) << setfill(' ') <<  "==>  " << "|" << setw(59) << setfill(' ') << left <<  " Press Enter Key to Enter Main Menu Again...!" << right << "|" << endl;
    cout << setw(25) << setfill(' ') << " " <<  "|" << setw(68) << setfill('-') << "-" << "|" << endl;
    cin.get(garbage);
    cin.clear();
    cin.ignore(100, '\n');

}
void sortBooks ()
{
    output_sortBooks();
    book hold;
    for (int pass=0; pass<countBooks-1; pass++ )
    {
    for (int i=0; i<countBooks-1; i++)
    {
        if ( Library[i].ID > Library[i+1].ID  )
        {
            hold = Library[i] ;
            Library[i]  = Library[i+1] ;
            Library[i+1]  = hold;
        }
    }
    }
    cout << setw(25) << setfill(' ') << " " <<  "|" << setw(68) << setfill('-') << "-" << "|" << endl;
    cout << setw(25) << setfill(' ') << " " << "|" << setw(8) << setfill(' ') << right <<  "==>  " << "|" << setw(59) << setfill(' ') << left <<  "All Books sorted by ID Successfully." << right << "|" << endl;
    cout << setw(25) << setfill(' ') << " " << "|" << setw(8) << setfill(' ') <<  "==>  " << "|" << setw(59) << setfill(' ') << left <<  " Press Enter Key to Enter Main Menu Again...!" << "|" << right << endl;
    cout << setw(25) << setfill(' ') << " " <<  "|" << setw(68) << setfill('-') << "-" << "|" << endl;
    cin.get(garbage);
    cin.get(garbage);
}
void loadBooks ()
{
    output_loadBooks ();
    ifstream indata;
    string fileName;
    cin.get(garbage);
    do
    {
    cout << setw(25) << setfill(' ') << " " <<  "|" << setw(68) << setfill('-') << "-" << "|" << endl;
    cout << setw(25) << setfill(' ') << " " << "|" << setw(8) << setfill(' ') << right <<  "==>  " << "|" << setw(59) << setfill(' ') << left <<  " Enter Input File Name:"  << right << "|" << endl;
    cout << setw(25) << setfill(' ') << " " <<  "|" << setw(68) << setfill('-') << "-" << "|" << endl;
    cout << setw(25) << setfill(' ') << " " << "|" << setw(8) << setfill(' ') << right <<  "==>  " << "| ";
    getline(cin, fileName);
    indata.open(fileName.c_str());
    if (!indata)
    {
    cout << setw(25) << setfill(' ') << " " <<  "|" << setw(68) << setfill('-') << "-" << "|" << endl;
    cout << setw(25) << setfill(' ') << " " << "|" << setw(8) << setfill(' ') << right <<  "==>  " << "|" << setw(59) << setfill(' ') << left <<  " File NOT Found....!" << right << "|" << endl;
    cout << setw(25) << setfill(' ') << " " <<  "|" << setw(68) << setfill('-') << "-" << "|" << endl;
    }
    else
    {
    cout << setw(25) << setfill(' ') << " " <<  "|" << setw(68) << setfill('-') << "-" << "|" << endl;
    cout << setw(25) << setfill(' ') << " " << "|" << setw(8) << setfill(' ') << right <<  "==>  " << "|" << setw(59) << setfill(' ') << left <<  " Record Found and has been Read Successfully." << right << "|" << endl;
    cout << setw(25) << setfill(' ') << " " <<  "|" << setw(68) << setfill('-') << "-" << "|" << endl;
    }
    } while (!indata);

    string issueFlag;
    while(!indata.eof())
    {
        indata >> Library[countBooks].ID;
        indata.get(garbage);
        getline(indata, Library[countBooks].title);
        getline(indata, Library[countBooks].author);
        indata >> Library[countBooks].price;
        indata.get(garbage);
        getline(indata, issueFlag);
        if (issueFlag=="Issued" || issueFlag=="issued")
            Library[countBooks].issue = true;
        if (issueFlag=="Unissued" || issueFlag=="unissued")
            Library[countBooks].issue = false;

        countBooks++;
    }
    cout << setw(25) << setfill(' ') << " " <<  "|" << setw(68) << setfill('-') << "-" << "|" << endl;
    cout << setw(25) << setfill(' ') << " " << "|" << setw(8) << setfill(' ') << right <<  "==>  " << "|" << setw(59) << setfill(' ') << left <<  " Books Information has been Read Successfully." << right << "|" << endl;
    cout << setw(25) << setfill(' ') << " " << "|" << setw(8) << setfill(' ') <<  "==>  " << "|" << setw(59) << setfill(' ') << left <<  " Press Enter Key to Enter Main Menu Again...!" << "|" << right << endl;
    cout << setw(25) << setfill(' ') << " " <<  "|" << setw(68) << setfill('-') << "-" << "|" << endl;
    cin.clear();
    cin.ignore(100, '\n');
}
void exportBooksInfo()
{
    ofstream outdata;
    output_exportBooksInfo(outdata);

    string fileName;
    cin.get(garbage);
    do
    {
    cout << setw(25) << setfill(' ') << " " <<  "|" << setw(68) << setfill('-') << "-" << "|" << endl;
    cout << setw(25) << setfill(' ') << " " << "|" << setw(8) << setfill(' ') << right <<  "==>  " << "|" << setw(59) << setfill(' ') << left <<  " Enter Output File Name:"  << right << "|" << endl;
    cout << setw(25) << setfill(' ') << " " <<  "|" << setw(68) << setfill('-') << "-" << "|" << endl;
    cout << setw(25) << setfill(' ') << " " << "|" << setw(8) << setfill(' ') << right <<  "==>  " << "| ";

    getline(cin, fileName);
    outdata.open(fileName.c_str());
    } while (!cin);


    output_exportBooksInfo(outdata);

    for (int i=0; i<countBooks; i++)
    {
    outdata << setw(9) << setfill(' ') << " " << "|"
            << " " << setw(8) << setfill(' ') << left << Library[i].ID << "|"
            << " " << setw(45) << setfill(' ') << left << Library[i].title<< "|"
            << " " << setw(27) << setfill(' ') << left << Library[i].author << "|"
            << " " << setw(6) << setfill(' ') << left << setprecision(1) << showpoint << fixed << Library[i].price << "|";
    if (Library[i].issue == 0)
        outdata << " " << setw(9) << setfill(' ') << left << "Issued" << "|"<< endl;
    else
        outdata << " " << setw(9) << setfill(' ') << left << "Unissued" << "|"<< endl;
    outdata << setw(9) << setfill(' ') << " " <<  "|" << setw(104) << setfill('-') << "-" << "|" << endl;
    }
    cout << setw(25) << setfill(' ') << " " <<  "|" << setw(68) << setfill('-') << "-" << "|" << endl;
    cout << setw(25) << setfill(' ') << " " << "|" << setw(8) << setfill(' ') << right <<  "==>  " << "|" << setw(59) << setfill(' ') << left <<  " All Books Info Exported to a File." <<  right << "|" << endl;
    cout << setw(25) << setfill(' ') << " " << "|" << setw(8) << setfill(' ') <<  "==>  " << "|" << setw(59) << setfill(' ') << left <<  " Press Enter Key to Enter Main Menu Again...!" << right << "|" << endl;
    cout << setw(25) << setfill(' ') << " " <<  "|" << setw(68) << setfill('-') << "-" << "|" << endl;
    cin.clear();
    cin.ignore(100, '\n');
}

//Ignore these functions. They are just manipulating the output of above functions.
void output_addBooks ()
{
    system("CLS");
    cout << setw(25) << setfill(' ') << " " <<  "|" << setw(68) << setfill('=') << "=" << "|" << endl;
    cout << setw(25) << setfill(' ') << " " << "|" << setw(19) << setfill(' ') << " " << setw(29) << "007-Library Management System" << setw(21) << setfill(' ') << right<< "|" << endl;
    cout << setw(25) << setfill(' ') << " " << "|" << setw(68) << setfill('=') << "=" << "|" << endl;

    cout << setw(25) << setfill(' ') << " " <<  "|" << setw(68) << setfill('=') << "=" << "|" << endl;
    cout << setw(25) << setfill(' ') << " " << "|" << setw(30) << setfill(' ') << " " << setw(9) << "Add Books" << setw(30) << setfill(' ') << right << "|" << endl;
    cout << setw(25) << setfill(' ') << " " << "|" << setw(68) << setfill('=') << "=" << "|" << endl;
    cout << endl;
}
void output_displayBooks ()
{
    system("CLS");
    cout << setw(25) << setfill(' ') << " " <<  "|" << setw(68) << setfill('=') << "=" << "|" << endl;
    cout << setw(25) << setfill(' ') << " " << "|" << setw(19) << setfill(' ') << " " << setw(29) << "007-Library Management System" << setw(21) << setfill(' ') << right<< "|" << endl;
    cout << setw(25) << setfill(' ') << " " << "|" << setw(68) << setfill('=') << "=" << "|" << endl;

    cout << setw(25) << setfill(' ') << " " <<  "|" << setw(68) << setfill('=') << "=" << "|" << endl;
    cout << setw(25) << setfill(' ') << " " << "|" << setw(25) << setfill(' ') << " " << setw(18) << "Display All Books" << setw(26) << setfill(' ') << right << "|" << endl;
    cout << setw(25) << setfill(' ') << " " << "|" << setw(68) << setfill('=') << "=" << "|" << endl;
    cout << endl;

    cout << setw(9) << setfill(' ') << " " <<  "|" << setw(104) << setfill('-') << "-" << "|" << endl;
    cout << setw(9) << setfill(' ') << " " << "|"
         << " " << setw(8) << setfill(' ') << left <<  "ID" << "|"
         << " " << setw(45) << setfill(' ') << left <<  "Title" << "|"
         << " " << setw(27) << setfill(' ') << left <<  "Author" << "|"
         << " " << setw(6) << setfill(' ') << left <<  "Price" << "|"
         << " " << setw(9) << setfill(' ') << left <<  " Status" << "|"<< endl;
    cout << setw(9) << setfill(' ') << " " <<  "|" << setw(104) << setfill('-') << "-" << "|" << endl;
    cout << setw(9) << setfill(' ') << " " <<  "|" << setw(104) << setfill('-') << "-" << "|" << endl;

}
void output_authorBooks ()
{
    system("CLS");
    cout << setw(25) << setfill(' ') << " " <<  "|" << setw(68) << setfill('=') << "=" << "|" << endl;
    cout << setw(25) << setfill(' ') << " " << "|" << setw(19) << setfill(' ') << " " << setw(29) << "007-Library Management System" << setw(21) << setfill(' ') << right<< "|" << endl;
    cout << setw(25) << setfill(' ') << " " << "|" << setw(68) << setfill('=') << "=" << "|" << endl;

    cout << setw(25) << setfill(' ') << " " <<  "|" << setw(68) << setfill('=') << "=" << "|" << endl;
    cout << setw(25) << setfill(' ') << " " << "|" << setw(19) << setfill(' ') << " " << setw(31) << "Display All Books of an Author" << setw(19) << setfill(' ') << right << "|" << endl;
    cout << setw(25) << setfill(' ') << " " << "|" << setw(68) << setfill('=') << "=" << "|" << endl;
    cout << endl;

}
void output_unissuedBooks ()
{
    system("CLS");
    cout << setw(25) << setfill(' ') << " " <<  "|" << setw(68) << setfill('=') << "=" << "|" << endl;
    cout << setw(25) << setfill(' ') << " " << "|" << setw(19) << setfill(' ') << " " << setw(29) << "007-Library Management System" << setw(21) << setfill(' ') << right<< "|" << endl;
    cout << setw(25) << setfill(' ') << " " << "|" << setw(68) << setfill('=') << "=" << "|" << endl;

    cout << setw(25) << setfill(' ') << " " <<  "|" << setw(68) << setfill('=') << "=" << "|" << endl;
    cout << setw(25) << setfill(' ') << " " << "|" << setw(22) << setfill(' ') << " " << setw(24) << "List of Un-issued Books" << setw(23) << setfill(' ') << right << "|" << endl;
    cout << setw(25) << setfill(' ') << " " << "|" << setw(68) << setfill('=') << "=" << "|" << endl;
    cout << endl;

    cout << setw(9) << setfill(' ') << " " <<  "|" << setw(104) << setfill('-') << "-" << "|" << endl;
    cout << setw(9) << setfill(' ') << " " << "|"
         << " " << setw(8) << setfill(' ') << left <<  "ID" << "|"
         << " " << setw(45) << setfill(' ') << left <<  "Title" << "|"
         << " " << setw(27) << setfill(' ') << left <<  "Author" << "|"
         << " " << setw(6) << setfill(' ') << left <<  "Price" << "|"
         << " " << setw(9) << setfill(' ') << left <<  " Status" << "|"<< endl;
    cout << setw(9) << setfill(' ') << " " <<  "|" << setw(104) << setfill('-') << "-" << "|" << endl;
    cout << setw(9) << setfill(' ') << " " <<  "|" << setw(104) << setfill('-') << "-" << "|" << endl;
}
void output_sortBooks ()
{
    system("CLS");
    cout << setw(25) << setfill(' ') << " " <<  "|" << setw(68) << setfill('=') << "=" << "|" << endl;
    cout << setw(25) << setfill(' ') << " " << "|" << setw(19) << setfill(' ') << " " << setw(29) << "007-Library Management System" << setw(21) << setfill(' ') << right<< "|" << endl;
    cout << setw(25) << setfill(' ') << " " << "|" << setw(68) << setfill('=') << "=" << "|" << endl;

    cout << setw(25) << setfill(' ') << " " <<  "|" << setw(68) << setfill('=') << "=" << "|" << endl;
    cout << setw(25) << setfill(' ') << " " << "|" << setw(22) << setfill(' ') << " " << setw(23) << "Sorting Books by Book ID" << setw(23) << setfill(' ') << right << "|" << endl;
    cout << setw(25) << setfill(' ') << " " << "|" << setw(68) << setfill('=') << "=" << "|" << endl;
    cout << endl;
}
void output_loadBooks ()
{
    system("CLS");
    cout << setw(25) << setfill(' ') << " " <<  "|" << setw(68) << setfill('=') << "=" << "|" << endl;
    cout << setw(25) << setfill(' ') << " " << "|" << setw(19) << setfill(' ') << " " << setw(29) << "007-Library Management System" << setw(21) << setfill(' ') << right<< "|" << endl;
    cout << setw(25) << setfill(' ') << " " << "|" << setw(68) << setfill('=') << "=" << "|" << endl;

    cout << setw(25) << setfill(' ') << " " <<  "|" << setw(68) << setfill('=') << "=" << "|" << endl;
    cout << setw(25) << setfill(' ') << " " << "|" << setw(20) << setfill(' ') << " " << setw(29) << "Import Books Data form a File" << setw(20) << setfill(' ') << right << "|" << endl;
    cout << setw(25) << setfill(' ') << " " << "|" << setw(68) << setfill('=') << "=" << "|" << endl;
    cout << endl;
}
void output_exportBooksInfo(ofstream& outdata)
{
    system("CLS");
    cout << setw(25) << setfill(' ') << " " <<  "|" << setw(68) << setfill('=') << "=" << "|" << endl;
    cout << setw(25) << setfill(' ') << " " << "|" << setw(19) << setfill(' ') << " " << setw(29) << "007-Library Management System" << setw(21) << setfill(' ') << right<< "|" << endl;
    cout << setw(25) << setfill(' ') << " " << "|" << setw(68) << setfill('=') << "=" << "|" << endl;

    cout << setw(25) << setfill(' ') << " " <<  "|" << setw(68) << setfill('=') << "=" << "|" << endl;
    cout << setw(25) << setfill(' ') << " " << "|" << setw(22) << setfill(' ') << " " << setw(25) << "Save Books Info on a File" << setw(22) << setfill(' ') << right << "|" << endl;
    cout << setw(25) << setfill(' ') << " " << "|" << setw(68) << setfill('=') << "=" << "|" << endl;
    cout << endl;

    outdata << setw(25) << setfill(' ') << " " <<  "|" << setw(68) << setfill('=') << "=" << "|" << endl;
    outdata << setw(25) << setfill(' ') << " " << "|" << setw(19) << setfill(' ') << " " << setw(29) << "007-Library Management System" << setw(21) << setfill(' ') << right<< "|" << endl;
    outdata << setw(25) << setfill(' ') << " " << "|" << setw(68) << setfill('=') << "=" << "|" << endl;

    outdata << setw(25) << setfill(' ') << " " <<  "|" << setw(68) << setfill('=') << "=" << "|" << endl;
    outdata << setw(25) << setfill(' ') << " " << "|" << setw(22) << setfill(' ') << " " << setw(25) << "Save Books Info on a File" << setw(22) << setfill(' ') << right << "|" << endl;
    outdata << setw(25) << setfill(' ') << " " << "|" << setw(68) << setfill('=') << "=" << "|" << endl;
    outdata << endl;

    outdata << setw(9) << setfill(' ') << " " <<  "|" << setw(104) << setfill('-') << "-" << "|" << endl;
    outdata << setw(9) << setfill(' ') << " " << "|"
         << " " << setw(8) << setfill(' ') << left <<  "ID" << "|"
         << " " << setw(45) << setfill(' ') << left <<  "Title" << "|"
         << " " << setw(27) << setfill(' ') << left <<  "Author" << "|"
         << " " << setw(6) << setfill(' ') << left <<  "Price" << "|"
         << " " << setw(9) << setfill(' ') << left <<  " Status" << "|"<< endl;
    outdata << setw(9) << setfill(' ') << " " <<  "|" << setw(104) << setfill('-') << "-" << "|" << endl;
    outdata << setw(9) << setfill(' ') << " " <<  "|" << setw(104) << setfill('-') << "-" << "|" << endl;
}
