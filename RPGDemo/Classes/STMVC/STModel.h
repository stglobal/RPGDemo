#ifndef  _ST_MODEL_H_
#define  _ST_MODEL_H_
#include "STObject.h"

template<class T = CSTObject>
class CSTModel:public CSTObject
{
private:
	T *m_pProxy;
public:
	CSTModel(void);
	virtual ~CSTModel(void);

	virtual Type GetClassType()
	{
		return ST_CLASS_TYPE_MODEL;
	}
protected:
	T *GetProxy()
	{
		return m_pProxy;
	}
};

template<class T>
CSTModel<T>::CSTModel(void):m_pProxy(0)
{
	m_pProxy = reinterpret_cast<T*>(T::SharedProxy());
	if(m_pProxy->GetClassType()==ST_CLASS_TYPE_OBJECT)
	{
		m_pProxy = 0;
	}

	if(m_pProxy)
	{
		m_pProxy->AddParent(this);
	}
}

template<class T>
CSTModel<T>::~CSTModel(void)
{
	if(m_pProxy)
	{
		m_pProxy->RemoveParent(this);
	}
}

#endif

