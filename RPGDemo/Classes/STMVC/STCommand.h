#ifndef  _ST_COMMAND_H_
#define  _ST_COMMAND_H_
#include "STObject.h"

#define REG_CMD(CMD_ID) \
int GetId()\
{\
	return CMD_ID;\
};

class CSTCommand:public CSTObject
{
private:
	bool m_bComplish;
public:
	CSTCommand(void);
	virtual ~CSTCommand(void);

	virtual Type GetClassType()
	{
		return ST_CLASS_TYPE_COMMAND;
	}

	virtual int GetId() = 0;

	void SetCompleted(const bool &bComplish);
	bool IsCompleted();
};

#endif

