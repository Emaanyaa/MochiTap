#pragma once

#include <Windows.h>
#include <d3d11.h>

namespace LocalPlayer
{

	extern DWORD			;
	extern DWORD			getLocal();
	extern int					getFlags();
	extern D3DXVECTOR3		getVelocity();
	extern void					initLocal();
	extern int					getFlashDur();
	extern int					getTeam();
	extern D3DXVECTOR3		getLocalViewAngles();
	extern void					setLocalViewAngles(D3DXVECTOR3 angles);
	extern D3DXVECTOR3		getLocalPunchaAngles();
	extern D3DXMATRIX		getLocalViewMatrix();
	extern int					getShotFired();
	extern int					getLocalCrosshair();
	extern D3DXVECTOR3		getLocalPos();
	extern D3DXVECOTR3		getLocalEyePos();
	extern int					getLocalCrossID();
	extern bool					isScoped();
}