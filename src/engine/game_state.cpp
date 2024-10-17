#include "game_state.hpp"

/* The main game loop. Loops until quit
 * event is fired. Checks the event loop
 * first, then updates state and objects,
 * and updates the renderer
 */
void GameState::game_loop () {
	while (!_quit) {
		event_loop();
		update();
		render();
	}
}

/* Pops any events from the SDL event loop
 * and passes their ID to the handle_event
 * function.
 */
void GameState::event_loop () {
	while (SDL_PollEvent(&_event)) {
		handle_event();
	}
}

/* Parses the given SDL Event ID
 * and calls the corresponding
 * function.
 */
void GameState::handle_event () {
	switch (_event.type) {
		case SDL_QUIT:
			_quit = true;
			break;
		case SDL_MOUSEMOTION:
			SDL_GetMouseState(&_mouseX, &_mouseY);
			break;
		case SDL_MOUSEBUTTONDOWN:
			for (size_t i = 0; i < _game_objects.size(); ++i) {
				if (_game_objects[i]->mouse_colliding(_mouseX, _mouseY))
					_game_objects[i]->mouse_button_down(_event);
			}
			break;
		case SDL_MOUSEBUTTONUP:
			for (size_t i = 0; i < _game_objects.size(); ++i) {
				if (_game_objects[i]->mouse_colliding(_mouseX, _mouseY))
					_game_objects[i]->mouse_button_up(_event);
			}
			break;
	}
}

/* Updates game objects and any game state
 * that needs to be updated before/outside
 * of the render loop
 */
void GameState::update () {
	for (size_t i = 0; i < _game_objects.size(); ++i) {
		_game_objects[i]->update();
	}
}

/* Handles the game state rendering outside
 * the main render loop and runs all game object
 * render functions inside the main render loop
 */
void GameState::render () {
	/* render background */
	SDL_SetRenderDrawColor(_sdl_state.get_renderer(), 35, 27, 46, 255);
	SDL_RenderClear(_sdl_state.get_renderer());

	for (size_t i = 0; i < _game_objects.size(); ++i) {
		_game_objects[i]->render();
	}

	SDL_RenderPresent(_sdl_state.get_renderer());
}

/* Registers a given object to the game object array
 */
void GameState::register_object (GameObject* object) {
	_game_objects.push_back(object);
}
