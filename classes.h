#pragma once
#include <string>

class GameObject {
private:
	int mass;
	int position;
public:
	void Drag(int distance);
	void Collide(GameObject& obj1, GameObject& obj2);
	GameObject &operator=(const GameObject& rhs);
	bool operator==(const GameObject& rhs);;
	int GetPosition() { return this->position; }
	GameObject();
	GameObject(int new_mass);
	GameObject(int new_mass, int new_position);
	GameObject(const GameObject& origin);
	GameObject(GameObject&& origin) noexcept;
	~GameObject();



};

class Character : public GameObject {
private:
	static int deathsCount;
	std::string name;
	int hp;
	int speed;
public:
	static int getDeathsCount() { return deathsCount; };
	std::string GetName() { return this->name; };
	void Move(int steps);
	void ChangeHp(int damage);
	Character &operator=(const Character& rhs);
	Character();
	Character(std::string new_name);
	Character(std::string new_name, int  new_hp);
	Character(std::string new_name, int  new_hp, int new_speed);
	Character(std::string new_name, int new_hp, int new_speed, int new_mass);
	Character(std::string new_name, int new_hp, int new_speed, int new_mass, int new_position);
	Character(Character&& origin) noexcept;
	Character(const Character& origin);
	~Character() ;
	friend std::ostream& operator<<(std::ostream& output, const Character& chr);
	friend std::istream& operator>>(std::istream& input, Character& chr);

};

class Weapon : public GameObject {
private:
	std::string name;
	int damage;
	double durability;
public:
	int GetDamage() { return this->damage; };
	Weapon& operator--();
	std::string GetName() { return this->name; };
	void Attack(Character& target);
	Weapon();
	Weapon(std::string new_name);
	Weapon(std::string new_name, int  new_damage);
	Weapon(std::string new_name, int  new_damage, double durability);
	Weapon(std::string new_name, int new_damage, double new_durability, int new_mass);
	Weapon(std::string new_name, int new_damage, double new_durability, int new_mass, int new_position);
	Weapon(const Weapon& origin);
	~Weapon();
};

class RangedWeapon : public Weapon {
private:
	int range;
	int capacity;
public:
	void Shoot(Character& chr);
	void Reload(int ammo);
	RangedWeapon();
	RangedWeapon(std::string new_name);
	RangedWeapon(std::string new_name, int new_damage);
	RangedWeapon(std::string new_name, int new_damage, double new_durability);
	RangedWeapon(std::string new_name, int new_damage, double new_durability, int new_range, int new_capacity);
	~RangedWeapon();
};

