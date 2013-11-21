#ifndef  _ST_OBJECT_H_
#define  _ST_OBJECT_H_

class CSTCommand;
class CSTObject
{
private:
	static CSTObject *m_pInstance;
	CSTObject *m_pParent;
public:
	CSTObject(void);
	virtual ~CSTObject(void);

	 enum Type
	{
		ST_CLASS_TYPE_OBJECT,
		ST_CLASS_TYPE_VIEW,
		ST_CLASS_TYPE_CONTROLLER,
		ST_CLASS_TYPE_MODEL,
		ST_CLASS_TYPE_COMMAND,
		ST_CLASS_TYPE_PROXY,
	};

	virtual Type GetClassType();

	static CSTObject *SharedProxy();
	void SetParent(CSTObject *p_Parent);
	CSTObject *GetParent();
	virtual void OnCommand(CSTCommand *p_cmd);
	void SendCommand(CSTCommand *p_cmd);
};

#endif
