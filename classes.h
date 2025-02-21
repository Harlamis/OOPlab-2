#pragma once
#include <string>

class GameObject {
private:
	std::string name;
	int mass;
	int position;
public:
	void Collide(GameObject& obj1, GameObject& obj2) {
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
	GameObject();
	GameObject(std::string);
	GameObject(std::string new_name, int new_mass);
	GameObject(std::string new_name, int new_mass, int new_position);
	~GameObject();

};
