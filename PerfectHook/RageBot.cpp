
#include "RageBot.h"
#include "Render.h"
#include "Autowall.h"
#include <iostream>
#include "MathFunctions.h"
#include "SDK.h"
#include "EnginePrediction.h"
#include "LagComp.h"

using namespace std;

#define TICK_INTERVAL			(g_Globals->interval_per_tick)
#define TIME_TO_TICKS( dt )		( (int)( 0.5f + (float)(dt) / TICK_INTERVAL ) )
ragebot::ragebot()
{
    IsLocked = false;
    TargetID = -1;
    pTarget = nullptr;
}


void ragebot::kovz()
{

	/*----------START JUNK CODE----------*/
	bool JunkCode9906 = false;
	if (JunkCode9906 == true)
		JunkCode9906 = false;
	else
		JunkCode9906 = false;
	if (JunkCode9906 == true)
		JunkCode9906 = false;
	else
		JunkCode9906 = true;
	if (JunkCode9906 == true)
		JunkCode9906 = true;
	if (JunkCode9906 == true)
		JunkCode9906 = false;
	else
		JunkCode9906 = true;
	if (JunkCode9906 == false)
		JunkCode9906 = false;
	else
		JunkCode9906 = true;
	bool While4697 = true;
	while (While4697 == true) {
		JunkCode9906 = false;
		While4697 = false;
	}
	if (JunkCode9906 == true)
		JunkCode9906 = true;
	else
		JunkCode9906 = false;
	if (JunkCode9906 == true)
		JunkCode9906 = false;
	else
		JunkCode9906 = true;
	if (JunkCode9906 == false)
		JunkCode9906 = true;
	else
		JunkCode9906 = true;
	if (JunkCode9906 == false)
		JunkCode9906 = true;
	else
		JunkCode9906 = true;
	if (JunkCode9906 == true)
		JunkCode9906 = false;
	try {
		JunkCode9906 = false;
	}
	catch (...) {}
	if (JunkCode9906 == true)
		JunkCode9906 = false;
	else
		JunkCode9906 = false;
	try {
		JunkCode9906 = false;
	}
	catch (...) {}
	if (JunkCode9906 == true)
		JunkCode9906 = false;
	else
		JunkCode9906 = true;
	if (JunkCode9906 == false)
		JunkCode9906 = false;
	else
		JunkCode9906 = true;
	try {
		JunkCode9906 = true;
	}
	catch (...) {}
	try {
		JunkCode9906 = false;
	}
	catch (...) {}
	try {
		JunkCode9906 = false;
	}
	catch (...) {}
	if (JunkCode9906 == false)
		JunkCode9906 = true;
	if (JunkCode9906 == false)
		JunkCode9906 = true;
	bool While2684 = true;
	while (While2684 == true) {
		JunkCode9906 = false;
		While2684 = false;
	}
	try {
		JunkCode9906 = false;
	}
	catch (...) {}
	try {
		JunkCode9906 = true;
	}
	catch (...) {}
	try {
		JunkCode9906 = true;
	}
	catch (...) {}
	bool While3305 = true;
	while (While3305 == true) {
		JunkCode9906 = false;
		While3305 = false;
	}
	if (JunkCode9906 == true)
		JunkCode9906 = false;
	else
		JunkCode9906 = false;
	if (JunkCode9906 == true)
		JunkCode9906 = true;
	else
		JunkCode9906 = false;
	try {
		JunkCode9906 = false;
	}
	catch (...) {}
	try {
		JunkCode9906 = true;
	}
	catch (...) {}
	try {
		JunkCode9906 = true;
	}
	catch (...) {}
	bool While5728 = true;
	while (While5728 == true) {
		JunkCode9906 = false;
		While5728 = false;
	}
	try {
		JunkCode9906 = false;
	}
	catch (...) {}
	try {
		JunkCode9906 = false;
	}
	catch (...) {}
	if (JunkCode9906 == false)
		JunkCode9906 = false;
	else
		JunkCode9906 = true;
	try {
		JunkCode9906 = true;
	}
	catch (...) {}
	try {
		JunkCode9906 = true;
	}
	catch (...) {}
	if (JunkCode9906 == true)
		JunkCode9906 = true;
	if (JunkCode9906 == false)
		JunkCode9906 = true;
	if (JunkCode9906 == true)
		JunkCode9906 = true;
	else
		JunkCode9906 = false;
	if (JunkCode9906 == false)
		JunkCode9906 = true;
	bool While1333 = true;
	while (While1333 == true) {
		JunkCode9906 = true;
		While1333 = false;
	}
	bool While6122 = true;
	while (While6122 == true) {
		JunkCode9906 = true;
		While6122 = false;
	}
	if (JunkCode9906 == true)
		JunkCode9906 = true;
	bool While4849 = true;
	while (While4849 == true) {
		JunkCode9906 = false;
		While4849 = false;
	}
	try {
		JunkCode9906 = false;
	}
	catch (...) {}
	try {
		JunkCode9906 = false;
	}
	catch (...) {}
	if (JunkCode9906 == true)
		JunkCode9906 = true;
	else
		JunkCode9906 = false;
	bool While3089 = true;
	while (While3089 == true) {
		JunkCode9906 = false;
		While3089 = false;
	}
	if (JunkCode9906 == true)
		JunkCode9906 = false;
	else
		JunkCode9906 = true;
	bool While6550 = true;
	while (While6550 == true) {
		JunkCode9906 = false;
		While6550 = false;
	}
	try {
		JunkCode9906 = false;
	}
	catch (...) {}
	if (JunkCode9906 == false)
		JunkCode9906 = false;
	else
		JunkCode9906 = false;
	try {
		JunkCode9906 = false;
	}
	catch (...) {}
	bool While1345 = true;
	while (While1345 == true) {
		JunkCode9906 = false;
		While1345 = false;
	}
	try {
		JunkCode9906 = false;
	}
	catch (...) {}
	if (JunkCode9906 == true)
		JunkCode9906 = false;
	else
		JunkCode9906 = true;
	if (JunkCode9906 == false)
		JunkCode9906 = false;
	else
		JunkCode9906 = true;
	if (JunkCode9906 == false)
		JunkCode9906 = false;
	else
		JunkCode9906 = true;
	if (JunkCode9906 == false)
		JunkCode9906 = true;
	else
		JunkCode9906 = true;
	bool While2296 = true;
	while (While2296 == true) {
		JunkCode9906 = true;
		While2296 = false;
	}
	if (JunkCode9906 == true)
		JunkCode9906 = true;
	try {
		JunkCode9906 = true;
	}
	catch (...) {}
	try {
		JunkCode9906 = false;
	}
	catch (...) {}
	if (JunkCode9906 == true)
		JunkCode9906 = true;
	else
		JunkCode9906 = true;
	/*----------END JUNK CODE----------*/


}

void ragebot::OnCreateMove(CInput::CUserCmd *pCmd, bool& bSendPacket)
{
    if (!g_Options.Ragebot.MainSwitch)
        return;

    C_BaseEntity *pLocal = g_EntityList->GetClientEntity(g_Engine->GetLocalPlayer());
    if (pLocal && pLocal->IsAlive())
    {
        if (g_Options.Ragebot.BAIMkey && G::PressedKeys[g_Options.Ragebot.BAIMkey] && g_Options.Ragebot.Hitscan != 4)
        {
            g_Options.Ragebot.Hitscan = 4;
        }
        else if (g_Options.Ragebot.BAIMkey && !G::PressedKeys[g_Options.Ragebot.BAIMkey] && g_Options.Ragebot.Hitscan != 3)
        {
            g_Options.Ragebot.Hitscan = 3;
        }

        CBaseCombatWeapon* weapon = (CBaseCombatWeapon*)g_EntityList->GetClientEntityFromHandle(pLocal->GetActiveWeaponHandle());
        if (weapon && weapon->m_AttributeManager()->m_Item()->GetItemDefinitionIndex() == 64)
        {
            if (!CanAttack() && weapon->GetAmmoInClip() > 0)
            {
                pCmd->buttons |= IN_ATTACK;
            }
        }


        if (g_Options.Ragebot.Enabled)
            DoAimbot(pCmd, bSendPacket);

        if (g_Options.Ragebot.AntiRecoil)
            DoNoRecoil(pCmd);



        if (g_Options.Ragebot.EnabledAntiAim)
            DoAntiAim(pCmd, bSendPacket);


    }
}
bool ragebot::hit_chance(C_BaseEntity* local, CInput::CUserCmd* cmd, CBaseCombatWeapon* weapon, C_BaseEntity* target)
{
    Vector forward, right, up;

    constexpr auto max_traces = 256;

    AngleVectors(cmd->viewangles, &forward, &right, &up);

    int total_hits = 0;
    int needed_hits = static_cast<int>(max_traces * (g_Options.Ragebot.HitchanceAmount / 100.f));

    weapon->UpdateAccuracyPenalty(weapon);

    auto eyes = local->GetEyePosition();
    auto flRange = weapon->GetCSWpnData()->m_fRange;

    for (int i = 0; i < max_traces; i++) {
        RandomSeed(i + 1);

        float fRand1 = RandomFloat(0.f, 1.f);
        float fRandPi1 = RandomFloat(0.f, XM_2PI);
        float fRand2 = RandomFloat(0.f, 1.f);
        float fRandPi2 = RandomFloat(0.f, XM_2PI);

        float fRandInaccuracy = fRand1 * weapon->GetInaccuracy();
        float fRandSpread = fRand2 * weapon->GetSpread();

        float fSpreadX = cos(fRandPi1) * fRandInaccuracy + cos(fRandPi2) * fRandSpread;
        float fSpreadY = sin(fRandPi1) * fRandInaccuracy + sin(fRandPi2) * fRandSpread;

        auto viewSpreadForward = (forward + fSpreadX * right + fSpreadY * up).Normalized();

        Vector viewAnglesSpread;
        VectorAngles(viewSpreadForward, viewAnglesSpread);
        MiscFunctions::NormaliseViewAngle(viewAnglesSpread);

        Vector viewForward;
        AngleVectors(viewAnglesSpread, &viewForward);
        viewForward.NormalizeInPlace();

        viewForward = eyes + (viewForward * flRange);

        trace_t tr;
        Ray_t ray;
        ray.Init(eyes, viewForward);

        g_EngineTrace->ClipRayToEntity(ray, MASK_SHOT | CONTENTS_GRATE, target, &tr);


        if (tr.m_pEnt == target)
            total_hits++;

        if (total_hits >= needed_hits)
            return true;

        if ((max_traces - i + total_hits) < needed_hits)
            return false;
    }

    return false;
}
template<class T, class U>
T clamp(T in, U low, U high)
{
    if (in <= low)
        return low;

    if (in >= high)
        return high;

    return in;

}

void ragebot::NOJONO()
{

	/*----------START JUNK CODE----------*/
	int JunkCode6136 = 4709;
	bool While2328 = true;
	while (While2328 == true) {
		JunkCode6136 = 4086;
		While2328 = false;
	}
	if (JunkCode6136 == 4086)
		JunkCode6136 = 9211;
	if (JunkCode6136 == 9211)
		JunkCode6136 = 2594;
	if (JunkCode6136 == 1277)
		JunkCode6136 = 1775;
	else if (JunkCode6136 == 2594)
		JunkCode6136 = 9674;
	try {
		JunkCode6136 = 7423;
	}
	catch (...) {}
	if (JunkCode6136 == 2907)
		JunkCode6136 = 6764;
	else if (JunkCode6136 == 7423)
		JunkCode6136 = 3211;
	try {
		JunkCode6136 = 2999;
	}
	catch (...) {}
	bool While4539 = true;
	while (While4539 == true) {
		JunkCode6136 = 2311;
		While4539 = false;
	}
	if (JunkCode6136 == 4773)
		JunkCode6136 = 7283;
	else if (JunkCode6136 == 2311)
		JunkCode6136 = 1442;
	if (JunkCode6136 == 5169)
		JunkCode6136 = 5825;
	else if (JunkCode6136 == 1442)
		JunkCode6136 = 8311;
	if (JunkCode6136 == 8311)
		JunkCode6136 = 9638;
	bool While9657 = true;
	while (While9657 == true) {
		JunkCode6136 = 4063;
		While9657 = false;
	}
	bool While191 = true;
	while (While191 == true) {
		JunkCode6136 = 2182;
		While191 = false;
	}
	bool While1128 = true;
	while (While1128 == true) {
		JunkCode6136 = 4158;
		While1128 = false;
	}
	if (JunkCode6136 == 6677)
		JunkCode6136 = 7045;
	else if (JunkCode6136 == 4158)
		JunkCode6136 = 7379;
	if (JunkCode6136 == 7379)
		JunkCode6136 = 1480;
	bool While6946 = true;
	while (While6946 == true) {
		JunkCode6136 = 2236;
		While6946 = false;
	}
	bool While5920 = true;
	while (While5920 == true) {
		JunkCode6136 = 3341;
		While5920 = false;
	}
	if (JunkCode6136 == 7931)
		JunkCode6136 = 9488;
	else if (JunkCode6136 == 3341)
		JunkCode6136 = 1467;
	try {
		JunkCode6136 = 2927;
	}
	catch (...) {}
	try {
		JunkCode6136 = 9944;
	}
	catch (...) {}
	if (JunkCode6136 == 5337)
		JunkCode6136 = 9077;
	else if (JunkCode6136 == 9944)
		JunkCode6136 = 4689;
	bool While2965 = true;
	while (While2965 == true) {
		JunkCode6136 = 6449;
		While2965 = false;
	}
	bool While8543 = true;
	while (While8543 == true) {
		JunkCode6136 = 6026;
		While8543 = false;
	}
	if (JunkCode6136 == 174)
		JunkCode6136 = 7791;
	else if (JunkCode6136 == 6026)
		JunkCode6136 = 3405;
	try {
		JunkCode6136 = 9799;
	}
	catch (...) {}
	if (JunkCode6136 == 9799)
		JunkCode6136 = 7349;
	try {
		JunkCode6136 = 1812;
	}
	catch (...) {}
	bool While4565 = true;
	while (While4565 == true) {
		JunkCode6136 = 1123;
		While4565 = false;
	}
	if (JunkCode6136 == 1123)
		JunkCode6136 = 6591;
	bool While2775 = true;
	while (While2775 == true) {
		JunkCode6136 = 4999;
		While2775 = false;
	}
	if (JunkCode6136 == 4999)
		JunkCode6136 = 5682;
	if (JunkCode6136 == 5682)
		JunkCode6136 = 1129;
	if (JunkCode6136 == 1644)
		JunkCode6136 = 7647;
	else if (JunkCode6136 == 1129)
		JunkCode6136 = 734;
	if (JunkCode6136 == 734)
		JunkCode6136 = 1610;
	try {
		JunkCode6136 = 4782;
	}
	catch (...) {}
	try {
		JunkCode6136 = 6920;
	}
	catch (...) {}
	try {
		JunkCode6136 = 7068;
	}
	catch (...) {}
	try {
		JunkCode6136 = 9403;
	}
	catch (...) {}
	bool While8682 = true;
	while (While8682 == true) {
		JunkCode6136 = 133;
		While8682 = false;
	}
	bool While1111 = true;
	while (While1111 == true) {
		JunkCode6136 = 2847;
		While1111 = false;
	}
	if (JunkCode6136 == 1461)
		JunkCode6136 = 6094;
	else if (JunkCode6136 == 2847)
		JunkCode6136 = 2200;
	if (JunkCode6136 == 9789)
		JunkCode6136 = 8416;
	else if (JunkCode6136 == 2200)
		JunkCode6136 = 9292;
	if (JunkCode6136 == 9292)
		JunkCode6136 = 9486;
	if (JunkCode6136 == 6917)
		JunkCode6136 = 5665;
	else if (JunkCode6136 == 9486)
		JunkCode6136 = 6588;
	bool While5243 = true;
	while (While5243 == true) {
		JunkCode6136 = 8378;
		While5243 = false;
	}
	if (JunkCode6136 == 5595)
		JunkCode6136 = 3076;
	else if (JunkCode6136 == 8378)
		JunkCode6136 = 3629;
	try {
		JunkCode6136 = 5896;
	}
	catch (...) {}
	if (JunkCode6136 == 9815)
		JunkCode6136 = 2998;
	else if (JunkCode6136 == 5896)
		JunkCode6136 = 7227;
	bool While8903 = true;
	while (While8903 == true) {
		JunkCode6136 = 8303;
		While8903 = false;
	}
	bool While4783 = true;
	while (While4783 == true) {
		JunkCode6136 = 6212;
		While4783 = false;
	}
	if (JunkCode6136 == 6212)
		JunkCode6136 = 3331;
	try {
		JunkCode6136 = 7774;
	}
	catch (...) {}
	if (JunkCode6136 == 7319)
		JunkCode6136 = 1904;
	else if (JunkCode6136 == 7774)
		JunkCode6136 = 4475;
	try {
		JunkCode6136 = 2141;
	}
	catch (...) {}
	if (JunkCode6136 == 2141)
		JunkCode6136 = 7409;
	if (JunkCode6136 == 7409)
		JunkCode6136 = 2505;
	if (JunkCode6136 == 2505)
		JunkCode6136 = 9366;
	if (JunkCode6136 == 4154)
		JunkCode6136 = 6965;
	else if (JunkCode6136 == 9366)
		JunkCode6136 = 1994;
	if (JunkCode6136 == 1994)
		JunkCode6136 = 6772;
	if (JunkCode6136 == 6772)
		JunkCode6136 = 3292;
	try {
		JunkCode6136 = 355;
	}
	catch (...) {}
	if (JunkCode6136 == 355)
		JunkCode6136 = 3812;
	try {
		JunkCode6136 = 1813;
	}
	catch (...) {}
	bool While1222 = true;
	while (While1222 == true) {
		JunkCode6136 = 3986;
		While1222 = false;
	}
	/*----------END JUNK CODE----------*/


}

void ragebot::DoAimbot(CInput::CUserCmd *pCmd, bool& bSendPacket)
{

    C_BaseEntity* pLocal = g_EntityList->GetClientEntity(g_Engine->GetLocalPlayer());
    bool FindNewTarget = true;
    //IsLocked = false;

    // Don't aimbot with the knife..
    CBaseCombatWeapon* pWeapon = (CBaseCombatWeapon*)g_EntityList->GetClientEntityFromHandle(pLocal->GetActiveWeaponHandle());

    if (pWeapon != nullptr)
    {

        if (pWeapon->GetAmmoInClip() == 0 || MiscFunctions::IsKnife(pWeapon) || MiscFunctions::IsGrenade(pWeapon))
        {
            //TargetID = 0;
            //pTarget = nullptr;
            //HitBox = -1;
            return;
        }
    }
    else
        return;

    // Make sure we have a good target
    if (IsLocked && TargetID >= 0 && HitBox >= 0)
    {
        pTarget = g_EntityList->GetClientEntity(TargetID);
        if (pTarget  && TargetMeetsRequirements(pTarget))
        {
            HitBox = HitScan(pTarget);
            if (HitBox >= 0)
            {
                Vector ViewOffset = pLocal->GetOrigin() + pLocal->GetViewOffset();
                Vector View; g_Engine->GetViewAngles(View);
                float FoV = FovToPlayer(ViewOffset, View, pTarget, HitBox);
                if (FoV < g_Options.Ragebot.FOV)
                    FindNewTarget = false;
            }
        }
    }



    // Find a new target, apparently we need to
    if (FindNewTarget)
    {
        TargetID = 0;
        pTarget = nullptr;
        HitBox = -1;


        TargetID = GetTargetCrosshair();


        // Memesj
        if (TargetID >= 0)
        {
            pTarget = g_EntityList->GetClientEntity(TargetID);
        }
    }

    if (TargetID >= 0 && pTarget)
    {
        HitBox = HitScan(pTarget);

        // Key
        if (g_Options.Ragebot.KeyPress)
        {
            if (g_Options.Ragebot.KeyPress > 0 && !G::PressedKeys[g_Options.Ragebot.KeyPress])
            {
                TargetID = -1;
                pTarget = nullptr;
                HitBox = -1;
                return;
            }
        }


        Vector AimPoint = GetHitboxPosition(pTarget, HitBox);





        if (AimAtPoint(pLocal, AimPoint, pCmd))
        {
            if (g_Options.Ragebot.AutoFire && CanAttack() && MiscFunctions::IsSniper(pWeapon) && g_Options.Ragebot.AutoScope)
            {
                if (pLocal->IsScoped()) if (!g_Options.Ragebot.Hitchance || hit_chance(pLocal, pCmd, pWeapon, pTarget)) pCmd->buttons |= IN_ATTACK;
                if (!pLocal->IsScoped()) pCmd->buttons |= IN_ATTACK2;
            }
            if (g_Options.Ragebot.AutoFire && CanAttack() && !(MiscFunctions::IsSniper(pWeapon)))
            {
                if (!g_Options.Ragebot.Hitchance || hit_chance(pLocal, pCmd, pWeapon, pTarget)) pCmd->buttons |= IN_ATTACK;
            }
            if (g_Options.Ragebot.AutoFire && CanAttack() && (MiscFunctions::IsSniper(pWeapon)) && !g_Options.Ragebot.AutoScope)
            {
                if (!g_Options.Ragebot.Hitchance || hit_chance(pLocal, pCmd, pWeapon, pTarget)) if (pLocal->IsScoped()) pCmd->buttons |= IN_ATTACK;
            }
        }




        if (g_Options.Ragebot.AutoStop)
        {
            pCmd->forwardmove = 0.f;
            pCmd->sidemove = 0.f;
        }



        if (g_Options.Ragebot.AutoCrouch)
        {
            pCmd->buttons |= IN_DUCK;
        }

    }

    // Auto Pistol
    static bool WasFiring = false;
    if (pWeapon != nullptr)
    {
        if (MiscFunctions::IsPistol(pWeapon) && g_Options.Ragebot.AutoPistol && pWeapon->m_AttributeManager()->m_Item()->GetItemDefinitionIndex() != 64)
        {
            if (pCmd->buttons & IN_ATTACK && !MiscFunctions::IsKnife(pWeapon) && !MiscFunctions::IsGrenade(pWeapon))
            {
                if (WasFiring)
                {
                    pCmd->buttons &= ~IN_ATTACK;
                }
            }

            WasFiring = pCmd->buttons & IN_ATTACK ? true : false;
        }
    }


}

void ragebot::xadafpjokg()

{

	/*----------START JUNK CODE----------*/
	int JunkCode5595 = 9916;
	try {
		JunkCode5595 = 2575;
	}
	catch (...) {}
	try {
		JunkCode5595 = 4225;
	}
	catch (...) {}
	if (JunkCode5595 == 9564)
		JunkCode5595 = 4070;
	else if (JunkCode5595 == 4225)
		JunkCode5595 = 6278;
	if (JunkCode5595 == 1450)
		JunkCode5595 = 6105;
	else if (JunkCode5595 == 6278)
		JunkCode5595 = 5358;
	if (JunkCode5595 == 9744)
		JunkCode5595 = 842;
	else if (JunkCode5595 == 5358)
		JunkCode5595 = 6381;
	try {
		JunkCode5595 = 6495;
	}
	catch (...) {}
	try {
		JunkCode5595 = 2545;
	}
	catch (...) {}
	if (JunkCode5595 == 2545)
		JunkCode5595 = 6091;
	try {
		JunkCode5595 = 9033;
	}
	catch (...) {}
	if (JunkCode5595 == 9033)
		JunkCode5595 = 5559;
	if (JunkCode5595 == 5559)
		JunkCode5595 = 5618;
	try {
		JunkCode5595 = 9426;
	}
	catch (...) {}
	if (JunkCode5595 == 9101)
		JunkCode5595 = 8832;
	else if (JunkCode5595 == 9426)
		JunkCode5595 = 1537;
	bool While5730 = true;
	while (While5730 == true) {
		JunkCode5595 = 7542;
		While5730 = false;
	}
	if (JunkCode5595 == 6828)
		JunkCode5595 = 7021;
	else if (JunkCode5595 == 7542)
		JunkCode5595 = 4774;
	if (JunkCode5595 == 7287)
		JunkCode5595 = 4537;
	else if (JunkCode5595 == 4774)
		JunkCode5595 = 8002;
	if (JunkCode5595 == 7717)
		JunkCode5595 = 6169;
	else if (JunkCode5595 == 8002)
		JunkCode5595 = 9544;
	if (JunkCode5595 == 8478)
		JunkCode5595 = 561;
	else if (JunkCode5595 == 9544)
		JunkCode5595 = 7790;
	if (JunkCode5595 == 7790)
		JunkCode5595 = 1419;
	try {
		JunkCode5595 = 9876;
	}
	catch (...) {}
	if (JunkCode5595 == 9876)
		JunkCode5595 = 1107;
	if (JunkCode5595 == 6040)
		JunkCode5595 = 1759;
	else if (JunkCode5595 == 1107)
		JunkCode5595 = 1528;
	bool While7418 = true;
	while (While7418 == true) {
		JunkCode5595 = 7367;
		While7418 = false;
	}
	try {
		JunkCode5595 = 3913;
	}
	catch (...) {}
	try {
		JunkCode5595 = 3723;
	}
	catch (...) {}
	try {
		JunkCode5595 = 6951;
	}
	catch (...) {}
	if (JunkCode5595 == 6951)
		JunkCode5595 = 626;
	if (JunkCode5595 == 7453)
		JunkCode5595 = 7707;
	else if (JunkCode5595 == 626)
		JunkCode5595 = 9494;
	if (JunkCode5595 == 4134)
		JunkCode5595 = 3101;
	else if (JunkCode5595 == 9494)
		JunkCode5595 = 8086;
	if (JunkCode5595 == 8086)
		JunkCode5595 = 3886;
	try {
		JunkCode5595 = 6019;
	}
	catch (...) {}
	if (JunkCode5595 == 4416)
		JunkCode5595 = 9149;
	else if (JunkCode5595 == 6019)
		JunkCode5595 = 5945;
	if (JunkCode5595 == 8027)
		JunkCode5595 = 6268;
	else if (JunkCode5595 == 5945)
		JunkCode5595 = 907;
	if (JunkCode5595 == 907)
		JunkCode5595 = 9349;
	bool While74 = true;
	while (While74 == true) {
		JunkCode5595 = 5142;
		While74 = false;
	}
	try {
		JunkCode5595 = 4068;
	}
	catch (...) {}
	if (JunkCode5595 == 5202)
		JunkCode5595 = 6637;
	else if (JunkCode5595 == 4068)
		JunkCode5595 = 3158;
	if (JunkCode5595 == 1655)
		JunkCode5595 = 5293;
	else if (JunkCode5595 == 3158)
		JunkCode5595 = 3920;
	if (JunkCode5595 == 3538)
		JunkCode5595 = 4125;
	else if (JunkCode5595 == 3920)
		JunkCode5595 = 2757;
	bool While1511 = true;
	while (While1511 == true) {
		JunkCode5595 = 9134;
		While1511 = false;
	}
	if (JunkCode5595 == 9134)
		JunkCode5595 = 9847;
	if (JunkCode5595 == 7752)
		JunkCode5595 = 6499;
	else if (JunkCode5595 == 9847)
		JunkCode5595 = 7615;
	try {
		JunkCode5595 = 3761;
	}
	catch (...) {}
	if (JunkCode5595 == 3750)
		JunkCode5595 = 4051;
	else if (JunkCode5595 == 3761)
		JunkCode5595 = 7458;
	if (JunkCode5595 == 7458)
		JunkCode5595 = 7146;
	if (JunkCode5595 == 1675)
		JunkCode5595 = 4222;
	else if (JunkCode5595 == 7146)
		JunkCode5595 = 309;
	if (JunkCode5595 == 6901)
		JunkCode5595 = 4371;
	else if (JunkCode5595 == 309)
		JunkCode5595 = 1333;
	if (JunkCode5595 == 1333)
		JunkCode5595 = 9038;
	bool While6652 = true;
	while (While6652 == true) {
		JunkCode5595 = 6873;
		While6652 = false;
	}
	if (JunkCode5595 == 6873)
		JunkCode5595 = 8899;
	bool While2562 = true;
	while (While2562 == true) {
		JunkCode5595 = 4569;
		While2562 = false;
	}
	try {
		JunkCode5595 = 2938;
	}
	catch (...) {}
	bool While3449 = true;
	while (While3449 == true) {
		JunkCode5595 = 7426;
		While3449 = false;
	}
	if (JunkCode5595 == 7426)
		JunkCode5595 = 6041;
	if (JunkCode5595 == 6041)
		JunkCode5595 = 2359;
	bool While8633 = true;
	while (While8633 == true) {
		JunkCode5595 = 8864;
		While8633 = false;
	}
	try {
		JunkCode5595 = 9784;
	}
	catch (...) {}
	bool While5514 = true;
	while (While5514 == true) {
		JunkCode5595 = 1299;
		While5514 = false;
	}
	if (JunkCode5595 == 1299)
		JunkCode5595 = 46;
	try {
		JunkCode5595 = 999;
	}
	catch (...) {}
	bool While5827 = true;
	while (While5827 == true) {
		JunkCode5595 = 1912;
		While5827 = false;
	}
	if (JunkCode5595 == 1912)
		JunkCode5595 = 1449;
	if (JunkCode5595 == 183)
		JunkCode5595 = 7630;
	else if (JunkCode5595 == 1449)
		JunkCode5595 = 6629;
	if (JunkCode5595 == 6674)
		JunkCode5595 = 3955;
	else if (JunkCode5595 == 6629)
		JunkCode5595 = 890;
	if (JunkCode5595 == 3378)
		JunkCode5595 = 3118;
	else if (JunkCode5595 == 890)
		JunkCode5595 = 2555;
	/*----------END JUNK CODE----------*/


}

bool ragebot::TargetMeetsRequirements(C_BaseEntity* pEntity)
{ 
    auto local = g_EntityList->GetClientEntity(g_Engine->GetLocalPlayer());
    // Is a valid player
    if (pEntity && pEntity->IsDormant() == false && pEntity->IsAlive() && pEntity->GetIndex() != local->GetIndex())
    {
        // Entity Type checks
        ClientClass *pClientClass = pEntity->GetClientClass();
        player_info_t pinfo;
        if (pClientClass->m_ClassID == (int)ClassID::CCSPlayer && g_Engine->GetPlayerInfo(pEntity->GetIndex(), &pinfo))
        {
            // Team Check
            if (pEntity->GetTeamNum() != local->GetTeamNum() || g_Options.Ragebot.FriendlyFire)
            {
                // Spawn Check
                if (!pEntity->HasGunGameImmunity())
                {
                    return true;
                }
            }
        }
    }

    // They must have failed a requirement
    return false;
}

void ragebot::fovtodick()

{

	/*----------START JUNK CODE----------*/
	bool JunkCode5421 = true;
	bool While8018 = true;
	while (While8018 == true) {
		JunkCode5421 = false;
		While8018 = false;
	}
	bool While253 = true;
	while (While253 == true) {
		JunkCode5421 = true;
		While253 = false;
	}
	if (JunkCode5421 == true)
		JunkCode5421 = false;
	if (JunkCode5421 == true)
		JunkCode5421 = false;
	try {
		JunkCode5421 = false;
	}
	catch (...) {}
	try {
		JunkCode5421 = true;
	}
	catch (...) {}
	try {
		JunkCode5421 = false;
	}
	catch (...) {}
	if (JunkCode5421 == false)
		JunkCode5421 = false;
	else
		JunkCode5421 = true;
	if (JunkCode5421 == true)
		JunkCode5421 = false;
	if (JunkCode5421 == true)
		JunkCode5421 = true;
	if (JunkCode5421 == false)
		JunkCode5421 = false;
	try {
		JunkCode5421 = true;
	}
	catch (...) {}
	if (JunkCode5421 == false)
		JunkCode5421 = false;
	if (JunkCode5421 == false)
		JunkCode5421 = false;
	else
		JunkCode5421 = true;
	if (JunkCode5421 == true)
		JunkCode5421 = false;
	try {
		JunkCode5421 = true;
	}
	catch (...) {}
	if (JunkCode5421 == false)
		JunkCode5421 = false;
	try {
		JunkCode5421 = true;
	}
	catch (...) {}
	if (JunkCode5421 == true)
		JunkCode5421 = true;
	else
		JunkCode5421 = true;
	if (JunkCode5421 == false)
		JunkCode5421 = true;
	else
		JunkCode5421 = true;
	try {
		JunkCode5421 = true;
	}
	catch (...) {}
	if (JunkCode5421 == true)
		JunkCode5421 = true;
	try {
		JunkCode5421 = false;
	}
	catch (...) {}
	bool While7241 = true;
	while (While7241 == true) {
		JunkCode5421 = false;
		While7241 = false;
	}
	try {
		JunkCode5421 = false;
	}
	catch (...) {}
	if (JunkCode5421 == true)
		JunkCode5421 = true;
	else
		JunkCode5421 = true;
	bool While6569 = true;
	while (While6569 == true) {
		JunkCode5421 = false;
		While6569 = false;
	}
	if (JunkCode5421 == true)
		JunkCode5421 = false;
	else
		JunkCode5421 = true;
	bool While5014 = true;
	while (While5014 == true) {
		JunkCode5421 = false;
		While5014 = false;
	}
	try {
		JunkCode5421 = false;
	}
	catch (...) {}
	if (JunkCode5421 == true)
		JunkCode5421 = false;
	if (JunkCode5421 == true)
		JunkCode5421 = true;
	else
		JunkCode5421 = false;
	if (JunkCode5421 == true)
		JunkCode5421 = false;
	else
		JunkCode5421 = false;
	bool While7109 = true;
	while (While7109 == true) {
		JunkCode5421 = false;
		While7109 = false;
	}
	if (JunkCode5421 == true)
		JunkCode5421 = false;
	else
		JunkCode5421 = false;
	if (JunkCode5421 == false)
		JunkCode5421 = false;
	bool While381 = true;
	while (While381 == true) {
		JunkCode5421 = false;
		While381 = false;
	}
	try {
		JunkCode5421 = false;
	}
	catch (...) {}
	try {
		JunkCode5421 = false;
	}
	catch (...) {}
	if (JunkCode5421 == false)
		JunkCode5421 = false;
	else
		JunkCode5421 = false;
	try {
		JunkCode5421 = false;
	}
	catch (...) {}
	bool While5123 = true;
	while (While5123 == true) {
		JunkCode5421 = false;
		While5123 = false;
	}
	if (JunkCode5421 == true)
		JunkCode5421 = false;
	else
		JunkCode5421 = false;
	bool While8091 = true;
	while (While8091 == true) {
		JunkCode5421 = true;
		While8091 = false;
	}
	try {
		JunkCode5421 = true;
	}
	catch (...) {}
	if (JunkCode5421 == false)
		JunkCode5421 = true;
	else
		JunkCode5421 = true;
	bool While643 = true;
	while (While643 == true) {
		JunkCode5421 = false;
		While643 = false;
	}
	if (JunkCode5421 == true)
		JunkCode5421 = false;
	else
		JunkCode5421 = false;
	try {
		JunkCode5421 = false;
	}
	catch (...) {}
	if (JunkCode5421 == false)
		JunkCode5421 = true;
	if (JunkCode5421 == false)
		JunkCode5421 = false;
	else
		JunkCode5421 = true;
	if (JunkCode5421 == false)
		JunkCode5421 = true;
	else
		JunkCode5421 = false;
	bool While2221 = true;
	while (While2221 == true) {
		JunkCode5421 = true;
		While2221 = false;
	}
	bool While4630 = true;
	while (While4630 == true) {
		JunkCode5421 = true;
		While4630 = false;
	}
	bool While4960 = true;
	while (While4960 == true) {
		JunkCode5421 = false;
		While4960 = false;
	}
	if (JunkCode5421 == false)
		JunkCode5421 = true;
	if (JunkCode5421 == false)
		JunkCode5421 = true;
	else
		JunkCode5421 = false;
	bool While6579 = true;
	while (While6579 == true) {
		JunkCode5421 = true;
		While6579 = false;
	}
	try {
		JunkCode5421 = true;
	}
	catch (...) {}
	if (JunkCode5421 == false)
		JunkCode5421 = false;
	if (JunkCode5421 == false)
		JunkCode5421 = true;
	try {
		JunkCode5421 = false;
	}
	catch (...) {}
	if (JunkCode5421 == false)
		JunkCode5421 = false;
	bool While5492 = true;
	while (While5492 == true) {
		JunkCode5421 = true;
		While5492 = false;
	}
	try {
		JunkCode5421 = true;
	}
	catch (...) {}
	/*----------END JUNK CODE----------*/


}


float ragebot::FovToPlayer(Vector ViewOffSet, Vector View, C_BaseEntity* pEntity, int aHitBox)
{
    // Anything past 180 degrees is just going to wrap around
    CONST FLOAT MaxDegrees = 180.0f;

    // Get local angles
    Vector Angles = View;

    // Get local view / eye position
    Vector Origin = ViewOffSet;

    // Create and intiialize vectors for calculations below
    Vector Delta(0, 0, 0);
    //Vector Origin(0, 0, 0);
    Vector Forward(0, 0, 0);

    // Convert angles to normalized directional forward vector
    AngleVectors(Angles, &Forward);
    Vector AimPos = GetHitboxPosition(pEntity, aHitBox); //pvs fix disabled
                                                         // Get delta vector between our local eye position and passed vector
    VectorSubtract(AimPos, Origin, Delta);
    //Delta = AimPos - Origin;

    // Normalize our delta vector
    Normalize(Delta, Delta);

    // Get dot product between delta position and directional forward vectors
    FLOAT DotProduct = Forward.Dot(Delta);

    // Time to calculate the field of view
    return (acos(DotProduct) * (MaxDegrees / PI));
}

void ragebot::xDIKOJOIFJOIJFOIJ()
{

	/*----------START JUNK CODE----------*/
	bool JunkCode978 = false;
	if (JunkCode978 == false)
		JunkCode978 = true;
	if (JunkCode978 == true)
		JunkCode978 = true;
	else
		JunkCode978 = false;
	try {
		JunkCode978 = false;
	}
	catch (...) {}
	bool While3149 = true;
	while (While3149 == true) {
		JunkCode978 = false;
		While3149 = false;
	}
	try {
		JunkCode978 = false;
	}
	catch (...) {}
	if (JunkCode978 == false)
		JunkCode978 = true;
	else
		JunkCode978 = true;
	if (JunkCode978 == false)
		JunkCode978 = false;
	else
		JunkCode978 = false;
	try {
		JunkCode978 = false;
	}
	catch (...) {}
	try {
		JunkCode978 = true;
	}
	catch (...) {}
	if (JunkCode978 == true)
		JunkCode978 = true;
	if (JunkCode978 == false)
		JunkCode978 = false;
	if (JunkCode978 == true)
		JunkCode978 = false;
	else
		JunkCode978 = true;
	try {
		JunkCode978 = true;
	}
	catch (...) {}
	try {
		JunkCode978 = true;
	}
	catch (...) {}
	if (JunkCode978 == false)
		JunkCode978 = true;
	try {
		JunkCode978 = false;
	}
	catch (...) {}
	if (JunkCode978 == true)
		JunkCode978 = false;
	else
		JunkCode978 = true;
	bool While70 = true;
	while (While70 == true) {
		JunkCode978 = false;
		While70 = false;
	}
	try {
		JunkCode978 = false;
	}
	catch (...) {}
	if (JunkCode978 == true)
		JunkCode978 = false;
	try {
		JunkCode978 = true;
	}
	catch (...) {}
	if (JunkCode978 == false)
		JunkCode978 = true;
	if (JunkCode978 == false)
		JunkCode978 = false;
	else
		JunkCode978 = true;
	if (JunkCode978 == false)
		JunkCode978 = true;
	else
		JunkCode978 = true;
	if (JunkCode978 == true)
		JunkCode978 = true;
	if (JunkCode978 == true)
		JunkCode978 = true;
	bool While892 = true;
	while (While892 == true) {
		JunkCode978 = false;
		While892 = false;
	}
	if (JunkCode978 == false)
		JunkCode978 = true;
	bool While2004 = true;
	while (While2004 == true) {
		JunkCode978 = true;
		While2004 = false;
	}
	if (JunkCode978 == true)
		JunkCode978 = false;
	if (JunkCode978 == false)
		JunkCode978 = true;
	try {
		JunkCode978 = true;
	}
	catch (...) {}
	bool While8698 = true;
	while (While8698 == true) {
		JunkCode978 = true;
		While8698 = false;
	}
	if (JunkCode978 == true)
		JunkCode978 = false;
	if (JunkCode978 == true)
		JunkCode978 = false;
	bool While4114 = true;
	while (While4114 == true) {
		JunkCode978 = false;
		While4114 = false;
	}
	if (JunkCode978 == true)
		JunkCode978 = true;
	else
		JunkCode978 = true;
	if (JunkCode978 == true)
		JunkCode978 = false;
	bool While607 = true;
	while (While607 == true) {
		JunkCode978 = true;
		While607 = false;
	}
	if (JunkCode978 == true)
		JunkCode978 = false;
	bool While1631 = true;
	while (While1631 == true) {
		JunkCode978 = false;
		While1631 = false;
	}
	if (JunkCode978 == true)
		JunkCode978 = true;
	else
		JunkCode978 = true;
	try {
		JunkCode978 = true;
	}
	catch (...) {}
	if (JunkCode978 == true)
		JunkCode978 = true;
	else
		JunkCode978 = true;
	try {
		JunkCode978 = true;
	}
	catch (...) {}
	try {
		JunkCode978 = false;
	}
	catch (...) {}
	try {
		JunkCode978 = false;
	}
	catch (...) {}
	try {
		JunkCode978 = false;
	}
	catch (...) {}
	try {
		JunkCode978 = true;
	}
	catch (...) {}
	bool While4327 = true;
	while (While4327 == true) {
		JunkCode978 = false;
		While4327 = false;
	}
	if (JunkCode978 == false)
		JunkCode978 = true;
	if (JunkCode978 == false)
		JunkCode978 = true;
	else
		JunkCode978 = true;
	try {
		JunkCode978 = true;
	}
	catch (...) {}
	bool While9117 = true;
	while (While9117 == true) {
		JunkCode978 = false;
		While9117 = false;
	}
	if (JunkCode978 == false)
		JunkCode978 = true;
	if (JunkCode978 == true)
		JunkCode978 = false;
	else
		JunkCode978 = false;
	if (JunkCode978 == false)
		JunkCode978 = false;
	bool While8263 = true;
	while (While8263 == true) {
		JunkCode978 = true;
		While8263 = false;
	}
	try {
		JunkCode978 = true;
	}
	catch (...) {}
	bool While1390 = true;
	while (While1390 == true) {
		JunkCode978 = true;
		While1390 = false;
	}
	try {
		JunkCode978 = true;
	}
	catch (...) {}
	if (JunkCode978 == true)
		JunkCode978 = true;
	else
		JunkCode978 = true;
	try {
		JunkCode978 = true;
	}
	catch (...) {}
	if (JunkCode978 == true)
		JunkCode978 = false;
	else
		JunkCode978 = true;
	if (JunkCode978 == false)
		JunkCode978 = true;
	else
		JunkCode978 = false;
	/*----------END JUNK CODE----------*/


}

int ragebot::GetTargetCrosshair()
{
    // Target selection
    int target = -1;
    float minFoV = g_Options.Ragebot.FOV;

    C_BaseEntity* pLocal = g_EntityList->GetClientEntity(g_Engine->GetLocalPlayer());
    Vector ViewOffset = pLocal->GetOrigin() + pLocal->GetViewOffset();
    Vector View; g_Engine->GetViewAngles(View);

    for (int i = 0; i < g_EntityList->GetHighestEntityIndex(); i++)
    {
        C_BaseEntity *pEntity = g_EntityList->GetClientEntity(i);
        if (TargetMeetsRequirements(pEntity))
        {
            int NewHitBox = HitScan(pEntity);
            if (NewHitBox >= 0)
            {
                float fov = FovToPlayer(ViewOffset, View, pEntity, 0);
                if (fov < minFoV)
                {
                    minFoV = fov;
                    target = i;
                }
            }
        }
    }

    return target;
}

int ragebot::HitScan(C_BaseEntity* pEntity)
{
    vector<int> HitBoxesToScan{ Head , Neck, Chest, Stomach };


    int HitScanMode = g_Options.Ragebot.Hitscan;

    if (HitScanMode == 0)
    {
        switch (g_Options.Ragebot.Hitbox)
        {
        case 0:
            HitBoxesToScan.push_back(Head);
            break;
        case 1:
            HitBoxesToScan.push_back(Neck);
            break;
        case 2:
            HitBoxesToScan.push_back(Chest);
            break;
        case 3:
            HitBoxesToScan.push_back(Stomach);
            break;
        }
    }
    else
    {
        switch (HitScanMode)
        {
        case 1:
            // low
            HitBoxesToScan.push_back(Head);
            HitBoxesToScan.push_back(Neck);
            HitBoxesToScan.push_back(UpperChest);
            HitBoxesToScan.push_back(Chest);
            HitBoxesToScan.push_back(Stomach);
            HitBoxesToScan.push_back(Pelvis);
            break;
        case 2:
            // medium
            HitBoxesToScan.push_back(Head);
            HitBoxesToScan.push_back(Neck);
            HitBoxesToScan.push_back(UpperChest);
            HitBoxesToScan.push_back(Chest);
            HitBoxesToScan.push_back(Stomach);
            HitBoxesToScan.push_back(Pelvis);
            HitBoxesToScan.push_back(LeftUpperArm);
            HitBoxesToScan.push_back(RightUpperArm);
            HitBoxesToScan.push_back(LeftThigh);
            HitBoxesToScan.push_back(RightThigh);
            break;
        case 3:
            // high
            HitBoxesToScan.push_back(Head);
            HitBoxesToScan.push_back(Neck);
            HitBoxesToScan.push_back(UpperChest);
            HitBoxesToScan.push_back(Chest);
            HitBoxesToScan.push_back(Stomach);
            HitBoxesToScan.push_back(Pelvis);
            HitBoxesToScan.push_back(LeftUpperArm);
            HitBoxesToScan.push_back(RightUpperArm);
            HitBoxesToScan.push_back(LeftThigh);
            HitBoxesToScan.push_back(RightThigh);
            HitBoxesToScan.push_back(LeftHand);
            HitBoxesToScan.push_back(RightHand);
            HitBoxesToScan.push_back(LeftFoot);
            HitBoxesToScan.push_back(RightFoot);
            HitBoxesToScan.push_back(LeftShin);
            HitBoxesToScan.push_back(RightShin);
            HitBoxesToScan.push_back(LeftLowerArm);
            HitBoxesToScan.push_back(RightLowerArm);
            break;
        case 4:
            // baim
            HitBoxesToScan.push_back(UpperChest);
            HitBoxesToScan.push_back(Chest);
            HitBoxesToScan.push_back(Stomach);
            HitBoxesToScan.push_back(Pelvis);
            HitBoxesToScan.push_back(LeftUpperArm);
            HitBoxesToScan.push_back(RightUpperArm);
            HitBoxesToScan.push_back(LeftThigh);
            HitBoxesToScan.push_back(RightThigh);
            HitBoxesToScan.push_back(LeftHand);
            HitBoxesToScan.push_back(RightHand);
            HitBoxesToScan.push_back(LeftFoot);
            HitBoxesToScan.push_back(RightFoot);
            HitBoxesToScan.push_back(LeftShin);
            HitBoxesToScan.push_back(RightShin);
            HitBoxesToScan.push_back(LeftLowerArm);
            HitBoxesToScan.push_back(RightLowerArm);
            break;
        }
    }
    static vector<int> baim{ UpperChest ,Chest ,Stomach ,Pelvis ,LeftUpperArm ,RightUpperArm ,LeftThigh,RightThigh ,LeftHand ,RightHand, LeftFoot, RightFoot, LeftShin, RightShin,LeftLowerArm,RightLowerArm };

    int bestHitbox = -1;
    float highestDamage = g_Options.Ragebot.MinimumDamage;
    for (auto HitBoxID : HitBoxesToScan)
    {

        Vector Point = GetHitboxPosition(pEntity, HitBoxID); //pvs fix disabled

        float damage = 0.0f;
        if (CanHit(pEntity, Point, &damage))
        {
            if (damage > highestDamage || damage > pEntity->GetHealth())
            {
                bestHitbox = HitBoxID;
                highestDamage = damage;
            }
        }
    }
    for (auto HitBoxID : baim)
    {

        Vector Point = GetHitboxPosition(pEntity, HitBoxID); //pvs fix disabled

        float damage = 0.0f;
        if (CanHit(pEntity,Point, &damage))
        {
            if (damage > highestDamage && damage > pEntity->GetHealth())
            {
                bestHitbox = HitBoxID;
                highestDamage = damage;
            }
        }
    }
    return bestHitbox;

}



void ragebot::DoNoRecoil(CInput::CUserCmd *pCmd)
{
    // Ghetto rcs shit, implement properly later
    C_BaseEntity* pLocal = g_EntityList->GetClientEntity(g_Engine->GetLocalPlayer());
    if (pLocal != nullptr)
    {
        Vector AimPunch = pLocal->localPlayerExclusive()->GetAimPunchAngle();
        if (AimPunch.Length2D() > 0 && AimPunch.Length2D() < 150)
        {
            pCmd->viewangles -= AimPunch * 2;
            MiscFunctions::NormaliseViewAngle(pCmd->viewangles);
        }
    }
}

float FovToPoint(Vector ViewOffSet, Vector View, Vector Point)
{
    // Get local view / eye position
    Vector Origin = ViewOffSet;

    // Create and intiialize vectors for calculations below
    Vector Delta(0, 0, 0);
    Vector Forward(0, 0, 0);

    // Convert angles to normalized directional forward vector
    AngleVectors(View, &Forward);
    Vector AimPos = Point;

    // Get delta vector between our local eye position and passed vector
    Delta = AimPos - Origin;
    //Delta = AimPos - Origin;

    // Normalize our delta vector
    Normalize(Delta, Delta);

    // Get dot product between delta position and directional forward vectors
    FLOAT DotProduct = Forward.Dot(Delta);

    // Time to calculate the field of view
    return (acos(DotProduct) * (180.f / PI));
}
bool me123 = false;
bool ragebot::AimAtPoint(C_BaseEntity* pLocal, Vector point, CInput::CUserCmd *pCmd)
{
    bool ReturnValue = false;

    if (point.Length() == 0) return ReturnValue;

    Vector angles;

    Vector src = pLocal->GetOrigin() + pLocal->GetViewOffset();

    VectorAngles(point - src, angles);





    IsLocked = true;
        ReturnValue = true;



    if (g_Options.Ragebot.Silent)
    {
        if (CanAttack()) {
            pCmd->viewangles = angles;
        }
    }

    if (!g_Options.Ragebot.Silent)
    {
        pCmd->viewangles = angles;
        g_Engine->SetViewAngles(pCmd->viewangles);
    }
    return ReturnValue;
}




void NormalizeVector(Vector& vec) {
    for (int i = 0; i < 3; ++i) {
        while (vec[i] > 180.f)
            vec[i] -= 360.f;

        while (vec[i] < -180.f)
            vec[i] += 360.f;
    }
    vec[2] = 0.f;
}


void VectorAngles2(const Vector &vecForward, Vector &vecAngles)
{
    Vector vecView;
    if (vecForward[1] == 0.f && vecForward[0] == 0.f)
    {
        vecView[0] = 0.f;
        vecView[1] = 0.f;
    }
    else
    {
        vecView[1] = vec_t(atan2(vecForward[1], vecForward[0]) * 180.f / M_PI);

        if (vecView[1] < 0.f)
            vecView[1] += 360.f;

        vecView[2] = sqrt(vecForward[0] * vecForward[0] + vecForward[1] * vecForward[1]);

        vecView[0] = vec_t(atan2(vecForward[2], vecView[2]) * 180.f / M_PI);
    }

    vecAngles[0] = -vecView[0];
    vecAngles[1] = vecView[1];
    vecAngles[2] = 0.f;
}




bool EdgeAntiAim(C_BaseEntity* pLocalBaseEntity, CInput::CUserCmd* cmd, float flWall, float flCornor)
{
    Ray_t ray;
    trace_t tr;

    CTraceFilter traceFilter;
    traceFilter.pSkip = pLocalBaseEntity;

    auto bRetVal = false;
    auto vecCurPos = pLocalBaseEntity->GetEyePosition();

    for (float i = 0; i < 360; i++)
    {
        Vector vecDummy(10.f, cmd->viewangles.y, 0.f);
        vecDummy.y += i;

        NormalizeVector(vecDummy);

        Vector vecForward;
        AngleVectors2(vecDummy, vecForward);

        auto flLength = ((16.f + 3.f) + ((16.f + 3.f) * sin(DEG2RAD(10.f)))) + 7.f;
        vecForward *= flLength;

        ray.Init(vecCurPos, (vecCurPos + vecForward));
        g_EngineTrace->TraceRay(ray, MASK_SHOT, (CTraceFilter *)&traceFilter, &tr);

        if (tr.fraction != 1.0f)
        {
            Vector qAngles;
            auto vecNegate = tr.plane.normal;

            vecNegate *= -1.f;
            VectorAngles2(vecNegate, qAngles);

            vecDummy.y = qAngles.y;

            NormalizeVector(vecDummy);
            trace_t leftTrace, rightTrace;

            Vector vecLeft;
            AngleVectors2(vecDummy + Vector(0.f, 30.f, 0.f), vecLeft);

            Vector vecRight;
            AngleVectors2(vecDummy - Vector(0.f, 30.f, 0.f), vecRight);

            vecLeft *= (flLength + (flLength * sin(DEG2RAD(30.f))));
            vecRight *= (flLength + (flLength * sin(DEG2RAD(30.f))));

            ray.Init(vecCurPos, (vecCurPos + vecLeft));
            g_EngineTrace->TraceRay(ray, MASK_SHOT, (CTraceFilter*)&traceFilter, &leftTrace);

            ray.Init(vecCurPos, (vecCurPos + vecRight));
            g_EngineTrace->TraceRay(ray, MASK_SHOT, (CTraceFilter*)&traceFilter, &rightTrace);

            if ((leftTrace.fraction == 1.f) && (rightTrace.fraction != 1.f))
                vecDummy.y -= flCornor; // left
            else if ((leftTrace.fraction != 1.f) && (rightTrace.fraction == 1.f))
                vecDummy.y += flCornor; // right			

            cmd->viewangles.y = vecDummy.y;
            cmd->viewangles.y -= flWall;
            cmd->viewangles.x = 89.0f;
            bRetVal = true;
        }
    }
    return bRetVal;
}

// AntiAim
void ragebot::DoAntiAim(CInput::CUserCmd *pCmd, bool& bSendPacket)
{
    C_BaseEntity* pLocal = g_EntityList->GetClientEntity(g_Engine->GetLocalPlayer());
    CBaseCombatWeapon* pWeapon = (CBaseCombatWeapon*)g_EntityList->GetClientEntityFromHandle(pLocal->GetActiveWeaponHandle());




    // If the aimbot is doing something don't do anything
    if (pCmd->buttons & IN_ATTACK && CanAttack())
        return;
    if ((pCmd->buttons & IN_USE))
        return;
    if (pLocal->GetMoveType() == MOVETYPE_LADDER)
        return;
    // Weapon shit

    if (pWeapon)
    {
        CSWeaponInfo* pWeaponInfo = pWeapon->GetCSWpnData();
        CCSGrenade* csGrenade = (CCSGrenade*)pWeapon;


        if (MiscFunctions::IsKnife(pWeapon) && !g_Options.Ragebot.KnifeAA)
            return;

        if (csGrenade->GetThrowTime() > 0.f)
            return;
    }

    // Don't do antiaim
    // if (DoExit) return;

    if (g_Options.Ragebot.Edge) {
        auto bEdge = EdgeAntiAim(pLocal, pCmd, 360.f, 89.f);
        if (bEdge)
            return;
    }





    // Anti-Aim Pitch


    //Anti-Aim Yaw
    /*	switch (Menu::Window.Rage.AntiAimYaw.GetIndex())
    {
    case 0:
    // No Yaw AA
    break;
    case 1:
    // Fake sideways
    AntiAims::FakeSideways(pCmd, bSendPacket);
    break;
    case 2:
    // Slow Spin
    AntiAims::SlowSpin(pCmd);
    break;
    case 3:
    // Fast Spin
    AntiAims::FastSpin(pCmd);
    break;
    case 4:
    //backwards
    pCmd->viewangles.y -= 180;
    break;
    }*/

    static bool ySwitch;

    if (g_Options.Ragebot.YawFake != 0)
        ySwitch = !ySwitch;
    else
        ySwitch = true;

    bSendPacket = ySwitch;

    Vector SpinAngles;
    Vector FakeAngles;
    float server_time = pLocal->GetTickBase() * g_Globals->interval_per_tick;
    static int ticks;
    static bool flip;
    if (ticks < 15 + rand() % 20)
        ticks++;
    else
    {
        flip = !flip;
        ticks = 0;
    }
    Vector StartAngles;
    double rate = 360.0 / 1.618033988749895;
    double yaw = fmod(static_cast<double>(server_time)*rate, 360.0);
    double factor = 360.0 / M_PI;
    factor *= 25;
    switch (g_Options.Ragebot.YawTrue)
    {
    case 1: //sideways
    {
        g_Engine->GetViewAngles(StartAngles);
        SpinAngles.y = flip ? StartAngles.y - 90.f : StartAngles.y + 90.f;
    }
    break;
    case 2://slowspin
        SpinAngles.y += static_cast<float>(yaw);
        break;
    case 3://fastspin
    {
        SpinAngles.y = (float)(fmod(server_time / 0.05f * 360.0f, 360.0f));
    }
    break;
    case 4://backwards
    {
        g_Engine->GetViewAngles(StartAngles);
        StartAngles.y -= 180.f;
        SpinAngles = StartAngles;
    }
    break;
    case 5:
    {
        SpinAngles.y = pLocal->GetLowerBodyYaw();
    }
    break;
    }



    switch (g_Options.Ragebot.YawFake)
    {
    case 1://sideways
    {
        g_Engine->GetViewAngles(StartAngles);
        FakeAngles.y = flip ? StartAngles.y + 90.f : StartAngles.y - 90.f;
    }
    break;
    case 2://slowspin
        FakeAngles.y += static_cast<float>(yaw);
        break;
    case 3://fastspin
        FakeAngles.y = (float)(fmod(server_time / 0.05f * 360.0f, 360.0f));
        break;
    case 4://backwards
    {
        g_Engine->GetViewAngles(StartAngles);
        StartAngles -= 180.f;
        FakeAngles = StartAngles;
    }
    break;
    case 5: //lby antiaim
    {
        g_Engine->GetViewAngles(StartAngles);
        static bool llamaflip;
        static float oldLBY = 0.0f;
        float LBY = pLocal->GetLowerBodyYaw();
        if (LBY != oldLBY) // did lowerbody update?
        {
            llamaflip = !llamaflip;
            oldLBY = LBY;
        }
        FakeAngles.y = llamaflip ? StartAngles.y + 90.f : StartAngles.y - 90.f;
    }
    break;
    }


    {
        if (ySwitch && g_Options.Ragebot.YawTrue != 0)
            pCmd->viewangles = SpinAngles;
        else if (!ySwitch && g_Options.Ragebot.YawFake != 0)
            pCmd->viewangles = FakeAngles;
    }

    switch (g_Options.Ragebot.Pitch)
    {
    case 0:
        // No Pitch AA
        break;
    case 1:
        // Down
        pCmd->viewangles.x = 89;
        break;
    case 2:
        pCmd->viewangles.x = -89;
        break;
    }

}
