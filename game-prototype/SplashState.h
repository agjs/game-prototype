#pragma once
#include <SFML/Graphics.hpp>
#include "state.h"
#include "Game.h"


namespace GamePrototype {
	class SplashState : public State
	{
	public:
		SplashState(GameDataRef_t data);
		~SplashState();

		void Init();
		void HandleInput();
		void Update(float dt);
		void Draw(float dt);

	private:
		GameDataRef_t _data;
		sf::Clock _clock;
		sf::Sprite _background;

	};
}