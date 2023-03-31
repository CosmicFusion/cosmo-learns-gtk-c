// Libraries
#include <gtk/gtk.h> // GTK Library
#include <stdio.h> // C IO Library (Not needed)
#include <stdlib.h>

// Widget Variables
GtkWidget *window;
GtkWidget *btn_launchpad; 
GtkWidget *startscreen_toptext;
GtkWidget *startscreen_icon;
GtkWidget *startscreen_buttomtext;

// Main function
int main(int argc, char *argv[])
{
	GtkBuilder *builder; // GTK Builder variable
	gtk_init(&argc, &argv); // Start GTK

	builder = gtk_builder_new(); // Create GTK UI Builder
	gtk_builder_add_from_file(builder, "main.ui", NULL); // Load glade UI file

	// Assign the Variables
	window = GTK_WIDGET(gtk_builder_get_object(builder, "Window")); // Load Widget Window
	btn_launchpad = GTK_WIDGET(gtk_builder_get_object(builder, "btn_launchpad")); // Load Widget Button
	startscreen_toptext = GTK_WIDGET(gtk_builder_get_object(builder, "startscreen_toptext")); // Load Widget Text
	startscreen_icon = GTK_WIDGET(gtk_builder_get_object(builder, "startscreen_icon")); // Load Widget Image
	startscreen_buttomtext = GTK_WIDGET(gtk_builder_get_object(builder, "startscreen_buttomtext")); // Load Widget Text

	// Modify
	gtk_label_set_label(startscreen_toptext, "Hello");
	gtk_image_set_from_icon_name(startscreen_icon, "emote-love", 128 );
	gtk_label_set_label(startscreen_buttomtext, "Fuk U");

	// Essential for a GTK based program
	gtk_builder_connect_signals(builder, NULL); 
	g_object_unref(builder);
	
	gtk_widget_show_all(window); // Show window
	gtk_main(); // Run gtk program

	return 0;
}

// Function to make btn_launchpad launch discord
void on_btn_launchpad_pressed() {
	int btn_launchpad_command;
	btn_launchpad_command = system("discord & disown");
}

// Function to exit our app
void exit_app()
{
	gtk_main_quit(); // Command to quit a GTK program
}
