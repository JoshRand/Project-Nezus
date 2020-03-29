#pragma once
#include <vector>
#include <map>
#include <string>
#include "spell.h"
#include "..\graphics\texture.h"
namespace nezus
{
	namespace graphics
	{

		class SpellsDatabase 
		{
		private:
		public:
			std::vector<Spell> m_SpellList;
			std::map<std::string, int> m_Properties;
			SpellsDatabase();
			//~SpellsDatabase();
			
			void makeDatabase();
			Spell getSpell(int id);
		
		
		};
	}
		

	
}