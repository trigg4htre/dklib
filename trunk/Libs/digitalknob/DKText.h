// DKText.h

#pragma once
#ifndef DKTEXT_H
#define DKTEXT_H

#include "DKFont.h"

//////////////////////////////
class DKText : public DKObject
{
public:
	DKText(){};
	DKText(DKObject *parent, DKPoint pos, DKFont *font, DKString text);
	void Create(DKObject *parent, DKPoint pos, DKFont *font, DKString text);
	~DKText();
	
	void SetPosition(DKPoint pos);
	void SetSize(DKSize siz);

	void SetColor(DKColor rgba);
	DKString GetString();
	void SetString(DKString string);
	void Display();

	DKFont *m_font;
	int font_size;
	DKString string;
	GLfloat text_color[4];

	static DKObject* NewText(DKObject *parent, DKPoint pos, DKFont *font, DKString text);
};

#endif //DKTEXT_H