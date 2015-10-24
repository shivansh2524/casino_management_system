//CASINO MANAGEMENT PROGRAM

//HEADER FILES USED:
#include<fstream.h>
#include<conio.h>
#include<process.h>
#include<stdio.h>
#include<string.h>
#include<time.h>
#include<stdlib.h>

//FUNCTIONS USED:

void disp();//TO DISPLAY RECORDS
void welcome1();//TO DISPLAY HEADER GRAFHIC
void enterprogram();//TO INITIALISE FILE WITH USER DETAILS
void new_registeration();//TO ADD NEW RECORD
void modify_details();//TO MODIFY RECORD
void entercasino();//CASINO ENTRY FUNCTION
void main_menu();//TO DISPLAY MAIN MENU
void bookroom();//ROOM BOOKING FUNCTION
int roomno();//TO RETURN ROOM NUMBER
void introupdown();// INTRODUCTION OF 7UP 7DOWN GAME
void p2updown();//7 UP / 7 DOWN GAME CODE
void won(int x);//ADDS WON AMOUNT TO TOTAL AMOUNT
void lost();//DEDUCTS BIDDING AMOUNT FROM TOTAL AMOUNT
void p2cardgame();//CARD GAME CODE
void introductioncg();//INTRODUCTION OF CARD GAME
void p2roulette();//ROULETTE GAME CODE
void introroulette();//INTRODUCTION OF ROULETTE GAME
//CHOICE FUNCTION(TAKE CHOICE FROM USER AND CALL OTHER FUNCTIONS)
void casinochoice();
void playupdown();
void g7up7down();
void cardgame();
void playcardgame();
void roulette();
void playroulette();
int cash2;
int bid;
void introduction();

class hoteluser
{

	int roomno;
	public:
	char name[30];
	void enterdet(char nm[],int x)//TO ENTER DETAILS OF CLASS
	{
		strcpy(name,nm);
		roomno=x;
	}
	void showdet()//TO SHOW DETAILS OF CLASS
	{
		cout<<"\nName:"<<name;
		cout<<"\nRoom No.:"<<roomno;
		cout<<"\n\n\n";
	}
};//END OF CLASS
void any()
{
	cout<<"\n\nPress any key to continue..........";
	getch();
}
class user
{

	long phno;
	char addr[50];
	public:
	char name[30];
	int cust_no;
	void enter_details()//TO ENTER DETAILS OF CLASS
	{
		cout<<"\n\n     Register Details:";
		cout<<"\n\n\n     Enter Customer Number:";
		cin>>cust_no;
		cout<<"\n     Enter name:";
		cin>>name;
		cout<<"\n     Enter phone number:";
		cin>>phno;
		cout<<"\n     Enter Address:";
		gets(addr);
	}
	void disp()//TO ENTER DETAILS OF CLASS
	{       cout<<"\nCustomer no:"<<cust_no;
		cout<<"\nName:"<<name;
		cout<<"\nPhone Number:"<<phno;
		cout<<"\nAddress:"<<addr;
		cout<<"\n\n\n";
	}
	void modify();
};//END OF CLASS
void introduction()
{
	clrscr();welcome1();
	cout<<"This Program imitates the working of a casino system.";
	cout<<"\nThis program includes Casino games namely ";
	cout<<"\nRoulette, 7 Up Or 7 Down & Card Game.";
	cout<<"\nIt also include Room booking facility in hotel.";
	any();
	main_menu();
}//END OF FUNCTION
void welcome1()
{       int i;clrscr();
	for(i=0;i<=24;i++)
		cout<<" ";
	for(i=0;i<=34;i++)
		cout<<"@";
	cout<<endl<<endl;
	for(i=0;i<=24;i++)
		cout<<" ";
	cout<<"{";
	cout<<"    WELCOME TO ROYALE CASINO     }\n\n";
	for(i=0;i<=24;i++)
		cout<<" ";
	for(i=0;i<=34;i++)
		cout<<"@";
	cout<<"\n\n\n\n\n";
}//END OF FUNCTION
void enterprogram()
{
	user o1;
	fstream file;
	file.open("STUDENT.DAT",ios::in|ios::out|ios::binary|ios::trunc);
	o1.enter_details();
	file.seekg(0,ios::beg);
	file.write((char*)&o1,sizeof(o1));
	cout<<"\n\nDATA SUCCESSFULLY REGISTERED";
	file.close();
	any();
	main_menu();
}//END OF FUNCTION
void new_registeration()
{
	user o1;
	fstream file;
	clrscr();welcome1();
	file.open("STUDENT.DAT",ios::in|ios::out|ios::binary|ios::ate);
	o1.enter_details();
	file.seekg(0,ios::end);
	file.write((char*)&o1,sizeof(o1));
	any();
	clrscr();
	welcome1();
	cout<<"\nCurrent Register:\n\n";
	file.close();
	disp();
	any();
	main_menu();
}//END OF FUNCTION
void disp()
{
	clrscr();welcome1();
	user o1;
	fstream file;
	file.open("STUDENT.DAT",ios::in|ios::binary);
	while(file.read((char*)&o1,sizeof(o1)))
	{
		o1.disp();
	}
	file.close();
	any();main_menu();
}//END OF FUNCTION
void user::modify()
{       clrscr();welcome1();
	cout<<"\nCustomer Number:"<<cust_no;
	cout<<"\nName:"<<name;
	cout<<"\nPhone Number:"<<phno;
	cout<<"\nAddress:"<<addr;
	cout<<"\nEnter New Details....";
	char nm[30];long ph;char addr2[30];int cn;
	cout<<"\nNew Customer Number:(Enter '-1' to retain old one):";
	cin>>cn;
	cout<<"\nNew Name:(Enter '.' to retain old one):";
	cin>>nm;
	cout<<"\nNew Phone Number:(Enter '-1' to retain old one):";
	cin>>ph;
	cout<<"\nNew Address:(Enter '.' to retain old one):";
	cin>>addr2;
	if(cn!=-1)
		cust_no=cn;
	if(strcmp(nm,".")!=0)
		strcpy(name,nm);
	if(ph!=-1)
		phno=ph;
	if(strcmp(addr2,".")!=0)
		strcpy(addr,addr2);
}//END OF FUNCTION
//==============================================
//FUNCTION TO MODIFY DETAILS OF USER
//==============================================
void modify_details()
{
	user o1;
	fstream file;
	file.open("STUDENT.DAT",ios::in|ios::out|ios::binary|ios::ate);
	int pos,cnmb;char found='f';
	file.seekg(0,ios::beg);
	cout<<"Enter Customer Number whose record is to be modified:";
	cin>>cnmb;
	while(!file.eof())
	{
		pos=file.tellg();
		file.read((char*)&o1,sizeof(o1));
		if(o1.cust_no==cnmb)
		{
			o1.modify();
			file.seekg(pos);
			file.write((char*)&o1,sizeof(o1));
			found='t';
			break;
		}
	}
	if(found=='f')
		cout<<"\n\nRecord Not Found!!";
	file.seekg(0);
	cout<<"Now the File contains:\n\n";
	file.close();
	disp();
	any();
	main_menu();
}//END OF FUNCTION           \
//=========================================
//FUNCTION FOR CASINO ENTRY
//=========================================
void entercasino()
{
	int cho;
	cout<<"\n\nEnter amount of cash you \n would like to invest in casino:";
	cin>>::cash2;
	any();
	casinochoice();
}//END OF FUNCTION
void casinochoice()
{       int cho;
	clrscr();welcome1();
	cout<<"\nWhich Game would you like to play......";
	cout<<"\n\n1. Roulette";
	cout<<"\n2. 7up/7down";
	cout<<"\n3. Card game";
	cout<<"\n4. Go to Main Menu";
	cout<<"\nEnter Choice(1-4):";
	cin>>cho;
	any();
	switch(cho)
	{
		case 1:
			roulette();
			break;
		case 2:
			g7up7down();
			break;
		case 3:
		       cardgame();
		       break;
		case 4:
			main_menu();
			break;
		default:
			cout<<"\nInvalid Selection!!!! Try Again...";
			any();
			casinochoice();
	}
}//END OF FUNCTION
//===========================================
//FUNCTION TO DISPLAY MAIN MENU
//===========================================
void main_menu()
{       int i;
	clrscr();welcome1();int ch;
	for(i=0;i<=24;i++)
		cout<<" ";
	cout<<"\n     Main Menu\n\n";
	cout<<"\n     1.INTRODUCTION\n";
	cout<<"\n     2.ENTER CASINO\n";
	cout<<"\n     3.BOOK A ROOM\n";
	cout<<"\n     4.ADD NEW REGISTRATION DETAILS\n";
	cout<<"\n     5.MODIFY DETAILS IN REGISTER\n";
	cout<<"\n     6.DISPLAY DETAILS\n";
	cout<<"\n     7.EXIT\n";
	cout<<"\n     Enter Choice(1-7):";
	cin>>ch;
	any();
	switch(ch)
	{
		case 1:
		       introduction();
			break;
		case 2:
			entercasino();
			break;
		case 3:
			bookroom();
			break;
		case 4:
			new_registeration();
			break;
		case 5:
			modify_details();
			break;
		case 6:
			disp();
			break;
		case 7:
			clrscr();
			cout<<"\n\n\n\n\n\n\n\n";
			cout<<"THANK YOU FOR USING ROYALE CASINO MANAGEMENT SYSTEM";
			exit(0);
			break;
		default:
			cout<<"\nInvalid Selection!!!! Try Again";
			any();
			main_menu();
		}
}//END OF FUNCTION
//======================================
//FUNCTION TO BOOK A ROOM
//======================================
void bookroom()
{       char nm[30];int cho,rmno;
	clrscr();welcome1();
	cout<<"Enter name:";cin>>nm;
	cout<<"\n\n     Select the type of room you would like to book.....";
	cout<<"\n\n     1.One room";
	cout<<"\n     2.Two room Suite";
	cout<<"\n     3.Three Room Suite";
	cout<<"\n     4. Lake View Suite";
	cout<<"\n     Enter Choice(1-4):";
	cin>>cho;
	any();
	if(cho<1 || cho>4)
	{
		cout<<"\nInvalid Selection!!!! Try Again......";
		any();
		bookroom();
	}
	rmno=roomno();
	hoteluser o1;
	o1.enterdet(nm,rmno);
	fstream file;
	file.open("HOTEL_REGISTER.DAT",ios::in|ios::out|ios::binary|ios::ate|ios::trunc);
	file.seekg(0,ios::end);
	file.write((char*)&o1,sizeof(o1));
	cout<<"\nRoom Alloted...";
	any();
	clrscr();
	welcome1();
	file.seekg(0,ios::beg);
	cout<<"\nCurrent Room Allotments are:\n";
	while(file.read((char*)&o1,sizeof(o1)))
	{
		o1.showdet();
	}
	cout<<"\nPress any key to return to main menu.....";
	getch();
	main_menu();
}//END OF FUNCTION
//======================================
//FUNCTION TO RETURN ROOM NO.
//======================================
int roomno()
{
	int rno,y,z;
	randomize();
	y=random(10);
	z=random(8)+1;
	rno=y*100+z;
	return rno;
}//END OF FUNCTION
void g7up7down()
{
	clrscr();
	welcome1();
	int i;
	for(i=0;i<=24;i++)
		cout<<" ";
	for(i=0;i<=25;i++)
		cout<<"*";
	cout<<endl<<endl;
	for(i=0;i<=24;i++)
		cout<<" ";
	cout<<"[";
	cout<<"     7 UP OR 7 DOWN     ]\n";
	cout<<"\n";
	for(i=0;i<=24;i++)
		cout<<" ";
	for(i=0;i<=25;i++)
		cout<<"*";
	cout<<"\n\n\n\n\n";
	int ans;
	cout<<"     1.Introduction";
	cout<<"\n    2.Play Game";
	cout<<"\n    Enter Choice:";cin>>ans;
	switch(ans)
	{
		case 1:
			introupdown();
			break;
		case 2:
			playupdown();
			break;
		default:
			cout<<"\nInvalid Selection!!!! Try Again....";
			any();
			g7up7down();
	}
}//END OF FUNCTION
void introupdown()
{	clrscr();welcome1();
	int i;
	for(i=0;i<=24;i++)
		cout<<" ";
	for(i=0;i<=25;i++)
		cout<<"*";
	cout<<endl<<endl;
	for(i=0;i<=24;i++)
		cout<<" ";
	cout<<"[";
	cout<<"     7 UP OR 7 DOWN     ]\n";
	cout<<"\n";
	for(i=0;i<=24;i++)
		cout<<" ";
	for(i=0;i<=25;i++)
		cout<<"*";
	cout<<"\n\n\n\n\n";
	getch();
	cout<<"\n\n";
	cout<<"    This Game is basically based on two dices.";
	cout<<"\n   You have to bid on whether the total of numbers";
	cout<<"\n   on both dices would be greater than or less than 7.";
	cout<<"\n   7 will be counted as greater than 7. The winning will";
	cout<<"\n   be 200% of you bidding amount.";
	any();
	playupdown();
}//END OF FUNCTION
void playupdown()
{
	clrscr();welcome1();
	int i;
	for(i=0;i<=24;i++)
		cout<<" ";
	for(i=0;i<=25;i++)
		cout<<"*";
	cout<<endl<<endl;
	for(i=0;i<=24;i++)
		cout<<" ";
	cout<<"[";
	cout<<"     7 UP OR 7 DOWN     ]\n";
	cout<<"\n";
	for(i=0;i<=24;i++)
		cout<<" ";
	for(i=0;i<=25;i++)
		cout<<"*";
	cout<<"\n\n\n\n\n";
	do{
	cout<<"\n     Enter bidding amount:";
	cin>>::bid;
	if(::bid>::cash2)
	{
		cout<<"\n     Bidding amount is greater than invested amount";
		cout<<"\n     Try Again...";
		any();
	}
	}while(::bid>::cash2);p2updown();
}//END OF FUNCTION
void p2updown()
{
	clrscr();int i;
	welcome1();
	for(i=0;i<=24;i++)
		cout<<" ";
	for(i=0;i<=25;i++)
		cout<<"*";
	cout<<endl<<endl;
	for(i=0;i<=24;i++)
		cout<<" ";
	cout<<"[";
	cout<<"     7 UP OR 7 DOWN     ]\n";
	cout<<"\n";
	for(i=0;i<=24;i++)
		cout<<" ";
	for(i=0;i<=25;i++)
		cout<<"*";
	cout<<"\n\n\n\n\n";
	int ans,r;
	cout<<"\n\n     Select choice";
	cout<<"\n     1. 7 UP";
	cout<<"\n     2. 7 DOWN";
	cout<<"\n     choice(1-2):";
	cin>>ans;any();
	if(ans!=1 && ans!=2)
	{
		cout<<"\nInvalid Selection!!!! Try again....";
		any();
		playupdown();
	}
	randomize();
	r=random(12)+1;
	if((r>=7 && ans==1) || (r<7 && ans==2))
		won(200);
	else
		lost();
}//END OF FUNCTION
void won(int x)
{
	::cash2+=::bid*x/100.0;
	clrscr();welcome1();
	cout<<"\n\n\n\n\n\n!!!!!!!!!!!!!! YOU WON !!!!!!!!!!!!!!!!";
	cout<<"\n\n     Your Current Amount : "<<::cash2;
	cout<<"\v     Press any key to return to games menu.....";
	any();
	casinochoice();
}//END OF FUNCTION
void lost()
{
	::cash2-=::bid;
	clrscr();
	welcome1();
	cout<<"\n\n\n\n\n\n!!!!!!!!!!!!!!! YOU LOST !!!!!!!!!!!!!!!!";
	cout<<"\n\n     Your Current Amount : "<<::cash2;
	cout<<"\v     Press any key To return to Games menu....";
	any();
	casinochoice();
}//END OF FUNCTION
void cardgame()
{
	clrscr();
	welcome1();
	int i;
	for(i=0;i<=24;i++)
		cout<<" ";
	for(i=0;i<=20;i++)
		cout<<"*";
	cout<<endl<<endl;
	for(i=0;i<=24;i++)
		cout<<" ";
	cout<<"[";
	cout<<"     CARD GAME     ]\n";
	cout<<"\n";
	for(i=0;i<=24;i++)
		cout<<" ";
	for(i=0;i<=20;i++)
		cout<<"*";
	cout<<"\n\n\n\n\n";
	do{
	cout<<"     Enter bidding amount:";
	cin>>::bid;
	if(::bid>::cash2)
	{
		cout<<"\n     Bidding amount is greater than invested amount";
		cout<<"\n     Try Again...";
		any();
	}
	}while(::bid>::cash2);playcardgame();
}//END OF FUNCTION
void playcardgame()
{
	clrscr();welcome1();
	int i;
	for(i=0;i<=24;i++)
		cout<<" ";
	for(i=0;i<=20;i++)
		cout<<"*";
	cout<<endl<<endl;
	for(i=0;i<=24;i++)
		cout<<" ";
	cout<<"[";
	cout<<"     CARD GAME     ]\n";
	cout<<"\n";
	for(i=0;i<=24;i++)
		cout<<" ";
	for(i=0;i<=20;i++)
		cout<<"*";
	cout<<"\n\n\n\n\n";
	int ans;
	cout<<"     Select Choice";
	cout<<"\n    1.Introduction";
	cout<<"\n    2.Play Game";
	cout<<"\n    choice(1-2):";
	cin>>ans;any();
	if(ans!=1 && ans!=2)
	{
		cout<<"\nInvalid Selection!!!! Try Again...";
		any();
		playcardgame();
	}
	switch(ans)
	{
		case 1:
			introductioncg();
			break;
		case 2:
			p2cardgame();
			break;
	}
}//END OF FUNCTION
void p2cardgame()
{
	clrscr();welcome1();
	int i;
	for(i=0;i<=24;i++)
		cout<<" ";
	for(i=0;i<=20;i++)
		cout<<"*";
	cout<<endl<<endl;
	for(i=0;i<=24;i++)
		cout<<" ";
	cout<<"[";
	cout<<"     CARD GAME     ]\n";
	cout<<"\n";
	for(i=0;i<=24;i++)
		cout<<" ";
	for(i=0;i<=20;i++)
		cout<<"*";
	cout<<"\n\n\n\n\n";
	int ans;
	cout<<"\n     Select Choice:";
	cout<<"\n     1.Bet on Nature(spade,club,diamond,heart)";
	cout<<"\n     2.Bet on Number[1-13,(11 is J | 12 is Q | 13 is K)]";
	cout<<"\n     3.Bet on Colour";
	cout<<"\n     Select choice(1-3):";
	cin>>ans;
	randomize();int r;
	switch(ans)
	{
		case 1: r=random(4)+1;
			cout<<"\n\n     Select Nature of Card:";
			cout<<"\n     1.Spade";
			cout<<"\n     2.Heart";
			cout<<"\n     3.Diamond";
			cout<<"\n     4.Club";
			cout<<"\n     choice(1-4)";
			cin>>ans;
			if(ans==r)
				won(400);
			else
				lost();
			break;
		case 2:r=random(13)+1;
			cout<<"\n     Enter Number on Card";
			cout<<"[1-13,(11 is J | 12 is Q | 13 is K)]";
			cout<<"\n     choice:";
			cin>>ans;
			if(ans==r)
				won(1000);
			else
				lost();
			break;
		case 3:r=random(2)+1;
			cout<<"     Enter Colour On Card:";
			cout<<"\n     1.Red";
			cout<<"\n     2.Black";
			cout<<"\n     choice(1-2):";
			cin>>ans;
			if(ans==r)
				won(200);
			else
				lost();
			break;
		default:
			cout<<"\nInvalid Selection!!!! Try Again...";
			any();
			p2cardgame();
	}
}//END OF FUNCTION
void introductioncg()
{
	clrscr();welcome1();
	int i;
	for(i=0;i<=24;i++)
		cout<<" ";
	for(i=0;i<=20;i++)
		cout<<"*";
	cout<<endl<<endl;
	for(i=0;i<=24;i++)
		cout<<" ";
	cout<<"[";
	cout<<"     CARD GAME     ]\n";
	cout<<"\n";
	for(i=0;i<=24;i++)
		cout<<" ";
	for(i=0;i<=20;i++)
		cout<<"*";
	cout<<"\n\n\n\n\n";
	cout<<"     INTRODUCTION:";
	cout<<"\n     This game is played by betting on the colour of";
	cout<<"\n     card,Nature of card or Number on card.";
	cout<<"\n     The Winning Sequence is :";
	cout<<"\n     Bet on colour\t\t200% of Bid";
	cout<<"\n     Bet on Nature\t\t400%of Bid";
	cout<<"\n     Bet on Number on Card\t\t1000% of bid";
	any();
	p2cardgame();
}//END OF FUNCTION
void roulette()
{
	clrscr();welcome1();
	int i;
	for(i=0;i<=24;i++)
		cout<<" ";
	for(i=0;i<=19;i++)
		cout<<"*";
	cout<<endl<<endl;
	for(i=0;i<=24;i++)
		cout<<" ";
	cout<<"[";
	cout<<"     ROULETTE     ]\n";
	cout<<"\n";
	for(i=0;i<=24;i++)
		cout<<" ";
	for(i=0;i<=19;i++)
		cout<<"*";
	cout<<"\n\n\n\n\n";
	do{
	cout<<"Enter Bidding amount:";
	cin>>::bid;
	if(::bid>::cash2)
	{
		cout<<"\nBidding Amount is mores than Invested amount...\n";
		cout<<"Try again...";
		any();
	}
	}while(::bid>::cash2);
	playroulette();
}//END OF FUNCTION
void playroulette()
{
	clrscr();welcome1();
	int i;
	for(i=0;i<=24;i++)
		cout<<" ";
	for(i=0;i<=19;i++)
		cout<<"*";
	cout<<endl<<endl;
	for(i=0;i<=24;i++)
		cout<<" ";
	cout<<"[";
	cout<<"     ROULETTE     ]\n";
	cout<<"\n";
	for(i=0;i<=24;i++)
		cout<<" ";
	for(i=0;i<=19;i++)
		cout<<"*";
	cout<<"\n\n\n\n\n";
	cout<<"Select Choice";
	cout<<"\n1.Introduction";int ans;
	cout<<"\n2.Play Game";
	cout<<"Choice(1-2):";cin>>ans;
	switch(ans)
	{
		case 1:
			introroulette();break;
		case 2:
			p2roulette();break;
		default:
			cout<<"\nInvalid Selection!!!! Try Again.....";
			any();
			playroulette();
	}

}//END OF FUNCTION
void p2roulette()
{
	clrscr();welcome1();
	int i;
	for(i=0;i<=24;i++)
		cout<<" ";
	for(i=0;i<=19;i++)
		cout<<"*";
	cout<<endl<<endl;
	for(i=0;i<=24;i++)
		cout<<" ";
	cout<<"[";
	cout<<"     ROULETTE     ]\n";
	cout<<"\n";
	for(i=0;i<=24;i++)
		cout<<" ";
	for(i=0;i<=19;i++)
		cout<<"*";
	cout<<"\n\n\n\n\n";
	cout<<"Select Choice";
	cout<<"\n1.Bet on Colour";
	cout<<"\n2.Bet on Single Number";
	cout<<"\n3.Bet on Range";
	cout<<"\nChoice(1-3):";int ans,r;
	cin>>ans;
	randomize();
	switch(ans)
	{
		case 1: cout<<"\n\nSelect Colour";
			cout<<"\n1.Red";
			cout<<"\n2.Black";
			cout<<"choice(1-2):";
			cin>>ans;
			r=random(2)+1;
			if(ans==r)
				won(400);
			else
				lost();
			break;
		case 2: cout<<"\n\nEnter Number(1-50)";
			cin>>ans;
			r=random(50)+1;
			if(ans==r)
				won(3500);
			else
				lost();
			break;
		case 3: int u,l;
			cout<<"\n\nEnter Lower Limit Of Range:";
			cin>>l;
			cout<<"\nEnter Upper LImit Of Range:";
			cin>>u;
			r=random(50)+1;
			if(r>=l && r<=u)
				won((50-(u-l)));
			else
				lost();
			break;
		default:cout<<"\nInvalid Selection!!!! Try again....";
			any();
			p2roulette();
	}
}//END OF FUNCTION
void introroulette()
{
	clrscr();welcome1();
	int i;
	for(i=0;i<=24;i++)
		cout<<" ";
	for(i=0;i<=19;i++)
		cout<<"*";
	cout<<endl<<endl;
	for(i=0;i<=24;i++)
		cout<<" ";
	cout<<"[";
	cout<<"     ROULETTE     ]\n";
	cout<<"\n";
	for(i=0;i<=24;i++)
		cout<<" ";
	for(i=0;i<=19;i++)
		cout<<"*";
	cout<<"\n\n\n\n\n";
	cout<<"INTRODUCTION";
	cout<<"\n\nRoulette is one of the most classical games in casino.";
	cout<<"\nThis game is played on a rotating disc, marked with numbers";
	cout<<"\nand red and black chips.";
	cout<<"\nWining Sequence is as follows:";
	cout<<"\nBet on colour\t\t200%:";
	cout<<"\nBet on single number\t\t3500%";
	cout<<"\n\nBet on range\t\t [{50-(U.L - L.L)}*10]%";
	any();
	p2roulette();
}//END OF FUNCTION
//====================================
//STARTING OF MAIN
//====================================
void main()
{
	welcome1();
	enterprogram();
	getch();
}//END OF MAIN
			  //END OF PROGRAM



