﻿#include "classes.h"
#include<iostream>
#include <vector>
#include <Windows.h>
using namespace std;

void GameObject::Collide(GameObject& obj1, GameObject& obj2) {
	if (obj1.mass < obj2.mass) {
		obj1.position -= (obj2.mass - obj1.mass);
	}
	else if (obj1.mass > obj2.mass) {
		obj2.position -= (obj2.mass - obj1.mass);
	}
	else if (obj1.mass == obj2.mass) {
		obj1.position--;
		obj2.position--;
	}
};

void GameObject::Move(int distance) {
	this->position += distance;
};

GameObject::GameObject()
	: mass{ 0 }, position{ 0 }{ }
GameObject::GameObject(int new_mass)
	: mass{ new_mass }, position{ 0 } {}
GameObject::GameObject(int new_mass, int new_position)
	: mass{ new_mass }, position{ new_position } {}
GameObject::~GameObject() {
	std::cout << "Object deleted\n";
}

GameObject::GameObject(GameObject&& origin) noexcept :  mass{ origin.mass }, position{ origin.position } {
	origin.mass = 0;
	origin.position = 0;
};

GameObject::GameObject(const GameObject& origin) : mass{ origin.mass }, position{ origin.position } {
	std::cout << "Copied\n";
}

GameObject& GameObject::operator=(const GameObject& rhs) {
	if (this != &rhs) {
		mass = rhs.mass;
		position = rhs.position;
	}
	return *this;
};

bool GameObject::operator==(const GameObject& rhs) {
	if ((this->mass == rhs.mass) && (this->position == rhs.position)) {
		return true;
	}
	return false;
}


void Character::ChangeHp(int damage) {
	this->hp -= damage;
};

Character& Character::operator=(const Character& rhs) {
	if (this != &rhs) {
		GameObject::operator=(rhs);
		name = rhs.name;
		hp = rhs.hp;
		speed = rhs.speed;
	}
	return *this;
};

void Character::TakeDamage(int amount) {
	this->hp -= amount;
}

Character::Character()
	: GameObject(), name("Unnamed"), hp(100), speed(1) {

	Character::characters.push_back(this);
}

Character::Character(std::string new_name)
	: GameObject(), name{std::move(new_name)}, hp{100}, speed{1} {
}

Character::Character(std::string new_name, int new_hp)
	: GameObject(), name{new_name }, hp{new_hp}, speed{1} {
}

Character::Character(std::string new_name, int new_hp, int new_speed)
	: GameObject(), name{new_name }, hp{new_hp}, speed{new_speed} {
}

Character::Character(std::string new_name, int new_hp, int new_speed, int new_mass)
	: GameObject(new_mass), name{new_name}, hp(new_hp), speed{new_speed} {
}

Character::Character(std::string new_name, int new_hp, int new_speed, int new_mass, int new_position)
	: GameObject(new_mass, new_position), name{new_name }, hp{ new_hp }, speed{ new_speed } {
}

Character::Character(const Character& origin)
	: GameObject(origin), name{ origin.name }, hp{ origin.hp }, speed{ origin.speed } {
}

int Character::deathsCount = 0;

Character::Character(Character&& origin) noexcept
	: GameObject(std::move(origin)), name(std::move(origin.name)), hp(origin.hp), speed(origin.speed) {
	origin.hp = 0;
	origin.speed = 0;
}

Character::~Character() { 
	std::cout << "Character deleted\n"; 
	deathsCount++;
};

void Character::Move(int steps) {
	for (int i = 0; i < steps; i++) {
		int currentPos = this->GetPosition();
		currentPos += this->speed;
		this->SetPosition(currentPos);
	};
}

 std::ostream& operator<<(std::ostream& output, const Character& chr) {
	output << "Character: " << chr.name << ", HP: " << chr.hp << ", Speed: " << chr.speed << ", Position: \n ";
	return output;
};

 std::istream& operator>>(std::istream& input, Character& chr) {
	 std::cout << "Enter name: ";
	 input >> chr.name;
	 std::cout << "Enter HP: ";
	 input >> chr.hp;
	 std::cout << "Enter speed: ";
	 input >> chr.speed;
	 std::cout << "Enter position: ";
	 return input;
 };

 Weapon::Weapon()
	 : GameObject(), name{ "Unknown" }, damage{ 0 }, durability{ 100.0 } {
 }

 Weapon::Weapon(std::string new_name)
	 : GameObject(), name{ std::move(new_name) }, damage{ 0 }, durability{ 100.0 } {
 }

 Weapon::Weapon(std::string new_name, int new_damage)
	 : GameObject(), name{ std::move(new_name) }, damage{ new_damage }, durability{ 100.0 } {
 }

 Weapon::Weapon(std::string new_name, int new_damage, double new_durability)
	 : GameObject(), name{ std::move(new_name) }, damage{ new_damage }, durability{ new_durability } {
 }

 Weapon::Weapon(std::string new_name, int new_damage, double new_durability, int new_mass)
	 : GameObject(new_mass), name{ std::move(new_name) }, damage{ new_damage }, durability{ new_durability } {
 }

 Weapon::Weapon(std::string new_name, int new_damage, double new_durability, int new_mass, int new_position)
	 : GameObject(new_mass, new_position), name{ std::move(new_name) }, damage{ new_damage }, durability{ new_durability } {
 }

 Weapon::Weapon(const Weapon& origin)
	 : GameObject(origin), name{ origin.name }, damage{ origin.damage }, durability{ origin.durability } {
 }

 void Weapon::TakeDamage(int amount) {
	 this->durability -= amount;
 };
Weapon::~Weapon() { std::cout << "weapon deleted\n"; }

void DynamicDemoFunc(Weapon& wpn) {
	wpn.DynamicDemo();
};



 void RangedWeapon::Shoot(Character& chr) {
	 if (this->capacity == 0) {
		 return;
	 }
	 int currentTargetPos = chr.GetPosition();
	 int currentShooterPos = this->GetPosition();
	 if (this->range > (currentTargetPos - currentShooterPos)) {
		 this->Attack(chr);
	 }
}

 void RangedWeapon::Reload(int ammo) {
	 this->capacity = ammo;
 }

 RangedWeapon::RangedWeapon()
	 : Weapon(), range{ 0 }, capacity{ 0 } {
 }

 RangedWeapon::RangedWeapon(std::string new_name)
	 : Weapon(new_name), range{ 0 }, capacity{ 0 } {
 }

 RangedWeapon::RangedWeapon(std::string new_name, int new_damage)
	 : Weapon(new_name, new_damage), range{ 0 }, capacity{ 0 } {
 }

 RangedWeapon::RangedWeapon(std::string new_name, int new_damage, double new_durability)
	 : Weapon(new_name, new_damage, new_durability), range{ 0 }, capacity{ 0 } {
 }

 RangedWeapon::RangedWeapon(std::string new_name, int new_damage, double new_durability, int new_range, int new_capacity)
	 : Weapon(new_name, new_damage, new_durability), range{ new_range }, capacity{ new_capacity } {
 }

 RangedWeapon::~RangedWeapon() {
 }


Weapon& Weapon::operator--() {
	if (durability > 0) {
		--durability;
	}
	return *this;
};

 void Weapon::Attack(Character& target) {
	 this->durability -= double((this->damage) / 20);
	 target.ChangeHp(this->damage);

}

 //begininng of lab6 code//
 std::vector<Character*> Character::characters = {};
 int appMode{0};
 std::string adminPass { "Harlam315" };
 bool adminAuth() {
	 int i = 3;
	 std::string input;
	 while (i != 0) {
		 std::cout << "Please, enter your admin password " << i << " attempts left\n";
		 std::cin >> input;
		 if (input == adminPass) {
			 return true;
		 }
		 input.clear();
		 i--;
	 }
	 std::cout << "You entered the wrong password!\n";
	 return false;
 }
 void authScreen() {
		 std::cout << "Welcome, please, choose the app mode:\n User mode: allows to interact with existing characters\n Admin mode (REQUIRES PASSWORD): allows to edit/create characters, weapons\n press 1 to enter user mode, press 2 to enter admin mode\n";
		 try {
			 std::cin >> appMode;
			 if (std::cin.fail()) {
				 throw std::invalid_argument("ERROR: you typed wrong value: try typing 1 or 2\n");
			 }
			 if (appMode != 1 && appMode != 2) {
				 throw std::out_of_range("ERROR: you typed a wrong value: try typing 1 or 2\n");
			 }

			 if (appMode == 1) {
				 std::cout << "Entering program in user mode...\n";
				 Sleep(2500);
				 system("cls");
				 // next screen function call (TBD)
			 }

			 if (appMode == 2) {
				 if (adminAuth()) {
				 std::cout << "Entering program in admin mode\n";
				 Sleep(2500);
				 system("cls");
				 //next screen function call (TBD)
				 }
				 else {
					 authScreen();
				 }
			 }
		 }
		 catch (std::invalid_argument& ex) {
			 std::cout << ex.what() << "\n";
			 std::cin.clear();
			 std::cin.ignore(100, '\n');
			 authScreen();
		 }
		 catch (std::out_of_range& ex) {
			 std::cout << ex.what() << "\n";
			 authScreen();
		 }
 };

 
 void mainScreen() {
	 if (appMode == 2) {
		 int choice { 0 };
		 try {
		 std::cout << "Please, choose your next action:\n" << "1) show current existing characters " << "2) show existing weapons\n"; << "3) create a new character " << "4) create a new weapon"
		 std::cin >> choice;
		 if (std::cin.fail()) {
			 throw std::invalid_argument("ERROR: you typed wrong value: try typing 1-4\n");
		 }
		 if (choice != 1 && choice != 2 && choice != 3 && choice != 4) {
			 throw std::out_of_range("ERROR: this command does not exist: try typing 1-4\n");
		 }
		 if (choice == 1) {
			 std::cout << "Displaying existing characters...\n";
				 // TODO display function call 
		 }
		 }
	 }
	 else {

	 }
 }



int main() {
	authScreen();
		return 0;
}