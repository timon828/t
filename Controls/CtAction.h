#pragma once

#define ACTION			WM_APP + 1000
#define DO_ACTION		ACTION


#define ACTION_GROUP_SELECT		DO_ACTION +1
#define ACTION_RELEASE_CHECK	DO_ACTION +2


class CtAction
{
public:
	CtAction();
	~CtAction();
};

