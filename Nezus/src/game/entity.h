#pragma once
#include "../math/math.h"
namespace nezus 
{
class Entity 
{
public:
	Entity(std::string name, math::vec2 position);
	Entity();
	float Getx();
	float Gety();
	void Setx(double x);
	void Sety(double y);
private:
	math::vec2 m_Position = math::vec2(0.0f,0.0f);
	std::string m_Name = "Entity";


};


}
