#ifndef BioGridSettings_Resource_INCLUDED
#define BioGridSettings_Resource_INCLUDED

#include "usettings_info_item.hpp"
#include "bio_control_resource.hpp"

namespace SmartBio
{
	namespace View
	{
		class BioGridSettingsResource : public BioControlResource < UInfoItem >
		{
		public:
			BioGridSettingsResource();
			virtual ~BioGridSettingsResource();

		private:
			void do_initialize();


		};
	}
}

#endif

