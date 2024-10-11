#include "game_state.hpp"

void GameState::game_loop () {
	while (!_quit) {
		event_loop();
		update();
		render();
	}
}

void GameState::event_loop () {
	while (SDL_PollEvent(&_event)) {
		handle_event(_event.type);
	}
}

void GameState::handle_event (int type) {
	switch (type) {
		case SDL_QUIT:
			_quit = true;
			break;
		case SDL_MOUSEMOTION:
			SDL_GetMouseState(&_mouseX, &_mouseY);
			break;
	}
}

void GameState::update () {
	for (size_t i = 0; i < _game_objects.size(); ++i) {
		_game_objects[i]->update();
	}
}

void GameState::render () {
	for (size_t i = 0; i < _game_objects.size(); ++i) {
		_game_objects[i]->render();
	}
}
