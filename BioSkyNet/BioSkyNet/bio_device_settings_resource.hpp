#ifndef BioDeviceSettings_Resource_INCLUDED
#define BioDeviceSettings_Resource_INCLUDED

#include "usettings_info_item.hpp"
#include "bio_control_resource.hpp"

namespace SmartBio
{
	namespace View
	{
		class BioDeviceSettingsResource : public BioControlResource < USettingInfoItem >
		{
		public:
			BioDeviceSettingsResource();
			virtual ~BioDeviceSettingsResource();

		private:
			void do_initialize();
		};
	}
}

#endif

