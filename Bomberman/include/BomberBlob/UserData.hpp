#ifndef BOMBERMAN_USERDATA_HPP
#define BOMBERMAN_USERDATA_HPP

enum objectTypeEnum{
	EXPLOSION = 0,
	BOMB = 1,
	PLAYER = 2,
	INDESTRUCTIBLE_BOX = 3,
	BOX = 4
};

struct UserData {
	objectTypeEnum materialIndex;
	void* object;
};

#endif //BOMBERMAN_USERDATA_HPP
