#include "classes.h"
#include<iostream>
using namespace std;
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
int main() {
GameObject helldiver = GameObject::GameObject("John Helldiver", 1000);
		return 0;
}