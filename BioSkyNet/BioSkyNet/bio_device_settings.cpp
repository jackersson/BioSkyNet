#include "stdafx.h"
#include "bio_device_settings.hpp"

#include "bio_device_settings_resource.hpp"

#include "bio_resources.hpp"

#include "bio_properties_utils.hpp"

namespace SmartBio
{
	namespace View
	{

		BioDeviceSettings::BioDeviceSettings() : wxPropertyGridPage()
		{
			do_initialize();
		}

		BioDeviceSettings::~BioDeviceSettings() {}

		void BioDeviceSettings::do_initialize()
		{

			Poco::SharedPtr<BioDeviceSettingsResource> resource(new BioDeviceSettingsResource());



			BioPropertiesUtils utils;

			wxEnumProperty* port_name_ = utils.createEnumProperty(ID_DEVICE_SETTINGS_PORT_NAME	, *this,  *resource);
			wxEnumProperty* baud_rate_ = utils.createEnumProperty(ID_DEVICE_SETTINGS_BAUD_RATE, *this, *resource);

			





		}


	}
}