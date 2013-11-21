#ifndef  _ST_VIEW_H_
#define  _ST_VIEW_H_
#include "STObject.h"

template<class T = CSTObject>
class CSTView:public CSTObject
{
private:
	T *m_pController;
	void InitController()
	{
		if(!m_pController)
		{
			m_pController = new T;
			if(m_pController->GetClassType()==ST_CLASS_TYPE_OBJECT)
			{
				UninitController();
			}
		}
	}

	void UninitController()
	{
		if(m_pController)
		{
			delete m_pController ;
			m_pController = 0;
		}
	}
public:
	CSTView(void);
	virtual ~CSTView(void);

	virtual Type GetClassType()
	{
		return ST_CLASS_TYPE_VIEW;
	}
protected:
	T *GetController()
	{
		return m_pController;
	}
};

template<class T>
CSTView<T>::CSTView(void):m_pController(0)
{
	InitController();
	if(m_pController)
	{
		m_pController->SetParent(this);
	}
}

template<class T>
CSTView<T>::~CSTView(void)
{
	UninitController();
}

#endif