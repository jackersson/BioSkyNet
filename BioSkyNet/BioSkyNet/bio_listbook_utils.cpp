#include "stdafx.h"
#include "bio_listbook_utils.hpp"

#include "uinfo_item.hpp"

namespace SmartBio
{
	namespace View
	{
		BioListbookUtils::BioListbookUtils(){	}
		BioListbookUtils::~BioListbookUtils()	{	}


		void BioListbookUtils::addPage( int index, wxPanel* parent, wxListbook& listbook
		                            	, BioInfoResource& resource, wxImageList& image_list, bool selected )
		{
			if (parent == NULL)
				return;

			bool result(false);
			UInfoItem item = resource.get(index, result);

			if (result)
			{
				int image_index = image_list.Add(item.bitmap());
				listbook.AddPage(parent, item.text(), selected, image_index);
			}

		}

		


	}
}