#include "include.h"

bool triggerbot::triggerbot_status = false;
int weaponID;
float inaccuracy;

int distance(D3DXVECTOR3 a, D3DXVECTOR3 b) {
	double distance;

	distance = sqrt(((int)a.x - (int)b.x) * ((int)a.x - (int)b.x) +
		((int)a.y - (int)b.y) * ((int)a.y - (int)b.y) +
		((int)a.z - (int)b.z) * ((int)a.z - (int)b.z));

	return (int)abs(round(distance));
}

void getWeapon() //obtains weapon id from entity.h
{

	int weapon = readMem<int>(LocalPlayer::getLocal() + hazedumper::netvars::m_hActiveWeapon);
	//does not work inbetween weapon changes
	int weaponEntity = readMem<int>(gameModule + hazedumper::signatures::dwEntityList + ((weapon & 0xFFF) - 1) * 0x10);

	if (weaponEntity != NULL) {
		weaponID = readMem<int>(weaponEntity + hazedumper::netvars::m_iItemDefinitionIndex);
		inaccuracy = readMem<float>(weaponEntity + hazedumper::netvars::m_fAccuracyPenalty);
	}
}

void triggerbot::trigger()
{

	if (triggerbot::triggerbot_status)
	{

		bool isScoped = readMem<bool>(LocalPlayer::getLocal() + hazedumper::netvars::m_bIsScoped);
		auto xhair = LocalPlayer::getLocalCrossID();
		if (xhair > -1) {
			auto inCross = entity::getEntityBase(xhair - 1); //entity
			getWeapon();
			if (entity::getEntTeam(inCross) != LocalPlayer::getTeam()) {
				if (weaponID == 40 || weaponID == 9 || weaponID == 11 || weaponID == 38)
				{
					
					float vel = readMem<float>(LocalPlayer::localPlayerAddress + hazedumper::netvars::m_vecVelocity);
					if (isScoped)
					{
						if ((vel > 0.1 || vel < -0.000984192) && LocalPlayer::getFlags() != FL_ON_GROUND_CROUCHED)
							return;

						Sleep(10);
						mouse_event(MOUSEEVENTF_LEFTDOWN, 0, 0, 0, 0);
						Sleep(25);
						mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);


					}
				}
				else if (weaponID == 31) // zeus meme bot
				{

					if (distance(LocalPlayer::getLocalPos(), entity::getEntPos(inCross)) <= 150)
					{

						mouse_event(MOUSEEVENTF_LEFTDOWN, NULL, NULL, NULL, NULL);
						Sleep(5);
						mouse_event(MOUSEEVENTF_LEFTUP, NULL, NULL, NULL, NULL);
					}
				}
				else if (weaponID == 42) //knife meme bot
				{
					if (distance(LocalPlayer::getLocalPos(), entity::getEntPos(inCross)) <= 82)
					{
						if (entity::getEntHp(inCross) <= 50 && distance(LocalPlayer::getLocalPos(), entity::getEntPos(inCross)) <= 70)
						{
							
							mouse_event(MOUSEEVENTF_RIGHTDOWN, NULL, NULL, NULL, NULL);
							Sleep(5);
							mouse_event(MOUSEEVENTF_RIGHTUP, NULL, NULL, NULL, NULL);

						}
						else{
							mouse_event(MOUSEEVENTF_LEFTDOWN, NULL, NULL, NULL, NULL);
							Sleep(5);
							mouse_event(MOUSEEVENTF_LEFTUP, NULL, NULL, NULL, NULL);
						}
					}
				}
			}
			else if (weaponID == 64)
			{
				Sleep(0);
				mouse_event(MOUSEEVENTF_LEFTDOWN, 0, 0, 0, 0);
				Sleep(1000);
				mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);
				

			}
			else if (inaccuracy < 0.025) {
				Sleep(25);
				mouse_event(MOUSEEVENTF_LEFTDOWN, 0, 0, 0, 0);
				Sleep(25);
				mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);
				
					
			}
				
		}
	}
}