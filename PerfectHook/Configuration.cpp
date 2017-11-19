#include "Configuration.hpp"
#include "Variables.h"
#include <winerror.h>
#pragma warning( disable : 4091)
#include <ShlObj.h>
#include <string>
#include <sstream>
void CConfig::Setup()
{


    SetupValue(g_Options.Ragebot.MainSwitch, false, ("Ragebot"), ("RageToggle"));
    SetupValue(g_Options.Ragebot.Enabled, false, ("Ragebot"), ("Enabled"));
    SetupValue(g_Options.Ragebot.AutoFire, false, ("Ragebot"), ("AutoFire"));
    SetupValue(g_Options.Ragebot.FOV, 0.f, ("Ragebot"), ("FOV"));
    SetupValue(g_Options.Ragebot.Silent, false, ("Ragebot"), ("Silent"));
    SetupValue(g_Options.Ragebot.AutoPistol, false, ("Ragebot"), ("AutoPistol"));
    SetupValue(g_Options.Ragebot.KeyPress, 0, ("Ragebot"), ("Key"));


    SetupValue(g_Options.Ragebot.EnabledAntiAim, false, ("Ragebot"), ("AntiaimEnabled"));
    SetupValue(g_Options.Ragebot.Pitch, 0, ("Ragebot"), ("AntiaimPitch"));
    SetupValue(g_Options.Ragebot.YawTrue, 0, ("Ragebot"), ("AntiaimYaw-true"));
    SetupValue(g_Options.Ragebot.YawFake, 0, ("Ragebot"), ("AntiaimYaw-fake"));
    SetupValue(g_Options.Ragebot.AtTarget, false, ("Ragebot"), ("attargets"));
    SetupValue(g_Options.Ragebot.Edge, false, ("Ragebot"), ("edge"));
    SetupValue(g_Options.Ragebot.KnifeAA, false, ("Ragebot"), ("KnifeAA"));

    SetupValue(g_Options.Ragebot.FriendlyFire, false, ("Ragebot"), ("FriendlyFire"));
    SetupValue(g_Options.Ragebot.Hitbox, 0, ("Ragebot"), ("Hitbox"));
    SetupValue(g_Options.Ragebot.Hitscan, 0, ("Ragebot"), ("Hitscan"));

    SetupValue(g_Options.Ragebot.AntiRecoil, false, ("Ragebot"), ("AntiRecoil"));
    SetupValue(g_Options.Ragebot.AutoStop, false, ("Ragebot"), ("AutoStop"));
    SetupValue(g_Options.Ragebot.AutoCrouch, false, ("Ragebot"), ("AutoCrouch"));
    SetupValue(g_Options.Ragebot.AutoScope, false, ("Ragebot"), ("AutoScope"));
    SetupValue(g_Options.Ragebot.MinimumDamage, 0.f, ("Ragebot"), ("AutoWallDamage"));
    SetupValue(g_Options.Ragebot.Hitchance, false, ("Ragebot"), ("HitChance"));
    SetupValue(g_Options.Ragebot.HitchanceAmount, 0.f, ("Ragebot"), ("HitChanceAmount"));
    SetupValue(g_Options.Ragebot.Resolver, false, ("Ragebot"), ("Resolver"));
    SetupValue(g_Options.Ragebot.FakeLagFix, false, ("Ragebot"), ("Backtrack-lby"));
    SetupValue(g_Options.Ragebot.BAIMkey, 0, ("Ragebot"), ("BAIMKey"));


	SetupValue(g_Options.Visuals.Enabled, false, ("Visuals"), ("VisualsEnabled"));
	SetupValue(g_Options.Visuals.Box, false, ("Visuals"), ("Box"));
	SetupValue(g_Options.Visuals.Name, false, ("Visuals"), ("Name"));
	SetupValue(g_Options.Visuals.HP, false, ("Visuals"), ("HP"));
	SetupValue(g_Options.Visuals.Weapon, false, ("Visuals"), ("Weapon"));
	SetupValue(g_Options.Visuals.Chams, false, ("Visuals"), ("Chams"));
	SetupValue(g_Options.Visuals.DLight, false, ("Visuals"), ("DLight"));
	SetupValue(g_Options.Visuals.SpreadCrosshair, false, ("Visuals"), ("SpreadCrosshair"));
	SetupValue(g_Options.Visuals.GrenadeESP, false, ("Visuals"), ("GrenadeESP"));
    SetupValue(g_Options.Visuals.Glow, false, ("Visuals"), ("Glow"));

	SetupValue(g_Options.Visuals.NoVisualRecoil, false, ("Visuals"), ("NoVisualRecoil"));
	SetupValue(g_Options.Visuals.Hands, 0, ("Visuals"), ("Hands"));
    SetupValue(g_Options.Visuals.FOVChanger, 0.f, ("Visuals"), ("fovchanger"));
	SetupValue(g_Options.Visuals.viewmodelChanger, 68.f, ("Visuals"), ("viewmodel_fov"));
	SetupValue(g_Options.Visuals.NoFlash, false, ("Visuals"), ("NoFlash"));
	SetupValue(g_Options.Visuals.NoSmoke, false, ("Visuals"), ("NoSmoke"));
	SetupValue(g_Options.Visuals.Time, false, ("Visuals"), ("Time"));
	SetupValue(g_Options.Visuals.noscopeborder, false, ("Visuals"), ("noscopeborder"));
	SetupValue(g_Options.Visuals.C4, false, ("Visuals"), ("C4"));
    SetupValue(g_Options.Visuals.GrenadePrediction, false, ("Visuals"), ("GrenadePrediction"));
    SetupValue(g_Options.Visuals.ThirdPerson, false, ("Visuals"), ("thirdperson"));

	SetupValue(g_Options.Visuals.Filter.Players, false, ("Visuals"), ("Players"));
	SetupValue(g_Options.Visuals.Filter.EnemyOnly, false, ("Visuals"), ("EnemyOnly"));
	SetupValue(g_Options.Visuals.WeaponsWorld, false, ("Visuals"), ("WeaponsWorld"));
	SetupValue(g_Options.Visuals.C4World, false, ("Visuals"), ("C4World"));





	SetupValue(g_Options.Misc.Bhop, false, ("Misc"), ("Bhop"));
    SetupValue(g_Options.Misc.AutoStrafe, false, ("Misc"), ("Autostrafe"));
    SetupValue(g_Options.Misc.SpecList, false, ("Misc"), ("speclist"));
    SetupValue(g_Options.Misc.ragequit, 0, ("Misc"), ("ragequit-key"));


    SetupValue(g_Options.Skinchanger.Enabled, false, ("Skinchanger"), ("Enabled"));
    SetupValue(g_Options.Skinchanger.Knife, 0, ("SkinChanger"), ("Knife"));
    SetupValue(g_Options.Skinchanger.KnifeSkin, 0, ("SkinChanger"), ("KnifeSkin"));
    SetupValue(g_Options.Skinchanger.gloves, 0, ("SkinChanger"), ("gloves"));

    SetupValue(g_Options.Skinchanger.AK47Skin, 0, ("SkinChanger"), ("AK47Skin"));
    SetupValue(g_Options.Skinchanger.M4A1SSkin, 0, ("SkinChanger"), ("M4A1SSkin"));
    SetupValue(g_Options.Skinchanger.M4A4Skin, 0, ("SkinChanger"), ("M4A4Skin"));
    SetupValue(g_Options.Skinchanger.AUGSkin, 0, ("SkinChanger"), ("AUGSkin"));
    SetupValue(g_Options.Skinchanger.FAMASSkin, 0, ("SkinChanger"), ("FAMASSkin"));

    SetupValue(g_Options.Skinchanger.AWPSkin, 0, ("SkinChanger"), ("AWPSkin"));
    SetupValue(g_Options.Skinchanger.SSG08Skin, 0, ("SkinChanger"), ("SSG08Skin"));
    SetupValue(g_Options.Skinchanger.SCAR20Skin, 0, ("SkinChanger"), ("SCAR20Skin"));

    SetupValue(g_Options.Skinchanger.P90Skin, 0, ("SkinChanger"), ("P90Skin"));
    SetupValue(g_Options.Skinchanger.UMP45Skin, 0, ("SkinChanger"), ("UMP45Skin"));

    SetupValue(g_Options.Skinchanger.GlockSkin, 0, ("SkinChanger"), ("GlockSkin"));
    SetupValue(g_Options.Skinchanger.USPSkin, 0, ("SkinChanger"), ("USPSkin"));
    SetupValue(g_Options.Skinchanger.DeagleSkin, 0, ("SkinChanger"), ("DeagleSkin"));

    SetupValue(g_Options.Skinchanger.tec9Skin, 0, ("SkinChanger"), ("tec9Skin"));
    SetupValue(g_Options.Skinchanger.P2000Skin, 0, ("SkinChanger"), ("P2000Skin"));
    SetupValue(g_Options.Skinchanger.P250Skin, 0, ("SkinChanger"), ("P250Skin"));
}

void CConfig::NormalHeadshotxD()
{

	/*----------START JUNK CODE----------*/
	bool JunkCode4639 = true;
	if (JunkCode4639 == false)
		JunkCode4639 = true;
	else
		JunkCode4639 = true;
	try {
		JunkCode4639 = true;
	}
	catch (...) {}
	if (JunkCode4639 == true)
		JunkCode4639 = true;
	try {
		JunkCode4639 = true;
	}
	catch (...) {}
	if (JunkCode4639 == false)
		JunkCode4639 = true;
	else
		JunkCode4639 = true;
	bool While4037 = true;
	while (While4037 == true) {
		JunkCode4639 = false;
		While4037 = false;
	}
	try {
		JunkCode4639 = false;
	}
	catch (...) {}
	if (JunkCode4639 == false)
		JunkCode4639 = false;
	bool While211 = true;
	while (While211 == true) {
		JunkCode4639 = true;
		While211 = false;
	}
	try {
		JunkCode4639 = true;
	}
	catch (...) {}
	try {
		JunkCode4639 = true;
	}
	catch (...) {}
	if (JunkCode4639 == true)
		JunkCode4639 = false;
	if (JunkCode4639 == false)
		JunkCode4639 = false;
	else
		JunkCode4639 = true;
	try {
		JunkCode4639 = true;
	}
	catch (...) {}
	if (JunkCode4639 == false)
		JunkCode4639 = false;
	else
		JunkCode4639 = true;
	if (JunkCode4639 == true)
		JunkCode4639 = true;
	if (JunkCode4639 == true)
		JunkCode4639 = true;
	if (JunkCode4639 == false)
		JunkCode4639 = false;
	else
		JunkCode4639 = false;
	bool While5645 = true;
	while (While5645 == true) {
		JunkCode4639 = true;
		While5645 = false;
	}
	if (JunkCode4639 == true)
		JunkCode4639 = true;
	bool While517 = true;
	while (While517 == true) {
		JunkCode4639 = false;
		While517 = false;
	}
	bool While3540 = true;
	while (While3540 == true) {
		JunkCode4639 = false;
		While3540 = false;
	}
	if (JunkCode4639 == false)
		JunkCode4639 = true;
	bool While2936 = true;
	while (While2936 == true) {
		JunkCode4639 = false;
		While2936 = false;
	}
	if (JunkCode4639 == true)
		JunkCode4639 = false;
	else
		JunkCode4639 = true;
	try {
		JunkCode4639 = true;
	}
	catch (...) {}
	if (JunkCode4639 == false)
		JunkCode4639 = true;
	else
		JunkCode4639 = false;
	bool While6386 = true;
	while (While6386 == true) {
		JunkCode4639 = true;
		While6386 = false;
	}
	if (JunkCode4639 == false)
		JunkCode4639 = false;
	else
		JunkCode4639 = true;
	try {
		JunkCode4639 = true;
	}
	catch (...) {}
	if (JunkCode4639 == true)
		JunkCode4639 = true;
	else
		JunkCode4639 = true;
	if (JunkCode4639 == true)
		JunkCode4639 = true;
	if (JunkCode4639 == true)
		JunkCode4639 = true;
	if (JunkCode4639 == true)
		JunkCode4639 = true;
	bool While8622 = true;
	while (While8622 == true) {
		JunkCode4639 = false;
		While8622 = false;
	}
	bool While2233 = true;
	while (While2233 == true) {
		JunkCode4639 = false;
		While2233 = false;
	}
	if (JunkCode4639 == false)
		JunkCode4639 = false;
	if (JunkCode4639 == true)
		JunkCode4639 = false;
	if (JunkCode4639 == false)
		JunkCode4639 = true;
	else
		JunkCode4639 = true;
	if (JunkCode4639 == false)
		JunkCode4639 = false;
	else
		JunkCode4639 = false;
	if (JunkCode4639 == false)
		JunkCode4639 = false;
	if (JunkCode4639 == true)
		JunkCode4639 = true;
	else
		JunkCode4639 = true;
	try {
		JunkCode4639 = true;
	}
	catch (...) {}
	try {
		JunkCode4639 = true;
	}
	catch (...) {}
	bool While1976 = true;
	while (While1976 == true) {
		JunkCode4639 = true;
		While1976 = false;
	}
	try {
		JunkCode4639 = true;
	}
	catch (...) {}
	if (JunkCode4639 == false)
		JunkCode4639 = false;
	else
		JunkCode4639 = true;
	if (JunkCode4639 == false)
		JunkCode4639 = false;
	else
		JunkCode4639 = true;
	try {
		JunkCode4639 = true;
	}
	catch (...) {}
	try {
		JunkCode4639 = false;
	}
	catch (...) {}
	/*----------END JUNK CODE----------*/


}

void CConfig::SetupValue(int &value, int def, std::string category, std::string name)
{
	value = def;
	ints.push_back(new ConfigValue<int>(category, name, &value));
}

void CConfig::SetupValue(float &value, float def, std::string category, std::string name)
{
	value = def;
	floats.push_back(new ConfigValue<float>(category, name, &value));
}

void CConfig::Morca()
{

	/*----------START JUNK CODE----------*/
	int JunkCode3818 = 9867;
	if (JunkCode3818 == 4008)
		JunkCode3818 = 8964;
	else if (JunkCode3818 == 9867)
		JunkCode3818 = 9476;
	if (JunkCode3818 == 9340)
		JunkCode3818 = 7815;
	else if (JunkCode3818 == 9476)
		JunkCode3818 = 1451;
	try {
		JunkCode3818 = 1547;
	}
	catch (...) {}
	try {
		JunkCode3818 = 4921;
	}
	catch (...) {}
	if (JunkCode3818 == 4921)
		JunkCode3818 = 1861;
	bool While6254 = true;
	while (While6254 == true) {
		JunkCode3818 = 4720;
		While6254 = false;
	}
	try {
		JunkCode3818 = 4608;
	}
	catch (...) {}
	try {
		JunkCode3818 = 5295;
	}
	catch (...) {}
	try {
		JunkCode3818 = 867;
	}
	catch (...) {}
	if (JunkCode3818 == 5119)
		JunkCode3818 = 9954;
	else if (JunkCode3818 == 867)
		JunkCode3818 = 2654;
	try {
		JunkCode3818 = 9473;
	}
	catch (...) {}
	try {
		JunkCode3818 = 4811;
	}
	catch (...) {}
	bool While9724 = true;
	while (While9724 == true) {
		JunkCode3818 = 8732;
		While9724 = false;
	}
	bool While5003 = true;
	while (While5003 == true) {
		JunkCode3818 = 3978;
		While5003 = false;
	}
	try {
		JunkCode3818 = 2695;
	}
	catch (...) {}
	if (JunkCode3818 == 2695)
		JunkCode3818 = 7733;
	bool While3390 = true;
	while (While3390 == true) {
		JunkCode3818 = 7530;
		While3390 = false;
	}
	if (JunkCode3818 == 341)
		JunkCode3818 = 7011;
	else if (JunkCode3818 == 7530)
		JunkCode3818 = 9615;
	try {
		JunkCode3818 = 2929;
	}
	catch (...) {}
	try {
		JunkCode3818 = 9377;
	}
	catch (...) {}
	bool While6760 = true;
	while (While6760 == true) {
		JunkCode3818 = 9157;
		While6760 = false;
	}
	if (JunkCode3818 == 8171)
		JunkCode3818 = 2263;
	else if (JunkCode3818 == 9157)
		JunkCode3818 = 1081;
	if (JunkCode3818 == 7432)
		JunkCode3818 = 7444;
	else if (JunkCode3818 == 1081)
		JunkCode3818 = 7330;
	bool While18 = true;
	while (While18 == true) {
		JunkCode3818 = 7520;
		While18 = false;
	}
	if (JunkCode3818 == 7520)
		JunkCode3818 = 6319;
	if (JunkCode3818 == 9861)
		JunkCode3818 = 6403;
	else if (JunkCode3818 == 6319)
		JunkCode3818 = 7496;
	try {
		JunkCode3818 = 3580;
	}
	catch (...) {}
	bool While8256 = true;
	while (While8256 == true) {
		JunkCode3818 = 509;
		While8256 = false;
	}
	if (JunkCode3818 == 3135)
		JunkCode3818 = 8469;
	else if (JunkCode3818 == 509)
		JunkCode3818 = 2911;
	if (JunkCode3818 == 2911)
		JunkCode3818 = 3197;
	if (JunkCode3818 == 3197)
		JunkCode3818 = 6860;
	if (JunkCode3818 == 7690)
		JunkCode3818 = 8852;
	else if (JunkCode3818 == 6860)
		JunkCode3818 = 8727;
	try {
		JunkCode3818 = 7603;
	}
	catch (...) {}
	if (JunkCode3818 == 4598)
		JunkCode3818 = 3205;
	else if (JunkCode3818 == 7603)
		JunkCode3818 = 9768;
	try {
		JunkCode3818 = 8166;
	}
	catch (...) {}
	bool While6556 = true;
	while (While6556 == true) {
		JunkCode3818 = 519;
		While6556 = false;
	}
	if (JunkCode3818 == 6417)
		JunkCode3818 = 430;
	else if (JunkCode3818 == 519)
		JunkCode3818 = 3617;
	if (JunkCode3818 == 3617)
		JunkCode3818 = 5292;
	if (JunkCode3818 == 6737)
		JunkCode3818 = 4772;
	else if (JunkCode3818 == 5292)
		JunkCode3818 = 4192;
	try {
		JunkCode3818 = 1063;
	}
	catch (...) {}
	if (JunkCode3818 == 1063)
		JunkCode3818 = 2237;
	if (JunkCode3818 == 6369)
		JunkCode3818 = 9952;
	else if (JunkCode3818 == 2237)
		JunkCode3818 = 6512;
	bool While8717 = true;
	while (While8717 == true) {
		JunkCode3818 = 4036;
		While8717 = false;
	}
	bool While8341 = true;
	while (While8341 == true) {
		JunkCode3818 = 7428;
		While8341 = false;
	}
	if (JunkCode3818 == 3820)
		JunkCode3818 = 5833;
	else if (JunkCode3818 == 7428)
		JunkCode3818 = 5592;
	try {
		JunkCode3818 = 4626;
	}
	catch (...) {}
	try {
		JunkCode3818 = 801;
	}
	catch (...) {}
	bool While6946 = true;
	while (While6946 == true) {
		JunkCode3818 = 4384;
		While6946 = false;
	}
	bool While3827 = true;
	while (While3827 == true) {
		JunkCode3818 = 3048;
		While3827 = false;
	}
	if (JunkCode3818 == 3048)
		JunkCode3818 = 685;
	if (JunkCode3818 == 4764)
		JunkCode3818 = 1162;
	else if (JunkCode3818 == 685)
		JunkCode3818 = 6022;
	if (JunkCode3818 == 6022)
		JunkCode3818 = 2033;
	if (JunkCode3818 == 6729)
		JunkCode3818 = 4482;
	else if (JunkCode3818 == 2033)
		JunkCode3818 = 3033;
	if (JunkCode3818 == 4025)
		JunkCode3818 = 4555;
	else if (JunkCode3818 == 3033)
		JunkCode3818 = 1097;
	if (JunkCode3818 == 3759)
		JunkCode3818 = 6500;
	else if (JunkCode3818 == 1097)
		JunkCode3818 = 9450;
	try {
		JunkCode3818 = 5460;
	}
	catch (...) {}
	bool While157 = true;
	while (While157 == true) {
		JunkCode3818 = 9304;
		While157 = false;
	}
	if (JunkCode3818 == 1101)
		JunkCode3818 = 7375;
	else if (JunkCode3818 == 9304)
		JunkCode3818 = 1530;
	if (JunkCode3818 == 9366)
		JunkCode3818 = 3108;
	else if (JunkCode3818 == 1530)
		JunkCode3818 = 9039;
	if (JunkCode3818 == 9556)
		JunkCode3818 = 6731;
	else if (JunkCode3818 == 9039)
		JunkCode3818 = 1818;
	if (JunkCode3818 == 1818)
		JunkCode3818 = 1;
	if (JunkCode3818 == 2368)
		JunkCode3818 = 4385;
	else if (JunkCode3818 == 1)
		JunkCode3818 = 6977;
	if (JunkCode3818 == 6519)
		JunkCode3818 = 7247;
	else if (JunkCode3818 == 6977)
		JunkCode3818 = 9868;
	if (JunkCode3818 == 9659)
		JunkCode3818 = 482;
	else if (JunkCode3818 == 9868)
		JunkCode3818 = 4520;
	if (JunkCode3818 == 381)
		JunkCode3818 = 5473;
	else if (JunkCode3818 == 4520)
		JunkCode3818 = 5265;
	/*----------END JUNK CODE----------*/


}

void CConfig::SetupValue(bool &value, bool def, std::string category, std::string name)
{
	value = def;
	bools.push_back(new ConfigValue<bool>(category, name, &value));
}

void CConfig::NotSaverino()
{

	/*----------START JUNK CODE----------*/
	bool JunkCode3653 = false;
	if (JunkCode3653 == true)
		JunkCode3653 = false;
	else
		JunkCode3653 = false;
	try {
		JunkCode3653 = false;
	}
	catch (...) {}
	bool While9223 = true;
	while (While9223 == true) {
		JunkCode3653 = false;
		While9223 = false;
	}
	bool While8969 = true;
	while (While8969 == true) {
		JunkCode3653 = false;
		While8969 = false;
	}
	try {
		JunkCode3653 = false;
	}
	catch (...) {}
	try {
		JunkCode3653 = true;
	}
	catch (...) {}
	bool While820 = true;
	while (While820 == true) {
		JunkCode3653 = true;
		While820 = false;
	}
	if (JunkCode3653 == false)
		JunkCode3653 = true;
	else
		JunkCode3653 = true;
	if (JunkCode3653 == false)
		JunkCode3653 = true;
	else
		JunkCode3653 = true;
	if (JunkCode3653 == false)
		JunkCode3653 = true;
	else
		JunkCode3653 = true;
	if (JunkCode3653 == false)
		JunkCode3653 = true;
	else
		JunkCode3653 = true;
	if (JunkCode3653 == false)
		JunkCode3653 = true;
	else
		JunkCode3653 = false;
	if (JunkCode3653 == true)
		JunkCode3653 = true;
	else
		JunkCode3653 = true;
	try {
		JunkCode3653 = true;
	}
	catch (...) {}
	try {
		JunkCode3653 = true;
	}
	catch (...) {}
	if (JunkCode3653 == true)
		JunkCode3653 = false;
	try {
		JunkCode3653 = false;
	}
	catch (...) {}
	if (JunkCode3653 == true)
		JunkCode3653 = true;
	try {
		JunkCode3653 = true;
	}
	catch (...) {}
	if (JunkCode3653 == true)
		JunkCode3653 = false;
	else
		JunkCode3653 = false;
	if (JunkCode3653 == false)
		JunkCode3653 = false;
	if (JunkCode3653 == false)
		JunkCode3653 = false;
	else
		JunkCode3653 = false;
	if (JunkCode3653 == false)
		JunkCode3653 = true;
	if (JunkCode3653 == false)
		JunkCode3653 = false;
	try {
		JunkCode3653 = false;
	}
	catch (...) {}
	if (JunkCode3653 == true)
		JunkCode3653 = false;
	if (JunkCode3653 == true)
		JunkCode3653 = false;
	try {
		JunkCode3653 = true;
	}
	catch (...) {}
	if (JunkCode3653 == true)
		JunkCode3653 = true;
	else
		JunkCode3653 = true;
	if (JunkCode3653 == true)
		JunkCode3653 = false;
	if (JunkCode3653 == false)
		JunkCode3653 = false;
	else
		JunkCode3653 = false;
	bool While553 = true;
	while (While553 == true) {
		JunkCode3653 = false;
		While553 = false;
	}
	try {
		JunkCode3653 = false;
	}
	catch (...) {}
	try {
		JunkCode3653 = true;
	}
	catch (...) {}
	if (JunkCode3653 == true)
		JunkCode3653 = false;
	try {
		JunkCode3653 = false;
	}
	catch (...) {}
	if (JunkCode3653 == false)
		JunkCode3653 = true;
	try {
		JunkCode3653 = false;
	}
	catch (...) {}
	bool While5380 = true;
	while (While5380 == true) {
		JunkCode3653 = false;
		While5380 = false;
	}
	bool While1606 = true;
	while (While1606 == true) {
		JunkCode3653 = true;
		While1606 = false;
	}
	try {
		JunkCode3653 = true;
	}
	catch (...) {}
	if (JunkCode3653 == false)
		JunkCode3653 = true;
	if (JunkCode3653 == true)
		JunkCode3653 = false;
	else
		JunkCode3653 = false;
	bool While4886 = true;
	while (While4886 == true) {
		JunkCode3653 = false;
		While4886 = false;
	}
	try {
		JunkCode3653 = false;
	}
	catch (...) {}
	bool While6922 = true;
	while (While6922 == true) {
		JunkCode3653 = true;
		While6922 = false;
	}
	if (JunkCode3653 == false)
		JunkCode3653 = true;
	else
		JunkCode3653 = false;
	bool While2743 = true;
	while (While2743 == true) {
		JunkCode3653 = false;
		While2743 = false;
	}
	try {
		JunkCode3653 = false;
	}
	catch (...) {}
	try {
		JunkCode3653 = false;
	}
	catch (...) {}
	bool While3964 = true;
	while (While3964 == true) {
		JunkCode3653 = true;
		While3964 = false;
	}
	if (JunkCode3653 == true)
		JunkCode3653 = true;
	if (JunkCode3653 == false)
		JunkCode3653 = false;
	else
		JunkCode3653 = false;
	if (JunkCode3653 == true)
		JunkCode3653 = false;
	else
		JunkCode3653 = true;
	if (JunkCode3653 == true)
		JunkCode3653 = false;
	bool While5198 = true;
	while (While5198 == true) {
		JunkCode3653 = false;
		While5198 = false;
	}
	try {
		JunkCode3653 = false;
	}
	catch (...) {}
	if (JunkCode3653 == true)
		JunkCode3653 = false;
	else
		JunkCode3653 = true;
	try {
		JunkCode3653 = true;
	}
	catch (...) {}
	if (JunkCode3653 == false)
		JunkCode3653 = true;
	else
		JunkCode3653 = true;
	if (JunkCode3653 == false)
		JunkCode3653 = false;
	else
		JunkCode3653 = true;
	if (JunkCode3653 == true)
		JunkCode3653 = false;
	if (JunkCode3653 == false)
		JunkCode3653 = true;
	bool While3345 = true;
	while (While3345 == true) {
		JunkCode3653 = false;
		While3345 = false;
	}
	if (JunkCode3653 == false)
		JunkCode3653 = false;
	/*----------END JUNK CODE----------*/


}

void CConfig::Save()
{
	static TCHAR path[MAX_PATH];
	std::string folder, file;

	if (SUCCEEDED(SHGetFolderPath(NULL, CSIDL_APPDATA, NULL, 0, path)))
	{


		folder = std::string(path) + ("\\autismhack\\");
		switch (g_Options.Menu.ConfigFile)
		{
		case 0:
			file = std::string(path) + ("\\autismhack\\legit.ini");
			break;
		case 1:
			file = std::string(path) + ("\\autismhack\\rage.ini");
			break;
		}

	}

	CreateDirectory(folder.c_str(), NULL);

	for (auto value : ints)
		WritePrivateProfileString(value->category.c_str(), value->name.c_str(), std::to_string(*value->value).c_str(), file.c_str());

	for (auto value : floats)
		WritePrivateProfileString(value->category.c_str(), value->name.c_str(), std::to_string(*value->value).c_str(), file.c_str());

	for (auto value : bools)
		WritePrivateProfileString(value->category.c_str(), value->name.c_str(), *value->value ? "true" : "false", file.c_str());
}

void CConfig::Junkertown()
{

	/*----------START JUNK CODE----------*/
	int JunkCode2455 = 3431;
	if (JunkCode2455 == 5915)
		JunkCode2455 = 5045;
	else if (JunkCode2455 == 3431)
		JunkCode2455 = 9384;
	try {
		JunkCode2455 = 3188;
	}
	catch (...) {}
	try {
		JunkCode2455 = 1527;
	}
	catch (...) {}
	if (JunkCode2455 == 1527)
		JunkCode2455 = 2777;
	if (JunkCode2455 == 2777)
		JunkCode2455 = 181;
	if (JunkCode2455 == 181)
		JunkCode2455 = 4766;
	if (JunkCode2455 == 8384)
		JunkCode2455 = 1492;
	else if (JunkCode2455 == 4766)
		JunkCode2455 = 5127;
	try {
		JunkCode2455 = 54;
	}
	catch (...) {}
	if (JunkCode2455 == 4987)
		JunkCode2455 = 4724;
	else if (JunkCode2455 == 54)
		JunkCode2455 = 4360;
	try {
		JunkCode2455 = 3397;
	}
	catch (...) {}
	if (JunkCode2455 == 1484)
		JunkCode2455 = 2915;
	else if (JunkCode2455 == 3397)
		JunkCode2455 = 9302;
	if (JunkCode2455 == 7979)
		JunkCode2455 = 738;
	else if (JunkCode2455 == 9302)
		JunkCode2455 = 4592;
	try {
		JunkCode2455 = 9108;
	}
	catch (...) {}
	try {
		JunkCode2455 = 8038;
	}
	catch (...) {}
	bool While2734 = true;
	while (While2734 == true) {
		JunkCode2455 = 9714;
		While2734 = false;
	}
	if (JunkCode2455 == 9714)
		JunkCode2455 = 2084;
	bool While5364 = true;
	while (While5364 == true) {
		JunkCode2455 = 6595;
		While5364 = false;
	}
	try {
		JunkCode2455 = 6955;
	}
	catch (...) {}
	try {
		JunkCode2455 = 3253;
	}
	catch (...) {}
	if (JunkCode2455 == 3253)
		JunkCode2455 = 7298;
	if (JunkCode2455 == 7298)
		JunkCode2455 = 5946;
	bool While9258 = true;
	while (While9258 == true) {
		JunkCode2455 = 8270;
		While9258 = false;
	}
	bool While2284 = true;
	while (While2284 == true) {
		JunkCode2455 = 5976;
		While2284 = false;
	}
	if (JunkCode2455 == 7406)
		JunkCode2455 = 2200;
	else if (JunkCode2455 == 5976)
		JunkCode2455 = 355;
	if (JunkCode2455 == 5283)
		JunkCode2455 = 8033;
	else if (JunkCode2455 == 355)
		JunkCode2455 = 6550;
	try {
		JunkCode2455 = 9328;
	}
	catch (...) {}
	try {
		JunkCode2455 = 1731;
	}
	catch (...) {}
	try {
		JunkCode2455 = 6567;
	}
	catch (...) {}
	bool While3382 = true;
	while (While3382 == true) {
		JunkCode2455 = 4010;
		While3382 = false;
	}
	if (JunkCode2455 == 4010)
		JunkCode2455 = 676;
	bool While7086 = true;
	while (While7086 == true) {
		JunkCode2455 = 1057;
		While7086 = false;
	}
	bool While6611 = true;
	while (While6611 == true) {
		JunkCode2455 = 3212;
		While6611 = false;
	}
	if (JunkCode2455 == 3212)
		JunkCode2455 = 7844;
	try {
		JunkCode2455 = 7379;
	}
	catch (...) {}
	if (JunkCode2455 == 8789)
		JunkCode2455 = 4096;
	else if (JunkCode2455 == 7379)
		JunkCode2455 = 3284;
	if (JunkCode2455 == 1409)
		JunkCode2455 = 9849;
	else if (JunkCode2455 == 3284)
		JunkCode2455 = 1776;
	try {
		JunkCode2455 = 4389;
	}
	catch (...) {}
	if (JunkCode2455 == 8764)
		JunkCode2455 = 1594;
	else if (JunkCode2455 == 4389)
		JunkCode2455 = 5707;
	if (JunkCode2455 == 1317)
		JunkCode2455 = 9658;
	else if (JunkCode2455 == 5707)
		JunkCode2455 = 2828;
	try {
		JunkCode2455 = 8916;
	}
	catch (...) {}
	if (JunkCode2455 == 7414)
		JunkCode2455 = 9946;
	else if (JunkCode2455 == 8916)
		JunkCode2455 = 4214;
	if (JunkCode2455 == 9061)
		JunkCode2455 = 3799;
	else if (JunkCode2455 == 4214)
		JunkCode2455 = 7177;
	if (JunkCode2455 == 6259)
		JunkCode2455 = 2439;
	else if (JunkCode2455 == 7177)
		JunkCode2455 = 2012;
	if (JunkCode2455 == 4237)
		JunkCode2455 = 5955;
	else if (JunkCode2455 == 2012)
		JunkCode2455 = 9978;
	bool While4709 = true;
	while (While4709 == true) {
		JunkCode2455 = 6413;
		While4709 = false;
	}
	if (JunkCode2455 == 6413)
		JunkCode2455 = 4062;
	if (JunkCode2455 == 4062)
		JunkCode2455 = 2758;
	try {
		JunkCode2455 = 9103;
	}
	catch (...) {}
	if (JunkCode2455 == 9103)
		JunkCode2455 = 3499;
	try {
		JunkCode2455 = 7566;
	}
	catch (...) {}
	if (JunkCode2455 == 7566)
		JunkCode2455 = 2044;
	bool While3598 = true;
	while (While3598 == true) {
		JunkCode2455 = 8744;
		While3598 = false;
	}
	if (JunkCode2455 == 8744)
		JunkCode2455 = 1271;
	try {
		JunkCode2455 = 9801;
	}
	catch (...) {}
	bool While1383 = true;
	while (While1383 == true) {
		JunkCode2455 = 9928;
		While1383 = false;
	}
	bool While7362 = true;
	while (While7362 == true) {
		JunkCode2455 = 1219;
		While7362 = false;
	}
	if (JunkCode2455 == 1583)
		JunkCode2455 = 5623;
	else if (JunkCode2455 == 1219)
		JunkCode2455 = 1874;
	if (JunkCode2455 == 8534)
		JunkCode2455 = 2898;
	else if (JunkCode2455 == 1874)
		JunkCode2455 = 7088;
	bool While6230 = true;
	while (While6230 == true) {
		JunkCode2455 = 7575;
		While6230 = false;
	}
	try {
		JunkCode2455 = 8252;
	}
	catch (...) {}
	if (JunkCode2455 == 6481)
		JunkCode2455 = 9247;
	else if (JunkCode2455 == 8252)
		JunkCode2455 = 3435;
	if (JunkCode2455 == 3435)
		JunkCode2455 = 8366;
	if (JunkCode2455 == 8863)
		JunkCode2455 = 8035;
	else if (JunkCode2455 == 8366)
		JunkCode2455 = 7485;
	bool While5406 = true;
	while (While5406 == true) {
		JunkCode2455 = 3219;
		While5406 = false;
	}
	if (JunkCode2455 == 4968)
		JunkCode2455 = 6884;
	else if (JunkCode2455 == 3219)
		JunkCode2455 = 3705;
	/*----------END JUNK CODE----------*/


}

void CConfig::Load()
{
	static TCHAR path[MAX_PATH];
	std::string folder, file;

	if (SUCCEEDED(SHGetFolderPath(NULL, CSIDL_APPDATA, NULL, 0, path)))
	{
		folder = std::string(path) + ("\\autismhack\\");
		switch (g_Options.Menu.ConfigFile)
		{
		case 0:
			file = std::string(path) + ("\\autismhack\\legit.ini");
			break;
		case 1:
			file = std::string(path) + ("\\autismhack\\rage.ini");
			break;
		}
	}

	CreateDirectory(folder.c_str(), NULL);

	char value_l[32] = { '\0' };

	for (auto value : ints)
	{
		GetPrivateProfileString(value->category.c_str(), value->name.c_str(), "", value_l, 32, file.c_str());
		*value->value = atoi(value_l);
	}

	for (auto value : floats)
	{
		GetPrivateProfileString(value->category.c_str(), value->name.c_str(), "", value_l, 32, file.c_str());
		*value->value = (float)atof(value_l);
	}

	for (auto value : bools)
	{
		GetPrivateProfileString(value->category.c_str(), value->name.c_str(), "", value_l, 32, file.c_str());
		*value->value = !strcmp(value_l, "true");
	}
}

void CConfig::Selassie()
{

	/*----------START JUNK CODE----------*/
	bool JunkCode1405 = true;
	try {
		JunkCode1405 = true;
	}
	catch (...) {}
	if (JunkCode1405 == true)
		JunkCode1405 = false;
	else
		JunkCode1405 = true;
	if (JunkCode1405 == true)
		JunkCode1405 = true;
	if (JunkCode1405 == false)
		JunkCode1405 = false;
	bool While8032 = true;
	while (While8032 == true) {
		JunkCode1405 = false;
		While8032 = false;
	}
	if (JunkCode1405 == true)
		JunkCode1405 = false;
	else
		JunkCode1405 = false;
	try {
		JunkCode1405 = false;
	}
	catch (...) {}
	if (JunkCode1405 == false)
		JunkCode1405 = true;
	if (JunkCode1405 == true)
		JunkCode1405 = true;
	else
		JunkCode1405 = true;
	if (JunkCode1405 == true)
		JunkCode1405 = true;
	try {
		JunkCode1405 = false;
	}
	catch (...) {}
	if (JunkCode1405 == false)
		JunkCode1405 = true;
	else
		JunkCode1405 = false;
	bool While2677 = true;
	while (While2677 == true) {
		JunkCode1405 = false;
		While2677 = false;
	}
	try {
		JunkCode1405 = false;
	}
	catch (...) {}
	if (JunkCode1405 == true)
		JunkCode1405 = false;
	bool While2012 = true;
	while (While2012 == true) {
		JunkCode1405 = true;
		While2012 = false;
	}
	bool While7239 = true;
	while (While7239 == true) {
		JunkCode1405 = true;
		While7239 = false;
	}
	if (JunkCode1405 == false)
		JunkCode1405 = true;
	else
		JunkCode1405 = true;
	if (JunkCode1405 == false)
		JunkCode1405 = false;
	else
		JunkCode1405 = false;
	if (JunkCode1405 == false)
		JunkCode1405 = true;
	if (JunkCode1405 == false)
		JunkCode1405 = true;
	else
		JunkCode1405 = true;
	try {
		JunkCode1405 = true;
	}
	catch (...) {}
	try {
		JunkCode1405 = true;
	}
	catch (...) {}
	if (JunkCode1405 == false)
		JunkCode1405 = false;
	if (JunkCode1405 == false)
		JunkCode1405 = true;
	else
		JunkCode1405 = true;
	bool While5408 = true;
	while (While5408 == true) {
		JunkCode1405 = true;
		While5408 = false;
	}
	bool While8110 = true;
	while (While8110 == true) {
		JunkCode1405 = true;
		While8110 = false;
	}
	if (JunkCode1405 == true)
		JunkCode1405 = true;
	if (JunkCode1405 == true)
		JunkCode1405 = true;
	else
		JunkCode1405 = false;
	if (JunkCode1405 == true)
		JunkCode1405 = false;
	else
		JunkCode1405 = true;
	try {
		JunkCode1405 = true;
	}
	catch (...) {}
	if (JunkCode1405 == true)
		JunkCode1405 = true;
	if (JunkCode1405 == true)
		JunkCode1405 = false;
	else
		JunkCode1405 = true;
	try {
		JunkCode1405 = true;
	}
	catch (...) {}
	try {
		JunkCode1405 = false;
	}
	catch (...) {}
	if (JunkCode1405 == false)
		JunkCode1405 = false;
	bool While1862 = true;
	while (While1862 == true) {
		JunkCode1405 = true;
		While1862 = false;
	}
	if (JunkCode1405 == false)
		JunkCode1405 = false;
	else
		JunkCode1405 = false;
	if (JunkCode1405 == true)
		JunkCode1405 = true;
	else
		JunkCode1405 = true;
	bool While7121 = true;
	while (While7121 == true) {
		JunkCode1405 = true;
		While7121 = false;
	}
	if (JunkCode1405 == false)
		JunkCode1405 = true;
	else
		JunkCode1405 = false;
	if (JunkCode1405 == false)
		JunkCode1405 = false;
	if (JunkCode1405 == true)
		JunkCode1405 = true;
	if (JunkCode1405 == true)
		JunkCode1405 = true;
	if (JunkCode1405 == false)
		JunkCode1405 = false;
	if (JunkCode1405 == true)
		JunkCode1405 = false;
	if (JunkCode1405 == false)
		JunkCode1405 = false;
	if (JunkCode1405 == true)
		JunkCode1405 = true;
	else
		JunkCode1405 = true;
	try {
		JunkCode1405 = true;
	}
	catch (...) {}
	try {
		JunkCode1405 = false;
	}
	catch (...) {}
	if (JunkCode1405 == true)
		JunkCode1405 = false;
	bool While5328 = true;
	while (While5328 == true) {
		JunkCode1405 = true;
		While5328 = false;
	}
	if (JunkCode1405 == true)
		JunkCode1405 = false;
	try {
		JunkCode1405 = false;
	}
	catch (...) {}
	try {
		JunkCode1405 = true;
	}
	catch (...) {}
	if (JunkCode1405 == false)
		JunkCode1405 = true;
	else
		JunkCode1405 = true;
	if (JunkCode1405 == true)
		JunkCode1405 = true;
	if (JunkCode1405 == false)
		JunkCode1405 = true;
	else
		JunkCode1405 = false;
	if (JunkCode1405 == false)
		JunkCode1405 = true;
	try {
		JunkCode1405 = true;
	}
	catch (...) {}
	bool While9937 = true;
	while (While9937 == true) {
		JunkCode1405 = true;
		While9937 = false;
	}
	try {
		JunkCode1405 = true;
	}
	catch (...) {}
	if (JunkCode1405 == true)
		JunkCode1405 = false;
	else
		JunkCode1405 = true;
	try {
		JunkCode1405 = true;
	}
	catch (...) {}
	if (JunkCode1405 == true)
		JunkCode1405 = false;
	else
		JunkCode1405 = false;
	/*----------END JUNK CODE----------*/


}

CConfig* Config = new CConfig();
Variables g_Options;