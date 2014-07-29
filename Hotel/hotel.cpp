#include <fstream.h>
#include <conio.h>
#include <dos.h>
#include <string.h>
#include <process.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>


class menu
{
	private :
		void edit_menu(void) ;
		void report_menu(void) ;
		void room_edit_menu(void) ;
		void customer_edit_menu(void) ;

	public :
		void intro(void) ;
		void main_menu(void) ;
		void enter_password(void) ;

} ;



class room
{
	private :
		int recordno(int) ;
		void display_record(int) ;
		int roomno ;
		char roomcode[5] , status ;
		float tariff ;
	public :
		void add (void) ;
		void modify(void) ;
		void deletion(void) ;
		void display_room_record(void) ;
		void display_list(void) ;
		int room_found( int ) ;
		void change_status(int,char) ;
		char room_status(int) ;
		float get_data(int) ;

} ;




class customer
{
	private :
		int recordno(int) ;
		void display_record(int) ;
		void delete_record(int) ;
		int roomno ;
		char name[21] , phone[8] ;
		float advance , misc , room_srv ;
	public :
		void checkin (void) ;
		void checkout (void) ;
		void modify(void) ;
		void deletion(void) ;
		void display_list(void) ;
		void display_customer_record(void) ;

} ;



class account
{
	public :
		void prepare_bill(int, float, char t_name[21], float, float, float) ;
} ;




void menu :: intro ( void )
{
	clrscr() ;
	gotoxy(30,3) ;
	cout<<"Welcome to Project" ;
	gotoxy(30,5) ;
	cout<<" Hotel Management " ;
	gotoxy(30,6) ;
	cout<<" ----- ---------- " ;
	gotoxy(15,8) ;
	cout<<"This  project has the facility of maintaining " ;
	gotoxy(15,9) ;
	cout<<"records of ROOMS and CUSTOMERS." ;
	gotoxy(15,11) ;
	cout<<"This  project  can  hold more  than  10,000 room" ;
	gotoxy(15,12) ;
	cout<<"records at a time." ;
	gotoxy(15,14) ;
	cout<<"This project is very easy to work on and has self" ;
	gotoxy(15,15) ;
	cout<<"explanatory menus." ;
	gotoxy(15,17) ;
	cout<<"For the security reasons a password facility is " ;
	gotoxy(15,18) ;
	cout<<"also provided in this project." ;
	cout<<"\t" ;
	gotoxy(40,20) ;
	cout<<"By Harsh & Prateek";
	gotoxy(20,23) ;
	cout<<"Press any key to continue..." ;
	getch() ;
	main_menu();
}

void menu :: enter_password()
{
	clrscr() ;
	char pass1, pass2, pass3 ;
	gotoxy(30,12) ;
	cout<<"Enter the password : " ;
	pass1=getch() ;
	cout<<"*" ;
	pass2=getch() ;
	cout<<"*" ;
	pass3=getch() ;
	cout<<"*" ;
	getch();
	if (pass1 == 'c' && pass2 == '+' && pass3 == '+')
	     {
		return ;
	     }
	clrscr();
	gotoxy(30,12) ;
	cout<<"   WRONG PASSWORD   " ;
	gotoxy(2,1) ;
	getch() ;
	exit(0) ;
}



void menu :: main_menu(void)
{
	char ch ;
	clrscr();
	gotoxy(14,2);
	cout<<"*********** M . A . I . N  -  M . E . N . U ***********";
	gotoxy(30,5) ;
	cout<<"1. INTRODUCTION" ;
	gotoxy(30,7) ;
	cout<<"2. CHECK IN" ;
	gotoxy(30,9) ;
	cout<<"3. CHECK OUT" ;
	gotoxy(30,11) ;
	cout<<"4. CUSTOMER RECORD" ;
	gotoxy(30,13) ;
	cout<<"5. ROOM RECORD" ;
	gotoxy(30,15) ;
	cout<<"6. EDIT" ;
	gotoxy(30,17) ;
	cout<<"7. REPORT" ;
	gotoxy(30,19) ;
	cout<<"8. EXIT TO DOS" ;
	gotoxy(55,25) ;
	cout<<" Harsh & Prateek " ;
	gotoxy(30,21) ;
	cout<<"Enter your choice : " ;
	cin>>ch;
	getch();
	if ( ch == '1' )
		intro() ;
		else
		if ( ch == '2' )
		{
			customer c ;
			c.checkin() ;
		}
		else
		if ( ch == '3' )
		{
			customer c ;
			c.checkout() ;
		}
		if ( ch == '4' )
		{
			customer c ;
			c.display_customer_record() ;
		}
		else
		if ( ch == '5' )
		{
			room r ;
			r.display_room_record() ;
		}
		else
		if ( ch == '6' )
			edit_menu() ;
		else
		if ( ch == '7' )
			report_menu() ;
		else
		if ( ch == '8' )
		 {
			clrscr();
			gotoxy(26,10);
			cout<<" THANK U FOR USING OUR PROJECT ";
			getch();
			gotoxy(32,12);
			cout<<" HAVE A NICE DAY " ;
			getch();
			exit(0);
		}
}



void menu :: edit_menu(void)
{
	char ch ;
	while(1)
	{
		clrscr() ;
		gotoxy(34,4) ;
		cout<<"     EDIT" ;
		gotoxy(30,8) ;
		cout<<"1. ROOM RECORDS" ;
		gotoxy(30,10) ;
		cout<<"2. CUSTOMER RECORDS" ;
		gotoxy(30,12) ;
		cout<<"3. BACK" ;
		gotoxy(30,15) ;
		cout<<"Enter your choice : " ;
		cin>>ch;
		getch() ;
		if ( ch == '1' )
			room_edit_menu() ;
		else
		if ( ch == '2' )
			customer_edit_menu() ;
		else
		if ( ch == '3' )
			main_menu();

	}
}



void menu :: room_edit_menu(void)
{
	char ch ;
	while(1)
	{
		clrscr() ;
		gotoxy(34,4);
		cout<<"EDIT ROOM";
		gotoxy(30,8) ;
		cout<<"1. ADD ROOM RECORDS" ;
		gotoxy(30,10) ;
		cout<<"2. MODIFY ROOM RECORDS" ;
		gotoxy(30,12) ;
		cout<<"3. DELETE ROOM RECORDS" ;
		gotoxy(30,14) ;
		cout<<"4. BACK" ;
		gotoxy(30,17) ;
		cout<<"Enter your choice : " ;
		cin>>ch;
		getch() ;
		if ( ch == '1' )
		{
			room r ;
			r.add() ;
		}
		else
		if ( ch == '2' )
		{
			room r ;
			r. modify() ;
		}
		else
		if ( ch == '3' )
		{
			room r ;
			r.deletion() ;
		}
		else
		if ( ch == '4' )
			break ;
	}
}



void menu :: customer_edit_menu(void)
{
	char ch ;
	while(1)
	{
		clrscr() ;
		gotoxy(34,4);
		cout<<"EDIT CUSTOMER";
		gotoxy(30,8) ;
		cout<<"1. MODIFY CUSTOMER RECORDS" ;
		gotoxy(30,10) ;
		cout<<"2. DELETE CUSTOMER RECORDS" ;
		gotoxy(30,12) ;
		cout<<"3. BACK" ;
		gotoxy(30,15) ;
		cout<<"Enter your choice : " ;
		cin>>ch;
		getch() ;
		if ( ch == '1' )
		{
			customer c ;
			c.modify() ;
		}
		else
		if ( ch == '2' )
		{
			customer c ;
			c.deletion() ;
		}
		else
		if ( ch == '3' )
			break ;
	}
}



void menu :: report_menu(void)
{
	char ch ;
	while(1)
	{
		clrscr() ;
		gotoxy(34,4);
		cout<<"REPORT";
		gotoxy(30,8) ;
		cout<<"1. LIST OF ROOMS" ;
		gotoxy(30,10) ;
		cout<<"2. LIST OF CUSTOMERS" ;
		gotoxy(30,12) ;
		cout<<"3. BACK" ;
		gotoxy(30,15) ;
		cout<<"Enter your choice : " ;
		cin>>ch;
		getch() ;
		if ( ch == '1' )
		{
			room r ;
			r.display_list() ;
		}
		else
		if ( ch == '2' )
		{
			customer c ;
			c.display_list() ;
		}
		else
		if ( ch == '3' )
		{
			main_menu();
			break ;
		}
	}
}



int room :: room_found ( int t_roomno )
{
	fstream file ;
	file.open("ROOM.DAT", ios::in) ;
	file.seekg(0) ;
	int found = 0 ;
	while (file.read((char *) this, sizeof(room)))
	{
		if ( roomno == t_roomno )
			found = 1 ;
	}
	file.close() ;
	return found ;
}



void room :: display_list (void)
{
	clrscr() ;
	fstream file ;
	file.open("ROOM.DAT", ios::in) ;
	file.seekg(0) ;
	int row = 5 , found = 0 , pageno = 1 ;
	gotoxy(18,1) ;
	cout<<"LIST OF ROOMS" ;
	gotoxy(1,3) ;
	cout<<" Room code     Room no.     Status       Tariff " ;
	while (file.read((char *) this, sizeof(room)))
	{
		delay(50) ;
		found = 1 ;
		gotoxy(2,row) ;
		cout<<roomcode ;
		gotoxy(16,row) ;
		cout	<<roomno ;
		gotoxy(29,row) ;
		cout	<<status ;
		gotoxy(42,row) ;
		cout	<<tariff ;
		if ( row == 23 )
		{
			row = 5 ;
			gotoxy(66,1) ;
			cout<<"Page no. : " <<pageno ;
			pageno++ ;
			gotoxy(1,25) ;
			cout<<"Press any key to continue..." ;
			getch() ;
			clrscr() ;
			gotoxy(18,1) ;
			cout<<"LIST OF ROOMS" ;
			gotoxy(1,5) ;
			cout<<" Room code     Room no.     Status       Tariff " ;
		}
		else
			row++ ;
	}
	if ( !found )
	{
		gotoxy(1,5) ;
		cout<<"Records not found" ;
	}
	gotoxy(66,1) ;
	cout<<"Page no. : " <<pageno ;
	gotoxy(1,25) ;
	cout<<"Press any key to continue..." ;
	getch() ;
	file.close () ;
}


int room :: recordno(int t_roomno)
{
	fstream file ;
	file.open("ROOM.DAT", ios::in) ;
	file.seekg(0) ;
	int count = 0 ;
	while (file.read((char *) this, sizeof(room)))
	{
		count++ ;
		if (t_roomno == roomno)
			break ;
	}
	file.close() ;
	return count ;
}



void room :: display_record(int t_roomno)
{
	fstream file ;
	file.open("ROOM.DAT", ios::in) ;
	file.seekg(0) ;
	int found = 0 ;
	while (file.read((char *) this, sizeof(room)) && !found)
	{
		if (t_roomno == roomno)
		{
			found = 1 ;
			gotoxy(1,5) ;
			cout<<"Room code : " <<roomcode ;
			gotoxy(1,6) ;
			cout<<"Room no.  : " <<roomno ;
			gotoxy(1,7) ;
			cout<<"Status    : " <<status ;
			gotoxy(1,8) ;
			cout<<"Tariff    : " <<tariff ;
		}
	}
	file.close () ;
}


void room :: display_room_record(void)
{
	clrscr() ;
	menu m;
	int valid ;
	int t_roomno ;
	gotoxy(1,3) ;
	cout<<"Enter the Room no. : " ;
	cin>>t_roomno ;
	if (!room_found(t_roomno))
	{
		gotoxy(1,25) ;	clreol() ;
		gotoxy(1,24) ;
		cout<<"ROOM NO. NOT FOUND" ;
		gotoxy(1,25) ;
		cout<<"Press any key to continue..." ;
		getch() ;
		m.main_menu();
	}
	clrscr() ;
	gotoxy(5,3) ;
	cout<<"ROOM RECORD" ;
	display_record(t_roomno) ;
	gotoxy(1,25) ;
	cout<<"Press any key to continue..." ;
	getch() ;
	m.main_menu();
}


void room :: change_status(int t_roomno , char t_status)
{
	int recno ;
	recno = recordno(t_roomno) ;
	fstream file ;
	file.open("ROOM.DAT", ios::out | ios::ate) ;
	int location ;
	location = (recno-1) * sizeof(room) ;
	file.seekp(location) ;
	status = t_status  ;
	file.write((char *) this, sizeof(room)) ;
	file.close () ;
}



char room :: room_status(int t_roomno)
{
	fstream file ;
	file.open("ROOM.DAT", ios::in) ;
	file.seekg(0) ;
	int found = 0 ;
	char t_status ;
	while (file.read((char *) this, sizeof(room)) && !found)
	{
		if (t_roomno == roomno)
		{
			found = 1 ;
			t_status = status ;
		}
	}
	file.close () ;
	return t_status ;
}


float room :: get_data(int t_roomno)
{
	fstream file ;
	file.open("ROOM.DAT", ios::in) ;
	file.seekg(0) ;
	float t_tariff ;
	while (file.read((char *) this, sizeof(room)))
	{
		if (t_roomno == roomno)
		{
			t_tariff = tariff ;
			break ;
		}
	}
	file.close() ;
	return t_tariff ;
}


void room :: add (void)
{
	char ch ;
	char t_rcode[5] ;
	int t_roomno ;
	char t_status ;
	float t_tariff ;
	do
	{
	fstream file ;
	file.open("ROOM.DAT", ios::out | ios::app ) ;
	clrscr() ;
	gotoxy(1,1) ;
	cout<<"Enter the details for the room" ;
	gotoxy(1,3) ;
	cout<<"Code     :  " ;
	gotoxy(1,4) ;
	cout<<"Room no. :  " ;
	gotoxy(1,5) ;
	cout<<"Status   :  " ;
	gotoxy(1,6) ;
	cout<<"Tariff   :  " ;
	gotoxy(20,11) ;
	cout<<"SS : SINGLE SUIT" ;
	gotoxy(20,12) ;
	cout<<"SR : SINGLE ROOM" ;
	gotoxy(20,13) ;
	cout<<"DR : DOUBLE ROOM" ;
	gotoxy(20,14) ;
	cout<<"DS : DOUBLE SUIT" ;
	int valid = 0 ;
	do
	{
		valid = 1 ;
		gotoxy(1,25) ;
		cout<<"ENTER THE ROOM CODE (SS/SR/DR/DS)" ;
		gotoxy(13,3) ;
		cin>>t_rcode ;
		strupr(t_rcode) ;
		char *string[4] = {"SS","DR","SR","DS"} ;
		int result , count = 0 ;
		for ( int i=0; i<4; i++ )
		{
			result = strcmpi(t_rcode,string[i]) ;
			if ( result != 0 )
			count++ ;
		}
		if ( count == 4 )
		{
			valid = 0 ;
			gotoxy(1,25) ;	clreol() ;
			gotoxy(1,24) ;
			cout<<"INVALID CODE" ;
			gotoxy(1,25) ;
			cout<<"Press any key to continue..." ;
			getch() ;
			gotoxy(1,24) ;	clreol() ;
			gotoxy(1,25) ;	clreol() ;
			gotoxy(13,3) ;	clreol() ;
		}
	} while ( valid == 0 ) ;
	for ( int i=11; i<=14; i++ )
	{
		gotoxy(1,i) ;	clreol() ;
	}
	do
	{
		valid = 1 ;
		gotoxy(1,25) ; clreol() ;
		gotoxy(1,25) ;
		cout<<"ENTER THE ROOM NUMBER" ;
		gotoxy(13,4) ;
		cin>>t_roomno ;
		getch();
		if ( t_roomno <= 0 || t_roomno > 900 )
		{
			valid = 0 ;
			gotoxy(1,25) ;	clreol() ;
			gotoxy(1,24) ;
			cout<<"IT SHOULD NOT BE NEGATIVE OR ZERO OR GREATER THAN 900" ;
			gotoxy(1,25) ;
			cout<<"Press any key to continue..." ;
			getch() ;
			gotoxy(1,24) ;	clreol() ;
			gotoxy(1,25) ;	clreol() ;
			gotoxy(13,4) ;	clreol() ;
		}
		if ( room_found( t_roomno ) )
		{
			valid = 0 ;
			gotoxy(1,25) ;	clreol() ;
			gotoxy(1,24) ;
			cout<<"ROOM NO. ALREADY EXIST" ;
			gotoxy(1,25) ;
			cout<<"Press any key to continue..." ;
			getch() ;
			gotoxy(1,24) ;	clreol() ;
			gotoxy(1,25) ;	clreol() ;
			gotoxy(13,4) ;	clreol() ;
		}
	} while ( !valid ) ;
	do
	{
		valid = 1 ;
		gotoxy(1,25) ;	clreol() ;
		gotoxy(1,25) ;
		cout<<"ENTER THE ROOM STATUS : V=vacant, O=occupied" ;
		gotoxy(13,5) ;
		cin>>t_status ;
		t_status = toupper(t_status) ;
		if (t_status != 'O' && t_status != 'V')
		{
			valid = 0 ;
			gotoxy(1,25) ;	clreol() ;
			gotoxy(1,24) ;
			cout<<"INVALID DATA ENTERED" ;
			gotoxy(1,25) ;
			cout<<"Press any key to continue..." ;
			getch() ;
			gotoxy(1,24) ;	clreol() ;
			gotoxy(1,25) ;	clreol() ;
			gotoxy(13,5) ;	clreol() ;
		}
	} while ( !valid ) ;
	do
	{
		valid = 1 ;
		gotoxy(1,25) ;	clreol() ;
		gotoxy(1,25) ;
		cout<<"ENTER THE TARIFF FOR THE ROOM" ;
		gotoxy(13,6) ;
		cin>>t_tariff ;
		getch();
		if ( t_tariff <= 0 )
		{
			valid = 0 ;
			gotoxy(1,25) ;	clreol() ;
			gotoxy(1,24) ;
			cout<<"IT SHOULD NOT BE NEGATIVE OR ZERO" ;
			gotoxy(1,25) ;
			cout<<"Press any key to continue..." ;
			getch() ;
			gotoxy(1,24) ;	clreol() ;
			gotoxy(1,25) ;	clreol() ;
			gotoxy(13,6) ;	clreol() ;
		}
	} while ( !valid ) ;
	gotoxy(1,8) ;
	cout<<"Do you want to save the record (y/n)  :  " ;
	do
	{
		valid = 1 ;
		gotoxy(42,8) ;
		cin>>ch;
		getch() ;
		ch = toupper(ch) ;
		if (ch != 'Y' && ch != 'N')
		{
			valid = 0 ;
			gotoxy(42,8) ;	clreol() ;
		}
	} while ( !valid ) ;
	if (ch == 'Y')
	{
		strcpy(roomcode,t_rcode) ;
		roomno  = t_roomno  ;
		status  = t_status  ;
		tariff = t_tariff ;
		file.write((char *) this, sizeof(room)) ;
	}
	gotoxy(1,9) ;
	cout<<"Do you want to add more records (y/n) :  " ;
	do
	{
		valid = 1 ;
		gotoxy(42,9) ;
		cin>>ch;
		getch() ;
		ch = toupper(ch) ;
		if (ch != 'Y' && ch != 'N')
		{
			valid = 0 ;
			gotoxy(42,9) ;	clreol() ;
		}
	} while ( !valid ) ;
	file.close () ;
	} while ( ch == 'Y') ;
}


void room :: modify(void)
{
	clrscr() ;
	int valid ;
	char ch ;
	char t_rcode[5] ;
	int t_roomno , tr ;
	char t_status ;
	float t_tariff ;
	fstream file ;
	file.open("ROOM.DAT", ios::out | ios::ate) ;
	gotoxy(1,3) ;
	cout<<"Enter the Room no. to be modified " ;
	cin>>tr ;
	getch();
	if ( !room_found( tr ) )
	{
		gotoxy(1,25) ;	clreol() ;
		gotoxy(1,24) ;
		cout<<"ROOM NO. NOT FOUND" ;
		gotoxy(1,25) ;
		cout<<"Press any key to continue..." ;
		getch() ;
		return ;
	}
	display_record(tr) ;
	gotoxy(1,10) ;
	cout<<"Do you want to modify this Room Record (y/n) : " ;
	do
	{
		valid = 1 ;
		gotoxy(48,10) ;
		cin>>ch;
		getch() ;
		ch = toupper(ch) ;
		if (ch != 'Y' && ch != 'N')
		{
			valid = 0 ;
			gotoxy(42,9) ;	clreol() ;
		}
	} while ( !valid ) ;
	if (ch == 'N')
		return ;
	gotoxy(1,12) ;
	cout<<"ENTER THE NEW DATA FOR THE ROOM" ;
	gotoxy(1,14) ;
	cout<<"Code     :  " ;
	gotoxy(1,15) ;
	cout<<"Room no. :  " ;
	gotoxy(1,16) ;
	cout<<"Status   :  " ;
	gotoxy(1,17) ;
	cout<<"Tariff   :  " ;
	do
	{
		valid = 1 ;
		gotoxy(1,25) ;
		cout<<"ENTER THE ROOM CODE (SS/SR/DR/DS)" ;
		gotoxy(13,14) ;
		cin>>t_rcode ;
		getch();
		strupr(t_rcode) ;
		char *string[4] = {"SS","DR","SR","DS"} ;
		int result , count = 0 ;
		for ( int i=0; i<4; i++ )
		{
			result = strcmpi(t_rcode,string[i]) ;
			if ( result != 0 )
			count++ ;
		}
		if ( count == 4 )
		{
			valid = 0 ;
			gotoxy(1,25) ;	clreol() ;
			gotoxy(1,24) ;
			cout<<"INVALID CODE" ;
			gotoxy(1,25) ;
			cout<<"Press any key to continue..." ;
			getch() ;
			gotoxy(1,24) ;	clreol() ;
			gotoxy(1,25) ;	clreol() ;
			gotoxy(13,14) ; clreol() ;
		}
	} while ( valid == 0 ) ;
	do
	{
		valid = 1 ;
		gotoxy(1,25) ; clreol() ;
		gotoxy(1,25) ;
		cout<<"ENTER THE ROOM NUMBER" ;
		gotoxy(13,15) ;
		cin>>t_roomno ;
		getch();
		if ( t_roomno <= 0 || t_roomno > 900 )
		{
			valid = 0 ;
			gotoxy(1,25) ;	clreol() ;
			gotoxy(1,24) ;
			cout<<"IT SHOULD NOT BE NEGATIVE OR ZERO OR GREATER THAN 900" ;
			gotoxy(1,25) ;
			cout<<"Press any key to continue..." ;
			getch() ;
			gotoxy(1,24) ;	clreol() ;
			gotoxy(1,25) ;	clreol() ;
			gotoxy(13,15) ; clreol() ;
		}
		if ( room_found( t_roomno ) && t_roomno != tr )
		{
			valid = 0 ;
			gotoxy(1,25) ;	clreol() ;
			gotoxy(1,24) ;
			cout<<"ROOM NO. ALREADY EXIST" ;
			gotoxy(1,25) ;
			cout<<"Press any key to continue..." ;
			getch() ;
			gotoxy(1,24) ;	clreol() ;
			gotoxy(1,25) ;	clreol() ;
			gotoxy(13,15) ; clreol() ;
		}
	} while ( !valid ) ;
	do
	{
		valid = 1 ;
		gotoxy(1,25) ;	clreol() ;
		gotoxy(1,25) ;
		cout<<"ENTER THE ROOM STATUS : V=vacant, O=occupied" ;
		gotoxy(13,16) ;
		cin>>t_status ;
		getch();
		t_status = toupper(t_status) ;
		if (t_status != 'O' &&  t_status != 'V')
		{
			valid = 0 ;
			gotoxy(1,25) ;	clreol() ;
			gotoxy(1,24) ;
			cout<<"INVALID DATA ENTERED" ;
			gotoxy(1,25) ;
			cout<<"Press any key to continue..." ;
			getch() ;
			gotoxy(1,24) ;	clreol() ;
			gotoxy(1,25) ;	clreol() ;
			gotoxy(13,16) ; clreol() ;
		}
	} while ( !valid ) ;
	do
	{
		valid = 1 ;
		gotoxy(1,25) ;	clreol() ;
		gotoxy(1,25) ;
		cout<<"ENTER THE TARIFF FOR THE ROOM" ;
		gotoxy(13,17) ;
		cin>>t_tariff ;
		getch();
		if ( t_tariff <= 0 )
		{
			valid = 0 ;
			gotoxy(1,25) ;	clreol() ;
			gotoxy(1,24) ;
			cout<<"IT SHOULD NOT BE NEGATIVE OR ZERO" ;
			gotoxy(1,25) ;
			cout<<"Press any key to continue..." ;
			getch() ;
			gotoxy(1,24) ;	clreol() ;
			gotoxy(1,25) ;	clreol() ;
			gotoxy(13,17) ; clreol() ;
		}
	} while ( !valid ) ;
	gotoxy(1,19) ;
	cout<<"Do you want to save the record (y/n)  :  " ;
	do
	{
		valid = 1 ;
		gotoxy(42,19) ;
		ch = getch() ;
		ch = toupper(ch) ;
		if (ch != 'Y' && ch != 'N')
		{
			valid = 0 ;
			gotoxy(42,19) ; clreol() ;
		}
	} while ( !valid ) ;
	if (ch == 'Y')
	{
		int recno ;
		recno = recordno(tr) ;
		int location ;
		location = (recno-1) * sizeof(room) ;
		file.seekp(location) ;
		strcpy(roomcode,t_rcode) ;
		roomno  = t_roomno  ;
		status  = t_status  ;
		tariff = t_tariff ;
		file.write((char *) this, sizeof(room)) ;
	}
	file.close () ;
}


void room :: deletion(void)
{
	clrscr() ;
	int valid ;
	char ch ;
	int t_roomno ;
	gotoxy(1,3) ;
	cout<<"Enter the Room no. to be deleted " ;
	cin>>t_roomno ;
	if ( !room_found( t_roomno ) )
	{
		gotoxy(1,25) ; clreol() ;
		gotoxy(1,24) ;
		cout<<"ROOM NO. NOT FOUND" ;
		gotoxy(1,25) ;
		cout<<"Press any key to continue..." ;
		getch() ;
		return ;
	}
	display_record(t_roomno) ;
	gotoxy(1,10) ;
	cout<<"Do you want to delete this Room Record (y/n) : " ;
	do
	{
		valid = 1 ;
		gotoxy(48,10) ;
		cin>>ch ;
		getch() ;
		ch = toupper(ch) ;
		if (ch != 'Y' && ch != 'N')
		{
			valid = 0 ;
			gotoxy(42,9) ;	clreol() ;
		}
	} while ( !valid ) ;
	if (ch == 'N')
		return ;
	fstream file ;
	file.open("ROOM.DAT", ios::in) ;
	fstream temp ;
	temp.open("temp.dat", ios::out) ;
	while ( !file.eof() )
	{
		file.read((char *) this, sizeof(room)) ;
		if ( file.eof() )
			break ;
		if ( roomno != t_roomno )
			temp.write((char *) this, sizeof(room)) ;
	}
	file.close() ;
	temp.close() ;
	file.open("ROOM.DAT", ios::out) ;
	temp.open("temp.dat", ios::in) ;
	temp.seekg(0) ;
	while ( !temp.eof() )
	{
		temp.read((char *) this, sizeof(room)) ;
		if ( temp.eof() )
			break ;
		file.write((char *) this, sizeof(room)) ;
	}
	file.close() ;
	temp.close() ;
}


void customer :: display_list(void)
{
	clrscr() ;
	fstream file ;
	file.open("CUSTOMER.DAT", ios::in) ;
	file.seekg(0) ;
	int row = 5 ;
	int found = 0 ;
	int pageno = 1 ;
	int total = 0 ;
	gotoxy(18,1) ;
	cout<<"LIST OF CUSTOMERS" ;
	gotoxy(1,3) ;
	cout<<" Room no.  Name                  Phone        Room service   Advance   Misc." ;
	while (file.read((char *) this, sizeof(customer)))
	{
		total++ ;
	   	found = 1 ;
		gotoxy(2,row) ;
		cout<<roomno ;
		gotoxy(12,row) ;
		puts(name) ;
		fflush(stdout) ;
		gotoxy(34,row) ;
		cout<<phone ;
		gotoxy(47,row) ;
		cout<<room_srv ;
		gotoxy(62,row) ;
		cout<<advance ;
		gotoxy(72,row) ;
		cout<<misc ;
		if ( row == 23 )
		{
			row = 5 ;
			gotoxy(66,1) ;
			cout<<"Page no. : " <<pageno ;
			pageno++ ;
			gotoxy(1,25) ;
			cout<<"Press any key to continue..." ;
			getch() ;
			clrscr() ;
			gotoxy(18,1) ;
			cout<<"LIST OF CUSTOMERS" ;
			gotoxy(1,3) ;
			cout<<" Room no.  Name                  Phone        Room service   Advance   Misc." ;
		}
		else
			row++ ;
	}
	if ( found==0 )
	{
		gotoxy(1,5) ;
		cout<<"Records not found" ;
	}
	gotoxy(66,1) ;
	cout<<"Page no. : " <<pageno ;
	gotoxy(1,25) ;
	cout<<"Press any key to continue..." ;
	getch() ;
	clrscr() ;
	gotoxy(5,5) ;
	cout<<"Total no. of Customers = " <<total ;
	gotoxy(1,25) ;
	cout<<"Press any key to continue..." ;
	getch() ;
	file.close () ;
}


void customer :: checkin(void)
{
	room r ;
	menu m1;
	char ch ;
	int valid = 1 ;
	int   t_roomno , t_no_cust ;
	char  t_name[21] , t_address[35] , t_phone[8] , t_nation[16] , t_passport[30] ;
	float t_advance , t_misc , t_room_srv ;
	clrscr() ;
	gotoxy(1,1) ;
	cout<<"Enter the details of the Customer" ;
	gotoxy(1,3) ;
	cout<<"Room no.         : " ;
	gotoxy(1,4) ;
	cout<<"Name             : " ;
	gotoxy(1,5) ;
	cout<<"No. of guests    : " ;
	gotoxy(1,6) ;
	cout<<"Address          : " ;
	gotoxy(1,7) ;
	cout<<"Phone            : " ;
	gotoxy(1,8) ;
	cout<<"Nationality      : " ;
	gotoxy(1,9) ;
	cout<<"Passport no.     : " ;
	gotoxy(1,11) ;
	cout<<"Advance          : " ;
	gotoxy(1,12) ;
	cout<<"Miscellineous    : " ;
	gotoxy(1,13) ;
	cout<<"Room service     : " ;
	gotoxy(20,3) ;
	cin>>t_roomno ;
	char t_status ;
	t_status = r.room_status(t_roomno) ;
	if (!r.room_found(t_roomno) || t_status == 'O')
	{
		gotoxy(1,25) ;	clreol() ;
		gotoxy(1,24) ;
		cout<<"ROOM NO. NOT FOUND OR NOT VACANT" ;
		gotoxy(1,25) ;
		cout<<"Press any key to continue..." ;
		getch() ;
		m1.main_menu() ;
	}
	do
	{
		valid = 1 ;
		gotoxy(1,25) ;	clreol() ;
		gotoxy(1,25) ;
		cout<<"ENTER THE NAME OF THE CUSTOMER" ;
		gotoxy(20,4) ;
		gets(t_name) ;
		strupr(t_name) ;
		fflush(stdin) ;
		if ((strlen(t_name) <= 0) || (strlen(t_name) > 20))
		{
			valid = 0 ;
			gotoxy(1,25) ;	clreol() ;
			gotoxy(1,24) ;
			cout<<"LENGTH SHOULD NOT BE ZERO OR GREATER THAN 20" ;
			gotoxy(1,25) ;
			cout<<"Press any key to continue..." ;
			getch() ;
			gotoxy(1,24) ;	clreol() ;
			gotoxy(1,25) ;	clreol() ;
			gotoxy(20,4) ; clreol() ;
		}
	} while ( !valid ) ;
	do
	{
		valid = 1 ;
		gotoxy(1,25) ;	clreol() ;
		gotoxy(1,25) ;
		cout<<"ENTER THE NO. OF GUESTS WITH THE CUSTOMER" ;
		gotoxy(20,5) ;
		cin>>t_no_cust ;
		if ((t_no_cust < 0) || (t_no_cust > 4))
		{
			valid = 0 ;
			gotoxy(1,25) ;	clreol() ;
			gotoxy(1,24) ;
			cout<<"GUESTS SHOULD NOT BE LESS THAN 0 OR GREATER THAN 4" ;
			gotoxy(1,25) ;
			cout<<"Press any key to continue..." ;
			getch() ;
			gotoxy(1,24) ;	clreol() ;
			gotoxy(1,25) ;	clreol() ;
			gotoxy(20,5) ;	clreol() ;
		}
	} while ( !valid ) ;
	do
	{
		valid = 1 ;
		gotoxy(1,25) ;	clreol() ;
		gotoxy(1,25) ;
		cout<<"ENTER THE ADDRESS OF THE CUSTOMER" ;
		gotoxy(20,6) ;
		gets(t_address) ;
		fflush(stdin) ;
		if ((strlen(t_address) <= 0) || (strlen(t_address) > 50))
		{
			valid = 0 ;
			gotoxy(1,25) ;	clreol() ;
			gotoxy(1,24) ;
			cout<<"LENGTH SHOULD NOT BE ZERO OR GREATER THAN 50" ;
			gotoxy(1,25) ;
			cout<<"Press any key to continue..." ;
			getch() ;
			gotoxy(1,24) ;	clreol() ;
			gotoxy(1,25) ;	clreol() ;
			gotoxy(20,6) ;	clreol() ;
		}
	} while ( !valid ) ;
	do
	{
		valid = 1 ;
		gotoxy(1,25) ;	clreol() ;
		gotoxy(1,25) ;
		cout<<"ENTER THE PHONE NO. OF THE CUSTOMER, ENTER '-' FOR NO PHONE NO." ;
		gotoxy(20,7) ;
		cin>>t_phone ;
		if ((strlen(t_phone) < 8 && strlen(t_phone) > 1) || (strlen(t_phone) > 8))
		{
			valid = 0 ;
			gotoxy(1,25) ;	clreol() ;
			gotoxy(1,24) ;
			cout<<"LENGTH SHOULD NOT LESS THAN 8 OR GREATER THAN 8" ;
			gotoxy(1,25) ;
			cout<<"Press any key to continue..." ;
			getch() ;
			gotoxy(1,24) ;	clreol() ;
			gotoxy(1,25) ;	clreol() ;
			gotoxy(20,7) ;	clreol() ;
		}
	} while ( !valid ) ;
	do
	{
		valid = 1 ;
		gotoxy(1,25) ;	clreol() ;
		gotoxy(1,25) ;
		cout<<"ENTER NATIONALITY OF THE CUSTOMER" ;
		gotoxy(20,8) ;
		gets(t_nation) ;
		fflush(stdin) ;
		if ((strlen(t_nation) <= 0) || (strlen(t_nation) > 15))
		{
			valid = 0 ;
			gotoxy(1,25) ;	clreol() ;
			gotoxy(1,24) ;
			cout<<"LENGTH SHOULD NOT LESS THAN ZERO OR GREATER THAN 15" ;
			gotoxy(1,25) ;
			cout<<"Press any key to continue..." ;
			getch() ;
			gotoxy(1,24) ;	clreol() ;
			gotoxy(1,25) ;	clreol() ;
			gotoxy(20,8) ;	clreol() ;
		}
	} while ( !valid ) ;
	do
	{
		valid = 1 ;
		gotoxy(1,25) ;	clreol() ;
		gotoxy(1,25) ;
		cout<<"ENTER PASSPORT NO. OF THE CUSTOMER" ;
		gotoxy(20,9) ;
		gets(t_passport) ;
		fflush(stdin) ;
		if ((strlen(t_passport) <= 0) || (strlen(t_passport) > 15))
		{
			valid = 0 ;
			gotoxy(1,25) ;	clreol() ;
			gotoxy(1,24) ;
			cout<<"LENGTH SHOULD NOT LESS THAN ZERO OR GREATER THAN 15" ;
			gotoxy(1,25) ;
			cout<<"Press any key to continue..." ;
			getch() ;
			gotoxy(1,24) ;	clreol() ;
			gotoxy(1,25) ;	clreol() ;
			gotoxy(20,9) ;	clreol() ;
		}
	} while ( !valid ) ;
	do
	{
		valid = 1 ;
		gotoxy(1,25) ; clreol() ;
		gotoxy(1,25) ;
		cout<<"ENTER THE ADVANCE IN RS. " ;
		gotoxy(20,11) ;
		cin>>t_advance ;
		if (t_advance < 0)
		{
			valid = 0 ;
			gotoxy(1,25) ;	clreol() ;
			gotoxy(1,24) ;
			cout<<"SHOULD NOT LESS THAN ZERO" ;
			gotoxy(1,25) ;
			cout<<"Press any key to continue..." ;
			getch() ;
			gotoxy(1,24) ;	clreol() ;
			gotoxy(1,25) ;	clreol() ;
			gotoxy(20,11) ; clreol() ;
		}
	} while ( !valid ) ;
	do
	{
		valid = 1 ;
		gotoxy(1,25) ; clreol() ;
		gotoxy(1,25) ;
		cout<<"ENTER THE MISCELLENIOUS CHARGES" ;
		gotoxy(20,12) ;
		cin>>t_misc ;
		if (t_misc < 0)
		{
			valid = 0 ;
			gotoxy(1,25) ;	clreol() ;
			gotoxy(1,24) ;
			cout<<"SHOULD NOT LESS THAN ZERO" ;
			gotoxy(1,25) ;
			cout<<"Press any key to continue..." ;
			getch() ;
			gotoxy(1,24) ;	clreol() ;
			gotoxy(1,25) ;	clreol() ;
			gotoxy(20,12) ; clreol() ;
		}
	} while ( !valid ) ;
	do
	{
		valid = 1 ;
		gotoxy(1,25) ; clreol() ;
		gotoxy(1,25) ;
		cout<<"ENTER THE ROOM SERVICE CHARGES" ;
		gotoxy(20,13) ;
		cin>>t_room_srv ;
		getch();
		if (t_room_srv < 0)
		{
			valid = 0 ;
			gotoxy(1,25) ;	clreol() ;
			gotoxy(1,24) ;
			cout<<"SHOULD NOT LESS THAN ZERO" ;
			gotoxy(1,25) ;
			cout<<"Press any key to continue..." ;
			getch() ;
			gotoxy(1,24) ;	clreol() ;
			gotoxy(1,25) ;	clreol() ;
			gotoxy(20,13) ; clreol() ;
		}
	} while ( !valid ) ;
	gotoxy(1,15) ;
	cout<<"Do you want to save the record (y/n)  :  " ;
	do
	{
		valid = 1 ;
		gotoxy(42,15) ;
		cin>>ch;
		getch() ;
		ch = toupper(ch) ;
		if (ch != 'Y' && ch != 'N')
		{
			valid = 0 ;
			gotoxy(42,15) ; clreol() ;
		}
	} while ( !valid ) ;
	if (ch == 'Y')
	{
		r.change_status(t_roomno,'O') ;
		roomno = t_roomno ;
		strcpy(name,t_name) ;
		strcpy(phone,t_phone) ;
		advance = t_advance ;
		misc = t_misc ;
		room_srv = t_room_srv ;
		fstream file ;
		file.open("CUSTOMER.DAT", ios::out | ios::app ) ;
		file.write((char*) this, sizeof(customer)) ;
		file.close() ;
	}
	m1.main_menu() ;
}


void customer :: display_record(int t_roomno)
{
	fstream file ;
	file.open("CUSTOMER.DAT", ios::in) ;
	file.seekg(0) ;
	int found = 0 ;
	while (file.read((char *) this, sizeof(customer)) && !found)
	{
		if (t_roomno == roomno)
		{
			found = 1 ;
			gotoxy(1,5) ;
			cout<<"Room no.             : " <<roomno ;
			gotoxy(1,6) ;
			cout<<"Customer Name        : " <<name ;
			gotoxy(1,7) ;
			cout<<"Phone no.            : " <<phone ;
			gotoxy(1,8) ;
			cout<<"Advance              : " <<advance ;
			gotoxy(1,9) ;
			cout<<"Misc. charges        : " <<misc ;
			gotoxy(1,10) ;
			cout<<"Room Service Charges : " <<room_srv ;
		}
	}
	file.close () ;
   }


int customer :: recordno(int t_roomno)
{
	fstream file ;
	file.open("CUSTOMER.DAT", ios::in) ;
	file.seekg(0) ;
	int count = 0 ;
	while (file.read((char *) this, sizeof(customer)))
	{
		count++ ;
		if (t_roomno == roomno)
			break ;
	}
	file.close() ;
	return count ;
}


void customer :: modify(void)
{
	clrscr() ;
	room r ;
	int valid ;
	char ch ;
	int t_roomno , tr ;
	char  t_name[21] , t_phone[8] ;
	float t_advance , t_misc , t_room_srv ;
	fstream file ;
	file.open("CUSTOMER.DAT", ios::out | ios::ate) ;
	gotoxy(1,3) ;
	cout<<"Enter the Room no. of the customer to be modified " ;
	cin>>tr ;
	getch();
	char t_status ;
	t_status = r.room_status(tr) ;
	if (!r.room_found(tr) || t_status == 'V')
	{
		gotoxy(1,25) ; clreol() ;
		gotoxy(1,24) ;
		cout<<"ROOM NO. NOT FOUND OR ROOM IS VACANT" ;
		gotoxy(1,25) ;
		cout<<"Press any key to continue..." ;
		getch() ;
		return ;
	}
	display_record(tr) ;
	gotoxy(1,12) ;
	cout<<"Do you want to modify this Room Record (y/n) : " ;
	do
	{
		valid = 1 ;
		gotoxy(48,12) ;
		cin>>ch;
		getch() ;
		ch = toupper(ch) ;
		if (ch != 'Y' && ch != 'N')
		{
			valid = 0 ;
			gotoxy(42,12) ; clreol() ;
		}
	} while ( !valid ) ;
	if (ch == 'N')
		return ;
	gotoxy(1,14) ;
	cout<<"ENTER THE NEW DATA FOR THE CUSTOMER" ;
	gotoxy(1,16) ;
	cout<<"Room no.         : " ;
	gotoxy(1,17) ;
	cout<<"Name             : " ;
	gotoxy(1,18) ;
	cout<<"Phone            : " ;
	gotoxy(1,19) ;
	cout<<"Advance          : " ;
	gotoxy(1,20) ;
	cout<<"Miscellineous    : " ;
	gotoxy(1,21) ;
	cout<<"Room service     : " ;
	do
	{
		valid = 1 ;
		gotoxy(1,25) ; clreol() ;
		gotoxy(1,25) ;
		cout<<"ENTER THE ROOM NUMBER FOR CUSTOMER : " ;
		gotoxy(20,16) ;
		cin>>t_roomno ;
		getch();
		t_status = r.room_status(t_roomno) ;
		if ((!r.room_found(t_roomno)) || (r.room_found(t_roomno) && t_roomno != tr && t_status == 'O'))
		{
			valid = 0 ;
			gotoxy(1,25) ;	clreol() ;
			gotoxy(1,24) ;
			cout<<"ROOM NO. NOT EXIST OR NOT VACANT" ;
			gotoxy(1,25) ;
			cout<<"Press any key to continue..." ;
			getch() ;
			gotoxy(1,24) ;	clreol() ;
			gotoxy(1,25) ;	clreol() ;
			gotoxy(20,16) ; clreol() ;
		}
	} while ( !valid ) ;
	do
	{
		valid = 1 ;
		gotoxy(1,25) ; clreol() ;
		gotoxy(1,25) ;
		cout<<"ENTER THE NAME OF THE CUSTOMER : " ;
		gotoxy(20,17) ;
		gets(t_name) ;
		getch();
		strupr(t_name) ;
		fflush(stdin) ;
		if ((strlen(t_name) <= 0) || (strlen(t_name) > 20))
		{
			valid = 0 ;
			gotoxy(1,25) ;	clreol() ;
			gotoxy(1,24) ;
			cout<<"LENGTH SHOULD NOT BE ZERO OR GREATER THAN 20" ;
			gotoxy(1,25) ;
			cout<<"Press any key to continue..." ;
			getch() ;
			gotoxy(1,24) ;	clreol() ;
			gotoxy(1,25) ;	clreol() ;
			gotoxy(20,17) ; clreol() ;
		}
	} while ( !valid ) ;
	do
	{
		valid = 1 ;
		gotoxy(1,25) ;	clreol() ;
		gotoxy(1,25) ;
		cout<<"ENTER THE PHONE NO. OF THE CUSTOMER, ENTER '-' FOR NO PHONE NO." ;
		gotoxy(20,18) ;
		cin>>t_phone ;
		if ((strlen(t_phone) < 8 && strlen(t_phone) > 1) || (strlen(t_phone) > 8))
		{
			valid = 0 ;
			gotoxy(1,25) ;	clreol() ;
			gotoxy(1,24) ;
			cout<<"LENGTH SHOULD NOT LESS THAN 8 OR GREATER THAN 8" ;
			gotoxy(1,25) ;
			cout<<"Press any key to continue..." ;
			getch() ;
			gotoxy(1,24) ;	clreol() ;
			gotoxy(1,25) ;	clreol() ;
			gotoxy(20,18) ; clreol() ;
		}
	} while ( !valid ) ;
	do
	{
		valid = 1 ;
		gotoxy(1,25) ;	clreol() ;
		gotoxy(1,25) ;
		cout<<"ENTER THE ADVANCE RS. " ;
		gotoxy(20,19) ;
		cin>>t_advance ;
		getch();
		if (t_advance < 0)
		{
			valid = 0 ;
			gotoxy(1,25) ;	clreol() ;
			gotoxy(1,24) ;
			cout<<"SHOULD NOT LESS THAN ZERO" ;
			gotoxy(1,25) ;
			cout<<"Press any key to continue..." ;
			getch() ;
			gotoxy(1,24) ;	clreol() ;
			gotoxy(1,25) ;	clreol() ;
			gotoxy(20,19) ; clreol() ;
		}
	} while ( !valid ) ;
	do
	{
		valid = 1 ;
		gotoxy(1,25) ;	clreol() ;
		gotoxy(1,25) ;
		cout<<"ENTER THE MISCALLENIOUS CHARGES" ;
		gotoxy(20,20) ;
		cin>>t_misc ;
		getch();
		if (t_misc < 0)
		{
			valid = 0 ;
			gotoxy(1,25) ;	clreol() ;
			gotoxy(1,24) ;
			cout<<"SHOULD NOT LESS THAN ZERO" ;
			gotoxy(1,25) ;
			cout<<"Press any key to continue..." ;
			getch() ;
			gotoxy(1,24) ;	clreol() ;
			gotoxy(1,25) ;	clreol() ;
			gotoxy(20,20) ; clreol() ;
		}
	} while ( !valid ) ;
	do
	{
		valid = 1 ;
		gotoxy(1,25) ;	clreol() ;
		gotoxy(1,25) ;
		cout<<"ENTER THE ROOM SERVICE CHARGES" ;
		gotoxy(20,21) ;
		cin>>t_room_srv ;
		getch();
		if (t_room_srv < 0)
		{
			valid = 0 ;
			gotoxy(1,25) ;	clreol() ;
			gotoxy(1,24) ;
			cout<<"SHOULD NOT LESS THAN ZERO" ;
			gotoxy(1,25) ;
			cout<<"Press any key to continue..." ;
			getch() ;
			gotoxy(1,24) ;	clreol() ;
			gotoxy(1,25) ;	clreol() ;
			gotoxy(20,21) ; clreol() ;
		}
	} while ( !valid ) ;
	gotoxy(1,23) ;
	cout<<"Do you want to save the record (y/n)  :  " ;
	do
	{
		valid = 1 ;
		gotoxy(42,23) ;
		cin>>ch;
		getch() ;
		ch = toupper(ch) ;
		if (ch != 'Y' && ch != 'N')
		{
			valid = 0 ;
			gotoxy(42,23) ; clreol() ;
		}
	} while ( !valid ) ;
	if (ch == 'Y')
	{
		if (t_roomno != tr)
		{
			r.change_status(t_roomno,'O') ;
			r.change_status(tr,'V') ;
		}
		int recno ;
		recno = recordno(tr) ;
		int location ;
		location = (recno-1) * sizeof(customer) ;
		file.seekp(location) ;
		roomno  = t_roomno  ;
		strcpy(name,t_name) ;
		strcpy(phone,t_phone) ;
		room_srv = t_room_srv ;
		advance = t_advance ;
		misc = t_misc ;
		file.write((char *) this, sizeof(customer)) ;
	}
	file.close () ;
}


void customer :: delete_record(int t_roomno)
{
	fstream file ;
	file.open("CUSTOMER.DAT", ios::in) ;
	fstream temp ;
	temp.open("temp.dat", ios::out) ;
	while ( !file.eof() )
	{
		file.read((char *) this, sizeof(customer)) ;
		if ( file.eof() )
			break ;
		if ( roomno != t_roomno )
			temp.write((char *) this, sizeof(customer)) ;
	}
	file.close() ;
	temp.close() ;
	file.open("CUSTOMER.DAT", ios::out) ;
	temp.open("temp.dat", ios::in) ;
	temp.seekg(0) ;
	while ( !temp.eof() )
	{
		temp.read((char *) this, sizeof(customer)) ;
		if ( temp.eof() )
			break ;
		file.write((char *) this, sizeof(customer)) ;
	}
	file.close() ;
	temp.close() ;
}


void customer :: display_customer_record(void)
{
	clrscr() ;
	room r ;
	int valid ;
	int t_roomno ;
	gotoxy(1,3) ;
	cout<<"Enter the Room no. of the customer : " ;
	cin>>t_roomno ;
	char t_status ;
	t_status = r.room_status(t_roomno) ;
	if (!r.room_found(t_roomno) || t_status == 'V')
	{
		gotoxy(1,25) ; clreol() ;
		gotoxy(1,24) ;
		cout<<"ROOM NO. NOT FOUND OR ROOM IS VACANT" ;
		gotoxy(1,25) ;
		cout<<"Press any key to continue..." ;
		getch() ;
		return ;
	}
	clrscr() ;
	gotoxy(5,3) ;
	cout<<"CUSTOMER RECORD" ;
	display_record(t_roomno) ;
	gotoxy(1,25) ;
	cout<<"Press any key to continue..." ;
	getch() ;
}


void customer :: deletion(void)
{
	clrscr() ;
	room r ;
	int valid ;
	char ch ;
	int t_roomno ;
	gotoxy(1,3) ;
	cout<<"Enter the Room no. of the customer to be deleted " ;
	cin>>t_roomno ;
	char t_status ;
	t_status = r.room_status(t_roomno) ;
	if (!r.room_found(t_roomno) || t_status == 'V')
	{
		gotoxy(1,25) ;	clreol() ;
		gotoxy(1,24) ;
		cout<<"ROOM NO. NOT FOUND OR ROOM IS VACANT" ;
		gotoxy(1,25) ;
		cout<<"Press any key to continue..." ;
		getch() ;
		return ;
	}
	display_record(t_roomno) ;
	gotoxy(1,15) ;
	cout<<"Do you want to delete this Customer Record (y/n) : " ;
	do
	{
		valid = 1 ;
		gotoxy(52,15) ;
		cin>>ch ;
		getch() ;
		ch = toupper(ch) ;
		if (ch != 'Y' && ch != 'N')
		{
			valid = 0 ;
			gotoxy(52,15) ; clreol() ;
		}
	} while ( !valid ) ;
	if (ch == 'N')
		return ;
	r.change_status(t_roomno,'V') ;
	delete_record(t_roomno) ;
}


void customer :: checkout(void)
{
	clrscr() ;
	menu m1 ;
	room r ;
	int valid ;
	char ch ;
	int t_roomno ;
	gotoxy(1,3) ;
	cout<<"Enter the Room no. of the customer to be check out " ;
	cin>>t_roomno ;
	char t_status ;
	t_status = r.room_status(t_roomno) ;
	if (!r.room_found(t_roomno) || t_status == 'V')
	{
		gotoxy(1,25) ;	clreol() ;
		gotoxy(1,24) ;
		cout<<"ROOM NO. NOT FOUND OR ROOM IS VACANT" ;
		gotoxy(1,25) ;
		cout<<"Press any key to continue..." ;
		getch() ;
		m1.main_menu();
	}
	display_record(t_roomno) ;
	gotoxy(1,15) ;
	cout<<"Do you want to prepare bill of this Customer Record (y/n) : " ;
	do
	{
		valid = 1 ;
		gotoxy(63,15) ;
		cin>>ch;
		getch() ;
		ch = toupper(ch) ;
		if (ch != 'Y' && ch != 'N')
		{
			valid = 0 ;
			gotoxy(63,15) ; clreol() ;
		}
	} while ( !valid ) ;
	if (ch == 'N')
		return ;
	fstream file ;
	file.open("CUSTOMER.DAT", ios::in) ;
	file.seekg(0) ;
	char t_name[21] ;
	float t_advance, t_room_srv, t_misc, t_tariff ;
	while (file.read((char *) this, sizeof(customer)))
	{
		if (t_roomno == roomno)
		{
			strcpy(t_name,name) ;
			t_advance = advance ;
			t_room_srv = room_srv ;
			t_misc = misc ;
			break ;
		}
	}
	file.close() ;
	t_tariff = r.get_data(t_roomno) ;
	account a ;
	a.prepare_bill(t_roomno,t_tariff,t_name,t_advance,t_room_srv,t_misc) ;
	r.change_status(t_roomno,'V') ;
	delete_record(t_roomno) ;
	gotoxy(1,25) ;
	cout<<"Press any key to continue..." ;
	getch() ;
	m1.main_menu() ;
}


void account :: prepare_bill(int t_roomno, float t_tariff, char t_name[21], float t_advance, float t_room_srv, float t_misc)
{
	menu m1 ;
	int valid ;
	int days ;
	float tax , total ;
	gotoxy(1,17) ;
	cout<<"Enter the no. of days : " ;
	do
	{
		valid = 1 ;
		gotoxy(25,17) ;
		cin>>days ;
		if (days < 0 || days > 2000)
		{
			valid = 0 ;
			gotoxy(1,25) ;	clreol() ;
			gotoxy(1,24) ;
			cout<<"SHOULD NOT LESS THAN ZERO" ;
			gotoxy(1,25) ;
			cout<<"Press any key to continue..." ;
			getch() ;
			gotoxy(1,24) ;	clreol() ;
			gotoxy(1,25) ;	clreol() ;
			gotoxy(25,17) ; clreol() ;
		}
	} while ( !valid ) ;
	t_tariff = t_tariff * days ;
	total = (t_room_srv + t_misc + t_tariff) - t_advance ;
	tax = total * 0.22 ;
	total = total + tax ;
	clrscr() ;
	menu m ;
	gotoxy(5,3) ;
	cout<<"Bill of Room no. : " <<t_roomno ;
	gotoxy(5,6) ;
	cout<<"Name of Customer     : " <<t_name ;
	gotoxy(5,8) ;
	cout<<"Tariff Charges      : " <<t_tariff ;
	gotoxy(5,10) ;
	cout<<"Misc. Charges        : " <<t_misc ;
	gotoxy(5,12) ;
	cout<<"Room service Charges : " <<t_room_srv ;
	gotoxy(5,14) ;
	cout<<"Tax                  : " <<tax ;
	gotoxy(5,16) ;
	cout<<"Advance              : " <<t_advance ;
	gotoxy(5,18) ;
	cout<<"------------------------------------------" ;
	gotoxy(5,19) ;
	cout<<"Total Bill           : " <<total ;
	gotoxy(5,20) ;
	cout<<"------------------------------------------" ;
}

void main ( void )
{
	menu m ;
	m.enter_password() ;
	m.intro();
}