/* Bundles a bunch of ImGui goodies for easy use in SDL software applications */
#ifndef _DEARIMGUISDL_H_
#define _DEARIMGUISDL_H_

#ifdef __cplusplus
/* Include C++ libraries if using C++ */
#include "cimgui/imgui/imgui.h"
#include "imnodes/imnodes.h"
#else
#define DEAR_IMGUI_SDL_C_API
#endif

#ifdef DEAR_IMGUI_SDL_C_API
/* Include C libraries */
#define CIMGUI_DEFINE_ENUMS_AND_STRUCTS
#define CIMNODES_DEFINE_ENUMS_AND_STRUCTS
#include "cimgui/cimgui.h"
#include "imnodes/cimnodes.h"
#endif

#include <SDL_render.h>
#include <SDL_video.h>
#include <SDL_events.h>
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

	/* Return codes */
	typedef enum {
		DEARIMGUISDL_SUCCESS = 0,
		DEARIMGUISDL_ERROR_INCOMPATIBLE_FORMAT = 1,
		DEARIMGUISDL_ERROR_OUT_OF_MEMORY = 2,
		DEARIMGUISDL_ERROR_UNREGISTERED = 3,
		_DEARIMGUISDL_ERROR_COUNT,
		DEARIMGUISDL_ERROR_UNKNOWN = UINT32_MAX
	} DearImguiSDL_Result;

	/* Get a null terminated string for a return code */
	const char* DearImguiSDL_GetResultString(DearImguiSDL_Result result);

	/* Initialize. Call this once at the start of your program */
	DearImguiSDL_Result DearImguiSDL_Initialize(const char* appName);
	/* Shutdown. Call once at the end of your program */
	DearImguiSDL_Result DearImguiSDL_Shutdown();

	/* Is the user currently working with the user interface?
	This is useful for blocking input to your game */
	bool DearImguiSDL_IsFocused();

	/* Begin a new frame. Call this after polling and handling events. */
	DearImguiSDL_Result DearImguiSDL_NewFrame(SDL_Window* pActiveWindow, SDL_Surface* pSurface, float deltaTime);
	/* End the current frame. Call this before rendering. */
	DearImguiSDL_Result DearImguiSDL_EndFrame();

	/* Register an SDL surface before rendering the gui to it.
	Call this after creating the surface. */
	DearImguiSDL_Result DearImguiSDL_RegisterSurface(SDL_Surface* pSurface, SDL_Renderer* pRenderer);
	/* Render the gui to the surface. Call this after "DearImguiSDL_EndFrame()" */
	DearImguiSDL_Result DearImguiSDL_RenderSurface(SDL_Surface* pSurface, SDL_Renderer* pRenderer);
	/* Unregister an SDL surface and free up internal state held by this library.
	Call this before destroying the surface. */
	DearImguiSDL_Result DearImguiSDL_UnregisterSurface(SDL_Surface* pSurface, SDL_Renderer* pRenderer);

	/* Handle an SDL event. Put this in your message loop. */
	void DearImguiSDL_HandleEvent(SDL_Event* pEvent);

	/* Show the software rendering statistics in an imgui window. Assumes "ImGui::Begin()" has been called. */
	void DearImguiSDL_ShowSoftwareStats();

#ifdef __cplusplus
}
#endif
#endif