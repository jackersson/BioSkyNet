#include "stdafx.h"
#include "uinfo_item.hpp"

namespace SmartBio
{
	namespace View
	{
	
		UInfoItem::UInfoItem() : text_(""), hint_(""), IconLoadable(""), hot_key_(""){}

		UInfoItem::UInfoItem( std::string text
				                , std::string hint 
				                , std::string icon_filename
				                , std::string hot_key												)
												: text_(text), hint_(hint), IconLoadable(icon_filename)
												, hot_key_(hot_key)
		{
		}

		UInfoItem::~UInfoItem(){}

		std::string UInfoItem::text() const
		{
			return text_;
		}

		std::string UInfoItem::hint() const
		{
			return hint_;
		}

		/*wxIcon UInfoItem::icon()
		{
			return loadIcon(icon_filename_);
		}

		wxBitmap UInfoItem::bitmap()
		{
			return loadBitmap(icon_filename_);
		}
*/

		std::string UInfoItem::hotKey() const
		{
			return hot_key_;
		}

		/*wxBitmap UInfoItem::loadBitmap(std::string const& filename)
		{
			if (!filename.empty())
			{
				wxImage image;
				if (image.LoadFile(filename))
				{
					wxBitmap bmp(image);
					return bmp;
				}
			}
			return wxArtProvider::GetBitmap(wxART_ERROR);
		}

		wxIcon UInfoItem::loadIcon(std::string const& filename)
		{
			wxIcon image;
			if (!filename.empty())
			{				
				if (image.LoadFile(filename))								
					return image;			
			}
			return image;
		}*/
	}
}