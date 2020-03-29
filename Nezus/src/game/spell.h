#pragma once
#include "..\graphics\texture.h"
#include <map>
namespace nezus
{
	namespace graphics
	{
		class Spell
		{
		private:
			

		public:
			int m_Id = 0;
			std::string m_SpellName = "default SN";
			Texture m_SpellTexture = Texture("default.png");
			std::map<std::string, int> m_Properties;
			
			//int m_DamageDone = 0;
			//int m_HealingDone = 0;
			//int m_ManaCost = 0;
			//int m_ManaGiven = 0;
			//int m_Aethers = 0;
			//int m_StunTime = 0;
			Spell(int id)
			{
				m_Id = id;
			}
				
			Spell(int id, std::string name, Texture graphic, std::map<std::string, int> properties)
				:m_Id(id),m_SpellName(name),m_SpellTexture(graphic), m_Properties(properties)
			{}
		};


	}

}