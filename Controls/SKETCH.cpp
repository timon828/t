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
//        텍스트를 그린다.
//  Param
//        pDC = 그림을 그릴 그래픽 헨들.
//        rc = 영역.
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
