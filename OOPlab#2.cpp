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

Character::Character()
	: GameObject(), name("Unnamed"), hp(100), speed(1) {
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


int main() {
	GameObject* chr = new Character;
	GameObject* wpn = new Weapon;
	chr->Hello();
	wpn->Hello();
	Weapon* demo = new RangedWeapon;
	demo->StaticDemo();
	Weapon sword;
	RangedWeapon bow;
	DynamicDemoFunc(sword);
	DynamicDemoFunc(bow);
	delete chr;
	delete wpn;
	delete demo;
		return 0;
}