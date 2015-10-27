#ifndef BioMainMenu_Resource_INCLUDED
#define BioMainMenu_Resource_INCLUDED

#include "uinfo_menu_item.hpp"
#include "bio_control_resource.hpp"

namespace SmartBio
{
	namespace View
	{
		
		/*
		BioMainMenuResource class is a whole menubar holder 
		*/
		class BioMainMenuResource : public BioControlResource <UInfoMenuItem>
		{
		public:
			BioMainMenuResource();

			virtual ~BioMainMenuResource();

		private:
			void do_initialize();

			/*
			Non recursive DFS for menuitem serching
			*/
			bool find(int index, UInfoMenuItem& item) const;			

		};

	}
}


#endif