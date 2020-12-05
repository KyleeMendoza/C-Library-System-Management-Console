#include <iostream>
#include<conio.h>
#include<string>

using namespace std;

//I use encapsulation getters and setters for privacy of attributes
class Book {
    private:
        string isbn,title,author,edition,publication;
    public:
        void setIsbn(string a){isbn = a;};
        void setTitle(string b){title = b;};
        void setAuthor(string c){author = c;};
        void setEdition(string d){edition = d;};
        void setPublication(string e){publication = e;};
        string getIsbn(){return isbn;};
        string getTitle(){return title;};
        string getAuthor(){return author;};
        string getEdition(){return edition;};
        string getPublication(){return publication;};
};
//I use encapsulation getters and setters for privacy of attributes
class member{
	private:
		string name;
		string number;
		string age;
		string code;
	public:
		void setCode(string a){code = a;
		};
		void setName(string b){name = b;
		};
		void setNumber(string c){number = c;
		};
		void setAge(string d){age = d;
		};
		string getCode(){return code;
		};
		string getName(){return name;
		};
		string getNumber(){return number;
		};
		string getAge(){return age;
		};
};	
//Created an object based on the "member" class and initialized an array 
member members[100];
//Created an object based on the "Book" class and initialized an array 
Book books[10];
//Then for organization, I initialized all functions to be used
void mainScreen();
void menu();
void case1(int counter);
void case2(int account);
void case3(int counter);
void case4(int account);
void case5(int account);
void case6(int counter);
void case7();
//Initialization of parameters to be used in all functions
int account = 0;
int counter = 0;
//Created functions that will increment and decrement parameters
void incrementBooks(int a){
	a++;
	counter=a;
}
void decrementBooks(int a){
	a--;
	counter=a;
}
void incrementAccount(int b){
	b++;
	account=b;
}
void decrementAccount(int b){
	b--;
	account=b;
}
void zeroCounter(int c){
	c = 0;
	counter = c;
}
void zeroMember(int c){
	c = 0;
	account = c;
}
//MAIN 
int main()
{
	//Program that limit log in access to 3 trials
    int password = 1234;
    int pass;
    int trial = 0;
    mainScreen();
    while(true){
        cout <<"Enter your password: ";
        cin >> pass;
        if (pass == password){
            system("CLS");
            mainScreen();
            menu();
            break;
        }
        else if(counter == 2){
            system("CLS");
            mainScreen();
            cout<<"You've exceed the number of attempt. Please try again later." << endl;
            break;
        }
        else{
            system("CLS");
            mainScreen();
            cout <<"You've entered incorrect password. Please try again."<< endl;
            trial++;
        }
    }
    return 0;
}
//Main header
void mainScreen(){
    cout << "*****Kyle Mendoza Library*****" << endl;
    cout << "    Manggahan, Pasig City" << endl;
    cout << "      TELEPHONE: 6817387" << endl;
    cout << "          CODE: 1611" << endl;
}
//Main tab
void menu(){
    int choice;
    cout <<"1. Add new books\n";
    cout <<"2. Add new members\n";
    cout <<"3. Remove a book\n";
    cout <<"4. Remove a member\n";
    cout <<"5. View members account\n";
    cout <<"6. View stock\n";
	cout <<"7.Exit\n";
    cout <<"Enter your choice: ";
    cin >> choice;
    switch(choice){
    case 1:
        case1(counter);
        break;
    case 2:
        case2(account);
        break;
    case 3:
        case3(counter);
        break;
    case 4:
        case4(account);
        break;
    case 5:
        case5(account);
        break;
    case 6:
        case6(counter);
        break;
    case 7:
    	system("CLS");
        cout<<"Thank you!";
        case7();
        break;
    default:
    	system("CLS");
        cout << "You've entered invalid number." << endl;
        cout<<"Press any key to continue . . .";
        _getch();
        system("CLS");
    	mainScreen();
		menu();
        break;
    }
}
//ADD BOOKS
void case1(int counter){
    string isbn,title,author,edition,publication;
    system("CLS");
    mainScreen();
    cout << "Enter ISBN: ";
    cin >> isbn;
    cout << "Enter Title: ";
    cin >> title;
    cout << "Enter Author: ";
    cin >> author;
    cout << "Enter Edition: ";
    cin >> edition;
    cout << "Enter Publication: ";
    cin >> publication;
    books[counter].setIsbn(isbn);
    books[counter].setTitle(title);
    books[counter].setAuthor(author);
    books[counter].setEdition(edition);
    books[counter].setPublication(publication);
    incrementBooks(counter);
    cout<<"BOOK ADDED!.."<< endl;
    cout<<"Press any key to continue . . .";
	_getch();
    system("CLS");
    mainScreen();
	menu();
};
//ADD MEMBERS
void case2(int account){
	string name,number,age,code;
	system("CLS");
    mainScreen();
    cout << "Enter Code: ";
    cin >> code;
    cout << "Enter Name: ";
    cin >> name;
    cout << "Enter Number: ";
    cin >> number;
    cout << "Enter Age: ";
    cin >> age;
    members[account].setCode(code);
    members[account].setName(name);
    members[account].setNumber(number);
    members[account].setAge(age);
    incrementAccount(account);
    cout<<"Account Added!"<< endl;
    cout<<"Press any key to continue . . .";
	_getch();
    system("CLS");
    mainScreen();
	menu();   
};
//REMOVE BOOK
void case3(int counter){
	system("CLS");
    mainScreen();
    int choice;
    string isbn;
    cout << "1. Remove all."<<endl;
    cout << "2. Search ISBN."<< endl;
    cout << "Enter your Choice: "<< endl;
    cin >> choice;
    system("CLS");
    mainScreen();
    if (choice == 1){
    	if (counter == 0){
    		cout<<"THERE IS NO BOOK TO REMOVE"<<endl;
    		cout<<"Press any key to continue . . .";
			_getch();
    		system("CLS");
    		mainScreen();
			menu();   
		}
		else{
			zeroCounter(counter);
			cout<<"ALL BOOKS ARE SUCCESSFULLY REMOVED"<<endl;
			cout<<"Press any key to continue . . .";
			_getch();
    		system("CLS");
    		mainScreen();
			menu();  
		}
	}
	else if (choice == 2){
		cout<<"Enter ISBN to be removed: "<<endl;
		cin >> isbn;
		system("CLS");
    	mainScreen();
    	for(int i=0;i<counter;i++){
    		if (books[i].getIsbn() == isbn){
    			books[i].setIsbn("");
    			books[i].setTitle("");
    			books[i].setAuthor("");
    			books[i].setEdition("");
    			books[i].setPublication("");
    			decrementBooks(counter);
    			for(int a=i;a<counter;a++){
    				books[a] = books[a+1];
				}
    			cout<<"THE BOOK IS SUCCESSFULLY REMOVED"<<endl;
				cout<<"Press any key to continue . . .";
				_getch();
    			system("CLS");
    			mainScreen();
				menu();  
			}
		}
		cout<<"\nBOOK NOT FOUND!\n\nPress any key to continue . . .";
		cout<<"Press any key to continue . . .";
		_getch();
    	system("CLS");
    	mainScreen();
		menu(); 
	}
	
	else{
		cout<<"Invalid Entry"<<endl;
		cout<<"Press any key to continue . . .";
		_getch();
    	system("CLS");
    	mainScreen();
		menu(); 
	}
};
//REMOVE MEMBER
void case4(int account){
	system("CLS");
    mainScreen();
    int choice;
    string code;
    cout << "1. Remove all."<<endl;
    cout << "2. Search Code."<< endl;
    cout << "Enter your Choice: "<< endl;
    cin >> choice;
    system("CLS");
    mainScreen();
    if (choice == 1){
    	if (account == 0){
    		cout<<"THERE IS NO MEMBER TO REMOVE"<<endl;
    		cout<<"Press any key to continue . . .";
			_getch();
    		system("CLS");
    		mainScreen();
			menu();   
		}
		else{
			zeroMember(account);
			cout<<"ALL ACCOUNTS ARE SUCCESSFULLY REMOVED"<<endl;
			cout<<"Press any key to continue . . .";
			_getch();
    		system("CLS");
    		mainScreen();
			menu();  
		}
	}
	else if (choice == 2){
		cout<<"Enter Code to be removed: "<<endl;
		cin >> code;
		system("CLS");
    	mainScreen();
    	for(int i=0;i<account;i++){
    		if (members[i].getCode() == code){
    			members[i].setCode("");
    			members[i].setName("");
    			members[i].setNumber("");
    			members[i].setAge("");
    			decrementAccount(account);
    			for(int a=i;a<account;a++){
    				members[a] = members[a+1];
				}
    			cout<<"THE MEMBER IS SUCCESSFULLY REMOVED"<<endl;
				cout<<"Press any key to continue . . .";
				_getch();
    			system("CLS");
    			mainScreen();
				menu();  
			}
		}
		cout<<"\nMEMBER NOT FOUND!\n\nPress any key to continue . . .";
		cout<<"Press any key to continue . . .";
		_getch();
    	system("CLS");
    	mainScreen();
		menu(); 
	}
	
	else{
		cout<<"Invalid Entry"<<endl;
		cout<<"Press any key to continue . . .";
		_getch();
    	system("CLS");
    	mainScreen();
		menu(); 
	}
};
//VIEW MEMBERS
void case5(int account){
	system("CLS");
    mainScreen();
    int choice;
    cout <<"1.All Memmbers."<< endl;
    cout <<"2.Search Code."<<endl;
    cout <<"Enter Your Choice: ";
    cin>>choice;
    system("CLS");
    mainScreen();
    if (choice == 1){
    	if (account == 0){
    		cout << "Only admin account detected." << endl;
    		cout<<"Press any key to continue . . .";
			_getch();
			system("CLS");
    		mainScreen();
			menu();
		}
		else{
			for(int i=0;i<account;i++){
				if (i == 0){
					cout<<"CODE\t"<<"NAME\t"<<"NUMBER\t"<<"AGE\t"<<endl;
				}
				cout<<members[i].getCode()<<"\t"<<members[i].getName()<<"\t"<<members[i].getNumber()<<"\t"<<members[i].getAge()<<endl<<endl;
				cout<<"\nTOTAL NUMBER OF ACCOUNT: "<<account<<endl;
			}
		}
	}
	else if (choice == 2){
		system("CLS");
    	mainScreen();
		string code;
		int found = 0;
		cout<<"Enter the Code: ";
		cin >> code;
		system("CLS");
    	mainScreen();
		for(int i=0;i<account;i++){
			if (members[i].getCode() == code){
				cout<<"CODE\t"<<"NAME\t"<<"NUMBER\t"<<"AGE\t"<<endl;
				cout<<members[i].getCode()<<"\t"<<members[i].getName()<<"\t"<<members[i].getNumber()<<"\t"<<members[i].getAge()<<endl<<endl;
				found++;
				break;
			}
			else{continue;};
		}
		if (found == 0){
			cout<<"Member do not exist"<<endl;
		}
	}
	else{
		cout<<"Invalid Entry"<<endl;
	}
	cout<<"Press any key to continue . . .";
	_getch();
	system("CLS");
    mainScreen();
	menu();	
};
//VIEW STOCKS
void case6(int counter){
    system("CLS");
    mainScreen();
    int choice;
    cout <<"1.All Books."<< endl;
    cout <<"2.Search ISBN."<<endl;
    cout <<"Enter Your Choice: ";
    cin>>choice;
    system("CLS");
    mainScreen();
    if (choice == 1){
    	system("CLS");
    	mainScreen();
    	if (counter == 0){
    		cout << "There is none listed" << endl;
    		cout<<"Press any key to continue . . .";
			_getch();
			system("CLS");
    		mainScreen();
			menu();
		}
		else{
			for(int i=0;i<counter;i++){
				if (i == 0){
					cout<<"ISBN\t"<<"TITLE\t"<<"AUTHOR\t"<<"EDITION\t"<<"PULICATION\t"<<endl;
				}
				cout<<books[i].getIsbn()<<"\t"<<books[i].getTitle()<<"\t"<<books[i].getAuthor()<<"\t"<<books[i].getEdition()<<"\t"<<books[i].getPublication()<<endl<<endl;
			}
			cout<<"\nTOTAL NUMBER OF BOOKS: "<<counter<<endl;
		}
	}
	else if (choice == 2){
		system("CLS");
    	mainScreen();
		string isbn;
		int found = 0;
		cout<<"Enter the ISBN: ";
		cin >> isbn;
		system("CLS");
    	mainScreen();
		for(int i=0;i<counter;i++){
			if (books[i].getIsbn() == isbn){
				cout<<"ISBN\t"<<"TITLE\t"<<"AUTHOR\t"<<"EDITION\t"<<"PULICATION\t"<<endl;
				cout<<books[i].getIsbn()<<"\t"<<books[i].getTitle()<<"\t"<<books[i].getAuthor()<<"\t"<<books[i].getEdition()<<"\t"<<books[i].getPublication()<<endl<<endl;
				found++;
				break;
			}
			else{continue;};
		}
		if (found == 0){
			cout<<"ISBN do not exist"<<endl;
		}
	}
	else{
		cout<<"Invalid Entry"<<endl;
	}
    cout<<"Press any key to continue . . .";
	_getch();
	system("CLS");
    mainScreen();
	menu();	
};
//EXIT
void case7(){
    _exit(1);
};







