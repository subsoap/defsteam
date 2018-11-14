# THIS IS NOW DEPRECIATED!! DO NOT USE!!

Use this up to date extension instead:

https://www.defold.com/community/projects/121594/

https://github.com/britzl/steamworks-defold


# DefSteam

Steamworks support for Defold

# Installation

To use this extension you must be a registered Steamworks developer through Valve and a game on Steam setup with an appid. Otherwise this extension will be of no use to you.

You can sign up here: https://partner.steamgames.com/

You must first download the latest Steamworks SDK. If the latest doesn't work the last known version tested is 1.40 which should work.

https://partner.steamgames.com/downloads/list

Create a folder called "res" in the root of your project next to your game.project file. Look at the example project for a sample. 

Create a "common" folder within the "res" folder and then create a "steam_appid.txt" and type your Steam game's appid into it. Open your game.project file and add a line under [project] with the text "bundle_resources = /res" without quotes.

Copy and paste the "steam_appid.txt" to the root of your project next to your game.project file. A steam_appid.txt file is required when launching a game using Steam directly without launching from Steam.

Create target folders within the "res" folder for each platform you wish to release your game on Steam. Valid options are "x86-win32" "x86_64-win32" "x86_64-osx" "x86_64-linux" then copy the appropriate redistributable files from the Steamworks SDK to these folders. You can find these in for example "\steamworks_sdk_140\sdk\redistributable_bin" with the non-64 win32 steam_api.dll in that folder. These files are copied into the root of your game's folder when bundling.

Next copy and paste the redistributable files into the root of your project next to the game.project file. This is so that you can test your game using "Project -> Build"

Next add this project as a [Defold library dependency](http://www.defold.com/manuals/libraries/). Open your game.project file and in the dependencies field under project add:

	https://github.com/subsoap/defsteam/archive/master.zip

Remember to do Project -> Fetch Libraries	
	
# Bundling

With the steps for installation correctly followed the appropriate redistributable files should be included with your game when bundling.

# Example

The example uses the Steam appid of 480. This is the game Valve uses for testing Steamworks features, and a copy of it is included in the Steamworks SDK. You can view its achievement and stats metadata here: https://steamdb.info/app/480/stats/

To run the example you will need to go through the steps in the installation to add redistributable files to your project root and res folders as the required redistributable files are not included with DefSteam.

# Usage

In your main script require DefSteam.

```
local defsteam = require("defsteam.defsteam")
```

Then run init

```
defsteam.init()
```

Most of the Steamworks API should be available to you. You can read the Steamworks documentation for features.

https://partner.steamgames.com/doc/sdk/api

For achievements you would for example use.

```
defsteam.userstats.SetAchievement("ACH_WIN_ONE_GAME")
```

# Information

DefSteam does not use native extensions and instead is using ffi.

DefSteam uses a modified ffibuild generated steamworks.lua from the [Goluwa project](https://github.com/CapsAdmin/goluwa).
