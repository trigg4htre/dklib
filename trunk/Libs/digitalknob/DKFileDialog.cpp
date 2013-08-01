#include "DKFileDialog.h"

/////////////////////////////////////////////////////////
DKFileDialog::DKFileDialog(DKObject *parent, int eventID)
{
	Create(parent, eventID);
}

////////////////////////////////////////////////////////
void DKFileDialog::Create(DKObject *parent, int eventID)
{
	name = "DKFileDialog";
	par = parent;
	frame = par->frame;

	thiswin = (DKWindow*)DKWindow::NewWindow(parent, "Select a file", DKPoint(parent->size.x/2-205,parent->size.y/2-160), DKSize(460,320), SDL_WINDOW_OPENGL|SDL_WINDOW_SHOWN|SDL_WINDOW_RESIZABLE);
	thiswin->SetColor(DKColor(0.5f,0.5f,0.5f,1));
	win = thiswin->win;

	SetColor(DKColor(0.5f,0.5f,0.5f,1));

	font = (DKFont*)DKFont::NewFont(this);

	path_string = (DKText*)DKText::NewText(this, DKPoint(10,10), font, "");

	drives_panel = (DKPanel*)DKPanel::NewPanel(this, DKPoint(10,30), DKSize(150,250));
	drives_panel->SetColor(DKColor(1,1,1,1));

	//drives_list.Create(drives_panel, DKPoint(0,0), DKSize(150,250), &font);

	DKStringArray drives;
	DKFile::GetDrives(drives);
	drives_list->AddSelections(drives);

	files_panel = (DKScrollPanel*)DKScrollPanel::NewScrollPanel(this, DKPoint(170, 30), DKSize(280,250));
	files_panel->SetColor(DKColor(1,1,1,1));

	//files_list.Create(files_panel, DKPoint(0,0), DKSize(280,250), &font);


	ok = (DKTextButton*)DKTextButton::NewTextButton(this, DKPoint(380,290), font, "OK",1);
}

////////////////////////////////////////////////////////////////////
DKObject* DKFileDialog::NewFileDialog(DKObject *parent, int eventID)
{
	objects.push_back(new DKFileDialog(parent, eventID));
    return objects[objects.size() - 1];
}

//////////////////////////////////////////////////
void DKFileDialog::OnWindowClose(SDL_Event* event)
{
	//If we closed this window or the main windows, delete this
	if(event->window.windowID == 1 || SDL_GetWindowID(win) == event->window.windowID){
		delete this;
	}
}

////////////////////////////////////////////
void DKFileDialog::OnListBox(DKEvent* event)
{
	if(event->id == 1){
		selected_drive = drives_list->selections[drives_list->current_selection-1]->text->string; //TODO - make a funtion for this.
		full_path = selected_drive;
		UpdateFilesPanel(full_path);
	}
	if(event->id == 2){
		DKString folder = files_list->selections[files_list->current_selection-1]->text->string;
		
		if(folder.compare("..") == 0){
			string::size_type pos = full_path.find_last_of("\\");
			full_path.resize(pos);
		}
		else{
			full_path = full_path + "\\" + folder;
		}
		UpdateFilesPanel(full_path);
	}

	path_string->SetString(full_path);
}

///////////////////////////////////////////////
void DKFileDialog::OnTextButton(DKEvent *event)
{
	if(event->id == 1){
		OnFileDialog(m_arg, this);
		delete this;
	}
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////
void DKFileDialog::LinkFileDialogEvent(void (*FileDialogEvent)(void*, DKEvent* event), void* arg, int id)
{
	OnFileDialog = FileDialogEvent;
	m_arg = arg;
	this->id = id;
}

//////////////////////////////////////////////////
void DKFileDialog::UpdateFilesPanel(DKString path)
{
	DKStringArray directories;
	DKStringArray files;
	DKFile::GetDirectories(path, directories);
	DKFile::GetFiles(path, files);
	files_list->ClearSelections();
	files_list->AddSelections(directories);
	files_list->AddSelections(files);
}