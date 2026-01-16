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

class Entryplus :public Entry
{
private:
	string streetNumber;
	string streetName;
	string city;
	string province;
	string postalCode;

public:
	void print();
	Entryplus(string s1, string s2, string s3, string s4, string s5, string s6, string s7) :Entry(s1, s2)
	{
		streetNumber = s3, streetName = s4, city = s5, province = s6, postalCode = s7;
	}
};

int main()
{
	Entryplus e("John", "784-4934", "3737", "Wascana Pkwy", "Regina", "SK","S4S 0A2");
	e.print();
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

void Entryplus::print()
{
	cout << "Person name: " << getName() << endl;
	cout << "Street number: " << streetNumber << endl;
	cout << "Street name: " << streetName << endl;
	cout << "City: " << city << endl;
	cout << "Province: " << province << endl;
	cout << "Postal code: " << postalCode << endl;
	cout << "Phone: " << getNumber() << endl;
}
