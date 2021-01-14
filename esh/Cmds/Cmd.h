#pragma once

#include "../Utils/Singleton.h"
#include "../Context/Ctx.h"
#include "../Context/PCtx.h"


#include <fmt/core.h>
#include <any>
#include <string>

// This is a class for store dev functions. Just for testing.


// TODO

inline void cmd_Set(CContext* ctx, CVContext* ctxp)
{
	auto it = ctxp->mVars.find(ctx->vCmd[0]);
	if (it != ctxp->mVars.end())
		ctxp->mVars[ctx->vCmd[0]] = ctx->vCmd[1];
	else
		ctxp->mVars.insert({ ctx->vCmd[0], ctx->vCmd[1] });
}

inline void cmd_Test(CContext *ctx, CVContext* ctxp)
{
	if (ctx->vCmd.size() == 0)
	{
		ctx->bVerbose = true;
		ctx->sOutput = fmt::format(fmt::fg(fmt::color::red), "Please provide a parameter\n");
		return;
	}
	// Equal
	if (ctx->mAttrib.find("-eq") != ctx->mAttrib.end())
	{
		if (std::stoi(std::any_cast<std::string>(ctx->mAttrib["-eq"])) == std::stoi(ctx->vCmd[0]))
			ctx->bReturn = true;
		else
			ctx->bReturn = false;
	}
}

inline void cmd_Exit(CContext* ctx, CVContext* ctxp)
{
	// TODO: Custom exit codes
	exit(0);
}

inline void cmd_Echo(CContext* ctx, CVContext* ctxp)
{
	// TODO: Pattern matching C++23


	// We enable the outputstd::any_cast<int>(ctx->mAttrib["-eq"])
	ctx->bVerbose = true;
	
	// We check if the attribute `-c` is supplied.
	if (ctx->mAttrib.find("-c") != ctx->mAttrib.end())
	{
		if (std::any_cast<std::string>(ctx->mAttrib["-c"]) == "red")
			ctx->sOutput = fmt::format(fmt::fg(fmt::color::red), "{}\n", fmt::join(ctx->vCmd, " "));
		else if (std::any_cast<std::string>(ctx->mAttrib["-c"]) == "green")
			ctx->sOutput = fmt::format(fmt::fg(fmt::color::green), "{}\n", fmt::join(ctx->vCmd, " "));
		else if (std::any_cast<std::string>(ctx->mAttrib["-c"]) == "blue")
			ctx->sOutput = fmt::format(fmt::fg(fmt::color::blue), "{}\n", fmt::join(ctx->vCmd, " "));
		else if (std::any_cast<std::string>(ctx->mAttrib["-c"]) == "yellow")
			ctx->sOutput = fmt::format(fmt::fg(fmt::color::yellow), "{}\n", fmt::join(ctx->vCmd, " "));
		else if (std::any_cast<std::string>(ctx->mAttrib["-c"]) == "pink")
			ctx->sOutput = fmt::format(fmt::fg(fmt::color::pink), "{}\n", fmt::join(ctx->vCmd, " "));
		else if (std::any_cast<std::string>(ctx->mAttrib["-c"]) == "purple")
			ctx->sOutput = fmt::format(fmt::fg(fmt::color::purple), "{}\n", fmt::join(ctx->vCmd, " "));
		else
			ctx->sOutput = fmt::format(fmt::fg(fmt::color::red), "{}\n", "Color not found");
		ctx->bReturn = true;
	}
	else
		// We grab the all the args as the output of our program
		if (ctx->bReturn)
		{
			fmt::print("{}\n", fmt::join(ctx->vCmd2 , " ")); // vCmd2[0] == cmd
		}
		else
			fmt::print("{}\n", fmt::join(ctx->vCmd, " "));
	ctx->bReturn = true;
}
