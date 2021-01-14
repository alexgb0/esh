#include "jsh/common.h"

#include <iostream>

#include "jsh/Context/Ctx.h"

int main(void)
{


	CVContext* ctxp = new CVContext();

	while (true)
	{
		CContext* ctx = new CContext();
		CParser Parser;
		CCmdH Cmdh;

		fmt::print(std::any_cast<std::string>(ctxp->mVars["$PS1"]));
		std::getline(std::cin, ctx->sLine);

		Parser.Parse(ctx, ctxp);
		
		Cmdh.CmdHandler(ctx, ctxp);

		if (ctx->bVerbose)
		{
			fmt::print("{}", ctx->sOutput);
			ctx->bVerbose = !ctx->bVerbose;
		}
	}

	return 0;
}
