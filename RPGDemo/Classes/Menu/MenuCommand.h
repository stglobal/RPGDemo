#pragma once
#include "STMVC/STMVC.h"
#include <string>

namespace ns_menu_cmd
{
	enum
	{
		CMD_HAHA,

	};

	struct cmd_haha:public CSTCommand
	{
		REG_CMD(CMD_HAHA);
		int m;
		int n;
		std::string haha;
	};
}

using namespace ns_menu_cmd;

