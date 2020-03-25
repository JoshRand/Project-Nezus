#pragma once
#include "../math/math.h"
#include <String.h>
#include <tuple>
#include <functional>

#include "../graphics/label.h"
#include "..\graphics\layers\tilelayer.h"
#include "..\graphics\sprite.h"
#include "..\graphics\layers\group.h"
#include "..\graphics\layers\layer.h"
#include "..\graphics\label.h"
#include "..\math\math.h"
#include "..\graphics\window.h"
#include "..\graphics\texture.h"
//#include "level.h"
namespace nezus 
{
class Entity 
{
public:
	Entity(std::string name,  int posx, int posy);
	Entity();
	int& getX() ;
	int& getY() ;
	std::string& GetName() ;
	void setX(int x);
	void setY(int y);
	float getSpeed();
	
	void setPositionChanged(bool ischanged);
	void PositionChange();
	bool checkPositionChange();
	std::string m_Name;
	float m_APositionX = 0.0f;
	float m_APositionY = 0.0f;
	
	int m_PositionX = 0;
	int m_PositionY = 0;
	bool isOccupied();
	void setOccupied();
	//math::vec3 m_Position;
	void moveGroup(graphics::Group* m_group, float dx, float dy);
	float m_PosPrevX = 0;
	float m_PosPrevY = 0;
private:
	bool m_Occupied = false;
	float m_Speed = 0.1f;
	std::tuple<int, const char*> skills = std::make_tuple(99, "hi");
	//std::tuple<int, int> tuples();
	bool m_PositionChange = false;
	

};


}
