
#include<iostream>
#include<fstream>
#include <list>
#include <map>
#include<iomanip>
using namespace std;

#define Reader_FILE "Reader.txt"

#define LibraryCount_FILE "LibraryCount.txt"

#define BookId_FILE "BookID.txt"

#define  BookBorrow_FILE "BookBorrow.txt"
typedef struct Date
{
	int Year;
	int Month;
	int day;

}Date;



class UserBaser
{
public:
	enum class Power
	{
		Nothing,
		Orindary,
		BookManager,
		SystemManager
	};
	string NameId;
	string Password;
	Power State;
	UserBaser() {};
	UserBaser(const UserBaser& User)
	{
		State = User.State;
		NameId = User.NameId;
		Password = User.Password;
	}
	UserBaser(Power State1, string Nameid1, string Password1) :NameId(Nameid1), Password(Password1), State(State1) {}
	~UserBaser() {}

};
class Reader :public UserBaser
{
public:
	string Name;
	string workLocation;
	int phoneId;
	int AllowBrrow;
	int NowBorrow;
	Reader() {};
	Reader(Power State1,
		string NameID1,
		string Password1,
		string Name1,
		string workLocation1,
		int phoneId1,
		int AllowBrow1,
		int NowBorrow1) :UserBaser(State1, NameID1, Password1)
	{
		Name = Name1;
		workLocation = workLocation1;
		phoneId = phoneId1;
		AllowBrrow = AllowBrow1;
		NowBorrow = NowBorrow1;
	}
	Reader(const Reader& Read) :UserBaser(Read)
	{
		Name = Read.Name;
		workLocation = Read.workLocation;
		phoneId = Read.phoneId;
		AllowBrrow = Read.AllowBrrow;
		NowBorrow = Read.NowBorrow;
	}
	void SetNWPAN(string Name1, string Lcoation1, int Phone1, int ALLowBook, int NowBook)
	{
		Name = Name1;
		workLocation = Lcoation1;
		phoneId = Phone1;
		AllowBrrow = ALLowBook;
		NowBorrow = NowBook;
	}
};


class Book
{
public:
	string BookName; string writer; string BookId; string Bookpublisher; int Inventory; int NowBorrow;
	Date TimeBorrow; Date TimeReturn;
	Book() {};
	Book(string BookName1,
		string BookId1,
		string Bookpublisher1,
		string writer1,
		int Inventory1,
		int NowBrrow1) :BookName(BookName1), BookId(BookId1), Bookpublisher(Bookpublisher1), Inventory(Inventory1), NowBorrow(NowBrrow1), writer(writer1) {}
	Book(const Book& Book1) {

		BookName = Book1.BookName;
		BookId = Book1.BookId;
		Bookpublisher = Book1.Bookpublisher;
		Inventory = Book1.Inventory;
		NowBorrow = Book1.NowBorrow;
		writer = Book1.writer;
	}
	void SetBookTimeBorrow(int Year, int month, int day);
	void SetBookTimeReturn(int Year, int month, int day);

};

ostream& operator<<(ostream& out, UserBaser& User);

ostream& operator<<(ostream& out, Reader& Reade);

ostream& operator<<(ostream& out, Book& Book1);
class LibraryManage
{

public:
	int ShowMenu(UserBaser& User);

	bool CheckWho(UserBaser& User, int MenuId);



	class UserManage
	{
	public:
		bool CheckWho(UserBaser& User, int MenuId);

		int ShowMenu(UserBaser& User);

		void UserInfoinput();

		bool SetInfo();

		bool DelUserInfo();

		void ShowUserInfo();

		bool SetPassword();

		bool WriteToFIle();

		bool LogFromFile();

		bool CheckIsHave(string NameId);
	private:
		list <UserBaser>Users;

	};


	class ReaderManage
	{
	public:
		int ShowMenu(UserBaser& User);

		bool CheckWho(UserBaser& User, int select);


		void ReaderInfoInput();

		bool SetReaderInfo();

		bool DelReaderInfo();

		void ShowReaderInfo();

		bool SearchReaderByNameId();

		bool LogNewReaderFromFile();

		bool LogoldReaderFromFile();

		bool WriteToFile();

		bool CheckIsHave(string NameId);
	private:
		list<Reader>Readers;
	};


	class BookManage
	{
	public:
		int ShowMenu(UserBaser& User);

		bool CheckWho(UserBaser& User, int MenuId);

		void AddBooks();

		void SetBook();

		void QueryBook();

		void SearchBookByNameId();

		void SearchBookByBookName();

		void SearchBookByWriter();

		void SearchBookPublisher();

		void Summary();

		void LOgBookToDoc();

		void LogBookFromFILE();

	private:
		list<Book>Books;

	};

	class BookPortManage
	{
	public:

		void ShowMenu(UserBaser& User);

		void BorrowBook(UserBaser& User);

		void ReturnBook(UserBaser& User);

		void LOgBookToDoc();

		void LogBookFromFILE();

		void LOgBookToDocB();

		bool LogoldReaderFromFile();

		bool WriteToFile();

	private:
		list<Book>Books;

		list<Reader>ReadesKCopy;
	};
public:
	UserManage UserManageInstance;
	ReaderManage ReaderManageInstance;
	BookManage BookManageInstance;
	BookPortManage BookPortManageInstance;
};







//cPP
ostream& operator<<(ostream& out, UserBaser& User)
{
	out << "\t\t" << setw(6) << User.NameId << "\t" << setw(6) << User.Password << "\t" << setw(6) << (int)User.State << endl;;
	return out;
}
ostream& operator<<(ostream& out, Reader& Reade)
{
	out << "\t\t" << setw(6) << Reade.NameId << "\t" << setw(6) << Reade.Name << "\t" << setw(6) << Reade.workLocation << "\t" << setw(6) << Reade.phoneId << "\t" << setw(6) << Reade.AllowBrrow << "\t" << setw(6) << Reade.NowBorrow << endl;
	return out;
}

std::ostream& operator<<(ostream& out, Book& Book1)
{
	out << "\t\t" << setw(6) << Book1.BookName << "\t" << setw(6) << Book1.BookId << "\t" << setw(6) << Book1.Bookpublisher << "\t\t" << setw(6) << Book1.writer << "\t\t" << setw(6) << Book1.Inventory << "\t\t" << setw(6) << Book1.NowBorrow << endl;
	return out;
}
std::ostream& operator<<(ostream& out, Date& date)
{
	out << setw(6) << date.Year << "\t" << setw(6) << date.Month << "\t" << setw(6) << date.day << endl;
	return out;
}
void Book::SetBookTimeBorrow(int Year, int month, int day)
{
	TimeBorrow.Year = Year;
	TimeBorrow.Month = month;
	TimeBorrow.day = day;
}

void Book::SetBookTimeReturn(int Year, int month, int day)
{
	TimeReturn.Year = Year;
	TimeReturn.Month = month;
	TimeReturn.day = day;

}

int LibraryManage::ShowMenu(UserBaser& User)
{

	int select;
	while (true)
	{
		cout << "\t\t -------------------------------\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t|          1.UserManage         |\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t|          2.ReaderManage       |\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t|          3.BookManage         |\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t|          4.BookPortMan        |\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t|          5.Exit               |\n";
		cout << "\t\t -------------------------------\n";
		cout << "输入您的选择: ";
		cin >> select;
		switch (select)
		{
		case 1:
			if (CheckWho(User, select))
			{
				system("cls");
				UserManageInstance.LogFromFile();
				UserManageInstance.ShowMenu(User);

			}
			else
			{
				cout << "You No Entry Possess" << endl;
				cout << "Please ReInput" << endl;
				system("pause");
				system("cls");
			}
			break;
		case 2:
			if (CheckWho(User, select))
			{
				system("cls");
				ReaderManageInstance.LogoldReaderFromFile();
				ReaderManageInstance.LogNewReaderFromFile();
				ReaderManageInstance.ShowMenu(User);

			}
			else
			{
				cout << "You No Entry Possess" << endl;
				cout << "Please ReInput" << endl;
				system("pause");
				system("cls");
			}
			break;
		case 3:
			if (CheckWho(User, select))
			{
				system("cls");
				BookManageInstance.LogBookFromFILE();
				BookManageInstance.ShowMenu(User);
			}
			else
			{
				cout << "You No Entry Possess" << endl;
				cout << "Please ReInput" << endl;
				system("pause");
				system("cls");
			}
			break;
		case 4:
			if (CheckWho(User, select))
			{
				system("cls");
				BookPortManageInstance.LogoldReaderFromFile();
				BookPortManageInstance.LogBookFromFILE();
				BookPortManageInstance.ShowMenu(User);

			}
			else
			{
				cout << "You No Entry Possess" << endl;
				cout << "Please ReInput" << endl;
				system("pause");
				system("cls");
			}
			break;
		case 5:
			cout << "欢迎下次使用" << endl;
			system("pause");
			system("cls");
			return 0;
			break;
		default:
			cout << "Error Input ReInput" << endl;
			system("pause");
			system("cls");
			break;
		}
	}


}
bool LibraryManage::CheckWho(UserBaser& User, int Menuid)
{
	if (User.State == UserBaser::Power::SystemManager)
	{
		if (Menuid == 1)
			return true;
		if (Menuid == 3)
			return true;

		else
			return false;
	}
	if (User.State == UserBaser::Power::Orindary)
	{
		if (Menuid == 1)
			return true;
		if (Menuid == 3)
			return true;
		if (Menuid == 4)
			return true;
		else
			return false;
	}
	if (User.State == UserBaser::Power::BookManager)
	{
		return true;
	}
	else
	{
		return false;
	}
}
//UserManager---------------------------------------------------
bool LibraryManage::UserManage::CheckWho(UserBaser& User, int MenuId)
{
	if (User.State == UserBaser::Power::Orindary)
	{
		if (MenuId == 5)
			return true;
		return false;
	}
	if (User.State == UserBaser::Power::BookManager)
	{
		if (MenuId == 5)
			return true;
		return false;
	}
	if (User.State == UserBaser::Power::SystemManager)
	{
		return true;
	}
	else
	{
		return false;
	}
}

int LibraryManage::UserManage::ShowMenu(UserBaser& User)
{
	int select;
	while (true)
	{
		cout << "\t\t -------------------------------|\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t|          1.UserInfoInput      |\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t|          2.UserInfoChange     |\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t|          3.UserINfoDel        |\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t|          4.UserInfoShow       |\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t|          5.UserpasswordChange |\n";
		cout << "\t\t|								 |\n";
		cout << "\t\t|          6.Return Menu		 |\n";
		cout << "\t\t -------------------------------|\n";
		cout << "输入您的选择: ";
		cin >> select;
		switch (select)
		{
		case 1:
			if (CheckWho(User, select))
			{
				system("cls");
				UserInfoinput();
			}
			else
			{
				cout << "You No Entry Possess" << endl;
				cout << "Please ReInput" << endl;
				system("pause");
				system("cls");
			}
			break;
		case 2:
			if (CheckWho(User, select))
			{
				system("cls");
				SetInfo();

			}
			else
			{
				cout << "You No Entry Possess" << endl;
				cout << "Please ReInput" << endl;
				system("pause");
				system("cls");
			}
			break;
		case 3:
			if (CheckWho(User, select))
			{
				system("cls");
				DelUserInfo();

			}
			else
			{
				cout << "You No Entry Possess" << endl;
				cout << "Please ReInput" << endl;
				system("pause");
				system("cls");
			}
			break;
		case 4:
			if (CheckWho(User, select))
			{
				system("cls");
				ShowUserInfo();
			}
			else
			{
				cout << "You No Entry Possess" << endl;
				cout << "Please ReInput" << endl;
				system("pause");
				system("cls");
			}
			break;
		case 5:
			if (CheckWho(User, select))
			{
				system("cls");
				SetPassword();
			}
			else
			{
				cout << "You No Entry Possess" << endl;
				cout << "Please ReInput" << endl;
				system("pause");
				system("cls");
			}
			break;
		case 6:
			WriteToFIle();
			Users.clear();
			cout << "Welcome Next Time" << endl;
			system("pause");
			system("cls");
			return 0;
			break;

		default:
			cout << "Error Input ReInput";
			system("pause");
			system("cls");
			break;
		}

	}

}

void LibraryManage::UserManage::UserInfoinput()
{

	int Num;
	cout << "How Many People Input" << endl;
	cin >> Num;
	string NameId;
	string passoword;
	int Identity;
	for (int i = 0; i < Num; i++)
	{

		cout << "Please Input Identity" << endl;
		cout << "1. Ordinary2.BookManager 3.SystemManager" << endl;
		cin >> Identity;
		while (Identity != 1 && Identity != 2 && Identity != 3)
		{
			cout << "Error Input" << endl;
			cin >> Identity;
			cin.get();
		}
		cout << "Please input NameId And Password" << endl;
		cin >> NameId >> passoword; cin.get();
		if (Identity == 1)
		{
			Users.push_back(Reader(UserBaser::Power::Orindary, NameId, passoword, "0", "0", 0, 0, 0));
		}
		else
		{
			Users.push_back(UserBaser(UserBaser::Power(Identity), NameId, passoword));
		}


	}
	cout << "Successful" << endl;
}

bool LibraryManage::UserManage::SetInfo()
{
	string nameid;
	string pass;
	string nameNewId;
	cout << "Please Who You Want Change Name" << endl;
	cin >> nameid; cin.get();
	cout << "Please input Password You Want" << endl;
	cin >> pass; cin.get();
	cout << "Please Who You Want New Name" << endl;
	cin >> nameNewId; cin.get();
	for (auto TempUser = Users.begin(); TempUser != Users.end(); TempUser++)
	{
		if (nameid == (*TempUser).NameId)
		{
			(*TempUser).NameId = nameNewId;
			(*TempUser).Password = pass;
			cout << "Successful!" << endl;
			return true;
		}

	}
	cout << "Fail No Name" << endl;
	return false;


}

bool LibraryManage::UserManage::DelUserInfo()
{
	string nameid;
	cout << "Please Who You Want Delete Nameid" << endl;
	cin >> nameid;

	for (list<UserBaser>::iterator TempUser = Users.begin(); TempUser != Users.end(); TempUser++)
	{
		if ((*TempUser).NameId == nameid)
		{
			Users.erase(TempUser);
			cout << "Successful!" << endl;
			return true;
		}
	}
	cout << "Fail No Name" << endl;
	return false;


}

void LibraryManage::UserManage::ShowUserInfo()
{
	cout << "\t\t" << setw(6) << "Name" << "\t" << setw(6) << "Pass" << "\t" << setw(6) << "User" << endl;
	for (auto& TempUser : Users)
	{
		cout << TempUser;
	}
}


bool LibraryManage::UserManage::SetPassword()
{
	string nameid;
	string pass;
	cout << "Please Who You Want Change Name" << endl;
	cin >> nameid;
	cout << "Please input Password You Want" << endl;
	cin >> pass;
	for (auto TempUser = Users.begin(); TempUser != Users.end(); TempUser++)
	{
		if (nameid == (*TempUser).NameId)
		{
			(*TempUser).Password = pass;
			cout << "Successful!" << endl;
			return true;
		}

	}
	cout << "Fail NoName" << endl;
	return false;


}

bool LibraryManage::UserManage::WriteToFIle()
{
	ofstream ofs;
	ofs.open(LibraryCount_FILE, ios::out | ios::trunc);
	if (!ofs.is_open())
	{
		cout << "Fail To Open File" << endl;
		return false;
	}
	for (auto& TempUser : Users)
	{
		ofs << TempUser.NameId << " " << TempUser.Password << " " << (int)TempUser.State << endl;
	}
	return true;
}

bool LibraryManage::UserManage::LogFromFile()
{
	ifstream ifs;
	ifs.open(LibraryCount_FILE, ios::in);
	if (!ifs.is_open())
	{
		cout << "Fail To Open File" << endl;
		return false;
	}
	string nameid; string pass; int State;
	while (ifs >> nameid, ifs >> pass, ifs >> State)
	{
		Users.push_back(UserBaser(UserBaser::Power(State), nameid, pass));
	}
	return true;
}

bool LibraryManage::UserManage::CheckIsHave(string NameId)
{
	for (auto& User : Users)
	{
		if (User.NameId == NameId)
		{
			return true;
		}
	}
	return false;
}

//ReaderManager-------------------------------------------------
int LibraryManage::ReaderManage::ShowMenu(UserBaser& User)
{
	int select = 0;
	while (true)
	{
		cout << "\t\t -------------------------------\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t|          1.ReaderInfoInput    |\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t|          2.ReaderInfoChange   |\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t|          3.ReaderInfoDel      |\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t|          4.ReaderInfoQuery    |\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t|          5.ReaderInfoShow     |\n";
		cout << "\t\t|								 |\n";
		cout << "\t\t|          6.Return Menu		 |\n";
		cout << "\t\t -------------------------------\n";
		cout << "输入您的选择: ";
		cin >> select;
		switch (select)
		{
		case 1:
			if (CheckWho(User, select))
			{
				system("cls");
				ReaderInfoInput();
	
			}
			else
			{
				cout << "You No Entry Possess" << endl;
				cout << "Please ReInput" << endl;
				system("pause");
				system("cls");
			}
			break;
		case 2:
			if (CheckWho(User, select))
			{
				system("cls");
				SetReaderInfo();

			}
			else
			{
				cout << "You No Entry Possess" << endl;
				cout << "Please ReInput" << endl;
				system("pause");
				system("cls");
			}
			break;
		case 3:
			if (CheckWho(User, select))
			{
				system("cls");
				DelReaderInfo();
			}
			else
			{
				cout << "You No Entry Possess" << endl;
				cout << "Please ReInput" << endl;
				system("pause");
				system("cls");
			}
			break;
		case 4:
			if (CheckWho(User, select))
			{
				system("cls");
				SearchReaderByNameId();
			}
			else
			{
				cout << "You No Entry Possess" << endl;
				cout << "Please ReInput" << endl;
				system("pause");
				system("cls");
			}
			break;
		case 5:
			if (CheckWho(User, select))
			{
				system("cls");
				ShowReaderInfo();
			}
			else
			{
				cout << "You No Entry Possess" << endl;
				cout << "Please ReInput" << endl;
				system("pause");
				system("cls");
			}
			break;
		case 6:
			WriteToFile();
			Readers.clear();
			cout << "Welcome Next Time" << endl;
			system("pause");
			system("cls");
			return 0;
			break;
		default:
			cout << "Error Input ReInput";
			system("pause");
			system("cls");
			break;
		}



	}
}
bool LibraryManage::ReaderManage::CheckWho(UserBaser& User, int select)
{
	if (User.State == UserBaser::Power::Orindary)
		return false;
	if (User.State == UserBaser::Power::SystemManager)
		return false;
	else if (User.State == UserBaser::Power::BookManager)
		return true;
	else
		return false;
}


void LibraryManage::ReaderManage::ReaderInfoInput()
{
	string Name1; string WorkLocation1; int PhoneId1; int AllwoBook; int NowBook;
	for (auto Readr = Readers.begin(); Readr != Readers.end(); Readr++)
	{
		if ((*Readr).workLocation == "0")
		{
			cout << "Please Input The Name Work Phone AllowBook NowBook of ID" << (*Readr).NameId << endl;
			cin >> Name1 >> WorkLocation1 >> PhoneId1 >> AllwoBook >> NowBook;
			cin.get();
			(*Readr).SetNWPAN(Name1, WorkLocation1, PhoneId1, AllwoBook, NowBook);
		}

	}
}

bool LibraryManage::ReaderManage::SetReaderInfo()
{
	string Id; string Name; string Location; int Phone; int AllowBook; int NowBook;
	cout << "Please Input You Want Changed NameId" << endl;
	cin >> Id;
	cin.get();
	for (auto TempRe = Readers.begin(); TempRe != Readers.end(); TempRe++)
	{
		if ((*TempRe).NameId == Id)
		{
			cout << "You Want to Set Name And Work And  Phone And AllowBook And NowBook " << endl;
			cin >> Name >> Location >> Phone >> AllowBook >> NowBook;
			cin.get();
			(*TempRe).SetNWPAN(Name, Location, Phone, AllowBook, NowBook);
			cout << "Successful" << endl;
			return true;
		}
		
	}
	cout << "Fail No NameId" << endl;
	return false;
}

bool LibraryManage::ReaderManage::DelReaderInfo()
{
	string Nameid;
	cout << "Input NameId for You Want Delete" << endl;
	cin >> Nameid;
	for (auto TempRe = Readers.begin(); TempRe != Readers.end(); TempRe++)
	{
		if ((*TempRe).NameId == Nameid)
		{
			Readers.erase(TempRe);
			cout << "Successful" << endl;
			return true;
		}
	}
	cout << "Fail No NameId" << endl;
	return false;



}

void LibraryManage::ReaderManage::ShowReaderInfo()
{

	cout << "\t\t" << setw(6) << "NameId" << "\t" << setw(6) << "Name" << "\t" << setw(6) << "Work" << "\t" << setw(6) << "PhoneId" << "\t" << setw(6) << "AllBook" << "\t" << setw(6) << "Now" << "\t" << endl;
	for (auto& TempReadr : Readers)
	{
		cout << TempReadr;
	}
}

bool LibraryManage::ReaderManage::SearchReaderByNameId()
{
	string Nameid;
	cout << "Input You Want Find NameId" << endl;
	cin >> Nameid;
	cin.get();
	for (auto& reade : Readers)
	{
		if (reade.NameId == Nameid)
		{
			cout << "\t\t" << setw(6) << "NameId" << "\t" << setw(6) << "Name" << "\t" << setw(6) << "WorkLocation" << "\t" << setw(6) << "PhoneId" << "\t" << setw(6) << "AllowBook" << "\t" << setw(6) << "NowBooks" << "\t" << endl;
			cout << reade;
			return true;
		}
	}
	return false;
}

bool LibraryManage::ReaderManage::LogNewReaderFromFile()
{
	ifstream ifs;
	ifs.open(LibraryCount_FILE, ios::in);
	if (!ifs.is_open())
	{
		cout << "Fail To Open File" << endl;
		return false;
	}
	string NameId;
	string password;
	int Id;
	while (ifs >> NameId, ifs >> password, ifs >> Id)
	{
		if (Id == 1 && !CheckIsHave(NameId))
		{
			Readers.push_back(Reader(UserBaser::Power::Orindary, NameId, password, "0", "0", 0, 0, 0));
		}
	}
	return true;
}

bool LibraryManage::ReaderManage::LogoldReaderFromFile()
{
	ifstream ifs;
	ifs.open(Reader_FILE, ios::in);
	if (!ifs.is_open())
	{
		cout << "Fail To Open Reader FILE OF LogoldReader" << endl;
		return false;
	}
	string NameID1; string password;
	string Name1;
	string workLocation1;
	int phoneId1;
	int AllowBrow1;
	int NowBorrow1;
	while (ifs >> NameID1, ifs >> password, ifs >> Name1, ifs >> workLocation1, ifs >> phoneId1, ifs >> AllowBrow1, ifs >> NowBorrow1)
	{


		Readers.push_back(Reader(UserBaser::Power::Orindary, NameID1, password, Name1, workLocation1, phoneId1, AllowBrow1, NowBorrow1));

	}
	return true;


}

bool LibraryManage::ReaderManage::WriteToFile()
{
	ofstream ofs;
	ofs.open(Reader_FILE, ios::out | ios::trunc);
	if (!ofs.is_open())
	{
		cout << "Fail To open File Of Reader FILe" << endl;
		return false;
	}
	for (auto& Reader : Readers)
	{
		ofs << Reader.NameId << " " << Reader.Password << " " << Reader.Name << " " << Reader.workLocation << " " << Reader.phoneId << " " << Reader.AllowBrrow << " " << Reader.NowBorrow << endl;
	}
	return true;
}

bool LibraryManage::ReaderManage::CheckIsHave(string NameId)
{
	for (auto& Reader : Readers)
	{
		if (Reader.NameId == NameId)
			return true;
	}
	return false;
}

//BookManager---------------------------------------------------------
int LibraryManage::BookManage::ShowMenu(UserBaser& User)
{
	int select;
	while (true)
	{
		cout << "\t\t -------------------------------\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t|          1.BookInfoInput      |\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t|          2.BookInfoChange     |\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t|          3.BookINfoQuery      |\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t|          4. BookSummary       |\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t|          5.Return Menu        |\n";
		cout << "\t\t|								 |\n";
		cout << "\t\t -------------------------------\n";
		cout << "输入您的选择: ";

		cin >> select;
		switch (select)
		{
		case 1:
			if (CheckWho(User, select))
			{
				system("cls");
				AddBooks();
			}
			else
			{
				cout << "You No Entry Possess" << endl;
				cout << "Please ReInput" << endl;
				system("Pause");
				system("cls");
			}
			break;
		case 2:
			if (CheckWho(User, select))
			{
				system("cls");
				SetBook();
			}
			else
			{
				cout << "You No Entry Possess" << endl;
				cout << "Please ReInput" << endl;
				system("pause");
				system("cls");
			}
			break;
		case 3:
			if (CheckWho(User, select))
			{
				system("cls");
				QueryBook();
			}
			else
			{
				cout << "You No Entry Possess" << endl;
				cout << "Please ReInput" << endl;
				system("pause");
				system("cls");
			}
			break;
		case 4:
			if (CheckWho(User, select))
			{
				system("cls");
				Summary();
			}
			else
			{
				cout << "You No Entry Possess" << endl;
				cout << "Please ReInput" << endl;
				system("pause");
				system("cls");
			}
			break;
		case 5:

			LOgBookToDoc();
			Books.clear();
			cout << "欢迎下次使用" << endl;
			system("pause");
			system("cls");
			return 0;
			break;
		default:
			cout << "Error Input ReInput" << endl;
			break;
		}
	}

}
bool LibraryManage::BookManage::CheckWho(UserBaser& User, int MenuId)
{
	if (User.State == UserBaser::Power::SystemManager)
	{
		if (MenuId == 3)
			return true;
		if (MenuId == 4)
			return true;
		else
			return false;
	}
	if (User.State == UserBaser::Power::Orindary)
	{
		if (MenuId == 3)
			return true;
		if (MenuId == 4)
			return true;
		else
			return false;
	}
	if (User.State == UserBaser::Power::BookManager)
	{
		return true;
	}
	else
	{
		return false;
	}
}




void LibraryManage::BookManage::AddBooks()
{
	int t;
	string BookName; string BookId; string Bookpublisher; int Inventory; string writer1;
	cout << "How many books you want add" << endl;
	cin >> t;
	cout << "Please Input BookName BookId BookWriter Publisher Inventory" << endl;
	while (t--)
	{
		cin >> BookName >> BookId >> writer1 >> Bookpublisher >> Inventory;
		cin.get();
		Books.push_back(Book(BookName, BookId, Bookpublisher, writer1, Inventory, 0));
	}
	cout << "successful" << endl;
}

void LibraryManage::BookManage::SetBook()
{
	string NameId;
	cout << "Please Book NameId";
	cin >> NameId;
	cin.get();
	int INvector1;
	int NowBorrow1;
	for (auto Book = Books.begin(); Book != Books.end(); Book++)
	{
		if ((*Book).BookId == NameId)
		{
			cout << "I Find It";
			cout << "Please INput New Inventory and NowBorrow" << endl;
			cin >> INvector1 >> NowBorrow1;
			cin.get();
			(*Book).Inventory = INvector1; (*Book).NowBorrow = NowBorrow1;
			return;
		}
	}
	cout << "I Can't Find It" << endl;

}

void LibraryManage::BookManage::QueryBook()
{
	while (true)
	{
		int select;
		cout << "\t\t -------------------------------\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t|			1.SearchByNameId     |\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t|          2.SearchByBookName   |\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t|          3.SearchByWriter     |\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t|          4.SearchByPublisher  |\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t|          5.Return Menu		 |\n";
		cout << "\t\t -------------------------------\n";
		cout << "输入您的选择: ";
		cin >> select;
		switch (select)
		{
		case 1:
			system("cls");
			SearchBookByNameId();
			break;

		case 2:
			system("cls");
			SearchBookByBookName();
			break;
		case 3:
			system("cls");
			SearchBookPublisher();
			break;
		case 4:
			system("cls");
			SearchBookByWriter();
			break;
		case 5:
			cout << "欢迎下次使用" << endl;
			system("pause");
			system("cls");
			return;
			break;
		default:
			cout << "Error Input ReInput" << endl;
			break;
		}
	}

}

void LibraryManage::BookManage::SearchBookByNameId()
{
	string BookId1;
	cout << "Please Input The Book NameID" << endl;
	cin >> BookId1;
	cin.get();
	for (auto& Book : Books)
	{
		if (Book.BookId == BookId1)
		{
			cout << Book;
			return;
		}
	}
	cout << "Sorry I Can't Find" << endl;
}

void LibraryManage::BookManage::SearchBookByBookName()
{
	string BookName;
	cout << "Please Input BookName" << endl;
	cin >> BookName;
	cin.get();
	int Flag = 0;
	for (auto& Book : Books)
	{
		if (Book.BookName == BookName)
		{
			cout << Book;
			Flag = 1;
		}
	}
	if (!Flag)
		cout << "I Can't Find" << endl;
}

void LibraryManage::BookManage::SearchBookByWriter()
{
	string BookWriter;
	cout << "Please Input BookWriter" << endl;
	cin >> BookWriter;
	cin.get();
	int flag = 0;
	for (auto& Book : Books)
	{
		if (Book.writer == BookWriter)
		{
			cout << Book;
			flag = 1;
		}
	}
	if (!flag)
		cout << "I can't find Book" << endl;
}

void LibraryManage::BookManage::SearchBookPublisher()
{
	string BookPublisher;
	cout << "Please Input BookPublisher" << endl;
	cin >> BookPublisher;
	cin.get();
	int flag = 0;
	for (auto& Book : Books)
	{
		if (Book.Bookpublisher == BookPublisher)
		{
			cout << Book;
			flag = 1;
		}
	}
	if (!flag)
		cout << "I can't find Book" << endl;
}

void LibraryManage::BookManage::Summary()
{
	cout << "\t\t" << setw(6) << "BookName" << setw(6) << "BookId" << "\t" << setw(3) << "BookPublisher" << "\t" << setw(3) << "BookWriter" << "\t" << setw(3) << "Inventory" << "\t" << setw(3) << "NowBorrow" << endl;
	for (auto& Book : Books)
	{
		cout << Book;
	}
}

void LibraryManage::BookManage::LOgBookToDoc()
{
	ofstream ofs;
	ofs.open(BookId_FILE, ios::out | ios::trunc);
	if (!ofs.is_open())
	{
		cout << "Fail to open FILE BOOK_FILE LogBookTODOC FUn" << endl;
		return;
	}
	for (auto& Book : Books)
	{
		ofs << Book.BookId << " " << Book.BookName << " " << Book.Bookpublisher << " " << Book.writer << " " << Book.Inventory << " " << Book.NowBorrow << endl;
	}
}

void LibraryManage::BookManage::LogBookFromFILE()
{
	string BookName; string writer; string BookId; string Bookpublisher; int Inventory; int NowBorrow;
	ifstream ifs;
	ifs.open(BookId_FILE, ios::in);
	if (!ifs.is_open())
	{
		cout << "Fail Open FILE In LogBookFromFILE" << endl;
		return;
	}
	while (ifs >> BookId, ifs >> BookName, ifs >> Bookpublisher, ifs >> writer, ifs >> Inventory, ifs >> NowBorrow)
	{
		Books.push_back(Book(BookName, BookId, Bookpublisher, writer, Inventory, NowBorrow));
	}
}




//BookPortManager------------------------------------------------------------
void LibraryManage::BookPortManage::ShowMenu(UserBaser& User)
{
	int select;
	while (true)
	{
		cout << "\t\t -------------------------------\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t|          1.BorrowBook         |\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t|          2.ReturnBook         |\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t|          3.Return Menu		 |\n";
		cout << "\t\t -------------------------------\n";
		cout << "输入您的选择: ";
		cin >> select;
		switch (select)
		{
		case 1:
			system("cls");
			BorrowBook(User);
			break;
		case 2:
			system("cls");
			ReturnBook(User);
			break;
		case 3:
			WriteToFile();
			LOgBookToDoc();
			LOgBookToDocB();
			cout << "欢迎下次使用" << endl;
			system("pause");
			system("cls");
			return;
			break;
		default:
			cout << "Error Input again";
			break;

		}

	}

}

void LibraryManage::BookPortManage::BorrowBook(UserBaser& User)
{
	string BookId;
	cout << "Please Input BookNameId" << endl;
	cin >> BookId;
	cin.get();
	int Year;
	int Month;
	int day;
	int flag = 0;
	for (auto& Reader : ReadesKCopy)
	{
		if (Reader.NameId == User.NameId)
		{
			if (Reader.AllowBrrow == 0)
				return;
			if (Reader.AllowBrrow == Reader.NowBorrow)
				return;
			for (Book& Book1 : Books)
			{

				if (Book1.BookId == BookId)
				{
					if (Book1.Inventory == 0)
					{
						cout << "This No Inventory" << endl;
						return;
					}
					if (Book1.NowBorrow == Book1.Inventory)
					{
						cout << "Book Is Borrowed Nothing" << endl;
						return;
					}
					else
					{
						flag = 1;
						Reader.NowBorrow += 1;
						Book1.NowBorrow += 1;
						cout << "please input Year Month Day" << endl;
						cin >> Year >> Month >> day; cin.get();
						Book1.SetBookTimeBorrow(Year, Month, day);
						cout << "Success" << endl;
						break;
					}
				}
			}
			if (!flag)
			{
				cout << "No the book" << endl;
			}
			break;
		}
	}
}

void LibraryManage::BookPortManage::ReturnBook(UserBaser& User)
{

	string BookId;
	cout << "Please Input BookNameId" << endl;
	cin >> BookId;
	cin.get();
	int Year;
	int Month;
	int day;
	int flag = 0;
	for (auto& Reader : ReadesKCopy)
	{
		if (Reader.NameId == User.NameId)
		{
			for (Book& Book1 : Books)
			{
				if (Book1.BookId == BookId)
				{
					flag = 1;
					Book1.NowBorrow -= 1;
					Reader.NowBorrow += 1;
					cout << "please Input Year Month Day" << endl;
					cin >> Year >> Month >> day;
					cin.get();
					Book1.SetBookTimeReturn(Year, Month, day);
					Book1.SetBookTimeBorrow(Book1.TimeBorrow.Year, Book1.TimeBorrow.Month, Book1.TimeBorrow.day);
					cout << "Successful" << endl;
					break;
				}
			}
			if (!flag)
				cout << "No the Book" << endl;

			break;
		}

	}

}

void LibraryManage::BookPortManage::LOgBookToDoc()
{
	ofstream ofs;
	ofs.open(BookId_FILE, ios::out | ios::trunc);
	if (!ofs.is_open())
	{
		cout << "Fail to open FILE BOOK_FILE LogBookTODOC FUn" << endl;
		return;
	}
	for (auto& Book : Books)
	{
		ofs << Book.BookId << " " << Book.BookName << " " << Book.Bookpublisher << " " << Book.writer << " " << Book.Inventory << " " << Book.NowBorrow << endl;
	}
}

void LibraryManage::BookPortManage::LogBookFromFILE()
{
	string BookName; string writer; string BookId; string Bookpublisher; int Inventory; int NowBorrow;
	ifstream ifs;
	ifs.open(BookId_FILE, ios::in);
	if (!ifs.is_open())
	{
		cout << "Fail Open FILE In LogBookFromFILE" << endl;
		return;
	}
	while (ifs >> BookId, ifs >> BookName, ifs >> Bookpublisher, ifs >> writer, ifs >> Inventory, ifs >> NowBorrow)
	{
		Books.push_back(Book(BookName, BookId, Bookpublisher, writer, Inventory, NowBorrow));
	}
}

void LibraryManage::BookPortManage::LOgBookToDocB()
{

	ofstream ofs;
	ofs.open(BookBorrow_FILE, ios::out | ios::trunc);
	if (!ofs.is_open())
	{
		cout << "Fail to open FILE BOOK_FILE LogBookTODOC FUn" << endl;
		return;
	}
	for (auto& Book : Books)
	{
		if (Book.NowBorrow != 0)
			ofs << Book.BookId << "借书日期" << Book.TimeBorrow << " 还书日期" << Book.TimeReturn;
	}
}

bool LibraryManage::BookPortManage::LogoldReaderFromFile()
{
	ifstream ifs;
	ifs.open(Reader_FILE, ios::in);
	if (!ifs.is_open())
	{
		cout << "Fail To Open Reader FILE OF LogoldReader" << endl;
		return false;
	}
	string NameID1; string password;
	string Name1;
	string workLocation1;
	int phoneId1;
	int AllowBrow1;
	int NowBorrow1;
	while (ifs >> NameID1, ifs >> password, ifs >> Name1, ifs >> workLocation1, ifs >> phoneId1, ifs >> AllowBrow1, ifs >> NowBorrow1)
	{

		ReadesKCopy.push_back(Reader(UserBaser::Power::Orindary, NameID1, password, Name1, workLocation1, phoneId1, AllowBrow1, NowBorrow1));

	}
	return true;


}

bool LibraryManage::BookPortManage::WriteToFile()
{
	ofstream ofs;
	ofs.open(Reader_FILE, ios::out | ios::trunc);
	if (!ofs.is_open())
	{
		cout << "Fail To open File Of Reader FILe" << endl;
		return false;
	}
	for (auto& Reader : ReadesKCopy)
	{
		ofs << Reader.NameId << " " << Reader.Password << " " << Reader.Name << " " << Reader.workLocation << " " << Reader.phoneId << " " << Reader.AllowBrrow << " " << Reader.NowBorrow << endl;
	}
	return true;
}















bool LogIn(const char* FileName,int Identity,string NameId,string Password)
{
	ifstream ifs;
	ifs.open(FileName, ios::in);
	if (!ifs.is_open())
	{
		cout << "Fail To open LogInFile" << endl;
		return false;
	}
	string NameID2; string Password2; int Identity2;

	while (ifs >> NameID2, ifs >> Password2, ifs >> Identity2)
	{
		if (NameId == NameID2 && Password == Password2 && Identity == Identity2)
		{
			return true;
		}
	}
	return false;
}





//Main

int main()
{
	LibraryManage Manage;
	int c = 0;
	int select = 0; //用于接受用户的选择
	while (true)
	{
		if (c>=3)
		{
			cout << "Error 3 Fail Login" << endl;
			break;
		}
		cout << "======================  图书馆  ====================="
			<< endl;
		cout << endl << "请输入您的身份" << endl;
		cout << "\t\t -------------------------------\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t|          1.Reader             |\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t|          2.BookManager        |\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t|          3.SystemManage       |\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t|          0.退    出           |\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t -------------------------------\n";
		cout << "输入您的选择: ";
		cin >> select; //接受用户选择
		string NameId; string Password;
		switch (select) //根据用户选择 实现不同接口
		{
		case 1: //Reader身份
			c++;
			cout << " Please Input NameId And Password" << endl;
			cin >> NameId >> Password;
			cin.get();
			if (LogIn(LibraryCount_FILE, 1,NameId,Password))
			{
				c = 0;
				UserBaser User = UserBaser(UserBaser::Power::Orindary, NameId, Password);
				system("cls");
				Manage.ShowMenu(User);
			}
			break;
		case 2: //BookManager身份
			c++;
			cout << " Please Input NameId And Password" << endl;
			cin >> NameId >> Password;
			cin.get();
			if (LogIn(LibraryCount_FILE, 2, NameId, Password))
			{
				c = 0;
				UserBaser User = UserBaser(UserBaser::Power::BookManager, NameId, Password);
				system("cls");
				Manage.ShowMenu(User);
			}
			break;
		case 3:  //SystemManager身份
			c++;
			cout << " Please Input NameId And Password" << endl;
			cin >> NameId >> Password;
			cin.get();
			if (LogIn(LibraryCount_FILE, 3, NameId, Password))
			{
				c = 0;
				UserBaser User = UserBaser(UserBaser::Power::SystemManager, NameId, Password);
				system("cls");
				Manage.ShowMenu(User);
			}
			break;
		case 0:  //退出系统
			cout << "欢迎下一次使用" << endl;
			system("pause");
			return 0;
			break;
		default:
			cout << "输入有误，请重新选择！" << endl;
			system("pause");
			system("cls");
			break;
		}
	}
	return 0;
}