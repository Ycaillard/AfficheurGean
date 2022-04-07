//---------------------------------------------------------------------------

#include <fmx.h>
#pragma hdrstop
#include "AfficheurGeant.h"
#include <chrono>
#include <thread>
#include <string>
#include <iostream>
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

	SecondThread = new Taffiche(false); // crée et exécute le thread

/*	 std::thread t1([]() {
	 AfficheurGeant aff;

		aff.ModifierImage("bleu.png");
		aff.EnvoyerImageEtTexte();
		Sleep(300);

		aff.ModifierImage("bleu.png");
		aff.EnvoyerImageEtTexte();
		Sleep(300);

		aff.ModifierImage("bleu.png");
		aff.EnvoyerImageEtTexte();
		Sleep(300);


	 });
*/
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button3Click(TObject *Sender)
{
	SecondThread->Terminate();
/*	std::atomic_bool stop_thread_1 = false;
	if (stop_thread_1)
	return;
	stop_thread_1 = true;
	stop_thread_1 = false;
*/
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
void __fastcall TForm1::ImageControl1Change(TObject *Sender)
{

 //TForm1->TImage1->Picture->LoadFromFile("rouge.png");

}
//---------------------------------------------------------------------------

