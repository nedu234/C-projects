#include <iostream>
using namespace std;

class Entry
{
	string name;
	string number;

public:
	Entry();
	Entry(string s1, string s2);
	Entry(string s1);
	void setEntry(string s1, string s2);
	void setEntry(string s1);
	string getName();
	string getNumber();
	bool operator == (const Entry& e);
	bool operator != (const Entry& e);

};

int main()
{
	Entry e1, e2("John"), e3("Chris", ""), e4("chris");
	if (e3 == e4)
		cout << "e3 == e4" << endl;
	else
		cout << "NOT e3 == e4" << endl;

	if (e1 != e2)
		cout << "e1 != e2" << endl;
	else
		cout << "NOT e1 != e2" << endl;

	e1.setEntry("Chris");
	cout << e1.getName() << endl;

	return 0;
}

Entry::Entry()
{
	name = "";
}

Entry::Entry(string s1, string s2)
{
	name = s1;
	number = s2;
}

Entry::Entry(string s1)
{
	name = s1;
	number = "";
}

void Entry::setEntry(string s1, string s2)
{
	name = s1;
	number = s2;
}

void Entry::setEntry(string s1)
{
	name = s1;
	number = "306-999-9999";
}

string Entry::getName()
{
	return name;
}

string Entry::getNumber()
{
	return number;
}

bool Entry::operator== (const Entry& e)
{
	if (name == e.name)
		return true;
	else
		return false;
}

bool Entry::operator!= (const Entry& e)
{
	if (name != e.name)
		return true;
	else
		return false;
}
