//---------------------------------------------------------------------------

#ifndef Unit3H
#define Unit3H
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
//---------------------------------------------------------------------------
class TafficheStop : public TThread
{
private:
protected:
	void __fastcall Execute();
public:
	__fastcall TafficheStop(bool CreateSuspended);
};
//---------------------------------------------------------------------------
#endif
