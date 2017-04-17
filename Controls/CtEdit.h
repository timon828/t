#pragma once


// CtEdit

class CtEdit : public CEdit
{
	DECLARE_DYNAMIC(CtEdit)

public:
	CtEdit();
	virtual ~CtEdit();

protected:
	DECLARE_MESSAGE_MAP()
public:
	int tCreate(CtWnd* pTWnd);
};


