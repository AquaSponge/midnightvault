#include <fstream>
#include <iostream>
#include <string>
#include "Character.h"

#define ROOT_DIR "/home/mio/Programming/Cpp/Midnight/data/Characters/"

using json11::Json;
using std::string;

//Character::Character(void) {};

///<summary>load base Character from file</summary>

//typedef std::shared_ptr<Character> sp_character;

Character::Character()
{
    baseAttributes.agility = 10;
    baseAttributes.magickAttack = 14; //can be psychic or physical
    baseAttributes.meleeAttack = 14;
    baseAttributes.armor = 23;
    baseAttributes.meleeDodge = 5;
    baseAttributes.psychicDodge = 4;
    baseAttributes.psychicArmor = 2;
};

Character::Character(sp_character character)
{
    baseAttributes = character->baseAttributes;
    stats = character->stats;

};

Character::Character(int init_id) : id(init_id)
{
    //init base attributes
    baseAttributes.agility = 10;
    baseAttributes.magickAttack = 14; //can be psychic or physical
    baseAttributes.meleeAttack = 14;
    baseAttributes.armor = 23;
    baseAttributes.meleeDodge = 5;
    baseAttributes.psychicDodge = 4;
    baseAttributes.psychicArmor = 2;

    std::cout << std::endl << id << " called Char constructor";
    //std::ifstream ifs;
    //ifs.open(ROOT_DIR + fileName);
    //std::string line;
    //while(std::getline(ifs, line))
    //{
        //do somethihng
    //}

}

Character::~Character()
{
    std::cout << std::endl << id << " explode!";
};


void Character::generateAttack(int t, sp_character victim)
{
    attackAbilities.at(t).execute(victim);
};

void Character::absorbAttack(int atk[4])
{
    // updates health stats depending on atk values.
    // later on I will impl. a variable "armor" value
    // which recouperates over time, such that
    // multiple successive attacks may reduce the AV
    // of a victim to the point where it affects health.
    int concussiveDmg = (baseAttributes.armor / 2) - atk[Attack::atkAttr::concussive];
    if (concussiveDmg > 0) stats.health = atk[Attack::atkAttr::concussive];
}

// === Damage ============================================================

























































/// === Attack ==========================================================

/*
	The main Battle loop is split up into two phases, one for each player.
	Momentarily
*/

void Attack::load(std::string fileName)
{
    //load from a json file: attributes, stats. both attributes and stats
	//classes should have their own parse(Json js); function.
    string err;
    const auto json = Json::parse(fileName, err);
    attributes.agility			= json["agility"		].int_value();
	attributes.armor			= json["armor"			].int_value();
    attributes.magickAttack		= json["magickAttack"	].int_value();
    attributes.maxEnergy		= json["maxEnergy"		].int_value();
    attributes.maxHealth		= json["maxHealth"		].int_value();
    attributes.maxMagicks		= json["maxMagicks"		].int_value();
    attributes.meleeAttack		= json["meleeAttack"	].int_value();
    attributes.meleeDodge		= json["meleeDodge"		].int_value();
    attributes.psychicArmor		= json["psychicArmor"	].int_value();
    attributes.psychicDodge		= json["psychi 	cDodge"	].int_value();
};

void Attack::setTarget(sp_character chVictim)
{
	victim = chVictim;
}

void Attack::prime()
{
    //takes character attributes, buffs and de-buffs and applies them 
    //to the character specific attack object.

	// +++ attributes
    primedAttr[atkAttr::concussive] = baseAttr[atkAttr::concussive];
    primedAttr[atkAttr::cutting]    = baseAttr[atkAttr::cutting];
    primedAttr[atkAttr::piercing]   = baseAttr[atkAttr::piercing];
    primedAttr[atkAttr::psychic]    = baseAttr[atkAttr::psychic];

	// +++ buffs [TODO]
	// +++ de-buffs [TODO]
}

void Attack::execute(sp_character victim)
{
	//the attack always needs to be primed, which technically makes the method
	//unnecessary.
	prime();
	//takes primed Attributes and applies them to victim;
    victim->absorbattack(primedAttr);

};


Attack::Attack(Attribute attribute, sp_character ch) : agent(ch)
{


}






























