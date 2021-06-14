#include "include.h"

using namespace std;

void userinterface::change_color(int desiredColor) {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), desiredColor);
}

void userinterface::ui()
{
	system("cls");
	userinterface::change_color(4);
	cout << "MOCHITAP External - by https://github.com/Emaanyaa (Emiinyaa@protonmail.ch)" << endl;
	userinterface::change_color(8);
	cout << "[END]->Panic kill key" << endl;

	if (bhop::bhop_status)
	{
		cout << "[F1]->Bhop = ";
		userinterface::change_color(2);
		cout << "Enabled" << endl;

	}
	else {
		cout << "[F1]->Bhop = ";
		userinterface::change_color(4);
		cout << "Disabled" << endl;
	}
	userinterface::change_color(8);

	if (triggerbot::triggerbot_status)
	{
		cout << "[F2]->Triggerbot = ";
		userinterface::change_color(2);
		cout << "Enabled" << endl;

	}
	else {
		cout << "[F2]->Triggerbot = ";
		userinterface::change_color(4);
		cout << "Disabled" << endl;

	}
	userinterface::change_color(8);

	if (glowesp::glow_status)
	{
		cout << "[F3]->GlowESP = ";
		userinterface::change_color(2);
		cout << "Enabled" << endl;
	}
	else {
		cout << "[F3]->GlowESP = ";
		userinterface::change_color(4);
		cout << "Disabled" << endl;

	}
	userinterface::change_color(8);

	if (radar::radar_status)
	{
		cout << "[F4]->Radar = ";
		userinterface::change_color(2);
		cout << "Enabled" << endl;
	}
	else {
		cout << "[F4]->Radar = ";
		userinterface::change_color(4);
		cout << "Disabled" << endl;
	}
	userinterface::change_color(8);

	if (norecoil::norecoil_status)
	{
		cout << "[F5]->NoRecoil = ";
		userinterface::change_color(2);
		cout << "Enabled" << endl;
	}
	else {
		cout << "[F5}->NoRecoil = ";
		userinterface::change_color(4);
		cout << "Diabled" << endl;
	}
	userinterface::change_color(8);


}

void userinterface::get_key()
{
	if (GetAsyncKeyState(VK_F1) & 1)
	{
		
		bhop::bhop_status = !bhop::bhop_status;
		userinterface::ui();

	}
	if (GetAsyncKeyState(VK_F2) & 1)
	{

		triggerbot::triggerbot_status = !triggerbot::triggerbot_status;
		userinterface::ui();
	}
	if (GetAsyncKeyState(VK_F3) & 1)
	{

		glowesp::glow_status = !glowesp::glow_status;
		userinterface::ui();
	}
	if (GetAsyncKeyState(VK_F4) & 1)
	{

		radar::radar_status = !radar::radar_status;
		userinterface::ui();
	}
	if (GetAsyncKeyState(VK_F5) & 1)
	{
		
		norecoil::norecoil_status = !norecoil::norecoil_status;
		userinterface::ui();
	}
}