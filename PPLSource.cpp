/*
Patrick Langley
Product Pick List with array
3/1/2021
*/
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <iomanip>
#include <vector>
#include <string>

using namespace std;

const int SIZE = 51;
struct Product_S
{
	int ID;
	char descr[SIZE];
	double price;
};

void Store_IDs(vector <int>& ids);

void Store_Products(Product_S prods[], int SZ, int& numPrds);

int main()
{
	vector <int> IDs;
	double* totalPrice_p = new double;
	double* avgPrice_p = new double;	
	int numMatches, numProds;
	
	const int SIZE = 100;
	Product_S prods[SIZE];  // array of Product_S structure variables

	cout << setprecision(2) << fixed;
	

	Store_Products(prods, SIZE, numProds);

	Store_IDs(IDs);

	*totalPrice_p = 0;
	numMatches = 0;
	Product_S prod;
	cout << "\nToday's pick list is:";
	bool found;
	int p = 0;
	while (p < numProds)
	{
		prod = prods[p];
		found = false;
		for (int i = 0; i < IDs.size(); i++)
		{
			if (IDs[i] == prod.ID)
			{
				found = true;
				numMatches++;
				cout << "\n\nProduct ID               " << prod.ID;
				cout << "\nProduct Name/Description " << prod.descr;
				cout << "\nProduct price           $" << prod.price;
				*totalPrice_p += prod.price;
			}
		}
		if (!found)
		{
			cout << "\n\nWarehouse product " << prod.ID << " not picked...notify customer service!\n";
		}
		p++;
	}
	if (numMatches > 0)
	{
		*avgPrice_p = *totalPrice_p / numMatches;
		cout << "\n\nThe picked preferred products' present price average is $" << *avgPrice_p;
	}
	else
	{

		cout << "\n\nNo products were picked, so there is no average price!";
	}

	delete totalPrice_p;
	delete avgPrice_p;

	cout << endl << endl;
	system("pause");
	return 0;
}
void Store_Products(Product_S prods[], int SZ, int &numPrds)
{
	
	Product_S prod;

	numPrds = 0;
	cout << "\nEnter the first Product ID>";
	cin >> prod.ID;
	while (prod.ID != 0 && numPrds < SZ)
	{
		cout << "\nEnter the Product description (50 characters or fewer)>";
		cin.ignore();
		cin.get(prod.descr, SIZE);
		cin.clear();   //If too many characters are entered, clear the resulting error state
		cin.ignore(numeric_limits<streamsize>::max(), '\n');   //Clear the input buffer up to & including \n
		
		cout << "\nEnter the price of the Product>";
		cin >> prod.price;
		
		prods[numPrds] = prod;

		numPrds++;

		cout << "\nEnter another Product ID or enter zero (0) to quit>";
		cin >> prod.ID;
	}	
}
void Store_IDs(vector <int>& ids)
{
	int id;

	cout << "\nEnter a Product ID to be picked>";
	cin >> id;
	while (id != 0)
	{
		ids.push_back(id);

		cout << "\nEnter another Product ID to be picked or enter zero (0) to quit>";
		cin >> id;
	}
}
