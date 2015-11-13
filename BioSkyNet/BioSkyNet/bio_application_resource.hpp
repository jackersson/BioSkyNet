#ifndef BioApplication_Resources_INCLUDED
#define BioApplication_Resources_INCLUDED

#include "uapp_info_item.hpp"
#include "bio_control_resource.hpp"

namespace SmartBio
{
	namespace View
	{
		class BioApplicationResource : public BioControlResource<UAppInfoItem>
		{
		public:
			BioApplicationResource();
			virtual ~BioApplicationResource();

		private:
			void do_initialize();
		};
	}
}
#endif