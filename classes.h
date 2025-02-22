#pragma once
#include <string>

class GameObject {
private:
	std::string name;
	int mass;
	int position;
public:
	void Move(GameObject obj, int distance);
	void Collide(GameObject& obj1, GameObject& obj2);
	std::string GetName(GameObject& obj) { return obj.name; };
	GameObject();
	GameObject(std::string new_name);
	GameObject(std::string new_name, int new_mass);
	GameObject(std::string new_name, int new_mass, int new_position);
	~GameObject();

};

class Character {
private:
	std::string name;
	int hp;
	int speed;
	int position;
public:
	std::string GetName(Character character) { return character.name; };
	void Move(Character dude, int steps);
	void ChangeHp(int damage, Character &character);
	Character();
	Character(std::string new_name);
	Character(std::string new_name, int  new_hp);
	Character(std::string new_name, int  new_hp, int new_speed);
	Character(std::string new_name, int  new_hp, int new_speed, int new_position);
	~Character();

};

class Weapon {
private:
	std::string name;
	int damage;
	double durability;
public:
	std::string GetName(Weapon& weapon) { return weapon.name; };
	void Attack(Character& target, Weapon weapon);
	Weapon();
	Weapon(std::string new_name);
	Weapon(std::string new_name, int  new_damage);
	Weapon(std::string new_name, int  new_damage, double durability);
	~Weapon();
};

