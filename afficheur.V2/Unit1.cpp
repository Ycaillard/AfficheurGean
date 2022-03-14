//---------------------------------------------------------------------------

#include <fmx.h>
#pragma hdrstop
#include "AfficheurGeant.h"
#include <chrono>
#include <thread>
#include <time.h>
#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.fmx"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
	AfficheurGeant aff;
	int loop=1;

do
   {
		aff.ModifierImage("bleu.png");
		aff.EnvoyerImageEtTexte();
		Sleep(300);


		aff.ModifierImage("rouge.png");
		aff.EnvoyerImageEtTexte();
		Sleep(300);


		aff.ModifierImage("vert.png");
		aff.EnvoyerImageEtTexte();
		Sleep(300);
   }while (loop==1);

}
//---------------------------------------------------------------------------


void __fastcall TForm1::Button2Click(TObject *Sender)
{
	SNClientTCP client;
	AfficheurGeant afficher;
	if(Edit1->Text == "172.20.21.199")
	{
		client.SeConnecterAUnServeur("172.20.21.199", 80);
		Label3->Visible=true;
		Label3->Name="connecté";

	}
	else
	{
		Label3->Visible=true;
		Label3->Name="non connecté";
	}

}
//---------------------------------------------------------------------------


void __fastcall TForm1::Button3Click(TObject *Sender)
{
AfficheurGeant aff;
aff.ModifierImage("blanc.png");
aff.EnvoyerImageEtTexte();

}
//---------------------------------------------------------------------------

