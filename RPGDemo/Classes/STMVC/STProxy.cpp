#include "STProxy.h"
#include <algorithm>
#include "STCommand.h"

CSTProxy *CSTProxy::m_pInstance = 0;
CSTProxy::CSTProxy(void)
{
}


CSTProxy::~CSTProxy(void)
{
}

CSTProxy *CSTProxy::SharedProxy()
{
	if(!m_pInstance)
	{
		m_pInstance = new CSTProxy;
	}

	return m_pInstance;
}

void CSTProxy::AddParent(CSTObject *p_Parent)
{
	if(std::find(m_pParentVec.begin(),m_pParentVec.end(),p_Parent) == m_pParentVec.end())
	{
		m_pParentVec.push_back(p_Parent);
	}
}

void CSTProxy::RemoveParent(CSTObject *p_Parent)
{
	std::vector<CSTObject*>::iterator iter_find = std::find(m_pParentVec.begin(),m_pParentVec.end(),p_Parent);
	if(iter_find != m_pParentVec.end())
	{
		m_pParentVec.erase(iter_find);
	}
}

void CSTProxy::SendCommand(CSTCommand *p_cmd)
{
	for(size_t i=0;i<m_pParentVec.size();i++)
	{
		CSTObject *p_parent = m_pParentVec[i];

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
}