#include "stdafx.h"
#include "bio_main_menu_resource.hpp"

#include "bio_resources.hpp"

#include <stack>


namespace SmartBio
{
	namespace View
	{	
		
		BioMainMenuResource::BioMainMenuResource()
		{
			initialize();
		}

		BioMainMenuResource::~BioMainMenuResource()	{}
	
		void BioMainMenuResource::do_initialize()
		{			
			std::string mfile = "File";
			std::string mview = "View";
			std::string mhelp = "Help";

			std::string mexit = "Exit";
			std::string mexit_hotkey = "\tAlt + F4";
			std::string mexit_icon = "resources\\menu\\exit.png";

			std::string mtoolbar = "Toolbar";
			std::string msettings = "Settings";
			std::string mabout = "About";
			std::string moutput_window = "Output window";

			View::UInfoMenuItem file(mfile, "", "", "");
			View::UInfoMenuItem view(mview, "", "", "");
			View::UInfoMenuItem help(mhelp, "", "", "");
			View::UInfoMenuItem exit(mexit, "", mexit_icon, mexit_hotkey);

			View::UInfoMenuItem toolbar(mtoolbar, "", "", "");
			View::UInfoMenuItem settings(msettings, "", "", "");
			View::UInfoMenuItem about(mabout, "", "", "");
			View::UInfoMenuItem output_window(moutput_window, "", "", "");

			file.add(UIMainMenu::ID_EXIT, exit);
			view.add(UIMainMenu::ID_TOOLBAR, toolbar);
			view.add(UIMainMenu::ID_SETTINGS, settings);
			view.add(UIMainMenu::ID_OUTPUT_WINDOW, output_window);

			help.add(UIMainMenu::ID_ABOUT, about);

			insert(UIMainMenu::ID_FILE, file);
			insert(UIMainMenu::ID_VIEW, view);
			insert(UIMainMenu::ID_HELP, help);
		}

		bool BioMainMenuResource::find(int index, UInfoMenuItem& item) const
		{

			auto elem = info_.find(index);
			if (elem != info_.end())
			{
				item = elem->second;
				return true;
			}

			std::stack<std::pair<int, UInfoMenuItem>> stack;

			for (auto it = std::begin(info_); it != std::end(info_); ++it)
				stack.push(*it);

			while (!stack.empty())
			{
				std::pair<int, UInfoMenuItem> elem = stack.top();
				stack.pop();
				UInfoMenuItem menu_item = elem.second;

				if (menu_item.hasChildrens())
				{
					std::map<int, UInfoMenuItem> childrens = menu_item.childrens();
					auto elem = childrens.find(index);
					if (elem != childrens.end())
					{
						item = elem->second;
						return true;
					}
					else
					{
						for (auto it = begin(childrens); it != end(childrens); ++it)
							stack.push(*it);
					}
				}
			}
			return false;
		}
	}
}