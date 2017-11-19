#pragma once
#include "SDK.h"
#include "singleton.hpp"
enum ACT
{
    ACT_NONE,
    ACT_THROW,
    ACT_LOB,
    ACT_DROP,
};

class grenade_prediction
    : public singleton<grenade_prediction>
{
private:
    std::vector<Vector> path;

    int type = 0;
    int act = 0;

    void Setup(Vector& vecSrc, Vector& vecThrow, Vector viewangles);
	void loladopkg();
    void Simulate(CViewSetup* setup);

    int Step(Vector& vecSrc, Vector& vecThrow, int tick, float interval);
	void xdawjfpojkg();
    bool CheckDetonate(const Vector& vecThrow, const trace_t& tr, int tick, float interval);

    void TraceHull(Vector& src, Vector& end, trace_t& tr);
    void AddGravityMove(Vector& move, Vector& vel, float frametime, bool onground);
    void PushEntity(Vector& src, const Vector& move, trace_t& tr);
    void ResolveFlyCollisionCustom(trace_t& tr, Vector& vecVelocity, float interval);
    int PhysicsClipVelocity(const Vector& in, const Vector& normal, Vector& out, float overbounce);
public:
    void Tick(int buttons);
    void View(CViewSetup* setup);
	void globalelite();
    void Paint();
};