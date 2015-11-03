#ifndef Bio_Listbook_Utils_INCLUDED
#define Bio_Listbook_Utils_INCLUDED

#include "uinfo_item.hpp"
#include "bio_control_resource.hpp"

namespace SmartBio
{
	namespace View
	{
		class BioListbookUtils
		{
		public:
			BioListbookUtils();
			~BioListbookUtils();

			void addPage( int index, wxPanel* parent, wxListbook& listbook
				          , BioControlResource<UInfoItem>& resource
				          , wxImageList& image_list, bool selected = false);
		};


	}
}

#endif