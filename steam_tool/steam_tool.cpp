#include "pch.h"

namespace settings { std::string application_name = xorstr_("sharkzxo´s (steam_tool)"); std::string mutex_name = xorstr_("steam_tool"); std::string dll_name = xorstr_("crashhandler.dll"); };

int main()
{
    SetConsoleTitle(settings::application_name.data());

    HANDLE mutex_handle = CreateMutexA(NULL, TRUE, settings::mutex_name.data());
    if (ERROR_ALREADY_EXISTS == GetLastError()) { std::cout << xorstr_("[<] another instance running") << std::endl; std::exit(0); }

    std::cout << xorstr_("[>] app initialized") << std::endl; { std::this_thread::sleep_for(std::chrono::milliseconds(500)); }

    if (std::filesystem::exists(tool::steam(xorstr_("\\cheat.dll")))) { std::filesystem::remove(tool::steam(xorstr_("\\cheat.dll"))); std::this_thread::sleep_for(std::chrono::milliseconds(500)); }

    if (std::filesystem::exists(settings::dll_name)) { std::cout << xorstr_("[>] our dll found [crashhandler.dll]") << std::endl; }
    else { std::cout << xorstr_("[<] our dll not found [crashhandler.dll]") << std::endl; std::this_thread::sleep_for(std::chrono::milliseconds(500)); }

    std::filesystem::rename(tool::steam(xorstr_("\\crashhandler.dll")), tool::steam(xorstr_("\\crashhandler_copy.dll")));
    {
        std::cout << xorstr_("[>] renamed original [crashhandler.dll] in target file to [crashhandler_copy.dll]") << std::endl;

        std::filesystem::copy(settings::dll_name, tool::steam(xorstr_("\\crashhandler.dll")));

        std::cout << xorstr_("[>] our dll was imported into target file [crashhandler.dll]") << std::endl;
    }
    std::cout << xorstr_("[>] please open the game") << std::endl;

    std::cout << xorstr_("[>] if you are in the game and the dll is active") << std::endl;
    {
        std::cout << xorstr_("[>] please press enter to delete recents changes") << std::endl;
        std::cout << xorstr_("[>] to avoid reinstalling steam files on next startup") << std::endl;
    }

    getchar();

    std::filesystem::rename(tool::steam(xorstr_("\\crashhandler.dll")), tool::steam(xorstr_("\\cheat.dll")));
    {
        std::cout << xorstr_("[>] our dll in target file was renamed to [cheat.dll]") << std::endl;

        std::filesystem::rename(tool::steam(xorstr_("\\crashhandler_copy.dll")), tool::steam(xorstr_("\\crashhandler.dll")));

        std::cout << xorstr_("[>] the original copy was renamed back to [crashhandler.dll]") << std::endl;
    }
    std::cout << xorstr_("[>] changes we´re removed") << std::endl;

    std::cout << xorstr_("[>] thanks for using this application") << std::endl;
    {
        std::this_thread::sleep_for(std::chrono::seconds(2));
        std::exit(0);
    }
}