#include "classes.h"
#include<iostream>
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

void GameObject::Move( int distance) {
	this->position += distance;
}

GameObject::GameObject()
	:name{ "None" }, mass{ 0 }, position{ 0 }{ }
GameObject::GameObject(std::string new_name)
	:name{ new_name }, mass{ 0 }, position{ 0 } {}
GameObject::GameObject(std::string new_name, int new_mass)
	:name{ new_name }, mass{ new_mass }, position{ 0 } {}
GameObject::GameObject(std::string new_name, int new_mass, int new_position)
	:name{ new_name }, mass{ new_mass }, position{ new_position } {}
GameObject::~GameObject() {
	std::cout << "Object deleted\n";
}

GameObject::GameObject(GameObject&& origin) noexcept :name{ std::move(origin.name) }, mass{ origin.mass }, position{ origin.position } {
	origin.mass = 0;
	origin.position = 0;
};

GameObject::GameObject(const GameObject& origin) :name{ origin.name }, mass{ origin.mass }, position{ origin.position } {
	std::cout << "Copied\n";
}

bool GameObject::operator==(const GameObject& rhs) {
	if ((this->name == rhs.name) && (this->mass == rhs.mass) && (this->position == rhs.position)) {
		return true;
	}
	return false;
}


void Character::ChangeHp(int damage) {
	this->hp -= damage;
};
Character::Character()
	:name{ "None" }, hp{ 0 }, speed{ 0 }, position{0} {
}
Character::Character(std::string new_name)
	:name{ new_name }, hp{ 0 }, speed{ 0 }, position{ 0 } {
}
Character::Character(std::string new_name, int  new_hp)
	:name{ new_name }, hp{ new_hp }, speed{ 0 }, position{ 0 } {
}
Character::Character(std::string new_name, int  new_hp, int new_speed)
	:name{ new_name }, hp{ new_hp }, speed{ new_speed }, position{ 0 } {
}
Character::Character(std::string new_name, int  new_hp, int new_speed, int new_position)
	:name{ new_name }, hp{ new_hp }, speed{ new_speed }, position{new_position} {
}
Character::~Character() { std::cout << "Character deleted\n"; };

int Character::deathsCount = 0;

Character::Character(const Character& origin) :name{ origin.name }, hp{ origin.hp }, speed{ origin.speed }, position{ origin.position } {
	std::cout << "\nCopied\n";
	deathsCount++;
}

void Character::Move(int steps) {
	for (int i = 0; i < steps; i++) {
		this->position += this->speed;
	};
}

 std::ostream& operator<<(std::ostream& output, const Character& chr) {
	output << "Character: " << chr.name << ", HP: " << chr.hp << ", Speed: " << chr.speed << ", Position: " << chr.position;
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
	 input >> chr.position;
	 return input;
 };

Weapon::Weapon()
	:name{ "None"}, damage{0}, durability{0} {
}
Weapon::Weapon(std::string new_name)
	:name{ new_name }, damage{ 0 }, durability{ 0 } {
}
Weapon::Weapon(std::string new_name, int new_damage)
	:name{ new_name }, damage{ new_damage }, durability{ 0 } {
}
Weapon::Weapon(std::string new_name, int new_damage, double new_durability)
	:name{new_name}, damage{new_damage},durability{new_durability} { }

Weapon::~Weapon() { std::cout << "weapon deleted\n"; }

Weapon::Weapon(const Weapon& origin) :name{ origin.name }, damage{ origin.damage }, durability{ origin.durability }{
	std::cout << "\n Copied\n";
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


int main() {
	

GameObject helldiver = GameObject::GameObject("John Helldiver", 1000);
GameObject newHelldiver = GameObject::GameObject(helldiver);
std::cout << "\nPause\n";

		GameObject rock = GameObject("stone");
		std::cout << rock.GetName();
		Character guy = Character("John", 35, 30, 10);
		guy.Move(3);
		Weapon sword = Weapon("Sword", 15);
		sword.Attack(guy);
		std::cout << "\nnumber of deaths: " << Character::getDeathsCount() << endl;
		return 0;
}