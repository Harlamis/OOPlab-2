#pragma once
#include <string>

class GameObject {
private:
	std::string Name;
	int mass;
	int posX;
	int posY;
	int posZ;
public:
	void Collide(GameObject& obj1, GameObject& obj2) {
		if (obj1.posX == obj2.posX) {
			
		}
	};

};
