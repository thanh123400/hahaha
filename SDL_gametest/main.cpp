#include <iostream>
#include <SDL.h>
#include <string.h>

const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 600;
const std::string WINDOW_TITLE = "An Implementation of Code.org Painter";
void initSDL(SDL_Window* &window, SDL_Renderer* &renderer);

void logSDLError(std::ostream& os,const std::string &msg, bool fatal = false);
void logSDLError(std::ostream& os,const std::string &msg, bool fatal)
{
 os << msg << " Error: " << SDL_GetError() << std::endl;
 if (fatal) {
 SDL_Quit();
 exit(1);
 }
}

void initSDL(SDL_Window* &window, SDL_Renderer* &renderer)
{
 if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
 logSDLError(std::cout, "SDL_Init", true);
 window = SDL_CreateWindow(WINDOW_TITLE.c_str(), SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
 if (window == nullptr) logSDLError(std::cout, "CreateWindow", true);
 renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED |
 SDL_RENDERER_PRESENTVSYNC);
}

void quitSDL(SDL_Window* window, SDL_Renderer* renderer)
{
SDL_DestroyRenderer(renderer);
SDL_DestroyWindow(window);
SDL_Quit();
}

void waitUntilKeyPressed()
{
 SDL_Event e;
 while (true) {
 if ( SDL_WaitEvent(&e) != 0 &&
 (e.type == SDL_KEYDOWN || e.type == SDL_QUIT) )
 return;
 SDL_Delay(100);
 }
}


int main(int argc, char* argv[])
{
 SDL_Window* window;
 SDL_Renderer* renderer;
 initSDL(window, renderer);

 SDL_RenderClear(renderer);

// SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255); // white
// SDL_RenderDrawPoint(renderer, 400, 300);
// SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255); // red
// SDL_RenderDrawLine(renderer, 100, 100, 200, 200);
// SDL_Rect filled_rect;
// filled_rect.x = SCREEN_WIDTH - 400;
// filled_rect.y = SCREEN_HEIGHT - 150;
// filled_rect.w = 320;
// filled_rect.h = 100;
// SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255); // green
// SDL_RenderFillRect(renderer, &filled_rect);
 //Khi thông thường chạy với môi trường bình thường ở nhà
 SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
 SDL_RenderDrawLine(renderer, 100, 100, 200, 200);
 SDL_RenderDrawLine(renderer, 200, 200, 300, 100);
 SDL_RenderDrawLine(renderer, 100, 100, 200, 150);
 SDL_RenderDrawLine(renderer, 300, 100, 200, 150);
 SDL_RenderPresent(renderer);

 waitUntilKeyPressed();
 quitSDL(window, renderer);
 return 0;
}


