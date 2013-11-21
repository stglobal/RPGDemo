#pragma once
#include "STMVC/STMVC.h"
#include "MenuController.h"
#include "MenuCommand.h"

class CMenuMain : public cocos2d::CCScene,
	public CSTView<CMenuController>
{
public:
	CMenuMain(void);
	~CMenuMain(void);
	void OnCommand(CSTCommand *p_cmd)
	{
		switch (p_cmd->GetId())
		{
		case CMD_HAHA:
			{
				cmd_haha *p_my_cmd_haha = reinterpret_cast<cmd_haha*>(p_cmd);
				int test = 0;
			}
			break;
		default:
			break;
		}
		
	}

	 bool init();

	 CREATE_FUNC(CMenuMain);
	 void StartGame(CCObject* pSender);
};

