#include <SDL3/SDL.h>

int main()
{
    if (!SDL_Init(SDL_INIT_VIDEO)) {
        SDL_Log("Couldn't initialize SDL: %s", SDL_GetError());
        return SDL_APP_FAILURE;
    }

    SDL_Window *window = SDL_CreateWindow("hello", 800, 600, 0);
    if (!window) {
        SDL_Log("Couldn't create window: %s", SDL_GetError());
        return SDL_APP_FAILURE;
    }

    SDL_ShowWindow(window);

    bool exit_requested = false;
    while(!exit_requested)
    {
        SDL_Event sdl_event;
        while (SDL_PollEvent(&sdl_event))
        {
            switch (sdl_event.type)
            {
                case SDL_EVENT_QUIT:
                case SDL_EVENT_WINDOW_CLOSE_REQUESTED:
                {
                    exit_requested = true;
                    break;
                }
                case SDL_EVENT_MOUSE_BUTTON_DOWN:
                case SDL_EVENT_MOUSE_BUTTON_UP:
                {
                    SDL_Window *w = SDL_GetWindowFromEvent(&sdl_event);
                    SDL_Log("SDL_GetWindowFromEvent -> %d", w);
                    break;
                }
                case SDL_EVENT_MOUSE_MOTION:
                {
                    SDL_Log("SDL_EVENT_MOUSE_MOTION -> %d", SDL_GetTicks());
                    break;
                }
                case SDL_EVENT_WINDOW_MOUSE_ENTER:
                {
                    SDL_Log("SDL_EVENT_WINDOW_MOUSE_ENTER -> %d", SDL_GetTicks());
                    break;
                }
                case SDL_EVENT_WINDOW_MOUSE_LEAVE:
                {
                    SDL_Log("SDL_EVENT_WINDOW_MOUSE_LEAVE -> %d", SDL_GetTicks());
                    break;
                }
                default:
                    break;
            }
        }
    }

    return 0;
}
