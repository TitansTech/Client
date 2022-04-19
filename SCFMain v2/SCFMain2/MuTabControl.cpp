// TabControl.cpp : main project file.

#include "stdafx.h"
#include "iostream"
#include "windows.h"
#include "MuTabControl.h"

using namespace std;
using namespace SCFMain2;

static value class refGlobal
{
public:
	static MuTabControl ^form = gcnew MuTabControl();
};
refGlobal tControl;

// Use an other thread for show like a Dialog (making that you can see the mouse pointer ^^)
void MuTabControl__Tread(void * lpParam)
{
	//tControl.form->MarryInfo("Liho",2000);
	refGlobal::form->ShowDialog();
}
void Show()
{	
	_beginthread( MuTabControl__Tread, 0, NULL  );
	//refGlobal::form->MarryInfo("Liho",2000);
    //refGlobal::form->Show();
}
void Pirulin()
{	
	refGlobal::form->MarryInfo("aca",5000);
}
void Pirulin2()
{	
	refGlobal::form->MarryInfo("eeee",5000);
}