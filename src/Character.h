#include <vector>
#include <iostream>
#include <string>
#include <map>
#include <memory>
#include "lib/jsonParser/json11.hpp"

typedef std::shared_ptr<Character> sp_character;

enum attackType
{
	blade = 0,
	projectile = 1,
	concussive = 2,
	psychic = 3,
	verbal = 4
};

struct Attribute
{
	/*
		determines the maximum health of a character.
		it should be possible during a battle that the
		characters maxHealth is under the health value 
		of the char. E.g. the char starts out with 30/30
		health and is attacked by a magicks which 
		reduces the attribute.maxHealth, but not the 
		stat.health var,
	*/

	//Attribute(const Attribute& a);
	Attribute()
	{
		static const std::vector<std::string> attributes =
		{"asd", "maxHealth", "maxMagicks", "meleeAttack", "magickAttack", 
		"meleeDodge", "psychicDodge", "armor", "psychicArmor", "agility", "maxEnergy"};

		maxHealth = 0;
		maxMagicks = 0;
		meleeAttack = 0;
		magickAttack = 0;
		meleeDodge = 0;
		psychicDodge = 0;
		armor = 0;
		psychicArmor = 0;
		agility = 0;
		maxEnergy = 0;
	}

	void print()
	{
		std::cout << std::endl
				  << maxHealth << ", "
				  << maxMagicks << ", "
				  << meleeAttack << ", "
				  << magickAttack << ", "
				  << meleeDodge << ", "
				  << psychicDodge << ", "
				  << armor << ", "
				  << psychicArmor << ", "
				  << agility;
	}

	int maxHealth{-1};
	int maxMagicks{-1};
	int maxEnergy{0};

	int meleeAttack{-1};
	int magickAttack{-1};

	int meleeDodge{-1};
	int psychicDodge{-1};

	int armor{-1};
	int psychicArmor{-1};

	int agility{-1};
};

struct Stat
{
	//should be evident what these vars are for.
	//the stats of a character are variable,
	//this means

	int health;
	int magicks;
	int energy; //moves cost energy which recouperates over rounds

	int psyche{360}; //value between 0 and 360, if reaches zero, things go bad.
};

class Character
{
  private:
	int id{0};

  public:
	Character();
	Character(int id);
	Character::Character(sp_character character);
	~Character();

	Stat stats;
	Attribute baseAttributes; //needs to be initialized in c'tor
	std::vector<Attribute> attributeHistory;

	std::vector<Attack> attackAbilities;

	void generateAttack(int t, sp_character victim);
	void absorbAttack(int atk[4]);

	/*
		A buff has an Attribute map
		*/
};

class Attack
{
  public:
	//damage caused place holders:

	enum atkAttr {
		concussive = 0,
		piercing = 1,
		cutting = 2,
		psychic = 3
	};

	int baseAttr[4];
	int primedAttr[4];

	sp_character agent;
	sp_character victim = nullptr;
	Attribute attributes;

	Attack(Attribute agentAttributes, sp_character agent);
	
	void execute(sp_character victim);

	void load(std::string fileName);

	void setTarget(sp_character chVictim);

	void prime();
};

	//this is Tuth and his sister Oriel


/*	
    class Character 
    {
    private:
        int id{0};

    public:
        Character(int id);
        ~Character();

        //stats:
        //int maxHealth;
        //int Health;
        //int maxMagicks;
        //int Magicks;
        std::map<std::string, int> stats;

        //attributes:
        //int attribute_meleeAttack;
        //int attribute_magickAttack;
        //int attribute_physicalDodge;
        //int attribute_psychicDodge;
        //int attribute_physicalArmor;
        //int attribute_psychicArmor;
        //int attribute_agility;
        std::map<std::string, int> attributes;

        //std::vector<Attack> //list of attacks, can be populated 

    };
*/

class Item 
{
  public:
	Item()
	{
		armor[Attack::atkAttr::concussive] = 0;
		armor[Attack::atkAttr::piercing] = 0;
		armor[Attack::atkAttr::cutting] = 0;
		armor[Attack::atkAttr::psychic] = 0;
	};

	~Item();

  private:
    int armor[4];
}