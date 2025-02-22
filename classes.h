#pragma once
#include <string>

class GameObject {
private:
	std::string name;
	int mass;
	int position;
public:
	void Collide(GameObject& obj1, GameObject& obj2);
	std::string GetName(GameObject& obj) { return obj.name; };
	GameObject();
	GameObject(std::string);
	GameObject(std::string new_name, int new_mass);
	GameObject(std::string new_name, int new_mass, int new_position);
	~GameObject();

};

