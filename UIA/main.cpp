#include "uia.h"
#include <iostream>

int main()
{
	UIA uiauto;

	std::vector<VecCond> cond{ {NamePropertyId, L"¼ÆËãÆ÷"},
							   {FrameworkIdPropertyId, L"XAML"},
							   {AutomationIdPropertyId, L"NavView"},
							   {AutomationIdPropertyId, L"PaneRoot"},
							   {ClassNamePropertyId, L"ScrollViewer"}
	};
	IUIAutomationElement * scroll = uiauto.FinElemByCond(cond);
	int ans;
	scroll->get_CurrentControlType(&ans);
	VARIANT varProp;
	varProp.vt = VT_BSTR;
	scroll->get_CurrentLocalizedControlType(&varProp.bstrVal);


	IUIAutomationScrollPattern * scrollpatten;
	double Percent;
	scroll->GetCurrentPattern(UIA_ScrollPatternId, (IUnknown**)&scrollpatten);
	scrollpatten->get_CurrentVerticalScrollPercent(&Percent);
	std::cout << Percent << std::endl;
	scrollpatten->Scroll(ScrollAmount_NoAmount, ScrollAmount_LargeIncrement);
	scrollpatten->get_CurrentVerticalScrollPercent(&Percent);
	std::cout << Percent << std::endl;
	return 0;
}