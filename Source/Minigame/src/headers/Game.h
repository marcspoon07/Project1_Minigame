#pragma once

#include "../simple_types.h"

#include "Singleton.h"

class Game : public Singleton<Game>
{
	friend class Singleton<Game>;
private:
	Game();
public:
	~Game();
};