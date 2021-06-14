#include "include.h"

DWORD LocalPlayer::LocalPlayerAddress = 0;

void LocalPlayer::initLocal() {

	LocalPlayer::localPlayerAddress = readMem<DWORD>(gameModule + hazedumper::signatures::dwLocalPlayer);
}

DWORD LocalPlayer::getLocal() {
	return LocalPlayer::LocalPlayerAddress;

}

int LocalPlayer::getFlags() {

	return readMem<int>(LocalPlayer::getLocal() + hazedumper::netvars::m_fFlags);
}

D3DXVECTOR3 LocalPlayer::getVelocity()
{
	return readMem<D3DXVECTOR3>(LocalPlayer::getLocal() + hazedumper::netvars::m_vecVelocity);
}

int LocalPlayer::getFlashDur() {
	return readMem<int>(LocalPlayer::getLocal() + hazedumper::netvars::m_flFlashDuration);
}

int LocalPlayer::getTeam() {

	return readMem<int>(LocalPlayer::getLocal() + hazedumper::netvars::m_iTeamNum);
}

void LocalPlayer::setLocalViewAngles(D3DXVECTOR3 angles)
{
	writeMem<D3DXVECTOR3>(clientState + hazedumper::signatures::dwClientState_ViewAngles, angles);
}

D3DXVECTOR3 LocalPlayer::getLocalPunchAngles()
{
	return readMem<D3DXVECTOR3>(localPlayer::getLocal() + hazedumper::)
}