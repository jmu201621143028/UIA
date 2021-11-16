#include "uia.h"

UIA::UIA()
{
	CoInitialize(NULL);
	assertm(
		CoCreateInstance(CLSID_CUIAutomation, NULL, CLSCTX_INPROC_SERVER, IID_IUIAutomation,
			reinterpret_cast<void **>(&Handle)) == S_OK, "create COM error"
	);

}

UIA::~UIA()
{
	CoUninitialize();
}

IUIAutomationElement * UIA::FinElemByCond(std::vector<VecCond> script)
{
	VARIANT varProp;
	varProp.vt = VT_BSTR;
	IUIAutomationCondition * pCondition;
	Handle->GetRootElement(&elem);
	for (auto item : script)
	{
		varProp.bstrVal = SysAllocString(item.value.c_str());
		Handle->CreatePropertyCondition(item.id, varProp, &pCondition);
		elem->FindFirst(TreeScope_Children, pCondition, &elem);
	}
	return elem;
}
