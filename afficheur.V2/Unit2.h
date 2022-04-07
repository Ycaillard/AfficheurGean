//---------------------------------------------------------------------------

#ifndef Unit2H
#define Unit2H
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
//---------------------------------------------------------------------------
class Taffiche : public TThread
{
private:
	int i;
protected:
	void __fastcall Execute();
public:
	__fastcall Taffiche(bool CreateSuspended);
    void __fastcall UpdateCaption();
};
//---------------------------------------------------------------------------
#endif
