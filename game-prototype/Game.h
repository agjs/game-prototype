#pragma once

#include <memory>
#include <string>
#include <SFML/Graphics.hpp>
#include "StateMachine.h"
#include "AssetManager.h"
#include "InputManager.h"

namespace GamePrototype {

	struct GameData {
		StateMachine machine;
		sf::RenderWindow window;
		AssetManager assets;
		InputManager input;
	};

	typedef std::shared_ptr<GameData> GameDataRef_t;

	class Game {
	public:
		Game(int width, int height, std::string applicationName);
		~Game();
	private:
		const float dt = 1.0f / 60.0f; // Frame Rate
		sf::Clock _clock;
		GameDataRef_t _data = std::make_shared<GameData>();

		void Run();

	};
};
