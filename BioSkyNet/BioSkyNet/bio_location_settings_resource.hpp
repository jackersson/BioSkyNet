#ifndef BioLocationSettings_Resource_INCLUDED
#define BioLocationSettings_Resource_INCLUDED

#include "usettings_info_item.hpp"
#include "bio_control_resource.hpp"

namespace SmartBio
{
	namespace View
	{
		class BioLocationSettingsResource : public BioControlResource < USettingInfoItem >
		{
		public:
			BioLocationSettingsResource();
			virtual ~BioLocationSettingsResource();

		private:
			void do_initialize();
		};
	}
}

#endif

