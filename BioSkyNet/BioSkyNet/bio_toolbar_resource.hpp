#ifndef BioToolBar_Resource_INCLUDED
#define BioToolBar_Resource_INCLUDED

#include "uinfo_item.hpp"
#include "bio_control_resource.hpp"

namespace SmartBio
{
	namespace View
	{
		class BioToolBarResource : public BioControlResource <UInfoItem>
		{
		public:
			BioToolBarResource();			
			virtual ~BioToolBarResource();

		private:
			void do_initialize();
		};
	}
}

#endif

