#pragma once
#include <string>

class GameObject {
private:
	std::string Name;
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


};
