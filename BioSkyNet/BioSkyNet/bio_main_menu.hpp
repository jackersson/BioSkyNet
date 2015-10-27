#ifndef Bio_MainMenu_INCLUDED
#define Bio_MainMenu_INCLUDED

//#include "bio_main_menu_resource.hpp"

namespace SmartBio
{
	namespace View
	{

		class BioMainMenu : public wxMenuBar
		{
		public:
			BioMainMenu();
			virtual ~BioMainMenu();

		private:
			void create();
			//void appendChild(int index, wxMenu* menu, wxItemKind style, BioMainMenuResource& resource);

		};

		
	}

}

#endif
