#include "stdafx.h"
#include "uinfo_menu_item.hpp"


namespace SmartBio
{
	namespace View
	{
		UInfoMenuItem::UInfoMenuItem() : UInfoItem() {}
		UInfoMenuItem::UInfoMenuItem( std::string text
			                          , std::string hint
			                          , std::string icon_filename
			                          , std::string hot_key)
			                          : UInfoItem(text, hint, icon_filename, hot_key)
		{
		}

		UInfoMenuItem::~UInfoMenuItem()	{}

		void UInfoMenuItem::add(int id, UInfoMenuItem item)
		{
			auto elem = info_.find(id);
			if (elem != info_.end())
				return;

			info_.insert(std::pair<int, UInfoMenuItem>(id, item));
		}

		bool UInfoMenuItem::hasChildrens() const
		{
			return !info_.empty();
		}

		void UInfoMenuItem::do_initialize() {}
	}
}
