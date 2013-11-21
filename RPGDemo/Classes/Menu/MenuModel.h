#pragma once
#include "STMVC/STMVC.h"
#include "MenuProxy.h"
class CMenuModel :
	public CSTModel<CMenuProxy>
{
public:
	CMenuModel(void);
	~CMenuModel(void);

	void GetInfo()
	{
		GetProxy()->GetInfo();
	}
};

