#include "stdafx.h"
#include "icon_loadable.hpp"

namespace SmartBio
{
	namespace View
	{
		IconLoadable::IconLoadable() : icon_filename_("") {}

		IconLoadable::IconLoadable(std::string icon_filename) : icon_filename_(icon_filename) {}

		IconLoadable::~IconLoadable()
		{

		}

		wxIcon   IconLoadable::icon()
		{
			return loadIcon(icon_filename_);
		}

		wxBitmap IconLoadable::bitmap()
		{
			return loadBitmap(icon_filename_);
		}

		wxBitmap IconLoadable::loadBitmap(std::string const& filename)
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

		wxIcon   IconLoadable::loadIcon(std::string const& filename)
		{		
			if (!filename.empty())
			{
				wxIcon image;
				if (image.LoadFile(filename))
					return image;
			}
			return wxArtProvider::GetIcon(wxART_ERROR);
		}

	}
}