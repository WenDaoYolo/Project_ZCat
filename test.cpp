#include<SDL.h>
#include<stdio.h>

int main(int argc, char *argv[])
{
    int SDL_Init(SDL_INIT_EVERYTHING);

    SDL_Window* win=SDL_CreateWindow
        (
            "HelloWorld",
            SDL_WINDOWPOS_CENTERED,
            SDL_WINDOWPOS_CENTERED,
            500,700,SDL_WINDOW_SHOWN
        );

    SDL_Renderer* win_rd=SDL_CreateRenderer(win,-1,SDL_RENDERER_SOFTWARE);
    SDL_RenderClear(win_rd);
    SDL_RenderPresent(win_rd);
    SDL_SetWindowResizable(win,SDL_TRUE);

    getchar();
    SDL_DestroyRenderer(win_rd);
    SDL_DestroyWindow(win);
    SDL_Quit();
    return 0;
}