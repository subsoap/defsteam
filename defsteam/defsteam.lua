local ffi = package.preload.ffi()

local M = {}

function M.init()
	local ok, err = pcall(function()
		local steamworks = require("defsteam.steamworks")
		M.active = true
		for k,v in pairs(steamworks) do
			if not M[k] then
				M[k] = v
			end
		end
	end)

	if not ok then
		print("DefSteam: Steamworks couldn't be started. Is Steam running?")
		M.active = false
	end	
end

function M.final()
	print("DefSteam: Steamworks Shutdown")
	M.SteamAPI_Shutdown()
end


return M