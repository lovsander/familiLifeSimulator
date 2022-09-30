// ConsoleApplication1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#include "ConsoleColor.h"
#include <iostream>

using namespace std;

class House
{
public:
	House() {
		this->report();
	}
	void checkHome(double dice) { 
		dirt += (10*dice+5); 
		if (dirt < 20 && dice > 0.8) {
			int leak = 50 * dice;
			dirt += leak;
			cout << red << "HOUSE dirt boom! " << leak << white << endl;
		}
		if (catFood > 50 && dice > 0.6) {
			int leak = catFood - (double)catFood * dice;
			catFood -=leak;
			cout << red << "HOUSE catFood leak! "<< leak << white << endl;
		}
		if (food > 100 && dice > 0.6) {
			int leak = food - (double)food * dice;
			food -= leak;
			cout << red << "HOUSE food leak! " << leak << white << endl;
		}
		if (money > 300 && dice > 0.7) {
			int leak = money - (double)money * dice;
			money -= leak;
			cout << red << "HOUSE money leak! " << leak << white << endl;
		}
	};
	void report() {
		cout << green << "HOUSE: dirt " << dirt << "  money: " << money << "  food: " << food << "  catFood: " << catFood << "  bonusPoints: " << bonusPoints << white << endl;
	};

	int dirt = 40;
	int money = 100;
	int food = 100;
	int catFood = 30;
	int overallMoney = 0;
	int bonusPoints = 0;
	//Cat* cats = nullptr;
};

class Cat
{
public:
	Cat(string name, House* house) {
		this->name = name;
		this->house = house;
		cout << this->house << "  ";
		this->report();
	};
	void report() {
		checkMe();
		cout << this->name << " health: " << this->health << endl;
	};
	void playPeople() {
		health -= 5;
		cout <<  this->name << " playPeople " ;
	};

	void act() {
		double dice = (double)rand() / RAND_MAX;
		if (health < 20) eat();
		else {
			cout << blue << this->name << " free chose " << white;
			if (dice > 0.7) {
				makeDirt();
			}
			else if (dice > 0.6) {
				sleeping();
			}
			else if (dice > 0.4) {
				goStreet();
			}
			else eat();
		}
	};
private:
	void checkMe() {
		if (health <= 0) {
			cout << red << this->name << " dead " << white << endl;
			system("pause");
			exit;
		}
		if (health > 100)	health = 100;
	};
	void makeDirt() {
		this->health -= 10;
		house->dirt += 5;
		cout << yellow << this->name << " makeDirt " << white << endl;
	};
	void sleeping() {
		cout << yellow << this->name << " sleeping " << white << endl;
	};
	void goStreet() {
		this->health -= 10;
		house->dirt += 2;
		cout << yellow << this->name << " goStreet " << white << endl;
	};
	void eat() {
			if (house->catFood >= 10) {
				this->health += 30;
				house->catFood -= 10;
				cout << yellow << this->name << " do eating " << white << endl;
			}
			else {
				this->health -= 10;
				cout << red << this->name << " hungry " << white << endl;
			}
	};


	string name = "cat";
	House* house = nullptr;
	int health = 30;
};
class Baby
{
public:
	Baby(string name, House* house) {
		this->name = name;
		this->house = house;
		cout << this->house << "  ";
		this->report();
	}
	void report() {
		checkMe();
		cout << name << " health: " << health << "  happy: " << happy << endl;
	};
	void act() {
		double dice = (double)rand() / RAND_MAX;
		if (health < 40) eat();
		else if (happy < 40) playToys();
		else if (health < happy) eat();
		else {
			cout << blue << this->name << " free chose " << white;
			if (dice > 0.95) {
				Illing();
			}
			else if (dice > 0.7) {
				Sleeping();
			}
			else if (dice > 0.5) {
				playCat();
			}
			else if (dice > 0.3) {
				playToys();
			}
			else eat();
		}
	};
protected:
	void Sleeping() {
		happy -= 5;
		health -= 5;
		cout << yellow << this->name << " sleeping " << white << endl;
	};
	void Illing() {
		happy -= 20;
		health -= 30;
		cout << red << this->name << " Illing " << white << endl;
	};
	void playCat() {
		health -= 5;
		happy += 5;
		//cat->playPeople();
		cout << yellow << this->name << " playCat " << white << endl;
	};
	void playToys() {
		health -= 5;
		happy += 30;
		house->money -= 20;
		cout << yellow << this->name << " play toys " << white << endl;
	};
	void eat() {
		if (house->food >= 20) {
			health += 20;
			happy -= 5;
			house->food -= 20;
			cout << yellow << this->name << " do eating " << white << endl;
		}
		else {
			health -= 10;
			cout << red << this->name << " hungry " << white << endl;
		}

	};
	void checkMe() {
		if (house->dirt > 90) {
			health -= 10;
			happy -= 5;
		}
		if (happy < 30) health -= 1;
		if (happy < 10) health = 0;
		if (health < 30) happy -= 1;
		if (health <= 0) {
			cout << red << this->name << " dead " << white << endl;
			system("pause");
			exit;
		}
		if (health > 300)	health = 300;
		if (happy > 300)	happy = 300;
	};
private:
	string name = "baby";
	House* house = nullptr;
	int happy = 100;
	int health = 30;
};


class Man
{
public:
	Man(string name, House *house) { 
		this->name = name;
		this->house = house;
		cout << this->house<<"  ";
		this->report();
	}
	void report() {
		checkMe();
		cout << this->name << " health: " << this->health << "  happy: " << this->happy << endl;
	};

protected:
	void checkMe() {
		if (house->dirt > 90) {
			health -= 10;
			happy -= 5;
		}
		if (happy < 100) health -= 1;
		if (happy < 10) health = 0;
		if (health < 100) happy -= 1;
		if (health <= 0) {
			cout << red << this->name << " dead " << white << endl;
			system("pause");
			exit;
		}
		if (health > 300) {
			firedHealth += health - 300;
			house->bonusPoints += 1;
			health = 300;
		}
		if (happy > 300) {
			firedHappy+= happy - 300;
			house->bonusPoints += 1;
			happy = 300;
		}
	};

	void playCat() {
		health -= 10;
		happy += 10;
		//cat->playPeople();
		cout << yellow << this->name << " playCat " << white << endl;
	};
	void cooking() {
		health -= 5;
		happy -= 5;
		if (house->money >= 120) {
			this->house->food += 120;
			this->house->money -= 120;
			cout << yellow << this->name << "  cooking " << white << endl;
		}
		else cout << red << this->name << " no money for cooking " << white << endl;
	};
	void buyCatFood() {
		health -= 10;
		happy -= 5;
		if (house->money >= 100) {
			this->house->catFood += 100;
			this->house->money -= 100;
			cout << yellow << this->name << " buyCatFood " << white << endl;
		}
		else cout << red << this->name << " no money for buyCatFood " << white << endl;
	};
	void eat() {
		if (house->food >= 30) {
			this->health += 30;
			house->food -= 30;
			cout << yellow<< this->name << " eating " <<white<< endl;
		}
		else {
			this->health -= 10;
			this->happy -= 10;
			cout << red << this->name << " hungry " << white << endl;
			cooking();
		}

	};


	string name = "noname";
	House *house = nullptr;
	int happy = 100;
	int health = 30;
public:
	int firedHappy = 0;
	int firedHealth = 0;
};


class Husband: public  Man
{
public:
	Husband(string name, House* house): Man(name, house) {
	};
	void act(double dice) {
		if (health < 30) eat();
		else if(house->money<150) working();
		else {
			cout << blue << this->name << " free chose " << white ;
			if (dice > 0.83) {
				if (house->catFood > 20)
					playCat();
				else
					buyCatFood();
			}
			else if (dice > 0.62) {
				working();
			}
			else {
				if (happy > health) eat(); else gaming();
			}
		}
	
	};

private:
	void working() { 
	house->money += 350; 
	house->overallMoney += 350;
	health -= 10;
	happy -= 10;
	cout << yellow << this->name << " working " << white << endl;
	};
	void gaming() { 
		health -= 10;
		if (house->money >= 20) {
			happy += 20;		
			house->money -= 20;
			cout << yellow << this->name << " gaming " << white << endl;
		} else cout << red << this->name << " no money for gaming " << white << endl;
	};
};

class Wife : public Man
{
public :
	Wife(string name, House* house) : Man(name, house) {
	};

	void act(double dice) {
		if (happy < 20) amusement();
		else if (health < 40) eat();
		else if (this->house->food < 60) cooking();
		else if (house->catFood < 20)buyCatFood();
		else if (this->house->dirt > 90) cleaning();
		else {
			cout << blue << this->name << " free chose " << white ;
			if (dice > 0.93) {
				if (house->catFood > 20)
					playCat();
				else
					buyCatFood();
			}
			else if (dice > 0.8 && this->house->dirt > 80) {
				cleaning();
			}
			else if (dice > 0.6) {
				cooking();
			}
			else {
				if (health < happy) eat(); else amusement();
			}
		}
	};

private:
	void cleaning() {
		health -= 10;
		happy -= 5;
		this->house->dirt -= 80;
		if (this->house->dirt < 0) this->house->dirt = 0;
		cout << yellow << this->name << " cleaning " << white << endl;
	};

	void amusement() {
		health -= 5;
		happy += 60;
		this->house->money -= 150;
		cout << yellow << this->name << " amusement " << white << endl;
	};

};

class A {
public:
	int a;
	void func() { ; }
	A() { cout << "A" << endl; }
	~A() { cout << "~A" << endl; }
};

class B :public A {
public:
	int b;
	B() { cout << "B" << endl; }
	~B(){ cout << "~B" << endl; }
};
class C :public virtual B {
public:
	int c;
};

int main()
{
	//A *a = new A();
	//B *b = new B();
	A *ab = new B();
	delete ab;

	C c;
	

	system("pause");
	return 0;

	House* home = new House();
	Cat* cats[] = { new Cat("Murzik", home), new Cat("Murka", home) };
	Husband* vasya = new Husband("Vasya",home);
	Wife* masha = new Wife("Masha", home);
	Baby* kids[] = { new Baby("Dima", home), new Baby("Anya", home) };
	double dice = 0;
	srand(time(NULL));
	for (int i = 0; i < 1000; i++)
	{
		cout << "day " << i <<"  ---------------------------------- dice " << dice << endl;
		dice = (double)rand() / RAND_MAX;
		home->checkHome(dice);
		home->report();

		vasya->act(dice);
		masha->act(dice);
		kids[0]->act();
		kids[1]->act();

		cats[0]->act();
		cats[1]->act();


		vasya->report();
		masha->report();
		kids[0]->report();
		kids[1]->report();
		cats[0]->report();
		cats[1]->report();


		cout << endl;
	}
	cout << "ov money " << home->overallMoney  << endl;
	cout << "wife firedHappy " << masha->firedHappy << endl;
	cout << "wife firedHealth " << masha->firedHealth << endl;
	cout << "husband firedHappy " << vasya->firedHappy << endl;
	cout << "husband firedHealth " << vasya->firedHealth << endl;
	system("pause");
	return 0;
}
