/*
 * NE PAS EDITER CE FICHIER - il est généré par Glade.
 */

#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>

#include <gnome.h>

#include "callbacks.h"
#include "interface.h"
#include "support.h"

static GnomeUIInfo Fichier_menu_uiinfo[] =
{
  {
    GNOME_APP_UI_ITEM, N_("_Encoder..."),
    NULL,
    on_encoder_activate, NULL, NULL,
    GNOME_APP_PIXMAP_NONE, NULL,
    0, 0, NULL
  },
  {
    GNOME_APP_UI_ITEM, N_("_Decoder..."),
    NULL,
    on_decoder_activate, NULL, NULL,
    GNOME_APP_PIXMAP_NONE, NULL,
    0, 0, NULL
  },
  GNOMEUIINFO_SEPARATOR,
  {
    GNOME_APP_UI_ITEM, N_("_Quitter"),
    NULL,
    on_quitter_activate, NULL, NULL,
    GNOME_APP_PIXMAP_NONE, NULL,
    0, 0, NULL
  },
  GNOMEUIINFO_END
};

static GnomeUIInfo aide_menu_uiinfo[] =
{
  {
    GNOME_APP_UI_ITEM, N_("A _propos..."),
    NULL,
    on_a_propos1_activate, NULL, NULL,
    GNOME_APP_PIXMAP_NONE, NULL,
    0, 0, NULL
  },
  GNOMEUIINFO_END
};

static GnomeUIInfo menubar3_uiinfo[] =
{
  {
    GNOME_APP_UI_SUBTREE, N_("_Fichier"),
    NULL,
    Fichier_menu_uiinfo, NULL, NULL,
    GNOME_APP_PIXMAP_NONE, NULL,
    0, 0, NULL
  },
  {
    GNOME_APP_UI_SUBTREE, N_("_Aide"),
    NULL,
    aide_menu_uiinfo, NULL, NULL,
    GNOME_APP_PIXMAP_NONE, NULL,
    0, 0, NULL
  },
  GNOMEUIINFO_END
};

GtkWidget*
create_Ecran_1_ (void)
{
  GtkWidget *Ecran_1_;
  GtkWidget *vbox1;
  GtkWidget *menubar3;
  GtkWidget *vbox2;
  GtkWidget *pixmap;
  GtkWidget *progressbar1;
  GtkWidget *frame1;
  GtkWidget *Etat;

  Ecran_1_ = gtk_window_new (GTK_WINDOW_TOPLEVEL);
  gtk_widget_set_name (Ecran_1_, "Ecran_1_");
  gtk_object_set_data (GTK_OBJECT (Ecran_1_), "Ecran_1_", Ecran_1_);
  gtk_window_set_title (GTK_WINDOW (Ecran_1_), _("Datacod v1.1 for LINUX"));
  gtk_window_set_position (GTK_WINDOW (Ecran_1_), GTK_WIN_POS_CENTER);
  gtk_window_set_policy (GTK_WINDOW (Ecran_1_), FALSE, FALSE, FALSE);

  vbox1 = gtk_vbox_new (FALSE, 0);
  gtk_widget_set_name (vbox1, "vbox1");
  gtk_widget_ref (vbox1);
  gtk_object_set_data_full (GTK_OBJECT (Ecran_1_), "vbox1", vbox1,
                            (GtkDestroyNotify) gtk_widget_unref);
  gtk_widget_show (vbox1);
  gtk_container_add (GTK_CONTAINER (Ecran_1_), vbox1);

  menubar3 = gtk_menu_bar_new ();
  gtk_widget_set_name (menubar3, "menubar3");
  gtk_widget_ref (menubar3);
  gtk_object_set_data_full (GTK_OBJECT (Ecran_1_), "menubar3", menubar3,
                            (GtkDestroyNotify) gtk_widget_unref);
  gtk_widget_show (menubar3);
  gtk_box_pack_start (GTK_BOX (vbox1), menubar3, FALSE, FALSE, 0);
  gnome_app_fill_menu (GTK_MENU_SHELL (menubar3), menubar3_uiinfo,
                       NULL, FALSE, 0);

  gtk_widget_set_name (menubar3_uiinfo[0].widget, "Fichier");
  gtk_widget_ref (menubar3_uiinfo[0].widget);
  gtk_object_set_data_full (GTK_OBJECT (Ecran_1_), "Fichier",
                            menubar3_uiinfo[0].widget,
                            (GtkDestroyNotify) gtk_widget_unref);

  gtk_widget_set_name (Fichier_menu_uiinfo[0].widget, "encoder");
  gtk_widget_ref (Fichier_menu_uiinfo[0].widget);
  gtk_object_set_data_full (GTK_OBJECT (Ecran_1_), "encoder",
                            Fichier_menu_uiinfo[0].widget,
                            (GtkDestroyNotify) gtk_widget_unref);

  gtk_widget_set_name (Fichier_menu_uiinfo[1].widget, "decoder");
  gtk_widget_ref (Fichier_menu_uiinfo[1].widget);
  gtk_object_set_data_full (GTK_OBJECT (Ecran_1_), "decoder",
                            Fichier_menu_uiinfo[1].widget,
                            (GtkDestroyNotify) gtk_widget_unref);

  gtk_widget_set_name (Fichier_menu_uiinfo[2].widget, "s_parateur3");
  gtk_widget_ref (Fichier_menu_uiinfo[2].widget);
  gtk_object_set_data_full (GTK_OBJECT (Ecran_1_), "s_parateur3",
                            Fichier_menu_uiinfo[2].widget,
                            (GtkDestroyNotify) gtk_widget_unref);

  gtk_widget_set_name (Fichier_menu_uiinfo[3].widget, "quitter");
  gtk_widget_ref (Fichier_menu_uiinfo[3].widget);
  gtk_object_set_data_full (GTK_OBJECT (Ecran_1_), "quitter",
                            Fichier_menu_uiinfo[3].widget,
                            (GtkDestroyNotify) gtk_widget_unref);

  gtk_widget_set_name (menubar3_uiinfo[1].widget, "aide");
  gtk_widget_ref (menubar3_uiinfo[1].widget);
  gtk_object_set_data_full (GTK_OBJECT (Ecran_1_), "aide",
                            menubar3_uiinfo[1].widget,
                            (GtkDestroyNotify) gtk_widget_unref);

  gtk_widget_set_name (aide_menu_uiinfo[0].widget, "a_propos1");
  gtk_widget_ref (aide_menu_uiinfo[0].widget);
  gtk_object_set_data_full (GTK_OBJECT (Ecran_1_), "a_propos1",
                            aide_menu_uiinfo[0].widget,
                            (GtkDestroyNotify) gtk_widget_unref);

  vbox2 = gtk_vbox_new (FALSE, 0);
  gtk_widget_set_name (vbox2, "vbox2");
  gtk_widget_ref (vbox2);
  gtk_object_set_data_full (GTK_OBJECT (Ecran_1_), "vbox2", vbox2,
                            (GtkDestroyNotify) gtk_widget_unref);
  gtk_widget_show (vbox2);
  gtk_box_pack_start (GTK_BOX (vbox1), vbox2, TRUE, TRUE, 0);

  pixmap = create_pixmap (Ecran_1_, "datacod/datacod.xpm", FALSE);
  gtk_widget_set_name (pixmap, "pixmap");
  gtk_widget_ref (pixmap);
  gtk_object_set_data_full (GTK_OBJECT (Ecran_1_), "pixmap", pixmap,
                            (GtkDestroyNotify) gtk_widget_unref);
  gtk_widget_show (pixmap);
  gtk_box_pack_start (GTK_BOX (vbox2), pixmap, TRUE, TRUE, 0);
  gtk_widget_set_usize (pixmap, 427, 232);

  progressbar1 = gtk_progress_bar_new ();
  gtk_widget_set_name (progressbar1, "progressbar1");
  gtk_widget_ref (progressbar1);
  gtk_object_set_data_full (GTK_OBJECT (Ecran_1_), "progressbar1", progressbar1,
                            (GtkDestroyNotify) gtk_widget_unref);
  gtk_widget_show (progressbar1);
  gtk_box_pack_start (GTK_BOX (vbox2), progressbar1, FALSE, FALSE, 0);

  frame1 = gtk_frame_new (NULL);
  gtk_widget_set_name (frame1, "frame1");
  gtk_widget_ref (frame1);
  gtk_object_set_data_full (GTK_OBJECT (Ecran_1_), "frame1", frame1,
                            (GtkDestroyNotify) gtk_widget_unref);
  gtk_widget_show (frame1);
  gtk_box_pack_start (GTK_BOX (vbox1), frame1, FALSE, FALSE, 0);
  gtk_frame_set_shadow_type (GTK_FRAME (frame1), GTK_SHADOW_ETCHED_OUT);

  Etat = gtk_label_new (_("Copyright (c) 2000, 2001 - Philippe BOUSQUET                             "));
  gtk_widget_set_name (Etat, "Etat");
  gtk_widget_ref (Etat);
  gtk_object_set_data_full (GTK_OBJECT (Ecran_1_), "Etat", Etat,
                            (GtkDestroyNotify) gtk_widget_unref);
  gtk_widget_show (Etat);
  gtk_container_add (GTK_CONTAINER (frame1), Etat);
  gtk_label_set_justify (GTK_LABEL (Etat), GTK_JUSTIFY_LEFT);

  gtk_signal_connect (GTK_OBJECT (Ecran_1_), "destroy",
                      GTK_SIGNAL_FUNC (on_Ecran_1__destroy),
                      NULL);

  return Ecran_1_;
}

GtkWidget*
create_fileselection1 (void)
{
  GtkWidget *fileselection1;
  GtkWidget *ok_button3;
  GtkWidget *cancel_button3;

  fileselection1 = gtk_file_selection_new (_("Fichiers *.*"));
  gtk_widget_set_name (fileselection1, "fileselection1");
  gtk_object_set_data (GTK_OBJECT (fileselection1), "fileselection1", fileselection1);
  gtk_container_set_border_width (GTK_CONTAINER (fileselection1), 10);
  GTK_WINDOW (fileselection1)->type = GTK_WINDOW_DIALOG;
  gtk_window_set_position (GTK_WINDOW (fileselection1), GTK_WIN_POS_CENTER);
  gtk_window_set_modal (GTK_WINDOW (fileselection1), TRUE);
  gtk_window_set_policy (GTK_WINDOW (fileselection1), TRUE, FALSE, FALSE);
  gtk_file_selection_hide_fileop_buttons (GTK_FILE_SELECTION (fileselection1));

  ok_button3 = GTK_FILE_SELECTION (fileselection1)->ok_button;
  gtk_widget_set_name (ok_button3, "ok_button3");
  gtk_object_set_data (GTK_OBJECT (fileselection1), "ok_button3", ok_button3);
  gtk_widget_show (ok_button3);
  GTK_WIDGET_SET_FLAGS (ok_button3, GTK_CAN_DEFAULT);

  cancel_button3 = GTK_FILE_SELECTION (fileselection1)->cancel_button;
  gtk_widget_set_name (cancel_button3, "cancel_button3");
  gtk_object_set_data (GTK_OBJECT (fileselection1), "cancel_button3", cancel_button3);
  gtk_widget_show (cancel_button3);
  GTK_WIDGET_SET_FLAGS (cancel_button3, GTK_CAN_DEFAULT);

  gtk_signal_connect (GTK_OBJECT (fileselection1), "destroy",
                      GTK_SIGNAL_FUNC (on_fileselection1_destroy),
                      NULL);
  gtk_signal_connect (GTK_OBJECT (ok_button3), "clicked",
                      GTK_SIGNAL_FUNC (on_ok_button3_clicked),
                      NULL);
  gtk_signal_connect (GTK_OBJECT (cancel_button3), "clicked",
                      GTK_SIGNAL_FUNC (on_cancel_button3_clicked),
                      NULL);

  gtk_widget_grab_focus (ok_button3);
  return fileselection1;
}

GtkWidget*
create_fileselection2 (void)
{
  GtkWidget *fileselection2;
  GtkWidget *ok_button4;
  GtkWidget *cancel_button4;

  fileselection2 = gtk_file_selection_new (_("Fichiers codés (*.DCD)"));
  gtk_widget_set_name (fileselection2, "fileselection2");
  gtk_object_set_data (GTK_OBJECT (fileselection2), "fileselection2", fileselection2);
  gtk_container_set_border_width (GTK_CONTAINER (fileselection2), 10);
  GTK_WINDOW (fileselection2)->type = GTK_WINDOW_DIALOG;
  gtk_window_set_position (GTK_WINDOW (fileselection2), GTK_WIN_POS_CENTER);
  gtk_window_set_modal (GTK_WINDOW (fileselection2), TRUE);
  gtk_window_set_policy (GTK_WINDOW (fileselection2), TRUE, FALSE, FALSE);
  gtk_window_set_wmclass (GTK_WINDOW (fileselection2), "", "*.DCD");
  gtk_file_selection_hide_fileop_buttons (GTK_FILE_SELECTION (fileselection2));

  ok_button4 = GTK_FILE_SELECTION (fileselection2)->ok_button;
  gtk_widget_set_name (ok_button4, "ok_button4");
  gtk_object_set_data (GTK_OBJECT (fileselection2), "ok_button4", ok_button4);
  gtk_widget_show (ok_button4);
  GTK_WIDGET_SET_FLAGS (ok_button4, GTK_CAN_DEFAULT);

  cancel_button4 = GTK_FILE_SELECTION (fileselection2)->cancel_button;
  gtk_widget_set_name (cancel_button4, "cancel_button4");
  gtk_object_set_data (GTK_OBJECT (fileselection2), "cancel_button4", cancel_button4);
  gtk_widget_show (cancel_button4);
  GTK_WIDGET_SET_FLAGS (cancel_button4, GTK_CAN_DEFAULT);

  gtk_signal_connect (GTK_OBJECT (fileselection2), "destroy",
                      GTK_SIGNAL_FUNC (on_fileselection2_destroy),
                      NULL);
  gtk_signal_connect (GTK_OBJECT (ok_button4), "clicked",
                      GTK_SIGNAL_FUNC (on_ok_button4_clicked),
                      NULL);
  gtk_signal_connect (GTK_OBJECT (cancel_button4), "clicked",
                      GTK_SIGNAL_FUNC (on_cancel_button4_clicked),
                      NULL);

  gtk_widget_grab_focus (ok_button4);
  return fileselection2;
}

GtkWidget*
create_Mot_de_passe (void)
{
  GtkWidget *Mot_de_passe;
  GtkWidget *frame2;
  GtkWidget *vbox6;
  GtkWidget *hbox9;
  GtkWidget *Champ_1;
  GtkWidget *fleche;
  GtkWidget *Champ_2;
  GtkWidget *frame4;
  GtkWidget *hbox16;
  GtkWidget *label15;
  GtkWidget *fixed3;
  GtkWidget *hbox17;
  GtkWidget *label16;
  GtkWidget *fixed4;
  GtkWidget *hbox11;
  GtkWidget *hbox12;
  GtkWidget *Passe;
  GtkWidget *fixed1;
  GtkWidget *label13;
  GtkWidget *hbox13;
  GtkWidget *cle;
  GtkWidget *fixed2;
  GtkWidget *label14;
  GtkWidget *frame3;
  GtkWidget *hbox15;
  GtkWidget *OK_BT;
  GtkWidget *Annu_BT;
  GtkTooltips *tooltips;

  tooltips = gtk_tooltips_new ();

  Mot_de_passe = gtk_window_new (GTK_WINDOW_DIALOG);
  gtk_widget_set_name (Mot_de_passe, "Mot_de_passe");
  gtk_object_set_data (GTK_OBJECT (Mot_de_passe), "Mot_de_passe", Mot_de_passe);
  gtk_window_set_title (GTK_WINDOW (Mot_de_passe), _("Mot de passe"));
  gtk_window_set_position (GTK_WINDOW (Mot_de_passe), GTK_WIN_POS_CENTER);
  gtk_window_set_modal (GTK_WINDOW (Mot_de_passe), TRUE);
  gtk_window_set_policy (GTK_WINDOW (Mot_de_passe), TRUE, FALSE, FALSE);

  frame2 = gtk_frame_new (NULL);
  gtk_widget_set_name (frame2, "frame2");
  gtk_widget_ref (frame2);
  gtk_object_set_data_full (GTK_OBJECT (Mot_de_passe), "frame2", frame2,
                            (GtkDestroyNotify) gtk_widget_unref);
  gtk_widget_show (frame2);
  gtk_container_add (GTK_CONTAINER (Mot_de_passe), frame2);
  gtk_container_set_border_width (GTK_CONTAINER (frame2), 7);
  gtk_frame_set_shadow_type (GTK_FRAME (frame2), GTK_SHADOW_NONE);

  vbox6 = gtk_vbox_new (FALSE, 0);
  gtk_widget_set_name (vbox6, "vbox6");
  gtk_widget_ref (vbox6);
  gtk_object_set_data_full (GTK_OBJECT (Mot_de_passe), "vbox6", vbox6,
                            (GtkDestroyNotify) gtk_widget_unref);
  gtk_widget_show (vbox6);
  gtk_container_add (GTK_CONTAINER (frame2), vbox6);

  hbox9 = gtk_hbox_new (FALSE, 0);
  gtk_widget_set_name (hbox9, "hbox9");
  gtk_widget_ref (hbox9);
  gtk_object_set_data_full (GTK_OBJECT (Mot_de_passe), "hbox9", hbox9,
                            (GtkDestroyNotify) gtk_widget_unref);
  gtk_widget_show (hbox9);
  gtk_box_pack_start (GTK_BOX (vbox6), hbox9, TRUE, TRUE, 0);

  Champ_1 = gtk_entry_new ();
  gtk_widget_set_name (Champ_1, "Champ_1");
  gtk_widget_ref (Champ_1);
  gtk_object_set_data_full (GTK_OBJECT (Mot_de_passe), "Champ_1", Champ_1,
                            (GtkDestroyNotify) gtk_widget_unref);
  gtk_widget_show (Champ_1);
  gtk_box_pack_start (GTK_BOX (hbox9), Champ_1, TRUE, TRUE, 0);
  gtk_entry_set_editable (GTK_ENTRY (Champ_1), FALSE);

  fleche = gtk_label_new (_(" >>> "));
  gtk_widget_set_name (fleche, "fleche");
  gtk_widget_ref (fleche);
  gtk_object_set_data_full (GTK_OBJECT (Mot_de_passe), "fleche", fleche,
                            (GtkDestroyNotify) gtk_widget_unref);
  gtk_widget_show (fleche);
  gtk_box_pack_start (GTK_BOX (hbox9), fleche, FALSE, FALSE, 0);

  Champ_2 = gtk_entry_new ();
  gtk_widget_set_name (Champ_2, "Champ_2");
  gtk_widget_ref (Champ_2);
  gtk_object_set_data_full (GTK_OBJECT (Mot_de_passe), "Champ_2", Champ_2,
                            (GtkDestroyNotify) gtk_widget_unref);
  gtk_widget_show (Champ_2);
  gtk_box_pack_start (GTK_BOX (hbox9), Champ_2, TRUE, TRUE, 0);
  gtk_entry_set_editable (GTK_ENTRY (Champ_2), FALSE);

  frame4 = gtk_frame_new (NULL);
  gtk_widget_set_name (frame4, "frame4");
  gtk_widget_ref (frame4);
  gtk_object_set_data_full (GTK_OBJECT (Mot_de_passe), "frame4", frame4,
                            (GtkDestroyNotify) gtk_widget_unref);
  gtk_widget_show (frame4);
  gtk_box_pack_start (GTK_BOX (vbox6), frame4, TRUE, TRUE, 0);
  gtk_widget_set_usize (frame4, -2, 40);
  gtk_container_set_border_width (GTK_CONTAINER (frame4), 2);
  gtk_frame_set_shadow_type (GTK_FRAME (frame4), GTK_SHADOW_NONE);

  hbox16 = gtk_hbox_new (FALSE, 0);
  gtk_widget_set_name (hbox16, "hbox16");
  gtk_widget_ref (hbox16);
  gtk_object_set_data_full (GTK_OBJECT (Mot_de_passe), "hbox16", hbox16,
                            (GtkDestroyNotify) gtk_widget_unref);
  gtk_widget_show (hbox16);
  gtk_container_add (GTK_CONTAINER (frame4), hbox16);

  label15 = gtk_label_new (_("Mot de passe : "));
  gtk_widget_set_name (label15, "label15");
  gtk_widget_ref (label15);
  gtk_object_set_data_full (GTK_OBJECT (Mot_de_passe), "label15", label15,
                            (GtkDestroyNotify) gtk_widget_unref);
  gtk_widget_show (label15);
  gtk_box_pack_start (GTK_BOX (hbox16), label15, FALSE, FALSE, 0);
  gtk_label_set_justify (GTK_LABEL (label15), GTK_JUSTIFY_LEFT);

  fixed3 = gtk_fixed_new ();
  gtk_widget_set_name (fixed3, "fixed3");
  gtk_widget_ref (fixed3);
  gtk_object_set_data_full (GTK_OBJECT (Mot_de_passe), "fixed3", fixed3,
                            (GtkDestroyNotify) gtk_widget_unref);
  gtk_widget_show (fixed3);
  gtk_box_pack_start (GTK_BOX (hbox16), fixed3, TRUE, TRUE, 0);

  hbox17 = gtk_hbox_new (FALSE, 0);
  gtk_widget_set_name (hbox17, "hbox17");
  gtk_widget_ref (hbox17);
  gtk_object_set_data_full (GTK_OBJECT (Mot_de_passe), "hbox17", hbox17,
                            (GtkDestroyNotify) gtk_widget_unref);
  gtk_widget_show (hbox17);
  gtk_box_pack_start (GTK_BOX (hbox16), hbox17, FALSE, FALSE, 0);

  label16 = gtk_label_new (_("Clé : "));
  gtk_widget_set_name (label16, "label16");
  gtk_widget_ref (label16);
  gtk_object_set_data_full (GTK_OBJECT (Mot_de_passe), "label16", label16,
                            (GtkDestroyNotify) gtk_widget_unref);
  gtk_widget_show (label16);
  gtk_box_pack_start (GTK_BOX (hbox17), label16, FALSE, FALSE, 0);
  gtk_widget_set_usize (label16, 26, -2);
  gtk_label_set_justify (GTK_LABEL (label16), GTK_JUSTIFY_LEFT);

  fixed4 = gtk_fixed_new ();
  gtk_widget_set_name (fixed4, "fixed4");
  gtk_widget_ref (fixed4);
  gtk_object_set_data_full (GTK_OBJECT (Mot_de_passe), "fixed4", fixed4,
                            (GtkDestroyNotify) gtk_widget_unref);
  gtk_widget_show (fixed4);
  gtk_box_pack_start (GTK_BOX (hbox17), fixed4, TRUE, TRUE, 0);
  gtk_widget_set_usize (fixed4, 128, -2);

  hbox11 = gtk_hbox_new (FALSE, 0);
  gtk_widget_set_name (hbox11, "hbox11");
  gtk_widget_ref (hbox11);
  gtk_object_set_data_full (GTK_OBJECT (Mot_de_passe), "hbox11", hbox11,
                            (GtkDestroyNotify) gtk_widget_unref);
  gtk_widget_show (hbox11);
  gtk_box_pack_start (GTK_BOX (vbox6), hbox11, TRUE, TRUE, 0);

  hbox12 = gtk_hbox_new (FALSE, 0);
  gtk_widget_set_name (hbox12, "hbox12");
  gtk_widget_ref (hbox12);
  gtk_object_set_data_full (GTK_OBJECT (Mot_de_passe), "hbox12", hbox12,
                            (GtkDestroyNotify) gtk_widget_unref);
  gtk_widget_show (hbox12);
  gtk_box_pack_start (GTK_BOX (hbox11), hbox12, TRUE, TRUE, 0);

  Passe = gtk_entry_new_with_max_length (4);
  gtk_widget_set_name (Passe, "Passe");
  gtk_widget_ref (Passe);
  gtk_object_set_data_full (GTK_OBJECT (Mot_de_passe), "Passe", Passe,
                            (GtkDestroyNotify) gtk_widget_unref);
  gtk_widget_show (Passe);
  gtk_box_pack_start (GTK_BOX (hbox12), Passe, TRUE, TRUE, 0);
  gtk_widget_set_usize (Passe, 80, -2);
  gtk_tooltips_set_tip (tooltips, Passe, _("4 caractères"), NULL);

  fixed1 = gtk_fixed_new ();
  gtk_widget_set_name (fixed1, "fixed1");
  gtk_widget_ref (fixed1);
  gtk_object_set_data_full (GTK_OBJECT (Mot_de_passe), "fixed1", fixed1,
                            (GtkDestroyNotify) gtk_widget_unref);
  gtk_widget_show (fixed1);
  gtk_box_pack_start (GTK_BOX (hbox12), fixed1, TRUE, TRUE, 0);
  gtk_widget_set_usize (fixed1, 102, -2);

  label13 = gtk_label_new ("");
  gtk_widget_set_name (label13, "label13");
  gtk_widget_ref (label13);
  gtk_object_set_data_full (GTK_OBJECT (Mot_de_passe), "label13", label13,
                            (GtkDestroyNotify) gtk_widget_unref);
  gtk_widget_show (label13);
  gtk_box_pack_start (GTK_BOX (hbox11), label13, FALSE, FALSE, 0);

  hbox13 = gtk_hbox_new (FALSE, 0);
  gtk_widget_set_name (hbox13, "hbox13");
  gtk_widget_ref (hbox13);
  gtk_object_set_data_full (GTK_OBJECT (Mot_de_passe), "hbox13", hbox13,
                            (GtkDestroyNotify) gtk_widget_unref);
  gtk_widget_show (hbox13);
  gtk_box_pack_start (GTK_BOX (hbox11), hbox13, TRUE, TRUE, 0);

  cle = gtk_entry_new_with_max_length (1);
  gtk_widget_set_name (cle, "cle");
  gtk_widget_ref (cle);
  gtk_object_set_data_full (GTK_OBJECT (Mot_de_passe), "cle", cle,
                            (GtkDestroyNotify) gtk_widget_unref);
  gtk_widget_show (cle);
  gtk_box_pack_start (GTK_BOX (hbox13), cle, TRUE, TRUE, 0);
  gtk_widget_set_usize (cle, 40, -2);
  gtk_tooltips_set_tip (tooltips, cle, _("1 caractère"), NULL);

  fixed2 = gtk_fixed_new ();
  gtk_widget_set_name (fixed2, "fixed2");
  gtk_widget_ref (fixed2);
  gtk_object_set_data_full (GTK_OBJECT (Mot_de_passe), "fixed2", fixed2,
                            (GtkDestroyNotify) gtk_widget_unref);
  gtk_widget_show (fixed2);
  gtk_box_pack_start (GTK_BOX (hbox13), fixed2, TRUE, TRUE, 0);
  gtk_widget_set_usize (fixed2, 110, -2);

  label14 = gtk_label_new ("");
  gtk_widget_set_name (label14, "label14");
  gtk_widget_ref (label14);
  gtk_object_set_data_full (GTK_OBJECT (Mot_de_passe), "label14", label14,
                            (GtkDestroyNotify) gtk_widget_unref);
  gtk_widget_show (label14);
  gtk_box_pack_start (GTK_BOX (hbox11), label14, FALSE, FALSE, 0);

  frame3 = gtk_frame_new (NULL);
  gtk_widget_set_name (frame3, "frame3");
  gtk_widget_ref (frame3);
  gtk_object_set_data_full (GTK_OBJECT (Mot_de_passe), "frame3", frame3,
                            (GtkDestroyNotify) gtk_widget_unref);
  gtk_widget_show (frame3);
  gtk_box_pack_start (GTK_BOX (vbox6), frame3, TRUE, TRUE, 0);
  gtk_frame_set_shadow_type (GTK_FRAME (frame3), GTK_SHADOW_NONE);

  hbox15 = gtk_hbox_new (TRUE, 2);
  gtk_widget_set_name (hbox15, "hbox15");
  gtk_widget_ref (hbox15);
  gtk_object_set_data_full (GTK_OBJECT (Mot_de_passe), "hbox15", hbox15,
                            (GtkDestroyNotify) gtk_widget_unref);
  gtk_widget_show (hbox15);
  gtk_container_add (GTK_CONTAINER (frame3), hbox15);
  gtk_container_set_border_width (GTK_CONTAINER (hbox15), 13);

  OK_BT = gnome_stock_button (GNOME_STOCK_BUTTON_OK);
  gtk_widget_set_name (OK_BT, "OK_BT");
  gtk_widget_ref (OK_BT);
  gtk_object_set_data_full (GTK_OBJECT (Mot_de_passe), "OK_BT", OK_BT,
                            (GtkDestroyNotify) gtk_widget_unref);
  gtk_widget_show (OK_BT);
  gtk_box_pack_start (GTK_BOX (hbox15), OK_BT, FALSE, FALSE, 0);

  Annu_BT = gnome_stock_button (GNOME_STOCK_BUTTON_CANCEL);
  gtk_widget_set_name (Annu_BT, "Annu_BT");
  gtk_widget_ref (Annu_BT);
  gtk_object_set_data_full (GTK_OBJECT (Mot_de_passe), "Annu_BT", Annu_BT,
                            (GtkDestroyNotify) gtk_widget_unref);
  gtk_widget_show (Annu_BT);
  gtk_box_pack_start (GTK_BOX (hbox15), Annu_BT, FALSE, FALSE, 0);

  gtk_signal_connect (GTK_OBJECT (Mot_de_passe), "destroy",
                      GTK_SIGNAL_FUNC (on_Mot_de_passe_destroy),
                      NULL);
  gtk_signal_connect (GTK_OBJECT (OK_BT), "clicked",
                      GTK_SIGNAL_FUNC (on_OK_BT_clicked),
                      NULL);
  gtk_signal_connect (GTK_OBJECT (Annu_BT), "clicked",
                      GTK_SIGNAL_FUNC (on_Annu_BT_clicked),
                      NULL);

  gtk_widget_grab_focus (OK_BT);
  gtk_object_set_data (GTK_OBJECT (Mot_de_passe), "tooltips", tooltips);

  return Mot_de_passe;
}

GtkWidget*
create_Erreur (void)
{
  GtkWidget *Erreur;
  GtkWidget *dialog_vbox3;
  GtkWidget *hbox24;
  GtkWidget *frame12;
  GtkWidget *pixmap2;
  GtkWidget *L_Erreur;
  GtkWidget *dialog_action_area3;
  GtkWidget *button9;

  Erreur = gtk_dialog_new ();
  gtk_widget_set_name (Erreur, "Erreur");
  gtk_object_set_data (GTK_OBJECT (Erreur), "Erreur", Erreur);
  GTK_WIDGET_SET_FLAGS (Erreur, GTK_CAN_FOCUS);
  gtk_window_set_title (GTK_WINDOW (Erreur), _("Erreur"));
  GTK_WINDOW (Erreur)->type = GTK_WINDOW_DIALOG;
  gtk_window_set_position (GTK_WINDOW (Erreur), GTK_WIN_POS_CENTER);
  gtk_window_set_modal (GTK_WINDOW (Erreur), TRUE);
  gtk_window_set_policy (GTK_WINDOW (Erreur), TRUE, TRUE, FALSE);

  dialog_vbox3 = GTK_DIALOG (Erreur)->vbox;
  gtk_widget_set_name (dialog_vbox3, "dialog_vbox3");
  gtk_object_set_data (GTK_OBJECT (Erreur), "dialog_vbox3", dialog_vbox3);
  gtk_widget_show (dialog_vbox3);

  hbox24 = gtk_hbox_new (FALSE, 0);
  gtk_widget_set_name (hbox24, "hbox24");
  gtk_widget_ref (hbox24);
  gtk_object_set_data_full (GTK_OBJECT (Erreur), "hbox24", hbox24,
                            (GtkDestroyNotify) gtk_widget_unref);
  gtk_widget_show (hbox24);
  gtk_box_pack_start (GTK_BOX (dialog_vbox3), hbox24, TRUE, TRUE, 0);

  frame12 = gtk_frame_new (NULL);
  gtk_widget_set_name (frame12, "frame12");
  gtk_widget_ref (frame12);
  gtk_object_set_data_full (GTK_OBJECT (Erreur), "frame12", frame12,
                            (GtkDestroyNotify) gtk_widget_unref);
  gtk_widget_show (frame12);
  gtk_box_pack_start (GTK_BOX (hbox24), frame12, FALSE, FALSE, 0);
  gtk_widget_set_usize (frame12, 83, -2);
  gtk_container_set_border_width (GTK_CONTAINER (frame12), 10);

  pixmap2 = create_pixmap (Erreur, "datacod/interdit_2.xpm", FALSE);
  gtk_widget_set_name (pixmap2, "pixmap2");
  gtk_widget_ref (pixmap2);
  gtk_object_set_data_full (GTK_OBJECT (Erreur), "pixmap2", pixmap2,
                            (GtkDestroyNotify) gtk_widget_unref);
  gtk_widget_show (pixmap2);
  gtk_container_add (GTK_CONTAINER (frame12), pixmap2);

  L_Erreur = gtk_label_new (_("Erreur"));
  gtk_widget_set_name (L_Erreur, "L_Erreur");
  gtk_widget_ref (L_Erreur);
  gtk_object_set_data_full (GTK_OBJECT (Erreur), "L_Erreur", L_Erreur,
                            (GtkDestroyNotify) gtk_widget_unref);
  gtk_widget_show (L_Erreur);
  gtk_box_pack_start (GTK_BOX (hbox24), L_Erreur, FALSE, FALSE, 0);
  GTK_WIDGET_SET_FLAGS (L_Erreur, GTK_CAN_FOCUS);

  dialog_action_area3 = GTK_DIALOG (Erreur)->action_area;
  gtk_widget_set_name (dialog_action_area3, "dialog_action_area3");
  gtk_object_set_data (GTK_OBJECT (Erreur), "dialog_action_area3", dialog_action_area3);
  gtk_widget_show (dialog_action_area3);
  gtk_container_set_border_width (GTK_CONTAINER (dialog_action_area3), 10);

  button9 = gnome_stock_button (GNOME_STOCK_BUTTON_OK);
  gtk_widget_set_name (button9, "button9");
  gtk_widget_ref (button9);
  gtk_object_set_data_full (GTK_OBJECT (Erreur), "button9", button9,
                            (GtkDestroyNotify) gtk_widget_unref);
  gtk_widget_show (button9);
  gtk_box_pack_start (GTK_BOX (dialog_action_area3), button9, FALSE, FALSE, 0);

  gtk_signal_connect (GTK_OBJECT (Erreur), "destroy",
                      GTK_SIGNAL_FUNC (on_Erreur_destroy),
                      NULL);
  gtk_signal_connect (GTK_OBJECT (button9), "clicked",
                      GTK_SIGNAL_FUNC (on_button9_clicked),
                      NULL);

  gtk_widget_grab_focus (button9);
  return Erreur;
}

GtkWidget*
create_Information (void)
{
  GtkWidget *Information;
  GtkWidget *vbox13;
  GtkWidget *hbox25;
  GtkWidget *frame13;
  GtkWidget *Info_2;
  GtkWidget *L_Info;
  GtkWidget *hbox26;
  GtkWidget *button10;

  Information = gtk_dialog_new ();
  gtk_widget_set_name (Information, "Information");
  gtk_object_set_data (GTK_OBJECT (Information), "Information", Information);
  GTK_WIDGET_SET_FLAGS (Information, GTK_CAN_FOCUS);
  gtk_window_set_title (GTK_WINDOW (Information), _("Information"));
  GTK_WINDOW (Information)->type = GTK_WINDOW_DIALOG;
  gtk_window_set_position (GTK_WINDOW (Information), GTK_WIN_POS_CENTER);
  gtk_window_set_modal (GTK_WINDOW (Information), TRUE);
  gtk_window_set_policy (GTK_WINDOW (Information), TRUE, TRUE, FALSE);

  vbox13 = GTK_DIALOG (Information)->vbox;
  gtk_widget_set_name (vbox13, "vbox13");
  gtk_object_set_data (GTK_OBJECT (Information), "vbox13", vbox13);
  gtk_widget_show (vbox13);

  hbox25 = gtk_hbox_new (FALSE, 0);
  gtk_widget_set_name (hbox25, "hbox25");
  gtk_widget_ref (hbox25);
  gtk_object_set_data_full (GTK_OBJECT (Information), "hbox25", hbox25,
                            (GtkDestroyNotify) gtk_widget_unref);
  gtk_widget_show (hbox25);
  gtk_box_pack_start (GTK_BOX (vbox13), hbox25, TRUE, TRUE, 0);

  frame13 = gtk_frame_new (NULL);
  gtk_widget_set_name (frame13, "frame13");
  gtk_widget_ref (frame13);
  gtk_object_set_data_full (GTK_OBJECT (Information), "frame13", frame13,
                            (GtkDestroyNotify) gtk_widget_unref);
  gtk_widget_show (frame13);
  gtk_box_pack_start (GTK_BOX (hbox25), frame13, FALSE, FALSE, 0);
  gtk_widget_set_usize (frame13, 83, -2);
  gtk_container_set_border_width (GTK_CONTAINER (frame13), 10);

  Info_2 = create_pixmap (Information, "datacod/info_2.xpm", FALSE);
  gtk_widget_set_name (Info_2, "Info_2");
  gtk_widget_ref (Info_2);
  gtk_object_set_data_full (GTK_OBJECT (Information), "Info_2", Info_2,
                            (GtkDestroyNotify) gtk_widget_unref);
  gtk_widget_show (Info_2);
  gtk_container_add (GTK_CONTAINER (frame13), Info_2);

  L_Info = gtk_label_new (_("Opération éffectuée.   "));
  gtk_widget_set_name (L_Info, "L_Info");
  gtk_widget_ref (L_Info);
  gtk_object_set_data_full (GTK_OBJECT (Information), "L_Info", L_Info,
                            (GtkDestroyNotify) gtk_widget_unref);
  gtk_widget_show (L_Info);
  gtk_box_pack_start (GTK_BOX (hbox25), L_Info, FALSE, FALSE, 0);

  hbox26 = GTK_DIALOG (Information)->action_area;
  gtk_widget_set_name (hbox26, "hbox26");
  gtk_object_set_data (GTK_OBJECT (Information), "hbox26", hbox26);
  gtk_widget_show (hbox26);
  gtk_container_set_border_width (GTK_CONTAINER (hbox26), 10);

  button10 = gnome_stock_button (GNOME_STOCK_BUTTON_OK);
  gtk_widget_set_name (button10, "button10");
  gtk_widget_ref (button10);
  gtk_object_set_data_full (GTK_OBJECT (Information), "button10", button10,
                            (GtkDestroyNotify) gtk_widget_unref);
  gtk_widget_show (button10);
  gtk_box_pack_start (GTK_BOX (hbox26), button10, FALSE, FALSE, 0);

  gtk_signal_connect (GTK_OBJECT (Information), "destroy",
                      GTK_SIGNAL_FUNC (on_Information_destroy),
                      NULL);
  gtk_signal_connect (GTK_OBJECT (button10), "clicked",
                      GTK_SIGNAL_FUNC (on_button10_clicked),
                      NULL);

  gtk_widget_grab_focus (button10);
  return Information;
}

GtkWidget*
create_Attention (void)
{
  GtkWidget *Attention;
  GtkWidget *vbox14;
  GtkWidget *hbox27;
  GtkWidget *frame14;
  GtkWidget *pixmap4;
  GtkWidget *L_Attention;
  GtkWidget *hbox28;
  GtkWidget *hbox29;
  GtkWidget *button14;
  GtkWidget *button15;

  Attention = gtk_dialog_new ();
  gtk_widget_set_name (Attention, "Attention");
  gtk_object_set_data (GTK_OBJECT (Attention), "Attention", Attention);
  GTK_WIDGET_SET_FLAGS (Attention, GTK_CAN_FOCUS);
  gtk_window_set_title (GTK_WINDOW (Attention), _("Attention"));
  GTK_WINDOW (Attention)->type = GTK_WINDOW_DIALOG;
  gtk_window_set_position (GTK_WINDOW (Attention), GTK_WIN_POS_CENTER);
  gtk_window_set_modal (GTK_WINDOW (Attention), TRUE);
  gtk_window_set_policy (GTK_WINDOW (Attention), TRUE, TRUE, FALSE);

  vbox14 = GTK_DIALOG (Attention)->vbox;
  gtk_widget_set_name (vbox14, "vbox14");
  gtk_object_set_data (GTK_OBJECT (Attention), "vbox14", vbox14);
  gtk_widget_show (vbox14);

  hbox27 = gtk_hbox_new (FALSE, 0);
  gtk_widget_set_name (hbox27, "hbox27");
  gtk_widget_ref (hbox27);
  gtk_object_set_data_full (GTK_OBJECT (Attention), "hbox27", hbox27,
                            (GtkDestroyNotify) gtk_widget_unref);
  gtk_widget_show (hbox27);
  gtk_box_pack_start (GTK_BOX (vbox14), hbox27, TRUE, TRUE, 0);

  frame14 = gtk_frame_new (NULL);
  gtk_widget_set_name (frame14, "frame14");
  gtk_widget_ref (frame14);
  gtk_object_set_data_full (GTK_OBJECT (Attention), "frame14", frame14,
                            (GtkDestroyNotify) gtk_widget_unref);
  gtk_widget_show (frame14);
  gtk_box_pack_start (GTK_BOX (hbox27), frame14, FALSE, FALSE, 0);
  gtk_widget_set_usize (frame14, 83, -2);
  gtk_container_set_border_width (GTK_CONTAINER (frame14), 10);

  pixmap4 = create_pixmap (Attention, "datacod/att_2.xpm", FALSE);
  gtk_widget_set_name (pixmap4, "pixmap4");
  gtk_widget_ref (pixmap4);
  gtk_object_set_data_full (GTK_OBJECT (Attention), "pixmap4", pixmap4,
                            (GtkDestroyNotify) gtk_widget_unref);
  gtk_widget_show (pixmap4);
  gtk_container_add (GTK_CONTAINER (frame14), pixmap4);

  L_Attention = gtk_label_new (_("Attention"));
  gtk_widget_set_name (L_Attention, "L_Attention");
  gtk_widget_ref (L_Attention);
  gtk_object_set_data_full (GTK_OBJECT (Attention), "L_Attention", L_Attention,
                            (GtkDestroyNotify) gtk_widget_unref);
  gtk_widget_show (L_Attention);
  gtk_box_pack_start (GTK_BOX (hbox27), L_Attention, FALSE, FALSE, 0);

  hbox28 = GTK_DIALOG (Attention)->action_area;
  gtk_widget_set_name (hbox28, "hbox28");
  gtk_object_set_data (GTK_OBJECT (Attention), "hbox28", hbox28);
  gtk_widget_show (hbox28);
  gtk_container_set_border_width (GTK_CONTAINER (hbox28), 10);

  hbox29 = gtk_hbox_new (FALSE, 0);
  gtk_widget_set_name (hbox29, "hbox29");
  gtk_widget_ref (hbox29);
  gtk_object_set_data_full (GTK_OBJECT (Attention), "hbox29", hbox29,
                            (GtkDestroyNotify) gtk_widget_unref);
  gtk_widget_show (hbox29);
  gtk_box_pack_start (GTK_BOX (hbox28), hbox29, FALSE, FALSE, 0);

  button14 = gnome_stock_button (GNOME_STOCK_BUTTON_OK);
  gtk_widget_set_name (button14, "button14");
  gtk_widget_ref (button14);
  gtk_object_set_data_full (GTK_OBJECT (Attention), "button14", button14,
                            (GtkDestroyNotify) gtk_widget_unref);
  gtk_widget_show (button14);
  gtk_box_pack_start (GTK_BOX (hbox29), button14, FALSE, FALSE, 0);

  button15 = gnome_stock_button (GNOME_STOCK_BUTTON_CANCEL);
  gtk_widget_set_name (button15, "button15");
  gtk_widget_ref (button15);
  gtk_object_set_data_full (GTK_OBJECT (Attention), "button15", button15,
                            (GtkDestroyNotify) gtk_widget_unref);
  gtk_widget_show (button15);
  gtk_box_pack_start (GTK_BOX (hbox28), button15, FALSE, FALSE, 0);

  gtk_signal_connect (GTK_OBJECT (Attention), "destroy",
                      GTK_SIGNAL_FUNC (on_Attention_destroy),
                      NULL);
  gtk_signal_connect (GTK_OBJECT (button14), "clicked",
                      GTK_SIGNAL_FUNC (on_button14_clicked),
                      NULL);
  gtk_signal_connect (GTK_OBJECT (button15), "clicked",
                      GTK_SIGNAL_FUNC (on_button15_clicked),
                      NULL);

  gtk_widget_grab_focus (button14);
  return Attention;
}

GtkWidget*
create_about1 (void)
{
  const gchar *authors[] = {
    "Thierry BOUSQUET",
    "Philippe BOUSQUET",
    NULL
  };
  GtkWidget *about1;

  about1 = gnome_about_new ("DataCod", VERSION,
                        _("Copiright (c) 2000,2001-Philippe BOUSQUET"),
                        authors,
                        _("Ce Logiciel est distribué sous licence GNU GENERAL PUBLIC LICENCE"),
                        "datacod/datacod2.xpm");
  gtk_widget_set_name (about1, "about1");
  gtk_object_set_data (GTK_OBJECT (about1), "about1", about1);
  gtk_widget_set_usize (about1, -2, 0);
  gtk_window_set_modal (GTK_WINDOW (about1), TRUE);

  gtk_signal_connect (GTK_OBJECT (about1), "destroy",
                      GTK_SIGNAL_FUNC (on_about1_destroy),
                      NULL);

  return about1;
}

