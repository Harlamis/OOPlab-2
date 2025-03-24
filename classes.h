#pragma once
#include <iostream>
#include <string>

class Damagable {
public:
	virtual void TakeDamage(int amount) = 0;
	virtual ~Damagable() {};
};

class GameObject  {
private:
	int mass;
	int position;
public:
	virtual void SayMyName() = 0;
	virtual void Move(int distance);
	void Collide(GameObject& obj1, GameObject& obj2);
	virtual void Hello() { std::cout << "Hello from GameObject!\n"; }
	GameObject &operator=(const GameObject& rhs);
	bool operator==(const GameObject& rhs);;
	int GetPosition() { return this->position; }
	void SetPosition(int pos) { this->position = pos; }
	GameObject();
	GameObject(int new_mass);
	GameObject(int new_mass, int new_position);
	GameObject(const GameObject& origin);
	GameObject(GameObject&& origin) noexcept;
	virtual ~GameObject();



};

class Character : public GameObject,  public Damagable {
private:
	static int deathsCount;
	std::string name;
	int hp;
	int speed;
public:
	virtual void TakeDamage( int amount) override;
	virtual void SayMyName() override { std::cout << "I am a Character!\n"; };
	static int getDeathsCount() { return deathsCount; };
	std::string GetName() { return this->name; };
	virtual void Move(int steps) override;
	virtual void Hello() override { std::cout << "Hello from Character!\n"; };
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
 	virtual ~Character() ;
	friend std::ostream& operator<<(std::ostream& output, const Character& chr);
	friend std::istream& operator>>(std::istream& input, Character& chr);

};

class Weapon : public GameObject, public Damagable {
private:
	std::string name;
	int damage;
	double durability;
public:
	virtual void TakeDamage(int amount) override;
	virtual void SayMyName() override { std::cout << "I am a Weapon!\n"; };
	int GetDamage() { return this->damage; };
	Weapon& operator--();
	std::string GetName() { return this->name; };
	void Attack(Character& target);
	void StaticDemo() { std::cout << "This is Weapon demo!\n"; };
	virtual void DynamicDemo() { std::cout << "This is dynamic weapon demo!\n"; };
	virtual void Hello() override { std::cout << "Hello from Weapon!\n"; };
	Weapon();
	Weapon(std::string new_name);
	Weapon(std::string new_name, int  new_damage);
	Weapon(std::string new_name, int  new_damage, double durability);
	Weapon(std::string new_name, int new_damage, double new_durability, int new_mass);
	Weapon(std::string new_name, int new_damage, double new_durability, int new_mass, int new_position);
	Weapon(const Weapon& origin);
	virtual ~Weapon();
};

class RangedWeapon : public Weapon {
private:
	int range;
	int capacity;
public:
	virtual void SayMyName() override { std::cout << "I am a Ranged Weapon!\n"; };
	void Shoot(Character& chr);
	void Reload(int ammo);
	void StaticDemo() { std::cout << "This is RangedWeapon demo!\n"; };
	virtual void DynamicDemo() override { std::cout << "This is dynamic ranged weapon demo!\n"; };
	RangedWeapon();
	RangedWeapon(std::string new_name);
	RangedWeapon(std::string new_name, int new_damage);
	RangedWeapon(std::string new_name, int new_damage, double new_durability);
	RangedWeapon(std::string new_name, int new_damage, double new_durability, int new_range, int new_capacity);
	virtual ~RangedWeapon();
};

