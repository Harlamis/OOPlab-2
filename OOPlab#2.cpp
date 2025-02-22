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

void GameObject::Move(GameObject obj, int distance) {
	obj.position += distance;
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
void Character::ChangeHp(int damage, Character& character) {
	character.hp -= damage;
};
Character::Character()
	:name{ "None"}, hp{0}, speed{0} { }
Character::Character(std::string new_name)
	:name{ new_name }, hp{ 0 }, speed{ 0 } {
}
Character::Character(std::string new_name, int  new_hp)
	:name{ new_name }, hp{ new_hp }, speed{ 0 } {
}
Character::Character(std::string new_name, int  new_hp, int new_speed)
	:name{ new_name }, hp{ new_hp }, speed{ new_speed } {
}
Character::~Character() { std::cout << "Character deleted\n"; };
int main() {
	{
GameObject helldiver = GameObject::GameObject("John Helldiver", 1000);
	}
		return 0;
}