#ifndef UInfo_Item_INCLUDED
#define UInfo_Item_INCLUDED

#include "icon_loadable.hpp"

namespace SmartBio
{
	namespace View
	{

		class UInfoItem : public IconLoadable
		{

		public:
			UInfoItem();

			UInfoItem( std::string text
				       , std::string hint = ""
				       , std::string icon_filename = ""
				       , std::string hot_key = ""	);
			

			virtual ~UInfoItem();

			std::string text       () const;
			std::string hint       () const;
			std::string hotKey     () const;		

		private:
			std::string hot_key_      ;
			std::string text_         ;
			std::string hint_         ;	

		};
	}
}

#endif