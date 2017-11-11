#define EXTENSION_NAME defsteam
#define LIB_NAME "defsteam"
#define MODULE_NAME "defsteam"

#define DLIB_LOG_DOMAIN LIB_NAME
#include <dmsdk/sdk.h>

#include "./steam_api.h"

#if defined(DM_PLATFORM_OSX) || defined(DM_PLATFORM_WINDOWS)

static int start_steam(lua_State* L) {

	if(!SteamAPI_Init()) {
		return -1;
	}

	CSteamID steamid;
	int loggedon;

	steamid = SteamUser()->GetSteamID();
	loggedon = SteamUser()->BLoggedOn();

	SteamUserStats()->RequestCurrentStats();

	
    return 0;
}



static const luaL_reg Module_methods[] =
{
    {"start_steam", start_steam},
    {0, 0}
};

static void LuaInit(lua_State* L)
{
    int top = lua_gettop(L);
    luaL_register(L, MODULE_NAME, Module_methods);
    lua_pop(L, 1);
    assert(top == lua_gettop(L));
}

dmExtension::Result AppInitializeDefos(dmExtension::AppParams* params)
{
    return dmExtension::RESULT_OK;
}

dmExtension::Result InitializeDefos(dmExtension::Params* params)
{
    LuaInit(params->m_L);
    return dmExtension::RESULT_OK;
}

dmExtension::Result AppFinalizeDefos(dmExtension::AppParams* params)
{
    return dmExtension::RESULT_OK;
}

dmExtension::Result FinalizeDefos(dmExtension::Params* params)
{
    return dmExtension::RESULT_OK;
}

DM_DECLARE_EXTENSION(EXTENSION_NAME, LIB_NAME, AppInitializeDefos, AppFinalizeDefos, InitializeDefos, 0, 0, FinalizeDefos)
#endif
