#ifndef Bio_MainMenu_Utils_INCLUDED
#define Bio_MainMenu_Utils_INCLUDED

#include "bio_main_menu_resource.hpp"

namespace SmartBio
{
	namespace View
	{
		class BioMainMenuUtils
		{
		public:
			BioMainMenuUtils() {}
			~BioMainMenuUtils() {}

			void appendChild(int index, wxMenu* menu, wxItemKind style, BioMainMenuResource& resource)
			{
				if (menu == NULL)
					return;

				bool flag(false);
				UInfoMenuItem mitem = resource.get(index, flag);

				if (flag)
				{
					wxMenuItem* item = new wxMenuItem(menu, index, mitem.text(), mitem.hint(), style);
					item->SetBitmap(mitem.bitmap());

					menu->Append(item);
				}
			}


			void appendRoot(int index, wxMenuBar& menu, wxMenu* root, /*wxItemKind style,*/ BioMainMenuResource& resource)
			{				
				bool flag(false);
				UInfoMenuItem mitem = resource.get(index, flag);

				if (flag)				
					menu.Append(root, mitem.text());				
			}

			void appendCheckItem(int index, wxMenu* menu, /*wxItemKind style,*/ BioMainMenuResource& resource)
			{
				if (menu == NULL)
					return;

				bool flag(false);
				UInfoMenuItem mitem = resource.get(index, flag);

				if (flag)
					menu->AppendCheckItem(index, mitem.text());
			}

		};
	}
}

#endif


