#ifndef UAppInfo_Item_INCLUDED
#define UAppInfo_Item_INCLUDED

#include "uinfo_item.hpp"

namespace SmartBio
{
	namespace View
	{
		class UAppInfoItem : public UInfoItem
		{

		public:
			UAppInfoItem();		

			UAppInfoItem( std::string application_name
				          , std::string hint = ""
				          , std::string icon_filename = ""
				          , std::string hot_key = ""
				          , std::string website = ""
				          , std::string version = "");

			virtual ~UAppInfoItem();

			std::string version() const;			
			std::string website() const;			

			wxIcon icon();			

		private:
			std::string version_;
			std::string website_;

		};
	}
}

#endif