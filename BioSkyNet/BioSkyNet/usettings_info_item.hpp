#ifndef USettingsInfo_Item_INCLUDED
#define USettingsInfo_Item_INCLUDED

#include "uinfo_item.hpp"

namespace SmartBio
{
	namespace View
	{
		class USettingInfoItem : public UInfoItem
		{

		public:
			USettingInfoItem();

			USettingInfoItem( std::string text
				              , std::string choices
				              , std::string hint = ""
				              , std::string icon_filename = ""
				              , std::string hot_key = ""
				              , std::string assign_property = ""
				              , std::string uicontrol = "");
			
			virtual ~USettingInfoItem();

			std::string assign_property() const;
			std::string uiControl()       const;
			std::string choices()         const;

		private:
			std::string assign_property_;
			std::string ui_control_;
			std::string choices_;
		};
	}
}

#endif