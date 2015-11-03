#ifndef BioSearchSettings_Resource_INCLUDED
#define BioSearchSettings_Resource_INCLUDED

#include "usettings_info_item.hpp"
#include "bio_control_resource.hpp"

namespace SmartBio
{
	namespace View
	{
		class BioSearchSettingsResource : public BioControlResource < USettingInfoItem >
		{
		public:
			BioSearchSettingsResource();
			virtual ~BioSearchSettingsResource();

		private:
			void do_initialize();
		};
	}
}

#endif

