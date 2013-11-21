#ifndef  _ST_CONTROLLER_H_
#define  _ST_CONTROLLER_H_
#include "STObject.h"

template<class T = CSTObject>
class CSTController:public CSTObject
{
private:
	T *m_pModel;
	void InitModel()
	{
		if(!m_pModel)
		{
			m_pModel = new T;

			if(m_pModel->GetClassType()==ST_CLASS_TYPE_OBJECT)
			{
				UninitModel();
			}
		}
	}

	void UninitModel()
	{
		if(m_pModel)
		{
			delete m_pModel;
			m_pModel = 0;
		}
	}
public:
	CSTController(void);
	virtual ~CSTController(void);
	virtual Type GetClassType()
	{
		return ST_CLASS_TYPE_CONTROLLER;
	}

protected:
	T *GetModel()
	{
		return m_pModel;
	}
};

template<class T>
CSTController<T>::CSTController(void):m_pModel(0)
{
	InitModel();
	if(m_pModel)
	{
		m_pModel->SetParent(this);
	}
}
template<class T>
CSTController<T>::~CSTController(void)
{
	UninitModel();
}

#endif
