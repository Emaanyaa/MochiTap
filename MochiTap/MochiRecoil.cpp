#include "include.h"

bool norecoil::norecoil_status = false;

D3DXVECTOR3 NewViewAngles;
D3DXVECTOR3 OldAimPunch;

void norecoil::rcs()
{

	if (norecoil::norecoil_status)
	{

		if (LocalPlayer::getShotsFired() > 1) {
			NewViewAngles.x = ((LocalPlayer::getLocalViewAngles().x + OldAimPunch.x) - (LocalPlayer::getLocalPunchAngles().x * 2.f));
			NewViewAngles.y = ((LocalPlayer::getLocalViewAngles().y + OldAimPunch.y) - (LocalPlayer::getLocalPunchAngles().y * 2.f));

			while (NewViewAngles.y > 180)
				NewViewAngles.y -= 360;

			while (NewViewAngles.y < -180)
				NewViewAngles.y += 360;

			if (NewViewAngles.x > 89.0f)
				NewViewAngles.x = 89.0f;

			if (NewViewAngles.x < -89.0f)
				NewViewAngles.x = -89.0f;

			OldAimPunch.x = LocalPlayer::getLocalPunchAngles().x * 2.f;
			OldAimPunch.y = LocalPlayer::getLocalPunchAngles().y * 2.f;

			LocalPlayer::setLocalViewAngles(NewViewAngles);
		}
		else
		{
			OldAimPunch.x = OldAimPunch.y = 0;
		}
	}
}