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
		 "・━・━・",
		 "┃□│□┃",
		 "・─・─・",
		 "┃□│□┃",
		 "・─・─・",
		 "┃□│□┃",
		 "・━・━・",
		};

	const ENEMY_DATA	enemy_data[]
	= {
	   { ENEMY_KIND::Mummy, { 0, 0 }, DIX_S, ENEMY_STAT::Awake  },
	   { ENEMY_KIND::Mummy, { 1, 0 }, DIX_S, ENEMY_STAT::Awake  },
	};

	const MAP_DATA	map_data
	= {
	   { map, {  2, 3 }, { 0, 0 } },
	   { {  0,  2 }, DIX_N },
	   { enemy_data, ARRAYSIZE( enemy_data ) },
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

	const MAP_DATA	map_data = { { map, {  5,11 }, { 0, 0 } }, { {  3, 10 }, DIX_N }, {} };
}

// End Of File
