# esh
Embedded shell for your needs

Here is an example of a simple function:

```cpp
inline void cmd_Add(CContext* ctx, CVContext* ctxp)
{
	int add = std::stoi(ctx->vCmd[0]) + std::stoi(ctx->vCmd[1]);
	fmt::print("{}+{}: {}", ctx->vCmd[0], ctx->vCmd[1], add);
}
```
How we can include this function? Easy just add to the map:
```cpp
//CCmdH.h:14
std::map<std::string, std::function<void(CContext*, CVContext*)>> mCmds =
	{
		// [...]
		// The string is how we are going to call this function.
		// And the second is the function. 
		{"add", cmd_Add}
	};
```

# How can I include this to my project?
If you are makinga cli application (like ftp) then use the file cli_main as your main file.

If you want to implement this to your GUI application, you can do this (Remember to delete the `cli_main` file.): 
```cpp
// This a random function simulating the functionality of a read gui lib.
// This funciton is called when the line is sent
void TextBox::writeEvent(Context *TextBoxCtx)
{
	// In this example the functionality of variables 
	// can't work on this example, more info in the variables section.
	
	// We make an instance of all our classes.
	CVContext* ctxp = new CVContext();
	CContext* ctx = new CContext();
	CParser Parser;
	CCmdH Cmdh;
	
	// Set the line string to our context and everything will set to go!
	ctx->sLine = TextBoxCtx->Line;
	
	Parser.Parse(ctx, ctxp);
	Cmdh.CmdHandler(ctx, ctxp);
}
```

# Functionalities

## Functions
Functions are stored in a map and are stored in pairs. 

The head (or first element) is a string, and is the name of the function in the shell. That means this is how we are going to call the function inside the shell. 

The Tail (or second element) is a function type. This function takes as an arguments  the Context and the Persistent Context.

## Variables
Variables are stored in the Persistent Context. You may ask: why there is two context? 
The normal Context is reset every time a new line needs to be processed. The Persistent Context (or Constant Context), keeps their values. Knowing this we can continue.

The variables are replaced with their actual values at the parsing time. Except with the command `set`.	 

The `ctxp->mVars` is a map. The head is the name. Important, if we have a variable called `$N` it actually value in the database is `$N`, with the dollar sign. The second value is the actual value, and the type is `std::any` for fast cast.

