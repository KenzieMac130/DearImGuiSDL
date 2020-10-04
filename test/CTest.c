#include <stdio.h>

#include <SDL.h>
#include <SDL_main.h>
#include <SDL_video.h>
#include <SDL_events.h>

#include "DearImGuiSDL.h"

int main(int argc, char* argv[])
{
	SDL_Init(SDL_INIT_VIDEO);

	/* Create a window */
	SDL_Window* pMainWindow = SDL_CreateWindow(
		"C Main Window",
		SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED,
		1920,
		1080,
		0);
	if (!pMainWindow) { return -1; }

	/* Create a renderer */
	SDL_Renderer* pRenderer = SDL_CreateRenderer(pMainWindow, -1, 0);
	if (!pRenderer) { return -2; }

	/* Create a surface */
	SDL_Surface* pMainSurface = SDL_GetWindowSurface(pMainWindow);
	if (!pMainSurface) { return -3; }
	DearImguiSDL_RegisterSurface(pMainSurface, pRenderer);

	/* Create Debug UI */
	DearImguiSDL_Initialize("C TEST");

	/* Main loop */
	bool running = true;
	while (running)
	{
		/* Poll events*/
		SDL_Event event;
		while (SDL_PollEvent(&event))
		{
			if (event.type == SDL_QUIT)
			{
				running = false;
			}
			DearImguiSDL_HandleEvent(&event);
		}
		DearImguiSDL_NewFrame(pMainWindow, pMainSurface, 1.0f / 60.0f);

		/* Previous Drawing */
		SDL_SetRenderDrawColor(pRenderer, 0, 0, 255, SDL_ALPHA_OPAQUE);
		SDL_RenderClear(pRenderer);

		/* Demo Window */
		igShowDemoWindow(NULL);

		/* Nodes Test */
		const int hardcoded_node_id = 1;
		const int output_attr_id = 2;
		inodeBeginNodeEditor();
		inodeBeginNode(hardcoded_node_id);
		inodeBeginOutputAttribute(output_attr_id, ImNodesPinShape_PinShape_Circle);
		igText("DOOT");
		inodeEndAttribute();
		inodeEndNode();
		inodeEndNodeEditor();

		SDL_RenderClear(pRenderer);

		/* Update Debug UI */
		DearImguiSDL_EndFrame();
		DearImguiSDL_RenderSurface(pMainSurface, pRenderer);

		SDL_RenderPresent(pRenderer);
	}

	DearImguiSDL_UnregisterSurface(pMainSurface, pRenderer);
	DearImguiSDL_Shutdown();
	SDL_DestroyWindow(pMainWindow);
	return 0;
}