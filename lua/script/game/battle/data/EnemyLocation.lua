
EnemyLocation = {	
	["1"] = {	{0,0,1},	},
	["2"] = {	{0,0,2},{54,-11,1},	},
	["3"] = {	{0,0,3},{56,-11,2},{30,-28.5,1},	},
	["4"] = {	{0,0,4},{62,0,3},{69,-29,1},{38,-12,2},	},
	["5"] = {	{0,0,5},{69,0,4},{35.95,-28.5,3},{110,-11.5,2},{87,-29,1},	},
	["6"] = {	{0,0,6},{60,0,4},{109,0,5},{29,-28.5,3},{80,-28.5,1},{124,-29.5,2},	},
	["7"] = {	{0,0,7},{64,0,5},{104,0,6},{20,-28.5,3},{76,-28.5,1},{124,-28.5,2},{52,-12,4},	},
	["8"] = {	{0,0,8},{59,0,6},{122,0,7},{44,-11.5,4},{22.95,-29,2},{74,-29,1},{134,-29,3},{108,-12,5},	},
	["9"] = {	{0,0,9},{54,0,7},{108,0,8},{46,-21,5},{24,-29,4},{65,-29,3},{114,-29,1},{80,0,6},{138,-29,2},	},
	["10"] = {	{0,0,10},{54,0,8},{108,0,9},{46,-21,5},{24,-29,4},{65,-29,2},{114,-29,1},{86,0,7},{153,-29,3},{162,0,6},	},
	["11"] = {	{0,0,11},{54,0,9},{108,0,10},{46,-21,5},{24,-29,4},{65,-29,3},{114,-29,1},{91,0,8},{153,-29,2},{162,0,7},{150,-12,6},	},
	["12"] = {	{0,0,12},{54,0,10},{108,0,11},{46,-21,6},{24,-29,5},{65,-29,4},{114,-29,1},{91,0,9},{153,-29,2},{162,0,8},{150,-12,7},{182,-29,3},	},
}




function EnemyLocation.getPosition(num)
	if num > 12 then
		echoWarn("_________________堆叠人数超过12")
		num = 12
	end
	local idx = tostring(num)
	return EnemyLocation[idx]
end

return EnemyLocation