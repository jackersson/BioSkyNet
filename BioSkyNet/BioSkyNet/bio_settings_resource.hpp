#ifndef BioSettings_Resource_INCLUDED
#define BioSettings_Resource_INCLUDED

#include "usettings_info_item.hpp"
#include "bio_control_resource.hpp"


namespace SmartBio
{
	namespace View
	{
		class BioSettingsResource : public BioControlResource < USettingInfoItem >
		{
		public:
			BioSettingsResource();
			virtual ~BioSettingsResource();

		private:
			void do_initialize();
		};
	}
}

#endif

