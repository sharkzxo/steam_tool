#include <Windows.h>
#include <iostream>
#include <filesystem>
#include <fstream>
#include <string>
#include <thread>

// encryption
#include "xorstr.h"

namespace tool {

	std::string steam_path() {
		DWORD dwType = REG_SZ;
		HKEY hKey = 0;
		char value[64];
		DWORD valueLength = 64;
		const char* subkey = xorstr_("SOFTWARE\\Valve\\Steam");
		RegOpenKey(HKEY_CURRENT_USER, subkey, &hKey);
		RegQueryValueEx(hKey, xorstr_("SteamPath"), NULL, &dwType, (LPBYTE)&value, &valueLength);

		sprintf(value, std::string(value).c_str());

		return value;
	}

	std::string steam(std::string name) {

		std::string path = steam_path();
		path += name;

		return path;
	}

};