#ifndef BioPersonal_Resource_INCLUDED
#define BioPersonal_Resource_INCLUDED

#include "usettings_info_item.hpp"
#include "bio_control_resource.hpp"

namespace SmartBio
{
	namespace View
	{

		class BioPersonalResource : public BioControlResource <USettingInfoItem>
		{
		public:
			BioPersonalResource();

			virtual ~BioPersonalResource();

		private:
			void do_initialize();

		};

	}
}


#endif