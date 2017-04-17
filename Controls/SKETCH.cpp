#include "stdafx.h"
#include "SKETCH.h"


SKETCH::SKETCH()
{
}


SKETCH::~SKETCH()
{
}

BOOL SKETCH::RECT(CDC* pDC, CRect rc, COLORREF crBrush, COLORREF crPen)
////////////////////////////////////////////////////////////////////////////////
//  Description
//        �ؽ�Ʈ�� �׸���.
//  Param
//        pDC = �׸��� �׸� �׷��� ���.
//        rc = ����.
//  Log
//        create/2009/08/09 JUN DAE HYUN.
////////////////////////////////////////////////////////////////////////////////
{
	if (pDC == NULL)
		return FALSE;

	CPen pen(PS_SOLID, 1, crPen);
	CPen *oldPen = pDC->SelectObject(&pen);
	CBrush brush(crBrush);
	CBrush *oldBrush = pDC->SelectObject(&brush);

	rc.right = rc.right + rc.left;
	rc.bottom = rc.top + rc.bottom;
	pDC->Rectangle(&rc);

	pDC->SelectObject(oldPen);
	pDC->SelectObject(oldBrush);
	pen.DeleteObject();
	brush.DeleteObject();
	return TRUE;
}
