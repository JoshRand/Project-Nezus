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
	bool PositionChange();
	std::string m_Name;
	int m_PositionX = 0;
	int m_PositionY = 0;
	bool isOccupied();
	void setOccupied();
	//math::vec3 m_Position;
	void moveGroup(graphics::Group* m_group, int dx, int dy);
private:
	bool m_Occupied = false;
	float m_Speed = 0.1f;
	std::tuple<int, const char*> skills = std::make_tuple(99, "hi");
	float m_PosPrevX = 0;
	float m_PosPrevY = 0;
	//std::tuple<int, int> tuples();
	bool m_PositionChange = false;
	

};


}
