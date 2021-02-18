#pragma once
//========================================
// enemy.hpp
//========================================
#include "com.hpp"

#include "enemy_k.hpp"
#include "enemy_s.hpp"
#include "enemy_d.hpp"

//----------------------------------------
// ENEMY
//----------------------------------------
//----------------------------------------
// AI states
//----------------------------------------
enum class ENEMY_AI{
	RANDOM,
	GOTOWARDS,
	STAYBACK,
	RUN,
	GUARD,
	FRIENDLYMOVE,
	FRIENDLYNOMOVE,
};

struct ENEMY {
	ENEMY( ENEMY_KIND k ) : kind{k}{}
	~ENEMY() = default;

	const ENEMY_KIND	kind;
	std::string			name;

	struct {
		int			facing = 0;
		int			subsquare = 0;
	};

	struct {
		int			power;
		int			speed;       	// affects chance of missing/dodging
		int			manapower;   	// intelligence & wisdom merged into 1 attribute
	};

	struct {
		int			defense;    	// % of weapon damage resisted
		int			magicresist;	// % of magic damage resisted
		int			fearresist = 5; // int affecting success rate of horn of fear (0-never works to 10-always works)
		int			parry = -1;
	};

	struct {
		int			movespeed;   	// rate of movement
		int			attackspeed; 	// rate of attack (kind of...) must be < movespeed
	};

	struct {
		int			mana;
		int			maxmana = 0;
	};
	struct {
		int			health;
		int			maxhealth;
	};

	struct {
		ENEMY_AI	currentai = ENEMY_AI::RANDOM;
		ENEMY_AI	defaultai = ENEMY_AI::GOTOWARDS;
		ENEMY_AI	newai;
		int 		moveattack = 0;	//used in ai routine to prevent double ai update when moving & attacking at once
		bool		wasfrightened = false; //switches mon's ai to run
	};

	struct {
		int			power;
		int			defense;
		int			magicresist;
		int			speed;
		int			manapower;
		int			movespeed;
		int			attackspeed;
	}	boost;

	struct {
		bool		hasmagic	= false;
		bool		hasheal		= false; // does mon have heal magic?
		bool		hasdrain	= false; // does mon have drain life magic?
	};

	bool 		silenced = false;
	int			silencecount = 0;

	struct {
		int			castpower;			// max power level of cast spells (can be 1-6), or shotpower for item projs
		int			minproj = 0;		// min mana needed to cast offensive magic

		int numspells;
	};
	std::map<std::string,int> knownspells;

	int poison = 0; // strength of poison

	struct {
		bool	isImmaterial = false; //not ghost
		bool	isflying = false; //if true, can fly over pits
	};

	struct {
		bool	ignoremons = true;	// will this mon shoot other mons if they are in the way?
		bool	canusestairs = true; //true if this mon can go up/down stairs (dragons too big, screamers cant climb, etc.)
		bool	canteleport = false; //true if mon can teleport like a sorcerer/vexirk
	};

	int timecounter = 0;
	int movecounter = 0;
	int deathcounter = 0;
	int randomcounter = 0; //for trying to get around obstacle
	int runcounter = 0; //for hit&run ai, including gigglers
	int x,y,xdist=0,ydist=0,level;
	bool isattacking = false; //used in drawMonster
	bool iscasting = false;   //"
	bool isdying = false;     //"
	bool mirrored = false;
	bool hurt = false; //used in ai routine
	bool wasstuck; //used in ai routine for stayback - gotowards swaps
	int hurttest = 0; //used in ai routine to delay a successive run when injured test
	bool waitattack = false; //used in ai for anti-circling
	bool ispoisoned; //if poison is afflicting mon
	int poisonresist; //0 = 0% resist (normal), 1 = 25% resist, 2 = 50% resist, 3 = 75% resist, 4 = 100% resist (immune)
	bool poisonimmune; //if true, poison has no effect
	int poisonpow; //power of poison afflicting mon
	int poisoncounter = 0; //determines when poison causes damage
	int olddir = -1; //used in ai routine for running
	int castsub = 0; //used in ai routine for sub5 smart mons casting
	bool breakdoor = false; //used in ai routine to prevent breaking and moving in same turn
	std::vector<int>	carrying;
	std::vector<int>	equipped;
	int ammo = 0; //arrows, knives, stars, whatever (1 type per monster)
	int ammonumber = -1; //item number of proj thrown/shot
	bool useammo = false;
	bool HITANDRUN = false; //true for gigglers, assassins, others?
	bool gamewin = false;
	int hurtitem,needitem,needhandneck,pickup,steal;
};

// End Of File
