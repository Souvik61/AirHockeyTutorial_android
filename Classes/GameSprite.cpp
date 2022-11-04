#include "GameSprite.h"

GameSprite::GameSprite(void) {
	_vector = Vec2(0, 0);
}

GameSprite::~GameSprite(void) {
}

GameSprite* GameSprite::gameSpriteWithFile(const char* pszFileName) {
	auto sprite = new GameSprite();
	if (sprite && sprite->initWithFile(pszFileName)) {
		sprite->autorelease();
		return sprite;
	}
	CC_SAFE_DELETE(sprite);
	return sprite = nullptr;
}

void GameSprite::setPosition(const Vec2& pos) {
	Sprite::setPosition(pos);
	if (!_nextPosition.equals(pos)) {
		_nextPosition = pos;
	}
}