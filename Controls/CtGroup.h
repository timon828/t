#pragma once

class CtWnd;
class CtGroup
{
public:
	CtGroup();
	~CtGroup();
private:
	int m_nGIDD;
	std::vector<CtWnd*> m_vItem;
public:
	void SetIDD(int nGIDD);
	int GetIDD();
	int AddItem(CtWnd* pTWnd);
	int DeleteItem(CtWnd* pTWnd);
	int DoAction(CtWnd* pTWnd);
	BOOL IsItem(CtWnd* pTWnd);
};

