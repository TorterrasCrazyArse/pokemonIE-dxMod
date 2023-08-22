.set LOCALID_NURSE, 1
.set LOCALID_SCOTT, 6

EverGrandeCity_PokemonCenter_1F_MapScripts:: @ 8229A34
	map_script MAP_SCRIPT_ON_TRANSITION, EverGrandeCity_PokemonCenter_1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0

EverGrandeCity_PokemonCenter_1F_OnTransition: @ 8229A3F
	setrespawn HEAL_LOCATION_EVER_GRANDE_CITY
	call_if_unset FLAG_MET_SCOTT_IN_EVERGRANDE, EverGrandeCity_PokemonCenter_1F_EventScript_TryShowScott
	end

EverGrandeCity_PokemonCenter_1F_EventScript_TryShowScott:: @ 8229A4C
	goto_if_unset FLAG_BADGE06_GET, Common_EventScript_NopReturn
	clearflag FLAG_HIDE_EVER_GRANDE_POKEMON_CENTER_1F_SCOTT
	return

EverGrandeCity_PokemonCenter_1F_EventScript_Nurse:: @ 8229A59
	setvar VAR_0x800B, LOCALID_NURSE
	call Common_EventScript_PkmnCenterNurse
	waitmessage
	waitbuttonpress
	release
	end

EverGrandeCity_PokemonCenter_1F_EventScript_Woman:: @ 8229A67
	msgbox EverGrandeCity_PokemonCenter_1F_Text_LeagueAfterVictoryRoad, MSGBOX_NPC
	end

EverGrandeCity_PokemonCenter_1F_EventScript_ExpertM:: @ 8229A70
	msgbox EverGrandeCity_PokemonCenter_1F_Text_BelieveInYourPokemon, MSGBOX_NPC
	end

EverGrandeCity_PokemonCenter_1F_EventScript_Scott:: @ 8229A79
	lock
	faceplayer
	msgbox EverGrandeCity_PokemonCenter_1F_Text_ScottHappyForYou, MSGBOX_DEFAULT
	closemessage
	compare VAR_FACING, DIR_NORTH
	call_if_eq EverGrandeCity_PokemonCenter_1F_EventScript_ScottExitNorth
	compare VAR_FACING, DIR_EAST
	call_if_eq EverGrandeCity_PokemonCenter_1F_EventScript_ScottExit
	compare VAR_FACING, DIR_WEST
	call_if_eq EverGrandeCity_PokemonCenter_1F_EventScript_ScottExit
	addvar VAR_SCOTT_STATE, 1
	setflag FLAG_MET_SCOTT_IN_EVERGRANDE
	playse SE_EXIT
	waitse
	removeobject LOCALID_SCOTT
	release
	end

EverGrandeCity_PokemonCenter_1F_EventScript_ScottExitNorth:: @ 8229AB6
	applymovement LOCALID_SCOTT, EverGrandeCity_PokemonCenter_1F_Movement_ScottExitNorth
	waitmovement 0
	return

EverGrandeCity_PokemonCenter_1F_EventScript_ScottExit:: @ 8229AC1
	applymovement LOCALID_SCOTT, EverGrandeCity_PokemonCenter_1F_Movement_ScottExit
	waitmovement 0
	return
	
EverGrandeCity_PokemonCenter_1F_EventScript_Clerk2::
	lock
	faceplayer
	goto_if_unset FLAG_DEFEATED_SLATEPORT_GRETA, EverGrandeCity_PokemonCenter_1F_EventScript_NotAceEnough
	goto_if_unset FLAG_ITEM_ROUTE_116_BINDING_BAND, EverGrandeCity_PokemonCenter_1F_EventScript_NotAceEnough
	goto_if_unset FLAG_HIDDEN_ITEM_ROUTE_123_BLACK_SLUDGE, EverGrandeCity_PokemonCenter_1F_EventScript_NotAceEnough
	goto_if_unset FLAG_HIDDEN_ITEM_ROUTE_117_BRIGHT_POWDER, EverGrandeCity_PokemonCenter_1F_EventScript_NotAceEnough
	goto_if_unset FLAG_ITEM_LILYCOVE_CITY_LIGHT_CLAY, EverGrandeCity_PokemonCenter_1F_EventScript_NotAceEnough
	goto_if_unset FLAG_WEATHER_INSTITUTE_ROCKS, EverGrandeCity_PokemonCenter_1F_EventScript_NotAceEnough
	goto_if_unset FLAG_DEWFORD_EVIOLITE, EverGrandeCity_PokemonCenter_1F_EventScript_NotAceEnough
	goto_if_unset FLAG_ASHEN_WOODS_FLAME_ORB, EverGrandeCity_PokemonCenter_1F_EventScript_NotAceEnough
	goto_if_unset FLAG_RECEIVED_LIFE_ORB, EverGrandeCity_PokemonCenter_1F_EventScript_NotAceEnough
	goto_if_unset FLAG_FORTREE_NPC_TRADE_COMPLETED, EverGrandeCity_PokemonCenter_1F_EventScript_NotAceEnough
	goto_if_unset FLAG_PACIFIDLOG_NPC_TRADE_COMPLETED, EverGrandeCity_PokemonCenter_1F_EventScript_NotAceEnough
	goto_if_unset FLAG_ITEM_DEWFORD_MEADOW_RING_TARGET, EverGrandeCity_PokemonCenter_1F_EventScript_NotAceEnough
	goto_if_unset FLAG_ITEM_ROUTE_114_PROTECTIVE_PADS, EverGrandeCity_PokemonCenter_1F_EventScript_NotAceEnough
	goto_if_unset FLAG_RECEIVED_SCOPE_LENS, EverGrandeCity_PokemonCenter_1F_EventScript_NotAceEnough
	goto_if_unset FLAG_ITEM_ROUTE_119_TOXIC_ORB, EverGrandeCity_PokemonCenter_1F_EventScript_NotAceEnough
	goto_if_unset FLAG_ITEM_ROUTE_123_WIDE_LENS, EverGrandeCity_PokemonCenter_1F_EventScript_NotAceEnough
	goto_if_unset FLAG_ITEM_ROUTE_109_ZOOM_LENS, EverGrandeCity_PokemonCenter_1F_EventScript_NotAceEnough
	message gText_HowMayIServeYou
	waitmessage
	pokemart PokeMart_PokeCenterEverGrandeCity
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
PokeMart_PokeCenterEverGrandeCity::
	.2byte ITEM_LIFE_ORB
	.2byte ITEM_TOXIC_ORB
	.2byte ITEM_FLAME_ORB
	.2byte ITEM_CHOICE_SCARF
	.2byte ITEM_CHOICE_BAND
    .2byte ITEM_CHOICE_SPECS
	.2byte ITEM_EXPERT_BELT
	.2byte ITEM_MUSCLE_BAND
	.2byte ITEM_WISE_GLASSES
	.2byte ITEM_ASSAULT_VEST
	.2byte ITEM_EVIOLITE
	.2byte ITEM_PROTECTIVE_PADS
	.2byte ITEM_SAFETY_GOGGLES
	.2byte ITEM_SCOPE_LENS
	.2byte ITEM_ZOOM_LENS
	.2byte ITEM_WIDE_LENS
	.2byte ITEM_SMOOTH_ROCK
	.2byte ITEM_DAMP_ROCK
	.2byte ITEM_ICY_ROCK
	.2byte ITEM_HEAT_ROCK
	.2byte ITEM_LIGHT_CLAY
	.2byte ITEM_TERRAIN_EXTENDER
	.2byte ITEM_BLACK_SLUDGE
	.2byte ITEM_RING_TARGET
	.2byte ITEM_BRIGHT_POWDER
	.2byte ITEM_DESTINY_KNOT
	.2byte ITEM_BINDING_BAND
	.2byte ITEM_ROCKY_HELMET
	.2byte ITEM_FOCUS_BAND
	.2byte ITEM_PP_UP
	.2byte ITEM_NONE
	release
	end
	
EverGrandeCity_PokemonCenter_1F_EventScript_NotAceEnough:
	msgbox EverGrandeCity_PokemonCenter_1F_Text_NotAceEnough, MSGBOX_DEFAULT
	release
	end
	
EverGrandeCity_PokemonCenter_1F_Movement_ScottExitNorth: @ 8229ACC
	walk_left
	walk_down
	walk_down
	walk_left
	walk_down
	walk_down
	step_end

EverGrandeCity_PokemonCenter_1F_Movement_ScottExit: @ 8229AD3
	walk_down
	walk_down
	walk_left
	walk_left
	walk_down
	walk_down
	step_end

EverGrandeCity_PokemonCenter_1F_Text_LeagueAfterVictoryRoad: @ 8229ADA
	.string "The Pokémon League is only a short\n"
	.string "distance after the Victory Road.\p"
	.string "If you've come this far, what choice\n"
	.string "do you have but to keep going?$"

EverGrandeCity_PokemonCenter_1F_Text_BelieveInYourPokemon: @ 8229B62
	.string "The long and harrowing Victory Road…\p"
	.string "It's like reliving the path one has\n"
	.string "traveled in life…\p"
	.string "Believe in your Pokémon and give it\n"
	.string "your very best!$"

EverGrandeCity_PokemonCenter_1F_Text_ScottHappyForYou: @ 8229BF1
	.string "Scott: {PLAYER}{KUN}, you've clawed your\n"
	.string "way up to face the Pokémon League!\p"
	.string "I'm happy for you!\n"
	.string "You made my cheering worthwhile!\p"
	.string "{PLAYER}{KUN}, if you were to become\n"
	.string "the Pokémon League Champion…\p"
	.string "I'll get in touch with you then.\p"
	.string "Okay, {PLAYER}{KUN}.\n"
	.string "Go for greatness!$"
	
EverGrandeCity_PokemonCenter_1F_Text_NotAceEnough:
	.string "I'm sorry, but currently we're\n"
	.string "waiting for some merchandise to\l"
	.string "be delivered.\p"
	.string "Come back later when we're done!$"

