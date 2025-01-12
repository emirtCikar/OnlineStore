#pragma once
#include<iostream>
#include<string>
#include<vector>
using namespace std;
class product 
{
public:
				// parametrized constructor declaration
	product(string name,string language,string genre, string category, int stock, double price, string code )	
	{

		_name = name;
		_language = language;										
		_genre = genre;
		_category = category;
		_stock = stock;
		_price = price;
		_code = code;
	
	}
	product() 
	{
		
	}
	~product() 
	{
		
	}
	string name() const { return  _name; }
	string category() { return _category; }
	void setPrice(double price) { _price=price; }
	void setStock(int stock) { _stock = stock; }
	string language() const { return _language; }
	string genre() const { return _genre; }
	string code() const { return _code; }
	int stock() const { return _stock; }
	double price() const { return _price; }

	double calculateDiscount() // A func that calculates thhe discount, no discount in any choice that has not mentioned
	{
		if (_category == "book")
			return (_price * 0.88);
		else if (_category == "music")
			return (_price * 0.85);
		else if (_category == "movie")
			return (_price * 0.95);
		else
			return _price;
	}

	bool checkStock() // This checks whether there is stock or not
	{
		return _stock > 0;
	}
	virtual void display()	//a virtual display function for base class which is needed for function overriding
	{
		cout << "Name: " << _name << endl;
		cout << "Language: " << _language << endl;
		cout << "Genre: " << _genre << endl;
		cout << "Category: " << _category << endl;
		cout << "Stock: " << _stock << endl;
		cout << "Price: " << _price <<"$"<< endl;
		cout << "Code: " << _code << endl;
	}
private:
	string _name, _language, _genre, _code, _category;
	double _price;
	int  _stock;
};

