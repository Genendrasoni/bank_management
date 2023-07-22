#include <iostream>
#include <fstream>
#include <Windows.h>
using namespace std;

char ch;
class Bank {

	public:
	
	string f_name, l_name, ph_no, address, password  ; int amount;
	Bank() :f_name(""), l_name(""), ph_no(""), address(""), password(""), amount(0) {}
	void welcome() {
cout<<"        \t\t\t\t\t   ___________________________________________________________________________ "<<endl;
cout<<"        \t\t\t\t\t  |                 ------    ----    -     -  -    -                         |"<<endl;
cout<<"        \t\t\t\t\t  |                 |     |  |    |  | -    |  |   -                          |"<<endl;
cout<<"        \t\t\t\t\t  |                 ------   |____|  |  -   |  | -                            |"<<endl;
cout<<"        \t\t\t\t\t  |                 |     |  |    |  |   -  |  |   -                          |"<<endl;
cout<<"        \t\t\t\t\t  |                 ------   |    |  |     -|  |    -                         |"<<endl;
cout<<"        \t\t\t\t\t  |                                                                           |"<<endl;
cout<<"        \t\t\t\t\t  |    -- --   ----   -    -  ----   ----   ----  -- --   ----  -    - -----  |"<<endl;
cout<<"        \t\t\t\t\t  |   |  |  | |    | | -   | |    | |      |     |  |  | |     | -   |   |    |"<<endl;
cout<<"        \t\t\t\t\t  |   |  |  | |____| |  -  | |____| | ___  |---- |  |  | |---- |  -  |   |    |"<<endl;
cout<<"        \t\t\t\t\t  |   |  |  | |    | |   - | |    | |    | |     |  |  | |     |   - |   |    |"<<endl;
cout<<"        \t\t\t\t\t  |   |     | |    | |    -| |    |  ----   ---- |     |  ---- |    -|   |    |"<<endl;
cout<<"        \t\t\t\t\t  |___________________________________________________________________________|"<<endl;

	}
	void info() {
		cout << "Please enter your first name   : \t"; cin >> f_name;
		cout<<endl;
		cout << "Please enter your last name    : \t"; cin >> l_name;
		cout<<endl;
		cout << "Please enter your phone no.    : \t"; cin >> ph_no;
		cout<<endl;
		cin.get(ch);
		cout << "Please enter your address      : \t"; getline(cin,address);
		cout<<endl;
	    cout << "Please create a 4 digit pin    : \t"; cin >> password;
		cout<<endl;


	}
	void display() {
		cout << "Your first name       : \t" << f_name << endl<<endl;
		cout << "Your last name        : \t" << l_name << endl<<endl;
		cout << "Your phone no.        : \t" << ph_no << endl<<endl;
		cout << "Your address          : \t" << address << endl<< endl;
		cout << "Your Balance  is      : \t" << amount << endl<< endl;

	}

	
};

int main() {
	int key;

	Bank b;
	do
	{
	system("cls");	
	b.welcome();
c:	cout << "\n\nPlease select one option from below menu: \n\n";
	cout << "1. Account Open. \n\n2. Deposit Amount. \n\n3. Withdraw Amount. \n\n4. Check Balance. \n\n";
	cout << "5. Update Record. \n\n6. Delete Record. \n\n7. Search Record. \n\n8. Exit. \n\n";
		cin >> key;

		if (key == 1)
		{   system("cls");

			  b.welcome();
			 cout<<"New Account Opening\n\n";
			int back=0;
			b.info();
			ofstream f("D:\\dev c++\\Banking\\Reg_users.dat",ios::app);
			f.write((char*)&b, sizeof(b));
			f.close();
			system("cls");
			 b.welcome();
			cout<<"New Account Opened Sucessfully !\n\n";
			b.display();
			cout<<endl<<endl;
			cout<<"press any number to go to main menu\t"; cin>>back;
			if(back==1){
				system("cls");	
			}
			else{
				system("cls");
			}

			
		}
		else if (key == 2) {
			system("cls");
             b.welcome();
			 cout<<"Money Deposit\n\n";
			int back=0;
			
			string fon,pin; int am = 0,count=0;
			cout << "Please enter your phone number: "; cin >> fon;
		    cout<<endl<<endl;
		    cout << "Please enter your pin         : "; cin >> pin ;
		    cout<<endl<<endl;
			ifstream u("D:\\dev c++\\Banking\\Reg_users.dat");
			while (u.read((char*)&b,sizeof(b)))
			{
				if (fon == b.ph_no && pin == b.password)
				{   system("cls");
				     b.welcome();
					 cout<<"Money Deposit\n\n";
					ofstream f("D:\\dev c++\\Banking\\Reg_users1.dat", ios::app);
					cout << "Name of account holder is      : " << b.f_name << " " << b.l_name << endl<<endl;
					cout << "Current amount is              : " << b.amount << endl<<endl;
					cout << "Please enter new deposit amount: "; cin >> am; cout<<endl<<endl;
					b.amount += am;
					 system("cls");
				     b.welcome();
					 cout<<"Money Deposit\n\n";
					 cout<<"\n\nMoney Deposited Successfully !\n\n";
					cout << "Name of account holder is: " << b.f_name << " " << b.l_name << endl<<endl;
					cout << "Current amount is        : " << b.amount << endl<<endl;
					f.write((char*)&b, sizeof(b));
					ifstream u("D:\\dev c++\\Banking\\Reg_users.dat");
					while (u.read((char*)&b, sizeof(b)))
					{
						if (fon != b.ph_no || pin != b.password)
						{
							f.write((char*)&b, sizeof(b));
						}
					}f.close(); count += 1;
				
				}
				
			}
			if (count==0){
					cout << "\n\n Wrong Phone number or Pin !, Try Again... \n";
				}
			
			u.close();
			if (count >= 1)
			{   
				remove("D:\\dev c++\\Banking\\Reg_users.dat");
				rename("D:\\dev c++\\Banking\\Reg_users1.dat", "D:\\dev c++\\Banking\\Reg_users.dat");
			}
            cout<<"press any number to go to main menu\t"; cin>>back;
			if(back==1){
				system("cls");
			}
			else{
				system("cls");
			}

		}
		else if (key == 3) {
			system("cls");
            b.welcome();
			cout<<"Money Withdrawal\n\n";
			int back=0;
			
			string fon,pin; int am = 0,count = 0;
			cout << "Please enter your phone number: "; cin >> fon;
		    cout<<endl<<endl;
		    cout << "Please enter your pin         : "; cin >> pin ;
		    cout<<endl<<endl;
			ifstream u("D:\\dev c++\\Banking\\Reg_users.dat");
			while (u.read((char*)&b, sizeof(b)))
			{
				if (fon == b.ph_no && pin == b.password)
			a:	{   system("cls");
                    b.welcome();
			        cout<<"Money Withdrawal\n\n";
					ofstream f("D:\\dev c++\\Banking\\Reg_users1.dat", ios::app);
					cout << "Name of account holder is               : " << b.f_name << " " << b.l_name << endl<<endl;
					cout << "Current amount is                       : " << b.amount << endl<<endl;
					cout << "Please enter amount you want to withdraw: "; cin >> am;
			        cout<<endl<<endl;
					if (am <= b.amount)
					{
						b.amount -= am;
					}
					else {
						cout << "Amount being withdrawn is more than amount avaiable in the account.\n\n";
						Sleep(3000);
						goto a;
					}
					system("cls");
                    b.welcome();
			        cout<<"Money Withdrawal\n\n";
					cout<<"\n\nMoney Has been Withdrawn Successfully !\n\n";
					cout << "Name of account holder is: " << b.f_name << " " << b.l_name << endl<<endl;
					cout << "Current amount is        : " << b.amount << endl<<endl;
					f.write((char*)&b, sizeof(b));
					ifstream u("D:\\dev c++\\Banking\\Reg_users.dat");
					while (u.read((char*)&b, sizeof(b)))
					{
						if (fon != b.ph_no || pin != b.password)
						{
							f.write((char*)&b, sizeof(b));
						}
					}
					f.close(); 
					count += 1;

				}
				
			}
			
				if (count==0){
					cout << "\n\n Wrong Phone number or Pin !, Try Again... \n";
				}
			
			u.close();
			if (count >= 1)
			{   
				remove("D:\\dev c++\\Banking\\Reg_users.dat");
				rename("D:\\dev c++\\Banking\\Reg_users1.dat", "D:\\dev c++\\Banking\\Reg_users.dat");
			}

			cout<<"press any number to go to main menu\t"; cin>>back;
			if(back==1){
				system("cls");
			}
			else{
				system("cls");
			}
		}
		else if (key == 4) {
			system("cls");
			 b.welcome();
			 cout<<"Check Balance\n\n";
			int back=0;
			
			string fon,pin; int count=0;
			cout << "Please enter your phone number: "; cin >> fon;
		    cout<<endl<<endl;
		    cout << "Please enter your pin         : "; cin >> pin ;
		    cout<<endl<<endl;
			ifstream u("D:\\dev c++\\Banking\\Reg_users.dat");
			while (u.read((char*)&b, sizeof(b)))
			{
				if (fon == b.ph_no && pin == b.password)
				{
					cout << "Name of account holder is: " << b.f_name << " " << b.l_name << endl<<endl;
					cout << "Current Balance is       : " << b.amount << endl<<endl;
					count =1;
				}
				
			}
			
				if (count==0){
					cout << "\n\n Wrong Phone number or Pin !, Try Again... \n";
				}
			
			u.close();
			cout<<"press any number to go to main menu\t"; cin>>back;
			if(back==1){
				system("cls");
			}
			else{
				system("cls");
			}
		}
		else if(key == 5){
			system("cls");
			 b.welcome();
			 cout<<"Account Update\n\n";
			int back=0;
			
		string fon,pin; int count = 0; char ke, opt;
		cout << "Please enter your phone number: "; cin >> fon;
		cout<<endl<<endl;
		cout << "Please enter your pin         : "; cin >> pin ;
		cout<<endl<<endl;
		ifstream u("D:\\dev c++\\Banking\\Reg_users.dat");
		while (u.read((char*)&b, sizeof(b)))
		{
			if (fon == b.ph_no && pin == b.password)
			{   system("cls");
			    b.welcome();
			    cout<<"Account Update\n\n";
				b.display();
				cout << "=================================================================\n\n";
				ofstream f("D:\\dev c++\\Banking\\Reg_users1.dat", ios::app);
			b:	cout << "To update first name (Press f). \n\nTo update last name (Press l). \n\n";
				cout << "To update phone no. (Press p). \n\nTo update address (Press a). \n\n";
				cin >> ke;
				if (ke == 'f')
				{   system("cls");
			        b.welcome();
			        cout<<"Account Update\n\n";
					cout << "Please enter your new name: "; cin >> b.f_name;
					cout<<endl<<endl;
					f.write((char*)&b, sizeof(b));
					ifstream u("D:\\dev c++\\Banking\\Reg_users.dat");
					while (u.read((char*)&b, sizeof(b)))
					{
						if (fon != b.ph_no || pin != b.password)
						{
							f.write((char*)&b, sizeof(b));
						}
					}
				}
				else if (ke == 'l') {
					system("cls");
			        b.welcome();
			        cout<<"Account Update\n\n";
					cout << "Please enter your new last name: "; cin >> b.l_name;
					cout<<endl<<endl;
					f.write((char*)&b, sizeof(b));
					ifstream u("D:\\dev c++\\Banking\\Reg_users.dat");
					while (u.read((char*)&b, sizeof(b)))
					{
						if (fon != b.ph_no || pin != b.password)
						{
							f.write((char*)&b, sizeof(b));
						}
					}
				}
				else if (ke == 'p') {
					system("cls");
			        b.welcome();
			        cout<<"Account Update\n\n";
					cout << "Please enter your new number: "; cin >> b.ph_no;
					cout<<endl<<endl;
					f.write((char*)&b, sizeof(b));
					ifstream u("D:\\dev c++\\Banking\\Reg_users.dat");
					while (u.read((char*)&b, sizeof(b)))
					{
						if (pin != b.password)
						{
							f.write((char*)&b, sizeof(b));
						}
					}
				}
				else if (ke == 'a') {
					system("cls");
			        b.welcome();
			        cout<<"Account Update\n\n";
					cout << "Please enter your new address: "; cin >> b.address;
					cout<<endl<<endl;
					f.write((char*)&b, sizeof(b));
					ifstream u("D:\\dev c++\\Banking\\Reg_users.dat");
					while (u.read((char*)&b, sizeof(b)))
					{
						if (fon != b.ph_no || pin != b.password)
						{
							f.write((char*)&b, sizeof(b));
						}
					}
				}
				else if (ke == 'q') {
					system("cls");
			        b.welcome();
			        cout<<"Account Update\n\n";
					cout << "Please enter your new pin: "; cin >> b.password;
					cout<<endl<<endl;
					f.write((char*)&b, sizeof(b));
					ifstream u("D:\\dev c++\\Banking\\Reg_users.dat");
					while (u.read((char*)&b, sizeof(b)))
					{
						if (fon != b.ph_no )
						{
							f.write((char*)&b, sizeof(b));
						}
					}
				}
				
				
					system("cls");
			        b.welcome();
			        cout<<"Account Update\n\n";
					cout<<"\n\nAccount Updated Successfully\n\n";
					f.close();
				    count += 1;
				
			}
			
		}
			if (count==0){
					cout << "\n\n Wrong Phone number or Pin !, Try Again... \n";
				}
		
		
		u.close();
		if (count >= 1)
		{
			remove("D:\\dev c++\\Banking\\Reg_users.dat");
			rename("D:\\dev c++\\Banking\\Reg_users1.dat", "D:\\dev c++\\Banking\\Reg_users.dat");
		}
		cout<<"press any number to go to main menu\t"; cin>>back;
			if(back==1){
				system("cls");
			}
			else{
				system("cls");
			}
}
		else if (key == 6) {
			system("cls");
			 b.welcome();
			 cout<<"Delete Account\n\n";
			int back=0;
			
		string fon,pin; int count = 0; char ke;
		cout << "Please enter your phone number: "; cin >> fon;
		cout<<endl<<endl;
		cout << "Please enter your pin         : "; cin >> pin ;
		cout<<endl<<endl;
		ifstream u("D:\\dev c++\\Banking\\Reg_users.dat");
		while (u.read((char*)&b, sizeof(b)))
		{
			if (fon == b.ph_no && pin == b.password)
			{
				ofstream f("D:\\dev c++\\Banking\\Reg_users1.dat", ios::app);
				cout << "Name of account holder is: " << b.f_name << " " << b.l_name << endl<<endl;
				cout << "Current amount is        : " << b.amount << endl<<endl;
				cout << "Do you really want to delete the record? (y/n) ";
				cin >> ke;
				if (ke == 'y')
				{
					ifstream u("D:\\dev c++\\Banking\\Reg_users.dat");
					while (u.read((char*)&b, sizeof(b)))
					{
						if (fon != b.ph_no || pin != b.password)
						{
							f.write((char*)&b, sizeof(b));
						}

					}
				}
				else {
					goto c;
				}
				f.close(); 
				count += 1;

			}
			
		}
		
			if (count==0){
					cout << "\n\n Wrong Phone number or Pin !, Try Again... \n" ;
				}
		
		
		u.close();
		if (count >= 1)
		{   cout<<"\n\nYour Account Has Been Deleted\n\n";
			remove("D:\\dev c++\\Banking\\Reg_users.dat");
			rename("D:\\dev c++\\Banking\\Reg_users1.dat", "D:\\dev c++\\Banking\\Reg_users.dat");
		}
		cout<<"press any number to go to main menu\t"; cin>>back;
			if(back==1){
				system("cls");
			}
			else{
				system("cls");
			}
}
		else if (key == 7) {
			system("cls");
			 b.welcome();
			 cout<<" Account Search\n\n";
		int back=0;
		
		string fon,pin; int count =0;
		cout << "Please enter your phone number: "; cin >> fon;
		cout<<endl<<endl;
		cout << "Please enter your pin         : "; cin >> pin ;
		cout<<endl<<endl;
		ifstream u("D:\\dev c++\\Banking\\Reg_users.dat");
		while (u.read((char*)&b, sizeof(b)))
		{
			if (fon == b.ph_no && pin == b.password)
			{  
				b.display();
				count=1;
			}
			
		}
			if (count==0){
					cout << "\n\n Wrong Phone number or Pin !, Try Again... \n";
				}
		
		u.close();

		cout<<"press any number to go to main menu\t"; cin>>back;
			if(back==1){
				system("cls");
				
			}
			else{
				system("cls");
			}
}

	} while (key != 8);
	system("cls");
	b.welcome();
	cout << "\n\n\t\t\t\t\t\t\t\t\t Thank You for visiting our bank! \n\t\t\t\t\t\t";
}