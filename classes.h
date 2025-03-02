#pragma once
#include <string>

class GameObject {
private:
	std::string name; //hello
	int mass;
	int position;
public:
	void Move(int distance);
	void Collide(GameObject& obj1, GameObject& obj2);
	std::string GetName() { return this->name; };
	GameObject();
	GameObject(std::string new_name);
	GameObject(std::string new_name, int new_mass);
	GameObject(std::string new_name, int new_mass, int new_position);
	GameObject(const GameObject& origin);
	~GameObject();

};

class Character {
private:
	static int deathsCount;
	std::string name;
	int hp;
	int speed;
	int position;
public:
	static int getDeathsCount() { return deathsCount; };
	std::string GetName() { return this->name; };
	void Move(int steps);
	void ChangeHp(int damage);
	Character();
	Character(std::string new_name);
	Character(std::string new_name, int  new_hp);
	Character(std::string new_name, int  new_hp, int new_speed);
	Character(std::string new_name, int  new_hp, int new_speed, int new_position);
	Character(const Character& origin);
	~Character();

};

class Weapon {
private:
	std::string name;
	int damage;
	double durability;
public:
	std::string GetName() { return this->name; };
	void Attack(Character& target);
	Weapon();
	Weapon(std::string new_name);
	Weapon(std::string new_name, int  new_damage);
	Weapon(std::string new_name, int  new_damage, double durability);
	Weapon(const Weapon& origin);
	~Weapon();
};

