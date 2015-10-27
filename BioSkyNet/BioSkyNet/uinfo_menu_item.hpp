#ifndef UInfo_MenuItem_Resource_INCLUDED
#define UInfo_MenuItem_Resource_INCLUDED

#include "uinfo_item.hpp"
#include "bio_control_resource.hpp"

namespace SmartBio
{
	namespace View
	{
		/*
		Inherits UInfoItem for information holder( Text, Hint, Icon, etc.. )
		Inherits BioControlResource as holder of children items. As menu item can holds other items.
		*/
		class UInfoMenuItem : public UInfoItem, public BioControlResource < UInfoMenuItem >
		{
		public:
			UInfoMenuItem();
			UInfoMenuItem( std::string text
				           , std::string hint = ""
				           , std::string icon_filename = ""
				           , std::string hot_key = "");

			~UInfoMenuItem();


			void add(int id, UInfoMenuItem item);

			bool hasChildrens() const;

		private:
			void do_initialize();			

		};
	}
}

#endif