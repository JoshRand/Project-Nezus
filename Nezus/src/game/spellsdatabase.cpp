#include "spellsdatabase.h"
namespace nezus
{
	namespace graphics
	{
		SpellsDatabase::SpellsDatabase()
		{
			makeDatabase();
		}

		void SpellsDatabase::makeDatabase()
		{
			
			m_Properties["m_HpGiven"] = 50;
			m_SpellList.push_back(Spell(0, "Soothe", Texture("soothe.png"),m_Properties));
					
					
			
		}

		Spell SpellsDatabase::getSpell(int id)
		{
			for (int i = 0; i != m_SpellList.size(); i++)
			{
				if (m_SpellList[i].m_Id == id)
					return m_SpellList[i];
			}
		}
	}
}