#include<iostream>
using namespace std;

class Shoes
{
public:
	virtual void Print() = 0;
};

class Sneakers : public Shoes
{
public:
	void Print()
	{
		cout << "Sneakers\n";
	}
};

class Slippers : public Shoes
{
public:
	void Print()
	{
		cout << "Slippers\n";
	}
};

class Boots : public Shoes
{
public:
	void Print()
	{
		cout << "Boots\n";
	}
};

class Factory {
public:
	virtual Shoes* createSneakers() = 0;
	virtual Shoes* createSlippers() = 0;
	virtual Shoes* createBoots() = 0;
};

class FactoryOfChineseFakes : public Factory
{
	Shoes* createSneakers()
	{
		return new Sneakers;
	}
	Shoes* createSlippers()
	{
		return new Slippers;
	}
	Shoes* createBoots()
	{
		return new Boots;
	}
};

class TheOriginalFactory : public Factory
{
	Shoes* createSneakers()
	{
		return new Sneakers;
	}
	Shoes* createSlippers()
	{
		return new Slippers;
	}
	Shoes* createBoots()
	{
		return new Boots;
	}
};

int main()
{
	Factory* factory1 = new TheOriginalFactory;
	Factory* factory2 = new FactoryOfChineseFakes;

	Shoes* shoes[6];

	shoes[0] = factory1->createSneakers();
	shoes[1] = factory2->createSneakers();
	shoes[2] = factory1->createBoots();
	shoes[3] = factory2->createBoots();
	shoes[4] = factory1->createSlippers();
	shoes[5] = factory2->createSlippers();

	for (int i = 0; i < 6; i++)
	{
		shoes[i]->Print();
	}
}