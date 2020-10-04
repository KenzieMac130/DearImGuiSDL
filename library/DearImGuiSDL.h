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

	typedef enum {
		DEARIMGUISDL_SUCCESS = 0,
		DEARIMGUISDL_ERROR_INCOMPATIBLE_FORMAT = 1,
		DEARIMGUISDL_ERROR_OUT_OF_MEMORY = 2,
		DEARIMGUISDL_ERROR_UNREGISTERED = 3,
		_DEARIMGUISDL_ERROR_COUNT,
		DEARIMGUISDL_ERROR_UNKNOWN = UINT32_MAX
	} DearImguiSDL_Result;

	const char* DearImguiSDL_GetResultString(DearImguiSDL_Result result);

	DearImguiSDL_Result DearImguiSDL_Initialize(const char* appName);
	DearImguiSDL_Result DearImguiSDL_Shutdown();

	bool DearImguiSDL_IsFocused();

	DearImguiSDL_Result DearImguiSDL_NewFrame(SDL_Window* pActiveWindow, SDL_Surface* pSurface, float deltaTime);
	DearImguiSDL_Result DearImguiSDL_EndFrame();

	DearImguiSDL_Result DearImguiSDL_RegisterSurface(SDL_Surface* pSurface, SDL_Renderer* pRenderer);
	DearImguiSDL_Result DearImguiSDL_UnregisterSurface(SDL_Surface* pSurface, SDL_Renderer* pRenderer);

	DearImguiSDL_Result DearImguiSDL_RenderSurface(SDL_Surface* pSurface, SDL_Renderer* pRenderer);
	void DearImguiSDL_HandleEvent(SDL_Event* pEvent);

	DearImguiSDL_Result DearImguiSDL_ShowSoftwareStats();

#ifdef __cplusplus
}
#endif
#endif