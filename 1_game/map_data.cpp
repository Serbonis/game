//========================================
// map.cpp
//========================================
#include "map_data.hpp"

//----------------------------------------
// MAP DATA
//----------------------------------------
using namespace opal;

//----------------------------------------
//----------------------------------------
namespace MAP_DATA000{ extern const MAP_DATA	map_data;	}
namespace MAP_DATA001{ extern const MAP_DATA	map_data;	}

namespace SCENE_GAME {
	extern const MAP_DATA* const	map_data[] = {
	   &MAP_DATA000::map_data,
	   &MAP_DATA001::map_data,
	};
	extern const unsigned int	map_data_max = ARRAYSIZE( map_data );
}

//----------------------------------------
// 000
//----------------------------------------
namespace MAP_DATA000 {
	const std::string	map[] =
		{
		 "・━・━・━・",
		 "┃□┃◎│□┃",
		 "・━・━・─・",
		 "┃□┃×┃□┃",
		 "・─・━・─・",
		 "┃□│□│□┃",
		 "・─・─・━・",
		 "┃□┃□┃　│",
		 "・━・━・─・",
		};

	const PLAYER_DATA	player_data[]
	= {
	   { {  0,  3 }, DIM_0, DIX_N },
	   { {  1,  3 }, DIM_0, DIX_N },
	};

	const ENEMY_DATA	enemy_data[]
	= {
	   { ENEMY_KIND::Mummy, { 0, 0 }, DIM_0, DIX_S, ENEMY_STAT::Awake  },
	   { ENEMY_KIND::Mummy, { 2, 0 }, DIM_8, DIX_S, ENEMY_STAT::Awake  },
	   { ENEMY_KIND::Mummy, { 2, 0 }, DIM_6, DIX_S, ENEMY_STAT::Awake  },
	};

	const MAP_DATA	map_data
	= {
	   "SAMPLE",
	   { map, {  3, 4 }, { 0, 0 } },
	   { player_data, ARRAYSIZE( player_data ) },
	   { enemy_data,  ARRAYSIZE( enemy_data  ) },
	};
}

//----------------------------------------
// 001
//----------------------------------------
namespace MAP_DATA001 {
	const std::string	map[] =
		{
		 "・━・━・━・━・━・",
		 "┃◎│□│□│□┃◎┃",
		 "・━・─・─・─・─・",
		 "　　┃□│□│□＊□┃",
		 "　　・━・━・━・─・",
		 "　　　　　　┃□│□┃",
		 "　　　　　　・─・━・",
		 "　　　　　　┃□┃　　",
		 "　　　　　　・─・━・",
		 "　　　　　　┃□│□┃",
		 "　　　　　　・━・─・",
		 "　　　　　　　　┃□┃",
		 "　　　　　　　　・─・",
		 "　　　　　　　　┃□┃",
		 "　　　　　　・━・─・",
		 "　　　　　　┃□│□┃",
		 "　　　　　　・─・━・",
		 "　　　　　　┃□┃　　",
		 "　　　　　　・─・　　",
		 "　　　　　　┃□┃　　",
		 "　　　　　　・─・　　",
		 "　　　　　　┃□┃　　",
		 "　　　　　　・━・　　",
		};

	const PLAYER_DATA	player_data[]
	= {
	   { {  3, 10 }, DIM_0, DIX_N },
	   { {  3, 10 }, DIM_0, DIX_N },
	};

	const ENEMY_DATA	enemy_data[]
	= {};

	const MAP_DATA	map_data
	= {
	   "ENTRANCE",
	   { map, {  5, 11 }, { 0, 0 } },
	   { player_data, ARRAYSIZE( player_data ) },
	   { enemy_data,  ARRAYSIZE( enemy_data  ) },
	};
}

// End Of File
