#pragma once

#include "../common.h"
#include <functional>
#include "../Cmds/Cmd.h"

class CCmdH
{
public:
	void CmdHandler(CContext* ctx, CVContext* ctxp);


private:
	std::map<std::string, std::function<void(CContext*, CVContext*)>> mCmds =
	{
		{"test", cmd_Test},
		{"echo", cmd_Echo},
		{"exit", cmd_Exit},
		{"set", cmd_Set}
	};

};

