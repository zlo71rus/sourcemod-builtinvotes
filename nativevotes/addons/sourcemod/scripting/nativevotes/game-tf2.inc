/**
 * vim: set ts=4 :
 * =============================================================================
 * NativeVotes
 * Copyright (C) 2011-2012 Ross Bemrose (Powerlord).  All rights reserved.
 * =============================================================================
 *
 * This program is free software; you can redistribute it and/or modify it under
 * the terms of the GNU General Public License, version 3.0, as published by the
 * Free Software Foundation.
 * 
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
 * FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more
 * details.
 *
 * You should have received a copy of the GNU General Public License along with
 * this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 * As a special exception, AlliedModders LLC gives you permission to link the
 * code of this program (as well as its derivative works) to "Half-Life 2," the
 * "Source Engine," the "SourcePawn JIT," and any Game MODs that run on software
 * by the Valve Corporation.  You must obey the GNU General Public License in
 * all respects for all other code used.  Additionally, AlliedModders LLC grants
 * this exception to all derivative works.  AlliedModders LLC defines further
 * exceptions, found in LICENSE.txt (as of this writing, version JULY-31-2007),
 * or <http://www.sourcemod.net/license.php>.
 *
 * Version: $Id$
 */

#if defined _nativevotes_vote_included
 #endinput
#endif

#define _nativevotes_vote_included

#include <sourcemod>

// User vote to kick user.
#define TRANSLATION_TF2_VOTE_KICK_IDLE_START			"#TF_vote_kick_player_idle"
#define TRANSLATION_TF2_VOTE_KICK_SCAMMING_START		"#TF_vote_kick_player_scamming"
#define TRANSLATION_TF2_VOTE_KICK_CHEATING_START		"#TF_vote_kick_player_cheating"
#define TRANSLATION_TF2_VOTE_KICK_START					"#TF_vote_kick_player_other"
#define TRANSLATION_TF2_VOTE_KICK_PASSED				"#TF_vote_passed_kick_player"

// User vote to restart map.
#define TRANSLATION_TF2_VOTE_RESTART_START				"#TF_vote_restart_game"
#define TRANSLATION_TF2_VOTE_RESTART_PASSED				"#TF_vote_passed_restart_game"

// User vote to change maps.
#define TRANSLATION_TF2_VOTE_CHANGELEVEL_START			"#TF_vote_changelevel"
#define TRANSLATION_TF2_VOTE_CHANGELEVEL_PASSED			"#TF_vote_passed_changelevel"

// User vote to change next level.
#define TRANSLATION_TF2_VOTE_NEXTLEVEL_SINGLE_START		"#TF_vote_nextlevel"
#define TRANSLATION_TF2_VOTE_NEXTLEVEL_MULTIPLE_START	"#TF_vote_nextlevel_choices" // Started by server
#define TRANSLATION_TF2_VOTE_NEXTLEVEL_EXTEND_PASSED	"#TF_vote_passed_nextlevel_extend"
#define TRANSLATION_TF2_VOTE_NEXTLEVEL_PASSED			"#TF_vote_passed_nextlevel"

// User vote to scramble teams.  Can be immediate or end of round.
#define TRANSLATION_TF2_VOTE_SCRAMBLE_IMMEDIATE_START	"#TF_vote_scramble_teams"
#define TRANSLATION_TF2_VOTE_SCRAMBLE_ROUNDEND_START	"#TF_vote_should_scramble_round"
#define TRANSLATION_TF2_VOTE_SCRAMBLE_PASSED 			"#TF_vote_passed_scramble_teams"

// While not a vote string, it works just as well.
#define TRANSLATION_TF2_VOTE_CUSTOM						"#TF_playerid_noteam"

bool:Game_CheckVoteType(NativeVotesType:voteType)
{
	switch(voteType)
	{
		case NativesVotesType_Custom_YesNo, NativesVotesType_Restart, NativesVotesType_ChangeLevel,
		NativesVotesType_Kick, NativesVotesType_KickIdle, NativesVotesType_KickScamming,
		NativesVotesType_KickCheating, NativesVotesType_NextLevel, NativesVotesType_NextLevelMult,
		NativesVotesType_ScrambleNow, NativesVotesType_ScrambleEnd, NativesVotesType_Custom_Mult:
		{
			return true;
		}
		
		default:
		{
			return false;
		}
	}
	
	return false;
}

Game_GetMaxItems()
{
	return 5;
}

public Action:Game_VoteParser(client, const String:command[], argc)
{
	// Vote Processing logic here
	
	return Plugin_Continue;
}
