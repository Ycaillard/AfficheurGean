//---------------------------------------------------------------------------

#include <System.hpp>
#pragma hdrstop

#include "Unit2.h"
#include "Unit1.h"
#include "AfficheurGeant.h"

#pragma package(smart_init)
//---------------------------------------------------------------------------

//   Important : Les méthodes et les propriétés des objets de la VCL peuvent seulement être
//   utilisées dans une méthode appelée avec Synchronize, par exemple :
//
//      Synchronize(&UpdateCaption);
//
//   où UpdateCaption pourrait ressembler à :
//
//      void __fastcall Taffiche::UpdateCaption()
//      {
//        Form1->Caption = "Mis à jour dans un thread";
//      }
//---------------------------------------------------------------------------

__fastcall Taffiche::Taffiche(bool CreateSuspended)
	: TThread(CreateSuspended)
{
}
//---------------------------------------------------------------------------
void __fastcall Taffiche::Execute()
{
	//---- Placer le code du thread ici ----
  /*	i = 0;
	while(!Terminated)
	{
		i++;
		Synchronize(&UpdateCaption);
		Sleep(1000);   // Pause de 1s
	}
 */
 AfficheurGeant aff;
 while (!Terminated)     //cree la boucle du premier thread pour lancer la premier playlist
	{
	AfficheurGeant aff;

	   aff.ModifierImage("bleu.png");
	   aff.EnvoyerImageEtTexte();
	   Sleep(1000);


	   aff.ModifierImage("rouge.png");
	   aff.EnvoyerImageEtTexte();
	   Sleep(1000);


	   aff.ModifierImage("vert.png");
	   aff.EnvoyerImageEtTexte();
	   Sleep(1000);

	   Synchronize(&UpdateCaption);

	}
   /*	Form1->ImageControl1->FImage     */
}
//---------------------------------------------------------------------------

void __fastcall Taffiche::UpdateCaption()
{

}
