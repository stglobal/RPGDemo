#pragma once
#include "STMVC/STMVC.h"
#include "MenuModel.h"

class CMenuController :
	public CSTController<CMenuModel>
{
public:
	CMenuController(void);
	~CMenuController(void);

	void GetInfo()
	{
		GetModel()->GetInfo();
	}
};

