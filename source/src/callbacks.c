#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gnome.h>
#include <sys/stat.h>

#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include "donnees.h"

//--- Les fichiers
FILE *fe;
char fic_out [512];
FILE *fs;
char enreg[256];
char fic_tmp [512];
struct stat fic_st;
//--- Mot de passe
char mpasse [10];
char mcle [10];
char code2 [4];
char cle2;
//--- Autres
float pourcent;
float step;
char message [128];

char * FichierSeul (char fc [])
{
  char res [512];
  char ent [512];
  char tmp [512];
  int i,j;
  strcpy(ent,fc);
  j=0;
  i=strlen(ent)-1;
  while ((i>=0) && (ent[i]!='/'))
  {
    tmp[j]=ent[i];
    j++;
    i--;
  }
  tmp[j]='\0';
  j=0;
  for (i=strlen(tmp)-1;i>=0;i--)
  {
    res[j]=tmp[i];
    j++;
  }
  res[j]='\0';
  return(res);
}

int IsDatacod (char f [])
{
  int ret = 1;
  char fd1 [255];
  FILE * fd;
  int i;
  char c;
  char entete [8];
  strcpy(entete,"DataCod\0");
  strcpy(fd1,f);
  fd=fopen(fd1,"rb");
  if (fd!=NULL)
  {
    for (i=0;i<7;i++)
    {
      if (fread(&c,sizeof(char),1,fd)==1)
      {
        if (c!=entete[i]) ret=0;
      }
      else ret=0;
    }
    fclose(fd);
  }
  else ret=-1;
  return(ret);
}

int VerifClee (char f [],char cd[], char cle)
{
  char fd1 [255];
  char codeX[5];
  char cleX;
  FILE * fd;
  char rcd[6];
  int i;
  // Récup données
  for (i=0;i<4;i++) codeX[i]=cd[i];
  codeX[4]='\0';
  cleX=cle;
  strcpy(fd1,f);
  // Lecture clée
  fd=fopen(fd1,"rb");
  if (fd!=NULL)
  {
    fseek(fd, sizeof(char) * 7L, 0);
    for (i=0;i<5;i++) fread(&rcd[i], sizeof(char), 1, fd);
    fclose(fd);
  }
  rcd[5]='\0';
  // Décodage
  rcd[4]=(rcd[4] ^ codeX[3] ^ codeX[2] ^ codeX[1] ^ codeX[0]);
  rcd[0] = rcd[0] ^ cleX ^ codeX[1];
  rcd[1] = rcd[1] ^ cleX ^ codeX[2];
  rcd[2] = rcd[2] ^ cleX ^ codeX[3];
  rcd[3] = rcd[3] ^ cleX ^ codeX[0];
  // Vérif clée
  return(((codeX[0]==rcd[0])&&(codeX[1]==rcd[1])&&(codeX[2]==rcd[2])&&(codeX[3]==rcd[3])&&(cleX==rcd[4])));
}

void
on_Fichier_activate                    (GtkMenuItem     *menuitem,
                                        gpointer         user_data)
{

}


void
on_encoder_activate                    (GtkMenuItem     *menuitem,
                                        gpointer         user_data)
{
  traitement=1;
  gtk_widget_show(fileselection1);
}


void
on_decoder_activate                    (GtkMenuItem     *menuitem,
                                        gpointer         user_data)
{
  traitement=2;
  gtk_widget_show(fileselection2);
}


void
on_quitter_activate                    (GtkMenuItem     *menuitem,
                                        gpointer         user_data)
{
  gtk_main_quit();
}


void
on_a_propos1_activate                  (GtkMenuItem     *menuitem,
                                        gpointer         user_data)
{
  gtk_widget_show(about1);
}


void
on_fileselection1_destroy              (GtkObject       *object,
                                        gpointer         user_data)
{
  fileselection1=create_fileselection1();
}


void
on_ok_button3_clicked                  (GtkButton       *button,
                                        gpointer         user_data)
{
  if (traitement==1)
  {
    strcpy(fic_in,gtk_file_selection_get_filename(fileselection1));
    if (fic_in[strlen(fic_in)-1]!='/')
    {
      if (stat(fic_in,&fic_st)==0)
      {
        gtk_widget_hide(fileselection1);
        gtk_widget_show(fileselection2);
      }
      else
      {
        gtk_label_set_text(lookup_widget(Erreur,"L_Erreur"),"Fichier introuvable !!! ");
        gtk_widget_show(Erreur);
      }
    }
  }
  else
  {
    strcpy(fic_out,gtk_file_selection_get_filename(fileselection1));
    if (fic_out[strlen(fic_out)-1]!='/')
    {
      if (strcmp(fic_in,fic_out)!=0)
      {
        if (stat(fic_out,&fic_st)!=0)
        {
          gtk_widget_hide(fileselection1);
          strcpy(fic_tmp,FichierSeul(fic_in));
          gtk_entry_set_text(lookup_widget(Mot_de_passe,"Champ_1"),fic_tmp); 
          strcpy(fic_tmp,FichierSeul(fic_out));
          gtk_entry_set_text(lookup_widget(Mot_de_passe,"Champ_2"),fic_tmp); 
          gtk_entry_set_text(lookup_widget(Mot_de_passe,"Passe"),"");
          gtk_entry_set_text(lookup_widget(Mot_de_passe,"cle"),"");
          gtk_widget_show(Mot_de_passe);
        }
        else
        {
          strcpy(message,"Ecraser le fichier \0");
          strcat(message,fic_out);
          strcat(message," ??? ");
          gtk_label_set_text(lookup_widget(Attention,"L_Attention"),message);
          gtk_widget_show(Attention);
        }
      }
      else
      {
        gtk_label_set_text(lookup_widget(Erreur,"L_Erreur"),"Nom de fichier incorrect !!! ");
        gtk_widget_show(Erreur);
      }
    }
  }
}


void
on_cancel_button3_clicked              (GtkButton       *button,
                                        gpointer         user_data)
{
  gtk_widget_hide(fileselection1);
}


void
on_fileselection2_destroy              (GtkObject       *object,
                                        gpointer         user_data)
{
  fileselection2=create_fileselection2();
}


void
on_ok_button4_clicked                  (GtkButton       *button,
                                        gpointer         user_data)
{
  if (traitement==1)
  {
    strcpy(fic_out,gtk_file_selection_get_filename(fileselection2));
    if (fic_out[strlen(fic_out)-1]!='/')
    {
      if (strcmp(fic_in,fic_out)!=0)
      {
        if (stat(fic_out,&fic_st)!=0)
        {
          gtk_widget_hide(fileselection2);
          strcpy(fic_tmp,FichierSeul(fic_in));
          gtk_entry_set_text(lookup_widget(Mot_de_passe,"Champ_1"),fic_tmp); 
          strcpy(fic_tmp,FichierSeul(fic_out));
          gtk_entry_set_text(lookup_widget(Mot_de_passe,"Champ_2"),fic_tmp); 
          gtk_entry_set_text(lookup_widget(Mot_de_passe,"Passe"),"");
          gtk_entry_set_text(lookup_widget(Mot_de_passe,"cle"),"");
          gtk_widget_show(Mot_de_passe);
        }
        else
        {
          strcpy(message,"Ecraser le fichier \0");
          strcat(message,fic_out);
          strcat(message," ??? ");
          gtk_label_set_text(lookup_widget(Attention,"L_Attention"),message);
          gtk_widget_show(Attention);
        }
      }
      else
      {
        gtk_label_set_text(lookup_widget(Erreur,"L_Erreur"),"Nom de fichier incorrect !!! ");
        gtk_widget_show(Erreur);
      }
    }
  }
  else
  {
    strcpy(fic_in,gtk_file_selection_get_filename(fileselection2));
    if (fic_in[strlen(fic_in)-1]!='/')
    {
      if (stat(fic_in,&fic_st)==0)
      {
        gtk_widget_hide(fileselection2);
        gtk_widget_show(fileselection1);
      }
      else
      {
        gtk_label_set_text(lookup_widget(Erreur,"L_Erreur"),"Fichier introuvable !!! ");
        gtk_widget_show(Erreur);
      }
    }
  }
}


void
on_cancel_button4_clicked              (GtkButton       *button,
                                        gpointer         user_data)
{
  gtk_widget_hide(fileselection2);
}


void
on_Mot_de_passe_destroy                (GtkObject       *object,
                                        gpointer         user_data)
{
  Mot_de_passe=create_Mot_de_passe();
}


void
on_OK_BT_clicked                       (GtkButton       *button,
                                        gpointer         user_data)
{
  strcpy(mpasse,gtk_entry_get_text(lookup_widget(Mot_de_passe,"Passe")));
  strcpy(mcle,gtk_entry_get_text(lookup_widget(Mot_de_passe,"cle")));
  if (strlen(mpasse)!=4)
  {
    gtk_label_set_text(lookup_widget(Erreur,"L_Erreur"),"Le mot de passe doit faire 4 caractères !!! ");
    gtk_widget_show(Erreur);
  }
  else if (strlen(mcle)!=1)
  {
    gtk_label_set_text(lookup_widget(Erreur,"L_Erreur"),"La clée doit faire 1 caractère !!! ");
    gtk_widget_show(Erreur);
  }
  else
  {
    gtk_widget_hide(Mot_de_passe);
    if (traitement==1)
    {    
      //----------------------------
      // CODAGE DU FICHIER
      //----------------------------
      fe=fopen(fic_in,"rb");
      if (fe!=NULL)
      {
        fstat(fileno(fe),&fic_st);
        step=256.0/fic_st.st_size;
        pourcent=0.0;
        gtk_progress_bar_update(lookup_widget(Ecran_1_,"progressbar1"),pourcent);
        gtk_widget_queue_draw(lookup_widget(Ecran_1_,"progressbar1"));
        //--- coder la clée
        cle2=(mcle[0] ^ mpasse[3] ^ mpasse[2] ^ mpasse[1] ^ mpasse[0]);
        code2[0] = mpasse[0] ^ mcle[0] ^ mpasse[1];
        code2[1] = mpasse[1] ^ mcle[0] ^ mpasse[2];
        code2[2] = mpasse[2] ^ mcle[0] ^ mpasse[3];
        code2[3] = mpasse[3] ^ mcle[0] ^ mpasse[0];
        //--- Ouverture fichier 2
        fs=fopen(fic_out,"wb");
        if (fs==NULL)
        {
          strcpy(message,"Impossible de créer \0");
          strcat(message,FichierSeul(fic_out));
          strcat(message," !!! ");
          gtk_label_set_text(lookup_widget(Erreur,"L_Erreur"),message);
          gtk_widget_show(Erreur);
        }
        else
        {
          //--- Ecrire l'entete
          int i;
          int j,n;
          char ent [12];
          ent[0]='D';
          ent[1]='a';
          ent[2]='t';
          ent[3]='a';
          ent[4]='C';
          ent[5]='o';
          ent[6]='d';
          for (i=0;i<4;i++) ent[7+i]=code2[i];
          ent[11]=cle2;
          fwrite(&ent,sizeof(char),12,fs);
          //--- Codage
          while (!feof(fe))
          {
            //--- lecture
            j=fread(&enreg,sizeof(char),256,fe);
            //--- codage
            n=1;
            for (i=0;i<j;i++)
            {
              enreg[i]^=mpasse[n];
              n++;
              if (n==4) n=0;
            }
            //--- ecriture
            fwrite(&enreg,sizeof(char),j,fs);
            pourcent+=step;
            if (pourcent>=1.0) pourcent=1.0;
            gtk_progress_bar_update(lookup_widget(Ecran_1_,"progressbar1"),pourcent);
            gtk_widget_queue_draw(lookup_widget(Ecran_1_,"progressbar1"));
          }
          fclose(fs);
        }
        fclose(fe);
        strcpy(message,"Codage du fichier \0");
        strcat(message,FichierSeul(fic_in));
        strcat(message," effectué ... ");
        gtk_label_set_text(lookup_widget(Information,"L_Info"),message);
        gtk_widget_show(Information);
      }
      else
      {
          strcpy(message,"Impossible d'ouvrir \0");
          strcat(message,FichierSeul(fic_in));
          strcat(message," !!! ");
          gtk_label_set_text(lookup_widget(Erreur,"L_Erreur"),message);
          gtk_widget_show(Erreur);
      }
    }
    else
    {
      int r;
      r=IsDatacod(fic_in);
      if (r<0)
      {
        strcpy(message,fic_in);
        strcat(message," fichier non trouvé !!! \0");
        gtk_label_set_text(lookup_widget(Erreur,"L_Erreur"),message);
        gtk_widget_show(Erreur);
      }
      else if (r==0)
      {
        strcpy(message,fic_in);
        strcat(message," n'est pas un fichier Datacod !!! \0");
        gtk_label_set_text(lookup_widget(Erreur,"L_Erreur"),message);
        gtk_widget_show(Erreur);
      }
      else
      {
        int i;
        //--- Décoder la clée
        cle2=mcle[0];
        for (i=0;i<4;i++) code2[i] = mpasse[i];
        //--- Verification du code
        if (VerifClee(fic_in,code2,cle2))
        {
          //--- Ouverture Fichiers
          fe=fopen(fic_in,"rb");
          fstat(fileno(fe),&fic_st);
          fseek(fe, sizeof(char) * 12L, 0);
          step=256.0/(fic_st.st_size-12.0);
          pourcent=0.0;
          gtk_progress_bar_update(lookup_widget(Ecran_1_,"progressbar1"),pourcent);
          gtk_widget_queue_draw(lookup_widget(Ecran_1_,"progressbar1"));
          fs=fopen(fic_out,"wb");
          if (fs==NULL)
          { 
            strcpy(message,"Impossible de créer \0");
            strcat(message,fic_out);
            strcat(message," !!! ");
            gtk_label_set_text(lookup_widget(Erreur,"L_Erreur"),message);
            gtk_widget_show(Erreur);
          }
          else
          {
            int n,i;
            int j;
            //--- Décodage
            while (!feof(fe))
            {
              //--- lecture
              j=fread(&enreg,sizeof(char),256,fe);
              //--- décodage
              n=1;
              for (i=0;i<j;i++)
              {
                enreg[i]^=mpasse[n];
                n++;
                if (n==4) n=0;
              }
              //--- ecriture
              fwrite(&enreg,sizeof(char),j,fs);
              pourcent+=step;
              if (pourcent>=1.0) pourcent=1.0;
              gtk_progress_bar_update(lookup_widget(Ecran_1_,"progressbar1"),pourcent);
              gtk_widget_queue_draw(lookup_widget(Ecran_1_,"progressbar1"));
            }
            fclose(fs);
          }
          fclose(fe);
          strcpy(message,"Déodage du fichier \0");
          strcat(message,FichierSeul(fic_in));
          strcat(message," effectué ... ");
          gtk_label_set_text(lookup_widget(Information,"L_Info"),message);
          gtk_widget_show(Information);
        }
        else
        {
          gtk_label_set_text(lookup_widget(Erreur,"L_Erreur"),"Code incorrect, décryptage abandonné !!! ");
          gtk_widget_show(Erreur);
        }
      }
    }
  }
}


void
on_Annu_BT_clicked                     (GtkButton       *button,
                                        gpointer         user_data)
{
  gtk_widget_hide(Mot_de_passe);
}


void
on_A_propos_destroy                    (GtkObject       *object,
                                        gpointer         user_data)
{
}


void
on_Ok_apropo_clicked                   (GtkButton       *button,
                                        gpointer         user_data)
{
}


void
on_Erreur_destroy                      (GtkObject       *object,
                                        gpointer         user_data)
{
  Erreur=create_Erreur();
}


void
on_button9_clicked                     (GtkButton       *button,
                                        gpointer         user_data)
{
  gtk_widget_hide(Erreur);
}


void
on_Information_destroy                 (GtkObject       *object,
                                        gpointer         user_data)
{
  gtk_progress_bar_update(lookup_widget(Ecran_1_,"progressbar1"),0);
  gtk_widget_queue_draw(lookup_widget(Ecran_1_,"progressbar1"));
  Information=create_Information();
}


void
on_button10_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{
  gtk_progress_bar_update(lookup_widget(Ecran_1_,"progressbar1"),0);
  gtk_widget_queue_draw(lookup_widget(Ecran_1_,"progressbar1"));
  gtk_widget_hide(Information);
}


void
on_Attention_destroy                   (GtkObject       *object,
                                        gpointer         user_data)
{
  Attention=create_Attention();
}


void
on_button14_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{
  gtk_widget_hide(Attention);
  if (traitement==1)
  {
    gtk_widget_hide(fileselection2);
    strcpy(fic_tmp,FichierSeul(fic_in));
    gtk_entry_set_text(lookup_widget(Mot_de_passe,"Champ_1"),fic_tmp); 
    strcpy(fic_tmp,FichierSeul(fic_out));
    gtk_entry_set_text(lookup_widget(Mot_de_passe,"Champ_2"),fic_tmp); 
    gtk_entry_set_text(lookup_widget(Mot_de_passe,"Passe"),"");
    gtk_entry_set_text(lookup_widget(Mot_de_passe,"cle"),"");
    gtk_widget_show(Mot_de_passe);
  }  
  else
  {
    gtk_widget_hide(fileselection1);
    strcpy(fic_tmp,FichierSeul(fic_in));
    gtk_entry_set_text(lookup_widget(Mot_de_passe,"Champ_1"),fic_tmp); 
    strcpy(fic_tmp,FichierSeul(fic_out));
    gtk_entry_set_text(lookup_widget(Mot_de_passe,"Champ_2"),fic_tmp); 
    gtk_entry_set_text(lookup_widget(Mot_de_passe,"Passe"),"");
    gtk_entry_set_text(lookup_widget(Mot_de_passe,"cle"),"");
    gtk_widget_show(Mot_de_passe);
  }  
}


void
on_button15_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{
  gtk_widget_hide(Attention);
}


void
on_Ecran_1__destroy                    (GtkObject       *object,
                                        gpointer         user_data)
{
  gtk_main_quit();
}


void
on_about1_destroy                      (GtkObject       *object,
                                        gpointer         user_data)
{
  gtk_widget_hide(about1);
}

