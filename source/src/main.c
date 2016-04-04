/*
 * main.c initial généré par Glade. Editer ce fichier à votre
 * convenance. Glade n'écrira plus dans ce fichier.
 */

#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gnome.h>

#include "interface.h"
#include "support.h"
#include "donnees.h"

GtkWidget *Ecran_1_;
GtkWidget *fileselection1;
GtkWidget *fileselection2;
GtkWidget *Mot_de_passe;
GtkWidget *about1;
GtkWidget *Erreur;
GtkWidget *Attention;
GtkWidget *Information;
char fic_in [512];
int traitement;

int
main (int argc, char *argv[])
{


#ifdef ENABLE_NLS
  bindtextdomain (PACKAGE, PACKAGE_LOCALE_DIR);
  textdomain (PACKAGE);
#endif

  gnome_init ("datacod", VERSION, argc, argv);

  /*
   * The following code was added by Glade to create one of each component
   * (except popup menus), just so that you see something after building
   * the project. Delete any components that you don't want shown initially.
   */

  // Récupération du fichier à traiter
  traitement=0; 
  if (argc>1)
  {
    FILE * fd;
    int i;
    char c;
    char entete [8];
    traitement=2;
    strcpy(fic_in,argv[1]);
    strcpy(entete,"DataCod\0");
    fd=fopen(fic_in,"rb");
    if (fd!=NULL)
    {  
      for (i=0;i<7;i++)
      {
        if (fread(&c,sizeof(char),1,fd)==1)
        {
          if (c!=entete[i]) traitement=1;
        }
        else traitement=0;
      }
      fclose(fd);
    }
    else traitement=0;
  }

  Ecran_1_ = create_Ecran_1_ ();
  gtk_widget_show (Ecran_1_);
  fileselection1 = create_fileselection1 ();
  if (traitement==2) gtk_widget_show (fileselection1);
  fileselection2 = create_fileselection2 ();
  if (traitement==1) gtk_widget_show (fileselection2); 
  Mot_de_passe = create_Mot_de_passe ();
  about1 = create_about1 ();
  Erreur = create_Erreur ();
  Attention = create_Attention ();
  Information = create_Information ();

  gtk_main ();
  return 0;
}

