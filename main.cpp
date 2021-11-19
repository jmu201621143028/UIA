#include "uia.h"
#include <iostream>

int main()
{
	UIA uiauto;
#ifdef SCROLL
	std::vector<VecCond> cond{ {NamePropertyId, L"计算器"},
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
#endif

	std::vector<VecCond> cond{ {NamePropertyId, L"计算器"},
							   {FrameworkIdPropertyId, L"XAML"},
							   {ClassNamePropertyId, L"LandmarkTarget"},
							   {ClassNamePropertyId, L"ListView"},
							   {NamePropertyId, L"位移位"},
							   {AutomationIdPropertyId, L"bitShiftButton"}
	};
	IUIAutomationElement * Toggle = uiauto.FinElemByCond(cond);
	VARIANT varProp;
	varProp.vt = VT_BSTR;
	Toggle->get_CurrentLocalizedControlType(&varProp.bstrVal);
	IUIAutomationTogglePattern * togglepatten;
	Toggle->GetCurrentPattern(UIA_TogglePatternId, (IUnknown **)&togglepatten);
	togglepatten->Toggle();
	Sleep(800);
	cond = {{NamePropertyId, L"计算器"},
			{FrameworkIdPropertyId, L"XAML"},
			{NamePropertyId, L"弹出窗口"},
			{AutomationIdPropertyId, L"BitShiftFlyout"},
			{AutomationIdPropertyId, L"logicalShiftButton"},
	};
	IUIAutomationElement * Button = uiauto.FinElemByCond(cond);
	IUIAutomationSelectionItemPattern * sip;
	Button->GetCurrentPattern(UIA_SelectionItemPatternId, (IUnknown **)&sip);
	sip->Select();
	Sleep(1000);
	//Sleep(10000);
	return 0;
}