#pragma once
#include <UIAutomationClient.h>
#include <cassert>
#include <vector>
#include <string>
#define assertm(exp, msg) assert(((void)msg, exp))


enum TypeCond
{
	NamePropertyId = 30005,
	AutomationIdPropertyId = 30011,
	ClassNamePropertyId = 30012,
	FrameworkIdPropertyId = 30024,
};
struct VecCond
{
	TypeCond id;
	std::wstring value;
	VecCond(TypeCond i, std::wstring s) :id(i), value(s) {}
};
class UIA
{
public:
	UIA();
	~UIA();
	IUIAutomationElement * elem;
	IUIAutomationElement * FinElemByCond(std::vector<VecCond> script);


private:
	IUIAutomation * Handle;
};