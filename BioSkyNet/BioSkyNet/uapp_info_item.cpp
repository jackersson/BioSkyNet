#include "stdafx.h"
#include "uapp_info_item.hpp"

#include "resources/logo.xpm"

namespace SmartBio
{
	namespace View
	{
	  	
		UAppInfoItem::UAppInfoItem() : UInfoItem(), version_(""), website_("")
		{
		}

		UAppInfoItem::UAppInfoItem( std::string application_name
				                      , std::string hint
				                      , std::string icon_filename
				                      , std::string hot_key
				                      , std::string website 
				                      , std::string version)
				                      : UInfoItem(application_name, hint, icon_filename, hot_key)
															, version_(version), website_(website)
		{
		}


	  UAppInfoItem::~UAppInfoItem()	{	}

		std::string UAppInfoItem::version() const
		{
			return version_;
		}

		std::string UAppInfoItem::website() const
		{
		 return website_;
		}		

		wxIcon UAppInfoItem::icon()
		{
			return wxIcon(logo);
		}
	}
}
