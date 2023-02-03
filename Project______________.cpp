#include<iostream>
#include<string>
#include<conio.h>
#include<windows.h>
#include<fstream>
#include<cstdio>
using namespace std;
struct Product{
	int pr_id;
	string name;
	float price;
	string expdate;
	
};

COORD coord={0,0};
void gotoxy(int x,int y)
{
 coord.X=x;
 coord.Y=y;
 SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}

//////////Prototypes//////////
void intro();
void menu();
void custmenu();
	void aditem();
	void delitem();
	void showcart();
	//void dis_pr();
void admenu();
	void add_product();
	void dis_pr();

int main()
{
	intro();
	menu();
}

void intro()
{
	system("cls");
    gotoxy(44, 5);
    cout << "SUPER MARKET BILLING SYSTEM";    
    gotoxy(45, 14);
    cout<<"Press any key to continue.";
    getch();
	
}

void menu()
{
	a:
	getch();
	system("cls");
	int ch;
	gotoxy(49,5);
	cout<<"MAIN MENU";
	gotoxy(39,7);
	cout<<"Press 1 for CUSTOMER MENU";
	gotoxy(39,8);
	cout<<"Press 2 for ADMINISTRATOR MENU";
	gotoxy(39,9);
	cout<<"Press 3 to Exit.";
	gotoxy(53,10);
	cin>>ch;
	switch(ch)
	{
		case 1:{
			custmenu();
			break;
		}
		
		case 2:{
			admenu();
			break;
		}
		case 3:{
			gotoxy(50,12);
			cout<<"Exiting";
			break;
		}
		
		default:{
			
			gotoxy(45,12);
			cout<<"\aEnter Valid Input!";
			getch();
			goto a;
		}
	}	
}

void custmenu()
{
	a:
	system("cls");
	gotoxy(35,5);
	cout<<"WELCOME TO CUSTOMERS MENU";
	gotoxy(33,7);
	cout<<"Press 1 to Add Items to your cart.";
	gotoxy(33,8);
	cout<<"Press 2 to Delete Item from your cart.";
	gotoxy(33,9);
	cout<<"Press 3 to show cart.";
	gotoxy(33,10);
	cout<<"Press 4 to check Bill Report.";
	gotoxy(33,11);
	cout<<"Press 5 to display all products in the shop.";
	gotoxy(33,12);
	cout<<"Press 6 to go back to main menu.";
	gotoxy(33,13);
	cout<<"Press 7 to Exit.";
	int ch;
	gotoxy(47,15);
	cin>>ch;
	switch(ch)
	{
		case 1:{
			aditem();
			break;
		}
		case 2:{
			delitem();
			break;
		}
		case 3:{
			showcart();
			break;
		}
		case 4:{
			
			break;
		}
		case 5:{
			dis_pr();
			break;
		}
		case 6:{
			menu();
			break;
		}
		case 7:{
			gotoxy(45,16);
			cout<<"Exiting.";
			break;
		}
		
		default:{
			gotoxy(40,15);
			cout<<"\aEnter Valid Input!";
			goto a;
			break;
		}
		
	}
	
	
	
}

void admenu()
{
	b:
			system("cls");
			gotoxy(49,8);
			cout<<"Enter Admin PIN: ";
			int pin;
			cin>>pin;
			getch();
			if(pin==1234)
			{
				goto a;
			}
			else
			{
				system("cls");
				gotoxy(49,7);
				cout<<"Wrong PIN.";
				getch();
				int p;
				c:
				system("cls");
				gotoxy(40,8);
				cout<<"Enter 1 to re-enter pin.";
				gotoxy(40,9);
				cout<<"Enter 2 to go back to main menu.";
				gotoxy(45,10);
				
				cin>>p;
				switch(p)
				{
					case 1:{
						goto b;
						break;
					}
					case 2:{
						menu();
						break;
					}
					default:{
						cout<<"\a";
						gotoxy(41,13);
						cout<<"Enter Valid Input!";
						goto c;
						break;
					}
				}
			}
	a:
	system("cls");
	gotoxy(38,5);
	cout<<"WELCOME TO ADMIN MENU";
	gotoxy(37,7);
	cout<<"Press 1 to add product.";
	gotoxy(35,8);
	cout<<"Press 2 to delete a product.";
	gotoxy(33,9);
	cout<<"Press 3 to display all products.";
	gotoxy(33,10);
	cout<<"Press 4 to go back to main menu.";
	int ch;
	gotoxy(47,12);
	cin>>ch;
	switch(ch)
	{
		case 1:{
			add_product();
			break;
		}
		case 2:{
			
			break;
		}
		case 3:{
			dis_pr();
			break;
		}
		case 4:{
			menu();
			break;
		}
		default:{
			gotoxy(40,13);
			cout<<"\aEnter Valid Input!";
			goto a;
			break;
		}	
	}	

}

void add_product()
{
	system("cls");
	ofstream obj;
	obj.open("Shop.txt",ios::app);
	int size;
	gotoxy(39,5);
	cout<<"How many products you want to add? ";
	cin>>size;
	Product p[size];
	for(int i=0;i<size;i++)
	{
		obj<<"Product Sr.No.: ";
		cout<<"\t\t\nEnter the Serial NO for "<<i+1<<" product: ";
		cin>>p[i].pr_id;
		obj<<p[i].pr_id<<endl;
		cin.ignore();
		obj<<"Product Name: ";
		cout<<"\t\tEnter name of "<<i+1<<" product: ";
		getline(cin,p[i].name);
		obj<<p[i].name<<endl;
		obj<<"Product Price: ";
		cout<<"\t\tEnter price of "<<i+1<<" product: ";
		cin>>p[i].price;
		obj<<p[i].price<<endl;
		cin.ignore();
		obj<<"Expiry date: ";
		cout<<"\t\tEnter expiry date of "<<i+1<<" product: ";
		getline(cin,p[i].expdate);
		obj<<p[i].expdate<<endl;
		cin.ignore();
		obj<<"\n--------------------------------------------\n";
	}
	obj.close();
	cout<<"\t\t\t\t\t  Product/s added successfully.";
	cout<<endl<<"\t\t\t\t\t Press any key to go back to Admin Menu.";
	getch();
	admenu();
	
}


void dis_pr()
{
	system("cls");
	ifstream obj;
	obj.open("Shop.txt");
	string n;
	while(!obj.eof())
	{
		getline(obj,n);
		cout<<n<<endl;
	}
	obj.close();
	cout<<"\t\t\t\t\t  These are all the products in Shop.";
	cout<<endl;
	int ch;
	x:
	cout<<"Press 1 to go back to customer menu.\nPress 2 to go to Admin menu\nPress 3 to EXIT program.";
	cin>>ch;
	switch(ch)
	{
		case 1:{
			custmenu();
			break;
		}
		
		case 2:{
			admenu();
			break;
		}
		case 3:{
			cout<<"Exiting!";
			break;
		}
		default:{
			cout<<"Enter Valid Input!";
			goto x;
			break;
		}
	}
	
}


void aditem()
{
	e:
	system("cls");
	ofstream obj;
	obj.open("Customer Cart.txt",ios::app);
	ifstream obj1;
	obj1.open("Shop.txt");
	string pname,n;
	
		
	cout<<"Enter name of product you want to add to your cart: ";
	cin>>pname;
	while (!obj1.eof())
	{
		obj1>>n;
		while(n==pname)
		{
		
			if(n==pname)
			{
				obj<<n<<endl;
				cout<<"Product added successfully to your cart."<<endl;
				goto x;
			}
			
		}
			
	}

	
	int ch;
	x:
	cout<<"Press 1 to add more products to your cart."<<endl;
	cout<<"Press 2 to go back to customer menu."<<endl;
	cout<<"Press 3 to Exit."<<endl;
	cin>>ch;
	switch(ch)
	{
		case 1:{
			goto e;
			break;
		}
		case 2:{
			custmenu();
			break;
		}
		case 3:{
			cout<<"Exiting!";
			break;
		}
		default:{
			cout<<"Enter Valid Input!";
			getch();
			goto x;
			break;
		}
	}
	obj.close();
	obj1.close();
	
}


void showcart()
{
	system("cls");
	ifstream obj;
	obj.open("Customer Cart.txt");
	string n;
	while(!obj.eof())
	{
		getline(obj,n);
		cout<<n<<endl;
	}
	obj.close();
	cout<<"\t\t\t\t\t  These are all the products in the Cart.";
	cout<<endl;
	int ch;
	x:
	cout<<"Press 1 to go back to customer menu.\nPress 2 to go to Admin menu\nPress 3 to EXIT program.";
	cin>>ch;
	switch(ch)
	{
		case 1:{
			custmenu();
			break;
		}
		
		case 2:{
			admenu();
			break;
		}
		case 3:{
			cout<<"Exiting!";
			break;
		}
		default:{
			cout<<"Enter Valid Input!";
			goto x;
			break;
		}
	}
	
}

void delitem()
{
	e:
	system("cls");
	ifstream obj1;
	obj1.open("Customer Cart.txt");
	string pname,n;
	
		
	cout<<"Enter name of item you want to delete from your cart: ";
	cin>>pname;
	while (!obj1.eof())
	{
		obj1>>n;
		while(n==pname)
		{
		
			if(n==pname)
			{
				//remove(n);
				cout<<"Item deleted successfully from your cart."<<endl;
				goto x;
			}
		}
			if(n!=pname)
			{
				cout<<"No such product exist in your cart with this name."<<endl;
				goto x;
			}
		
	}

	
	int ch;
	x:
	cout<<"Press 1 to delete more items from your cart."<<endl;
	cout<<"Press 2 to go back to customer menu."<<endl;
	cout<<"Press 3 to Exit."<<endl;
	cin>>ch;
	switch(ch)
	{
		case 1:{
			goto e;
			break;
		}
		case 2:{
			custmenu();
			break;
		}
		case 3:{
			cout<<"Exiting!";
			break;
		}
		default:{
			cout<<"Enter Valid Input!";
			getch();
			goto x;
			break;
		}
	}
	obj1.close();
}






