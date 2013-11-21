#pragma once
#include "STMVC/STMVC.h"
#include "MenuCommand.h"
class CMenuProxy:public CSTProxy
{
public:
	CMenuProxy(void);
	~CMenuProxy(void);

	void GetInfo()
	{
		cmd_haha cmd;
		cmd.m = 3;
		cmd.n = 5;
		cmd.haha = "hehe,this is a test";
		SendCommand(&cmd);

	}
};

