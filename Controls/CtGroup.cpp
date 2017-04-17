#include "stdafx.h"
#include "CtGroup.h"


CtGroup::CtGroup()
	: m_nGIDD(0)
{
}


CtGroup::~CtGroup()
{
	m_vItem.clear();
}


void CtGroup::SetIDD(int nGIDD)
{
	m_nGIDD = nGIDD;
}


int CtGroup::GetIDD()
{
	return m_nGIDD;
}


int CtGroup::AddItem(CtWnd* pTWnd)
{
	if (pTWnd == NULL)
		return -1;
	m_vItem.push_back(pTWnd);
	return 0;
}


int CtGroup::DeleteItem(CtWnd* pTWnd)
{
	// 그룹에서 빠지는것이고 실제 아이템 윈도우는 삭제되지 않는다.
	for (vector <int>::size_type i = 0; m_vItem.size(); i++)
	{
		if (m_vItem[i] == pTWnd)
		{
			m_vItem.erase(m_vItem.begin() + i, m_vItem.begin() + i);
			break;
		}
	}
	return 0;
}


int CtGroup::DoAction(CtWnd* pTWnd)
{
	if (pTWnd == NULL)
		return -1;
	for (vector <int>::size_type i = 0; m_vItem.size(); i++)
	{
		if (m_vItem[i] != pTWnd)
			m_vItem[i]->SendMessage(DO_ACTION, ACTION_RELEASE_CHECK, 0);// 나머지는 모두 체크 해제
	}
	return 0;
}


BOOL CtGroup::IsItem(CtWnd* pTWnd)
{
	for (vector <int>::size_type i = 0; m_vItem.size(); i++)
	{
		if (m_vItem[i] == pTWnd)
		{
			return TRUE;
		}
	}
	return FALSE;
}
