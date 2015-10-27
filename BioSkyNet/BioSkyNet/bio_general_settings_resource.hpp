#ifndef BioGeneralSettings_Resource_INCLUDED
#define BioGeneralSettings_Resource_INCLUDED

#include "usettings_info_item.hpp"
#include "bio_control_resource.hpp"

namespace SmartBio
{
	namespace View
	{
		class BioGeneralSettingsResource : public BioControlResource < USettingInfoItem >
		{
		public:
			BioGeneralSettingsResource();
			virtual ~BioGeneralSettingsResource();

		private:
			void do_initialize();
		};
	}
}

#endif

