/****************************************
* Student Name : Jonathan White
* Date Due : 05 / 03 / 2022
* Date Submitted : 05 / 03 / 2022
* Program Name : Book Reservation System
* Program Description : A book reservation system capable of creating and deleting customers, creating books for them to rentand return, and displaying information on both the booksand the customers.*
**
*****************************************/



// Header files

#include<conio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include<stdio.h>
#include<iostream>
#include<fstream>
using namespace std;

//Class declaration

class library
{
	//Members of the class

	char title[50];
	char a_name[50];
	char name[50];
	char number[11];
	char choice;
	char f1[500];
	char f2[500];
	int stock;
	int edition;
	int isbn;
	int age;
	int validity;
	int code;
	int payment;
	int cheque_num;

public:
	//Methods of the class

	void header();
	void add_books();
	void menu();
	void password();
	void add_customer();
	void issue();
	void deposit();
	void customer_ac();
	// void customer_count();
	void book_stock();
	void rent();
	void remove_customer();
	void list_issue();
	void update_issue();
};

/*****************************
	Main function
******************************/

int main()
{
	library x;

	x.header();
	x.password();
	getch();
	return 0;

}

/****************************
*       Header Function     *
*****************************/

void library::header()
{
	system("clear");

	time_t t = time(0);
	char* str;
	str = ctime(&t);
	cout << str;

	cout << "\n\n\n\t\t********** WHITE WINGS LIBRARY RESERSVATION SYSTEM **********" << endl;
	cout << "\t\t\t      C-45 JLN WHITE,JONATHAN" << endl;
	cout << "\t\t\t     TELEPHONE :- (123) 456-6789 " << endl;
	cout << "\t\t\t       PIN CODE :- 302027" << endl << endl;
}

/*************************
*     Menu Function      *
**************************/


void library::menu()
{
	int choice;

point2:

	header();

	cout << "\t        1. Add Book" << endl;
	cout << "\t        2. Add Customer" << endl;
	cout << "\t        3. Rent Book" << endl;
	cout << "\t        4. Delete Customer" << endl;
	cout << "\t        5. Issue a book" << endl;
	cout << "\t        6. Return Book" << endl;
	cout << "\t        7. Deposit a book" << endl;
	cout << "\t        8. View members account" << endl;
	cout << "\t        9. Report current books information" << endl;
	cout << "\t        10.Report current customers information" << endl;
	cout << "\t        11.Exit" << endl << endl;
	cout << "\t	Enter your choice : ";
	cin >> choice;

	if (choice == 10)
	{
		cout << "\n\t\t! The program will be terminated............";
		getch();

		abort();
	}

	if (choice < 0 || choice>10)
	{
		cout << "\n\t        ! invalid input ! please try again ! " << endl << endl;
		goto point2;
	}


	else
	{
		if (choice == 1)
		{
			add_books();
		}
		if (choice == 2)
		{
			add_customer();
		}
		if (choice == 3)
		{
			system("clear");
			rent();
		}
		if (choice == 4)
		{
			system("clear");
			remove_customer();
		}
		if (choice == 5)
		{
			issue();
		}
		if (choice == 6)
		{
			deposit();
		}
		if (choice == 7)
		{
			customer_ac();
		}
		if (choice == 8)
		{
			book_stock();
		}
		if (choice == 9)
		{
			list_issue();
		}
	}
}

/***********************************
*      Add New Books Function      *
************************************/

void library::add_books()
{


point:

	header();

	cout << endl;

	ofstream outf;
	outf.open("books.txt", ios::app);

	cout << "\t\t Enter the ISBN number of the book : ";
	cin >> isbn;
	cout << "\t\t Enter the title of the book : ";
	cin >> title;
	cout << "\t\t Enter the author name of the book : ";
	cin >> a_name;
	cout << "\t\t Enter the edition of the book : ";
	cin >> edition;
	cout << "\t\t Enter the quantity of the book : ";
	cin >> stock;

	outf << isbn << "\n" << title << "\t\t" << a_name << "\t" << edition << "\t" << stock << endl;

	cout << "\n\n\t\t ! book is added succesfully !" << endl << endl;

	outf.close();

point1:

	cout << "\t\t Press 'y' to continue , press 'm' to go to menu , press 'n' to exit : ";
	cin >> choice;

	if (choice == 'y')
	{
		goto point;
	}

	if (choice == 'm')
	{
		menu();
	}

	if (choice == 'n')
	{
		cout << "\n\t\t ! The program will be terminated............";
		getch();

		abort();
	}

	else
	{
		cout << "\n\n\t\t ! invalid input ! try again !" << endl << endl;
		goto point1;
	}

}

/*************************
*  Password Function     *
**************************/



void library::password()
{
	int pass, flag = 3;

point:

	cout << "\t\t Enter the password : ";
	cin >> pass;

	flag--;

	if (pass != 3020)
	{
		if (flag > 0 && flag <= 3)
		{
			cout << "\n\t\t ! wrong password ! try again !" << endl << endl;
			cout << "\t\t ! you have " << flag << " chance to enter right password !" << endl << endl;

			goto point;
		}

		else
		{
			cout << "\n\t\t ! You have exceed the limit to enter the right password !" << endl;
			cout << "\t\t ! The program will be terminated............";

			getch();

			abort();
		}
	}

	else
	{
		menu();
	}
}

/****************************
*  Add New Customers Function *
*****************************/


void library::add_customer()
{
	system("clear");

po9:

	header();

	ofstream outf;
	outf.open("members.txt", ios::app);

	cout << "\n\t\t Enter the name : ";
	cin >> name;
	cout << "\t\t Enter the age : ";
	cin >> age;
	cout << "\t\t Enter the validity in years : ";
	cin >> validity;
	cout << "\t\t Enetr the telephone number : ";
	cin >> number;
	cout << "\t\t Enter the code of members : ";
	cin >> code;

	outf << code << "\n" << name << "\t" << number << "\t" << age << "\t" << validity << endl;

	cout << "\n\n\t\t The member is entered successfully !" << endl << endl;

	outf.close();

po:

	cout << "\t\t Press 'y' to continue , press 'm' to go to menu , press 'n' to exit : ";
	cin >> choice;

	if (choice == 'y')
	{
		goto po9;
	}

	if (choice == 'm')
	{
		system("clear");
		menu();
	}

	if (choice == 'n')
	{
		cout << "\n\t\t ! The program will be terminated............";
		getch();

		abort();
	}

	else
	{
		cout << "\n\n\t\t ! invalid input ! try again !" << endl << endl;
		goto po;
	}

}

/**************************
*  Rent Books Function   *
***************************/


void library::rent()
{
	int flag = 1, flag2 = 1;
	char is[50], isb[50], c[50], co[50], cod[50], sh[50];

issu:

	header();

	cout << endl;

	ifstream inf;

	inf.open("books.txt");

	cout << "\n\t\t enter the isbn number of the book : ";
	cin >> isb;

	while (!inf.eof())
	{
		inf.getline(is, 50);
		if (!strcmp(is, isb))
		{
			cout << "\n\t\t ! Book is found !" << endl << endl;
			cout << "\n\t\t isbn\tname of book\tauthor\t\tedition\tquantity\n";
			inf.getline(sh, 50);
			cout << "\n\t\t " << is << "\t" << sh << endl << endl << endl;
			flag = 0;
			break;
		}
	}

	inf.close();

	if (flag == 1 || flag == -1)
	{
		cout << "\n\t\t Book is not found !" << endl << endl;

	pre:

		cout << "\t\t Press 'y' to continue , press 'm' to go to menu , press 'n' to exit : ";
		cin >> choice;

		if (choice == 'y')
		{
			goto issu;
		}

		if (choice == 'm')
		{
			system("clear");
			menu();
		}

		if (choice == 'n')
		{
			cout << "\n\t\t! The program will be terminated............";
			getch();

			abort();
		}
		else
		{
			cout << "\n\n\t\t ! invalid input ! try again !" << endl << endl;
			goto pre;
		}
	}

	inf.open("members.txt");

	cout << "\t\t Enter the code of member : ";
	cin >> co;

	while (!inf.eof())
	{
		inf.getline(c, 50);
		if (!strcmp(c, co))
		{
			cout << "\n\t\t name\t\tnumber\t\tage\tvalidity\n";
			inf.getline(cod, 50);
			flag2 = 0;
			cout << "\n\t\t " << cod << endl << endl;
			break;
		}
	}

	if (flag2 != 0)
	{
		cout << "\n\t\t ! invalid code of member !" << endl << endl;

	back:

		cout << "\t\t Press 'y' to continue , press 'm' to go to menu , press 'n' to exit : ";
		cin >> choice;

		if (choice == 'y')
		{
			goto issu;
		}

		if (choice == 'm')
		{
			system("clear");
			menu();
		}

		if (choice == 'n')
		{
			cout << "\n\t\t! The program will be terminated............";
			getch();

			abort();
		}

		else
		{
			cout << "\n\n\t\t ! invalid input ! try again !" << endl << endl;
			goto back;
		}
	}

	if (flag2 == 0)
	{
		ofstream out;

		out.open("issue.txt", ios::app);
		out << co << "\n" << isb << endl;
		cout << "\n\t\t ! Book is issued succesfully !" << endl << endl;
		out.close();
	poi:

		cout << "\t\t Press 'y' to continue , press 'm' to go to menu , press 'n' to exit : ";
		cin >> choice;

		if (choice == 'y')
		{
			goto issu;
		}

		if (choice == 'm')
		{
			system("clear");
			menu();
		}

		if (choice == 'n')
		{
			cout << "\n\t\t! The program will be terminated............";
			getch();

			abort();
		}

		else
		{
			cout << "\n\n\t\t ! invalid input ! try again !" << endl << endl;
			goto poi;
		}
	}

	inf.close();
}

/*****************************************
*   Display Customer Information Function *
******************************************/


void library::customer_ac()
{
memb:

	int select, flag = 1, count = 0;
	char m[50];

	header();

	cout << "\n\t\t 1.All members.\n\t\t 2.Search member.";
	cout << "\n\t\t Enter your choice : ";
	cin >> select;

	ifstream inf;

	if (select == 1)
	{
		header();

		char st[50], str[50];

		inf.open("members.txt");

		while (!inf.eof())
		{
			inf.getline(m, 50);
			count++;
		}

		inf.close();

		cout << "\t\t code\t\tname\t\tnumber\t\tage\tvalidity\n";

		inf.open("members.txt");

		while (!inf.eof())
		{
			inf.getline(st, 50);
			inf.getline(str, 50);

			cout << "\n\t\t " << st << "\t\t" << str << endl;
		}

		cout << "\t\t Total members = " << count / 2 << endl;

		inf.close();

	poin:

		cout << "\n\t\t Press 'y' to continue , press 'm' to go to menu , press 'n' to exit : ";
		cin >> choice;

		if (choice == 'y')
		{
			goto memb;
		}

		if (choice == 'm')
		{
			system("clear");
			menu();
		}

		if (choice == 'n')
		{
			cout << "\n\t\t! The program will be terminated............";
			getch();

			abort();
		}

		else
		{
			cout << "\n\n\t\t ! invalid input ! try again !" << endl << endl;
			goto poin;
		}
	}

	if (select == 2)
	{
		char s[50];
		char st[50];
		char str[50];

		inf.open("members.txt");

		cout << "\n\t\t Enter the code of the member : ";
		cin >> s;

		while (!inf.eof())
		{
			inf.getline(st, 50);

			if (!strcmp(s, st))
			{
				inf.getline(str, 50);

				cout << "\n\t\t code\t\tname\t\tnumber\t\tage\tvalidity\n";
				cout << "\n\t\t " << st << "\t\t" << str << endl;
				flag = 0;
				break;
			}
		}

		inf.close();

		if (flag == 0)
		{
		bac:

			cout << "\n\t\t Press 'y' to continue , press 'm' to go to menu , press 'n' to exit : ";
			cin >> choice;

			if (choice == 'y')
			{
				goto memb;
			}

			if (choice == 'm')
			{
				system("clear");
				menu();
			}

			if (choice == 'n')
			{
				cout << "\n\t\t! The program will be terminated............";
				getch();

				abort();
			}

			else
			{
				cout << "\n\n\t\t ! invalid input ! try again !" << endl << endl;
				goto bac;
			}
		}

		if (flag == 1 || flag == -1)
		{
			cout << "\n\t\t ! invalid code of member !" << endl;
		po1:
			cout << "\n\t\t Press 'y' to continue , press 'm' to go to menu , press 'n' to exit : ";
			cin >> choice;

			if (choice == 'y')
			{
				goto memb;
			}

			if (choice == 'm')
			{
				system("clear");
				menu();
			}

			if (choice == 'n')
			{
				cout << "\n\t\t! The program will be terminated............";
				getch();

				abort();
			}
			else
			{
				cout << "\n\n\t\t ! invalid input ! try again !" << endl << endl;
				goto po1;
			}
		}
	}
}

/*******************************************
*  Display All Books In The Stock Function *
********************************************/


void library::book_stock()
{
	int ch, book_count = 0;
	char b[50], i[50];

sb:

	header();

	cout << "\n\t\t 1.All books.\n\t\t 2.search a book\n\t\t Enter your choice : ";
	cin >> ch;

	if (ch == 1)
	{
		header();
		ifstream inf;
		inf.open("books.txt");

		cout << "\t\t ISBN\ttital\t\tauthor\t\tedition\tquantity" << endl;

		while (!inf.eof())
		{
			inf.getline(b, 50);
			inf.getline(i, 50);
			cout << "\n\t\t " << b << "\t" << i << endl;
			book_count++;
		}

		cout << "\t\t Total number of books : " << book_count - 1 << endl;

		inf.close();

	po2:

		cout << "\n\t\t Press 'y' to continue , press 'm' to go to menu , press 'n' to exit : ";
		cin >> choice;

		if (choice == 'y')
		{
			goto sb;
		}

		if (choice == 'm')
		{
			system("clear");
			menu();
		}

		if (choice == 'n')
		{
			cout << "\n\t\t! The program will be terminated............";
			getch();

			abort();
		}
		else
		{
			cout << "\n\n\t\t ! invalid input ! try again !" << endl << endl;
			goto po2;
		}
	}

	if (ch == 2)
	{
		char isb[40], bn[50], mb[50];
		int f = 0;

		ifstream inf;

		inf.open("books.txt");

		cout << "\n\t\t Enter the isbn number of the book : ";
		cin >> isb;

		while (!inf.eof())
		{
			inf.getline(bn, 50);
			inf.getline(mb, 50);

			if (!strcmp(bn, isb))
			{
				cout << "\n\t\t isbn\tname of book\tauthor\t\tedition\tquantity\n";
				cout << "\n\t\t " << bn << "\t" << mb << endl;
				f = 1;
			}
		}

		if (f == 1)
		{
		po3:

			cout << "\n\t\t Press 'y' to continue , press 'm' to go to menu , press 'n' to exit : ";
			cin >> choice;

			if (choice == 'y')
			{
				goto sb;
			}

			if (choice == 'm')
			{
				system("clear");
				menu();
			}

			if (choice == 'n')
			{
				cout << "\n\t\t! The program will be terminated............";
				getch();

				abort();
			}
			else
			{
				cout << "\n\n\t\t ! invalid input ! try again !" << endl << endl;
				goto po3;
			}
		}

		if (f == 0)
		{
			cout << "\n\t\t ! Book  not found !" << endl;

		po4:

			cout << "\n\t\t Press 'y' to continue , press 'm' to go to menu , press 'n' to exit : ";
			cin >> choice;

			if (choice == 'y')
			{
				goto sb;
			}

			if (choice == 'm')
			{
				system("clear");
				menu();
			}

			if (choice == 'n')
			{
				cout << "\n\t\t! The program will be terminated............";
				getch();

				abort();
			}
			else
			{
				cout << "\n\n\t\t ! invalid input ! try again !" << endl << endl;
				goto po4;
			}
		}
	}
}

/*************************
* Rent Books Function *
**************************/

void library::issue()
{
depo:

	header();
	char memb[100];
	char c[100];
	char c1[100];
	int flagd = 0;

	cout << "\n\n\t\t Enter the code of member : ";
	cin >> memb;

	ifstream inf;
	inf.open("issue.txt");

	while (!inf.eof())
	{
		inf.getline(c, 100);


		if (!strcmp(c, memb))
		{
			cout << "\n\n\t\t Member is found......" << endl << endl;
			inf.getline(c1, 100);

			strcpy(f1, c);
			strcpy(f2, c1);

			cout << "\t\t ISBN number of the books issued is : " << c1 << endl;

			update_issue();

			cout << "\n\n\t\t The book is deposited successfully......." << endl << endl;
			flagd = 1;

		po5:

			cout << "\n\t\t Press 'y' to continue , press 'm' to go to menu , press 'n' to exit : ";
			cin >> choice;

			if (choice == 'y')
			{
				goto depo;
			}

			if (choice == 'm')
			{
				system("clear");
				menu();
			}

			if (choice == 'n')
			{
				cout << "\n\t\t! The program will be terminated............";
				getch();

				abort();
			}
			else
			{
				cout << "\n\n\t\t ! invalid input ! try again !" << endl << endl;
				goto po5;
			}
		}
	}

	inf.close();

	if (flagd == 0)
	{
		cout << "\n\n\t\t ! Member is not found !";

		cout << "\n\n\t\t Press 'y' to continue , press 'm' to go to menu , press 'n' to exit : ";
		cin >> choice;

		if (choice == 'y')
		{
			goto depo;
		}

		if (choice == 'm')
		{
			system("clear");
			menu();
		}

		if (choice == 'n')
		{
			cout << "\n\t\t! The program will be terminated............";
			getch();

			abort();
		}
		else
		{
			cout << "\n\n\t\t ! invalid input ! try again !" << endl << endl;
			goto po5;
		}
	}
}

/***************************
*     Return book function *
****************************/

void library::deposit()
{
pop:

	header();

	char remov[500];
	char k[500];
	int km, mm;
	char m[500];

	cout << "\n\n\t\t Enter the ISBN number of the book : ";
	cin >> remov;

	ifstream inf;
	inf.open("books.txt");

	ofstream outf;
	outf.open("temp.txt");

	while (!inf.eof())
	{
		inf.getline(k, 500);

		/* Convert character array k to string
		 * ex.: string tempString = string(k);
		 * Remove last character of k string
		 * ex.: string tempString1 = tempString.substr(0,tempString.size()-1);
		 * Convert character array remov to string
		 * ex.: string tempString2 = string(remov);
		 * in c++ you can compare string as if(string1 == string2)
		 */

		int b = strcmp(remov, k);

		if (b == 0)
		{
			inf.getline(k, 500);
			km = 1;
		}
		else
		{
			outf << k << endl;
		}
	}
	if (km == 1)
	{
		cout << "\n\n\t\t Book has been successfully removed.....";
		remove("books.txt");
		outf.close();
		inf.close();

		rename("temp.txt", "books.txt");

	gop:

		cout << "\n\n\t\t Press 'y' to continue , press 'm' to go to menu , press 'n' to exit : ";
		cin >> choice;

		if (choice == 'y')
		{
			goto pop;
		}

		if (choice == 'm')
		{
			system("clear");
			menu();
		}

		if (choice == 'n')
		{
			cout << "\n\t\t! The program will be terminated............";
			getch();

			abort();
		}
		else
		{
			cout << "\n\n\t\t ! invalid input ! try again !" << endl << endl;
			goto gop;
		}
	}

	else
	{
		cout << "\n\n\t\t ! ISBN number wrong !";

	pom:

		cout << "\n\n\t\t Press 'y' to continue , press 'm' to go to menu , press 'n' to exit : ";
		cin >> choice;

		if (choice == 'y')
		{
			goto pop;
		}

		if (choice == 'm')
		{
			system("clear");
			menu();
		}

		if (choice == 'n')
		{
			cout << "\n\t\t! The program will be terminated............";
			getch();

			abort();
		}
		else
		{
			cout << "\n\n\t\t ! invalid input ! try again !" << endl << endl;
			goto pom;
		}
	}
}

/******************
* Remove a customer *
*******************/


void library::remove_customer()
{
mom:

	header();

	char r[500], b[500];
	int c;

	cout << "\n\n\t\t Enter the code of the member : ";
	cin >> r;

	ifstream inf;
	inf.open("members.txt");
	ofstream outf;
	outf.open("temp.txt");

	while (!inf.eof())
	{
		inf.getline(b, 500);

		if (!strcmp(b, r))
		{
			c = 1;
			inf.getline(b, 500);
		}
		else
		{
			outf << b << endl;
		}
	}

	if (c == 1)
	{
		cout << "\n\n\t\t Member has been successfully removed....";
		inf.close();
		outf.close();
		remove("members.txt");
		rename("temp.txt", "members.txt");

	mop:

		cout << "\n\n\t\t Press 'y' to continue , press 'm' to go to menu , press 'n' to exit : ";
		cin >> choice;

		if (choice == 'y')
		{
			goto mom;
		}

		if (choice == 'm')
		{
			system("clear");
			menu();
		}

		if (choice == 'n')
		{
			cout << "\n\t\t! The program will be terminated............";
			getch();

			abort();
		}
		else
		{
			cout << "\n\n\t\t ! invalid input ! try again !" << endl << endl;
			goto mop;
		}
	}

	else
	{
		cout << "\n\n\t\t ! Invalid code of member !";

	job:

		cout << "\n\n\t\t Press 'y' to continue , press 'm' to go to menu , press 'n' to exit : ";
		cin >> choice;

		if (choice == 'y')
		{
			goto mom;
		}

		if (choice == 'm')
		{
			system("clear");
			menu();
		}

		if (choice == 'n')
		{
			cout << "\n\t\t! The program will be terminated............";
			getch();

			abort();
		}
		else
		{
			cout << "\n\n\t\t ! invalid input ! try again !" << endl << endl;
			goto job;
		}
	}

}

/*******************************
* List of books issued function*
********************************/

void library::list_issue()
{
	header();

	char l[500], m[500];

	ifstream inf("issue.txt");

	cout << "\t\t Code of member\t\tISBN number of book";

	while (!inf.eof())
	{
		inf.getline(l, 500);
		inf.getline(m, 500);

		cout << "\n\n\t\t\t " << l << "\t\t\t" << m << endl;
	}

boj:

	cout << "\t\t press 'm' to go to menu , press 'n' to exit : ";
	cin >> choice;

	if (choice == 'm')
	{
		system("clear");
		menu();
	}

	if (choice == 'n')
	{
		cout << "\n\t\t! The program will be terminated............";
		getch();

		abort();
	}
	else
	{
		cout << "\n\n\t\t ! invalid input ! try again !" << endl << endl;
		goto boj;
	}
}

/*************************
* Update books issue list*
**************************/

void library::update_issue()
{
	char buf[500];

	ofstream outf("temp.txt");
	ifstream inf("issue.txt");

	while (!inf.eof())
	{
		inf.getline(buf, 500);

		if (!strcmp(buf, f1))
		{
			inf.getline(buf, 500);
			inf.getline(buf, 500);
		}

		outf << buf << endl;
	}

	inf.close();
	outf.close();

	remove("issue.txt");
	rename("temp.txt", "issue.txt");
}
