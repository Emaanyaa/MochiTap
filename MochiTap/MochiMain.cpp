
#include "include.h"

using namespace std;

string gen_random(const int len, DWORD procID) {

	string tmp_s;
	static const char alphanum[] =
		"0123456789"
		"ABCDEFGHIJKLMNOPQRSTUVWXYZ"
		"abcdefghijklmnopqrstuvwxyz";

	srand((unsigned)time(NULL) * procID);

	tmp_s.reserve(len);

	for (int i = 0; i < len; ++i)
		tmp_s += alphanum[rand() % (sizeof(alphanum) - 1)];

	return tmp_s;

}

int main()
{

	SetConsoleTitle("MOCHITAP");
	HWND hwnd = GetConsoleWindow();
	if (hwnd != NULL)
	{
		MoveWindow(hwnd, 340, 150, 750, 500, TRUE);
		SetWindowLong(hwnd, GWL_STYLE, GetWindowLong(hwnd, GWL_STYLE) & ~WS_MAXIMIZEBOX & ~WS_SIZEBOX);
		//size and noresize
	}

	userinterface::change_color(2);
	cout << "MochiTap - github.com/Emaanyaa (Emiinyaa@protonmail.ch)" << endl;
	userinterface::change_color(8);

	DWORD pID;
	cout << "Input <csgo.exe> processID:" << endl;
	cin >> pID;

	SetConsoleTitle(gen_random(8, pID).c_str());

	getProcess(pID);
	gameModule = getModule(XOR(LPSTR("client.dll")));
	engineModule = getModule(XOR(LPSTR("engine.dll")));

	if (!engineModule || !gameModule)
	{

		cout << "Could not find game modules ;c ." << endl;
		Sleep(1000);
		return -1;
	}
	Sleep(500);
	system("cls");

	userinterface::change_color(2);
	cout << std::dec << "Mochi Initializing..." << endl;
	Sleep(500);

	userinterface::ui();

	LocalPlayer::initLocal();

	//main loop
	while (true)
	{

		if (GetAsyncKeyState(VK_END) && 1)
			break;

		userinterface::get_key();
		//threds, UI

		bhop::bhop();
		triggerbot::trigger();
		norecoil::rcs();

		//binding
		for (int i = 0; i < 32; i++)
		{
			glowesp::glow(i);
			radar::show(i);
		}
	}



}