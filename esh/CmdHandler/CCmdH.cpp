#include "CCmdH.h"


void CCmdH::CmdHandler(CContext* ctx, CVContext* ctxp)
{
	try
	{
		// We try to call the function and pass the pointer of ctx as argument.
		mCmds[ctx->sCmd](ctx, ctxp);

		// If the first command was true 
		if (ctx->bReturn && !ctx->sCmd2.empty())
			mCmds[ctx->sCmd2](ctx, ctxp);
	}
	catch (const std::exception&)
	{
		// If the function name doesn't exist we output the problem.
		
		// We enable the verbose so we can print in the console
		ctx->bVerbose = true;
		
		// And we print the problem
		ctx->sOutput = fmt::format(fmt::fg(fmt::color::red), "Command '{}' not found.\n", ctx->sCmd);
	}
}
