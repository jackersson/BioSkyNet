#include "stdafx.h"
#include "bio_main_menu.hpp"

#include "bio_main_menu_utils.hpp"
#include "bio_resources.hpp"

namespace SmartBio
{
	namespace View
	{
		BioMainMenu::BioMainMenu() : wxMenuBar()
		{
			create();
		}

		BioMainMenu::~BioMainMenu(){}

		void BioMainMenu::create()
		{	
			Poco::SharedPtr<BioMainMenuResource> resource(new BioMainMenuResource());

			BioMainMenuUtils utils;
			
			wxMenu* fileMenu = new wxMenu;
			utils.appendChild(UIMainMenu::ID_EXIT, fileMenu,           wxITEM_NORMAL, *resource);
			utils.appendRoot (UIMainMenu::ID_FILE, *this, fileMenu,/* wxITEM_NORMAL,*/ *resource);

			wxMenu* viewMenu = new wxMenu;			
			utils.appendCheckItem(UIMainMenu::ID_TOOLBAR      , viewMenu, /*wxITEM_NORMAL,*/ *resource);
			utils.appendCheckItem(UIMainMenu::ID_SETTINGS     , viewMenu, /*wxITEM_NORMAL,*/ *resource);
			utils.appendCheckItem(UIMainMenu::ID_OUTPUT_WINDOW, viewMenu, /*wxITEM_NORMAL,*/ *resource);		
			utils.appendRoot(UIMainMenu::ID_VIEW, *this, viewMenu, /*wxITEM_NORMAL,*/ *resource);
			
			wxMenu* helpMenu = new wxMenu;
			utils.appendChild(UIMainMenu::ID_ABOUT, helpMenu, wxITEM_NORMAL, *resource);
			utils.appendRoot(UIMainMenu::ID_HELP, *this, helpMenu, /*wxITEM_NORMAL,*/ *resource);

		}



		

	}
}