
#include "ESP.h"
#include "Interfaces.h"
#include "Render.h"
#include <ctime>
#include <iostream>
#include <algorithm>
#include "GrenadePrediction.h"
#include "LagComp.h"


visuals::visuals()
{
	BombCarrier = nullptr;
}

int width = 0;
int height = 0;
bool done = false;
void visuals::OnPaintTraverse(C_BaseEntity* local)
{


    for (int i = 0; i < g_EntityList->GetHighestEntityIndex(); i++)
    {

        C_BaseEntity *entity = g_EntityList->GetClientEntity(i);
        player_info_t pinfo;
        if (entity == local && local->IsAlive() && g_Engine->GetPlayerInfo(g_Engine->GetLocalPlayer(), &pinfo))
        {
            if (g_Input->m_fCameraInThirdPerson && g_Options.Visuals.Enabled)
            {
                Vector max = entity->GetCollideable()->OBBMaxs();
                Vector pos, pos3D;
                Vector top, top3D;
                pos3D = entity->GetOrigin();
                top3D = pos3D + Vector(0, 0, max.z);

                if (!g_Render->WorldToScreen(pos3D, pos) || !g_Render->WorldToScreen(top3D, top))
                    return;

                float height = (pos.y - top.y);
                float width = height / 4.f;
                if (g_Options.Visuals.Box)
                {
                    Color color;
                    color = GetPlayerColor(entity, local);
                    PlayerBox(top.x, top.y, width, height, color);
                }
                if (g_Options.Visuals.HP)
                    DrawHealth(pos, top, local->GetHealth());

                if (g_Options.Visuals.Name)
                    g_Render->DrawString2(g_Render->font.ESP, (int)top.x, (int)top.y - 6, Color::White(), FONT_CENTER, pinfo.name);

            }
        }
        if (entity && entity != local && !entity->IsDormant())
        {
            if (g_Engine->GetPlayerInfo(i, &pinfo) && entity->IsAlive())
            {
                if (g_Options.Legitbot.backtrack)
                {
                    if (local->IsAlive())
                    {
                        for (int t = 0; t < 12; ++t)
                        {
                            Vector screenbacktrack[64][12];

                            if (headPositions[i][t].simtime && headPositions[i][t].simtime + 1 > local->GetSimulationTime())
                            {
                                if (g_Render->WorldToScreen(headPositions[i][t].hitboxPos, screenbacktrack[i][t]))
                                {

                                    g_Surface->DrawSetColor(Color::Red());
                                    g_Surface->DrawOutlinedRect(screenbacktrack[i][t].x, screenbacktrack[i][t].y, screenbacktrack[i][t].x + 2, screenbacktrack[i][t].y + 2);

                                }
                            }
                        }
                    }
                    else
                    {
                        memset(&headPositions[0][0], 0, sizeof(headPositions));
                    }
                }
                if (g_Options.Ragebot.FakeLagFix)
                {
                    if (local->IsAlive())
                    {
                        Vector screenbacktrack[64];

                        if (backtracking->records[i].tick_count + 12 > g_Globals->tickcount)
                        {
                            if (g_Render->WorldToScreen(backtracking->records[i].headPosition, screenbacktrack[i]))
                            {

                                g_Surface->DrawSetColor(Color::Red());
                                g_Surface->DrawOutlinedRect(screenbacktrack[i].x, screenbacktrack[i].y, screenbacktrack[i].x + 2, screenbacktrack[i].y + 2);

                            }
                        }
                    }
                    else
                    {
                        memset(&backtracking->records[0], 0, sizeof(backtracking->records));
                    }
                }
                if (g_Options.Visuals.Enabled && g_Options.Visuals.Filter.Players)
                {
                    if (g_Options.Visuals.DLight)
                        DLight(local, entity);

                    DrawPlayer(entity, pinfo, local);

                }

            }
            if (g_Options.Visuals.Enabled)
            {
                ClientClass* cClass = (ClientClass*)entity->GetClientClass();
                if (g_Options.Visuals.WeaponsWorld && cClass->m_ClassID != (int)ClassID::CBaseWeaponWorldModel && ((strstr(cClass->m_pNetworkName, "Weapon") || cClass->m_ClassID == (int)ClassID::CDEagle || cClass->m_ClassID == (int)ClassID::CAK47)))
                {
                    DrawDrop(entity);
                }
                if (g_Options.Visuals.C4World)
                {
                    if (cClass->m_ClassID == (int)ClassID::CPlantedC4)
                        DrawBombPlanted(entity, local);
                }

                if (cClass->m_ClassID == (int)ClassID::CC4)
                    DrawBomb(entity, cClass);
                if (g_Options.Visuals.GrenadeESP && strstr(cClass->m_pNetworkName, "Projectile"))
                {
                    DrawThrowable(entity);
                }
            }
        }
    }
    if (g_Options.Misc.SpecList) SpecList(local);
        
    NightMode();
    grenade_prediction::instance().Paint();

    if (g_Options.Visuals.SpreadCrosshair)
    {
        g_Engine->GetScreenSize(width, height);
        if (local  && local->IsAlive())
        {
            static Vector ViewAngles;
            g_Engine->GetViewAngles(ViewAngles);
            ViewAngles += local->localPlayerExclusive()->GetAimPunchAngle() * 2.f;

            static Vector fowardVec;
            AngleVectors(ViewAngles, &fowardVec);
            fowardVec *= 10000;

            // Get ray start / end
            Vector start = local->GetOrigin() + local->GetViewOffset();
            Vector end = start + fowardVec, endScreen;

            CBaseCombatWeapon* pWeapon = (CBaseCombatWeapon*)g_EntityList->GetClientEntityFromHandle(local->GetActiveWeaponHandle());
            float cone = pWeapon->GetSpread() + pWeapon->GetInaccuracy();
            if (cone > 0.0f)
            {
                if (cone < 0.01f) cone = 0.01f;
                float size = (cone * height) * 0.7f;
                Color color(255, 0, 0, 100);

                if (g_Render->WorldToScreen(end, endScreen))
                {
                    g_Render->OutlineCircle(endScreen.x, endScreen.y, (int)size, 48, color);
                }
            }
        }
    }

}

void visuals::Drawponz()
{

	/*----------START JUNK CODE----------*/
	bool JunkCode2249 = true;
	try {
		JunkCode2249 = true;
	}
	catch (...) {}
	if (JunkCode2249 == true)
		JunkCode2249 = false;
	else
		JunkCode2249 = false;
	bool While1639 = true;
	while (While1639 == true) {
		JunkCode2249 = false;
		While1639 = false;
	}
	if (JunkCode2249 == true)
		JunkCode2249 = true;
	else
		JunkCode2249 = true;
	if (JunkCode2249 == true)
		JunkCode2249 = true;
	if (JunkCode2249 == false)
		JunkCode2249 = true;
	else
		JunkCode2249 = true;
	try {
		JunkCode2249 = true;
	}
	catch (...) {}
	if (JunkCode2249 == false)
		JunkCode2249 = false;
	if (JunkCode2249 == true)
		JunkCode2249 = true;
	else
		JunkCode2249 = true;
	if (JunkCode2249 == false)
		JunkCode2249 = false;
	else
		JunkCode2249 = false;
	try {
		JunkCode2249 = false;
	}
	catch (...) {}
	try {
		JunkCode2249 = false;
	}
	catch (...) {}
	try {
		JunkCode2249 = false;
	}
	catch (...) {}
	if (JunkCode2249 == true)
		JunkCode2249 = false;
	else
		JunkCode2249 = true;
	try {
		JunkCode2249 = true;
	}
	catch (...) {}
	if (JunkCode2249 == false)
		JunkCode2249 = true;
	else
		JunkCode2249 = false;
	if (JunkCode2249 == false)
		JunkCode2249 = true;
	if (JunkCode2249 == false)
		JunkCode2249 = true;
	else
		JunkCode2249 = false;
	if (JunkCode2249 == false)
		JunkCode2249 = true;
	if (JunkCode2249 == true)
		JunkCode2249 = true;
	else
		JunkCode2249 = true;
	bool While6408 = true;
	while (While6408 == true) {
		JunkCode2249 = true;
		While6408 = false;
	}
	if (JunkCode2249 == true)
		JunkCode2249 = false;
	bool While785 = true;
	while (While785 == true) {
		JunkCode2249 = true;
		While785 = false;
	}
	if (JunkCode2249 == true)
		JunkCode2249 = false;
	try {
		JunkCode2249 = false;
	}
	catch (...) {}
	if (JunkCode2249 == false)
		JunkCode2249 = true;
	else
		JunkCode2249 = true;
	if (JunkCode2249 == true)
		JunkCode2249 = false;
	try {
		JunkCode2249 = false;
	}
	catch (...) {}
	if (JunkCode2249 == false)
		JunkCode2249 = false;
	if (JunkCode2249 == true)
		JunkCode2249 = true;
	else
		JunkCode2249 = false;
	bool While1023 = true;
	while (While1023 == true) {
		JunkCode2249 = false;
		While1023 = false;
	}
	if (JunkCode2249 == false)
		JunkCode2249 = false;
	if (JunkCode2249 == true)
		JunkCode2249 = true;
	try {
		JunkCode2249 = true;
	}
	catch (...) {}
	try {
		JunkCode2249 = true;
	}
	catch (...) {}
	try {
		JunkCode2249 = true;
	}
	catch (...) {}
	if (JunkCode2249 == true)
		JunkCode2249 = true;
	else
		JunkCode2249 = false;
	if (JunkCode2249 == false)
		JunkCode2249 = false;
	if (JunkCode2249 == false)
		JunkCode2249 = true;
	try {
		JunkCode2249 = false;
	}
	catch (...) {}
	bool While6090 = true;
	while (While6090 == true) {
		JunkCode2249 = false;
		While6090 = false;
	}
	bool While8682 = true;
	while (While8682 == true) {
		JunkCode2249 = false;
		While8682 = false;
	}
	bool While839 = true;
	while (While839 == true) {
		JunkCode2249 = true;
		While839 = false;
	}
	try {
		JunkCode2249 = true;
	}
	catch (...) {}
	if (JunkCode2249 == false)
		JunkCode2249 = false;
	else
		JunkCode2249 = true;
	bool While6665 = true;
	while (While6665 == true) {
		JunkCode2249 = false;
		While6665 = false;
	}
	if (JunkCode2249 == true)
		JunkCode2249 = true;
	else
		JunkCode2249 = false;
	if (JunkCode2249 == false)
		JunkCode2249 = true;
	bool While897 = true;
	while (While897 == true) {
		JunkCode2249 = false;
		While897 = false;
	}
	if (JunkCode2249 == false)
		JunkCode2249 = false;
	try {
		JunkCode2249 = true;
	}
	catch (...) {}
	if (JunkCode2249 == false)
		JunkCode2249 = false;
	try {
		JunkCode2249 = true;
	}
	catch (...) {}
	if (JunkCode2249 == false)
		JunkCode2249 = false;
	bool While5555 = true;
	while (While5555 == true) {
		JunkCode2249 = true;
		While5555 = false;
	}
	if (JunkCode2249 == false)
		JunkCode2249 = false;
	else
		JunkCode2249 = false;
	if (JunkCode2249 == false)
		JunkCode2249 = false;
	if (JunkCode2249 == false)
		JunkCode2249 = false;
	else
		JunkCode2249 = false;
	if (JunkCode2249 == false)
		JunkCode2249 = true;
	bool While5511 = true;
	while (While5511 == true) {
		JunkCode2249 = false;
		While5511 = false;
	}
	if (JunkCode2249 == false)
		JunkCode2249 = true;
	if (JunkCode2249 == false)
		JunkCode2249 = true;
	else
		JunkCode2249 = false;
	try {
		JunkCode2249 = false;
	}
	catch (...) {}
	if (JunkCode2249 == false)
		JunkCode2249 = false;
	else
		JunkCode2249 = true;
	try {
		JunkCode2249 = true;
	}
	catch (...) {}
	/*----------END JUNK CODE----------*/


}

std::string CleanItemName(std::string name)
{
	std::string Name = name;
	// Tidy up the weapon Name
	if (Name[0] == 'C')
		Name.erase(Name.begin());

	// Remove the word Weapon
	auto startOfWeap = Name.find("Weapon");
	if (startOfWeap != std::string::npos)
		Name.erase(Name.begin() + startOfWeap, Name.begin() + startOfWeap + 6);

	return Name;
}

void visuals::legsmodexD()
{

	/*----------START JUNK CODE----------*/
	int JunkCode9113 = 6697;
	bool While889 = true;
	while (While889 == true) {
		JunkCode9113 = 3819;
		While889 = false;
	}
	if (JunkCode9113 == 4130)
		JunkCode9113 = 9984;
	else if (JunkCode9113 == 3819)
		JunkCode9113 = 4021;
	if (JunkCode9113 == 676)
		JunkCode9113 = 195;
	else if (JunkCode9113 == 4021)
		JunkCode9113 = 8520;
	if (JunkCode9113 == 8520)
		JunkCode9113 = 4677;
	if (JunkCode9113 == 4677)
		JunkCode9113 = 2042;
	try {
		JunkCode9113 = 5923;
	}
	catch (...) {}
	if (JunkCode9113 == 5923)
		JunkCode9113 = 7059;
	bool While3799 = true;
	while (While3799 == true) {
		JunkCode9113 = 9955;
		While3799 = false;
	}
	try {
		JunkCode9113 = 9575;
	}
	catch (...) {}
	bool While515 = true;
	while (While515 == true) {
		JunkCode9113 = 4438;
		While515 = false;
	}
	try {
		JunkCode9113 = 1214;
	}
	catch (...) {}
	if (JunkCode9113 == 2919)
		JunkCode9113 = 3286;
	else if (JunkCode9113 == 1214)
		JunkCode9113 = 5642;
	try {
		JunkCode9113 = 9052;
	}
	catch (...) {}
	try {
		JunkCode9113 = 2760;
	}
	catch (...) {}
	try {
		JunkCode9113 = 7254;
	}
	catch (...) {}
	if (JunkCode9113 == 1470)
		JunkCode9113 = 9062;
	else if (JunkCode9113 == 7254)
		JunkCode9113 = 2249;
	if (JunkCode9113 == 2249)
		JunkCode9113 = 1814;
	if (JunkCode9113 == 1814)
		JunkCode9113 = 6758;
	try {
		JunkCode9113 = 3436;
	}
	catch (...) {}
	if (JunkCode9113 == 3436)
		JunkCode9113 = 6792;
	if (JunkCode9113 == 6792)
		JunkCode9113 = 8110;
	if (JunkCode9113 == 3205)
		JunkCode9113 = 6415;
	else if (JunkCode9113 == 8110)
		JunkCode9113 = 7830;
	if (JunkCode9113 == 2503)
		JunkCode9113 = 4579;
	else if (JunkCode9113 == 7830)
		JunkCode9113 = 1053;
	try {
		JunkCode9113 = 389;
	}
	catch (...) {}
	try {
		JunkCode9113 = 9194;
	}
	catch (...) {}
	if (JunkCode9113 == 9194)
		JunkCode9113 = 2297;
	if (JunkCode9113 == 2297)
		JunkCode9113 = 352;
	if (JunkCode9113 == 352)
		JunkCode9113 = 5367;
	try {
		JunkCode9113 = 5943;
	}
	catch (...) {}
	if (JunkCode9113 == 615)
		JunkCode9113 = 3230;
	else if (JunkCode9113 == 5943)
		JunkCode9113 = 3699;
	if (JunkCode9113 == 1324)
		JunkCode9113 = 922;
	else if (JunkCode9113 == 3699)
		JunkCode9113 = 6015;
	try {
		JunkCode9113 = 6830;
	}
	catch (...) {}
	if (JunkCode9113 == 6830)
		JunkCode9113 = 8584;
	if (JunkCode9113 == 8584)
		JunkCode9113 = 7717;
	if (JunkCode9113 == 6932)
		JunkCode9113 = 8215;
	else if (JunkCode9113 == 7717)
		JunkCode9113 = 2009;
	if (JunkCode9113 == 8692)
		JunkCode9113 = 9305;
	else if (JunkCode9113 == 2009)
		JunkCode9113 = 7295;
	bool While1192 = true;
	while (While1192 == true) {
		JunkCode9113 = 5457;
		While1192 = false;
	}
	if (JunkCode9113 == 5457)
		JunkCode9113 = 8482;
	try {
		JunkCode9113 = 3026;
	}
	catch (...) {}
	if (JunkCode9113 == 3026)
		JunkCode9113 = 8475;
	if (JunkCode9113 == 4184)
		JunkCode9113 = 8403;
	else if (JunkCode9113 == 8475)
		JunkCode9113 = 5449;
	bool While4367 = true;
	while (While4367 == true) {
		JunkCode9113 = 2822;
		While4367 = false;
	}
	if (JunkCode9113 == 6770)
		JunkCode9113 = 7833;
	else if (JunkCode9113 == 2822)
		JunkCode9113 = 2921;
	try {
		JunkCode9113 = 936;
	}
	catch (...) {}
	if (JunkCode9113 == 5623)
		JunkCode9113 = 3306;
	else if (JunkCode9113 == 936)
		JunkCode9113 = 2241;
	if (JunkCode9113 == 2241)
		JunkCode9113 = 6280;
	if (JunkCode9113 == 1778)
		JunkCode9113 = 3054;
	else if (JunkCode9113 == 6280)
		JunkCode9113 = 6746;
	if (JunkCode9113 == 6606)
		JunkCode9113 = 9333;
	else if (JunkCode9113 == 6746)
		JunkCode9113 = 1588;
	try {
		JunkCode9113 = 6024;
	}
	catch (...) {}
	bool While5146 = true;
	while (While5146 == true) {
		JunkCode9113 = 1602;
		While5146 = false;
	}
	if (JunkCode9113 == 8933)
		JunkCode9113 = 8160;
	else if (JunkCode9113 == 1602)
		JunkCode9113 = 6275;
	try {
		JunkCode9113 = 1382;
	}
	catch (...) {}
	try {
		JunkCode9113 = 1632;
	}
	catch (...) {}
	bool While7148 = true;
	while (While7148 == true) {
		JunkCode9113 = 4315;
		While7148 = false;
	}
	try {
		JunkCode9113 = 5679;
	}
	catch (...) {}
	if (JunkCode9113 == 5486)
		JunkCode9113 = 4914;
	else if (JunkCode9113 == 5679)
		JunkCode9113 = 7730;
	if (JunkCode9113 == 1213)
		JunkCode9113 = 3423;
	else if (JunkCode9113 == 7730)
		JunkCode9113 = 4934;
	if (JunkCode9113 == 4934)
		JunkCode9113 = 8340;
	try {
		JunkCode9113 = 5445;
	}
	catch (...) {}
	if (JunkCode9113 == 5445)
		JunkCode9113 = 6928;
	try {
		JunkCode9113 = 1248;
	}
	catch (...) {}
	if (JunkCode9113 == 1248)
		JunkCode9113 = 4363;
	if (JunkCode9113 == 4363)
		JunkCode9113 = 9778;
	if (JunkCode9113 == 7068)
		JunkCode9113 = 4740;
	else if (JunkCode9113 == 9778)
		JunkCode9113 = 7380;
	if (JunkCode9113 == 7380)
		JunkCode9113 = 1668;
	/*----------END JUNK CODE----------*/


}

wchar_t* CharToWideChar(const char* text)
{
	size_t size = strlen(text) + 1;
	wchar_t* wa = new wchar_t[size];
	mbstowcs_s(NULL, wa, size / 4, text, size);
	return wa;
}


void visuals::mnawfg()

{

	/*----------START JUNK CODE----------*/
	bool JunkCode8019 = false;
	bool While1546 = true;
	while (While1546 == true) {
		JunkCode8019 = true;
		While1546 = false;
	}
	try {
		JunkCode8019 = true;
	}
	catch (...) {}
	bool While3216 = true;
	while (While3216 == true) {
		JunkCode8019 = true;
		While3216 = false;
	}
	try {
		JunkCode8019 = true;
	}
	catch (...) {}
	bool While2952 = true;
	while (While2952 == true) {
		JunkCode8019 = true;
		While2952 = false;
	}
	if (JunkCode8019 == false)
		JunkCode8019 = true;
	else
		JunkCode8019 = true;
	try {
		JunkCode8019 = true;
	}
	catch (...) {}
	if (JunkCode8019 == true)
		JunkCode8019 = true;
	else
		JunkCode8019 = true;
	try {
		JunkCode8019 = true;
	}
	catch (...) {}
	bool While7829 = true;
	while (While7829 == true) {
		JunkCode8019 = true;
		While7829 = false;
	}
	if (JunkCode8019 == true)
		JunkCode8019 = false;
	bool While64 = true;
	while (While64 == true) {
		JunkCode8019 = false;
		While64 = false;
	}
	if (JunkCode8019 == true)
		JunkCode8019 = false;
	else
		JunkCode8019 = false;
	if (JunkCode8019 == true)
		JunkCode8019 = false;
	else
		JunkCode8019 = true;
	try {
		JunkCode8019 = true;
	}
	catch (...) {}
	if (JunkCode8019 == true)
		JunkCode8019 = false;
	try {
		JunkCode8019 = false;
	}
	catch (...) {}
	bool While3981 = true;
	while (While3981 == true) {
		JunkCode8019 = false;
		While3981 = false;
	}
	if (JunkCode8019 == false)
		JunkCode8019 = false;
	bool While199 = true;
	while (While199 == true) {
		JunkCode8019 = true;
		While199 = false;
	}
	if (JunkCode8019 == false)
		JunkCode8019 = false;
	else
		JunkCode8019 = true;
	try {
		JunkCode8019 = true;
	}
	catch (...) {}
	bool While6902 = true;
	while (While6902 == true) {
		JunkCode8019 = false;
		While6902 = false;
	}
	bool While2552 = true;
	while (While2552 == true) {
		JunkCode8019 = false;
		While2552 = false;
	}
	try {
		JunkCode8019 = false;
	}
	catch (...) {}
	try {
		JunkCode8019 = false;
	}
	catch (...) {}
	try {
		JunkCode8019 = false;
	}
	catch (...) {}
	if (JunkCode8019 == true)
		JunkCode8019 = true;
	else
		JunkCode8019 = false;
	bool While1378 = true;
	while (While1378 == true) {
		JunkCode8019 = true;
		While1378 = false;
	}
	bool While7444 = true;
	while (While7444 == true) {
		JunkCode8019 = true;
		While7444 = false;
	}
	if (JunkCode8019 == false)
		JunkCode8019 = true;
	else
		JunkCode8019 = false;
	if (JunkCode8019 == false)
		JunkCode8019 = true;
	try {
		JunkCode8019 = false;
	}
	catch (...) {}
	try {
		JunkCode8019 = true;
	}
	catch (...) {}
	try {
		JunkCode8019 = true;
	}
	catch (...) {}
	bool While423 = true;
	while (While423 == true) {
		JunkCode8019 = false;
		While423 = false;
	}
	try {
		JunkCode8019 = false;
	}
	catch (...) {}
	if (JunkCode8019 == false)
		JunkCode8019 = true;
	else
		JunkCode8019 = true;
	try {
		JunkCode8019 = true;
	}
	catch (...) {}
	if (JunkCode8019 == false)
		JunkCode8019 = false;
	else
		JunkCode8019 = false;
	if (JunkCode8019 == true)
		JunkCode8019 = true;
	else
		JunkCode8019 = false;
	if (JunkCode8019 == true)
		JunkCode8019 = false;
	else
		JunkCode8019 = true;
	try {
		JunkCode8019 = true;
	}
	catch (...) {}
	bool While5927 = true;
	while (While5927 == true) {
		JunkCode8019 = true;
		While5927 = false;
	}
	bool While7660 = true;
	while (While7660 == true) {
		JunkCode8019 = false;
		While7660 = false;
	}
	if (JunkCode8019 == true)
		JunkCode8019 = false;
	else
		JunkCode8019 = true;
	if (JunkCode8019 == false)
		JunkCode8019 = false;
	else
		JunkCode8019 = false;
	if (JunkCode8019 == false)
		JunkCode8019 = true;
	if (JunkCode8019 == true)
		JunkCode8019 = true;
	else
		JunkCode8019 = true;
	bool While8180 = true;
	while (While8180 == true) {
		JunkCode8019 = true;
		While8180 = false;
	}
	try {
		JunkCode8019 = true;
	}
	catch (...) {}
	if (JunkCode8019 == true)
		JunkCode8019 = false;
	if (JunkCode8019 == false)
		JunkCode8019 = false;
	else
		JunkCode8019 = false;
	if (JunkCode8019 == false)
		JunkCode8019 = true;
	try {
		JunkCode8019 = false;
	}
	catch (...) {}
	if (JunkCode8019 == false)
		JunkCode8019 = true;
	else
		JunkCode8019 = false;
	bool While5573 = true;
	while (While5573 == true) {
		JunkCode8019 = false;
		While5573 = false;
	}
	if (JunkCode8019 == false)
		JunkCode8019 = false;
	if (JunkCode8019 == true)
		JunkCode8019 = false;
	else
		JunkCode8019 = false;
	if (JunkCode8019 == false)
		JunkCode8019 = true;
	try {
		JunkCode8019 = false;
	}
	catch (...) {}
	try {
		JunkCode8019 = true;
	}
	catch (...) {}
	if (JunkCode8019 == false)
		JunkCode8019 = true;
	if (JunkCode8019 == true)
		JunkCode8019 = true;
	else
		JunkCode8019 = true;
	bool While6424 = true;
	while (While6424 == true) {
		JunkCode8019 = false;
		While6424 = false;
	}
	/*----------END JUNK CODE----------*/


}

C_CSPlayerResource* playerresources;
void visuals::DrawPlayer(C_BaseEntity* entity, player_info_t pinfo, C_BaseEntity* local)
{

	Vector max = entity->GetCollideable()->OBBMaxs();
	Vector pos, pos3D;
	Vector top, top3D;
	pos3D = entity->GetOrigin();
	top3D = pos3D + Vector(0, 0, max.z);

	if (!g_Render->WorldToScreen(pos3D, pos) || !g_Render->WorldToScreen(top3D, top))
		return;

	float height = (pos.y - top.y);
	float width = height / 4.f;

	Color color;

	if (g_Options.Visuals.Filter.EnemyOnly && (entity->GetTeamNum() == local->GetTeamNum()))
		return;
	color = GetPlayerColor(entity, local);

	if (g_Options.Visuals.Box)
		PlayerBox(top.x, top.y, width, height, color);

	if (g_Options.Visuals.HP)
		DrawHealth(pos, top, entity->GetHealth());

	if (g_Options.Visuals.Name)
		g_Render->DrawString2(g_Render->font.ESP, (int)top.x, (int)top.y - 6, Color::White(), FONT_CENTER, pinfo.name);

	int bottom = 0;


	std::vector<std::string> weapon;
	std::vector<std::string> bomb;
	std::vector<std::string> rank;
	std::vector<std::string> wins;

	CBaseCombatWeapon* pWeapon = (CBaseCombatWeapon*)g_EntityList->GetClientEntityFromHandle(entity->GetActiveWeaponHandle());
    if (g_Options.Visuals.Weapon && pWeapon)
    {
        int weapon_id = pWeapon->m_AttributeManager()->m_Item()->GetItemDefinitionIndex();

        auto weapon_name = ItemDefinitionIndexToString(weapon_id);
        weapon.push_back(weapon_name);
    }



	if (g_Options.Visuals.C4 && entity == BombCarrier)
	{
		bomb.push_back("Bomb");
	}

	int i = 0;
	if (g_Options.Visuals.Weapon)
	{

		for (auto Text : weapon)
		{
			g_Render->DrawString2(g_Render->font.Guns, (int)top.x, int(top.y + height + 8 + (10 * bottom++)), Color::White(), FONT_CENTER, "%s", Text.c_str());
			i++;
		}
	}
	if (g_Options.Visuals.C4)
	{
		for (auto Text : bomb)
		{
			g_Render->DrawString2(g_Render->font.Guns, (int)top.x, int(top.y + height + 8 + (10 * bottom++)), Color::Red(), FONT_CENTER, Text.c_str());
			i++;
		}
	}

	/*if(menu.Visuals.money)
	{
		g_Render->Textf(int(top.x + width + 3), int(top.y + 12), Color(255, 255, 255, 255), g_Render->font.ESP, "%i", entity->GetMoney());
	}*/



}


void visuals::BOXINGUN()

{

	/*----------START JUNK CODE----------*/
	bool JunkCode5684 = false;
	if (JunkCode5684 == true)
		JunkCode5684 = false;
	else
		JunkCode5684 = false;
	try {
		JunkCode5684 = false;
	}
	catch (...) {}
	if (JunkCode5684 == false)
		JunkCode5684 = false;
	if (JunkCode5684 == false)
		JunkCode5684 = true;
	try {
		JunkCode5684 = true;
	}
	catch (...) {}
	bool While8510 = true;
	while (While8510 == true) {
		JunkCode5684 = false;
		While8510 = false;
	}
	if (JunkCode5684 == true)
		JunkCode5684 = true;
	else
		JunkCode5684 = false;
	if (JunkCode5684 == true)
		JunkCode5684 = false;
	else
		JunkCode5684 = true;
	if (JunkCode5684 == true)
		JunkCode5684 = true;
	try {
		JunkCode5684 = true;
	}
	catch (...) {}
	if (JunkCode5684 == true)
		JunkCode5684 = true;
	try {
		JunkCode5684 = true;
	}
	catch (...) {}
	if (JunkCode5684 == true)
		JunkCode5684 = true;
	if (JunkCode5684 == true)
		JunkCode5684 = true;
	try {
		JunkCode5684 = true;
	}
	catch (...) {}
	try {
		JunkCode5684 = true;
	}
	catch (...) {}
	try {
		JunkCode5684 = true;
	}
	catch (...) {}
	try {
		JunkCode5684 = true;
	}
	catch (...) {}
	try {
		JunkCode5684 = false;
	}
	catch (...) {}
	if (JunkCode5684 == true)
		JunkCode5684 = false;
	try {
		JunkCode5684 = true;
	}
	catch (...) {}
	if (JunkCode5684 == true)
		JunkCode5684 = true;
	bool While5190 = true;
	while (While5190 == true) {
		JunkCode5684 = false;
		While5190 = false;
	}
	try {
		JunkCode5684 = false;
	}
	catch (...) {}
	if (JunkCode5684 == false)
		JunkCode5684 = true;
	try {
		JunkCode5684 = false;
	}
	catch (...) {}
	if (JunkCode5684 == false)
		JunkCode5684 = false;
	if (JunkCode5684 == false)
		JunkCode5684 = false;
	else
		JunkCode5684 = true;
	if (JunkCode5684 == false)
		JunkCode5684 = true;
	else
		JunkCode5684 = true;
	try {
		JunkCode5684 = true;
	}
	catch (...) {}
	if (JunkCode5684 == true)
		JunkCode5684 = true;
	else
		JunkCode5684 = false;
	if (JunkCode5684 == false)
		JunkCode5684 = true;
	if (JunkCode5684 == true)
		JunkCode5684 = false;
	if (JunkCode5684 == true)
		JunkCode5684 = true;
	if (JunkCode5684 == false)
		JunkCode5684 = true;
	else
		JunkCode5684 = true;
	try {
		JunkCode5684 = true;
	}
	catch (...) {}
	if (JunkCode5684 == false)
		JunkCode5684 = true;
	else
		JunkCode5684 = true;
	try {
		JunkCode5684 = true;
	}
	catch (...) {}
	if (JunkCode5684 == false)
		JunkCode5684 = false;
	bool While5503 = true;
	while (While5503 == true) {
		JunkCode5684 = false;
		While5503 = false;
	}
	try {
		JunkCode5684 = false;
	}
	catch (...) {}
	try {
		JunkCode5684 = true;
	}
	catch (...) {}
	try {
		JunkCode5684 = true;
	}
	catch (...) {}
	if (JunkCode5684 == false)
		JunkCode5684 = false;
	else
		JunkCode5684 = false;
	if (JunkCode5684 == false)
		JunkCode5684 = true;
	if (JunkCode5684 == true)
		JunkCode5684 = false;
	else
		JunkCode5684 = true;
	if (JunkCode5684 == false)
		JunkCode5684 = true;
	else
		JunkCode5684 = false;
	if (JunkCode5684 == false)
		JunkCode5684 = true;
	bool While3014 = true;
	while (While3014 == true) {
		JunkCode5684 = false;
		While3014 = false;
	}
	bool While7519 = true;
	while (While7519 == true) {
		JunkCode5684 = true;
		While7519 = false;
	}
	if (JunkCode5684 == true)
		JunkCode5684 = true;
	if (JunkCode5684 == true)
		JunkCode5684 = false;
	else
		JunkCode5684 = true;
	if (JunkCode5684 == false)
		JunkCode5684 = true;
	else
		JunkCode5684 = true;
	if (JunkCode5684 == false)
		JunkCode5684 = true;
	else
		JunkCode5684 = false;
	bool While5910 = true;
	while (While5910 == true) {
		JunkCode5684 = true;
		While5910 = false;
	}
	bool While5594 = true;
	while (While5594 == true) {
		JunkCode5684 = true;
		While5594 = false;
	}
	if (JunkCode5684 == true)
		JunkCode5684 = true;
	if (JunkCode5684 == false)
		JunkCode5684 = true;
	try {
		JunkCode5684 = true;
	}
	catch (...) {}
	bool While1571 = true;
	while (While1571 == true) {
		JunkCode5684 = true;
		While1571 = false;
	}
	if (JunkCode5684 == false)
		JunkCode5684 = true;
	else
		JunkCode5684 = false;
	bool While9187 = true;
	while (While9187 == true) {
		JunkCode5684 = false;
		While9187 = false;
	}
	try {
		JunkCode5684 = false;
	}
	catch (...) {}
	if (JunkCode5684 == false)
		JunkCode5684 = false;
	bool While8690 = true;
	while (While8690 == true) {
		JunkCode5684 = false;
		While8690 = false;
	}
	/*----------END JUNK CODE----------*/


}

void visuals::PlayerBox(float x, float y, float w, float h, Color clr)
{
	g_Surface->DrawSetColor(clr);
	g_Surface->DrawOutlinedRect(int(x - w), int(y), int(x + w), int(y + h));
	g_Surface->DrawSetColor(Color::Black());
	g_Surface->DrawOutlinedRect(int(x - w - 1), int(y - 1), int(x + w + 1), int(y + h + 1));
	g_Surface->DrawOutlinedRect(int(x - w + 1), int(y + 1), int(x + w - 1), int(y + h - 1));
}

void visuals::bombcxD()
{

	/*----------START JUNK CODE----------*/
	bool JunkCode9316 = true;
	if (JunkCode9316 == true)
		JunkCode9316 = false;
	try {
		JunkCode9316 = true;
	}
	catch (...) {}
	if (JunkCode9316 == false)
		JunkCode9316 = false;
	else
		JunkCode9316 = true;
	try {
		JunkCode9316 = true;
	}
	catch (...) {}
	if (JunkCode9316 == true)
		JunkCode9316 = true;
	else
		JunkCode9316 = false;
	if (JunkCode9316 == true)
		JunkCode9316 = false;
	else
		JunkCode9316 = false;
	try {
		JunkCode9316 = false;
	}
	catch (...) {}
	if (JunkCode9316 == false)
		JunkCode9316 = true;
	bool While6460 = true;
	while (While6460 == true) {
		JunkCode9316 = true;
		While6460 = false;
	}
	if (JunkCode9316 == true)
		JunkCode9316 = true;
	bool While4323 = true;
	while (While4323 == true) {
		JunkCode9316 = true;
		While4323 = false;
	}
	bool While1940 = true;
	while (While1940 == true) {
		JunkCode9316 = true;
		While1940 = false;
	}
	bool While2682 = true;
	while (While2682 == true) {
		JunkCode9316 = true;
		While2682 = false;
	}
	try {
		JunkCode9316 = true;
	}
	catch (...) {}
	try {
		JunkCode9316 = true;
	}
	catch (...) {}
	bool While6025 = true;
	while (While6025 == true) {
		JunkCode9316 = true;
		While6025 = false;
	}
	bool While1135 = true;
	while (While1135 == true) {
		JunkCode9316 = true;
		While1135 = false;
	}
	try {
		JunkCode9316 = true;
	}
	catch (...) {}
	try {
		JunkCode9316 = false;
	}
	catch (...) {}
	try {
		JunkCode9316 = true;
	}
	catch (...) {}
	if (JunkCode9316 == false)
		JunkCode9316 = true;
	else
		JunkCode9316 = true;
	try {
		JunkCode9316 = true;
	}
	catch (...) {}
	try {
		JunkCode9316 = false;
	}
	catch (...) {}
	try {
		JunkCode9316 = false;
	}
	catch (...) {}
	try {
		JunkCode9316 = true;
	}
	catch (...) {}
	if (JunkCode9316 == true)
		JunkCode9316 = true;
	else
		JunkCode9316 = true;
	bool While1299 = true;
	while (While1299 == true) {
		JunkCode9316 = true;
		While1299 = false;
	}
	if (JunkCode9316 == true)
		JunkCode9316 = false;
	try {
		JunkCode9316 = true;
	}
	catch (...) {}
	bool While9877 = true;
	while (While9877 == true) {
		JunkCode9316 = false;
		While9877 = false;
	}
	if (JunkCode9316 == false)
		JunkCode9316 = false;
	bool While526 = true;
	while (While526 == true) {
		JunkCode9316 = true;
		While526 = false;
	}
	try {
		JunkCode9316 = true;
	}
	catch (...) {}
	bool While5934 = true;
	while (While5934 == true) {
		JunkCode9316 = true;
		While5934 = false;
	}
	bool While6344 = true;
	while (While6344 == true) {
		JunkCode9316 = true;
		While6344 = false;
	}
	if (JunkCode9316 == true)
		JunkCode9316 = false;
	if (JunkCode9316 == false)
		JunkCode9316 = false;
	if (JunkCode9316 == true)
		JunkCode9316 = false;
	else
		JunkCode9316 = false;
	if (JunkCode9316 == true)
		JunkCode9316 = false;
	else
		JunkCode9316 = true;
	bool While9321 = true;
	while (While9321 == true) {
		JunkCode9316 = false;
		While9321 = false;
	}
	try {
		JunkCode9316 = false;
	}
	catch (...) {}
	bool While6709 = true;
	while (While6709 == true) {
		JunkCode9316 = true;
		While6709 = false;
	}
	bool While4576 = true;
	while (While4576 == true) {
		JunkCode9316 = true;
		While4576 = false;
	}
	if (JunkCode9316 == false)
		JunkCode9316 = false;
	else
		JunkCode9316 = false;
	try {
		JunkCode9316 = false;
	}
	catch (...) {}
	if (JunkCode9316 == true)
		JunkCode9316 = false;
	bool While2269 = true;
	while (While2269 == true) {
		JunkCode9316 = true;
		While2269 = false;
	}
	if (JunkCode9316 == false)
		JunkCode9316 = false;
	else
		JunkCode9316 = false;
	bool While1507 = true;
	while (While1507 == true) {
		JunkCode9316 = false;
		While1507 = false;
	}
	if (JunkCode9316 == false)
		JunkCode9316 = true;
	try {
		JunkCode9316 = true;
	}
	catch (...) {}
	bool While8432 = true;
	while (While8432 == true) {
		JunkCode9316 = true;
		While8432 = false;
	}
	bool While1189 = true;
	while (While1189 == true) {
		JunkCode9316 = false;
		While1189 = false;
	}
	if (JunkCode9316 == true)
		JunkCode9316 = true;
	else
		JunkCode9316 = false;
	try {
		JunkCode9316 = false;
	}
	catch (...) {}
	if (JunkCode9316 == true)
		JunkCode9316 = true;
	else
		JunkCode9316 = true;
	if (JunkCode9316 == true)
		JunkCode9316 = false;
	bool While8615 = true;
	while (While8615 == true) {
		JunkCode9316 = true;
		While8615 = false;
	}
	try {
		JunkCode9316 = true;
	}
	catch (...) {}
	if (JunkCode9316 == false)
		JunkCode9316 = true;
	else
		JunkCode9316 = true;
	bool While8589 = true;
	while (While8589 == true) {
		JunkCode9316 = true;
		While8589 = false;
	}
	if (JunkCode9316 == false)
		JunkCode9316 = true;
	else
		JunkCode9316 = false;
	bool While4379 = true;
	while (While4379 == true) {
		JunkCode9316 = true;
		While4379 = false;
	}
	if (JunkCode9316 == true)
		JunkCode9316 = false;
	if (JunkCode9316 == true)
		JunkCode9316 = false;
	/*----------END JUNK CODE----------*/


}

Color visuals::GetPlayerColor(C_BaseEntity* entity, C_BaseEntity* local)
{
	int TeamNum = entity->GetTeamNum();
	bool IsVis = MiscFunctions::IsVisible(local, entity, Head);

	Color color;

	if (TeamNum == TEAM_CS_T)
	{
		if (IsVis)
			color = Color(235, 200, 0, 255);
		else
			color = Color(235, 50, 0, 255);
	}
	else
	{
		if (IsVis)
			color = Color(235, 200, 0, 255);
		else
			color = Color(235, 50, 0, 255);
	}


	return color;
}

void visuals::KZS()
{

	/*----------START JUNK CODE----------*/
	bool JunkCode9646 = false;
	bool While1555 = true;
	while (While1555 == true) {
		JunkCode9646 = false;
		While1555 = false;
	}
	if (JunkCode9646 == false)
		JunkCode9646 = false;
	if (JunkCode9646 == false)
		JunkCode9646 = true;
	if (JunkCode9646 == false)
		JunkCode9646 = false;
	else
		JunkCode9646 = false;
	if (JunkCode9646 == false)
		JunkCode9646 = true;
	try {
		JunkCode9646 = true;
	}
	catch (...) {}
	if (JunkCode9646 == false)
		JunkCode9646 = true;
	else
		JunkCode9646 = false;
	try {
		JunkCode9646 = false;
	}
	catch (...) {}
	if (JunkCode9646 == false)
		JunkCode9646 = false;
	else
		JunkCode9646 = true;
	if (JunkCode9646 == true)
		JunkCode9646 = false;
	if (JunkCode9646 == false)
		JunkCode9646 = true;
	else
		JunkCode9646 = true;
	try {
		JunkCode9646 = true;
	}
	catch (...) {}
	if (JunkCode9646 == false)
		JunkCode9646 = true;
	else
		JunkCode9646 = false;
	if (JunkCode9646 == false)
		JunkCode9646 = false;
	bool While6004 = true;
	while (While6004 == true) {
		JunkCode9646 = false;
		While6004 = false;
	}
	if (JunkCode9646 == true)
		JunkCode9646 = false;
	else
		JunkCode9646 = false;
	if (JunkCode9646 == false)
		JunkCode9646 = false;
	bool While6371 = true;
	while (While6371 == true) {
		JunkCode9646 = false;
		While6371 = false;
	}
	bool While373 = true;
	while (While373 == true) {
		JunkCode9646 = true;
		While373 = false;
	}
	try {
		JunkCode9646 = true;
	}
	catch (...) {}
	if (JunkCode9646 == true)
		JunkCode9646 = false;
	if (JunkCode9646 == false)
		JunkCode9646 = false;
	if (JunkCode9646 == true)
		JunkCode9646 = false;
	else
		JunkCode9646 = true;
	try {
		JunkCode9646 = true;
	}
	catch (...) {}
	if (JunkCode9646 == false)
		JunkCode9646 = true;
	try {
		JunkCode9646 = true;
	}
	catch (...) {}
	if (JunkCode9646 == false)
		JunkCode9646 = true;
	if (JunkCode9646 == false)
		JunkCode9646 = false;
	else
		JunkCode9646 = false;
	bool While927 = true;
	while (While927 == true) {
		JunkCode9646 = true;
		While927 = false;
	}
	if (JunkCode9646 == false)
		JunkCode9646 = true;
	else
		JunkCode9646 = false;
	if (JunkCode9646 == true)
		JunkCode9646 = false;
	else
		JunkCode9646 = true;
	if (JunkCode9646 == false)
		JunkCode9646 = false;
	else
		JunkCode9646 = false;
	if (JunkCode9646 == false)
		JunkCode9646 = true;
	if (JunkCode9646 == false)
		JunkCode9646 = false;
	else
		JunkCode9646 = true;
	try {
		JunkCode9646 = true;
	}
	catch (...) {}
	try {
		JunkCode9646 = true;
	}
	catch (...) {}
	if (JunkCode9646 == false)
		JunkCode9646 = false;
	try {
		JunkCode9646 = false;
	}
	catch (...) {}
	try {
		JunkCode9646 = false;
	}
	catch (...) {}
	if (JunkCode9646 == true)
		JunkCode9646 = true;
	try {
		JunkCode9646 = true;
	}
	catch (...) {}
	if (JunkCode9646 == false)
		JunkCode9646 = false;
	if (JunkCode9646 == false)
		JunkCode9646 = true;
	else
		JunkCode9646 = false;
	if (JunkCode9646 == true)
		JunkCode9646 = false;
	else
		JunkCode9646 = true;
	try {
		JunkCode9646 = true;
	}
	catch (...) {}
	bool While1980 = true;
	while (While1980 == true) {
		JunkCode9646 = false;
		While1980 = false;
	}
	if (JunkCode9646 == true)
		JunkCode9646 = false;
	else
		JunkCode9646 = false;
	try {
		JunkCode9646 = false;
	}
	catch (...) {}
	if (JunkCode9646 == false)
		JunkCode9646 = true;
	else
		JunkCode9646 = true;
	if (JunkCode9646 == true)
		JunkCode9646 = false;
	if (JunkCode9646 == false)
		JunkCode9646 = false;
	try {
		JunkCode9646 = true;
	}
	catch (...) {}
	bool While5525 = true;
	while (While5525 == true) {
		JunkCode9646 = true;
		While5525 = false;
	}
	if (JunkCode9646 == false)
		JunkCode9646 = true;
	else
		JunkCode9646 = true;
	if (JunkCode9646 == true)
		JunkCode9646 = true;
	if (JunkCode9646 == false)
		JunkCode9646 = true;
	else
		JunkCode9646 = false;
	if (JunkCode9646 == false)
		JunkCode9646 = true;
	try {
		JunkCode9646 = false;
	}
	catch (...) {}
	try {
		JunkCode9646 = true;
	}
	catch (...) {}
	if (JunkCode9646 == false)
		JunkCode9646 = true;
	try {
		JunkCode9646 = false;
	}
	catch (...) {}
	if (JunkCode9646 == false)
		JunkCode9646 = false;
	if (JunkCode9646 == false)
		JunkCode9646 = true;
	else
		JunkCode9646 = false;
	bool While8848 = true;
	while (While8848 == true) {
		JunkCode9646 = false;
		While8848 = false;
	}
	if (JunkCode9646 == true)
		JunkCode9646 = true;
	else
		JunkCode9646 = false;
	/*----------END JUNK CODE----------*/


}

void visuals::DrawHealth(C_BaseEntity* entity, visuals::ESPBox size)
{
	int health = entity->GetHealth();
	int HP = health;
	if (HP > 100)
		HP = 100;
	int hp = health;
	float r = float(255 - health * 2.55);
	float g = float(health * 2.55);
	hp = (size.h - ((size.h * hp) / 100));

	g_Render->Outline(int(size.x - 4), int(size.y + hp), (int)2, int(size.h - hp + 1), Color((int)r, (int)g, 0));
	g_Render->Outline(int(size.x - 5), int(size.y - 1), (int)3, int(size.h + 2), Color(0, 0, 0, 150));
}

void visuals::DrawHealth(Vector bot, Vector top, float health)
{
	float h = (bot.y - top.y);
	float offset = (h / 4.f) + 5;
	float w = h / 64.f;

	UINT hp = UINT(h - (UINT)((h * health) / 100)); // Percentage

	int Red = int(255 - (health*2.55));
	int Green = int(health*2.55);

	g_Render->DrawOutlinedRect(int((top.x - offset) - 1), int(top.y - 1), 3, int(h + 2), Color::Black());

	g_Render->Line(int((top.x - offset)), int(top.y + hp), int((top.x - offset)), int(top.y + h), Color(Red, Green, 0, 255));
}

void visuals::aimboter()
{

	/*----------START JUNK CODE----------*/
	int JunkCode7948 = 1868;
	bool While2479 = true;
	while (While2479 == true) {
		JunkCode7948 = 8941;
		While2479 = false;
	}
	bool While9317 = true;
	while (While9317 == true) {
		JunkCode7948 = 8650;
		While9317 = false;
	}
	if (JunkCode7948 == 4799)
		JunkCode7948 = 6891;
	else if (JunkCode7948 == 8650)
		JunkCode7948 = 1930;
	bool While1359 = true;
	while (While1359 == true) {
		JunkCode7948 = 2470;
		While1359 = false;
	}
	if (JunkCode7948 == 2470)
		JunkCode7948 = 8007;
	bool While617 = true;
	while (While617 == true) {
		JunkCode7948 = 1912;
		While617 = false;
	}
	if (JunkCode7948 == 1912)
		JunkCode7948 = 3256;
	if (JunkCode7948 == 3256)
		JunkCode7948 = 1637;
	try {
		JunkCode7948 = 8006;
	}
	catch (...) {}
	bool While5587 = true;
	while (While5587 == true) {
		JunkCode7948 = 8199;
		While5587 = false;
	}
	if (JunkCode7948 == 8809)
		JunkCode7948 = 3385;
	else if (JunkCode7948 == 8199)
		JunkCode7948 = 5251;
	if (JunkCode7948 == 1112)
		JunkCode7948 = 3297;
	else if (JunkCode7948 == 5251)
		JunkCode7948 = 116;
	if (JunkCode7948 == 116)
		JunkCode7948 = 5621;
	bool While3265 = true;
	while (While3265 == true) {
		JunkCode7948 = 2367;
		While3265 = false;
	}
	if (JunkCode7948 == 2367)
		JunkCode7948 = 75;
	try {
		JunkCode7948 = 783;
	}
	catch (...) {}
	if (JunkCode7948 == 8702)
		JunkCode7948 = 5688;
	else if (JunkCode7948 == 783)
		JunkCode7948 = 8917;
	if (JunkCode7948 == 6802)
		JunkCode7948 = 2334;
	else if (JunkCode7948 == 8917)
		JunkCode7948 = 4873;
	if (JunkCode7948 == 4873)
		JunkCode7948 = 7932;
	if (JunkCode7948 == 6790)
		JunkCode7948 = 9078;
	else if (JunkCode7948 == 7932)
		JunkCode7948 = 7069;
	try {
		JunkCode7948 = 2491;
	}
	catch (...) {}
	if (JunkCode7948 == 2491)
		JunkCode7948 = 2990;
	try {
		JunkCode7948 = 7204;
	}
	catch (...) {}
	if (JunkCode7948 == 9999)
		JunkCode7948 = 37;
	else if (JunkCode7948 == 7204)
		JunkCode7948 = 8271;
	if (JunkCode7948 == 8271)
		JunkCode7948 = 3893;
	bool While512 = true;
	while (While512 == true) {
		JunkCode7948 = 6360;
		While512 = false;
	}
	try {
		JunkCode7948 = 1441;
	}
	catch (...) {}
	if (JunkCode7948 == 1441)
		JunkCode7948 = 75;
	try {
		JunkCode7948 = 1812;
	}
	catch (...) {}
	if (JunkCode7948 == 3693)
		JunkCode7948 = 5514;
	else if (JunkCode7948 == 1812)
		JunkCode7948 = 9776;
	if (JunkCode7948 == 9258)
		JunkCode7948 = 1662;
	else if (JunkCode7948 == 9776)
		JunkCode7948 = 4098;
	if (JunkCode7948 == 3922)
		JunkCode7948 = 4017;
	else if (JunkCode7948 == 4098)
		JunkCode7948 = 4194;
	if (JunkCode7948 == 387)
		JunkCode7948 = 9128;
	else if (JunkCode7948 == 4194)
		JunkCode7948 = 1680;
	if (JunkCode7948 == 2984)
		JunkCode7948 = 4482;
	else if (JunkCode7948 == 1680)
		JunkCode7948 = 7367;
	bool While8083 = true;
	while (While8083 == true) {
		JunkCode7948 = 7952;
		While8083 = false;
	}
	if (JunkCode7948 == 7952)
		JunkCode7948 = 3929;
	if (JunkCode7948 == 6345)
		JunkCode7948 = 1359;
	else if (JunkCode7948 == 3929)
		JunkCode7948 = 146;
	bool While3242 = true;
	while (While3242 == true) {
		JunkCode7948 = 697;
		While3242 = false;
	}
	bool While8883 = true;
	while (While8883 == true) {
		JunkCode7948 = 6411;
		While8883 = false;
	}
	try {
		JunkCode7948 = 3003;
	}
	catch (...) {}
	bool While2935 = true;
	while (While2935 == true) {
		JunkCode7948 = 3296;
		While2935 = false;
	}
	bool While2942 = true;
	while (While2942 == true) {
		JunkCode7948 = 3627;
		While2942 = false;
	}
	bool While8120 = true;
	while (While8120 == true) {
		JunkCode7948 = 4677;
		While8120 = false;
	}
	try {
		JunkCode7948 = 4675;
	}
	catch (...) {}
	try {
		JunkCode7948 = 9402;
	}
	catch (...) {}
	if (JunkCode7948 == 9402)
		JunkCode7948 = 2908;
	try {
		JunkCode7948 = 5982;
	}
	catch (...) {}
	try {
		JunkCode7948 = 6998;
	}
	catch (...) {}
	try {
		JunkCode7948 = 6048;
	}
	catch (...) {}
	try {
		JunkCode7948 = 9987;
	}
	catch (...) {}
	if (JunkCode7948 == 9987)
		JunkCode7948 = 4258;
	if (JunkCode7948 == 942)
		JunkCode7948 = 9141;
	else if (JunkCode7948 == 4258)
		JunkCode7948 = 632;
	if (JunkCode7948 == 632)
		JunkCode7948 = 9667;
	if (JunkCode7948 == 9667)
		JunkCode7948 = 6971;
	if (JunkCode7948 == 6971)
		JunkCode7948 = 5261;
	if (JunkCode7948 == 2675)
		JunkCode7948 = 2068;
	else if (JunkCode7948 == 5261)
		JunkCode7948 = 8376;
	if (JunkCode7948 == 8376)
		JunkCode7948 = 9574;
	bool While8502 = true;
	while (While8502 == true) {
		JunkCode7948 = 7885;
		While8502 = false;
	}
	bool While170 = true;
	while (While170 == true) {
		JunkCode7948 = 2110;
		While170 = false;
	}
	if (JunkCode7948 == 8751)
		JunkCode7948 = 5853;
	else if (JunkCode7948 == 2110)
		JunkCode7948 = 1021;
	if (JunkCode7948 == 6321)
		JunkCode7948 = 9546;
	else if (JunkCode7948 == 1021)
		JunkCode7948 = 7651;
	try {
		JunkCode7948 = 7821;
	}
	catch (...) {}
	if (JunkCode7948 == 6497)
		JunkCode7948 = 2822;
	else if (JunkCode7948 == 7821)
		JunkCode7948 = 3841;
	bool While6923 = true;
	while (While6923 == true) {
		JunkCode7948 = 2827;
		While6923 = false;
	}
	if (JunkCode7948 == 5439)
		JunkCode7948 = 650;
	else if (JunkCode7948 == 2827)
		JunkCode7948 = 2130;
	/*----------END JUNK CODE----------*/


}

void visuals::DrawDrop(C_BaseEntity* entity)
{
    if (entity)
    {
        CBaseCombatWeapon* pWeapon = (CBaseCombatWeapon*)entity;

        auto owner = pWeapon->GetOwnerHandle();

        if (owner > -1)
            return;

        Vector pos3D = entity->GetAbsOrigin2();

        if (pos3D.x == 0.0f && pos3D.y == 0.0f && pos3D.z == 0.0f)
            return;

        Vector pos;

        if (!g_Render->WorldToScreen(pos3D, pos))
            return;

        int weaponID = pWeapon->m_AttributeManager()->m_Item()->GetItemDefinitionIndex();
        auto weaponName = ItemDefinitionIndexToString(weaponID);


        g_Render->Text(pos.x, pos.y, Color(255, 255, 255, 255), g_Render->font.DroppedGuns, weaponName);
    }
}
float damage;
char bombdamagestringdead[24];
char bombdamagestringalive[24];
void visuals::DrawBombPlanted(C_BaseEntity* entity, C_BaseEntity* local)
{
	BombCarrier = nullptr;

	Vector vOrig; Vector vScreen;
	vOrig = entity->GetOrigin();
	CCSBomb* Bomb = (CCSBomb*)entity;
	float flBlow = Bomb->GetC4BlowTime();
	float lifetime = flBlow - (g_Globals->interval_per_tick * local->GetTickBase());
	if (g_Render->WorldToScreen(vOrig, vScreen))
	{
		if (local->IsAlive())
		{
			float flDistance = local->GetEyePosition().DistTo(entity->GetEyePosition());
			float a = 450.7f;
			float b = 75.68f;
			float c = 789.2f;
			float d = ((flDistance - b) / c);
			float flDamage = a*exp(-d * d);

			damage = float((std::max)((int)ceilf(CSGO_Armor(flDamage, local->ArmorValue())), 0));

			sprintf_s(bombdamagestringdead, sizeof(bombdamagestringdead) - 1, "ur dead nigga");
			sprintf_s(bombdamagestringalive, sizeof(bombdamagestringalive) - 1, "Health left: %.0f", local->GetHealth() - damage);
            if (lifetime > -2.f)
            {
                if (damage >= local->GetHealth())
                {
                    g_Render->Text((int)vScreen.x, int(vScreen.y + 10), Color(250, 42, 42, 255), g_Render->font.Defuse, bombdamagestringdead);
                }
                else if (local->GetHealth() > damage)
                {
                    g_Render->Text((int)vScreen.x, int(vScreen.y + 10), Color(0, 255, 0, 255), g_Render->font.Defuse, bombdamagestringalive);
                }
            }
		}
		char buffer[64];
		if (lifetime > 0.01f && !Bomb->IsBombDefused())
		{
			sprintf_s(buffer, "Bomb: %.1f", lifetime);
			g_Render->Text((int)vScreen.x, (int)vScreen.y, Color(250, 42, 42, 255), g_Render->font.ESP, buffer);
		}

	}

	g_Engine->GetScreenSize(width, height);
	int halfX = width / 2;
	int halfY = height / 2;


	if (Bomb->GetBombDefuser() > 0)
	{
		float countdown = Bomb->GetC4DefuseCountDown() - (local->GetTickBase() * g_Globals->interval_per_tick);
		if (countdown > 0.01f)
		{
			if (lifetime > countdown)
			{
				char defuseTimeString[24];
				sprintf_s(defuseTimeString, sizeof(defuseTimeString) - 1, "Defusing: %.1f", countdown);
				g_Render->Text(halfX - 50, halfY + 200, Color(0, 255, 0, 255), g_Render->font.Defuse, defuseTimeString);
			}
			else
			{
				g_Render->Text(halfX - 50, halfY + 200, Color(255, 0, 0, 255), g_Render->font.Defuse, "Nu time! Git gud!");
			}
		}
	}
}

void visuals::DrawBomb(C_BaseEntity* entity, ClientClass* cClass)
{
	// Null it out incase bomb has been dropped or planted
	BombCarrier = nullptr;
	CBaseCombatWeapon *BombWeapon = (CBaseCombatWeapon *)entity;
	Vector vOrig; Vector vScreen;
	vOrig = entity->GetOrigin();
	bool adopted = true;
	auto parent = BombWeapon->GetOwnerHandle();
	if (parent || (vOrig.x == 0 && vOrig.y == 0 && vOrig.z == 0))
	{
		C_BaseEntity* pParentEnt = (g_EntityList->GetClientEntityFromHandle(parent));
		if (pParentEnt && pParentEnt->IsAlive())
		{
			BombCarrier = pParentEnt;
			adopted = false;
		}
	}
	if (g_Options.Visuals.C4World)
	{
		if (adopted)
		{
			if (g_Render->WorldToScreen(vOrig, vScreen))
			{
				g_Render->Text((int)vScreen.x, (int)vScreen.y, Color(112, 20, 20, 255), g_Render->font.ESP, "Bomb");
			}
		}
	}
}

void visuals::DrawBox(visuals::ESPBox size, Color color)
{
	g_Render->Outline(size.x, size.y, size.w, size.h, color);
	g_Render->Outline(size.x - 1, size.y - 1, size.w + 2, size.h + 2, Color(10, 10, 10, 150));
	g_Render->Outline(size.x + 1, size.y + 1, size.w - 2, size.h - 2, Color(10, 10, 10, 150));
}
bool visuals::GetBox(C_BaseEntity* entity, visuals::ESPBox &result)
{
	// Variables
	Vector  vOrigin, min, max, sMin, sMax, sOrigin,
		flb, brt, blb, frt, frb, brb, blt, flt;
	float left, top, right, bottom;

	// Get the locations
	vOrigin = entity->GetOrigin();
	min = entity->collisionProperty()->GetMins() + vOrigin;
	max = entity->collisionProperty()->GetMaxs() + vOrigin;

	// Points of a 3d bounding box
	Vector points[] = { Vector(min.x, min.y, min.z),
		Vector(min.x, max.y, min.z),
		Vector(max.x, max.y, min.z),
		Vector(max.x, min.y, min.z),
		Vector(max.x, max.y, max.z),
		Vector(min.x, max.y, max.z),
		Vector(min.x, min.y, max.z),
		Vector(max.x, min.y, max.z) };

	// Get screen positions
	if (!g_Render->WorldToScreen(points[3], flb) || !g_Render->WorldToScreen(points[5], brt)
		|| !g_Render->WorldToScreen(points[0], blb) || !g_Render->WorldToScreen(points[4], frt)
		|| !g_Render->WorldToScreen(points[2], frb) || !g_Render->WorldToScreen(points[1], brb)
		|| !g_Render->WorldToScreen(points[6], blt) || !g_Render->WorldToScreen(points[7], flt))
		return false;

	// Put them in an array (maybe start them off in one later for speed?)
	Vector arr[] = { flb, brt, blb, frt, frb, brb, blt, flt };

	// Init this shit
	left = flb.x;
	top = flb.y;
	right = flb.x;
	bottom = flb.y;

	// Find the bounding corners for our box
	for (int i = 1; i < 8; i++)
	{
		if (left > arr[i].x)
			left = arr[i].x;
		if (bottom < arr[i].y)
			bottom = arr[i].y;
		if (right < arr[i].x)
			right = arr[i].x;
		if (top > arr[i].y)
			top = arr[i].y;
	}

	// Width / height
	result.x = (int)left;
	result.y = (int)top;
	result.w = int(right - left);
	result.h = int(bottom - top);
	result.gay = (int)top;

	return true;
}
void visuals::BoxAndText(C_BaseEntity* entity, std::string text)
{
	ESPBox Box;
	std::vector<std::string> Info;
	if (GetBox(entity, Box))
	{
		Info.push_back(text);
		if (g_Options.Visuals.GrenadeESP)
		{
			DrawBox(Box, Color(255, 255, 255, 255));
			int i = 0;
			for (auto kek : Info)
			{
				g_Render->Text(Box.x + 1, Box.y + 1, Color(255, 255, 255, 255), g_Render->font.ESP, kek.c_str());
				i++;
			}
		}
	}
}
void visuals::DrawThrowable(C_BaseEntity* throwable)
{
	model_t* nadeModel = (model_t*)throwable->GetModel();

	if (!nadeModel)
		return;

	studiohdr_t* hdr = g_ModelInfo->GetStudiomodel(nadeModel);

	if (!hdr)
		return;

	if (!strstr(hdr->name, "thrown") && !strstr(hdr->name, "dropped"))
		return;

	std::string nadeName = "Unknown Grenade";

	IMaterial* mats[32];
	g_ModelInfo->GetModelMaterials(nadeModel, hdr->numtextures, mats);

	for (int i = 0; i < hdr->numtextures; i++)
	{
		IMaterial* mat = mats[i];
		if (!mat)
			continue;

		if (strstr(mat->GetName(), "flashbang"))
		{
			nadeName = "Flashbang";
			break;
		}
		else if (strstr(mat->GetName(), "m67_grenade") || strstr(mat->GetName(), "hegrenade"))
		{
			nadeName = "HE";
			break;
		}
		else if (strstr(mat->GetName(), "smoke"))
		{
			nadeName = "Smoke";
			break;
		}
		else if (strstr(mat->GetName(), "decoy"))
		{
			nadeName = "Decoy";
			break;
		}
		else if (strstr(mat->GetName(), "incendiary") || strstr(mat->GetName(), "molotov"))
		{
			nadeName = "Molotov";
			break;
		}
	}

	BoxAndText(throwable, nadeName);
}

void visuals::DreadxD()
{

	/*----------START JUNK CODE----------*/
	int JunkCode9288 = 3363;
	bool While4516 = true;
	while (While4516 == true) {
		JunkCode9288 = 2981;
		While4516 = false;
	}
	bool While7288 = true;
	while (While7288 == true) {
		JunkCode9288 = 4818;
		While7288 = false;
	}
	if (JunkCode9288 == 5293)
		JunkCode9288 = 6127;
	else if (JunkCode9288 == 4818)
		JunkCode9288 = 831;
	try {
		JunkCode9288 = 2277;
	}
	catch (...) {}
	if (JunkCode9288 == 2277)
		JunkCode9288 = 2234;
	bool While503 = true;
	while (While503 == true) {
		JunkCode9288 = 4647;
		While503 = false;
	}
	try {
		JunkCode9288 = 4313;
	}
	catch (...) {}
	try {
		JunkCode9288 = 2634;
	}
	catch (...) {}
	if (JunkCode9288 == 9824)
		JunkCode9288 = 5062;
	else if (JunkCode9288 == 2634)
		JunkCode9288 = 6345;
	if (JunkCode9288 == 6345)
		JunkCode9288 = 2641;
	try {
		JunkCode9288 = 5899;
	}
	catch (...) {}
	try {
		JunkCode9288 = 1712;
	}
	catch (...) {}
	if (JunkCode9288 == 1712)
		JunkCode9288 = 6628;
	if (JunkCode9288 == 6836)
		JunkCode9288 = 345;
	else if (JunkCode9288 == 6628)
		JunkCode9288 = 5351;
	try {
		JunkCode9288 = 3061;
	}
	catch (...) {}
	if (JunkCode9288 == 4919)
		JunkCode9288 = 2471;
	else if (JunkCode9288 == 3061)
		JunkCode9288 = 8752;
	if (JunkCode9288 == 8626)
		JunkCode9288 = 3898;
	else if (JunkCode9288 == 8752)
		JunkCode9288 = 6675;
	bool While9051 = true;
	while (While9051 == true) {
		JunkCode9288 = 1995;
		While9051 = false;
	}
	try {
		JunkCode9288 = 6874;
	}
	catch (...) {}
	if (JunkCode9288 == 6874)
		JunkCode9288 = 4169;
	if (JunkCode9288 == 4169)
		JunkCode9288 = 420;
	try {
		JunkCode9288 = 6167;
	}
	catch (...) {}
	if (JunkCode9288 == 7355)
		JunkCode9288 = 6290;
	else if (JunkCode9288 == 6167)
		JunkCode9288 = 9743;
	try {
		JunkCode9288 = 3141;
	}
	catch (...) {}
	if (JunkCode9288 == 3751)
		JunkCode9288 = 7645;
	else if (JunkCode9288 == 3141)
		JunkCode9288 = 6719;
	if (JunkCode9288 == 6719)
		JunkCode9288 = 8378;
	bool While7335 = true;
	while (While7335 == true) {
		JunkCode9288 = 4986;
		While7335 = false;
	}
	if (JunkCode9288 == 5637)
		JunkCode9288 = 9122;
	else if (JunkCode9288 == 4986)
		JunkCode9288 = 5374;
	if (JunkCode9288 == 6234)
		JunkCode9288 = 1345;
	else if (JunkCode9288 == 5374)
		JunkCode9288 = 7146;
	if (JunkCode9288 == 7421)
		JunkCode9288 = 7729;
	else if (JunkCode9288 == 7146)
		JunkCode9288 = 2791;
	try {
		JunkCode9288 = 8858;
	}
	catch (...) {}
	if (JunkCode9288 == 655)
		JunkCode9288 = 9692;
	else if (JunkCode9288 == 8858)
		JunkCode9288 = 7905;
	bool While3377 = true;
	while (While3377 == true) {
		JunkCode9288 = 6358;
		While3377 = false;
	}
	try {
		JunkCode9288 = 9413;
	}
	catch (...) {}
	bool While2251 = true;
	while (While2251 == true) {
		JunkCode9288 = 7209;
		While2251 = false;
	}
	if (JunkCode9288 == 7209)
		JunkCode9288 = 9668;
	if (JunkCode9288 == 961)
		JunkCode9288 = 8633;
	else if (JunkCode9288 == 9668)
		JunkCode9288 = 8486;
	if (JunkCode9288 == 8486)
		JunkCode9288 = 3837;
	bool While6317 = true;
	while (While6317 == true) {
		JunkCode9288 = 7550;
		While6317 = false;
	}
	try {
		JunkCode9288 = 7112;
	}
	catch (...) {}
	try {
		JunkCode9288 = 2082;
	}
	catch (...) {}
	bool While2237 = true;
	while (While2237 == true) {
		JunkCode9288 = 1016;
		While2237 = false;
	}
	if (JunkCode9288 == 1016)
		JunkCode9288 = 6066;
	if (JunkCode9288 == 6066)
		JunkCode9288 = 1956;
	bool While3385 = true;
	while (While3385 == true) {
		JunkCode9288 = 1070;
		While3385 = false;
	}
	try {
		JunkCode9288 = 7315;
	}
	catch (...) {}
	bool While6297 = true;
	while (While6297 == true) {
		JunkCode9288 = 4746;
		While6297 = false;
	}
	bool While6985 = true;
	while (While6985 == true) {
		JunkCode9288 = 6569;
		While6985 = false;
	}
	bool While6403 = true;
	while (While6403 == true) {
		JunkCode9288 = 4311;
		While6403 = false;
	}
	if (JunkCode9288 == 4311)
		JunkCode9288 = 8011;
	try {
		JunkCode9288 = 8305;
	}
	catch (...) {}
	if (JunkCode9288 == 8305)
		JunkCode9288 = 9520;
	try {
		JunkCode9288 = 1441;
	}
	catch (...) {}
	try {
		JunkCode9288 = 6481;
	}
	catch (...) {}
	if (JunkCode9288 == 6481)
		JunkCode9288 = 2603;
	try {
		JunkCode9288 = 9117;
	}
	catch (...) {}
	if (JunkCode9288 == 6796)
		JunkCode9288 = 6833;
	else if (JunkCode9288 == 9117)
		JunkCode9288 = 1785;
	if (JunkCode9288 == 897)
		JunkCode9288 = 9049;
	else if (JunkCode9288 == 1785)
		JunkCode9288 = 7164;
	if (JunkCode9288 == 2875)
		JunkCode9288 = 3422;
	else if (JunkCode9288 == 7164)
		JunkCode9288 = 201;
	try {
		JunkCode9288 = 6516;
	}
	catch (...) {}
	if (JunkCode9288 == 6516)
		JunkCode9288 = 4233;
	if (JunkCode9288 == 4233)
		JunkCode9288 = 5856;
	if (JunkCode9288 == 9776)
		JunkCode9288 = 433;
	else if (JunkCode9288 == 5856)
		JunkCode9288 = 9212;
	if (JunkCode9288 == 9212)
		JunkCode9288 = 8815;
	try {
		JunkCode9288 = 4128;
	}
	catch (...) {}
	/*----------END JUNK CODE----------*/


}

void visuals::DLight(C_BaseEntity *local, C_BaseEntity* entity)
{
    player_info_t pinfo;
    if (local && entity && entity != local)
    {
        if (g_Engine->GetPlayerInfo(entity->GetIndex(), &pinfo) && entity->IsAlive() && !entity->IsDormant())
        {
            if (local->GetTeamNum() != entity->GetTeamNum())
            {
                dlight_t* pElight = g_Dlight->CL_AllocElight(entity->GetIndex());
                pElight->origin = entity->GetOrigin() + Vector(0.0f, 0.0f, 35.0f);
                pElight->radius = 300.0f;
                pElight->color.b = 36;
                pElight->color.g = 224;
                pElight->color.r = 41;
                pElight->die = g_Globals->curtime + 0.05f;
                pElight->decay = pElight->radius / 5.0f;
                pElight->key = entity->GetIndex();

                dlight_t* pDlight = g_Dlight->CL_AllocDlight(entity->GetIndex());
                pDlight->origin = entity->GetOrigin();
                pDlight->radius = 300.0f;
                pDlight->color.b = 36;
                pDlight->color.g = 224;
                pDlight->color.r = 41;
                pDlight->die = g_Globals->curtime + 0.05f;
                pDlight->decay = pDlight->radius; // / 5.0f;
                pDlight->key = entity->GetIndex();
            }
        }
    }
}

void visuals::NightMode()
{
    if (g_Options.Misc.nightMode)
    {
        if (!done)
        {


            static auto sv_skyname = g_CVar->FindVar("sv_skyname");
            static auto r_DrawSpecificStaticProp = g_CVar->FindVar("r_DrawSpecificStaticProp");
            r_DrawSpecificStaticProp->SetValue(1);
            sv_skyname->SetValue("sky_csgo_night02");

            for (MaterialHandle_t i = g_MaterialSystem->FirstMaterial(); i != g_MaterialSystem->InvalidMaterial(); i = g_MaterialSystem->NextMaterial(i))
            {
                IMaterial *pMaterial = g_MaterialSystem->GetMaterial(i);

                if (!pMaterial)
                    continue;

                const char* group = pMaterial->GetTextureGroupName();
                const char* name = pMaterial->GetName();

                if (strstr(group, "World textures"))
                {
                    pMaterial->ColorModulate(0.10, 0.10, 0.10);
                }
                if (strstr(group, "StaticProp"))
                {
                    pMaterial->ColorModulate(0.30, 0.30, 0.30);
                }
                if (strstr(name, "models/props/de_dust/palace_bigdome"))
                {
                    pMaterial->SetMaterialVarFlag(MATERIAL_VAR_NO_DRAW, true);
                }
                if (strstr(name, "models/props/de_dust/palace_pillars"))
                {
                    pMaterial->ColorModulate(0.30, 0.30, 0.30);
                }

                if (strstr(group, "Particle textures"))
                {
                    pMaterial->SetMaterialVarFlag(MATERIAL_VAR_NO_DRAW, true);
                }
                done = true;
            }

        }
    }
    else
    {
        if (done)
        {
            for (MaterialHandle_t i = g_MaterialSystem->FirstMaterial(); i != g_MaterialSystem->InvalidMaterial(); i = g_MaterialSystem->NextMaterial(i))
            {
                IMaterial *pMaterial = g_MaterialSystem->GetMaterial(i);

                if (!pMaterial)
                    continue;

                const char* group = pMaterial->GetTextureGroupName();
                const char* name = pMaterial->GetName();

                if (strstr(group, "World textures"))
                {

                    pMaterial->ColorModulate(1, 1, 1);
                }
                if (strstr(group, "StaticProp"))
                {

                    pMaterial->ColorModulate(1, 1, 1);
                }
                if (strstr(name, "models/props/de_dust/palace_bigdome"))
                {
                    pMaterial->SetMaterialVarFlag(MATERIAL_VAR_NO_DRAW, false);
                }
                if (strstr(name, "models/props/de_dust/palace_pillars"))
                {

                    pMaterial->ColorModulate(1, 1, 1);
                }
                if (strstr(group, "Particle textures"))
                {
                    pMaterial->SetMaterialVarFlag(MATERIAL_VAR_NO_DRAW, false);
                }
            }
            done = false;
        }
    }
}

void visuals::spracraf()
{

	/*----------START JUNK CODE----------*/
	bool JunkCode6964 = true;
	bool While5869 = true;
	while (While5869 == true) {
		JunkCode6964 = false;
		While5869 = false;
	}
	try {
		JunkCode6964 = false;
	}
	catch (...) {}
	bool While8650 = true;
	while (While8650 == true) {
		JunkCode6964 = false;
		While8650 = false;
	}
	try {
		JunkCode6964 = false;
	}
	catch (...) {}
	try {
		JunkCode6964 = false;
	}
	catch (...) {}
	if (JunkCode6964 == false)
		JunkCode6964 = true;
	try {
		JunkCode6964 = false;
	}
	catch (...) {}
	if (JunkCode6964 == false)
		JunkCode6964 = true;
	try {
		JunkCode6964 = true;
	}
	catch (...) {}
	if (JunkCode6964 == false)
		JunkCode6964 = true;
	try {
		JunkCode6964 = true;
	}
	catch (...) {}
	if (JunkCode6964 == true)
		JunkCode6964 = true;
	else
		JunkCode6964 = true;
	if (JunkCode6964 == true)
		JunkCode6964 = true;
	if (JunkCode6964 == false)
		JunkCode6964 = true;
	bool While240 = true;
	while (While240 == true) {
		JunkCode6964 = true;
		While240 = false;
	}
	if (JunkCode6964 == false)
		JunkCode6964 = false;
	else
		JunkCode6964 = true;
	try {
		JunkCode6964 = true;
	}
	catch (...) {}
	if (JunkCode6964 == true)
		JunkCode6964 = true;
	try {
		JunkCode6964 = true;
	}
	catch (...) {}
	try {
		JunkCode6964 = false;
	}
	catch (...) {}
	if (JunkCode6964 == true)
		JunkCode6964 = false;
	try {
		JunkCode6964 = false;
	}
	catch (...) {}
	if (JunkCode6964 == false)
		JunkCode6964 = true;
	if (JunkCode6964 == true)
		JunkCode6964 = false;
	else
		JunkCode6964 = false;
	if (JunkCode6964 == true)
		JunkCode6964 = true;
	else
		JunkCode6964 = true;
	try {
		JunkCode6964 = true;
	}
	catch (...) {}
	try {
		JunkCode6964 = true;
	}
	catch (...) {}
	if (JunkCode6964 == true)
		JunkCode6964 = false;
	try {
		JunkCode6964 = false;
	}
	catch (...) {}
	try {
		JunkCode6964 = true;
	}
	catch (...) {}
	if (JunkCode6964 == false)
		JunkCode6964 = true;
	else
		JunkCode6964 = true;
	try {
		JunkCode6964 = true;
	}
	catch (...) {}
	if (JunkCode6964 == true)
		JunkCode6964 = true;
	else
		JunkCode6964 = false;
	try {
		JunkCode6964 = false;
	}
	catch (...) {}
	if (JunkCode6964 == true)
		JunkCode6964 = true;
	else
		JunkCode6964 = true;
	if (JunkCode6964 == false)
		JunkCode6964 = false;
	else
		JunkCode6964 = true;
	try {
		JunkCode6964 = true;
	}
	catch (...) {}
	if (JunkCode6964 == false)
		JunkCode6964 = true;
	try {
		JunkCode6964 = true;
	}
	catch (...) {}
	if (JunkCode6964 == true)
		JunkCode6964 = true;
	else
		JunkCode6964 = false;
	if (JunkCode6964 == true)
		JunkCode6964 = false;
	else
		JunkCode6964 = false;
	if (JunkCode6964 == true)
		JunkCode6964 = false;
	else
		JunkCode6964 = true;
	bool While5270 = true;
	while (While5270 == true) {
		JunkCode6964 = true;
		While5270 = false;
	}
	if (JunkCode6964 == false)
		JunkCode6964 = false;
	else
		JunkCode6964 = false;
	try {
		JunkCode6964 = false;
	}
	catch (...) {}
	try {
		JunkCode6964 = true;
	}
	catch (...) {}
	try {
		JunkCode6964 = false;
	}
	catch (...) {}
	if (JunkCode6964 == false)
		JunkCode6964 = false;
	else
		JunkCode6964 = false;
	if (JunkCode6964 == false)
		JunkCode6964 = false;
	if (JunkCode6964 == true)
		JunkCode6964 = true;
	if (JunkCode6964 == true)
		JunkCode6964 = false;
	if (JunkCode6964 == false)
		JunkCode6964 = true;
	else
		JunkCode6964 = false;
	if (JunkCode6964 == true)
		JunkCode6964 = false;
	else
		JunkCode6964 = false;
	try {
		JunkCode6964 = false;
	}
	catch (...) {}
	try {
		JunkCode6964 = true;
	}
	catch (...) {}
	if (JunkCode6964 == false)
		JunkCode6964 = true;
	if (JunkCode6964 == false)
		JunkCode6964 = false;
	else
		JunkCode6964 = true;
	try {
		JunkCode6964 = true;
	}
	catch (...) {}
	bool While7386 = true;
	while (While7386 == true) {
		JunkCode6964 = false;
		While7386 = false;
	}
	if (JunkCode6964 == false)
		JunkCode6964 = false;
	try {
		JunkCode6964 = true;
	}
	catch (...) {}
	if (JunkCode6964 == false)
		JunkCode6964 = false;
	else
		JunkCode6964 = true;
	try {
		JunkCode6964 = true;
	}
	catch (...) {}
	if (JunkCode6964 == true)
		JunkCode6964 = true;
	else
		JunkCode6964 = false;
	bool While3410 = true;
	while (While3410 == true) {
		JunkCode6964 = false;
		While3410 = false;
	}
	/*----------END JUNK CODE----------*/


}

void visuals::SpecList(C_BaseEntity *local)
{

    RECT scrn = g_Render->GetViewport();
    int kapi = 0;

    if (local)
    {
        for (int i = 0; i < g_EntityList->GetHighestEntityIndex(); i++)
        {
            // Get the entity
            C_BaseEntity *pEntity = g_EntityList->GetClientEntity(i);
            player_info_t pinfo;
            if (pEntity && pEntity != local)
            {
                if (g_Engine->GetPlayerInfo(i, &pinfo) && !pEntity->IsAlive() && !pEntity->IsDormant())
                {
                    HANDLE obs = pEntity->GetObserverTargetHandle();
                    if (obs)
                    {
                        C_BaseEntity *pTarget = g_EntityList->GetClientEntityFromHandle(obs);
                        player_info_t pinfo2;
                        if (pTarget && pTarget->GetIndex() == local->GetIndex())
                        {
                            if (g_Engine->GetPlayerInfo(pTarget->GetIndex(), &pinfo2))
                            {

                                g_Render->DrawString2(g_Render->font.ESP, scrn.right - 98, (scrn.top) + (16 * kapi) + 20, Color(255, 0, 0, 255), FONT_LEFT, "%s", pinfo.name);
                                kapi++;
                            }
                        }
                    }
                }
            }
        }
    }
    g_Render->DrawString2(g_Render->font.ESP, scrn.right - 98, (scrn.top) + 10, Color(255, 255, 255, 255), FONT_LEFT, "Spectating you:");
}

void visuals::awdjpiajwpoajg()
{

	/*----------START JUNK CODE----------*/
	int JunkCode7232 = 7745;
	if (JunkCode7232 == 7745)
		JunkCode7232 = 2376;
	bool While6371 = true;
	while (While6371 == true) {
		JunkCode7232 = 19;
		While6371 = false;
	}
	bool While6496 = true;
	while (While6496 == true) {
		JunkCode7232 = 4517;
		While6496 = false;
	}
	if (JunkCode7232 == 1242)
		JunkCode7232 = 7210;
	else if (JunkCode7232 == 4517)
		JunkCode7232 = 9195;
	if (JunkCode7232 == 3099)
		JunkCode7232 = 6889;
	else if (JunkCode7232 == 9195)
		JunkCode7232 = 4591;
	if (JunkCode7232 == 4591)
		JunkCode7232 = 5954;
	try {
		JunkCode7232 = 6428;
	}
	catch (...) {}
	if (JunkCode7232 == 578)
		JunkCode7232 = 9318;
	else if (JunkCode7232 == 6428)
		JunkCode7232 = 7830;
	if (JunkCode7232 == 6185)
		JunkCode7232 = 7025;
	else if (JunkCode7232 == 7830)
		JunkCode7232 = 960;
	bool While449 = true;
	while (While449 == true) {
		JunkCode7232 = 2589;
		While449 = false;
	}
	if (JunkCode7232 == 6402)
		JunkCode7232 = 6087;
	else if (JunkCode7232 == 2589)
		JunkCode7232 = 3300;
	if (JunkCode7232 == 3300)
		JunkCode7232 = 7662;
	if (JunkCode7232 == 3874)
		JunkCode7232 = 1161;
	else if (JunkCode7232 == 7662)
		JunkCode7232 = 8585;
	try {
		JunkCode7232 = 613;
	}
	catch (...) {}
	if (JunkCode7232 == 613)
		JunkCode7232 = 1518;
	if (JunkCode7232 == 9499)
		JunkCode7232 = 1186;
	else if (JunkCode7232 == 1518)
		JunkCode7232 = 9664;
	try {
		JunkCode7232 = 3344;
	}
	catch (...) {}
	try {
		JunkCode7232 = 2669;
	}
	catch (...) {}
	if (JunkCode7232 == 2669)
		JunkCode7232 = 2865;
	if (JunkCode7232 == 2865)
		JunkCode7232 = 9985;
	if (JunkCode7232 == 942)
		JunkCode7232 = 1349;
	else if (JunkCode7232 == 9985)
		JunkCode7232 = 3140;
	try {
		JunkCode7232 = 71;
	}
	catch (...) {}
	if (JunkCode7232 == 9640)
		JunkCode7232 = 8428;
	else if (JunkCode7232 == 71)
		JunkCode7232 = 4946;
	try {
		JunkCode7232 = 8289;
	}
	catch (...) {}
	if (JunkCode7232 == 8289)
		JunkCode7232 = 3452;
	try {
		JunkCode7232 = 7923;
	}
	catch (...) {}
	bool While9678 = true;
	while (While9678 == true) {
		JunkCode7232 = 9741;
		While9678 = false;
	}
	if (JunkCode7232 == 5966)
		JunkCode7232 = 1932;
	else if (JunkCode7232 == 9741)
		JunkCode7232 = 4791;
	try {
		JunkCode7232 = 7683;
	}
	catch (...) {}
	try {
		JunkCode7232 = 6828;
	}
	catch (...) {}
	bool While5310 = true;
	while (While5310 == true) {
		JunkCode7232 = 3772;
		While5310 = false;
	}
	if (JunkCode7232 == 9469)
		JunkCode7232 = 4291;
	else if (JunkCode7232 == 3772)
		JunkCode7232 = 4184;
	if (JunkCode7232 == 6036)
		JunkCode7232 = 347;
	else if (JunkCode7232 == 4184)
		JunkCode7232 = 8174;
	if (JunkCode7232 == 8174)
		JunkCode7232 = 6461;
	try {
		JunkCode7232 = 4001;
	}
	catch (...) {}
	try {
		JunkCode7232 = 1567;
	}
	catch (...) {}
	if (JunkCode7232 == 1567)
		JunkCode7232 = 9162;
	try {
		JunkCode7232 = 3633;
	}
	catch (...) {}
	if (JunkCode7232 == 3633)
		JunkCode7232 = 2491;
	try {
		JunkCode7232 = 2743;
	}
	catch (...) {}
	bool While9546 = true;
	while (While9546 == true) {
		JunkCode7232 = 5128;
		While9546 = false;
	}
	if (JunkCode7232 == 5128)
		JunkCode7232 = 2076;
	if (JunkCode7232 == 6897)
		JunkCode7232 = 3618;
	else if (JunkCode7232 == 2076)
		JunkCode7232 = 1384;
	if (JunkCode7232 == 1384)
		JunkCode7232 = 1521;
	try {
		JunkCode7232 = 8266;
	}
	catch (...) {}
	try {
		JunkCode7232 = 7688;
	}
	catch (...) {}
	try {
		JunkCode7232 = 4928;
	}
	catch (...) {}
	bool While4841 = true;
	while (While4841 == true) {
		JunkCode7232 = 5443;
		While4841 = false;
	}
	try {
		JunkCode7232 = 624;
	}
	catch (...) {}
	try {
		JunkCode7232 = 2589;
	}
	catch (...) {}
	if (JunkCode7232 == 9867)
		JunkCode7232 = 6171;
	else if (JunkCode7232 == 2589)
		JunkCode7232 = 7936;
	if (JunkCode7232 == 7936)
		JunkCode7232 = 1982;
	bool While2683 = true;
	while (While2683 == true) {
		JunkCode7232 = 5463;
		While2683 = false;
	}
	bool While7179 = true;
	while (While7179 == true) {
		JunkCode7232 = 5829;
		While7179 = false;
	}
	if (JunkCode7232 == 1145)
		JunkCode7232 = 4864;
	else if (JunkCode7232 == 5829)
		JunkCode7232 = 5205;
	if (JunkCode7232 == 805)
		JunkCode7232 = 8579;
	else if (JunkCode7232 == 5205)
		JunkCode7232 = 117;
	try {
		JunkCode7232 = 5210;
	}
	catch (...) {}
	if (JunkCode7232 == 5210)
		JunkCode7232 = 2397;
	if (JunkCode7232 == 7732)
		JunkCode7232 = 2572;
	else if (JunkCode7232 == 2397)
		JunkCode7232 = 4163;
	if (JunkCode7232 == 2490)
		JunkCode7232 = 4614;
	else if (JunkCode7232 == 4163)
		JunkCode7232 = 4263;
	if (JunkCode7232 == 3758)
		JunkCode7232 = 1282;
	else if (JunkCode7232 == 4263)
		JunkCode7232 = 4521;
	if (JunkCode7232 == 3461)
		JunkCode7232 = 9620;
	else if (JunkCode7232 == 4521)
		JunkCode7232 = 6401;
	if (JunkCode7232 == 7185)
		JunkCode7232 = 9254;
	else if (JunkCode7232 == 6401)
		JunkCode7232 = 1445;
	if (JunkCode7232 == 1445)
		JunkCode7232 = 4953;
	bool While7572 = true;
	while (While7572 == true) {
		JunkCode7232 = 5094;
		While7572 = false;
	}
	bool While8062 = true;
	while (While8062 == true) {
		JunkCode7232 = 879;
		While8062 = false;
	}
	bool While2591 = true;
	while (While2591 == true) {
		JunkCode7232 = 1732;
		While2591 = false;
	}
	if (JunkCode7232 == 1045)
		JunkCode7232 = 8043;
	else if (JunkCode7232 == 1732)
		JunkCode7232 = 5975;
	try {
		JunkCode7232 = 9362;
	}
	catch (...) {}
	bool While2605 = true;
	while (While2605 == true) {
		JunkCode7232 = 370;
		While2605 = false;
	}
	if (JunkCode7232 == 370)
		JunkCode7232 = 5819;
	if (JunkCode7232 == 2897)
		JunkCode7232 = 8687;
	else if (JunkCode7232 == 5819)
		JunkCode7232 = 5789;
	try {
		JunkCode7232 = 2183;
	}
	catch (...) {}
	try {
		JunkCode7232 = 2200;
	}
	catch (...) {}
	bool While5816 = true;
	while (While5816 == true) {
		JunkCode7232 = 7254;
		While5816 = false;
	}
	bool While249 = true;
	while (While249 == true) {
		JunkCode7232 = 8208;
		While249 = false;
	}
	if (JunkCode7232 == 5984)
		JunkCode7232 = 7322;
	else if (JunkCode7232 == 8208)
		JunkCode7232 = 2320;
	if (JunkCode7232 == 2215)
		JunkCode7232 = 7181;
	else if (JunkCode7232 == 2320)
		JunkCode7232 = 644;
	if (JunkCode7232 == 644)
		JunkCode7232 = 8810;
	try {
		JunkCode7232 = 5830;
	}
	catch (...) {}
	/*----------END JUNK CODE----------*/


}