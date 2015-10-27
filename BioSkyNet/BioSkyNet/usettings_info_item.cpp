#include "stdafx.h"
#include "usettings_info_item.hpp"

namespace SmartBio
{
	namespace View
	{		
		
	  USettingInfoItem::USettingInfoItem() : UInfoItem(), assign_property_(""), ui_control_("")
		{
		}

		USettingInfoItem::USettingInfoItem(std::string text
				              ,  std::string choices
				              , std::string hint
				              , std::string icon_filename
				              , std::string hot_key
				              , std::string assign_property
				              , std::string uicontrol )
				              : UInfoItem(text, hint, icon_filename, hot_key)
				              , assign_property_(assign_property)
				              , ui_control_(uicontrol), choices_(choices)
		{
		}


		USettingInfoItem::~USettingInfoItem(){}

		std::string USettingInfoItem::assign_property() const
		{
			return assign_property_;
		}

		std::string USettingInfoItem::uiControl() const
		{
			return ui_control_;
		}

		std::string USettingInfoItem::choices() const
		{
			return choices_;
		}

		
	}
}