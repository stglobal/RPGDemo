#include "STObject.h"
#include "STCommand.h"

CSTObject *CSTObject::m_pInstance = 0;

CSTObject::CSTObject(void):m_pParent(0)
{
}


CSTObject::~CSTObject(void)
{
}

CSTObject::Type CSTObject::GetClassType()
{
	return ST_CLASS_TYPE_OBJECT;
}

CSTObject *CSTObject::SharedProxy()
{
	if(!m_pInstance)
	{
		m_pInstance = new CSTObject;
	}

	return m_pInstance;
}

void CSTObject::SetParent(CSTObject *p_Parent)
{
	m_pParent = p_Parent;
}

CSTObject *CSTObject::GetParent()
{
	return m_pParent;
}

void CSTObject::OnCommand(CSTCommand *p_cmd)
{

}

void CSTObject::SendCommand(CSTCommand *p_cmd)
{
	CSTObject *p_parent = this->GetParent();

	do
	{
		if(p_parent)
		{
			p_parent->OnCommand(p_cmd);
			if(!p_cmd->IsCompleted())
			{
				p_parent = p_parent->GetParent();
			}
		}else
		{
			break;
		}
	}while(true);
	
}