#include "Weapon.hpp"

void Weapon::setType(const std::string& newType){
	type = newType;
}
const std::string& Weapon::getType() const{
    return type;
}
Weapon::Weapon(const std::string& newType) {
	this->type = newType;
}