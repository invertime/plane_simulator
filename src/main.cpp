#include <SDL2/SDL.h>
#include <cstdlib>

int main(int argc, char *argv[])
{
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "[DEBUG] > %s", SDL_GetError());
        return EXIT_FAILURE;
    }
    SDL_Window *pWindow{nullptr};
    SDL_Renderer *pRenderer{nullptr};
    if (SDL_CreateWindowAndRenderer(800, 600, SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE, &pWindow, &pRenderer) < 0)
    {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "[DEBUG] > %s", SDL_GetError());
        SDL_Quit();
        return EXIT_FAILURE;
    }
    SDL_SetWindowTitle(pWindow, "CT-1201 Simulator");
    SDL_Event events;
    bool isOpen{true};
    while (isOpen)
    {
        while (SDL_PollEvent(&events))
        {
            switch (events.type)
            {
            case SDL_QUIT:
                isOpen = false;
                SDL_LogError(SDL_LOG_CATEGORY_APPLICATION,"[DEBUG] > Exiting window...");
                break;
            }
        }

        SDL_SetRenderDrawColor(pRenderer, 0, 0, 0, 255);
        SDL_RenderClear(pRenderer);
        SDL_RenderPresent(pRenderer);
    }
    SDL_DestroyRenderer(pRenderer);
    SDL_DestroyWindow(pWindow);
    SDL_Quit();
    return EXIT_SUCCESS;
}
