//// DKFileDialog.h ////

#pragma once
#ifndef DKFileDialog_H
#define DKFileDialog_H

#include "DKWindow.h"
#include "DKScrollPanel.h"
#include "DKFont.h"
#include "DKText.h"
#include "DKListBox.h"
#include "DKFile.h"


/////////////////////////////////////
class DKFileDialog : public DKWindow
{
public:
	DKFileDialog(){};
	DKFileDialog(DKObject *parent, int eventID);
	void Create(DKObject *parent, int eventID);
	~DKFileDialog(){};

	void OnWindowClose(SDL_Event* event);
	void OnListBox(DKEvent* event);
	void OnTextButton(DKEvent *event);

	//event info
	void LinkFileDialogEvent(void (*FileDialogEvent)(void*, DKEvent*), void* arg, int id);
	void (*OnFileDialog)(void*, DKEvent*);
	void* m_arg;

	void UpdateFilesPanel(DKString path);

	DKWindow* thiswin;

	DKString selected_drive;
	DKString full_path;

	DKFont* font;
	DKText* path_string;
	DKPanel* drives_panel;
	DKListBox* drives_list;
	DKScrollPanel* files_panel;
	DKListBox* files_list;

	DKTextButton* ok;

	static DKObject* NewFileDialog(DKObject *parent, int eventID);
};

#endif //DKFileDialog_H