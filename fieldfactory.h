#pragma once
#include "Map.h"
#include <SFML/System/String.hpp>
#include "player.h"
#include "cell_facrory.h"
class fieldfactory 
{
private:
	Map* m;
	player* p;
public:
	fieldfactory(Map* m, player* p);
	const sf::String s1[11] = {
	"00000000000",
	"01011000000",
	"01023000010",
	"02000000000",
	"00333000000",
	"00000000000",
	"00000000010",
	"00010101010",
	"01111111000",
	"00000001110",
	"00000000000",
	};
	const sf::String s2[16] = {
		"0000000000000000",
		"0000000000000000",
		"0000000000000000",
		"0000000000000000",
		"0000000000000000",
		"0000000000000000",
		"0000000000000000",
		"0000000000000000",
		"0000000000000000",
		"0000000000000000",
		"0000000000000000",
		"0000000011110000",
		"0000000000000000",
		"0000000000000000",
		"0000000000000000",
		"1000000111111111",
	};

	const sf::String s3[21] = {
		"000000000000011111110",
		"000000000000000000000",
		"000000000031100000000",
		"000000033333311111000",
		"000000000021000010000",
		"000000003333333000000",
		"001100000000001100000",
		"000000020200000000000",
		"000000003333333300000",
		"000000000000033300000",
		"000000011110000000000",
		"000000000003303100000",
		"000000000000000000000",
		"011111111000000000000",
		"000000111110000000000",
		"033000000001000000000",
		"001300000000000000000",
		"011111110000033300000",
		"020000000000000003300",
		"000000000333333300000",
		"000000000000000000000",
	};

	void creat_Map();
};

