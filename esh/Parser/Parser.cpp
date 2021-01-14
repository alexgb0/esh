#include "Parser.h"

#include <sstream>
#include <algorithm>
#include <iterator>
#include <string>

void CParser::Parse(CContext *ctx, CVContext *ctxp)
{
    std::vector<std::string> vSingleCmd;
    std::vector<std::string> vMultiCmd;
  

    std::vector<std::string> vLine;

    // Add more tokens
    if (ctx->sLine.find("&") != std::string::npos)
    {
        // [0] == FirstCMD
        // [1] == ScondCMD
        vMultiCmd = split(ctx->sLine, '&');
        
        if (vMultiCmd.size() == 1 || vMultiCmd.size() == 0)
        {
            Utils::Panic("Bad syntax");
            return;
        }
        // We parase the first cmd as a normal

        std::vector<std::string> vFirst = split(vMultiCmd[0], ' ');
        std::vector<std::string> vSecond = split(vMultiCmd[1], ' ');
  
        // First cmd

        // Error fix: for only one command input: `$ test`
        if (vFirst.size() < 1)
            ctx->sCmd = ctx->sLine;
        else
        {
            if (vFirst[0] == " ")
                ctx->sCmd = vFirst[1];
            else
                ctx->sCmd = vFirst[0];

            if (vFirst.size() > 1)
                map(vFirst, ctxp->mVars, ctx->mAttrib, ctx->vCmd);
        }

        // Second cmd

        if (vSecond.size() < 1)
            ctx->sCmd = ctx->sLine; // BUGG ERROR
        else
        {
            if (vSecond[0] == " " || "")
                ctx->sCmd2 = vSecond[1];
            else
                ctx->sCmd2 = vSecond[0];

            if (vSecond.size() > 1)
            {
                map(vSecond, ctxp->mVars, ctx->mAttrib2, ctx->vCmd2);
                ctx->vCmd2.erase(ctx->vCmd2.begin());
            }
        }
    }
    else
    {
        vSingleCmd = split(ctx->sLine, ' ');
        // Error fix: for only one command input: `$ test`
        if (vSingleCmd.size() < 1)
            ctx->sCmd = ctx->sLine;
        else
        {
            if (vSingleCmd[0] == " ")
                ctx->sCmd = vSingleCmd[1];
            else
                ctx->sCmd = vSingleCmd[0];

            if (vSingleCmd.size() > 1)
                map(vSingleCmd, ctxp->mVars, ctx->mAttrib, ctx->vCmd);
        }

    }
}

std::vector<std::string> CParser::split(const std::string& s, char delimiter)
{
   std::vector<std::string> tokens;
   std::string token;
   std::istringstream tokenStream(s);
   while (std::getline(tokenStream, token, delimiter))
   {
      tokens.push_back(token);
   }
   return tokens;
}

void CParser::map(std::vector<std::string> vec, std::map<std::string, std::any> &mVars, std::map<std::string, std::any> &mArgs, std::vector<std::string> &vCmd)
{
    // We start at 1 because in the first one is the cmd
    for (size_t i = 1; i < vec.size(); i++)
    {

        // For variables
        if (vec[i].find("$") != std::string::npos)
        {
            // If we are setting / changing the variable we don't want to be replaced.
            if (vec[i - 1] != "set")
            {
                // Objective: Replace the variables with their actual value
                auto it = mVars.find(vec[i]);

                if (it != mVars.end())
                {
                    if (std::any_cast<std::string>(it->first) == vec[i])
                        vec[i] = std::any_cast<std::string>(mVars[vec[i]]); // Found the var
                }
            }
        }
        
        //TODO: Check for arguments like -t=123
        if (vec[i].find("-") != std::string::npos)
        {
            // Fix
            if (i + 1 <= vec.size())
            {
                if (vec[i + 1].find("-") == std::string::npos)
                {
                    mArgs.insert(std::pair<std::string, std::any>(vec[i], vec[i + 1]));
                    // we skip one index
                    i++;
                }
                else
                    mArgs.insert(std::pair<std::string, std::any>(vec[i], NULL));
            }
            else
                vCmd.push_back(vec[i]);
        }
        else
            vCmd.push_back(vec[i]);

    }
}