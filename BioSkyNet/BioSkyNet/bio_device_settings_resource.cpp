#include "stdafx.h"
#include "bio_device_settings_resource.hpp"

#include "bio_resources.hpp"

namespace SmartBio
{
	namespace View
	{

		BioDeviceSettingsResource::BioDeviceSettingsResource()
		{
			initialize();
		}

		BioDeviceSettingsResource::~BioDeviceSettingsResource()	{}

		void BioDeviceSettingsResource::do_initialize()
		{ 			

			View::USettingInfoItem port_name("Port name", "", "Port name", "", "", "");
			View::USettingInfoItem baud_rate("Baud rate", "", "Baud rate", "", "", "");

			insert(UIBioDeviceSettings::ID_DEVICE_SETTINGS_PORT_NAME, port_name);
			insert(UIBioDeviceSettings::ID_DEVICE_SETTINGS_BAUD_RATE, baud_rate);
		}
	}
}


