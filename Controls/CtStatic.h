#pragma once


// CtStatic

class CtStatic : public CtWnd
{
	DECLARE_DYNAMIC(CtStatic)

public:
	CtStatic();
	virtual ~CtStatic();

protected:
	DECLARE_MESSAGE_MAP()
public:
	int tCreate(CtWnd* pTWnd);
};


