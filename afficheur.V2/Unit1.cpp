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
#include <fstream>

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
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button3Click(TObject *Sender)
{
	SecondThread->Terminate(); //permet de faire quitter le premier thread
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
		Label3->Visible=false;
		Label3->Name="non connecté";
	}

}
//---------------------------------------------------------------------------
void __fastcall TForm1::ImageControl1Change(TObject *Sender)
{
 //TForm1->TImage1->Picture->LoadFromFile("rouge.png");
}
//---------------------------------------------------------------------------

void __fastcall TForm1::RadioButton1Click(TObject *Sender)
{
	SNClientTCP client;
	client.SeConnecterAUnServeur("172.20.21.221", 80);
	char requete[1000];
	sprintf(requete,"GET /public_html/rest.php/playlist1 HTTP/1.1\r\nHost: 172.20.21.221\r\nConnection: keep-alive\r\n\r\n");
	int lreq=strlen(requete);
	client.Envoyer(requete,lreq);
}
//---------------------------------------------------------------------------



void __fastcall TForm1::RadioButton2Click(TObject *Sender)
{
	SNClientTCP client;
	client.SeConnecterAUnServeur("172.20.21.221", 80);
	char requete[1000];
	sprintf(requete,"GET /public_html/rest.php/playlist2 HTTP/1.1\r\nHost: 172.20.21.221\r\nConnection: keep-alive\r\n\r\n");
	int lreq=strlen(requete);
	client.Envoyer(requete,lreq);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::RadioButton3Click(TObject *Sender)
{
	SNClientTCP client;
	client.SeConnecterAUnServeur("172.20.21.221", 80);
	char requete[1000];
	sprintf(requete,"GET /public_html/rest.php/playlist3 HTTP/1.1\r\nHost: 172.20.21.221\r\nConnection: keep-alive\r\n\r\n");
	int lreq=strlen(requete);
	client.Envoyer(requete,lreq);
}
//---------------------------------------------------------------------------

