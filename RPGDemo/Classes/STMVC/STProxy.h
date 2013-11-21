#ifndef  _ST_PROXY_H_
#define  _ST_PROXY_H_
#include <vector>
#include "STObject.h"

class CSTProxy:public CSTObject
{
private:
	static CSTProxy *m_pInstance;
	std::vector<CSTObject*> m_pParentVec;
public:
	CSTProxy(void);
	virtual ~CSTProxy(void);

	virtual Type GetClassType()
	{
		return ST_CLASS_TYPE_PROXY;
	}

	static CSTProxy *SharedProxy();

	void AddParent(CSTObject *p_Parent);
	void RemoveParent(CSTObject *p_Parent);

	void SendCommand(CSTCommand *p_cmd);
};

#endif

