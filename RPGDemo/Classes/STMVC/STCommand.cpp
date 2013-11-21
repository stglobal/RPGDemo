#include "STCommand.h"


CSTCommand::CSTCommand(void):m_bComplish(false)
{
}


CSTCommand::~CSTCommand(void)
{
}

void CSTCommand::SetCompleted(const bool &bComplish)
{
	this->m_bComplish = bComplish;
}

bool CSTCommand::IsCompleted()
{
	return this->m_bComplish;
}